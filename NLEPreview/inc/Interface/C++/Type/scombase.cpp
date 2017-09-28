//------------------------------------------------------------------------------
// File: ComBase.cpp
//
// Desc: DirectShow base classes - implements class hierarchy for creating
//       COM objects.
//
// Copyright (c) 1992-2001 Microsoft Corporation.  All rights reserved.
//------------------------------------------------------------------------------

// #include "stdafx.h"
#include "scombase.h"
#pragma warning( disable : 4514 )   // Disable warnings re unused inline functions

/* Constructor */

// We know we use "this" in the initialization list, we also know we don't modify *phr.
#pragma warning( disable : 4355 4100 )
namespace scombase
{
CUnknown::CUnknown( LPUNKNOWN pUnk)
: /* Start the object with a reference count of zero - when the      */
/* object is queried for it's first interface this may be          */
/* incremented depending on whether or not this object is          */
/* currently being aggregated upon                                 */
 m_cRef(0)
/* Set our pointer to our IUnknown interface.                      */
/* If we have an outer, use its, otherwise use ours.               */
/* This pointer effectivly points to the owner of                  */
/* this object and can be accessed by the GetOwner() method.       */
, m_pUnknown( pUnk != 0 ? pUnk : reinterpret_cast<LPUNKNOWN>( static_cast<PNDUNKNOWN>(this) ) )
 /* Why the double cast?  Well, the inner cast is a type-safe cast */
 /* to pointer to a type from which we inherit.  The second is     */
 /* type-unsafe but works because INonDelegatingUnknown "behaves   */
 /* like" IUnknown. (Only the names on the methods change.)        */
{
    // Everything we need to do has been done in the initializer list
}

// This does the same as above except it has a useless HRESULT argument
// use the previous constructor, this is just left for compatibility...
CUnknown::CUnknown( LPUNKNOWN pUnk, HRESULT *phr) :
    m_cRef(0),
    m_pUnknown( pUnk != 0 ? pUnk : reinterpret_cast<LPUNKNOWN>( static_cast<PNDUNKNOWN>(this) ) )
{
}


#pragma warning( default : 4355 4100 )

/* QueryInterface */

HRESULT CUnknown::NonDelegatingQueryInterface(REFIID riid, void ** ppv)
{
    CheckPointer(ppv,E_POINTER);
    ValidateReadWritePtr(ppv,sizeof(PVOID));

    /* We know only about IUnknown */

    if (riid == IID_IUnknown) {
        GetInterface((LPUNKNOWN) (PNDUNKNOWN) this, ppv);
        return NOERROR;
    } else {
        *ppv = NULL;
        return E_NOINTERFACE;
    }
}

/* We have to ensure that we DON'T use a max macro, since these will typically   */
/* lead to one of the parameters being evaluated twice.  Since we are worried    */
/* about concurrency, we can't afford to access the m_cRef twice since we can't  */
/* afford to run the risk that its value having changed between accesses.        */

template<class T> inline static T ourmax( const T & a, const T & b )
{
    return a > b ? a : b;
}

/* AddRef */

STDMETHODIMP_(ULONG) CUnknown::NonDelegatingAddRef()
{
    LONG lRef = InterlockedIncrement( &m_cRef );
    ASSERT(lRef > 0);
    return ourmax(ULONG(m_cRef), (ULONG)1);
}


/* Release */

STDMETHODIMP_(ULONG) CUnknown::NonDelegatingRelease()
{
    /* If the reference count drops to zero delete ourselves */

    LONG lRef = InterlockedDecrement( &m_cRef );
    ASSERT(lRef >= 0);

    if (lRef == 0) {

        // COM rules say we must protect against re-entrancy.
        // If we are an aggregator and we hold our own interfaces
        // on the aggregatee, the QI for these interfaces will
        // addref ourselves. So after doing the QI we must release
        // a ref count on ourselves. Then, before releasing the
        // private interface, we must addref ourselves. When we do
        // this from the destructor here it will result in the ref
        // count going to 1 and then back to 0 causing us to
        // re-enter the destructor. Hence we add an extra refcount here
        // once we know we will delete the object.
        // for an example aggregator see filgraph\distrib.cpp.

        //m_cRef++;

        delete this;
        return ULONG(0);
    } else {
        //  Don't touch m_cRef again even in this leg as the object
        //  may have just been released on another thread too
        return ourmax(ULONG(lRef), (ULONG)1);
    }
}


/* Return an interface pointer to a requesting client
   performing a thread safe AddRef as necessary */

HRESULT __stdcall GetInterface(LPUNKNOWN pUnk, void **ppv)
{
    CheckPointer(ppv, E_POINTER);
    *ppv = pUnk;
    pUnk->AddRef();
    return NOERROR;
}


/* Compares two interfaces and returns TRUE if they are on the same object */

BOOL WINAPI IsEqualObject(IUnknown *pFirst, IUnknown *pSecond)
{
    /*  Different objects can't have the same interface pointer for
        any interface
    */
    if (pFirst == pSecond) {
        return TRUE;
    }
    /*  OK - do it the hard way - check if they have the same
        IUnknown pointers - a single object can only have one of these
    */
    LPUNKNOWN pUnknown1;     // Retrieve the IUnknown interface
    LPUNKNOWN pUnknown2;     // Retrieve the other IUnknown interface
    HRESULT hr;              // General OLE return code

    ASSERT(pFirst);
    ASSERT(pSecond);

    /* See if the IUnknown pointers match */

    hr = pFirst->QueryInterface(IID_IUnknown,(void **) &pUnknown1);
    if (FAILED(hr)) {
        return FALSE;
    }
    ASSERT(pUnknown1);

    /* Release the extra interface we hold */

    pUnknown1->Release();

    hr = pSecond->QueryInterface(IID_IUnknown,(void **) &pUnknown2);
    if (FAILED(hr)) {
        return FALSE;
    }
    ASSERT(pUnknown2);

    /* Release the extra interface we hold */

    pUnknown2->Release();
    return (pUnknown1 == pUnknown2);
}
}

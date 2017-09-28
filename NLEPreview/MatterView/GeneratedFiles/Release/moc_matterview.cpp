/****************************************************************************
** Meta object code from reading C++ file 'matterview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../../include/inc_MatterView/matterview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'matterview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MatterView_t {
    QByteArrayData data[7];
    char stringdata[66];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MatterView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MatterView_t qt_meta_stringdata_MatterView = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MatterView"
QT_MOC_LITERAL(1, 11, 10), // "signalLoad"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 5), // "bPlay"
QT_MOC_LITERAL(4, 29, 12), // "signlaUnload"
QT_MOC_LITERAL(5, 42, 18), // "sigViewSizeChanged"
QT_MOC_LITERAL(6, 61, 4) // "size"

    },
    "MatterView\0signalLoad\0\0bPlay\0signlaUnload\0"
    "sigViewSizeChanged\0size"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MatterView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    0,   32,    2, 0x06 /* Public */,
       5,    1,   33,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QSize,    6,

       0        // eod
};

void MatterView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MatterView *_t = static_cast<MatterView *>(_o);
        switch (_id) {
        case 0: _t->signalLoad((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->signlaUnload(); break;
        case 2: _t->sigViewSizeChanged((*reinterpret_cast< QSize(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MatterView::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MatterView::signalLoad)) {
                *result = 0;
            }
        }
        {
            typedef void (MatterView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MatterView::signlaUnload)) {
                *result = 1;
            }
        }
        {
            typedef void (MatterView::*_t)(QSize );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MatterView::sigViewSizeChanged)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject MatterView::staticMetaObject = {
    { &NLEBaseWidget::staticMetaObject, qt_meta_stringdata_MatterView.data,
      qt_meta_data_MatterView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MatterView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MatterView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MatterView.stringdata))
        return static_cast<void*>(const_cast< MatterView*>(this));
    return NLEBaseWidget::qt_metacast(_clname);
}

int MatterView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = NLEBaseWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void MatterView::signalLoad(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MatterView::signlaUnload()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void MatterView::sigViewSizeChanged(QSize _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE

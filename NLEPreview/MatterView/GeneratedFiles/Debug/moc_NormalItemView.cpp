/****************************************************************************
** Meta object code from reading C++ file 'NormalItemView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../Controls/NormalItemView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NormalItemView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NormalItemView_t {
    QByteArrayData data[4];
    char stringdata[50];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NormalItemView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NormalItemView_t qt_meta_stringdata_NormalItemView = {
    {
QT_MOC_LITERAL(0, 0, 14), // "NormalItemView"
QT_MOC_LITERAL(1, 15, 19), // "signalAddBtnClicked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 13) // "ListItemData*"

    },
    "NormalItemView\0signalAddBtnClicked\0\0"
    "ListItemData*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NormalItemView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

       0        // eod
};

void NormalItemView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NormalItemView *_t = static_cast<NormalItemView *>(_o);
        switch (_id) {
        case 0: _t->signalAddBtnClicked((*reinterpret_cast< ListItemData*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (NormalItemView::*_t)(ListItemData * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NormalItemView::signalAddBtnClicked)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject NormalItemView::staticMetaObject = {
    { &ItemBaseView::staticMetaObject, qt_meta_stringdata_NormalItemView.data,
      qt_meta_data_NormalItemView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NormalItemView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NormalItemView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NormalItemView.stringdata))
        return static_cast<void*>(const_cast< NormalItemView*>(this));
    return ItemBaseView::qt_metacast(_clname);
}

int NormalItemView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ItemBaseView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void NormalItemView::signalAddBtnClicked(ListItemData * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_TextItemView_t {
    QByteArrayData data[1];
    char stringdata[13];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TextItemView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TextItemView_t qt_meta_stringdata_TextItemView = {
    {
QT_MOC_LITERAL(0, 0, 12) // "TextItemView"

    },
    "TextItemView"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TextItemView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void TextItemView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject TextItemView::staticMetaObject = {
    { &NormalItemView::staticMetaObject, qt_meta_stringdata_TextItemView.data,
      qt_meta_data_TextItemView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TextItemView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TextItemView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TextItemView.stringdata))
        return static_cast<void*>(const_cast< TextItemView*>(this));
    return NormalItemView::qt_metacast(_clname);
}

int TextItemView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = NormalItemView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_AudioFilterItemView_t {
    QByteArrayData data[1];
    char stringdata[20];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AudioFilterItemView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AudioFilterItemView_t qt_meta_stringdata_AudioFilterItemView = {
    {
QT_MOC_LITERAL(0, 0, 19) // "AudioFilterItemView"

    },
    "AudioFilterItemView"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AudioFilterItemView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void AudioFilterItemView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject AudioFilterItemView::staticMetaObject = {
    { &NormalItemView::staticMetaObject, qt_meta_stringdata_AudioFilterItemView.data,
      qt_meta_data_AudioFilterItemView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AudioFilterItemView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AudioFilterItemView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AudioFilterItemView.stringdata))
        return static_cast<void*>(const_cast< AudioFilterItemView*>(this));
    return NormalItemView::qt_metacast(_clname);
}

int AudioFilterItemView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = NormalItemView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_MontageItemView_t {
    QByteArrayData data[1];
    char stringdata[16];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MontageItemView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MontageItemView_t qt_meta_stringdata_MontageItemView = {
    {
QT_MOC_LITERAL(0, 0, 15) // "MontageItemView"

    },
    "MontageItemView"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MontageItemView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void MontageItemView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject MontageItemView::staticMetaObject = {
    { &NormalItemView::staticMetaObject, qt_meta_stringdata_MontageItemView.data,
      qt_meta_data_MontageItemView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MontageItemView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MontageItemView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MontageItemView.stringdata))
        return static_cast<void*>(const_cast< MontageItemView*>(this));
    return NormalItemView::qt_metacast(_clname);
}

int MontageItemView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = NormalItemView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE

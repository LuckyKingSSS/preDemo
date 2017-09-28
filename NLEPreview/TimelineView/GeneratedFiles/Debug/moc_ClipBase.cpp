/****************************************************************************
** Meta object code from reading C++ file 'ClipBase.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../TimelineManager/ClipBase.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ClipBase.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ClipBase_t {
    QByteArrayData data[4];
    char stringdata[44];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ClipBase_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ClipBase_t qt_meta_stringdata_ClipBase = {
    {
QT_MOC_LITERAL(0, 0, 8), // "ClipBase"
QT_MOC_LITERAL(1, 9, 23), // "signalThumbnailAvalible"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 9) // "ClipBase*"

    },
    "ClipBase\0signalThumbnailAvalible\0\0"
    "ClipBase*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClipBase[] = {

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

void ClipBase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ClipBase *_t = static_cast<ClipBase *>(_o);
        switch (_id) {
        case 0: _t->signalThumbnailAvalible((*reinterpret_cast< ClipBase*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ClipBase* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ClipBase::*_t)(ClipBase * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClipBase::signalThumbnailAvalible)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject ClipBase::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ClipBase.data,
      qt_meta_data_ClipBase,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ClipBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClipBase::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ClipBase.stringdata))
        return static_cast<void*>(const_cast< ClipBase*>(this));
    return QObject::qt_metacast(_clname);
}

int ClipBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void ClipBase::signalThumbnailAvalible(ClipBase * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_ComplexClip_t {
    QByteArrayData data[1];
    char stringdata[12];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ComplexClip_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ComplexClip_t qt_meta_stringdata_ComplexClip = {
    {
QT_MOC_LITERAL(0, 0, 11) // "ComplexClip"

    },
    "ComplexClip"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ComplexClip[] = {

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

void ComplexClip::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject ComplexClip::staticMetaObject = {
    { &ClipBase::staticMetaObject, qt_meta_stringdata_ComplexClip.data,
      qt_meta_data_ComplexClip,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ComplexClip::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ComplexClip::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ComplexClip.stringdata))
        return static_cast<void*>(const_cast< ComplexClip*>(this));
    return ClipBase::qt_metacast(_clname);
}

int ComplexClip::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ClipBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_SimplexClip_t {
    QByteArrayData data[1];
    char stringdata[12];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SimplexClip_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SimplexClip_t qt_meta_stringdata_SimplexClip = {
    {
QT_MOC_LITERAL(0, 0, 11) // "SimplexClip"

    },
    "SimplexClip"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SimplexClip[] = {

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

void SimplexClip::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject SimplexClip::staticMetaObject = {
    { &ClipBase::staticMetaObject, qt_meta_stringdata_SimplexClip.data,
      qt_meta_data_SimplexClip,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SimplexClip::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SimplexClip::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SimplexClip.stringdata))
        return static_cast<void*>(const_cast< SimplexClip*>(this));
    return ClipBase::qt_metacast(_clname);
}

int SimplexClip::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ClipBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_VedioClip_t {
    QByteArrayData data[1];
    char stringdata[10];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VedioClip_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VedioClip_t qt_meta_stringdata_VedioClip = {
    {
QT_MOC_LITERAL(0, 0, 9) // "VedioClip"

    },
    "VedioClip"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VedioClip[] = {

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

void VedioClip::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject VedioClip::staticMetaObject = {
    { &SimplexClip::staticMetaObject, qt_meta_stringdata_VedioClip.data,
      qt_meta_data_VedioClip,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *VedioClip::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VedioClip::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_VedioClip.stringdata))
        return static_cast<void*>(const_cast< VedioClip*>(this));
    return SimplexClip::qt_metacast(_clname);
}

int VedioClip::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SimplexClip::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_AudioClip_t {
    QByteArrayData data[1];
    char stringdata[10];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AudioClip_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AudioClip_t qt_meta_stringdata_AudioClip = {
    {
QT_MOC_LITERAL(0, 0, 9) // "AudioClip"

    },
    "AudioClip"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AudioClip[] = {

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

void AudioClip::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject AudioClip::staticMetaObject = {
    { &SimplexClip::staticMetaObject, qt_meta_stringdata_AudioClip.data,
      qt_meta_data_AudioClip,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AudioClip::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AudioClip::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AudioClip.stringdata))
        return static_cast<void*>(const_cast< AudioClip*>(this));
    return SimplexClip::qt_metacast(_clname);
}

int AudioClip::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SimplexClip::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_EffectClip_t {
    QByteArrayData data[1];
    char stringdata[11];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EffectClip_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EffectClip_t qt_meta_stringdata_EffectClip = {
    {
QT_MOC_LITERAL(0, 0, 10) // "EffectClip"

    },
    "EffectClip"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EffectClip[] = {

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

void EffectClip::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject EffectClip::staticMetaObject = {
    { &SimplexClip::staticMetaObject, qt_meta_stringdata_EffectClip.data,
      qt_meta_data_EffectClip,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *EffectClip::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EffectClip::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_EffectClip.stringdata))
        return static_cast<void*>(const_cast< EffectClip*>(this));
    return SimplexClip::qt_metacast(_clname);
}

int EffectClip::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SimplexClip::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'timelinecontrol.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../timelinecontrol.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'timelinecontrol.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TimelineDragControl_t {
    QByteArrayData data[7];
    char stringdata[78];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TimelineDragControl_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TimelineDragControl_t qt_meta_stringdata_TimelineDragControl = {
    {
QT_MOC_LITERAL(0, 0, 19), // "TimelineDragControl"
QT_MOC_LITERAL(1, 20, 13), // "ClipCollision"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 13), // "srcTrackIndex"
QT_MOC_LITERAL(4, 49, 14), // "destTrackIndex"
QT_MOC_LITERAL(5, 64, 6), // "SeekTo"
QT_MOC_LITERAL(6, 71, 6) // "frames"

    },
    "TimelineDragControl\0ClipCollision\0\0"
    "srcTrackIndex\0destTrackIndex\0SeekTo\0"
    "frames"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TimelineDragControl[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x06 /* Public */,
       5,    1,   29,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int,    6,

       0        // eod
};

void TimelineDragControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TimelineDragControl *_t = static_cast<TimelineDragControl *>(_o);
        switch (_id) {
        case 0: _t->ClipCollision((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->SeekTo((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TimelineDragControl::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineDragControl::ClipCollision)) {
                *result = 0;
            }
        }
        {
            typedef void (TimelineDragControl::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineDragControl::SeekTo)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject TimelineDragControl::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TimelineDragControl.data,
      qt_meta_data_TimelineDragControl,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TimelineDragControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TimelineDragControl::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TimelineDragControl.stringdata))
        return static_cast<void*>(const_cast< TimelineDragControl*>(this));
    return QObject::qt_metacast(_clname);
}

int TimelineDragControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void TimelineDragControl::ClipCollision(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TimelineDragControl::SeekTo(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_TimelineTrimControl_t {
    QByteArrayData data[4];
    char stringdata[35];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TimelineTrimControl_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TimelineTrimControl_t qt_meta_stringdata_TimelineTrimControl = {
    {
QT_MOC_LITERAL(0, 0, 19), // "TimelineTrimControl"
QT_MOC_LITERAL(1, 20, 6), // "SeekTo"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 6) // "frames"

    },
    "TimelineTrimControl\0SeekTo\0\0frames"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TimelineTrimControl[] = {

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
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void TimelineTrimControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TimelineTrimControl *_t = static_cast<TimelineTrimControl *>(_o);
        switch (_id) {
        case 0: _t->SeekTo((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TimelineTrimControl::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineTrimControl::SeekTo)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject TimelineTrimControl::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TimelineTrimControl.data,
      qt_meta_data_TimelineTrimControl,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TimelineTrimControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TimelineTrimControl::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TimelineTrimControl.stringdata))
        return static_cast<void*>(const_cast< TimelineTrimControl*>(this));
    return QObject::qt_metacast(_clname);
}

int TimelineTrimControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void TimelineTrimControl::SeekTo(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_TimelineTrackBuilder_t {
    QByteArrayData data[1];
    char stringdata[21];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TimelineTrackBuilder_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TimelineTrackBuilder_t qt_meta_stringdata_TimelineTrackBuilder = {
    {
QT_MOC_LITERAL(0, 0, 20) // "TimelineTrackBuilder"

    },
    "TimelineTrackBuilder"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TimelineTrackBuilder[] = {

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

void TimelineTrackBuilder::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject TimelineTrackBuilder::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TimelineTrackBuilder.data,
      qt_meta_data_TimelineTrackBuilder,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TimelineTrackBuilder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TimelineTrackBuilder::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TimelineTrackBuilder.stringdata))
        return static_cast<void*>(const_cast< TimelineTrackBuilder*>(this));
    return QObject::qt_metacast(_clname);
}

int TimelineTrackBuilder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE

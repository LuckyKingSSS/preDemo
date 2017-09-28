/****************************************************************************
** Meta object code from reading C++ file 'TrackManager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../TimelineManager/TrackManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TrackManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TrackManager_t {
    QByteArrayData data[8];
    char stringdata[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TrackManager_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TrackManager_t qt_meta_stringdata_TrackManager = {
    {
QT_MOC_LITERAL(0, 0, 12), // "TrackManager"
QT_MOC_LITERAL(1, 13, 23), // "signalThumbnailAvalible"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 9), // "ClipBase*"
QT_MOC_LITERAL(4, 48, 18), // "signalTrackChanged"
QT_MOC_LITERAL(5, 67, 17), // "signalTrackUpdate"
QT_MOC_LITERAL(6, 85, 11), // "nTrackIndex"
QT_MOC_LITERAL(7, 97, 22) // "signalNestedCommndExec"

    },
    "TrackManager\0signalThumbnailAvalible\0"
    "\0ClipBase*\0signalTrackChanged\0"
    "signalTrackUpdate\0nTrackIndex\0"
    "signalNestedCommndExec"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TrackManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    0,   37,    2, 0x06 /* Public */,
       5,    1,   38,    2, 0x06 /* Public */,
       7,    0,   41,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,

       0        // eod
};

void TrackManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TrackManager *_t = static_cast<TrackManager *>(_o);
        switch (_id) {
        case 0: _t->signalThumbnailAvalible((*reinterpret_cast< ClipBase*(*)>(_a[1]))); break;
        case 1: _t->signalTrackChanged(); break;
        case 2: _t->signalTrackUpdate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->signalNestedCommndExec(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TrackManager::*_t)(ClipBase * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TrackManager::signalThumbnailAvalible)) {
                *result = 0;
            }
        }
        {
            typedef void (TrackManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TrackManager::signalTrackChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (TrackManager::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TrackManager::signalTrackUpdate)) {
                *result = 2;
            }
        }
        {
            typedef void (TrackManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TrackManager::signalNestedCommndExec)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject TrackManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TrackManager.data,
      qt_meta_data_TrackManager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TrackManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TrackManager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TrackManager.stringdata))
        return static_cast<void*>(const_cast< TrackManager*>(this));
    return QObject::qt_metacast(_clname);
}

int TrackManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void TrackManager::signalThumbnailAvalible(ClipBase * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TrackManager::signalTrackChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void TrackManager::signalTrackUpdate(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TrackManager::signalNestedCommndExec()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'TimelineManager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../TimelineManager/TimelineManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TimelineManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TimelineManager_t {
    QByteArrayData data[10];
    char stringdata[148];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TimelineManager_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TimelineManager_t qt_meta_stringdata_TimelineManager = {
    {
QT_MOC_LITERAL(0, 0, 15), // "TimelineManager"
QT_MOC_LITERAL(1, 16, 23), // "signalThumbnailAvalible"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 11), // "nTrackIndex"
QT_MOC_LITERAL(4, 53, 18), // "signalTrackRebuild"
QT_MOC_LITERAL(5, 72, 17), // "signalTrackUpdate"
QT_MOC_LITERAL(6, 90, 20), // "signalCanUndoChanged"
QT_MOC_LITERAL(7, 111, 7), // "canUndo"
QT_MOC_LITERAL(8, 119, 20), // "signalCanRedoChanged"
QT_MOC_LITERAL(9, 140, 7) // "canRedo"

    },
    "TimelineManager\0signalThumbnailAvalible\0"
    "\0nTrackIndex\0signalTrackRebuild\0"
    "signalTrackUpdate\0signalCanUndoChanged\0"
    "canUndo\0signalCanRedoChanged\0canRedo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TimelineManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    0,   42,    2, 0x06 /* Public */,
       5,    1,   43,    2, 0x06 /* Public */,
       6,    1,   46,    2, 0x06 /* Public */,
       8,    1,   49,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    9,

       0        // eod
};

void TimelineManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TimelineManager *_t = static_cast<TimelineManager *>(_o);
        switch (_id) {
        case 0: _t->signalThumbnailAvalible((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->signalTrackRebuild(); break;
        case 2: _t->signalTrackUpdate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->signalCanUndoChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->signalCanRedoChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TimelineManager::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineManager::signalThumbnailAvalible)) {
                *result = 0;
            }
        }
        {
            typedef void (TimelineManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineManager::signalTrackRebuild)) {
                *result = 1;
            }
        }
        {
            typedef void (TimelineManager::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineManager::signalTrackUpdate)) {
                *result = 2;
            }
        }
        {
            typedef void (TimelineManager::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineManager::signalCanUndoChanged)) {
                *result = 3;
            }
        }
        {
            typedef void (TimelineManager::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineManager::signalCanRedoChanged)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject TimelineManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TimelineManager.data,
      qt_meta_data_TimelineManager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TimelineManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TimelineManager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TimelineManager.stringdata))
        return static_cast<void*>(const_cast< TimelineManager*>(this));
    return QObject::qt_metacast(_clname);
}

int TimelineManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void TimelineManager::signalThumbnailAvalible(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TimelineManager::signalTrackRebuild()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void TimelineManager::signalTrackUpdate(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TimelineManager::signalCanUndoChanged(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TimelineManager::signalCanRedoChanged(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE

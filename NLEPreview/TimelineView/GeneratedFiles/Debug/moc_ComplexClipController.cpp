/****************************************************************************
** Meta object code from reading C++ file 'ComplexClipController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../TimelineManager/ComplexClipController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ComplexClipController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ComplexClipController_t {
    QByteArrayData data[7];
    char stringdata[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ComplexClipController_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ComplexClipController_t qt_meta_stringdata_ComplexClipController = {
    {
QT_MOC_LITERAL(0, 0, 21), // "ComplexClipController"
QT_MOC_LITERAL(1, 22, 23), // "signalThumbnailAvalible"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 11), // "nTrackIndex"
QT_MOC_LITERAL(4, 59, 18), // "signalTrackChanged"
QT_MOC_LITERAL(5, 78, 17), // "signalTrackUpdate"
QT_MOC_LITERAL(6, 96, 22) // "signalNestedCommndExec"

    },
    "ComplexClipController\0signalThumbnailAvalible\0"
    "\0nTrackIndex\0signalTrackChanged\0"
    "signalTrackUpdate\0signalNestedCommndExec"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ComplexClipController[] = {

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
       6,    0,   41,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

       0        // eod
};

void ComplexClipController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ComplexClipController *_t = static_cast<ComplexClipController *>(_o);
        switch (_id) {
        case 0: _t->signalThumbnailAvalible((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->signalTrackChanged(); break;
        case 2: _t->signalTrackUpdate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->signalNestedCommndExec(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ComplexClipController::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ComplexClipController::signalThumbnailAvalible)) {
                *result = 0;
            }
        }
        {
            typedef void (ComplexClipController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ComplexClipController::signalTrackChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (ComplexClipController::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ComplexClipController::signalTrackUpdate)) {
                *result = 2;
            }
        }
        {
            typedef void (ComplexClipController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ComplexClipController::signalNestedCommndExec)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject ComplexClipController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ComplexClipController.data,
      qt_meta_data_ComplexClipController,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ComplexClipController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ComplexClipController::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ComplexClipController.stringdata))
        return static_cast<void*>(const_cast< ComplexClipController*>(this));
    return QObject::qt_metacast(_clname);
}

int ComplexClipController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ComplexClipController::signalThumbnailAvalible(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ComplexClipController::signalTrackChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void ComplexClipController::signalTrackUpdate(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ComplexClipController::signalNestedCommndExec()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'ImportHelper.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../ImportHelper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ImportHelper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ImportHelper_t {
    QByteArrayData data[10];
    char stringdata[140];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImportHelper_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImportHelper_t qt_meta_stringdata_ImportHelper = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ImportHelper"
QT_MOC_LITERAL(1, 13, 14), // "signalImported"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 15), // "MatterDataBase*"
QT_MOC_LITERAL(4, 45, 17), // "signalImportBegin"
QT_MOC_LITERAL(5, 63, 8), // "fileName"
QT_MOC_LITERAL(6, 72, 24), // "signalImportProgressText"
QT_MOC_LITERAL(7, 97, 12), // "progressText"
QT_MOC_LITERAL(8, 110, 20), // "signalImportProgress"
QT_MOC_LITERAL(9, 131, 8) // "progress"

    },
    "ImportHelper\0signalImported\0\0"
    "MatterDataBase*\0signalImportBegin\0"
    "fileName\0signalImportProgressText\0"
    "progressText\0signalImportProgress\0"
    "progress"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImportHelper[] = {

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
       4,    1,   37,    2, 0x06 /* Public */,
       6,    1,   40,    2, 0x06 /* Public */,
       8,    1,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::Int,    9,

       0        // eod
};

void ImportHelper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ImportHelper *_t = static_cast<ImportHelper *>(_o);
        switch (_id) {
        case 0: _t->signalImported((*reinterpret_cast< MatterDataBase*(*)>(_a[1]))); break;
        case 1: _t->signalImportBegin((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->signalImportProgressText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->signalImportProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ImportHelper::*_t)(MatterDataBase * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImportHelper::signalImported)) {
                *result = 0;
            }
        }
        {
            typedef void (ImportHelper::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImportHelper::signalImportBegin)) {
                *result = 1;
            }
        }
        {
            typedef void (ImportHelper::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImportHelper::signalImportProgressText)) {
                *result = 2;
            }
        }
        {
            typedef void (ImportHelper::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ImportHelper::signalImportProgress)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject ImportHelper::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ImportHelper.data,
      qt_meta_data_ImportHelper,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ImportHelper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImportHelper::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ImportHelper.stringdata))
        return static_cast<void*>(const_cast< ImportHelper*>(this));
    return QThread::qt_metacast(_clname);
}

int ImportHelper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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
void ImportHelper::signalImported(MatterDataBase * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ImportHelper::signalImportBegin(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ImportHelper::signalImportProgressText(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ImportHelper::signalImportProgress(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE

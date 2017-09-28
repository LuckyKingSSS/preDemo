/****************************************************************************
** Meta object code from reading C++ file 'Command.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../TimelineManager/Command.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Command.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UndoCommandBase_t {
    QByteArrayData data[3];
    char stringdata[30];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UndoCommandBase_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UndoCommandBase_t qt_meta_stringdata_UndoCommandBase = {
    {
QT_MOC_LITERAL(0, 0, 15), // "UndoCommandBase"
QT_MOC_LITERAL(1, 16, 12), // "signalUpdate"
QT_MOC_LITERAL(2, 29, 0) // ""

    },
    "UndoCommandBase\0signalUpdate\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UndoCommandBase[] = {

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
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void UndoCommandBase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UndoCommandBase *_t = static_cast<UndoCommandBase *>(_o);
        switch (_id) {
        case 0: _t->signalUpdate(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (UndoCommandBase::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UndoCommandBase::signalUpdate)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject UndoCommandBase::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_UndoCommandBase.data,
      qt_meta_data_UndoCommandBase,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *UndoCommandBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UndoCommandBase::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_UndoCommandBase.stringdata))
        return static_cast<void*>(const_cast< UndoCommandBase*>(this));
    if (!strcmp(_clname, "QUndoCommand"))
        return static_cast< QUndoCommand*>(const_cast< UndoCommandBase*>(this));
    return QObject::qt_metacast(_clname);
}

int UndoCommandBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void UndoCommandBase::signalUpdate()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
struct qt_meta_stringdata_NestedCommond_t {
    QByteArrayData data[3];
    char stringdata[38];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NestedCommond_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NestedCommond_t qt_meta_stringdata_NestedCommond = {
    {
QT_MOC_LITERAL(0, 0, 13), // "NestedCommond"
QT_MOC_LITERAL(1, 14, 22), // "signalNestedCommndExec"
QT_MOC_LITERAL(2, 37, 0) // ""

    },
    "NestedCommond\0signalNestedCommndExec\0"
    ""
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NestedCommond[] = {

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
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void NestedCommond::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NestedCommond *_t = static_cast<NestedCommond *>(_o);
        switch (_id) {
        case 0: _t->signalNestedCommndExec(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (NestedCommond::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NestedCommond::signalNestedCommndExec)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject NestedCommond::staticMetaObject = {
    { &UndoCommandBase::staticMetaObject, qt_meta_stringdata_NestedCommond.data,
      qt_meta_data_NestedCommond,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *NestedCommond::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NestedCommond::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_NestedCommond.stringdata))
        return static_cast<void*>(const_cast< NestedCommond*>(this));
    return UndoCommandBase::qt_metacast(_clname);
}

int NestedCommond::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = UndoCommandBase::qt_metacall(_c, _id, _a);
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
void NestedCommond::signalNestedCommndExec()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
struct qt_meta_stringdata_ClipCommandBase_t {
    QByteArrayData data[4];
    char stringdata[49];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ClipCommandBase_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ClipCommandBase_t qt_meta_stringdata_ClipCommandBase = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ClipCommandBase"
QT_MOC_LITERAL(1, 16, 17), // "signalClipChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 13) // "OperatorBase*"

    },
    "ClipCommandBase\0signalClipChanged\0\0"
    "OperatorBase*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClipCommandBase[] = {

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

void ClipCommandBase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ClipCommandBase *_t = static_cast<ClipCommandBase *>(_o);
        switch (_id) {
        case 0: _t->signalClipChanged((*reinterpret_cast< OperatorBase*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ClipCommandBase::*_t)(OperatorBase * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClipCommandBase::signalClipChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject ClipCommandBase::staticMetaObject = {
    { &UndoCommandBase::staticMetaObject, qt_meta_stringdata_ClipCommandBase.data,
      qt_meta_data_ClipCommandBase,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ClipCommandBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClipCommandBase::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ClipCommandBase.stringdata))
        return static_cast<void*>(const_cast< ClipCommandBase*>(this));
    return UndoCommandBase::qt_metacast(_clname);
}

int ClipCommandBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = UndoCommandBase::qt_metacall(_c, _id, _a);
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
void ClipCommandBase::signalClipChanged(OperatorBase * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_AddClipCommand_t {
    QByteArrayData data[1];
    char stringdata[15];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AddClipCommand_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AddClipCommand_t qt_meta_stringdata_AddClipCommand = {
    {
QT_MOC_LITERAL(0, 0, 14) // "AddClipCommand"

    },
    "AddClipCommand"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AddClipCommand[] = {

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

void AddClipCommand::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject AddClipCommand::staticMetaObject = {
    { &ClipCommandBase::staticMetaObject, qt_meta_stringdata_AddClipCommand.data,
      qt_meta_data_AddClipCommand,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AddClipCommand::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddClipCommand::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AddClipCommand.stringdata))
        return static_cast<void*>(const_cast< AddClipCommand*>(this));
    return ClipCommandBase::qt_metacast(_clname);
}

int AddClipCommand::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ClipCommandBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_RemoveClipCommand_t {
    QByteArrayData data[1];
    char stringdata[18];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RemoveClipCommand_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RemoveClipCommand_t qt_meta_stringdata_RemoveClipCommand = {
    {
QT_MOC_LITERAL(0, 0, 17) // "RemoveClipCommand"

    },
    "RemoveClipCommand"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RemoveClipCommand[] = {

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

void RemoveClipCommand::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject RemoveClipCommand::staticMetaObject = {
    { &ClipCommandBase::staticMetaObject, qt_meta_stringdata_RemoveClipCommand.data,
      qt_meta_data_RemoveClipCommand,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RemoveClipCommand::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RemoveClipCommand::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RemoveClipCommand.stringdata))
        return static_cast<void*>(const_cast< RemoveClipCommand*>(this));
    return ClipCommandBase::qt_metacast(_clname);
}

int RemoveClipCommand::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ClipCommandBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_MoveClipCommand_t {
    QByteArrayData data[1];
    char stringdata[16];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MoveClipCommand_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MoveClipCommand_t qt_meta_stringdata_MoveClipCommand = {
    {
QT_MOC_LITERAL(0, 0, 15) // "MoveClipCommand"

    },
    "MoveClipCommand"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MoveClipCommand[] = {

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

void MoveClipCommand::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject MoveClipCommand::staticMetaObject = {
    { &ClipCommandBase::staticMetaObject, qt_meta_stringdata_MoveClipCommand.data,
      qt_meta_data_MoveClipCommand,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MoveClipCommand::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MoveClipCommand::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MoveClipCommand.stringdata))
        return static_cast<void*>(const_cast< MoveClipCommand*>(this));
    return ClipCommandBase::qt_metacast(_clname);
}

int MoveClipCommand::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ClipCommandBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_CopyClipCommand_t {
    QByteArrayData data[1];
    char stringdata[16];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CopyClipCommand_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CopyClipCommand_t qt_meta_stringdata_CopyClipCommand = {
    {
QT_MOC_LITERAL(0, 0, 15) // "CopyClipCommand"

    },
    "CopyClipCommand"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CopyClipCommand[] = {

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

void CopyClipCommand::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject CopyClipCommand::staticMetaObject = {
    { &ClipCommandBase::staticMetaObject, qt_meta_stringdata_CopyClipCommand.data,
      qt_meta_data_CopyClipCommand,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CopyClipCommand::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CopyClipCommand::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CopyClipCommand.stringdata))
        return static_cast<void*>(const_cast< CopyClipCommand*>(this));
    return ClipCommandBase::qt_metacast(_clname);
}

int CopyClipCommand::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ClipCommandBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_SplitClipCommand_t {
    QByteArrayData data[1];
    char stringdata[17];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SplitClipCommand_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SplitClipCommand_t qt_meta_stringdata_SplitClipCommand = {
    {
QT_MOC_LITERAL(0, 0, 16) // "SplitClipCommand"

    },
    "SplitClipCommand"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SplitClipCommand[] = {

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

void SplitClipCommand::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject SplitClipCommand::staticMetaObject = {
    { &ClipCommandBase::staticMetaObject, qt_meta_stringdata_SplitClipCommand.data,
      qt_meta_data_SplitClipCommand,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SplitClipCommand::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SplitClipCommand::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SplitClipCommand.stringdata))
        return static_cast<void*>(const_cast< SplitClipCommand*>(this));
    return ClipCommandBase::qt_metacast(_clname);
}

int SplitClipCommand::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ClipCommandBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_AdjustClipCommand_t {
    QByteArrayData data[1];
    char stringdata[18];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AdjustClipCommand_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AdjustClipCommand_t qt_meta_stringdata_AdjustClipCommand = {
    {
QT_MOC_LITERAL(0, 0, 17) // "AdjustClipCommand"

    },
    "AdjustClipCommand"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AdjustClipCommand[] = {

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

void AdjustClipCommand::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject AdjustClipCommand::staticMetaObject = {
    { &ClipCommandBase::staticMetaObject, qt_meta_stringdata_AdjustClipCommand.data,
      qt_meta_data_AdjustClipCommand,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AdjustClipCommand::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AdjustClipCommand::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AdjustClipCommand.stringdata))
        return static_cast<void*>(const_cast< AdjustClipCommand*>(this));
    return ClipCommandBase::qt_metacast(_clname);
}

int AdjustClipCommand::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ClipCommandBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_CropClipCommand_t {
    QByteArrayData data[1];
    char stringdata[16];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CropClipCommand_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CropClipCommand_t qt_meta_stringdata_CropClipCommand = {
    {
QT_MOC_LITERAL(0, 0, 15) // "CropClipCommand"

    },
    "CropClipCommand"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CropClipCommand[] = {

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

void CropClipCommand::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject CropClipCommand::staticMetaObject = {
    { &ClipCommandBase::staticMetaObject, qt_meta_stringdata_CropClipCommand.data,
      qt_meta_data_CropClipCommand,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CropClipCommand::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CropClipCommand::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CropClipCommand.stringdata))
        return static_cast<void*>(const_cast< CropClipCommand*>(this));
    return ClipCommandBase::qt_metacast(_clname);
}

int CropClipCommand::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ClipCommandBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_TrackCommondBase_t {
    QByteArrayData data[3];
    char stringdata[37];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TrackCommondBase_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TrackCommondBase_t qt_meta_stringdata_TrackCommondBase = {
    {
QT_MOC_LITERAL(0, 0, 16), // "TrackCommondBase"
QT_MOC_LITERAL(1, 17, 18), // "signalTrackChanged"
QT_MOC_LITERAL(2, 36, 0) // ""

    },
    "TrackCommondBase\0signalTrackChanged\0"
    ""
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TrackCommondBase[] = {

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
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void TrackCommondBase::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TrackCommondBase *_t = static_cast<TrackCommondBase *>(_o);
        switch (_id) {
        case 0: _t->signalTrackChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TrackCommondBase::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TrackCommondBase::signalTrackChanged)) {
                *result = 0;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject TrackCommondBase::staticMetaObject = {
    { &UndoCommandBase::staticMetaObject, qt_meta_stringdata_TrackCommondBase.data,
      qt_meta_data_TrackCommondBase,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TrackCommondBase::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TrackCommondBase::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TrackCommondBase.stringdata))
        return static_cast<void*>(const_cast< TrackCommondBase*>(this));
    return UndoCommandBase::qt_metacast(_clname);
}

int TrackCommondBase::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = UndoCommandBase::qt_metacall(_c, _id, _a);
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
void TrackCommondBase::signalTrackChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
struct qt_meta_stringdata_AddTrackCommond_t {
    QByteArrayData data[1];
    char stringdata[16];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AddTrackCommond_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AddTrackCommond_t qt_meta_stringdata_AddTrackCommond = {
    {
QT_MOC_LITERAL(0, 0, 15) // "AddTrackCommond"

    },
    "AddTrackCommond"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AddTrackCommond[] = {

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

void AddTrackCommond::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject AddTrackCommond::staticMetaObject = {
    { &TrackCommondBase::staticMetaObject, qt_meta_stringdata_AddTrackCommond.data,
      qt_meta_data_AddTrackCommond,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AddTrackCommond::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AddTrackCommond::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AddTrackCommond.stringdata))
        return static_cast<void*>(const_cast< AddTrackCommond*>(this));
    return TrackCommondBase::qt_metacast(_clname);
}

int AddTrackCommond::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TrackCommondBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_RemoveTrackCommond_t {
    QByteArrayData data[1];
    char stringdata[19];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RemoveTrackCommond_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RemoveTrackCommond_t qt_meta_stringdata_RemoveTrackCommond = {
    {
QT_MOC_LITERAL(0, 0, 18) // "RemoveTrackCommond"

    },
    "RemoveTrackCommond"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RemoveTrackCommond[] = {

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

void RemoveTrackCommond::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject RemoveTrackCommond::staticMetaObject = {
    { &TrackCommondBase::staticMetaObject, qt_meta_stringdata_RemoveTrackCommond.data,
      qt_meta_data_RemoveTrackCommond,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *RemoveTrackCommond::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RemoveTrackCommond::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_RemoveTrackCommond.stringdata))
        return static_cast<void*>(const_cast< RemoveTrackCommond*>(this));
    return TrackCommondBase::qt_metacast(_clname);
}

int RemoveTrackCommond::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TrackCommondBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_MoveTrackCommond_t {
    QByteArrayData data[1];
    char stringdata[17];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MoveTrackCommond_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MoveTrackCommond_t qt_meta_stringdata_MoveTrackCommond = {
    {
QT_MOC_LITERAL(0, 0, 16) // "MoveTrackCommond"

    },
    "MoveTrackCommond"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MoveTrackCommond[] = {

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

void MoveTrackCommond::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject MoveTrackCommond::staticMetaObject = {
    { &TrackCommondBase::staticMetaObject, qt_meta_stringdata_MoveTrackCommond.data,
      qt_meta_data_MoveTrackCommond,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MoveTrackCommond::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MoveTrackCommond::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MoveTrackCommond.stringdata))
        return static_cast<void*>(const_cast< MoveTrackCommond*>(this));
    return TrackCommondBase::qt_metacast(_clname);
}

int MoveTrackCommond::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TrackCommondBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_SwapTrackCommond_t {
    QByteArrayData data[1];
    char stringdata[17];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SwapTrackCommond_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SwapTrackCommond_t qt_meta_stringdata_SwapTrackCommond = {
    {
QT_MOC_LITERAL(0, 0, 16) // "SwapTrackCommond"

    },
    "SwapTrackCommond"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SwapTrackCommond[] = {

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

void SwapTrackCommond::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject SwapTrackCommond::staticMetaObject = {
    { &TrackCommondBase::staticMetaObject, qt_meta_stringdata_SwapTrackCommond.data,
      qt_meta_data_SwapTrackCommond,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SwapTrackCommond::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SwapTrackCommond::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SwapTrackCommond.stringdata))
        return static_cast<void*>(const_cast< SwapTrackCommond*>(this));
    return TrackCommondBase::qt_metacast(_clname);
}

int SwapTrackCommond::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TrackCommondBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE

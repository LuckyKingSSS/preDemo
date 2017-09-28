/****************************************************************************
** Meta object code from reading C++ file 'matterviewprivate.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../matterviewprivate.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'matterviewprivate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MatterViewPrivate_t {
    QByteArrayData data[4];
    char stringdata[43];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MatterViewPrivate_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MatterViewPrivate_t qt_meta_stringdata_MatterViewPrivate = {
    {
QT_MOC_LITERAL(0, 0, 17), // "MatterViewPrivate"
QT_MOC_LITERAL(1, 18, 18), // "sigViewSizeChanged"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 4) // "size"

    },
    "MatterViewPrivate\0sigViewSizeChanged\0"
    "\0size"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MatterViewPrivate[] = {

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
    QMetaType::Void, QMetaType::QSize,    3,

       0        // eod
};

void MatterViewPrivate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MatterViewPrivate *_t = static_cast<MatterViewPrivate *>(_o);
        switch (_id) {
        case 0: _t->sigViewSizeChanged((*reinterpret_cast< QSize(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MatterViewPrivate::*_t)(QSize );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MatterViewPrivate::sigViewSizeChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject MatterViewPrivate::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MatterViewPrivate.data,
      qt_meta_data_MatterViewPrivate,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MatterViewPrivate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MatterViewPrivate::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MatterViewPrivate.stringdata))
        return static_cast<void*>(const_cast< MatterViewPrivate*>(this));
    return QWidget::qt_metacast(_clname);
}

int MatterViewPrivate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void MatterViewPrivate::sigViewSizeChanged(QSize _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_UpperView_t {
    QByteArrayData data[1];
    char stringdata[10];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UpperView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UpperView_t qt_meta_stringdata_UpperView = {
    {
QT_MOC_LITERAL(0, 0, 9) // "UpperView"

    },
    "UpperView"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UpperView[] = {

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

void UpperView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject UpperView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_UpperView.data,
      qt_meta_data_UpperView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *UpperView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UpperView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_UpperView.stringdata))
        return static_cast<void*>(const_cast< UpperView*>(this));
    return QWidget::qt_metacast(_clname);
}

int UpperView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_ResViewArea_t {
    QByteArrayData data[9];
    char stringdata[107];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ResViewArea_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ResViewArea_t qt_meta_stringdata_ResViewArea = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ResViewArea"
QT_MOC_LITERAL(1, 12, 12), // "signalUnload"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 10), // "signalLoad"
QT_MOC_LITERAL(4, 37, 5), // "bPlay"
QT_MOC_LITERAL(5, 43, 20), // "slotImportBtnClicked"
QT_MOC_LITERAL(6, 64, 20), // "slotRemoveBtnClicked"
QT_MOC_LITERAL(7, 85, 18), // "slotToolBtnClicked"
QT_MOC_LITERAL(8, 104, 2) // "id"

    },
    "ResViewArea\0signalUnload\0\0signalLoad\0"
    "bPlay\0slotImportBtnClicked\0"
    "slotRemoveBtnClicked\0slotToolBtnClicked\0"
    "id"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ResViewArea[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    1,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   43,    2, 0x0a /* Public */,
       6,    0,   44,    2, 0x0a /* Public */,
       7,    1,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

void ResViewArea::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ResViewArea *_t = static_cast<ResViewArea *>(_o);
        switch (_id) {
        case 0: _t->signalUnload(); break;
        case 1: _t->signalLoad((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->slotImportBtnClicked(); break;
        case 3: _t->slotRemoveBtnClicked(); break;
        case 4: _t->slotToolBtnClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ResViewArea::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ResViewArea::signalUnload)) {
                *result = 0;
            }
        }
        {
            typedef void (ResViewArea::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ResViewArea::signalLoad)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject ResViewArea::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ResViewArea.data,
      qt_meta_data_ResViewArea,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ResViewArea::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ResViewArea::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ResViewArea.stringdata))
        return static_cast<void*>(const_cast< ResViewArea*>(this));
    return QWidget::qt_metacast(_clname);
}

int ResViewArea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void ResViewArea::signalUnload()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void ResViewArea::signalLoad(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE

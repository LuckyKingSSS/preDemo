/****************************************************************************
** Meta object code from reading C++ file 'ResListView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../Controls/ResListView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ResListView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ResListWidget_t {
    QByteArrayData data[12];
    char stringdata[232];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ResListWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ResListWidget_t qt_meta_stringdata_ResListWidget = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ResListWidget"
QT_MOC_LITERAL(1, 14, 21), // "signalBlankAreaLClick"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 21), // "signalBlankAreaRClick"
QT_MOC_LITERAL(4, 59, 23), // "signalLBtnMultiSelected"
QT_MOC_LITERAL(5, 83, 23), // "QList<QListWidgetItem*>"
QT_MOC_LITERAL(6, 107, 24), // "signalLBtnSingleSelected"
QT_MOC_LITERAL(7, 132, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(8, 149, 26), // "signalLBtnDClickedSelected"
QT_MOC_LITERAL(9, 176, 28), // "signalLBtnSingleSelectedDown"
QT_MOC_LITERAL(10, 205, 23), // "signalShowSelectionRect"
QT_MOC_LITERAL(11, 229, 2) // "rc"

    },
    "ResListWidget\0signalBlankAreaLClick\0"
    "\0signalBlankAreaRClick\0signalLBtnMultiSelected\0"
    "QList<QListWidgetItem*>\0"
    "signalLBtnSingleSelected\0QListWidgetItem*\0"
    "signalLBtnDClickedSelected\0"
    "signalLBtnSingleSelectedDown\0"
    "signalShowSelectionRect\0rc"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ResListWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    1,   51,    2, 0x06 /* Public */,
       6,    1,   54,    2, 0x06 /* Public */,
       8,    1,   57,    2, 0x06 /* Public */,
       9,    1,   60,    2, 0x06 /* Public */,
      10,    2,   63,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, QMetaType::Bool, QMetaType::QRect,    2,   11,

       0        // eod
};

void ResListWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ResListWidget *_t = static_cast<ResListWidget *>(_o);
        switch (_id) {
        case 0: _t->signalBlankAreaLClick(); break;
        case 1: _t->signalBlankAreaRClick(); break;
        case 2: _t->signalLBtnMultiSelected((*reinterpret_cast< QList<QListWidgetItem*>(*)>(_a[1]))); break;
        case 3: _t->signalLBtnSingleSelected((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 4: _t->signalLBtnDClickedSelected((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 5: _t->signalLBtnSingleSelectedDown((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 6: _t->signalShowSelectionRect((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const QRect(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ResListWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ResListWidget::signalBlankAreaLClick)) {
                *result = 0;
            }
        }
        {
            typedef void (ResListWidget::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ResListWidget::signalBlankAreaRClick)) {
                *result = 1;
            }
        }
        {
            typedef void (ResListWidget::*_t)(QList<QListWidgetItem*> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ResListWidget::signalLBtnMultiSelected)) {
                *result = 2;
            }
        }
        {
            typedef void (ResListWidget::*_t)(QListWidgetItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ResListWidget::signalLBtnSingleSelected)) {
                *result = 3;
            }
        }
        {
            typedef void (ResListWidget::*_t)(QListWidgetItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ResListWidget::signalLBtnDClickedSelected)) {
                *result = 4;
            }
        }
        {
            typedef void (ResListWidget::*_t)(QListWidgetItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ResListWidget::signalLBtnSingleSelectedDown)) {
                *result = 5;
            }
        }
        {
            typedef void (ResListWidget::*_t)(bool , const QRect & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ResListWidget::signalShowSelectionRect)) {
                *result = 6;
            }
        }
    }
}

const QMetaObject ResListWidget::staticMetaObject = {
    { &QListWidget::staticMetaObject, qt_meta_stringdata_ResListWidget.data,
      qt_meta_data_ResListWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ResListWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ResListWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ResListWidget.stringdata))
        return static_cast<void*>(const_cast< ResListWidget*>(this));
    return QListWidget::qt_metacast(_clname);
}

int ResListWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void ResListWidget::signalBlankAreaLClick()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void ResListWidget::signalBlankAreaRClick()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void ResListWidget::signalLBtnMultiSelected(QList<QListWidgetItem*> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ResListWidget::signalLBtnSingleSelected(QListWidgetItem * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ResListWidget::signalLBtnDClickedSelected(QListWidgetItem * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ResListWidget::signalLBtnSingleSelectedDown(QListWidgetItem * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ResListWidget::signalShowSelectionRect(bool _t1, const QRect & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
struct qt_meta_stringdata_ResListView_t {
    QByteArrayData data[12];
    char stringdata[241];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ResListView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ResListView_t qt_meta_stringdata_ResListView = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ResListView"
QT_MOC_LITERAL(1, 12, 23), // "signalItemAddBtnClicked"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 13), // "ListItemData*"
QT_MOC_LITERAL(4, 51, 23), // "signalLBtnMultiSelected"
QT_MOC_LITERAL(5, 75, 23), // "QList<QListWidgetItem*>"
QT_MOC_LITERAL(6, 99, 24), // "signalLBtnSingleSelected"
QT_MOC_LITERAL(7, 124, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(8, 141, 26), // "signalLBtnDClickedSelected"
QT_MOC_LITERAL(9, 168, 28), // "signalLBtnSingleSelectedDown"
QT_MOC_LITERAL(10, 197, 21), // "signalBlankAreaLClick"
QT_MOC_LITERAL(11, 219, 21) // "signalBlankAreaRClick"

    },
    "ResListView\0signalItemAddBtnClicked\0"
    "\0ListItemData*\0signalLBtnMultiSelected\0"
    "QList<QListWidgetItem*>\0"
    "signalLBtnSingleSelected\0QListWidgetItem*\0"
    "signalLBtnDClickedSelected\0"
    "signalLBtnSingleSelectedDown\0"
    "signalBlankAreaLClick\0signalBlankAreaRClick"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ResListView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    1,   52,    2, 0x06 /* Public */,
       6,    1,   55,    2, 0x06 /* Public */,
       8,    1,   58,    2, 0x06 /* Public */,
       9,    1,   61,    2, 0x06 /* Public */,
      10,    0,   64,    2, 0x06 /* Public */,
      11,    0,   65,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ResListView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ResListView *_t = static_cast<ResListView *>(_o);
        switch (_id) {
        case 0: _t->signalItemAddBtnClicked((*reinterpret_cast< ListItemData*(*)>(_a[1]))); break;
        case 1: _t->signalLBtnMultiSelected((*reinterpret_cast< QList<QListWidgetItem*>(*)>(_a[1]))); break;
        case 2: _t->signalLBtnSingleSelected((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->signalLBtnDClickedSelected((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 4: _t->signalLBtnSingleSelectedDown((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 5: _t->signalBlankAreaLClick(); break;
        case 6: _t->signalBlankAreaRClick(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ResListView::*_t)(ListItemData * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ResListView::signalItemAddBtnClicked)) {
                *result = 0;
            }
        }
        {
            typedef void (ResListView::*_t)(QList<QListWidgetItem*> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ResListView::signalLBtnMultiSelected)) {
                *result = 1;
            }
        }
        {
            typedef void (ResListView::*_t)(QListWidgetItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ResListView::signalLBtnSingleSelected)) {
                *result = 2;
            }
        }
        {
            typedef void (ResListView::*_t)(QListWidgetItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ResListView::signalLBtnDClickedSelected)) {
                *result = 3;
            }
        }
        {
            typedef void (ResListView::*_t)(QListWidgetItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ResListView::signalLBtnSingleSelectedDown)) {
                *result = 4;
            }
        }
        {
            typedef void (ResListView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ResListView::signalBlankAreaLClick)) {
                *result = 5;
            }
        }
        {
            typedef void (ResListView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ResListView::signalBlankAreaRClick)) {
                *result = 6;
            }
        }
    }
}

const QMetaObject ResListView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ResListView.data,
      qt_meta_data_ResListView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ResListView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ResListView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ResListView.stringdata))
        return static_cast<void*>(const_cast< ResListView*>(this));
    return QWidget::qt_metacast(_clname);
}

int ResListView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void ResListView::signalItemAddBtnClicked(ListItemData * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ResListView::signalLBtnMultiSelected(QList<QListWidgetItem*> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ResListView::signalLBtnSingleSelected(QListWidgetItem * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ResListView::signalLBtnDClickedSelected(QListWidgetItem * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ResListView::signalLBtnSingleSelectedDown(QListWidgetItem * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ResListView::signalBlankAreaLClick()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void ResListView::signalBlankAreaRClick()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}
struct qt_meta_stringdata_SelectionWidget_t {
    QByteArrayData data[1];
    char stringdata[16];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SelectionWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SelectionWidget_t qt_meta_stringdata_SelectionWidget = {
    {
QT_MOC_LITERAL(0, 0, 15) // "SelectionWidget"

    },
    "SelectionWidget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SelectionWidget[] = {

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

void SelectionWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject SelectionWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SelectionWidget.data,
      qt_meta_data_SelectionWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SelectionWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SelectionWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SelectionWidget.stringdata))
        return static_cast<void*>(const_cast< SelectionWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int SelectionWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE

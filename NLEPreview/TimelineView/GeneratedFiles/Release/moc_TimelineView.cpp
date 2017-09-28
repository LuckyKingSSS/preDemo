/****************************************************************************
** Meta object code from reading C++ file 'TimelineView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../../include/inc_TimelineView/TimelineView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TimelineView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TimelineView_t {
    QByteArrayData data[16];
    char stringdata[201];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TimelineView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TimelineView_t qt_meta_stringdata_TimelineView = {
    {
QT_MOC_LITERAL(0, 0, 12), // "TimelineView"
QT_MOC_LITERAL(1, 13, 11), // "StartSeekTo"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 9), // "EndSeekTo"
QT_MOC_LITERAL(4, 36, 6), // "SeekTo"
QT_MOC_LITERAL(5, 43, 6), // "frames"
QT_MOC_LITERAL(6, 50, 5), // "Pause"
QT_MOC_LITERAL(7, 56, 4), // "Play"
QT_MOC_LITERAL(8, 61, 15), // "DurationChanged"
QT_MOC_LITERAL(9, 77, 18), // "ComplexClipChanged"
QT_MOC_LITERAL(10, 96, 12), // "NLETimeline*"
QT_MOC_LITERAL(11, 109, 8), // "timeline"
QT_MOC_LITERAL(12, 118, 21), // "TimelineSelectChanged"
QT_MOC_LITERAL(13, 140, 17), // "pSelectedTimeline"
QT_MOC_LITERAL(14, 158, 27), // "TimelineDoubleSelectChanged"
QT_MOC_LITERAL(15, 186, 14) // "TimelineDelete"

    },
    "TimelineView\0StartSeekTo\0\0EndSeekTo\0"
    "SeekTo\0frames\0Pause\0Play\0DurationChanged\0"
    "ComplexClipChanged\0NLETimeline*\0"
    "timeline\0TimelineSelectChanged\0"
    "pSelectedTimeline\0TimelineDoubleSelectChanged\0"
    "TimelineDelete"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TimelineView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    1,   66,    2, 0x06 /* Public */,
       6,    0,   69,    2, 0x06 /* Public */,
       7,    0,   70,    2, 0x06 /* Public */,
       8,    0,   71,    2, 0x06 /* Public */,
       9,    1,   72,    2, 0x06 /* Public */,
      12,    1,   75,    2, 0x06 /* Public */,
      14,    1,   78,    2, 0x06 /* Public */,
      15,    1,   81,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10,   13,
    QMetaType::Void, 0x80000000 | 10,   13,
    QMetaType::Void, 0x80000000 | 10,   13,

       0        // eod
};

void TimelineView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TimelineView *_t = static_cast<TimelineView *>(_o);
        switch (_id) {
        case 0: _t->StartSeekTo(); break;
        case 1: _t->EndSeekTo(); break;
        case 2: _t->SeekTo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->Pause(); break;
        case 4: _t->Play(); break;
        case 5: _t->DurationChanged(); break;
        case 6: _t->ComplexClipChanged((*reinterpret_cast< NLETimeline*(*)>(_a[1]))); break;
        case 7: _t->TimelineSelectChanged((*reinterpret_cast< NLETimeline*(*)>(_a[1]))); break;
        case 8: _t->TimelineDoubleSelectChanged((*reinterpret_cast< NLETimeline*(*)>(_a[1]))); break;
        case 9: _t->TimelineDelete((*reinterpret_cast< NLETimeline*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TimelineView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineView::StartSeekTo)) {
                *result = 0;
            }
        }
        {
            typedef void (TimelineView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineView::EndSeekTo)) {
                *result = 1;
            }
        }
        {
            typedef void (TimelineView::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineView::SeekTo)) {
                *result = 2;
            }
        }
        {
            typedef void (TimelineView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineView::Pause)) {
                *result = 3;
            }
        }
        {
            typedef void (TimelineView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineView::Play)) {
                *result = 4;
            }
        }
        {
            typedef void (TimelineView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineView::DurationChanged)) {
                *result = 5;
            }
        }
        {
            typedef void (TimelineView::*_t)(NLETimeline * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineView::ComplexClipChanged)) {
                *result = 6;
            }
        }
        {
            typedef void (TimelineView::*_t)(NLETimeline * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineView::TimelineSelectChanged)) {
                *result = 7;
            }
        }
        {
            typedef void (TimelineView::*_t)(NLETimeline * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineView::TimelineDoubleSelectChanged)) {
                *result = 8;
            }
        }
        {
            typedef void (TimelineView::*_t)(NLETimeline * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineView::TimelineDelete)) {
                *result = 9;
            }
        }
    }
}

const QMetaObject TimelineView::staticMetaObject = {
    { &NLEBaseWidget::staticMetaObject, qt_meta_stringdata_TimelineView.data,
      qt_meta_data_TimelineView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TimelineView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TimelineView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TimelineView.stringdata))
        return static_cast<void*>(const_cast< TimelineView*>(this));
    return NLEBaseWidget::qt_metacast(_clname);
}

int TimelineView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = NLEBaseWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void TimelineView::StartSeekTo()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void TimelineView::EndSeekTo()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void TimelineView::SeekTo(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TimelineView::Pause()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void TimelineView::Play()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void TimelineView::DurationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void TimelineView::ComplexClipChanged(NLETimeline * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void TimelineView::TimelineSelectChanged(NLETimeline * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void TimelineView::TimelineDoubleSelectChanged(NLETimeline * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void TimelineView::TimelineDelete(NLETimeline * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_END_MOC_NAMESPACE

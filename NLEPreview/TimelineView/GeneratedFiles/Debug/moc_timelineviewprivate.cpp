/****************************************************************************
** Meta object code from reading C++ file 'timelineviewprivate.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../timelineviewprivate.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'timelineviewprivate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TimelineViewPrivate_t {
    QByteArrayData data[19];
    char stringdata[246];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TimelineViewPrivate_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TimelineViewPrivate_t qt_meta_stringdata_TimelineViewPrivate = {
    {
QT_MOC_LITERAL(0, 0, 19), // "TimelineViewPrivate"
QT_MOC_LITERAL(1, 20, 11), // "StartSeekTo"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 9), // "EndSeekTo"
QT_MOC_LITERAL(4, 43, 6), // "SeekTo"
QT_MOC_LITERAL(5, 50, 6), // "frames"
QT_MOC_LITERAL(6, 57, 4), // "Play"
QT_MOC_LITERAL(7, 62, 5), // "Pause"
QT_MOC_LITERAL(8, 68, 15), // "DurationChanged"
QT_MOC_LITERAL(9, 84, 18), // "ComplexClipChanged"
QT_MOC_LITERAL(10, 103, 12), // "NLETimeline*"
QT_MOC_LITERAL(11, 116, 8), // "timeline"
QT_MOC_LITERAL(12, 125, 21), // "CurrentFramesOutRuler"
QT_MOC_LITERAL(13, 147, 5), // "right"
QT_MOC_LITERAL(14, 153, 21), // "TimelineSelectChanged"
QT_MOC_LITERAL(15, 175, 9), // "pSelected"
QT_MOC_LITERAL(16, 185, 27), // "TimelineDoubleSelectChanged"
QT_MOC_LITERAL(17, 213, 17), // "pSelectedTimeline"
QT_MOC_LITERAL(18, 231, 14) // "TimelineDelete"

    },
    "TimelineViewPrivate\0StartSeekTo\0\0"
    "EndSeekTo\0SeekTo\0frames\0Play\0Pause\0"
    "DurationChanged\0ComplexClipChanged\0"
    "NLETimeline*\0timeline\0CurrentFramesOutRuler\0"
    "right\0TimelineSelectChanged\0pSelected\0"
    "TimelineDoubleSelectChanged\0"
    "pSelectedTimeline\0TimelineDelete"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TimelineViewPrivate[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    0,   70,    2, 0x06 /* Public */,
       4,    1,   71,    2, 0x06 /* Public */,
       6,    0,   74,    2, 0x06 /* Public */,
       7,    0,   75,    2, 0x06 /* Public */,
       8,    0,   76,    2, 0x06 /* Public */,
       9,    1,   77,    2, 0x06 /* Public */,
      12,    1,   80,    2, 0x06 /* Public */,
      14,    1,   83,    2, 0x06 /* Public */,
      16,    1,   86,    2, 0x06 /* Public */,
      18,    1,   89,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void, 0x80000000 | 10,   15,
    QMetaType::Void, 0x80000000 | 10,   17,
    QMetaType::Void, 0x80000000 | 10,   17,

       0        // eod
};

void TimelineViewPrivate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TimelineViewPrivate *_t = static_cast<TimelineViewPrivate *>(_o);
        switch (_id) {
        case 0: _t->StartSeekTo(); break;
        case 1: _t->EndSeekTo(); break;
        case 2: _t->SeekTo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->Play(); break;
        case 4: _t->Pause(); break;
        case 5: _t->DurationChanged(); break;
        case 6: _t->ComplexClipChanged((*reinterpret_cast< NLETimeline*(*)>(_a[1]))); break;
        case 7: _t->CurrentFramesOutRuler((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->TimelineSelectChanged((*reinterpret_cast< NLETimeline*(*)>(_a[1]))); break;
        case 9: _t->TimelineDoubleSelectChanged((*reinterpret_cast< NLETimeline*(*)>(_a[1]))); break;
        case 10: _t->TimelineDelete((*reinterpret_cast< NLETimeline*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TimelineViewPrivate::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineViewPrivate::StartSeekTo)) {
                *result = 0;
            }
        }
        {
            typedef void (TimelineViewPrivate::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineViewPrivate::EndSeekTo)) {
                *result = 1;
            }
        }
        {
            typedef void (TimelineViewPrivate::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineViewPrivate::SeekTo)) {
                *result = 2;
            }
        }
        {
            typedef void (TimelineViewPrivate::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineViewPrivate::Play)) {
                *result = 3;
            }
        }
        {
            typedef void (TimelineViewPrivate::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineViewPrivate::Pause)) {
                *result = 4;
            }
        }
        {
            typedef void (TimelineViewPrivate::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineViewPrivate::DurationChanged)) {
                *result = 5;
            }
        }
        {
            typedef void (TimelineViewPrivate::*_t)(NLETimeline * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineViewPrivate::ComplexClipChanged)) {
                *result = 6;
            }
        }
        {
            typedef void (TimelineViewPrivate::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineViewPrivate::CurrentFramesOutRuler)) {
                *result = 7;
            }
        }
        {
            typedef void (TimelineViewPrivate::*_t)(NLETimeline * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineViewPrivate::TimelineSelectChanged)) {
                *result = 8;
            }
        }
        {
            typedef void (TimelineViewPrivate::*_t)(NLETimeline * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineViewPrivate::TimelineDoubleSelectChanged)) {
                *result = 9;
            }
        }
        {
            typedef void (TimelineViewPrivate::*_t)(NLETimeline * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineViewPrivate::TimelineDelete)) {
                *result = 10;
            }
        }
    }
}

const QMetaObject TimelineViewPrivate::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TimelineViewPrivate.data,
      qt_meta_data_TimelineViewPrivate,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TimelineViewPrivate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TimelineViewPrivate::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TimelineViewPrivate.stringdata))
        return static_cast<void*>(const_cast< TimelineViewPrivate*>(this));
    return QWidget::qt_metacast(_clname);
}

int TimelineViewPrivate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void TimelineViewPrivate::StartSeekTo()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void TimelineViewPrivate::EndSeekTo()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void TimelineViewPrivate::SeekTo(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TimelineViewPrivate::Play()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void TimelineViewPrivate::Pause()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void TimelineViewPrivate::DurationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void TimelineViewPrivate::ComplexClipChanged(NLETimeline * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void TimelineViewPrivate::CurrentFramesOutRuler(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void TimelineViewPrivate::TimelineSelectChanged(NLETimeline * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void TimelineViewPrivate::TimelineDoubleSelectChanged(NLETimeline * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void TimelineViewPrivate::TimelineDelete(NLETimeline * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}
struct qt_meta_stringdata_TimelineViewTrackRulerToolBar_t {
    QByteArrayData data[7];
    char stringdata[103];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TimelineViewTrackRulerToolBar_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TimelineViewTrackRulerToolBar_t qt_meta_stringdata_TimelineViewTrackRulerToolBar = {
    {
QT_MOC_LITERAL(0, 0, 29), // "TimelineViewTrackRulerToolBar"
QT_MOC_LITERAL(1, 30, 13), // "ButtonClicked"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 2), // "id"
QT_MOC_LITERAL(4, 48, 21), // "ScaleUnitValueChanged"
QT_MOC_LITERAL(5, 70, 5), // "value"
QT_MOC_LITERAL(6, 76, 26) // "StartScaleUnitValueChanged"

    },
    "TimelineViewTrackRulerToolBar\0"
    "ButtonClicked\0\0id\0ScaleUnitValueChanged\0"
    "value\0StartScaleUnitValueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TimelineViewTrackRulerToolBar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    1,   32,    2, 0x06 /* Public */,
       6,    0,   35,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,

       0        // eod
};

void TimelineViewTrackRulerToolBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TimelineViewTrackRulerToolBar *_t = static_cast<TimelineViewTrackRulerToolBar *>(_o);
        switch (_id) {
        case 0: _t->ButtonClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->ScaleUnitValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->StartScaleUnitValueChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TimelineViewTrackRulerToolBar::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineViewTrackRulerToolBar::ButtonClicked)) {
                *result = 0;
            }
        }
        {
            typedef void (TimelineViewTrackRulerToolBar::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineViewTrackRulerToolBar::ScaleUnitValueChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (TimelineViewTrackRulerToolBar::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineViewTrackRulerToolBar::StartScaleUnitValueChanged)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject TimelineViewTrackRulerToolBar::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TimelineViewTrackRulerToolBar.data,
      qt_meta_data_TimelineViewTrackRulerToolBar,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TimelineViewTrackRulerToolBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TimelineViewTrackRulerToolBar::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TimelineViewTrackRulerToolBar.stringdata))
        return static_cast<void*>(const_cast< TimelineViewTrackRulerToolBar*>(this));
    return QWidget::qt_metacast(_clname);
}

int TimelineViewTrackRulerToolBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void TimelineViewTrackRulerToolBar::ButtonClicked(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TimelineViewTrackRulerToolBar::ScaleUnitValueChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TimelineViewTrackRulerToolBar::StartScaleUnitValueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE

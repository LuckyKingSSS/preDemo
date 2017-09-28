/****************************************************************************
** Meta object code from reading C++ file 'timelineviewtrack.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../timelineviewtrack.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'timelineviewtrack.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TimelineViewTrack_t {
    QByteArrayData data[13];
    char stringdata[167];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TimelineViewTrack_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TimelineViewTrack_t qt_meta_stringdata_TimelineViewTrack = {
    {
QT_MOC_LITERAL(0, 0, 17), // "TimelineViewTrack"
QT_MOC_LITERAL(1, 18, 5), // "Pause"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 15), // "DurationChanged"
QT_MOC_LITERAL(4, 41, 8), // "duration"
QT_MOC_LITERAL(5, 50, 17), // "TrackStateChanged"
QT_MOC_LITERAL(6, 68, 5), // "state"
QT_MOC_LITERAL(7, 74, 18), // "ComplexClipChanged"
QT_MOC_LITERAL(8, 93, 12), // "NLETimeline*"
QT_MOC_LITERAL(9, 106, 8), // "timeline"
QT_MOC_LITERAL(10, 115, 21), // "TimelineTrackScrollTo"
QT_MOC_LITERAL(11, 137, 3), // "pos"
QT_MOC_LITERAL(12, 141, 25) // "TimelineTrackScrollOffset"

    },
    "TimelineViewTrack\0Pause\0\0DurationChanged\0"
    "duration\0TrackStateChanged\0state\0"
    "ComplexClipChanged\0NLETimeline*\0"
    "timeline\0TimelineTrackScrollTo\0pos\0"
    "TimelineTrackScrollOffset"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TimelineViewTrack[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    1,   45,    2, 0x06 /* Public */,
       5,    1,   48,    2, 0x06 /* Public */,
       7,    1,   51,    2, 0x06 /* Public */,
      10,    1,   54,    2, 0x06 /* Public */,
      12,    1,   57,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,

       0        // eod
};

void TimelineViewTrack::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TimelineViewTrack *_t = static_cast<TimelineViewTrack *>(_o);
        switch (_id) {
        case 0: _t->Pause(); break;
        case 1: _t->DurationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->TrackStateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->ComplexClipChanged((*reinterpret_cast< NLETimeline*(*)>(_a[1]))); break;
        case 4: _t->TimelineTrackScrollTo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->TimelineTrackScrollOffset((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TimelineViewTrack::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineViewTrack::Pause)) {
                *result = 0;
            }
        }
        {
            typedef void (TimelineViewTrack::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineViewTrack::DurationChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (TimelineViewTrack::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineViewTrack::TrackStateChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (TimelineViewTrack::*_t)(NLETimeline * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineViewTrack::ComplexClipChanged)) {
                *result = 3;
            }
        }
        {
            typedef void (TimelineViewTrack::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineViewTrack::TimelineTrackScrollTo)) {
                *result = 4;
            }
        }
        {
            typedef void (TimelineViewTrack::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineViewTrack::TimelineTrackScrollOffset)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject TimelineViewTrack::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TimelineViewTrack.data,
      qt_meta_data_TimelineViewTrack,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TimelineViewTrack::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TimelineViewTrack::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TimelineViewTrack.stringdata))
        return static_cast<void*>(const_cast< TimelineViewTrack*>(this));
    return QWidget::qt_metacast(_clname);
}

int TimelineViewTrack::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void TimelineViewTrack::Pause()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void TimelineViewTrack::DurationChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TimelineViewTrack::TrackStateChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TimelineViewTrack::ComplexClipChanged(NLETimeline * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TimelineViewTrack::TimelineTrackScrollTo(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void TimelineViewTrack::TimelineTrackScrollOffset(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
struct qt_meta_stringdata_TimelineViewTrackItem_t {
    QByteArrayData data[5];
    char stringdata[66];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TimelineViewTrackItem_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TimelineViewTrackItem_t qt_meta_stringdata_TimelineViewTrackItem = {
    {
QT_MOC_LITERAL(0, 0, 21), // "TimelineViewTrackItem"
QT_MOC_LITERAL(1, 22, 13), // "ClipCollision"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 13), // "srcTrackIndex"
QT_MOC_LITERAL(4, 51, 14) // "destTrackIndex"

    },
    "TimelineViewTrackItem\0ClipCollision\0"
    "\0srcTrackIndex\0destTrackIndex"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TimelineViewTrackItem[] = {

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
       1,    2,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,

       0        // eod
};

void TimelineViewTrackItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TimelineViewTrackItem *_t = static_cast<TimelineViewTrackItem *>(_o);
        switch (_id) {
        case 0: _t->ClipCollision((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (TimelineViewTrackItem::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&TimelineViewTrackItem::ClipCollision)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject TimelineViewTrackItem::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TimelineViewTrackItem.data,
      qt_meta_data_TimelineViewTrackItem,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TimelineViewTrackItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TimelineViewTrackItem::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TimelineViewTrackItem.stringdata))
        return static_cast<void*>(const_cast< TimelineViewTrackItem*>(this));
    return QWidget::qt_metacast(_clname);
}

int TimelineViewTrackItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void TimelineViewTrackItem::ClipCollision(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_TimelineViewTrackItemHead_t {
    QByteArrayData data[1];
    char stringdata[26];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TimelineViewTrackItemHead_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TimelineViewTrackItemHead_t qt_meta_stringdata_TimelineViewTrackItemHead = {
    {
QT_MOC_LITERAL(0, 0, 25) // "TimelineViewTrackItemHead"

    },
    "TimelineViewTrackItemHead"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TimelineViewTrackItemHead[] = {

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

void TimelineViewTrackItemHead::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject TimelineViewTrackItemHead::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TimelineViewTrackItemHead.data,
      qt_meta_data_TimelineViewTrackItemHead,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TimelineViewTrackItemHead::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TimelineViewTrackItemHead::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TimelineViewTrackItemHead.stringdata))
        return static_cast<void*>(const_cast< TimelineViewTrackItemHead*>(this));
    return QWidget::qt_metacast(_clname);
}

int TimelineViewTrackItemHead::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_TimelineViewTrackItem_Video_t {
    QByteArrayData data[1];
    char stringdata[28];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TimelineViewTrackItem_Video_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TimelineViewTrackItem_Video_t qt_meta_stringdata_TimelineViewTrackItem_Video = {
    {
QT_MOC_LITERAL(0, 0, 27) // "TimelineViewTrackItem_Video"

    },
    "TimelineViewTrackItem_Video"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TimelineViewTrackItem_Video[] = {

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

void TimelineViewTrackItem_Video::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject TimelineViewTrackItem_Video::staticMetaObject = {
    { &TimelineViewTrackItem::staticMetaObject, qt_meta_stringdata_TimelineViewTrackItem_Video.data,
      qt_meta_data_TimelineViewTrackItem_Video,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TimelineViewTrackItem_Video::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TimelineViewTrackItem_Video::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TimelineViewTrackItem_Video.stringdata))
        return static_cast<void*>(const_cast< TimelineViewTrackItem_Video*>(this));
    return TimelineViewTrackItem::qt_metacast(_clname);
}

int TimelineViewTrackItem_Video::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TimelineViewTrackItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_TimelineViewTrackItem_Audio_t {
    QByteArrayData data[1];
    char stringdata[28];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TimelineViewTrackItem_Audio_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TimelineViewTrackItem_Audio_t qt_meta_stringdata_TimelineViewTrackItem_Audio = {
    {
QT_MOC_LITERAL(0, 0, 27) // "TimelineViewTrackItem_Audio"

    },
    "TimelineViewTrackItem_Audio"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TimelineViewTrackItem_Audio[] = {

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

void TimelineViewTrackItem_Audio::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject TimelineViewTrackItem_Audio::staticMetaObject = {
    { &TimelineViewTrackItem::staticMetaObject, qt_meta_stringdata_TimelineViewTrackItem_Audio.data,
      qt_meta_data_TimelineViewTrackItem_Audio,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TimelineViewTrackItem_Audio::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TimelineViewTrackItem_Audio::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TimelineViewTrackItem_Audio.stringdata))
        return static_cast<void*>(const_cast< TimelineViewTrackItem_Audio*>(this));
    return TimelineViewTrackItem::qt_metacast(_clname);
}

int TimelineViewTrackItem_Audio::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TimelineViewTrackItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_TimelineViewTrackItem_Effect_t {
    QByteArrayData data[1];
    char stringdata[29];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TimelineViewTrackItem_Effect_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TimelineViewTrackItem_Effect_t qt_meta_stringdata_TimelineViewTrackItem_Effect = {
    {
QT_MOC_LITERAL(0, 0, 28) // "TimelineViewTrackItem_Effect"

    },
    "TimelineViewTrackItem_Effect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TimelineViewTrackItem_Effect[] = {

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

void TimelineViewTrackItem_Effect::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject TimelineViewTrackItem_Effect::staticMetaObject = {
    { &TimelineViewTrackItem::staticMetaObject, qt_meta_stringdata_TimelineViewTrackItem_Effect.data,
      qt_meta_data_TimelineViewTrackItem_Effect,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TimelineViewTrackItem_Effect::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TimelineViewTrackItem_Effect::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TimelineViewTrackItem_Effect.stringdata))
        return static_cast<void*>(const_cast< TimelineViewTrackItem_Effect*>(this));
    return TimelineViewTrackItem::qt_metacast(_clname);
}

int TimelineViewTrackItem_Effect::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TimelineViewTrackItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_TimelineViewTrackItemDraw_t {
    QByteArrayData data[1];
    char stringdata[26];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TimelineViewTrackItemDraw_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TimelineViewTrackItemDraw_t qt_meta_stringdata_TimelineViewTrackItemDraw = {
    {
QT_MOC_LITERAL(0, 0, 25) // "TimelineViewTrackItemDraw"

    },
    "TimelineViewTrackItemDraw"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TimelineViewTrackItemDraw[] = {

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

void TimelineViewTrackItemDraw::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject TimelineViewTrackItemDraw::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TimelineViewTrackItemDraw.data,
      qt_meta_data_TimelineViewTrackItemDraw,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *TimelineViewTrackItemDraw::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TimelineViewTrackItemDraw::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_TimelineViewTrackItemDraw.stringdata))
        return static_cast<void*>(const_cast< TimelineViewTrackItemDraw*>(this));
    return QObject::qt_metacast(_clname);
}

int TimelineViewTrackItemDraw::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE

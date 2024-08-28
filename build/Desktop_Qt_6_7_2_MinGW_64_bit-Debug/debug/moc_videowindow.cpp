/****************************************************************************
** Meta object code from reading C++ file 'videowindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../videowindow.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'videowindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSVideoWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSVideoWindowENDCLASS = QtMocHelpers::stringData(
    "VideoWindow",
    "on_pushButton_clicked",
    "",
    "on_openButton_clicked",
    "on_playButton_clicked",
    "on_stopButton_clicked",
    "updateProgressBarPosition",
    "on_progressBar_sliderReleased",
    "on_progressBar_sliderMoved",
    "position",
    "getTime",
    "time",
    "updateTotalTime",
    "on_forwardButton_clicked",
    "on_backwardButton_clicked",
    "on_speedOptionBox_valueChanged",
    "arg1",
    "on_voiceButton_clicked",
    "on_voiceSlider_sliderReleased",
    "on_voiceSlider_valueChanged",
    "value",
    "endPlay",
    "QMediaPlayer::PlaybackState",
    "state"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSVideoWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  110,    2, 0x08,    1 /* Private */,
       3,    0,  111,    2, 0x08,    2 /* Private */,
       4,    0,  112,    2, 0x08,    3 /* Private */,
       5,    0,  113,    2, 0x08,    4 /* Private */,
       6,    0,  114,    2, 0x08,    5 /* Private */,
       7,    0,  115,    2, 0x08,    6 /* Private */,
       8,    1,  116,    2, 0x08,    7 /* Private */,
      10,    1,  119,    2, 0x08,    9 /* Private */,
      12,    0,  122,    2, 0x08,   11 /* Private */,
      13,    0,  123,    2, 0x08,   12 /* Private */,
      14,    0,  124,    2, 0x08,   13 /* Private */,
      15,    1,  125,    2, 0x08,   14 /* Private */,
      17,    0,  128,    2, 0x08,   16 /* Private */,
      18,    0,  129,    2, 0x08,   17 /* Private */,
      19,    1,  130,    2, 0x08,   18 /* Private */,
      21,    1,  133,    2, 0x08,   20 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::QString, QMetaType::LongLong,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, 0x80000000 | 22,   23,

       0        // eod
};

Q_CONSTINIT const QMetaObject VideoWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSVideoWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSVideoWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSVideoWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<VideoWindow, std::true_type>,
        // method 'on_pushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_openButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_playButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_stopButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateProgressBarPosition'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_progressBar_sliderReleased'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_progressBar_sliderMoved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getTime'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'updateTotalTime'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_forwardButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_backwardButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_speedOptionBox_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'on_voiceButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_voiceSlider_sliderReleased'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_voiceSlider_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'endPlay'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMediaPlayer::PlaybackState, std::false_type>
    >,
    nullptr
} };

void VideoWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VideoWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_openButton_clicked(); break;
        case 2: _t->on_playButton_clicked(); break;
        case 3: _t->on_stopButton_clicked(); break;
        case 4: _t->updateProgressBarPosition(); break;
        case 5: _t->on_progressBar_sliderReleased(); break;
        case 6: _t->on_progressBar_sliderMoved((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: { QString _r = _t->getTime((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->updateTotalTime(); break;
        case 9: _t->on_forwardButton_clicked(); break;
        case 10: _t->on_backwardButton_clicked(); break;
        case 11: _t->on_speedOptionBox_valueChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 12: _t->on_voiceButton_clicked(); break;
        case 13: _t->on_voiceSlider_sliderReleased(); break;
        case 14: _t->on_voiceSlider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 15: _t->endPlay((*reinterpret_cast< std::add_pointer_t<QMediaPlayer::PlaybackState>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *VideoWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VideoWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSVideoWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int VideoWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP

/****************************************************************************
** Meta object code from reading C++ file 'musicwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../musicwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'musicwindow.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSMusicWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMusicWindowENDCLASS = QtMocHelpers::stringData(
    "MusicWindow",
    "resizeEvent",
    "",
    "QResizeEvent*",
    "event",
    "updateCoverArtSize",
    "getSavedMusicPaths",
    "loadSavedMusic",
    "do_positionChanged",
    "position",
    "do_durationChanged",
    "duration",
    "do_sourceChanged",
    "media",
    "do_playbackStateChanged",
    "QMediaPlayer::PlaybackState",
    "newState",
    "do_metaDataChanged",
    "initializeFavorites",
    "on_btnAdd_clicked",
    "on_btnRemove_clicked",
    "on_btnClear_clicked",
    "on_btnPlay_clicked",
    "on_btnPause_clicked",
    "on_btnStop_clicked",
    "on_btnPrevious_clicked",
    "on_btnNext_clicked",
    "on_doubleSpinBox_valueChanged",
    "arg1",
    "on_btnLoop_clicked",
    "checked",
    "on_btnSound_clicked",
    "on_sliderVolumn_valueChanged",
    "value",
    "on_sliderPosition_valueChanged",
    "on_listWidget_doubleClicked",
    "QModelIndex",
    "index",
    "on_btnCover_clicked",
    "on_btnSearch_clicked",
    "onSearchFinished",
    "QNetworkReply*",
    "reply",
    "on_pushButton_clicked",
    "lrcWidget_sliderMoved",
    "lrcWidget_playPauseToggled",
    "lrcWidget_prevClicked",
    "lrcWidget_nextClicked",
    "lrcWidget_volumeChanged",
    "lrcWidget_speedChanged",
    "lrcWidget_modeChanged",
    "lrcWidget_sliderPressed",
    "lrcWidget_sliderReleased",
    "on_btnmin_clicked",
    "on_label_linkActivated",
    "link",
    "on_love_button_clicked",
    "on_listWidget_2_itemClicked",
    "QListWidgetItem*",
    "item"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMusicWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      41,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  260,    2, 0x08,    1 /* Private */,
       5,    0,  263,    2, 0x08,    3 /* Private */,
       6,    0,  264,    2, 0x08,    4 /* Private */,
       7,    0,  265,    2, 0x08,    5 /* Private */,
       8,    1,  266,    2, 0x08,    6 /* Private */,
      10,    1,  269,    2, 0x08,    8 /* Private */,
      12,    1,  272,    2, 0x08,   10 /* Private */,
      14,    1,  275,    2, 0x08,   12 /* Private */,
      17,    0,  278,    2, 0x08,   14 /* Private */,
      18,    0,  279,    2, 0x08,   15 /* Private */,
      19,    0,  280,    2, 0x08,   16 /* Private */,
      20,    0,  281,    2, 0x08,   17 /* Private */,
      21,    0,  282,    2, 0x08,   18 /* Private */,
      22,    0,  283,    2, 0x08,   19 /* Private */,
      23,    0,  284,    2, 0x08,   20 /* Private */,
      24,    0,  285,    2, 0x08,   21 /* Private */,
      25,    0,  286,    2, 0x08,   22 /* Private */,
      26,    0,  287,    2, 0x08,   23 /* Private */,
      27,    1,  288,    2, 0x08,   24 /* Private */,
      29,    1,  291,    2, 0x08,   26 /* Private */,
      31,    0,  294,    2, 0x08,   28 /* Private */,
      32,    1,  295,    2, 0x08,   29 /* Private */,
      34,    1,  298,    2, 0x08,   31 /* Private */,
      35,    1,  301,    2, 0x08,   33 /* Private */,
      38,    0,  304,    2, 0x08,   35 /* Private */,
      39,    0,  305,    2, 0x08,   36 /* Private */,
      40,    1,  306,    2, 0x08,   37 /* Private */,
      43,    0,  309,    2, 0x08,   39 /* Private */,
      44,    1,  310,    2, 0x08,   40 /* Private */,
      45,    0,  313,    2, 0x08,   42 /* Private */,
      46,    0,  314,    2, 0x08,   43 /* Private */,
      47,    0,  315,    2, 0x08,   44 /* Private */,
      48,    1,  316,    2, 0x08,   45 /* Private */,
      49,    1,  319,    2, 0x08,   47 /* Private */,
      50,    0,  322,    2, 0x08,   49 /* Private */,
      51,    0,  323,    2, 0x08,   50 /* Private */,
      52,    0,  324,    2, 0x08,   51 /* Private */,
      53,    0,  325,    2, 0x08,   52 /* Private */,
      54,    1,  326,    2, 0x08,   53 /* Private */,
      56,    0,  329,    2, 0x08,   55 /* Private */,
      57,    1,  330,    2, 0x08,   56 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::QStringList,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,    9,
    QMetaType::Void, QMetaType::LongLong,   11,
    QMetaType::Void, QMetaType::QUrl,   13,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   28,
    QMetaType::Void, QMetaType::Bool,   30,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   33,
    QMetaType::Void, QMetaType::Int,   33,
    QMetaType::Void, 0x80000000 | 36,   37,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 41,   42,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   33,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   33,
    QMetaType::Void, QMetaType::Double,   33,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   55,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 58,   59,

       0        // eod
};

Q_CONSTINIT const QMetaObject MusicWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMusicWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMusicWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMusicWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MusicWindow, std::true_type>,
        // method 'resizeEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QResizeEvent *, std::false_type>,
        // method 'updateCoverArtSize'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'getSavedMusicPaths'
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        // method 'loadSavedMusic'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'do_positionChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'do_durationChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'do_sourceChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QUrl &, std::false_type>,
        // method 'do_playbackStateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMediaPlayer::PlaybackState, std::false_type>,
        // method 'do_metaDataChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'initializeFavorites'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnAdd_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnRemove_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnClear_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnPlay_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnPause_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnStop_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnPrevious_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnNext_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_doubleSpinBox_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'on_btnLoop_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_btnSound_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_sliderVolumn_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_sliderPosition_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_listWidget_doubleClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'on_btnCover_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnSearch_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSearchFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QNetworkReply *, std::false_type>,
        // method 'on_pushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'lrcWidget_sliderMoved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'lrcWidget_playPauseToggled'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'lrcWidget_prevClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'lrcWidget_nextClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'lrcWidget_volumeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'lrcWidget_speedChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'lrcWidget_modeChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'lrcWidget_sliderPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'lrcWidget_sliderReleased'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btnmin_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_label_linkActivated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_love_button_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_listWidget_2_itemClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>
    >,
    nullptr
} };

void MusicWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MusicWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->resizeEvent((*reinterpret_cast< std::add_pointer_t<QResizeEvent*>>(_a[1]))); break;
        case 1: _t->updateCoverArtSize(); break;
        case 2: { QStringList _r = _t->getSavedMusicPaths();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->loadSavedMusic(); break;
        case 4: _t->do_positionChanged((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 5: _t->do_durationChanged((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 6: _t->do_sourceChanged((*reinterpret_cast< std::add_pointer_t<QUrl>>(_a[1]))); break;
        case 7: _t->do_playbackStateChanged((*reinterpret_cast< std::add_pointer_t<QMediaPlayer::PlaybackState>>(_a[1]))); break;
        case 8: _t->do_metaDataChanged(); break;
        case 9: _t->initializeFavorites(); break;
        case 10: _t->on_btnAdd_clicked(); break;
        case 11: _t->on_btnRemove_clicked(); break;
        case 12: _t->on_btnClear_clicked(); break;
        case 13: _t->on_btnPlay_clicked(); break;
        case 14: _t->on_btnPause_clicked(); break;
        case 15: _t->on_btnStop_clicked(); break;
        case 16: _t->on_btnPrevious_clicked(); break;
        case 17: _t->on_btnNext_clicked(); break;
        case 18: _t->on_doubleSpinBox_valueChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 19: _t->on_btnLoop_clicked((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 20: _t->on_btnSound_clicked(); break;
        case 21: _t->on_sliderVolumn_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 22: _t->on_sliderPosition_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 23: _t->on_listWidget_doubleClicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 24: _t->on_btnCover_clicked(); break;
        case 25: _t->on_btnSearch_clicked(); break;
        case 26: _t->onSearchFinished((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        case 27: _t->on_pushButton_clicked(); break;
        case 28: _t->lrcWidget_sliderMoved((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 29: _t->lrcWidget_playPauseToggled(); break;
        case 30: _t->lrcWidget_prevClicked(); break;
        case 31: _t->lrcWidget_nextClicked(); break;
        case 32: _t->lrcWidget_volumeChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 33: _t->lrcWidget_speedChanged((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 34: _t->lrcWidget_modeChanged(); break;
        case 35: _t->lrcWidget_sliderPressed(); break;
        case 36: _t->lrcWidget_sliderReleased(); break;
        case 37: _t->on_btnmin_clicked(); break;
        case 38: _t->on_label_linkActivated((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 39: _t->on_love_button_clicked(); break;
        case 40: _t->on_listWidget_2_itemClicked((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 26:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *MusicWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MusicWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMusicWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MusicWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 41)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 41;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 41)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 41;
    }
    return _id;
}
QT_WARNING_POP

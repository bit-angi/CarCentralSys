/****************************************************************************
** Meta object code from reading C++ file 'lrcwidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../lrcwidget.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lrcwidget.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSlrcwidgetENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSlrcwidgetENDCLASS = QtMocHelpers::stringData(
    "lrcwidget",
    "sliderMoved",
    "",
    "position",
    "sliderPressed",
    "sliderReleased",
    "on_horizontalSlider_sliderMoved",
    "on_horizontalSlider_sliderPressed",
    "on_horizontalSlider_sliderReleased",
    "updateLyrics",
    "on_pushButton_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSlrcwidgetENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x06,    1 /* Public */,
       4,    0,   65,    2, 0x06,    3 /* Public */,
       5,    0,   66,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    1,   67,    2, 0x08,    5 /* Private */,
       7,    0,   70,    2, 0x08,    7 /* Private */,
       8,    0,   71,    2, 0x08,    8 /* Private */,
       9,    1,   72,    2, 0x0a,    9 /* Public */,
      10,    0,   75,    2, 0x08,   11 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,    3,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject lrcwidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSlrcwidgetENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSlrcwidgetENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSlrcwidgetENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<lrcwidget, std::true_type>,
        // method 'sliderMoved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'sliderPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sliderReleased'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_horizontalSlider_sliderMoved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_horizontalSlider_sliderPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_horizontalSlider_sliderReleased'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateLyrics'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<qint64, std::false_type>,
        // method 'on_pushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void lrcwidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<lrcwidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sliderMoved((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->sliderPressed(); break;
        case 2: _t->sliderReleased(); break;
        case 3: _t->on_horizontalSlider_sliderMoved((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->on_horizontalSlider_sliderPressed(); break;
        case 5: _t->on_horizontalSlider_sliderReleased(); break;
        case 6: _t->updateLyrics((*reinterpret_cast< std::add_pointer_t<qint64>>(_a[1]))); break;
        case 7: _t->on_pushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (lrcwidget::*)(int );
            if (_t _q_method = &lrcwidget::sliderMoved; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (lrcwidget::*)();
            if (_t _q_method = &lrcwidget::sliderPressed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (lrcwidget::*)();
            if (_t _q_method = &lrcwidget::sliderReleased; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *lrcwidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *lrcwidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSlrcwidgetENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int lrcwidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void lrcwidget::sliderMoved(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void lrcwidget::sliderPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void lrcwidget::sliderReleased()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP

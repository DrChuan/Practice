/****************************************************************************
** Meta object code from reading C++ file 'EditWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Window/EditWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EditWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EditWindow_t {
    QByteArrayData data[14];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EditWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EditWindow_t qt_meta_stringdata_EditWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "EditWindow"
QT_MOC_LITERAL(1, 11, 6), // "setIce"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 7), // "setFire"
QT_MOC_LITERAL(4, 27, 7), // "setLeaf"
QT_MOC_LITERAL(5, 35, 9), // "clickItem"
QT_MOC_LITERAL(6, 45, 2), // "id"
QT_MOC_LITERAL(7, 48, 10), // "clickEnemy"
QT_MOC_LITERAL(8, 59, 9), // "clickGame"
QT_MOC_LITERAL(9, 69, 13), // "updateDrawObj"
QT_MOC_LITERAL(10, 83, 1), // "x"
QT_MOC_LITERAL(11, 85, 1), // "y"
QT_MOC_LITERAL(12, 87, 17), // "clickHelpBoardBtn"
QT_MOC_LITERAL(13, 105, 9) // "putSquare"

    },
    "EditWindow\0setIce\0\0setFire\0setLeaf\0"
    "clickItem\0id\0clickEnemy\0clickGame\0"
    "updateDrawObj\0x\0y\0clickHelpBoardBtn\0"
    "putSquare"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EditWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       3,    0,   60,    2, 0x0a /* Public */,
       4,    0,   61,    2, 0x0a /* Public */,
       5,    1,   62,    2, 0x0a /* Public */,
       7,    1,   65,    2, 0x0a /* Public */,
       8,    1,   68,    2, 0x0a /* Public */,
       9,    2,   71,    2, 0x0a /* Public */,
      12,    0,   76,    2, 0x0a /* Public */,
      13,    0,   77,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   10,   11,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void EditWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EditWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setIce(); break;
        case 1: _t->setFire(); break;
        case 2: _t->setLeaf(); break;
        case 3: _t->clickItem((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->clickEnemy((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->clickGame((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->updateDrawObj((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->clickHelpBoardBtn(); break;
        case 8: _t->putSquare(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject EditWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_EditWindow.data,
    qt_meta_data_EditWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *EditWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EditWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EditWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int EditWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

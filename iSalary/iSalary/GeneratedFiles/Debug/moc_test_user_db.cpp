/****************************************************************************
** Meta object code from reading C++ file 'test_user_db.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../test_user_db.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'test_user_db.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Test_User_DB_t {
    QByteArrayData data[7];
    char stringdata0[70];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Test_User_DB_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Test_User_DB_t qt_meta_stringdata_Test_User_DB = {
    {
QT_MOC_LITERAL(0, 0, 12), // "Test_User_DB"
QT_MOC_LITERAL(1, 13, 6), // "insert"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 7), // "getById"
QT_MOC_LITERAL(4, 29, 8), // "getByIds"
QT_MOC_LITERAL(5, 38, 11), // "findByLogin"
QT_MOC_LITERAL(6, 50, 19) // "findByLoginPassword"

    },
    "Test_User_DB\0insert\0\0getById\0getByIds\0"
    "findByLogin\0findByLoginPassword"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Test_User_DB[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Test_User_DB::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Test_User_DB *_t = static_cast<Test_User_DB *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->insert(); break;
        case 1: _t->getById(); break;
        case 2: _t->getByIds(); break;
        case 3: _t->findByLogin(); break;
        case 4: _t->findByLoginPassword(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Test_User_DB::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Test_User_DB.data,
      qt_meta_data_Test_User_DB,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Test_User_DB::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Test_User_DB::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Test_User_DB.stringdata0))
        return static_cast<void*>(const_cast< Test_User_DB*>(this));
    return QObject::qt_metacast(_clname);
}

int Test_User_DB::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE

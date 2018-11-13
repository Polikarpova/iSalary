/****************************************************************************
** Meta object code from reading C++ file 'EmployeesPage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../EmployeesPage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'EmployeesPage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_EmployeesPage_t {
    QByteArrayData data[9];
    char stringdata0[76];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EmployeesPage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EmployeesPage_t qt_meta_stringdata_EmployeesPage = {
    {
QT_MOC_LITERAL(0, 0, 13), // "EmployeesPage"
QT_MOC_LITERAL(1, 14, 11), // "showDetails"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 5), // "index"
QT_MOC_LITERAL(4, 33, 9), // "startEdit"
QT_MOC_LITERAL(5, 43, 8), // "startAdd"
QT_MOC_LITERAL(6, 52, 8), // "saveEdit"
QT_MOC_LITERAL(7, 61, 7), // "saveAdd"
QT_MOC_LITERAL(8, 69, 6) // "cancel"

    },
    "EmployeesPage\0showDetails\0\0index\0"
    "startEdit\0startAdd\0saveEdit\0saveAdd\0"
    "cancel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EmployeesPage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x09 /* Protected */,
       4,    0,   47,    2, 0x09 /* Protected */,
       5,    0,   48,    2, 0x09 /* Protected */,
       6,    0,   49,    2, 0x09 /* Protected */,
       7,    0,   50,    2, 0x09 /* Protected */,
       8,    0,   51,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void EmployeesPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EmployeesPage *_t = static_cast<EmployeesPage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showDetails((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->startEdit(); break;
        case 2: _t->startAdd(); break;
        case 3: _t->saveEdit(); break;
        case 4: _t->saveAdd(); break;
        case 5: _t->cancel(); break;
        default: ;
        }
    }
}

const QMetaObject EmployeesPage::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_EmployeesPage.data,
      qt_meta_data_EmployeesPage,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *EmployeesPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EmployeesPage::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_EmployeesPage.stringdata0))
        return static_cast<void*>(const_cast< EmployeesPage*>(this));
    return QObject::qt_metacast(_clname);
}

int EmployeesPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE

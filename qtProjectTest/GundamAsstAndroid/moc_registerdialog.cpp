/****************************************************************************
** Meta object code from reading C++ file 'registerdialog.h'
**
** Created: Sat Aug 2 16:57:01 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dialogs/registerdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'registerdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RegisterDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      58,   54,   49,   15, 0x08,
      77,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_RegisterDialog[] = {
    "RegisterDialog\0\0on_lineEdit_textChanged(QString)\0"
    "bool\0key\0verifyKey(QString)\0"
    "on_pushButton_pressed()\0"
};

void RegisterDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        RegisterDialog *_t = static_cast<RegisterDialog *>(_o);
        switch (_id) {
        case 0: _t->on_lineEdit_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: { bool _r = _t->verifyKey((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: _t->on_pushButton_pressed(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData RegisterDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject RegisterDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_RegisterDialog,
      qt_meta_data_RegisterDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RegisterDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RegisterDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RegisterDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RegisterDialog))
        return static_cast<void*>(const_cast< RegisterDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int RegisterDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

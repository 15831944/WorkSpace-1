/****************************************************************************
** Meta object code from reading C++ file 'phoneinfowidget.h'
**
** Created: Sat Aug 2 16:56:28 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "widgets/phoneinfowidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'phoneinfowidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PhoneInfoWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x08,
      41,   16,   16,   16, 0x08,
      76,   57,   16,   16, 0x08,
     107,   16,   16,   16, 0x08,
     127,   16,   16,   16, 0x08,
     144,   16,   16,   16, 0x08,
     168,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PhoneInfoWidget[] = {
    "PhoneInfoWidget\0\0on_pushButton_clicked()\0"
    "showPhoneInfo()\0image,width,height\0"
    "showScreenshot(QImage,int,int)\0"
    "refreshScreenshot()\0takeScreenshot()\0"
    "updateScreenshotLabel()\0saveScreenshot()\0"
};

void PhoneInfoWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PhoneInfoWidget *_t = static_cast<PhoneInfoWidget *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->showPhoneInfo(); break;
        case 2: _t->showScreenshot((*reinterpret_cast< QImage(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->refreshScreenshot(); break;
        case 4: _t->takeScreenshot(); break;
        case 5: _t->updateScreenshotLabel(); break;
        case 6: _t->saveScreenshot(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PhoneInfoWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PhoneInfoWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PhoneInfoWidget,
      qt_meta_data_PhoneInfoWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PhoneInfoWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PhoneInfoWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PhoneInfoWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PhoneInfoWidget))
        return static_cast<void*>(const_cast< PhoneInfoWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int PhoneInfoWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

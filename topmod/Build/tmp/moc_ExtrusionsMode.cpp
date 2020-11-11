/****************************************************************************
** Meta object code from reading C++ file 'ExtrusionsMode.hh'
**
** Created: Wed Jul 4 16:00:40 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ExtrusionsMode.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ExtrusionsMode.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ExtrusionsMode[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   16,   15,   15, 0x0a,
      40,   16,   15,   15, 0x0a,
      59,   16,   15,   15, 0x0a,
      78,   16,   15,   15, 0x0a,
      97,   16,   15,   15, 0x0a,
     114,   16,   15,   15, 0x0a,
     138,   16,   15,   15, 0x0a,
     162,   16,   15,   15, 0x0a,
     186,   16,   15,   15, 0x0a,
     208,   16,   15,   15, 0x0a,
     228,   16,   15,   15, 0x0a,
     248,   16,   15,   15, 0x0a,
     271,  265,   15,   15, 0x0a,
     305,  265,   15,   15, 0x0a,
     337,   16,   15,   15, 0x0a,
     370,   16,   15,   15, 0x0a,
     409,   16,   15,   15, 0x0a,
     447,   15,   15,   15, 0x0a,
     472,   15,   15,   15, 0x0a,
     496,   15,   15,   15, 0x0a,
     525,   15,   15,   15, 0x0a,
     553,   15,   15,   15, 0x0a,
     580,   15,   15,   15, 0x0a,
     605,   15,   15,   15, 0x0a,
     636,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ExtrusionsMode[] = {
    "ExtrusionsMode\0\0value\0setLength(double)\0"
    "setLength1(double)\0setLength2(double)\0"
    "setLength3(double)\0setAngle(double)\0"
    "setLength1Icosa(double)\0setLength2Icosa(double)\0"
    "setLength3Icosa(double)\0setAngleIcosa(double)\0"
    "setRotation(double)\0setSegments(double)\0"
    "setScale(double)\0state\0"
    "toggleCubicalTriangulateFace(int)\0"
    "toggleCubicalScherkCollins(int)\0"
    "ChangeScherkCollinsPinch(double)\0"
    "ChangeScherkCollinsPinchCenter(double)\0"
    "ChangeScherkCollinsPinchWidth(double)\0"
    "triggerDooSabinExtrude()\0"
    "triggerCubicalExtrude()\0"
    "triggerDodecahedralExtrude()\0"
    "triggerIcosahedralExtrude()\0"
    "triggerOctahedralExtrude()\0"
    "triggerStellateExtrude()\0"
    "triggerDoubleStellateExtrude()\0"
    "triggerDomeExtrude()\0"
};

void ExtrusionsMode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ExtrusionsMode *_t = static_cast<ExtrusionsMode *>(_o);
        switch (_id) {
        case 0: _t->setLength((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->setLength1((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->setLength2((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->setLength3((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->setAngle((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->setLength1Icosa((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->setLength2Icosa((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->setLength3Icosa((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->setAngleIcosa((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->setRotation((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->setSegments((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->setScale((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: _t->toggleCubicalTriangulateFace((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->toggleCubicalScherkCollins((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->ChangeScherkCollinsPinch((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: _t->ChangeScherkCollinsPinchCenter((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: _t->ChangeScherkCollinsPinchWidth((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 17: _t->triggerDooSabinExtrude(); break;
        case 18: _t->triggerCubicalExtrude(); break;
        case 19: _t->triggerDodecahedralExtrude(); break;
        case 20: _t->triggerIcosahedralExtrude(); break;
        case 21: _t->triggerOctahedralExtrude(); break;
        case 22: _t->triggerStellateExtrude(); break;
        case 23: _t->triggerDoubleStellateExtrude(); break;
        case 24: _t->triggerDomeExtrude(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ExtrusionsMode::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ExtrusionsMode::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ExtrusionsMode,
      qt_meta_data_ExtrusionsMode, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ExtrusionsMode::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ExtrusionsMode::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ExtrusionsMode::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ExtrusionsMode))
        return static_cast<void*>(const_cast< ExtrusionsMode*>(this));
    return QWidget::qt_metacast(_clname);
}

int ExtrusionsMode::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

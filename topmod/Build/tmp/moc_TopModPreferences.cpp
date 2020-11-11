/****************************************************************************
** Meta object code from reading C++ file 'TopModPreferences.hh'
**
** Created: Wed Jul 4 16:00:10 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../TopModPreferences.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TopModPreferences.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TopModPreferences[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x0a,
      34,   18,   18,   18, 0x0a,
      52,   18,   18,   18, 0x0a,
      71,   18,   18,   18, 0x0a,
      88,   18,   18,   18, 0x0a,
     108,   18,   18,   18, 0x0a,
     128,   18,   18,   18, 0x0a,
     148,   18,   18,   18, 0x0a,
     169,   18,   18,   18, 0x0a,
     193,   18,   18,   18, 0x0a,
     218,   18,   18,   18, 0x0a,
     241,   18,   18,   18, 0x0a,
     264,   18,   18,   18, 0x0a,
     285,   18,   18,   18, 0x0a,
     304,   18,   18,   18, 0x0a,
     323,   18,   18,   18, 0x0a,
     340,   18,   18,   18, 0x0a,
     363,   18,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TopModPreferences[] = {
    "TopModPreferences\0\0saveSettings()\0"
    "discardSettings()\0setViewportColor()\0"
    "setRenderColor()\0setCoolLightColor()\0"
    "setWarmLightColor()\0setWireframeColor()\0"
    "setSilhouetteColor()\0setPatchBoundaryColor()\0"
    "setSelectedVertexColor()\0"
    "setSelectedEdgeColor()\0setSelectedFaceColor()\0"
    "setVertexIDBgColor()\0setFaceIDBgColor()\0"
    "setEdgeIDBgColor()\0setNormalColor()\0"
    "setFaceCentroidColor()\0loadDefaults()\0"
};

void TopModPreferences::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TopModPreferences *_t = static_cast<TopModPreferences *>(_o);
        switch (_id) {
        case 0: _t->saveSettings(); break;
        case 1: _t->discardSettings(); break;
        case 2: _t->setViewportColor(); break;
        case 3: _t->setRenderColor(); break;
        case 4: _t->setCoolLightColor(); break;
        case 5: _t->setWarmLightColor(); break;
        case 6: _t->setWireframeColor(); break;
        case 7: _t->setSilhouetteColor(); break;
        case 8: _t->setPatchBoundaryColor(); break;
        case 9: _t->setSelectedVertexColor(); break;
        case 10: _t->setSelectedEdgeColor(); break;
        case 11: _t->setSelectedFaceColor(); break;
        case 12: _t->setVertexIDBgColor(); break;
        case 13: _t->setFaceIDBgColor(); break;
        case 14: _t->setEdgeIDBgColor(); break;
        case 15: _t->setNormalColor(); break;
        case 16: _t->setFaceCentroidColor(); break;
        case 17: _t->loadDefaults(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData TopModPreferences::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TopModPreferences::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_TopModPreferences,
      qt_meta_data_TopModPreferences, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TopModPreferences::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TopModPreferences::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TopModPreferences::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TopModPreferences))
        return static_cast<void*>(const_cast< TopModPreferences*>(this));
    return QDialog::qt_metacast(_clname);
}

int TopModPreferences::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

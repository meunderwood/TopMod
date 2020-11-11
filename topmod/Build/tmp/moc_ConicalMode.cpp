/****************************************************************************
** Meta object code from reading C++ file 'ConicalMode.hh'
**
** Created: Wed Jul 4 16:00:49 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ConicalMode.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ConicalMode.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ConicalMode[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   13,   12,   12, 0x0a,
      44,   13,   12,   12, 0x0a,
      75,   69,   12,   12, 0x0a,
      96,   69,   12,   12, 0x0a,
     119,   13,   12,   12, 0x0a,
     144,   13,   12,   12, 0x0a,
     169,   12,   12,   12, 0x0a,
     188,   12,   12,   12, 0x0a,
     209,   12,   12,   12, 0x0a,
     234,   12,   12,   12, 0x0a,
     253,   12,   12,   12, 0x0a,
     275,   12,   12,   12, 0x0a,
     299,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ConicalMode[] = {
    "ConicalMode\0\0value\0changeCutOffsetE(double)\0"
    "changeCutOffsetV(double)\0state\0"
    "toggleGlobalCut(int)\0toggleSelectedCut(int)\0"
    "changeTiltPlane1(double)\0"
    "changeTiltPlane2(double)\0triggerCutbyEdge()\0"
    "triggerCutbyVertex()\0triggerCutbyEdgeVertex()\0"
    "triggerCutbyFace()\0triggerTruncateEdge()\0"
    "triggerTruncateVertex()\0triggerDualConvexHull()\0"
};

void ConicalMode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ConicalMode *_t = static_cast<ConicalMode *>(_o);
        switch (_id) {
        case 0: _t->changeCutOffsetE((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->changeCutOffsetV((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->toggleGlobalCut((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->toggleSelectedCut((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->changeTiltPlane1((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->changeTiltPlane2((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->triggerCutbyEdge(); break;
        case 7: _t->triggerCutbyVertex(); break;
        case 8: _t->triggerCutbyEdgeVertex(); break;
        case 9: _t->triggerCutbyFace(); break;
        case 10: _t->triggerTruncateEdge(); break;
        case 11: _t->triggerTruncateVertex(); break;
        case 12: _t->triggerDualConvexHull(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ConicalMode::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ConicalMode::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ConicalMode,
      qt_meta_data_ConicalMode, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ConicalMode::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ConicalMode::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ConicalMode::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ConicalMode))
        return static_cast<void*>(const_cast< ConicalMode*>(this));
    return QWidget::qt_metacast(_clname);
}

int ConicalMode::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

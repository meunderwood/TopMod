/****************************************************************************
** Meta object code from reading C++ file 'HighgenusMode.hh'
**
** Created: Wed Jul 4 16:00:53 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../HighgenusMode.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'HighgenusMode.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CreateTorusTool[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x0a,
      25,   16,   16,   16, 0x0a,
      36,   16,   16,   16, 0x0a,
      66,   16,   16,   16, 0x0a,
      91,   16,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CreateTorusTool[] = {
    "CreateTorusTool\0\0Apply()\0Activate()\0"
    "ToggleTriangulateNewFace(int)\0"
    "ToggleScherkCollins(int)\0"
    "ChangeSizeCrossSection(double)\0"
};

void CreateTorusTool::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CreateTorusTool *_t = static_cast<CreateTorusTool *>(_o);
        switch (_id) {
        case 0: _t->Apply(); break;
        case 1: _t->Activate(); break;
        case 2: _t->ToggleTriangulateNewFace((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->ToggleScherkCollins((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->ChangeSizeCrossSection((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CreateTorusTool::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CreateTorusTool::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CreateTorusTool,
      qt_meta_data_CreateTorusTool, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CreateTorusTool::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CreateTorusTool::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CreateTorusTool::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CreateTorusTool))
        return static_cast<void*>(const_cast< CreateTorusTool*>(this));
    return QWidget::qt_metacast(_clname);
}

int CreateTorusTool::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
static const uint qt_meta_data_HighgenusMode[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      32,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   15,   14,   14, 0x0a,
      60,   54,   14,   14, 0x0a,
      95,   92,   14,   14, 0x0a,
     132,  126,   14,   14, 0x0a,
     175,  126,   14,   14, 0x0a,
     207,  126,   14,   14, 0x0a,
     233,  126,   14,   14, 0x0a,
     260,  126,   14,   14, 0x0a,
     285,  126,   14,   14, 0x0a,
     313,   54,   14,   14, 0x0a,
     352,   14,   14,   14, 0x0a,
     375,   14,   14,   14, 0x0a,
     400,   14,   14,   14, 0x0a,
     421,   14,   14,   14, 0x0a,
     450,   14,   14,   14, 0x0a,
     481,   14,   14,   14, 0x0a,
     508,   14,   14,   14, 0x0a,
     536,   14,   14,   14, 0x0a,
     560,   14,   14,   14, 0x0a,
     580,   14,   14,   14, 0x0a,
     605,   14,   14,   14, 0x0a,
     627,   54,   14,   14, 0x0a,
     657,   54,   14,   14, 0x0a,
     693,   54,   14,   14, 0x0a,
     728,   54,   14,   14, 0x0a,
     761,   54,   14,   14, 0x0a,
     800,   54,   14,   14, 0x0a,
     838,   54,   14,   14, 0x0a,
     881,   54,   14,   14, 0x0a,
     921,   54,   14,   14, 0x0a,
     957,   54,   14,   14, 0x0a,
     994,   54,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_HighgenusMode[] = {
    "HighgenusMode\0\0factor\0"
    "changeNormalTwistingFactor(int)\0value\0"
    "numSegmentsValueChanged(double)\0on\0"
    "changeMultiFaceAlgorithm(bool)\0state\0"
    "toggleMultiFaceHandleUseMaxOffsetFlag(int)\0"
    "toggleSymmetricWeightsFlag(int)\0"
    "toggleWireframeSplit(int)\0"
    "toggleTriangulateFace(int)\0"
    "toggleScherkCollins(int)\0"
    "toggleCrustCleanupFlag(int)\0"
    "numSegmentsConnectValueChanged(double)\0"
    "triggerAddHoleHandle()\0triggerAddHoleHandleCV()\0"
    "triggerAddHandleSI()\0triggerRindModelingScaling()\0"
    "triggerRindModelingThickness()\0"
    "triggerWireframeModeling()\0"
    "triggerWireframeModeling2()\0"
    "triggerColumnModeling()\0triggerSierpinsky()\0"
    "triggerMultiFaceHandle()\0triggerMengerSponge()\0"
    "changeHoleHandlePinch(double)\0"
    "changeHoleHandlePinchCenter(double)\0"
    "changeHoleHandlePinchWidth(double)\0"
    "ChangeScherkCollinsPinch(double)\0"
    "ChangeScherkCollinsPinchCenter(double)\0"
    "ChangeScherkCollinsPinchWidth(double)\0"
    "ChangeScherkCollinsHoleNumSegments(double)\0"
    "ChangeScherkCollinsHoleInitSkip(double)\0"
    "ChangeScherkCollinsHoleSkip(double)\0"
    "ChangeScherkCollinsHoleTwist(double)\0"
    "ChangeScherkCollinsHoleSegSkip(double)\0"
};

void HighgenusMode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        HighgenusMode *_t = static_cast<HighgenusMode *>(_o);
        switch (_id) {
        case 0: _t->changeNormalTwistingFactor((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->numSegmentsValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->changeMultiFaceAlgorithm((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->toggleMultiFaceHandleUseMaxOffsetFlag((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->toggleSymmetricWeightsFlag((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->toggleWireframeSplit((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->toggleTriangulateFace((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->toggleScherkCollins((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->toggleCrustCleanupFlag((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->numSegmentsConnectValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->triggerAddHoleHandle(); break;
        case 11: _t->triggerAddHoleHandleCV(); break;
        case 12: _t->triggerAddHandleSI(); break;
        case 13: _t->triggerRindModelingScaling(); break;
        case 14: _t->triggerRindModelingThickness(); break;
        case 15: _t->triggerWireframeModeling(); break;
        case 16: _t->triggerWireframeModeling2(); break;
        case 17: _t->triggerColumnModeling(); break;
        case 18: _t->triggerSierpinsky(); break;
        case 19: _t->triggerMultiFaceHandle(); break;
        case 20: _t->triggerMengerSponge(); break;
        case 21: _t->changeHoleHandlePinch((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 22: _t->changeHoleHandlePinchCenter((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 23: _t->changeHoleHandlePinchWidth((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 24: _t->ChangeScherkCollinsPinch((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 25: _t->ChangeScherkCollinsPinchCenter((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 26: _t->ChangeScherkCollinsPinchWidth((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 27: _t->ChangeScherkCollinsHoleNumSegments((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 28: _t->ChangeScherkCollinsHoleInitSkip((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 29: _t->ChangeScherkCollinsHoleSkip((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 30: _t->ChangeScherkCollinsHoleTwist((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 31: _t->ChangeScherkCollinsHoleSegSkip((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData HighgenusMode::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject HighgenusMode::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_HighgenusMode,
      qt_meta_data_HighgenusMode, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &HighgenusMode::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *HighgenusMode::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *HighgenusMode::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HighgenusMode))
        return static_cast<void*>(const_cast< HighgenusMode*>(this));
    return QWidget::qt_metacast(_clname);
}

int HighgenusMode::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 32)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 32;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

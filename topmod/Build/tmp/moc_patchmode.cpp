/****************************************************************************
** Meta object code from reading C++ file 'patchmode.hh'
**
** Created: Wed Jul 4 16:01:07 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../patchmode.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'patchmode.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PatchMode[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,
      31,   10,   10,   10, 0x05,
      50,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      83,   77,   10,   10, 0x08,
     117,   77,   10,   10, 0x08,
     152,   77,   10,   10, 0x08,
     188,   77,   10,   10, 0x08,
     232,   77,   10,   10, 0x08,
     264,   77,   10,   10, 0x08,
     313,   77,   10,   10, 0x08,
     345,   77,   10,   10, 0x08,
     369,   77,   10,   10, 0x08,
     400,   10,   10,   10, 0x08,
     418,   77,   10,   10, 0x08,
     441,   77,   10,   10, 0x08,
     464,   10,   10,   10, 0x08,
     481,   10,   10,   10, 0x08,
     504,   10,   10,   10, 0x08,
     523,   10,   10,   10, 0x08,
     543,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PatchMode[] = {
    "PatchMode\0\0ParametersUpdated()\0"
    "ConvertToTopMode()\0PatchRenderUpdateRequest()\0"
    "value\0showPatchControlMeshChanged(bool)\0"
    "renderPatchBoundariesChanged(bool)\0"
    "renderDooSabinPolygonsChanged(bool)\0"
    "renderModifiedDooSabinPolygonsChanged(bool)\0"
    "regularizePolygonsChanged(bool)\0"
    "polygonRegularizationIterationSliderChanged(int)\0"
    "patchNestingMethodChanged(bool)\0"
    "subDivisionChanged(int)\0"
    "patchNestingFactorChanged(int)\0"
    "resetParameters()\0scaleValueChanged(int)\0"
    "angleValueChanged(int)\0allOptSelected()\0"
    "alternateOptSelected()\0edgesOptSelected()\0"
    "vertexOptSelected()\0convertTriggered()\0"
};

void PatchMode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PatchMode *_t = static_cast<PatchMode *>(_o);
        switch (_id) {
        case 0: _t->ParametersUpdated(); break;
        case 1: _t->ConvertToTopMode(); break;
        case 2: _t->PatchRenderUpdateRequest(); break;
        case 3: _t->showPatchControlMeshChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->renderPatchBoundariesChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->renderDooSabinPolygonsChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->renderModifiedDooSabinPolygonsChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->regularizePolygonsChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->polygonRegularizationIterationSliderChanged((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 9: _t->patchNestingMethodChanged((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 10: _t->subDivisionChanged((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 11: _t->patchNestingFactorChanged((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 12: _t->resetParameters(); break;
        case 13: _t->scaleValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->angleValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->allOptSelected(); break;
        case 16: _t->alternateOptSelected(); break;
        case 17: _t->edgesOptSelected(); break;
        case 18: _t->vertexOptSelected(); break;
        case 19: _t->convertTriggered(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PatchMode::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PatchMode::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PatchMode,
      qt_meta_data_PatchMode, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PatchMode::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PatchMode::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PatchMode::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PatchMode))
        return static_cast<void*>(const_cast< PatchMode*>(this));
    return QWidget::qt_metacast(_clname);
}

int PatchMode::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void PatchMode::ParametersUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void PatchMode::ConvertToTopMode()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void PatchMode::PatchRenderUpdateRequest()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE

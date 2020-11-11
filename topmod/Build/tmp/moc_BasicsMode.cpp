/****************************************************************************
** Meta object code from reading C++ file 'BasicsMode.hh'
**
** Created: Wed Jul 4 16:00:36 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../BasicsMode.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BasicsMode.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GeometricTool[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x0a,
      32,   14,   14,   14, 0x0a,
      40,   14,   14,   14, 0x0a,
      48,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GeometricTool[] = {
    "GeometricTool\0\0DoAction(double)\0Apply()\0"
    "Reset()\0Activate()\0"
};

void GeometricTool::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GeometricTool *_t = static_cast<GeometricTool *>(_o);
        switch (_id) {
        case 0: _t->DoAction((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->Apply(); break;
        case 2: _t->Reset(); break;
        case 3: _t->Activate(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData GeometricTool::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GeometricTool::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GeometricTool,
      qt_meta_data_GeometricTool, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GeometricTool::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GeometricTool::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GeometricTool::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GeometricTool))
        return static_cast<void*>(const_cast< GeometricTool*>(this));
    return QWidget::qt_metacast(_clname);
}

int GeometricTool::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
static const uint qt_meta_data_BasicsMode[] = {

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
      12,   11,   11,   11, 0x0a,
      32,   11,   11,   11, 0x0a,
      52,   11,   11,   11, 0x0a,
      74,   11,   11,   11, 0x0a,
      97,   11,   11,   11, 0x0a,
     119,   11,   11,   11, 0x0a,
     142,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_BasicsMode[] = {
    "BasicsMode\0\0triggerInsertEdge()\0"
    "triggerDeleteEdge()\0triggerCollapseEdge()\0"
    "triggerSubdivideEdge()\0triggerConnectEdges()\0"
    "triggerSpliceCorners()\0triggerSelectionOptions()\0"
};

void BasicsMode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BasicsMode *_t = static_cast<BasicsMode *>(_o);
        switch (_id) {
        case 0: _t->triggerInsertEdge(); break;
        case 1: _t->triggerDeleteEdge(); break;
        case 2: _t->triggerCollapseEdge(); break;
        case 3: _t->triggerSubdivideEdge(); break;
        case 4: _t->triggerConnectEdges(); break;
        case 5: _t->triggerSpliceCorners(); break;
        case 6: _t->triggerSelectionOptions(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData BasicsMode::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BasicsMode::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BasicsMode,
      qt_meta_data_BasicsMode, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BasicsMode::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BasicsMode::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BasicsMode::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BasicsMode))
        return static_cast<void*>(const_cast< BasicsMode*>(this));
    return QWidget::qt_metacast(_clname);
}

int BasicsMode::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

/****************************************************************************
** Meta object code from reading C++ file 'BranchCovering_CornerCutting_Widget.hh'
**
** Created: Wed Jul 4 16:01:10 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../BranchCovering_CornerCutting_Widget.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BranchCovering_CornerCutting_Widget.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BranchCovering_CornerCutting_Widget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      61,   37,   36,   36, 0x05,

 // slots: signature, parameters, type, tag, flags
     145,  139,   36,   36, 0x08,
     174,  139,   36,   36, 0x08,
     202,  139,   36,   36, 0x08,
     227,  139,   36,   36, 0x08,
     255,  139,   36,   36, 0x08,
     295,   36,   36,   36, 0x08,
     316,   36,   36,   36, 0x08,
     338,   36,   36,   36, 0x08,
     357,   36,   36,   36, 0x08,
     374,   36,   36,   36, 0x08,
     393,   36,   36,   36, 0x08,
     409,   36,   36,   36, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_BranchCovering_CornerCutting_Widget[] = {
    "BranchCovering_CornerCutting_Widget\0"
    "\0mapping_guid,parameters\0"
    "Apply(std::vector<HALF_EDGE_MAPPING>,BranchCovering_CornerCutting_Para"
    "meters)\0"
    "value\0update_shrinking_factor(int)\0"
    "update_rotation_factor(int)\0"
    "update_thickness(double)\0"
    "update_panel_offset(double)\0"
    "update_panel_alternation_offset(double)\0"
    "add_forward_symbol()\0add_backward_symbol()\0"
    "add_cross_symbol()\0move_up_symbol()\0"
    "move_down_symbol()\0remove_symbol()\0"
    "apply()\0"
};

void BranchCovering_CornerCutting_Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BranchCovering_CornerCutting_Widget *_t = static_cast<BranchCovering_CornerCutting_Widget *>(_o);
        switch (_id) {
        case 0: _t->Apply((*reinterpret_cast< const std::vector<HALF_EDGE_MAPPING>(*)>(_a[1])),(*reinterpret_cast< const BranchCovering_CornerCutting_Parameters(*)>(_a[2]))); break;
        case 1: _t->update_shrinking_factor((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 2: _t->update_rotation_factor((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 3: _t->update_thickness((*reinterpret_cast< const double(*)>(_a[1]))); break;
        case 4: _t->update_panel_offset((*reinterpret_cast< const double(*)>(_a[1]))); break;
        case 5: _t->update_panel_alternation_offset((*reinterpret_cast< const double(*)>(_a[1]))); break;
        case 6: _t->add_forward_symbol(); break;
        case 7: _t->add_backward_symbol(); break;
        case 8: _t->add_cross_symbol(); break;
        case 9: _t->move_up_symbol(); break;
        case 10: _t->move_down_symbol(); break;
        case 11: _t->remove_symbol(); break;
        case 12: _t->apply(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData BranchCovering_CornerCutting_Widget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BranchCovering_CornerCutting_Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BranchCovering_CornerCutting_Widget,
      qt_meta_data_BranchCovering_CornerCutting_Widget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BranchCovering_CornerCutting_Widget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BranchCovering_CornerCutting_Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BranchCovering_CornerCutting_Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BranchCovering_CornerCutting_Widget))
        return static_cast<void*>(const_cast< BranchCovering_CornerCutting_Widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int BranchCovering_CornerCutting_Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void BranchCovering_CornerCutting_Widget::Apply(const std::vector<HALF_EDGE_MAPPING> & _t1, const BranchCovering_CornerCutting_Parameters & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

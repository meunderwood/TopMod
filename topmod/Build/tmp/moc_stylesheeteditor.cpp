/****************************************************************************
** Meta object code from reading C++ file 'stylesheeteditor.hh'
**
** Created: Wed Jul 4 16:01:05 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../stylesheeteditor.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stylesheeteditor.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_StyleSheetEditor[] = {

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
      28,   18,   17,   17, 0x08,
      76,   61,   17,   17, 0x08,
     114,   17,   17,   17, 0x08,
     145,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_StyleSheetEditor[] = {
    "StyleSheetEditor\0\0styleName\0"
    "on_styleCombo_activated(QString)\0"
    "styleSheetName\0on_styleSheetCombo_activated(QString)\0"
    "on_styleTextEdit_textChanged()\0"
    "on_applyButton_clicked()\0"
};

void StyleSheetEditor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        StyleSheetEditor *_t = static_cast<StyleSheetEditor *>(_o);
        switch (_id) {
        case 0: _t->on_styleCombo_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_styleSheetCombo_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_styleTextEdit_textChanged(); break;
        case 3: _t->on_applyButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData StyleSheetEditor::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject StyleSheetEditor::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_StyleSheetEditor,
      qt_meta_data_StyleSheetEditor, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &StyleSheetEditor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *StyleSheetEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *StyleSheetEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_StyleSheetEditor))
        return static_cast<void*>(const_cast< StyleSheetEditor*>(this));
    return QWidget::qt_metacast(_clname);
}

int StyleSheetEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE

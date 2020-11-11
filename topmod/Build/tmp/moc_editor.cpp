/****************************************************************************
** Meta object code from reading C++ file 'editor.hh'
**
** Created: Wed Jul 4 16:00:32 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../editor.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editor.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Editor[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      33,   28,    7,    7, 0x0a,
      56,    7,    7,    7, 0x0a,
      71,    7,    7,    7, 0x0a,
      93,   89,    7,    7, 0x0a,
     115,    7,    7,    7, 0x09,
     135,    7,    7,    7, 0x09,
     162,  157,    7,    7, 0x09,
     184,    7,    7,    7, 0x09,
     198,    7,    7,    7, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_Editor[] = {
    "Editor\0\0ctrlReturnPressed()\0text\0"
    "appendHistory(QString)\0clearHistory()\0"
    "moveCursorToEnd()\0txt\0setPlainText(QString)\0"
    "checkAutoComplete()\0triggerAutoComplete()\0"
    "item\0autoComplete(QString)\0historyBack()\0"
    "historyForward()\0"
};

void Editor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Editor *_t = static_cast<Editor *>(_o);
        switch (_id) {
        case 0: _t->ctrlReturnPressed(); break;
        case 1: _t->appendHistory((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->clearHistory(); break;
        case 3: _t->moveCursorToEnd(); break;
        case 4: _t->setPlainText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->checkAutoComplete(); break;
        case 6: _t->triggerAutoComplete(); break;
        case 7: _t->autoComplete((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->historyBack(); break;
        case 9: _t->historyForward(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Editor::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Editor::staticMetaObject = {
    { &QTextEdit::staticMetaObject, qt_meta_stringdata_Editor,
      qt_meta_data_Editor, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Editor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Editor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Editor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Editor))
        return static_cast<void*>(const_cast< Editor*>(this));
    return QTextEdit::qt_metacast(_clname);
}

int Editor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Editor::ctrlReturnPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
static const uint qt_meta_data_EditorCompletion[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   18,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      51,   17,   17,   17, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_EditorCompletion[] = {
    "EditorCompletion\0\0item\0"
    "selectedCompletion(QString)\0"
    "moveCompletionPopup()\0"
};

void EditorCompletion::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        EditorCompletion *_t = static_cast<EditorCompletion *>(_o);
        switch (_id) {
        case 0: _t->selectedCompletion((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->moveCompletionPopup(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData EditorCompletion::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject EditorCompletion::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_EditorCompletion,
      qt_meta_data_EditorCompletion, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EditorCompletion::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EditorCompletion::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EditorCompletion::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EditorCompletion))
        return static_cast<void*>(const_cast< EditorCompletion*>(this));
    return QObject::qt_metacast(_clname);
}

int EditorCompletion::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void EditorCompletion::selectedCompletion(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

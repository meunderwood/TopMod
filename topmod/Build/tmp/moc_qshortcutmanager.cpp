/****************************************************************************
** Meta object code from reading C++ file 'qshortcutmanager.hh'
**
** Created: Wed Jul 4 16:00:31 2018
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qshortcutmanager.hh"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qshortcutmanager.hh' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QShortcutManager[] = {

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
      18,   17,   17,   17, 0x0a,
      28,   17,   17,   17, 0x0a,
      39,   17,   17,   17, 0x0a,
      56,   51,   17,   17, 0x0a,
      83,   81,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QShortcutManager[] = {
    "QShortcutManager\0\0readXml()\0writeXml()\0"
    "configure()\0lang\0languageChanged(QString)\0"
    "o\0destroyed(QObject*)\0"
};

void QShortcutManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QShortcutManager *_t = static_cast<QShortcutManager *>(_o);
        switch (_id) {
        case 0: _t->readXml(); break;
        case 1: _t->writeXml(); break;
        case 2: _t->configure(); break;
        case 3: _t->languageChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->destroyed((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QShortcutManager::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QShortcutManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QShortcutManager,
      qt_meta_data_QShortcutManager, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QShortcutManager::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QShortcutManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QShortcutManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QShortcutManager))
        return static_cast<void*>(const_cast< QShortcutManager*>(this));
    return QObject::qt_metacast(_clname);
}

int QShortcutManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

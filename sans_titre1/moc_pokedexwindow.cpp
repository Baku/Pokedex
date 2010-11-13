/****************************************************************************
** Meta object code from reading C++ file 'pokedexwindow.h'
**
** Created: Sat Nov 13 21:59:02 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "pokedexwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pokedexwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_pokedexWindow[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x0a,
      29,   14,   14,   14, 0x0a,
      51,   14,   14,   14, 0x0a,
      61,   14,   14,   14, 0x0a,
      72,   14,   14,   14, 0x0a,
      93,   14,   14,   14, 0x0a,
     111,   14,   14,   14, 0x0a,
     127,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_pokedexWindow[] = {
    "pokedexWindow\0\0changeImage()\0"
    "changeImageFromTeam()\0addTeam()\0"
    "saveTeam()\0loadPokemonTrainer()\0"
    "loadPokemonTeam()\0deletePokemon()\0"
    "deleteAllPokemon()\0"
};

const QMetaObject pokedexWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_pokedexWindow,
      qt_meta_data_pokedexWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &pokedexWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *pokedexWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *pokedexWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_pokedexWindow))
        return static_cast<void*>(const_cast< pokedexWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int pokedexWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: changeImage(); break;
        case 1: changeImageFromTeam(); break;
        case 2: addTeam(); break;
        case 3: saveTeam(); break;
        case 4: loadPokemonTrainer(); break;
        case 5: loadPokemonTeam(); break;
        case 6: deletePokemon(); break;
        case 7: deleteAllPokemon(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

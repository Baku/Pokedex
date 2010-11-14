#ifndef POKEDEXWINDOW_H
#define POKEDEXWINDOW_H

#include <QtGui>
#include <QWidget>
#include <QString>
#include <QListView>
#include <QDirModel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QStringListModel>
#include <string>
#include <mainwindow.h>
#include "pokedexParser.h"

class pokedexWindow : public QWidget
{
Q_OBJECT
public:
    void run();
    pokedexWindow();
    ~pokedexWindow();
public slots:
    void        changeImage();
    void        changeImageFromTeam();
    void        addTeam();
    void        saveTeam();
    void        loadPokemonTrainer();
    void        loadPokemonTeam();
    void        deletePokemon();
    void        deleteAllPokemon();
    void        createPokemonTrainer();
private:
    MainWindow       *w;
    QStringListModel *allModele;
    QStringListModel *teamModele;
    QStringListModel *currentPokemonModele;
    QStringList      listePokemon;
    QStringList      teamPokemon;
    QStringList      currentPokemonList;
    QPushButton      *bouton;
    QPushButton      *loadTrainer;
    QPushButton      *createTrainer;
    QPushButton      *loadTeam;
    QPushButton      *quitButton;
    QPushButton      *saveButton;
    QPushButton      *deleteButton;
    QPushButton      *deleteAllButton;
    QListView        *allView;
    QListView        *teamView;
    QListView        *currentPokemonView;
    QLabel           *label_img;
    QLabel           *pokeImage;
    QPixmap          *pixmap_img;
    QPixmap          *pokePix;
    QList<Pokemon>   pokeList;
};

#endif // POKEDEXWINDOW_H

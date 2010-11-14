#include "pokedexwindow.h"

pokedexWindow::pokedexWindow()
{
    this->w = new MainWindow;
    this->w->setMinimumSize(710, 484);
    this->w->setMaximumSize(710, 484);

    parser = new PokedexParser("pokedata.xml");

    parser->parse();

    QList<Pokemon> pokeList = parser->pokedex_;
    for (QList<Pokemon>::iterator it = pokeList.begin();
        it < pokeList.end();
        it++)
        this->listePokemon << (*it).getName();

    // this->currentPokemonList << "ATK = 42" << "DEF = 87" << "TYPE = EAU" << "DESCRIPTION = zeefuzenfozenfiozenfozenfiozenfozenfozenfnzeoifnzeoinfozeinfozeinfiozenfoizenfiozenfiozenfoizenfiozenfiozenfozenfiozenfiozneiofnzeiofnzeionfzeionfiozenfiozenfzioenfzioenfionzeifnzeionfzeoinfzoifniozefnzioenfzioenfzioenfzoeifnzioenfzeoinfzeoin";

    this->allModele = new QStringListModel(listePokemon);
    this->teamModele = new QStringListModel();
    this->currentPokemonModele = new QStringListModel(this->currentPokemonList);

    this->currentPokemonView = new QListView(this->w);
    currentPokemonView->setModel(this->currentPokemonModele);
    currentPokemonView->setGeometry(10, 220, 370, 260);
    currentPokemonView->setStyleSheet("background-color: grey;");

    this->teamView = new QListView(this->w);
    teamView->setModel(this->teamModele);
    teamView->setGeometry(400, 220, 150, 100);
    teamView->setStyleSheet("background-color: orange;");

    this->allView = new QListView(this->w);
    allView->setModel(allModele);
    allView->setGeometry(10,10,200,200);
    allView->setStyleSheet("background-color: white;");

    this->label_img  = new QLabel(this->w);
    pixmap_img = new QPixmap(QDir::currentPath() + "/Pokemon/chen.png");
    label_img->setPixmap(*pixmap_img);
    label_img->setGeometry(450, 10, 200, 200);

    this->pokeImage  = new QLabel("poke", this->w);
    pokePix = new QPixmap(QDir::currentPath() + "/Pokemon/logo.png");
    pokeImage->setPixmap(*pokePix);
    pokeImage->setGeometry(400, 330, 300, 150);

    this->bouton = new QPushButton("Add", this->w);
    bouton->setGeometry(250, 40, 150, 50);
    bouton->setToolTip("Add the selected pokemon on the current team.");
    bouton->setStyleSheet("background-color: green;");

    this->createTrainer = new QPushButton("Create Trainer", this->w);
    createTrainer->setGeometry(250, 90, 150, 50);
    createTrainer->setToolTip("Create a trainer.");
    createTrainer->setStyleSheet("background-color: brown;");

    this->loadTrainer = new QPushButton("Load Trainer", this->w);
    loadTrainer->setGeometry(250, 140, 150, 50);
    loadTrainer->setToolTip("Load a trainer.");
    loadTrainer->setStyleSheet("background-color: cyan;");

    this->loadTeam = new QPushButton("Load Team", this->w);
    loadTeam->setGeometry(560, 280, 150, 20);
    loadTeam->setToolTip("Load a team.");
    loadTeam->setStyleSheet("background-color: blue;");

    this->saveButton = new QPushButton("Save", this->w);
    saveButton->setGeometry(560, 260, 150, 20);
    saveButton->setToolTip("Save the current team.");
    saveButton->setStyleSheet("background-color: violet;");

    this->deleteButton = new QPushButton("Delete", this->w);
    deleteButton->setGeometry(560, 220, 150, 20);
    deleteButton->setToolTip("Delete the selected pokemon from the team.");
    deleteButton->setStyleSheet("background-color: white;");

    this->deleteAllButton = new QPushButton("Delete All", this->w);
    deleteAllButton->setGeometry(560, 240, 150, 20);
    deleteAllButton->setToolTip("Delete all the pokemon from the team.");
    deleteAllButton->setStyleSheet("background-color: purple;");

    this->quitButton = new QPushButton("Quit", this->w);
    quitButton->setGeometry(560, 300, 150, 20);
    quitButton->setToolTip("Quit the Pokedex program.");
    quitButton->setStyleSheet("background-color: yellow;");

    this->connect(allView, SIGNAL(clicked(QModelIndex)), SLOT(changeImage()));
    this->connect(teamView, SIGNAL(clicked(QModelIndex)), SLOT(changeImageFromTeam()));
    this->connect(bouton, SIGNAL(clicked()), SLOT(addTeam()));
    this->connect(saveButton, SIGNAL(clicked()), SLOT(saveTeam()));
    this->connect(loadTeam, SIGNAL(clicked()), SLOT(loadPokemonTeam()));
    this->connect(createTrainer, SIGNAL(clicked()), SLOT(createPokemonTrainer()));
    this->connect(loadTrainer, SIGNAL(clicked()), SLOT(loadPokemonTrainer()));
    this->connect(quitButton, SIGNAL(clicked()), this->w, SLOT(close()));
    this->connect(deleteButton, SIGNAL(clicked()), SLOT(deletePokemon()));
    this->connect(deleteAllButton, SIGNAL(clicked()), SLOT(deleteAllPokemon()));
}

pokedexWindow::~pokedexWindow()
{
    delete       w;
    delete allModele;
    delete teamModele;
    delete currentPokemonModele;
    delete  bouton;
    delete loadTrainer;
    delete createTrainer;
    delete loadTeam;
    delete quitButton;
    delete saveButton;
    delete deleteButton;
    delete deleteAllButton;
    delete allView;
    delete teamView;
    delete currentPokemonView;
    delete label_img;
    delete pixmap_img;
}

void    pokedexWindow::changeImage()
{
    QItemSelectionModel *selection = this->allView->selectionModel();
    QModelIndex indexElementSelectionne = selection->currentIndex();
    QVariant elementSelectionne = allModele->data(indexElementSelectionne, Qt::DisplayRole);
    delete this->pixmap_img;
    //pixmap_img = new QPixmap("C:\\Pokemon/" + elementSelectionne.toString() + ".png");
    Pokemon *p = parser->getPokemon(elementSelectionne.toString());
    
    QList<QString> list = p->getAttributes();

    //this->currentPokemon << elementSelectionne.toString();
    this->currentPokemonModele->setStringList(list);
    this->currentPokemonView->setModel(this->currentPokemonModele);
    pixmap_img = new QPixmap(QDir::currentPath() + "/Pokemon/" + elementSelectionne.toString() + ".png");
    label_img->setPixmap(*pixmap_img);
}

void    pokedexWindow::saveTeam()
{
    QString fichier = QFileDialog::getSaveFileName(this, "Save Team", QString(), "Equipes (*.xml)");
}

void    pokedexWindow::loadPokemonTrainer()
{
    QString fichier = QFileDialog::getOpenFileName(this, "Load Trainer", QString(), "Equipes (*.xml)");
}

void    pokedexWindow::createPokemonTrainer()
{
    bool ok = false;
    QString pseudo = QInputDialog::getText(this, "Pseudo", "What is your pseudo ?", QLineEdit::Normal, QString(), &ok);
    if (!ok && pseudo.isEmpty())
      QMessageBox::critical(this, "Pseudo", "Sorry but we need a pseudo.");
    else
    {
        QStringList avatar;
        avatar << "Scout" << "Ninja" << "Karateka" << "Young Girl" << "Young Boy" << "Blue";
        QInputDialog::getItem(this, "Votre avatar", "Which avatar do you want?", avatar);
    }
}

void    pokedexWindow::loadPokemonTeam()
{
    QString fichier = QFileDialog::getOpenFileName(this, "Load team", QString(), "Equipes (*.xml)");
}

void    pokedexWindow::changeImageFromTeam()
{
    QItemSelectionModel *selection = this->teamView->selectionModel();
    QModelIndex indexElementSelectionne = selection->currentIndex();
    QVariant elementSelectionne = teamModele->data(indexElementSelectionne, Qt::DisplayRole);
    delete this->pixmap_img;
    pixmap_img = new QPixmap(QDir::currentPath() + "/Pokemon/" + elementSelectionne.toString() + ".png");
    label_img->setPixmap(*pixmap_img);
}

void    pokedexWindow::deletePokemon()
{
    QItemSelectionModel *selection = this->teamView->selectionModel();
    QModelIndex indexElementSelectionne = selection->currentIndex();
    QVariant elementSelectionne = teamModele->data(indexElementSelectionne, Qt::DisplayRole);
    if (elementSelectionne.toString().size() > 0)
    {
        int result = QMessageBox::question(this, "Delete Pokemon", "Etes-vous sur de vouloir eliminer " + elementSelectionne.toString() + " de l'équipe?", QMessageBox::Yes | QMessageBox::No);
        if (result == QMessageBox::Yes)
            {
                this->teamPokemon.removeOne(elementSelectionne.toString());
                this->teamModele->setStringList(this->teamPokemon);
                this->teamView->setModel(this->teamModele);
            }
    }
}

void    pokedexWindow::deleteAllPokemon()
{
    QItemSelectionModel *selection = this->teamView->selectionModel();
    QModelIndex indexElementSelectionne = selection->currentIndex();
    QVariant elementSelectionne = teamModele->data(indexElementSelectionne, Qt::DisplayRole);
    if (teamPokemon.size() > 0)
    {
        int result = QMessageBox::question(this, "Delete Pokemon", "Etes-vous sur de vouloir eliminer tout les pokemons de l'équipe?", QMessageBox::Yes | QMessageBox::No);
        if (result == QMessageBox::Yes)
            {
                this->teamPokemon.clear();
                this->teamModele->setStringList(this->teamPokemon);
                this->teamView->setModel(this->teamModele);
            }
    }
}

void    pokedexWindow::addTeam()
{
    QItemSelectionModel *selection = this->allView->selectionModel();
    QModelIndex indexElementSelectionne = selection->currentIndex();
    QVariant elementSelectionne = allModele->data(indexElementSelectionne, Qt::DisplayRole);
    if (this->teamPokemon.size() < 6 && elementSelectionne.toString().size() > 0)
    {
        this->teamPokemon << elementSelectionne.toString();
        this->teamModele->setStringList(this->teamPokemon);
        this->teamView->setModel(this->teamModele);
    }
    else if (this->teamPokemon.size() >= 6)
        QMessageBox::warning(this, "Trop de Pokemons", "Une équipe comporte au maximum 6 pokemons.");
}

void    pokedexWindow::run()
{
    this->w->show();
}

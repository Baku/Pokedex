//
// pokemon.cpp for pokedex in /home/pascua_n//pascua_n/pokedex
// 
// Made by nicolas pascual
// Login   <pascua_n@epitech.net>
// 
// Started on  Sun Nov 14 04:47:07 2010 nicolas pascual
// Last update Sun Nov 14 05:11:06 2010 nicolas pascual
//

#include "pokemon.h"
#include <iostream>

Pokemon::Pokemon(int id) : name_(""),
			   description_(""),
			   weight_(0.0),
			   height_(0.0),
			   max_xp_(0),
			   ratio_(0.0),
			   hp_(0),
			   atk_(0),
			   def_(0),
			   spd_(0),
			   sat_(0),
			   sde_(0)
{
  if (id > 0)
    id_ = id;
}

Pokemon::Pokemon(Pokemon *p)
{
  this->id_ = p->getId();
  this->types_ = p->getTypes();
  this->name_ = p->getName();
  this->description_ = p->getDescription(); 
  this->weight_ = p->getWeight();
  this->height_ = p->getHeight();
  this->max_xp_ = p->getMaxXp(); 
  this->evo_ = p->getEvolutions();
  this->ratio_ = p->getRatio(); 
  this->hp_ = p->getHp();
  this->atk_ = p->getAtk(); 
  this->def_ = p->getDef(); 
  this->spd_ = p->getSpd();
  this->sat_ = p->getSat(); 
  this->sde_ = p->getSde(); 
  this->tm_hm_ = p->getTmHms();
  this->level_ = p->getLevels();
}

Pokemon::~Pokemon()
{

}

void	Pokemon::setName(QString name)
{
  if (name != NULL)
    name_ = name;
}

void	Pokemon::addType(QString type)
{
  types_.push_back(type);
}

void	Pokemon::setDescription(QString desc)
{
  description_ = desc;
}

void	Pokemon::setWeight(float w)
{
  if (w > 0)
    weight_ = w;
}

void	Pokemon::setHeight(float h)
{
  if (h > 0)
    height_ = h;
}

void	Pokemon::setMaxXp(int m)
{
  if (m > 0)
    max_xp_ = m;
}

void	Pokemon::addEvolution(Evolution *evo)
{
  evo_.push_back(evo);
}

void	Pokemon::setRatio(float r)
{
  if (r > 0)
    ratio_ = r;
}

void	Pokemon::setHp(int hp)
{
  if (hp >= 0)
    hp_ = hp;
}

void	Pokemon::setAtk(int atk)
{
  if (atk >= 0)
    atk_ = atk;
}

void	Pokemon::setDef(int def)
{
  if (def >= 0)
    def_ = def;
}

void	Pokemon::setSpd(int spd)
{
  if (spd >= 0)
    spd_ = spd;
}

void	Pokemon::setSat(int sat)
{
  if (sat >= 0)
    sat_ = sat;
}

void	Pokemon::setSde(int sde)
{
  if (sde >= 0)
    sde_ = sde;
}

void	Pokemon::addTmHm(Tm_hm *t)
{
  tm_hm_.push_back(t);
}

void	Pokemon::addLevel(Level *l)
{
  level_.push_back(l);
}

void		Pokemon::setSpecies(QString sp)
{
  species_ = sp;
}

void		Pokemon::addEggGroup(QString eg)
{
  eggGroup_.push_back(eg);
}

// getters

int	Pokemon::getId() const
{
  return id_;
}

QString	Pokemon::getName() const
{
  return name_;
}

QString Pokemon::getDescription() const
{
  return description_;
}

QList<QString>	Pokemon::getTypes() const
{
  return types_;
}

float	Pokemon::getWeight() const
{
  return weight_;
}

float	Pokemon::getHeight() const
{
  return height_;
}

int	Pokemon::getMaxXp() const
{
  return max_xp_;
}

QList<Evolution*>	Pokemon::getEvolutions() const
{
  return (evo_);
}

float	Pokemon::getRatio() const
{
  return ratio_;
}

int	Pokemon::getHp() const
{
  return hp_;
}

int	Pokemon::getAtk() const
{
  return atk_;
}

int	Pokemon::getDef() const
{
  return def_;
}

int	Pokemon::getSpd() const
{
  return spd_;
}

int	Pokemon::getSat() const
{
  return sat_;
}

int	Pokemon::getSde() const
{
  return sde_;
}

QList<Tm_hm*>	Pokemon::getTmHms() const
{
  return tm_hm_;
}

QList<Level*>	Pokemon::getLevels() const
{
  return level_;
}

QString	Pokemon::getSpecies() const
{
  return species_;
}

QList<QString> Pokemon::getEggGroup() const
{
  return eggGroup_;
}

void	Pokemon::print()
{
  std::cout << "Pokemon #" << id_ << std::endl;
  std::cout << "-name:" << name_.toStdString() << std::endl;
  std::cout << "-description:" << std::endl;
  std::cout << description_.toStdString() << std::endl;
  std::cout << "-weight:" << weight_ << std::endl;
  std::cout << "-height:" << height_ << std::endl;
  std::cout << "-maxXp:" << max_xp_ << std::endl;
  std::cout << "evolutions:" << std::endl;
  for (QList<Evolution*>::iterator it = evo_.begin();
       it < evo_.end();
       it++)
    (*it)->print();
  std::cout << "tm_hms:" << std::endl;
  for (QList<Tm_hm*>::iterator it = tm_hm_.begin();
       it < tm_hm_.end();
       it++)
    (*it)->print();
  std::cout << "level-up:" << std::endl;
  for (QList<Level*>::iterator it = level_.begin();
       it < level_.end();
       it++)
    (*it)->print();
  for (QList<QString>::iterator it = eggGroup_.begin();
       it < eggGroup_.end();
       it++)
    std::cout << (*it).toStdString() << std::endl;
  std::cout << "-ratio:" << ratio_ << std::endl;
  std::cout << "-hp:" << hp_ << std::endl;
  std::cout << "-atk:" << atk_ << std::endl;
  std::cout << "-def:" << def_ << std::endl;
  std::cout << "-spd:" << spd_ << std::endl;
  std::cout << "-sat:" << sat_ << std::endl;
  std::cout << "-sde:" << sde_ << std::endl;
  std::cout << "-species:" << species_.toStdString() << std::endl;
  std::cout << std::endl;
}

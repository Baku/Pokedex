//
// evolution.cpp for pokedex in /home/pascua_n//pascua_n/pokedex
// 
// Made by nicolas pascual
// Login   <pascua_n@epitech.net>
// 
// Started on  Sun Nov 14 04:41:21 2010 nicolas pascual
// Last update Sun Nov 14 04:41:23 2010 nicolas pascual
//

#include "evolution.h"

Evolution::Evolution(int id) :name_(""),
			      level_(0)
{
  if (id > 0)
    id_ = id;
}

Evolution::~Evolution()
{

}

int Evolution::getId() const
{
  return id_;
}

QString Evolution::getName() const
{
  return name_;
}

int	Evolution::getlevel() const
{
  return level_;
}

void	Evolution::setName(QString name)
{
  name_ = name;
}

void	Evolution::setLevel(int lvl)
{
  level_ = lvl;
}

void	Evolution::print()
{
  std::cout << "id:" << id_ << std::endl;
  std::cout << "name:" << name_.toStdString() << std::endl;
  std::cout << "level:" << level_ << std::endl;
}

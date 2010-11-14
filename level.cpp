//
// level.cpp for pokedex in /home/pascua_n//pascua_n/pokedex
// 
// Made by nicolas pascual
// Login   <pascua_n@epitech.net>
// 
// Started on  Sun Nov 14 04:42:57 2010 nicolas pascual
// Last update Sun Nov 14 04:42:59 2010 nicolas pascual
//

#include "level.h"

Level::Level():name_(""),
	       level_(0)
{

}

Level::~Level()
{

}

void	Level::setName(QString name)
{
  name_ = name;
}

void	Level::setLevel(int lvl)
{
  level_ = lvl;
}

QString	Level::getName() const
{
  return name_;
}

int	Level::getLevel() const
{
  return level_;
}

void	Level::print() const
{
  std::cout << "name: " << name_.toStdString() << std::endl;
  std::cout << "level: " << level_ << std::endl;
}

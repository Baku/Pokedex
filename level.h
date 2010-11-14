/*
** level.h for pokedex in /home/pascua_n//pascua_n/pokedex
** 
** Made by nicolas pascual
** Login   <pascua_n@epitech.net>
** 
** Started on  Sun Nov 14 04:41:45 2010 nicolas pascual
** Last update Sun Nov 14 04:42:26 2010 nicolas pascual
*/

#ifndef __LEVEL_H_
#define __LEVEL_H_

#include <QString>
#include <iostream>

class Level
{
 private:
  QString	name_;
  int		level_;
 public:
  Level();
  ~Level();
  void		setName(QString);
  void		setLevel(int);
  QString	getName() const;
  int		getLevel() const;
  void		print() const;
};

#endif /* __LEVEL_H_ */

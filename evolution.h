/*
** evolution.h for  in /home/pascua_n//pascua_n/pokedex/sax
** 
** Made by nicolas pascual
** Login   <pascua_n@epitech.net>
** 
** Started on  Sun Nov 14 01:05:17 2010 nicolas pascual
** Last update Sun Nov 14 04:40:55 2010 nicolas pascual
*/

#ifndef __EVOLUTION_H_
#define __EVOLUTION_H_

#include <QString>
#include <iostream>

class Evolution
{
 public:
  Evolution(int);
  ~Evolution();

  int getId() const;
  QString getName() const;
  int	getlevel() const;

  void	setName(QString);
  void	setLevel(int);

  void	print();
 private:
  int	id_;
  QString	name_;
  int		level_;
};

#endif /* __EVOLUTION_H_ */

/*
** tm_hm.h for  in /home/pascua_n//pascua_n/pokedex/sax
** 
** Made by nicolas pascual
** Login   <pascua_n@epitech.net>
** 
** Started on  Sun Nov 14 01:09:51 2010 nicolas pascual
** Last update Sun Nov 14 08:54:31 2010 nicolas pascual
*/

#include <QString>
#include <iostream>

class Tm_hm
{
 public:
  Tm_hm();
  ~Tm_hm();

  void	setMachine(QString);
  void	setName(QString);
  void	setLevel(int);

  QString	getMachine() const;
  QString	getName() const;
  int	getLevel() const;

  void	print() const;
  QString	to_xml();


 private:
  QString	machine_;
  QString	name_;
  int		level_;
};

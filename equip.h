/*
** equip.h for pokedex in /home/pascua_n//pascua_n/pokedex
** 
** Made by nicolas pascual
** Login   <pascua_n@epitech.net>
** 
** Started on  Sun Nov 14 04:35:44 2010 nicolas pascual
** Last update Sun Nov 14 04:52:17 2010 nicolas pascual
*/

#ifndef		__EQUIP_H__
# define	__EQUIP_H__

#include <QString>

class	Equip
{
 public:
  Equip(int);
  Equip(int, QString);
  Equip(const Equip &);
  ~Equip();
  Equip	&operator=(const Equip &);

  void		setName(QString);

  QString	getName() const;
  int		getTamerId() const;
  int		getId() const;

 private:
  Equip();
  QString	name_;
  int		tamerId_;
  int		id_;
};

#endif		/* __EQUIP_H__ */

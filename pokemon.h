/*
** pokemon.h for  in /home/pfad_a//.ssh/Pokedex/Pokedex
** 
** Made by antoine pfad
** Login   <pfad_a@epitech.net>
** 
** Started on  Fri Nov 12 22:01:20 2010 antoine pfad
** Last update Fri Nov 12 23:58:13 2010 antoine pfad
*/

#ifndef _POKEMON_H_
# define _POKEMON_H_

#include <QString>

class Pokemon
{
 public:
  Pokemon(int);
  virtual ~Pokemon();

  void	setWeight(float);
  void	setMaxXp(int);
  void	setEvo(int, int)
  void	setRatio(float);
  void	setHp(int);
  void	setAtk(int);
  void	setDef(int);
  void	setSpd(int);
  void	setSat(int);
  void	setSde(int);

  int	getId() const;
  QString	getName() const;
  float	getWeight() const;
  int	getMaxXp() const;
  int	getEvo() const;
  float	getRatio() const;
  int	getHp() const;
  int	getAtk() const;
  int	getDef() const;
  int	getSpd() const;
  int	getSat() const;
  int	getSde() const;

 private:
  int		id_;
  QString	name_;
  float		weight_;
  int		max_xp_;
  float		act_exp;
  int		level;
  int		evo[3];
  float		ratio_;
  int		hp_;
  int		atk_;
  int		def_;
  int		spd_;
  int		sat_;
  int		sde_;
  bool		alive;
}

#endif

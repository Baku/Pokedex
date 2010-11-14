/*
** pokemon.h for pokedex in /home/pascua_n//pascua_n/pokedex
** 
** Made by nicolas pascual
** Login   <pascua_n@epitech.net>
** 
** Started on  Sun Nov 14 04:46:20 2010 nicolas pascual
** Last update Sun Nov 14 07:28:42 2010 nicolas pascual
*/

#ifndef __POKEMON_H_
# define __POKEMON_H_

#include <QList>
#include <QString>

#include "evolution.h"
#include "tm_hm.h"
#include "level.h"

class Pokemon
{
 public:
  Pokemon(int);
  Pokemon(Pokemon*);
  ~Pokemon();

  void		setName(QString);
  void		addType(QString);
  void		setDescription(QString);
  void		setWeight(float);
  void		setHeight(float);
  void		setMaxXp(int);
  void		addEvolution(Evolution*);
  void		setRatio(float);
  void		setHp(int);
  void		setAtk(int);
  void		setDef(int);
  void		setSpd(int);
  void		setSat(int);
  void		setSde(int);
  void		addTmHm(Tm_hm*);
  void		addLevel(Level*);
  void		setSpecies(QString);
  void		addEggGroup(QString);
  void		addEgg(QString);

  int		getId() const;
  QString	getName() const;
  QString	getDescription() const;
  QList<QString>	getTypes() const;
  float		getWeight() const;
  float		getHeight() const;
  int		getMaxXp() const;
  QList<Evolution*>	getEvolutions() const;
  float		getRatio() const;
  int		getHp() const;
  int		getAtk() const;
  int		getDef() const;
  int		getSpd() const;
  int		getSat() const;
  int		getSde() const;
  QList<Tm_hm*>	getTmHms() const;
  QList<Level*>	getLevels() const;
  QString	getSpecies() const;
  QList<QString> getEggGroup() const;
  QList<QString> getEggs() const;

  
  QList<QString>	getAttributes();
  void		print();

 private:
  int			id_;
  QList<QString>	types_;
  QString		name_;
  QString		description_;
  float			weight_;
  float			height_;
  int			max_xp_;
  QList<Evolution*>	evo_;
  float			ratio_;
  int			hp_;
  int			atk_;
  int			def_;
  int			spd_;
  int			sat_;
  int			sde_;
  QList<Tm_hm*>		tm_hm_;
  QList<Level*>		level_;
  QString		species_;
  QList<QString>	eggGroup_;
  QList<QString>	eggs_;
};

#endif /* __POKEMON_H_ */

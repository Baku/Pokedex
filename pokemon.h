#ifndef _POKEMON_H_
# define _POKEMON_H_

#include <QString>

class Pokemon
{
 public:
  Pokemon(int);
  virtual ~Pokemon();

  void		setWeight(float);
  void		setHeight(float);
  void		setMaxXp(int);
  void		setEvo(int, int)
  void		setRatio(float);
  void		setHp(int);
  void		setAtk(int);
  void		setDef(int);
  void		setSpd(int);
  void		setSat(int);
  void		setSde(int);

  int		getId() const;
  QString	getDescription();
  QString	getName() const;
  float		getWeight() const;
  float		getHeight() const;
  int		getMaxXp() const;
  int[]		getEvo() const;
  float		getRatio() const;
  int		getHp() const;
  int		getAtk() const;
  int		getDef() const;
  int		getSpd() const;
  int		getSat() const;
  int		getSde() const;

 private:
  int		id_;
  QString	name_;
  QString	description_;
  float		weight_;
  float		height_;
  int		max_xp_;
  int		evo[3];
  float		ratio_;
  int		hp_;
  int		atk_;
  int		def_;
  int		spd_;
  int		sat_;
  int		sde_;
  
}

#endif

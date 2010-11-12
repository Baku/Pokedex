#include "pokemon.h"

Pokemon::Pokemon(int id) : name_(""),
				 weight_(0.0),
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
  for (int i = 0; i < 3; ++i)
    evo[i] = 0;
}



Pokemon::~Pokemon()
{

}

void	Pokemon::setName(QString name)
{
  if (name != NULL)
    name_ = name;
}

void	Pokemon::setWeight(float w)
{
  if (w > 0)
    weight = w;
}

void	Pokemon::setMaxXp(int m)
{
  if (m > 0)
    max_xp_ = m;
}

void	Pokemon::setEvo(int nb, int id)
{
  if (nb >= 0 && nb < 3 && id > 0)
    evo[nb] = id;
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

int	Pokemon::getId() const
{
  return id_;
}

QString	Pokemon::getName() const
{
  return name_;
}

float	Pokemon::getWeight() const
{
  return weight_;
}

int	Pokemon::getMaxXp() const
{
  return max_xp_;
}

int	Pokemon::getEvo(int nb) const
{
  if (nb >= 0 && nb < 4)
    return evo[nb];
  return (0);
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

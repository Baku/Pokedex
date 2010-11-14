#include "equip.h"

Equip::Equip()
{
}

Equip::Equip(int tamer_id) : id_(tamer_id)
{
}

Equip::Equip(int tamer_id, QString name) : id_(tamer_id)
{
  name_ = name;
}

Equip::~Equip()
{
}

Equip::Equip(const Equip &to_copy)
{
  this->name_ = to_copy.name_;
  this->tamerId_ = to_copy.tamerId_;
  this->id_ = to_copy.id_;
}

Equip	&Equip::operator=(const Equip &to_copy)
{
  if (this != &to_copy)
    {
      this->name_ = to_copy.name_;
      this->tamerId_ = to_copy.tamerId_;
      this->id_ = to_copy.id_;
    }
  return *this;
}

void	Equip::setName(QString name)
{
  this->name_ = name;
}

QString	Equip::getName() const
{
  return this->name_;
}

int	Equip::getId() const
{
  return this->id_;
}

int	Equip::getTamerId() const
{
  return this->tamerId_;
}

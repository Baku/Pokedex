#include "equip.h"

equip::equip()
{
}

equip::equip(int tamer_id) : _id(id)
{
}

equip::equip(int tamer_id, std::string name) : _id(id)
{
  _name = name;
}

equip::~equip()
{
}

equip	*equip::equip(const equip &to_copy)
{
  this->_name = to_copy.name;
  this->_tamerId = to_copy._tamerId;
  this->_id = to_copy._id;
  return this;
}

equip	*operator=(const equip &to_copy)
{
  if (this != &to_copy)
    {
      this->_name = to_copy.name;
      this->_tamerId = to_copy._tamerId;
      this->_id = to_copy._id;
    }
  return this;
}

void	equip::set_name(std::string name)
{
  this->_name = name;
}

Qstring	equip::get_name() const
{
  return this->_name;
}

int	equip::get_id() const
{
  return this->_id;
}

int	equip::get_tamerId() const
{
  return this->_tamerId;
}

#include "attack.h"

attack::attack()
{
}

attack::~attack()
{
}

attack	*attack::attack(const attack &to_copy)
{
  this->_level = to_copy._level;
  this->_type = to_copy._type;
  this->_name = to_copy._name;
  this->is_special = to_copy._is_special;
  this->_id = to_copy._id;
  return this;
}

attack	*operator=(const attack &to_copy)
{
  if (*this != to_copy)
    {
      this->_level = to_copy._level;
      this->_type = to_copy._type;
      this->_name = to_copy._name;
      this->is_special = to_copy._is_special;
      this->_id = to_copy._id;
    }
  return this;
}

void	attack::set_name(std::string name)
{
  this->_name = name;
}

void	attack::set_type(std::string type)
{
  this->_type = type;
}

int	attack::get_level() const
{
  return this->_level;
}

Qstring	attack::get_name() const
{
  return this->_name;
}

Qstring	attack::get_type() const
{
  return this->_type;
}

bool	attack::get_special() const
{
  return this->is_special;
}

int	attack::get_id() const
{
  return this->_id;
}

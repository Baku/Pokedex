#include "tamer.h"

tamer::tamer()
{
}

tamer::tamer(int type, std::string name = "red") : _genre(type)
{
  _name = name;
  this->_id = 1;
  // this->_id = last_tamer_id();
}

tamer::~tamer()
{
}

tamer::tamer(const tamer &to_copy)
{
  this->_name = to_copy._name;
  this->_id = to_copy._id;
  this->_genre = to_copy._genre;
  return *this;
}

tamer	&operator=(const tamer &to_copy)
{
  if (this != &to_copy)
    {
      this->_name = to_copy._name;
      this->_id = to_copy._id;
      this->_genre = to_copy._genre;
    }
  return *this;
}

void	tamer::set_genre(int genre)
{
  this->_genre = genre;
}

void	tamer::set_name(std::string name)
{
  this->_name = name;
}

int	tamer::get_id() const
{
  return this->_id
}

int	tamer::get_genre() const
{
  return this->_genre;
}

Qstring	tamer::get_name() const
{
  return this->_name;
}

#include "tm_hm.h"

Tm_hm::Tm_hm()
{

}

Tm_hm::~Tm_hm()
{

}

void	Tm_hm::setMachine(QString mach)
{
  machine_ = mach;
}

void	Tm_hm::setName(QString name)
{
  name_ = name;
}

void	Tm_hm::setLevel(int lvl)
{
  level_ = lvl;
}

QString	Tm_hm::getMachine() const
{
  return machine_;
}

QString	Tm_hm::getName() const
{
  return name_;
}

int	Tm_hm::getLevel() const
{
  return level_;
}

void	Tm_hm::print() const
{
  std::cout << "machine: " << machine_.toStdString() << std::endl;
  std::cout << "name: " << name_.toStdString() << std::endl;
  std::cout << "level: " << level_ << std::endl;
}

QString	Tm_hm::to_xml()
{
  QString res = "";
  QString tmp;

  res += "<move type='TM/HM'>\n";
  res += "<machine>" + machine_ + "</machine>\n";
  res += "<name>" + name_ + "</name>\n";
  res += "<lvl>" + tmp.setNum(level_) + "</lvl>\n";
  res += "</move>\n";
  return res;
}

#include "pokedexParser.h"
#include <iostream>

PokedexParser::PokedexParser(QString filename) : filename_(filename)
{
  inPokedex_ = false;
  inEvo_ = false;
  inTmHm_ = false;
  inLevel_ = false;
  inEggs_ = false;
}

PokedexParser::~PokedexParser()
{

}

void	PokedexParser::parse()
{
  QFile *file = new QFile(filename_);
  QXmlInputSource source(file);
  QXmlSimpleReader reader;
  reader.setContentHandler(this);
  reader.parse(source);
}
 
Pokemon	*PokedexParser::getPokemon(int id)
{
  QList<Pokemon>::iterator begin = pokedex_.begin();
  QList<Pokemon>::iterator end = pokedex_.end();
  
  for (QList<Pokemon>::iterator it = begin; it != end; ++it)
    if ((*it).getId() == id)
      return (new Pokemon((*it)));
  std::cout << "Error, Your pokemon doesn't exist" << std::endl;
  return (NULL);
}

Pokemon	*PokedexParser::getPokemon(QString name)
{
  QList<Pokemon>::iterator begin = pokedex_.begin();
  QList<Pokemon>::iterator end = pokedex_.end();
  
  for (QList<Pokemon>::iterator it = begin; it != end; ++it)
    if ((*it).getName() == name)
      return (new Pokemon((*it)));
  std::cout << "Error, Your pokemon doesn't exist" << std::endl;
  return (NULL);
}

bool PokedexParser::startElement(const QString		&//namespaceURI
				 ,
				 const QString		&//localName
				 ,
				 const QString		&qName,
				 const QXmlAttributes	&attrs)
{
  if (qName == "pokedex")
    this->inPokedex_ = true;
  else if (qName == "pokemon")
    {
      if ((attrs.count() >= 1) && (attrs.qName(0) == "id"))
	tmpPok_ = new Pokemon(attrs.value(0).toInt());
      else
	tmpPok_ = NULL;
    }
  else if (qName == "evolution")
    {
      if ((attrs.count() >= 1) && (attrs.qName(0) == "id"))
	tmpEvo_ = new Evolution(attrs.value(0).toInt());
      inEvo_ = true;
    }
  else if (qName == "move")
    {
      if ((attrs.count() >= 1) && (attrs.qName(0) == "type"))
	{
	  if (attrs.value(0) == "level-up")
	    {
	      tmpLevel_ = new Level();
	      inLevel_ = true;
	    }
	  else if (attrs.value(0) == "TM/HM")
	    {
	      tmpTm_hm_ = new Tm_hm();
	      inTmHm_ = true;
	    }
	  else if (attrs.value(0) == "egg")
	    inEggs_ = true;
	}
    }
  return true;
}

bool PokedexParser::endElement(const QString  &//namespaceURI
			       ,
			       const QString  &//localName
			       ,
			       const QString &qName)
{
  if (qName == "pokedex")
    this->inPokedex_ = false;
  else if (qName == "pokemon")
    {
      pokedex_.append(tmpPok_);
      tmpPok_ = NULL;
    }
  else if (qName == "evolution")
    {
      tmpPok_->addEvolution(tmpEvo_);
      inEvo_ = false;
    }  
  else if (qName == "ability")
    tmpPok_->setAbility(tmpString_);
  else if (qName == "move")
    {
      if (inTmHm_)
	{
	  tmpPok_->addTmHm(tmpTm_hm_);
	  tmpTm_hm_ = NULL;
	  inTmHm_ = false;
	}
      else if (inLevel_)
	{
	  tmpPok_->addLevel(tmpLevel_);
	  tmpLevel_ = NULL;
	  inLevel_ = false;
	}
      else if (inEggs_)
	inEggs_ = false;
    }
  else if (qName == "name")
    {
      if (inEvo_)
	tmpEvo_->setName(tmpString_);
      else if (inTmHm_)
	tmpTm_hm_->setName(tmpString_);
      else if (inLevel_)
	tmpLevel_->setName(tmpString_);
      else if (inEggs_)
	tmpPok_->addEgg(tmpString_);
      else
	tmpPok_->setName(tmpString_);
    }
  else if (qName == "type")
    tmpPok_->addType(tmpString_);
  else if (qName == "lvl")
    {
      if (inEvo_)
	tmpEvo_->setLevel(tmpString_.toInt());
      else if (inTmHm_)
	tmpTm_hm_->setLevel(tmpString_.toInt());
      else if (inLevel_)
	tmpLevel_->setLevel(tmpString_.toInt());
    }  
  else if (qName == "exp")
    tmpPok_->setMaxXp(tmpString_.toInt());
  else if (qName == "species")
    tmpPok_->setSpecies(tmpString_);
  else if (qName == "egg-group")
    tmpPok_->addEggGroup(tmpString_);
  else if (qName == "height")
    tmpPok_->setHeight(tmpString_.toFloat());
  else if (qName == "description")
    tmpPok_->setDescription(tmpString_);
  else if (qName == "machine")
    tmpTm_hm_->setMachine(tmpString_);
  else if (qName == "weight")
    tmpPok_->setWeight(tmpString_.toFloat());
  else if (qName == "male")
    tmpPok_->setRatio(tmpString_.toFloat());
  else if (qName == "HP")
    tmpPok_->setHp(tmpString_.toInt());
  else if (qName == "ATK")
    tmpPok_->setAtk(tmpString_.toInt());
  else if (qName == "DEF")
    tmpPok_->setDef(tmpString_.toInt());
  else if (qName == "SPD")
    tmpPok_->setSpd(tmpString_.toInt());
  else if (qName == "SAT")
    tmpPok_->setSat(tmpString_.toInt());
  else if (qName == "SDF")
    tmpPok_->setSde(tmpString_.toInt());
  return true;
}

bool PokedexParser::characters(const QString &str)
{
  tmpString_ = str;
  return true;
}

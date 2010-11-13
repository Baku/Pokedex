#ifndef _XMLPARSER_H_
# define _XMLPARSER_H_

#include <QList>
#include "pokemon.h"

class PokedexParser : public QXmlDefaultHandler
{
 public:
  PokedexParser(std::string);
  virtual ~PokedexParser();
  void	parse();
  Pokemon	*getPokemon(int id); /* creation new Pokemon*/

  //parser methods

private:
  QList<Pokemon>	pokedex_;
  QString		filename_;
}


#endif

#include "pokedexParser.h"
#include "pokemon.h"

#include <iostream>

int	main(int // ac
	     , char **// av
	     )
{
  PokedexParser parser("1to10.xml");

  parser.parse();

  for (int i = 1; i <= parser.pokedex_.size(); ++i)
    {
      Pokemon *p = parser.getPokemon(i);
      if (p != NULL)
	p->print();
    }
  return (0);
}

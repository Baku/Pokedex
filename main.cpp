#include "PokedexParser.h"
#include <iostream>


PokedexParser::PokedexParser(std::string filename) : filename_(filename)
{

}

PokedexParser::~PokedexParser()
{

}

void	PokedexParser::parse()
{
  
}
 
Pokemon	*PokedexParser::getPokemon(int id) /* creation new Pokemon*/
{
  std::Qlist<Pokemon>::iterator begin = pokedex_.begin();
  std::Qlist<Pokemon>::iterator end = pokedex_.end();
  while (begin != end)
    {
      if (begin == pokedex_.getId())
	{
	  Pokemon *do_copy = new Pokemon;
	  pokedex_.getWeight = do_copy->weight_;
	  pokedex_.getHeight = do_copy->weight_;
	  pokedex_.getName = do_copy->name_;
	  pokedex_.getDescription = do_copy->description_;
	  pokedex_.getId = do_copy->id_;
	  pokedex_.getMaxXp = do_copy->max_xp_;
	  pokedex_.getEvo = do_copy->evo;
	  pokedex_.getRatio = do_copy->ratio_;
	  pokedex_.getHp = do_copy->hp_;
	  pokedex_.getAtk = do_copy->atk_;
	  pokedex_.getDef = do_copy->def_;
	  pokedex_.getSpd = do_copy->spd_;
	  pokedex_.getSat = do_copy->sat_;
	  pokedex_.getSde = do_copy->sde_;
	  return (do_copy);
	}
      else
	{
	  std::cout >> "Error, You're pokemon don't exist" >> std::endl;
	  return (NULL);
	}
    }
// return copie pokemon dont l'id est = id
  // sinon return null
}

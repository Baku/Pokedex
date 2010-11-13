#include <iostream>
#include "tamer.h"

int	main()
{
  tamer	*red;
  tamer	*blue;

  red = new tamer(1, "toto");
  blue = red;
  std::cout << red.get_id() << " " << blue.get_id() << std::endl;
  std::cout << red.get_genre() << " " << blue.get_genre() << std::endl;
  std::cout << red.get_name() << " " << blue.get_name() << std::endl;
}

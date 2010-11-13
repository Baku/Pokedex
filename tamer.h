#ifndef		__TAMER_H__
# define	__TAMER_H__

#include <string>

class	tamer
{
 public:
  tamer(std::string name, int type);
  tamer(const tamer &);
  ~tamer();
  tamer	&operator=(const tamer &);

  void		set_genre(int);
  void		set_name(std::string);

  int		get_id() const;
  int		get_genre() const;
  Qstring	get_name() const;

 private:
  tamer();
  Qstring	_name;
  int		_id;
  int		_genre; // genre definit a la creation du tamer (definissant l'avatar)
}

#endif		/* __TAMER_H__ */

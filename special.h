#ifndef		__SPECIAL_H__
# define	__SPECIAL_H__

class	special
{
 public:
  special();
  ~special();

 private:
  Qstring	_name;
  Qstring	_kind;
  Qstring	_type;
  int		_pp;
  int		_accuracy;
  Qstring	_information;
  Qstring	_location;
  Qstring	_suggestion;
}

#endif		/* __SPECIAL_H__ */

#ifndef		__ATTACK_H__
# define	__ATTACK_H__

class	attack
{
 public:
  attack();
  ~attack();
  attack	*attack(const attack &);
  attack	*operator=(const attack &);

  void		set_name(std::string);
  void		set_type(std::string);

  int		get_level() const;
  Qstring	get_name() const;
  Qstring	get_type() const;
  bool		get_special() const;
  int		get_id() const;

 private:
  int		_level;
  Qstring	_type;
  Qstring	_name;
  bool		_is_special;
  int		_id;
}

#endif /* __ATTACK_H__ */

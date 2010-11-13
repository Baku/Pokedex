#ifndef		__EQUIP_H__
# define	__EQUIP_H__

class	equip
{
 public:
  equip(int);
  equip(int, std::string);
  equip	*equip(const equip &);
  ~equip();
  equip	*operator=(const equip &);

  void		set_name(std::string);

  Qstring	get_name() const;
  int		get_tamerId() const;
  int		get_id() const;

 private:
  equip();
  Qstring	_name;
  int		_tamerId;
  int		_id;
}

#endif		/* __EQUIP_H__ */

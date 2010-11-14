/*
** pokedexParser.h for pokedex in /home/pascua_n//pascua_n/pokedex
** 
** Made by nicolas pascual
** Login   <pascua_n@epitech.net>
** 
** Started on  Sun Nov 14 04:43:27 2010 nicolas pascual
** Last update Sun Nov 14 04:58:17 2010 nicolas pascual
*/

#ifndef __POKEDEXPARSER_H_
# define __POKEDEXPARSER_H_

#include <QtXml>
#include <QList>
#include <QString>
#include "pokemon.h"

class PokedexParser : public QXmlDefaultHandler
{
 public:
  PokedexParser(QString);
  virtual ~PokedexParser();
  void	parse();
  Pokemon	*getPokemon(int id);

  //parser methods
  bool startElement(const QString &namespaceURI, const QString &localName,
		    const QString &qName, const QXmlAttributes &attributes);
  bool endElement(const QString &namespaceURI, const QString &localName,
		  const QString &qName);
  bool characters(const QString &str);

  QList<Pokemon>	pokedex_;
private:
  QString		filename_;
  bool			inPokedex_;
  bool			inEvo_;
  bool			inTmHm_;
  bool			inLevel_;
  Pokemon		*tmpPok_;
  QString		tmpString_;
  Evolution		*tmpEvo_;
  Tm_hm			*tmpTm_hm_;
  Level			*tmpLevel_;
};


#endif /* __POKEDEXPARSER_H_ */

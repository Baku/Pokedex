#!/bin/sh
##
## img.sh
## Login : <baku@anthrax>
## Started on  Sat Nov 13 13:43:41 2010 baku
## $Id$
##
## Author(s):
##  - baku <millet_c@epitech.net>
##
## Copyright (C) 2010 baku
## This program is free software; you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation; either version 3 of the License, or
## (at your option) any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with this program; if not, write to the Free Software
## Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
##


if [ ! -d "img" ];
then
  mkdir img
fi
i=1
while [ $i -le 493 ];
do
  ##echo "$i";
  wget http://www.pokebip.com/pokemon/pokedex/images/sugimori/$i.png
  i=$(($i + 1))
done

mv *.png img/

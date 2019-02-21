/*
 * Copyright (c) 2018-2019 GMRV/URJC.
 *
 * Authors: Gonzalo Bayo Martinez <gonzalo.bayo@urjc.es>
 *
 * This file is part of VishnuCommon <https://gitlab.gmrv.es/cbbsp1/vishnucommon>
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License version 3.0 as published
 * by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#include "Property.h"

namespace vishnucommon
{
  Property::Property( void )
  {

  }

  Property::Property( const std::string& name, const DataCategory& dataCategory,
    const DataStructureType& dataStructureType )
      : _name( name )
      , _dataCategory( dataCategory )
      , _dataStructureType( dataStructureType )
  {

  }

  Property::~Property( void )
  {

  }

  std::string Property::getName( void ) const
  {
    return _name;
  }

  void Property::setName( const std::string& name )
  {
    _name = name;
  }

  DataCategory Property::getDataCategory( void ) const
  {
    return _dataCategory;
  }

  void Property::setDataCategory( const DataCategory& dataCategory )
  {
    _dataCategory = dataCategory;
  }

  DataStructureType Property::getDataStructureType( void ) const
  {
    return _dataStructureType;
  }

  void Property::setDataStructureType(
    const DataStructureType& dataStructureType )
  {
    _dataStructureType = dataStructureType;
  }

  void Property::deserialize( const QJsonObject& jsonObject )
  {
    _name = jsonObject[ "name" ].toString( ).toStdString( );
    _dataCategory = toDataCategory(
      jsonObject["dataCategory" ].toString( ).toStdString( ) );
    _dataStructureType = toDataStructureType(
      jsonObject["dataStructureType" ].toString( ).toStdString( ) );
  }

  void Property::serialize( QJsonObject& jsonObject ) const
  {
    jsonObject["name"] = QString::fromStdString( _name );
    jsonObject["dataCategory"] = QString::fromStdString(
      toString( _dataCategory ) );
    jsonObject["dataStructureType"] = QString::fromStdString( toString(
      _dataStructureType ) );
  }

}

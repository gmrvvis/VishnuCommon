/* 
 * Copyright (c) 2018-2019 GMRV/URJC.
 * 
 * Authors: Gonzalo Bayo Martinez <gonzalo.bayo@urjc.es>
 * 
 * This file is part of VishnuCommon <https://gitlab.gmrv.es/cbbsp1/vishnucommon>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of his software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
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

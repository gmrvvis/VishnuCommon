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

#include "Feature.h"

namespace vishnucommon
{

  Feature::Feature( void )
  {

  }

  Feature::Feature( const std::string& sourceColumn,
    const std::string& applicationLabel, const std::string& unitsLabel,
    const DataCategory& dataCategory, const DataStructureType& dataStructureType )
      : _sourceColumn( sourceColumn )
      , _applicationLabel( applicationLabel )
      , _unitsLabel( unitsLabel )
      , _dataCategory( dataCategory )
      , _dataStructureType( dataStructureType )
  {

  }

  Feature::~Feature( void )
  {

  }

  std::string Feature::getSourceColumn( void ) const
  {
    return _sourceColumn;
  }

  void Feature::setSourceColumn( const std::string& sourceColumn )
  {
    _sourceColumn = sourceColumn;
  }

  std::string Feature::getApplicationLabel( void ) const
  {
    return _applicationLabel;
  }

  void Feature::setApplicationLabel( const std::string& applicationLabel )
  {
    _applicationLabel = applicationLabel;
  }

  std::string Feature::getUnitsLabel( void ) const
  {
    return _unitsLabel;
  }

  void Feature::setUnitsLabel( const std::string& unitsLabel )
  {
    _unitsLabel = unitsLabel;
  }

  DataCategory Feature::getDataCategory( void ) const
  {
    return _dataCategory;
  }

  void Feature::setDataCategory( const DataCategory& dataCategory )
  {
    _dataCategory = dataCategory;
  }

  DataStructureType Feature::getDataStructureType( void ) const
  {
    return _dataStructureType;
  }

  void Feature::setDataStructureType( const DataStructureType& dataStructureType )
  {
    _dataStructureType = dataStructureType;
  }

  void Feature::serialize( QXmlStreamWriter& streamWriter ) const
  {
    streamWriter.writeStartElement( "feature" );
    streamWriter.writeAttribute( "sourceColumn",
      QString::fromStdString( _sourceColumn ) );
    streamWriter.writeAttribute( "applicationLabel",
      QString::fromStdString( _applicationLabel ) );
    streamWriter.writeAttribute( "unitsLabel",
      QString::fromStdString( _unitsLabel ) );
    streamWriter.writeAttribute( "dataCategory",
      QString::fromStdString( toString( _dataCategory ) ) );
    streamWriter.writeAttribute( "dataStructureType",
      QString::fromStdString( toString( _dataStructureType ) ) );
    streamWriter.writeEndElement( );
  }

}

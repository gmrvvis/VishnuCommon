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

#include "DataSet.h"

#include <QJsonArray>

namespace vishnucommon
{
  DataSet::DataSet( void )
  {

  }

  DataSet::DataSet( const std::string& path )
    : _path( path )
  {

  }

  DataSet::DataSet( const std::string& path,
    const Properties& dataSetProperties,
    const MetadataPtr& metadata )
      : _path( path )
      , _properties( dataSetProperties )
      , _metadata( metadata )
  {

  }

  DataSet::~DataSet( void )
  {

  }

  std::string DataSet::getPath( void ) const
  {
    return _path;
  }

  void DataSet::setPath( const std::string& path )
  {
    _path = path;
  }

  Properties DataSet::getProperties( void ) const
  {
    return _properties;
  }

  void DataSet::setProperties( const Properties& properties )
  {
    _properties = properties;
  }

  void DataSet::addProperty( const PropertyPtr& property )
  {
    _properties.emplace_back( property );
  }

  std::vector< std::string > DataSet::getPropertyNames (void ) const
  {
    std::vector< std::string > propertyNames;
    for ( const auto& property : _properties )
    {
      propertyNames.emplace_back( property->getName( ) );
    }
    return propertyNames;
  }

  MetadataPtr DataSet::getMetadata( void ) const
  {
    return _metadata;
  }

  void DataSet::setMetadata( const MetadataPtr& metadata )
  {
    _metadata = metadata;
  }

  void DataSet::deserialize( const QJsonObject& jsonObject )
  {
    _path = jsonObject[ "path" ].toString( ).toStdString( );
    QJsonArray properties = jsonObject[ "properties" ].toArray( );
    for (int i = 0; i < properties.size(); ++i)
    {
      QJsonObject propertyObject = properties.at( i ).toObject();
      PropertyPtr dataSetProperty( new Property( ) );
      dataSetProperty->deserialize( propertyObject );
      _properties.push_back( dataSetProperty );
    }

    QJsonObject metadataObject = jsonObject[ "metadata" ].toObject( );
    _metadata.reset( new Metadata( ) );
    _metadata->deserialize( metadataObject );
  }

  void DataSet::serialize( QJsonObject& jsonObject ) const
  {
    jsonObject[ "path" ] = QString::fromStdString( _path );

    QJsonArray properties;
    for ( const auto& property : _properties )
    {
        QJsonObject propertyObject;
        property->serialize(propertyObject);
        properties.append(propertyObject);
    }
    jsonObject[ "properties" ] = properties;

    QJsonObject metadataObject;
    if ( _metadata != nullptr )
    {
      _metadata->serialize( metadataObject );
    }
    jsonObject[ "metadata" ] = metadataObject;
  }

}

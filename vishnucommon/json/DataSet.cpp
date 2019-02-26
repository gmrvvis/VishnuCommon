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

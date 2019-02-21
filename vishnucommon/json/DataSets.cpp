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

#include "DataSets.h"

#include <QJsonArray>

namespace vishnucommon
{

  DataSets::DataSets( void )
  {

  }

  DataSets::DataSets( const DataSetVector& dataSets )
    : _dataSets( dataSets )
  {

  }

  DataSets::~DataSets( void )
  {

  }

  DataSetVector DataSets::getDataSets( ) const
  {
    return _dataSets;
  }

  void DataSets::setDataSets( const DataSetVector& dataSets )
  {
    _dataSets = dataSets;
  }

  void DataSets::addDataSet( const DataSetPtr& dataSet )
  {
    _dataSets.emplace_back( dataSet );
  }

  PropertyGroupsPtr DataSets::getPropertyGroups( void ) const
  {
    return _propertyGroups;
  }

  void DataSets::setPropertyGroups( const PropertyGroupsPtr& propertyGroups )
  {
    _propertyGroups = propertyGroups;
  }

  MetadataPtr DataSets::getMetadata( void ) const
  {
    return _metadata;
  }

  void DataSets::setMetadata( const MetadataPtr& metadata )
  {
    _metadata = metadata;
  }

  void DataSets::deserialize( const QJsonObject& jsonObject )
  {
    QJsonArray dataSets = jsonObject[ "dataSets" ].toArray( );
    for (int i = 0; i < dataSets.size(); ++i)
    {
      QJsonObject dataSetObject = dataSets.at( i ).toObject();
      DataSetPtr dataSet( new DataSet( ) );
      dataSet->deserialize( dataSetObject );
      _dataSets.push_back( dataSet );
    }

    QJsonObject propertyGroupsObject =
      jsonObject[ "propertyGroups" ].toObject( );
    _propertyGroups.reset( new PropertyGroups( ) );
    _propertyGroups->deserialize( propertyGroupsObject );

    QJsonObject metadataObject = jsonObject[ "metadata" ].toObject( );
    _metadata.reset( new Metadata( ) );
    _metadata->deserialize( metadataObject );
  }

  void DataSets::serialize( QJsonObject& jsonObject ) const
  {
    QJsonArray dataSets;
    if ( _dataSets.size( ) > 0 )
    {
      for ( const auto& dataSet : _dataSets )
      {
        QJsonObject dataSetObject;
        dataSet->serialize( dataSetObject );
        dataSets.append( dataSetObject );
      }
    }
    jsonObject[ "dataSets" ] = dataSets;

    QJsonObject propertyGroupsObject;
    if ( _propertyGroups != nullptr )
    {
      _propertyGroups->serialize( propertyGroupsObject );
    }
    jsonObject[ "propertyGroups" ] = propertyGroupsObject;

    QJsonObject metadataObject;
    if ( _metadata != nullptr )
    {
      _metadata->serialize( metadataObject );
    }
    jsonObject[ "metadata" ] = metadataObject;
  }

}

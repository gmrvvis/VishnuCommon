/* 
 * Copyright (c) 2018-2019 GMRV/URJC.
 * 
 * Authors: Gonzalo Bayo Martinez <gonzalo.bayo@urjc.es>
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

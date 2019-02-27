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

#include "PropertyGroups.h"

#include <QJsonArray>

namespace vishnucommon
{

  PropertyGroups::PropertyGroups( )
  {

  }

  PropertyGroups::PropertyGroups(
    const std::vector< std::string >& usedPrimaryKeys,
    const std::vector< std::string >& usedNonPrimaryKeys,
    const std::string& xAxis, const std::string& yAxis,
    const std::string& zAxis )
      : _usedPrimaryKeys( usedPrimaryKeys )
      , _usedNonPrimaryKeys( usedNonPrimaryKeys )
      , _axes( { xAxis, yAxis, zAxis } )
  {

  }

  PropertyGroups::PropertyGroups(
    const std::vector< std::string >& usedPrimaryKeys,
    const std::vector< std::string >& usedNonPrimaryKeys,
    const std::string& axes )
      : _usedPrimaryKeys( usedPrimaryKeys )
      , _usedNonPrimaryKeys( usedNonPrimaryKeys )
      , _axes( { axes } )
  {

  }

  PropertyGroups::~PropertyGroups( void )
  {

  }

  std::vector< std::string > PropertyGroups::getUsedPrimaryKeys( void ) const
  {
    return _usedPrimaryKeys;
  }

  void PropertyGroups::setUsedPrimaryKeys(
    const std::vector< std::string >& usedPrimaryKeys )
  {
    _usedPrimaryKeys = usedPrimaryKeys;
  }

  void PropertyGroups::addUsedPrimaryKey( const std::string& usedPrimaryKey )
  {
    _usedPrimaryKeys.emplace_back( usedPrimaryKey );
  }

  std::vector< std::string > PropertyGroups::getUsedNonPrimaryKeys( void ) const
  {
    return _usedNonPrimaryKeys;
  }

  void PropertyGroups::setUsedNonPrimaryKeys(
    const std::vector< std::string >& usedNonPrimaryKeys )
  {
    _usedNonPrimaryKeys = usedNonPrimaryKeys;
  }

  void PropertyGroups::addUsedNonPrimaryKey(
    const std::string& usedNonPrimaryKey )
  {
    _usedNonPrimaryKeys.emplace_back( usedNonPrimaryKey );
  }

  std::vector< std::string > PropertyGroups::getAxes( void ) const
  {
    return _axes;
  }

  void PropertyGroups::setAxes( const std::string& xAxis,
    const std::string& yAxis, const std::string& zAxis )
  {
    _axes = { xAxis, yAxis, zAxis };
  }

  void PropertyGroups::setAxes( const std::string& axes )
  {
    _axes = { axes };
  }

  std::vector< std::string > PropertyGroups::getHeaders( void ) const
  {
    std::vector< std::string > pkHeaders = _usedPrimaryKeys;
    pkHeaders.insert( pkHeaders.end( ), _usedNonPrimaryKeys.begin( ),
      _usedNonPrimaryKeys.end( ) );
    return pkHeaders;
  }

  void PropertyGroups::deserialize( const QJsonObject& jsonObject )
  {
    _usedPrimaryKeys.clear( );
    QJsonArray usedPrimaryKeys = jsonObject[ "usedPrimaryKeys" ].toArray( );
    for ( int i = 0; i < usedPrimaryKeys.size( ); ++i )
    {
      _usedPrimaryKeys.emplace_back(
        usedPrimaryKeys.at( i ).toString( ).toStdString( ) );
    }

    _usedNonPrimaryKeys.clear( );
    QJsonArray usedNonPrimaryKeys =
      jsonObject[ "usedNonPrimaryKeys" ].toArray( );
    for ( int i = 0; i < usedNonPrimaryKeys.size( ); ++i )
    {
      _usedNonPrimaryKeys.emplace_back(
        usedNonPrimaryKeys.at( i ).toString( ).toStdString( ) );
    }

    _axes.clear( );
    QJsonArray axes = jsonObject[ "axes" ].toArray( );
    for ( int i = 0; i < axes.size( ); ++i )
    {
      _axes.emplace_back( axes.at( i ).toString( ).toStdString( ) );
    }
  }

  void PropertyGroups::serialize( QJsonObject& jsonObject ) const
  {
    QJsonArray usedPrimaryKeys;
    for ( const auto& usedPrimaryKey : _usedPrimaryKeys )
    {
      usedPrimaryKeys.append( QString::fromStdString( usedPrimaryKey ) );
    }
    jsonObject[ "usedPrimaryKeys" ] = usedPrimaryKeys;

    QJsonArray usedNonPrimaryKeys;
    for ( const auto& nonPrimaryKey : _usedNonPrimaryKeys )
    {
      usedNonPrimaryKeys.append( QString::fromStdString( nonPrimaryKey ) );
    }
    jsonObject[ "usedNonPrimaryKeys" ] = usedNonPrimaryKeys;

    QJsonArray axes;
    for ( const auto& axis : _axes )
    {
      axes.append( QString::fromStdString( axis ) );
    }
    jsonObject[ "axes" ] = axes;
  }

}

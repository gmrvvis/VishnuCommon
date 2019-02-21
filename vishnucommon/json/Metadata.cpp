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

#include "Metadata.h"

#include <QStringList>

namespace vishnucommon
{

  Metadata::Metadata( )
  {

  }

  Metadata::Metadata( const MetadataMap& metadata )
    : _metadata( metadata )
  {

  }

  Metadata::~Metadata( void )
  {

  }

  MetadataMap Metadata::getMetadata( void ) const
  {
    return _metadata;
  }

  void Metadata::setMetadata( const MetadataMap& metadata )
  {
    _metadata = metadata;
  }

  std::string Metadata::getMetadata( const std::string& key ) const
  {
    return _metadata.at( key );
  }

  void Metadata::setMetadata( const std::string& key, const std::string& value )
  {
    _metadata[ key ] = value;
  }

  void Metadata::deserialize( const QJsonObject &jsonObject )
  {
    QJsonObject metadata = jsonObject[ "metadata" ].toObject( );
    for (int i = 0; i < metadata.size( ); ++i)
    {
      std::string key = metadata.keys( ).at( i ).toStdString( );
      _metadata[ key ] =
        metadata[ QString::fromStdString( key ) ].toString( ).toStdString( );
    }
  }

  void Metadata::serialize( QJsonObject &jsonObject ) const
  {
    QJsonObject metadata;
    for ( const auto& met : _metadata )
    {
      metadata[ QString::fromStdString( met.first ) ] =
        QString::fromStdString( met.second );
    }
    jsonObject[ "metadata" ] = metadata;
  }

}

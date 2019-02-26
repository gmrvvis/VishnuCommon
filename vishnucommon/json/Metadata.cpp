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

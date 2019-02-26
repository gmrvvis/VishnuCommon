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

#include "Features.h"

namespace vishnucommon
{

  Features::Features( void )
  {

  }

  Features::Features( const std::vector< std::string >& idColumns,
    const std::vector< std::string >& positionsXYZColumn,
    const std::string& geometryColumn, const FeaturesVector& features )
      : _idColumns( idColumns )
      , _positionsXYZColumn( positionsXYZColumn )
      , _geometryColumn( geometryColumn )
      , _features( features )
  {

  }

  Features::~Features( void )
  {

  }

  std::vector< std::string > Features::getIdColumns( void ) const
  {
    return _idColumns;
  }

  void Features::setIdColumns( const std::vector< std::string >& idColumns )
  {
    _idColumns = idColumns;
  }

  std::vector< std::string > Features::getPositionsXYZColumn( void ) const
  {
    return _positionsXYZColumn;
  }

  void Features::setPositionsXYZColumn(
    const std::vector< std::string >& positionsXYZColumn )
  {
    _positionsXYZColumn = positionsXYZColumn;
  }

  std::string Features::getGeometryColumn( void ) const
  {
    return _geometryColumn;
  }

  void Features::setGeometryColumn( const std::string& geometryColumn )
  {
    _geometryColumn = geometryColumn;
  }

  FeaturesVector Features::getFeatures( void ) const
  {
    return _features;
  }

  void Features::setFeatures( const FeaturesVector& features )
  {
    _features = features;
  }

  void Features::serialize( QXmlStreamWriter& streamWriter ) const
  {
    streamWriter.writeStartElement( "features" );
    streamWriter.writeAttribute( "idColumn",
      QString::fromStdString( Strings::join( _idColumns, "," ) ) );
    if ( _positionsXYZColumn.size( ) == 1 )
    {
      streamWriter.writeAttribute( "positionXYZColumn",
        QString::fromStdString( _positionsXYZColumn.at( 0 ) ) );
    }
    else
    {
      streamWriter.writeAttribute( "positionXColumn",
        QString::fromStdString( _positionsXYZColumn.at( 0 ) ) );
      streamWriter.writeAttribute( "positionYColumn",
        QString::fromStdString( _positionsXYZColumn.at( 1 ) ) );
      streamWriter.writeAttribute( "positionZColumn",
        QString::fromStdString( _positionsXYZColumn.at( 2 ) ) );
    }
    streamWriter.writeAttribute( "geometryColumn",
      QString::fromStdString( _geometryColumn ) );
    for (const auto& feature : _features )
    {
      feature->serialize( streamWriter );
    }
    streamWriter.writeEndElement( );
  }

}

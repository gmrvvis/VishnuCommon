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

#include "Vec3.h"

namespace vishnucommon
{

  Vec3::Vec3( void )
  {

  }

  Vec3::Vec3( const std::string& x, const std::string& y, const std::string& z)
    : _xyz( { { x, y, z } } )
  {

  }

  Vec3::~Vec3( void )
  {

  }

  std::string Vec3::getX( void ) const
  {
    return _xyz[ 0 ];
  }

  void Vec3::setX( const std::string& x )
  {
    _xyz[ 0 ] = x;
  }

  std::string Vec3::getY( void ) const
  {
    return _xyz[ 1 ];
  }

  void Vec3::setY( const std::string& y )
  {
    _xyz[ 1 ] = y;
  }

  std::string Vec3::getZ( void ) const
  {
    return _xyz[ 2 ];
  }

  void Vec3::setZ( const std::string& z )
  {
    _xyz[ 2 ] = z;
  }

  void Vec3::serialize( QXmlStreamWriter& streamWriter,
    const std::string& elementName,
    const std::vector< std::string >& attributeNames ) const
  {
    streamWriter.writeStartElement( QString::fromStdString( elementName ) );
    streamWriter.writeAttribute(
      QString::fromStdString( attributeNames.at( 0 ) ),
      QString::fromStdString( _xyz[ 0 ] ) );
    streamWriter.writeAttribute(
      QString::fromStdString( attributeNames.at( 1 ) ),
      QString::fromStdString( _xyz[ 1 ] ) );
    streamWriter.writeAttribute(
      QString::fromStdString( attributeNames.at( 2 ) ),
      QString::fromStdString( _xyz[ 2 ] ) );
    streamWriter.writeEndElement( );
  }

}

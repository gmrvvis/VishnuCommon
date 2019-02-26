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

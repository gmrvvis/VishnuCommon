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

#include "Camera.h"

namespace vishnucommon
{

  Camera::Camera( void )
  {

  }

  Camera::Camera( const Vec3Ptr& eye, const Vec3Ptr& center, const Vec3Ptr& up )
    : _eye( eye )
    , _center( center )
    , _up( up )
  {

  }

  Camera::~Camera( void )
  {

  }

  Vec3Ptr Camera::getEye( void ) const
  {
    return _eye;
  }

  void Camera::setEye( const Vec3Ptr& eye )
  {
    _eye = eye;
  }

  Vec3Ptr Camera::getCenter( void ) const
  {
    return _center;
  }

  void Camera::setCenter( const Vec3Ptr& center )
  {
    _center = center;
  }

  Vec3Ptr Camera::getUp( void ) const
  {
    return _up;
  }

  void Camera::setUp( const Vec3Ptr& up )
  {
    _up = up;
  }

  void Camera::serialize( QXmlStreamWriter& streamWriter ) const
  {
    streamWriter.writeStartElement( "camera" );
    _eye->serialize( streamWriter, "eye", { "x", "y", "z" } );
    _center->serialize( streamWriter, "center", { "x", "y", "z" } );
    _up->serialize( streamWriter, "up", { "x", "y", "z" } );
    streamWriter.writeEndElement( );
  }

}

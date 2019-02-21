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

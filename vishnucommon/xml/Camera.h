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

#ifndef VISHNUCOMMON_XML_CAMERA_H
#define VISHNUCOMMON_XML_CAMERA_H

#include <QXmlStreamWriter>

#include <memory>

#include "Vec3.h"

#include <vishnucommon/api.h>

namespace vishnucommon
{

  class VISHNUCOMMON_API Camera;
  typedef std::shared_ptr< Camera > CameraPtr;

  class VISHNUCOMMON_API Camera
  {
    public:
      Camera( void );
      Camera( const Vec3Ptr& eye, const Vec3Ptr& center, const Vec3Ptr& up );
      ~Camera( void );

      Vec3Ptr getEye( void ) const;
      void setEye( const Vec3Ptr& eye );

      Vec3Ptr getCenter( void ) const;
      void setCenter( const Vec3Ptr& center );

      Vec3Ptr getUp( void ) const;
      void setUp( const Vec3Ptr& up );

      void serialize( QXmlStreamWriter& streamWriter ) const;

    private:
      Vec3Ptr _eye;
      Vec3Ptr _center;
      Vec3Ptr _up;

  };
}

#endif

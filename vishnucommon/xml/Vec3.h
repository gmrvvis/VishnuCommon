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

#ifndef VISHNUCOMMON_XML_VEC3_H
#define VISHNUCOMMON_XML_VEC3_H

#include <QXmlStreamWriter>

#include <string>
#include <array>
#include <memory>

#include <vishnucommon/api.h>

namespace vishnucommon
{

  class VISHNUCOMMON_API Vec3;
  typedef std::shared_ptr< Vec3 > Vec3Ptr;

  class VISHNUCOMMON_API Vec3
  {
    public:
      Vec3( void );
      Vec3( const std::string& x, const std::string& y, const std::string& z);
      ~Vec3( void );

      std::string getX( void ) const;
      void setX( const std::string& x );

      std::string getY( void ) const;
      void setY( const std::string& y );

      std::string getZ( void ) const;
      void setZ( const std::string& z );

      void serialize( QXmlStreamWriter& streamWriter,
        const std::string& elementName,
        const std::vector< std::string >& attributeNames ) const;

    private:
      std::array< std::string, 3 > _xyz;

  };

}

#endif

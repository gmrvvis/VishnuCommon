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

#ifndef VISHNUCOMMON_XML_CONFIGURATION_H
#define VISHNUCOMMON_XML_CONFIGURATION_H

#include <QXmlStreamWriter>

#include <string>
#include <memory>

#include "Data.h"
#include "Colors.h"
#include "Camera.h"

#include <vishnucommon/api.h>

namespace vishnucommon
{

  class VISHNUCOMMON_API Configuration;
  typedef std::shared_ptr< Configuration > ConfigurationPtr;

  class VISHNUCOMMON_API Configuration
  {
    public:
      Configuration( void );
      Configuration( const std::string& app, const std::string& version,
        const std::string& label, const DataPtr& data, const ColorsPtr& colors,
        const CameraPtr& camera );
      ~Configuration( void );

      std::string getApp( void ) const;
      void setApp( const std::string& app );

      std::string getVersion( void ) const;
      void setVersion( const std::string& version );

      std::string getLabel( void ) const;
      void setLabel( const std::string& label );

      DataPtr getData( void ) const;
      void setData( const DataPtr& data );

      ColorsPtr getColors( void ) const;
      void setColors( const ColorsPtr& colors );

      CameraPtr getCamera( void ) const;
      void setCamera( const CameraPtr& camera );

      void serialize( QXmlStreamWriter& streamWriter ) const;

    private:
      std::string _app;
      std::string _version;
      std::string _label;
      DataPtr _data;
      ColorsPtr _colors;
      CameraPtr _camera;
  };

}

#endif

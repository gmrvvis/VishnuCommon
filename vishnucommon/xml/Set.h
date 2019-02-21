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

#ifndef VISHNUCOMMON_XML_SET_H
#define VISHNUCOMMON_XML_SET_H

#include <QXmlStreamWriter>

#include <string>
#include <memory>

#include <vishnucommon/api.h>

namespace vishnucommon
{

  class VISHNUCOMMON_API Set;
  typedef std::shared_ptr< Set > SetPtr;  
  typedef std::vector< SetPtr > Sets;

  class VISHNUCOMMON_API Set
  {
    public:
      Set( void );
      Set( const std::string& objectsFeaturesCSV,
        const std::string& objectsMeshesPath = std::string( ),
        const std::string& additionalMeshesPath = std::string( ) );
      ~Set( void );

      std::string getObjectsFeaturesCSV( void ) const;
      void setObjectsFeaturesCSV( const std::string& objectsFeaturesCSV );

      std::string getObjectsMeshesPath( void ) const;
      void setObjectsMeshesPath( const std::string& objectsMeshesPath );

      std::string getAdditionalMeshesPath( void ) const;
      void setAdditionalMeshesPath( const std::string& additionalMeshesPath );

      void serialize( QXmlStreamWriter& streamWriter ) const;

    private:
      std::string _objectsFeaturesCSV;
      std::string _objectsMeshesPath;
      std::string _additionalMeshesPath;
  };

}

#endif

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

#ifndef VISHNUCOMMON_XML_PYRAMIDALXML_H
#define VISHNUCOMMON_XML_PYRAMIDALXML_H

#include <QXmlStreamWriter>

#include <string>
#include <memory>

#include "Configuration.h"

#include <vishnucommon/api.h>

namespace vishnucommon
{

  class VISHNUCOMMON_API PyramidalXML;
  typedef std::shared_ptr< PyramidalXML > PyramidalXMLPtr;

  class VISHNUCOMMON_API PyramidalXML
  {
    public:
      PyramidalXML( void );
      PyramidalXML( const std::string& dtd,
        const ConfigurationPtr& configuration );
      ~PyramidalXML( void );

      std::string getDTD( void ) const;
      void setDTD( const std::string& dtd );

      ConfigurationPtr getConfiguration( void ) const;
      void setConfiguration( const ConfigurationPtr& configuration );

      void serialize( QXmlStreamWriter& streamWriter ) const;

    private:
      std::string _dtd;
      ConfigurationPtr _configuration;
  };

}

#endif

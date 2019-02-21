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

#include "PyramidalXML.h"

namespace vishnucommon
{
  PyramidalXML::PyramidalXML( void )
  {

  }

  PyramidalXML::PyramidalXML( const std::string& dtd,
    const ConfigurationPtr& configuration )
      : _dtd( dtd )
      , _configuration( configuration )
  {

  }

  PyramidalXML::~PyramidalXML( void )
  {

  }

  std::string PyramidalXML::getDTD( void ) const
  {
    return _dtd;
  }

  void PyramidalXML::setDTD( const std::string& dtd )
  {
    _dtd = dtd;
  }

  ConfigurationPtr PyramidalXML::getConfiguration( void ) const
  {
    return _configuration;
  }

  void PyramidalXML::setConfiguration( const ConfigurationPtr& configuration )
  {
    _configuration = configuration;
  }

  void PyramidalXML::serialize( QXmlStreamWriter& streamWriter ) const
  {
    streamWriter.writeDTD( QString::fromStdString( _dtd ) );
    _configuration->serialize( streamWriter );
  }
}

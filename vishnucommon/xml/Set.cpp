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

#include "Set.h"

namespace vishnucommon
{

  Set::Set( void )
  {

  }

  Set::Set( const std::string& objectsFeaturesCSV,
    const std::string& objectsMeshesPath,
    const std::string& additionalMeshesPath )
      : _objectsFeaturesCSV( objectsFeaturesCSV )
      , _objectsMeshesPath( objectsMeshesPath )
      , _additionalMeshesPath( additionalMeshesPath )
  {

  }

  Set::~Set( void )
  {

  }

  std::string Set::getObjectsFeaturesCSV( void ) const
  {
    return _objectsFeaturesCSV;
  }

  void Set::setObjectsFeaturesCSV( const std::string& objectsFeaturesCSV )
  {
    _objectsFeaturesCSV = objectsFeaturesCSV;
  }

  std::string Set::getObjectsMeshesPath( void ) const
  {
    return _objectsMeshesPath;
  }

  void Set::setObjectsMeshesPath( const std::string& objectsMeshesPath )
  {
    _objectsMeshesPath = objectsMeshesPath;
  }

  std::string Set::getAdditionalMeshesPath( void ) const
  {
    return _additionalMeshesPath;
  }

  void Set::setAdditionalMeshesPath( const std::string& additionalMeshesPath )
  {
    _additionalMeshesPath = additionalMeshesPath;
  }

  void Set::serialize( QXmlStreamWriter& streamWriter ) const
  {
    streamWriter.writeStartElement( "set" );
    streamWriter.writeTextElement( "objectsFeaturesCSV",
      QString::fromStdString( _objectsFeaturesCSV ) );
    if ( !_objectsMeshesPath.empty( ) )
    {
      streamWriter.writeTextElement( "objectsMeshesPath",
        QString::fromStdString( _objectsMeshesPath ) );
    }
    if ( !_additionalMeshesPath.empty( ) )
    {
      streamWriter.writeTextElement( "additionalMeshesPath",
        QString::fromStdString( _additionalMeshesPath ) );
    }
    streamWriter.writeEndElement( );
  }

}

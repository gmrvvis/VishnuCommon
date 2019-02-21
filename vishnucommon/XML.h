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

#ifndef VISHNUCOMMON_XML_H
#define VISHNUCOMMON_XML_H

#include <memory>

#include <QFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

#include "Error.hpp"
#include <vishnucommon/api.h>

namespace vishnucommon
{
  class XML
  {

    public:

    template< class T >
    static std::shared_ptr< T > deserialize( const std::string& file )
    {
      QFile qFile( QString::fromStdString( file ) );
      if ( !qFile.open( QIODevice::ReadOnly ) )
      {
        Error::throwError( Error::ErrorType::Error, "Can't read XML file.",
          true );
        exit( -1 );
      }

      std::unique_ptr< T > xmlClass( new T( ) );

      QXmlStreamReader streamReader;
      streamReader.setDevice( &qFile );

      xmlClass->deserialize( streamReader );

      qFile.close( );

      return xmlClass;
    }

    template< class T >
    static bool serialize( const std::string& file,
      std::shared_ptr< T >& xmlClass )
    {
      QFile qFile( QString::fromStdString( file ) );

      if ( !qFile.open( QIODevice::WriteOnly ) )
      {
        Error::throwError( Error::ErrorType::Error, "Can't write XML file.",
          true );
        return false;
      }

      QXmlStreamWriter streamWriter( &qFile );
      streamWriter.setAutoFormatting(true);
      streamWriter.writeStartDocument();
      xmlClass->serialize( streamWriter );
      streamWriter.writeEndDocument();

      qFile.close();

      return true;
    }

  };
}

#endif

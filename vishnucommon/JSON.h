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

#ifndef VISHNUCOMMON_JSON_H
#define VISHNUCOMMON_JSON_H

#include <memory>

#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

#include "Error.hpp"
#include <vishnucommon/api.h>

namespace vishnucommon
{
  class JSON
  {

    public:

    template< class T >
    static std::shared_ptr< T > deserialize( const std::string& file )
    {
      QFile qfile( QString::fromStdString( file ) );
      if ( !qfile.open( QIODevice::ReadOnly ) )
      {
        Error::throwError( Error::ErrorType::Error, "Can't read JSON file.",
          true );
        exit( -1 );
      }
      const QByteArray saveData = qfile.readAll( );
      qfile.close( );

      QJsonDocument jsonDocument( QJsonDocument::fromJson( saveData ) );

      QJsonObject qJsonObject = jsonDocument.object( );

      std::shared_ptr< T > jsonData( new T( ) );
      jsonData->deserialize( qJsonObject );
      return jsonData;
    }

    template< class T >
    static bool serialize( const std::string& file,
      const std::shared_ptr< T >& jsonData )
    {
      QFile saveFile( QString::fromStdString( file ) );

      if ( !saveFile.open( QIODevice::WriteOnly ) )
      {
        Error::throwError( Error::ErrorType::Error, "Can't write JSON file.",
          true );
        return false;
      }

      QJsonObject qJsonObject;
      jsonData->serialize( qJsonObject );
      QJsonDocument saveDoc( qJsonObject );
      saveFile.write( saveDoc.toJson( ) );

      return true;
    }

  };
}

#endif

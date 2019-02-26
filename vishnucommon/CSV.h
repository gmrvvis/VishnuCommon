/* 
 * Copyright (c) 2018-2019 GMRV/URJC.
 * 
 * Authors: Gonzalo Bayo Martinez <gonzalo.bayo@urjc.es>
 * 
 * This file is part of VishnuCommon <https://gitlab.gmrv.es/cbbsp1/vishnucommon>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of his software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */

#ifndef VISHNUCOMMON_CSV_H
#define VISHNUCOMMON_CSV_H

#include <string>
#include <memory>

#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

#include "Error.hpp"
#include <vishnucommon/api.h>

namespace vishnucommon
{
  class CSV
  {

    public:

    template< class T >
    static std::unique_ptr< T > deserialize( const std::string& file )
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

      std::unique_ptr< T > jsonData( new T( ) );
      jsonData->deserialize( qJsonObject );
      return jsonData;
    }

    template< class T >
    static bool serialize( const std::string& file,
      std::unique_ptr< T >& jsonData )
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

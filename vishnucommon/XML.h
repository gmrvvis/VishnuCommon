/* 
 * Copyright (c) 2018-2019 GMRV/URJC.
 * 
 * Authors: Gonzalo Bayo Martinez <gonzalo.bayo@urjc.es>
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

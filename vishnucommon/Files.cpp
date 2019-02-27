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

#include "Files.h"

#include <QString>
#include <QVariant>
#include <QTextStream>
#include <QXmlStreamWriter>

#include <iostream>
#include <fstream>

#include "Strings.hpp"

namespace vishnucommon
{

  bool Files::exist( const std::string& name )
  {
    std::ifstream f( name.c_str( ) );
    return f.good( );
  }

  bool Files::remove( const std::string& name )
  {
    return ( std::remove( name.c_str( ) ) ) == 0 ? true : false ;
  }

  Matrix Files::readCsv( const std::string& file )
  {
    QFile qFile( QString::fromStdString( file ) );
    Matrix matrix;

    if ( !qFile.open( QIODevice::ReadOnly ) )
    {
      Error::throwError( Error::ErrorType::Warning, 
        qFile.errorString( ).toStdString( ) );
      return matrix;
    }

    while ( !qFile.atEnd( ) )
    {
      QByteArray line = qFile.readLine( );
      matrix.emplace_back( Strings::split( line.toStdString( ), ',' ) );
    }

    qFile.close( );

    return matrix;
  }

  std::string Files::readRawCsv( const std::string& file )
  {
    std::string rawCsv;
    QFile qFile( QString::fromStdString( file ) );
    if ( !qFile.open( QIODevice::ReadOnly ) )
    {
      Error::throwError( Error::ErrorType::Warning,
        qFile.errorString( ).toStdString( ) );
      return rawCsv;
    }
    rawCsv = qFile.readAll( ).toStdString( );
    qFile.close( );
    return rawCsv;
  }

  std::vector< std::string > Files::readCsvHeaders( const std::string& file )
  {
    QFile qFile( QString::fromStdString( file ) );
    std::vector< std::string > headers;
    if ( !qFile.open( QIODevice::ReadOnly ) )
    {
      Error::throwError( Error::ErrorType::Warning,
        qFile.errorString( ).toStdString( ) );
      return headers;
    }
    QByteArray line = qFile.readLine( );
    headers = Strings::splitAndTrim( line.toStdString( ), ',' );
    qFile.close( );
    return headers;
  }

  bool Files::writeCsv( const std::string& file, const std::string& content,
    const bool& append )
  {
    bool result = false;

    QFile qFile( QString::fromStdString( file ) );
    QIODevice::OpenMode flags = QFile::WriteOnly | QFile::Truncate;
    if ( append )
    {
      flags |= QIODevice::Append;
    }
    if ( qFile.open( flags ) )
    {
      QTextStream stream( &qFile );
      stream << QString::fromStdString( content );
      qFile.close( );
      result = true;
    }

    return result;
  }

  bool Files::writeLine( const std::string& file, const std::string& content,
    const bool& append )
  {
    return writeCsv( file, content + "\n", append );
  }

}

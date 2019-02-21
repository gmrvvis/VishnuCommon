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

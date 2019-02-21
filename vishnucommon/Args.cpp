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

#include "Args.h"

#include <QStringList>
#include <QJsonArray>

namespace vishnucommon
{
  Args::Args( )
  {

  }

  Args::Args(int argc, char* argv[])
  {
    _args = splitArgs( argc, argv );
  }

  Args::Args( const ArgsMap& args )
  {
    _args = args;
  }

  bool Args::has( const std::string& type ) const
  {
    return _args.find( type ) != _args.end( );
  }

  std::string Args::get( const std::string& type ) const
  {
    auto it = _args.find( type );
    if ( it != _args.end( ) )
    {
      return it->second;
    }
    return std::string( );
  }

  ArgsMap Args::get( ) const
  {
    return _args;
  }
  
  ArgsMap Args::splitArgs( int argc, char *argv[] )
  {
    ArgsMap args;
    int count = 1; //skip program name
    while ( count < argc )
    {
      if ( argv[count][0] == DASH )
      {
        //Type
        if ( count + 1 < argc )
        {
          //Maybe pair arguments
          if ( argv[count + 1][0] == DASH )
          {
            //Single argument
            args[argv[count]] = std::string( );
            count += 1;
          }
          else
          {
            //Pair arguments
            args[argv[count]] = argv[count + 1];
            count += 2;
          }
        }
        else
        {
          //Single argument
          args[argv[count]] = std::string( );
          count += 1;
        }
      }
      else
      {
        //Single argument without dash
        args[argv[count]] = std::string( );
        count += 1;
      }
    }
    return args;
  }

  void Args::deserialize( const QJsonObject &jsonObject )
  {
    QJsonObject args = jsonObject[ "args" ].toObject( );
    for (int i = 0; i < args.size( ); ++i)
    {
      std::string key = args.keys( ).at( i ).toStdString( );
      _args[ key ] =
        args[ QString::fromStdString( key ) ].toString( ).toStdString( );
    }
  }

  void Args::serialize( QJsonObject &jsonObject ) const
  {    
    QJsonObject args;
    for ( const auto& arg : _args )
    {
      args[ QString::fromStdString( arg.first ) ] =
        QString::fromStdString( arg.second );
    }
    jsonObject[ "args" ] = args;
  }

}

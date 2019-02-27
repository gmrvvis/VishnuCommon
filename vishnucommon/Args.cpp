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

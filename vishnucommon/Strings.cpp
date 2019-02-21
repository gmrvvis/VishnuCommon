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

#include "Strings.hpp"

#include <ctime>
#include <random>
#include <algorithm>
#include <functional>

#include <iostream>

namespace vishnucommon
{

  std::vector< std::string > Strings::split( const std::string& str,
    const char& delimiter, const bool& removeEmptyLines )
  {
    std::istringstream stringStream( str );
    std::vector< std::string > splitted;
    std::string s;
    while ( std::getline( stringStream, s, delimiter ) )
    {
      if ( !removeEmptyLines )
      {
        splitted.emplace_back( s );
      }
      else
      {
        if ( !s.empty( ) )
        {
          splitted.emplace_back( s );
        }
      }
    }
    return splitted;
  }

  std::vector< std::string > Strings::splitAndTrim( const std::string& str,
    const char& delimiter )
  {
    std::istringstream stringStream( str );
    std::vector< std::string > splitted;
    std::string s;
    while ( std::getline( stringStream, s, delimiter ) )
    {
      splitted.emplace_back( removeLineBreaks( trim( s ) ) );
    }
    return splitted;
  }

  std::string Strings::join( const std::vector< std::string >& vec,
    const std::string& delimiter, const std::string& toRemove )
  {
    std::string joined;
    for ( const auto& str : vec )
    {
      if ( str != toRemove )
        //if (str.find(toRemove) == std::string::npos) (contains)
      {
        joined += str + delimiter;
      }
    }
    joined = joined.substr( 0, joined.size( ) - 1 );
    return joined;
  }

  std::string Strings::joinAndTrim( const std::vector< std::string >& vec,
    const std::string& delimiter, const std::string& toRemove )
  {
    std::string joined;
    for ( const auto& str : vec )
    {
      if ( str != toRemove )
        //if (str.find(toRemove) == std::string::npos) (contains)
      {
        joined += trim( str ) + delimiter;
      }
    }
    joined = joined.substr( 0, joined.size( ) - 1 );
    return joined;
  }

  char Strings::lower( const char& c )
  {
    return static_cast< char >( std::tolower( 
      static_cast< unsigned char >( c ) ) );
  }

  std::string Strings::lower( const std::string& str )
  {
    std::string result = str;
    std::transform( result.begin( ), result.end( ), result.begin( ), 
      [ ]( unsigned char c ) { return std::tolower( c ); } );
    return result;
  }

  char Strings::upper( const char& c )
  {
    return static_cast< char >( std::toupper(
      static_cast< unsigned char >( c ) ) );
  }

  std::string Strings::upper( const std::string& str )
  {
    std::string result = str;
    std::transform( result.begin( ), result.end( ), result.begin( ),
      [ ]( unsigned char c ) { return std::toupper( c ); } );
    return result;
  }

  std::string Strings::capitalize( const std::string& str )
  {
    if ( str.empty( ) )
    {
      return str;
    }

    std::string result = str;    
    result = lower( result );
    result.at( 0 ) = upper( str.at( 0 ) );
    return result;
  }

  std::string Strings::generateRandom( const int& length )
  {
    srand( static_cast< unsigned int >( time( 0 ) ) );
    auto randchar = [ ]( ) -> char
    {
      const char charset[ ] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
      const size_t max_index = ( sizeof( charset ) - 1 );
      return charset[ rand( ) % max_index ];
    };
    std::string str( length, 0 );
    std::generate_n( str.begin( ), length, randchar );
    return str;
  }

}

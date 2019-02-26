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

#include "Strings.hpp"

#include <ctime>
#include <random>
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
      [ ]( unsigned char c ) { return lower( c ); } );
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
      [ ]( unsigned char c ) { return upper( c ); } );
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

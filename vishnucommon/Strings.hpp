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

#ifndef VISHNUCOMMON_STRINGS_HPP
#define VISHNUCOMMON_STRINGS_HPP

#include <vishnucommon/api.h>

#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>

namespace vishnucommon
{

  class Strings
  {

    public:

    VISHNUCOMMON_API
      static std::vector< std::string > split( const std::string& str,
        const char& delimiter, const bool& removeEmptyLines = false );

    VISHNUCOMMON_API
      static std::vector< std::string > splitAndTrim( const std::string& str,
        const char& delimiter );

    VISHNUCOMMON_API
      static std::string join( const std::vector< std::string >& vec,
        const std::string& delimiter, 
        const std::string& toRemove = std::string( ) );

    VISHNUCOMMON_API
      static std::string joinAndTrim( const std::vector< std::string >& vec,
        const std::string& delimiter,
        const std::string& toRemove = std::string( ) );

    VISHNUCOMMON_API
      static char lower( const char& c );

    VISHNUCOMMON_API
      static std::string lower( const std::string& str );

    VISHNUCOMMON_API
      static char upper( const char& c );

    VISHNUCOMMON_API
      static std::string upper( const std::string& str );

    VISHNUCOMMON_API
      static std::string capitalize( const std::string& str );

    VISHNUCOMMON_API
      static std::string generateRandom( const int& length );

    VISHNUCOMMON_API
      static inline std::string trim( std::string s )
      {
        s.erase( s.begin(), std::find_if( s.begin( ), s.end( ), [ ]( int ch )
        {
          return !std::isspace( ch );
        }));
        s.erase( std::find_if( s.rbegin( ), s.rend( ), [ ]( int ch )
        {
          return !std::isspace( ch );
        }).base( ), s.end( ) );
        return s;
      }

    VISHNUCOMMON_API
      static inline std::string removeLineBreaks( std::string str )
      {
        std::string::size_type pos = 0;
        while( ( pos = str.find ("\r\n", pos) ) != std::string::npos )
        {
          str.erase( pos, 2 );
        }
        return str;
      }

    template< typename T >
      static std::string to_string( const T& t )
    {
      std::stringstream s;
      s << t;
      return s.str( );
    }

  };
}

#endif
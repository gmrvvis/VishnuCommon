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

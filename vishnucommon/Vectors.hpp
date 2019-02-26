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

#ifndef VISHNUCOMMON_VECTORS_HPP
#define VISHNUCOMMON_VECTORS_HPP

#include <vishnucommon/api.h>

#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>

#include <iostream>

namespace vishnucommon
{
  class Vectors
  {

    public:

      template< class T >
      static std::vector< T > intersect( std::vector< T >& v1,
        std::vector< T >& v2 )
      {
        std::vector< T > v;

        std::sort( v1.begin(), v1.end( ) );
        std::sort( v2.begin(), v2.end( ) );

        std::set_intersection( v1.begin( ), v1.end( ), v2.begin( ), v2.end( ),
          std::back_inserter( v ) );

        return v;
      }

      template< class T >
      static int find( const std::vector< T >& v, const T& e )
      {
        auto itr = std::find( v.begin( ), v.end( ), e );
        if ( itr != v.end( ) )
        {
          return std::distance( v.begin( ), itr );
        }
        return -1;
      }

      template< class T >
      static bool remove( std::vector< T >& v, const T& e )
      {
        auto itr = std::find( v.begin( ), v.end( ), e );
        if ( itr != v.end( ) )
        {
          v.erase( itr );
          return true;
        }
        return false;
      }

  };
}

#endif

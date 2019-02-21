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

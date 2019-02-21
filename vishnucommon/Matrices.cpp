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

#include "Matrices.h"

#include <algorithm>

namespace vishnucommon
{

  Matrix Matrices::removeRow( Matrix& matrix, unsigned int rowIndex )
  {
    matrix.erase( matrix.begin( ) + rowIndex );
    return matrix;
  }

  Matrix Matrices::removeColumn( Matrix& matrix, unsigned int colIndex )
  {
    /*std::for_each( matrix.begin( ), matrix.end( ),
      [ & ]( std::vector< std::string >& row )
      {
        row.erase( std::next( row.begin( ), colIndex ) );
      }
    );*/
    for ( auto& row : matrix )
    {
      row.erase( std::next( row.begin( ), colIndex ) );
    }
    return matrix;
  }

}

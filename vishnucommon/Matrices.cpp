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

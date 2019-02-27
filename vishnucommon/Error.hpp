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

#ifndef VISHNUCOMMON_ERROR_HPP
#define VISHNUCOMMON_ERROR_HPP

#include <cassert>
#include <iostream>
#include <string>
#include <stdexcept>

namespace vishnucommon
{

  class Error
  {

    public:
     
    enum class ErrorType
    {
      Info,
      Warning,
      Error
    };

    inline static void throwError( const ErrorType& type, 
      const std::string& str, const bool& close = false )
    {
      switch ( type )
      {
        case ErrorType::Info:
          std::cout << "INFO: " << str << std::endl;
          break;
        case ErrorType::Warning:
          std::cerr << "WARNING: " << str << std::endl;
          break;
        case ErrorType::Error:
          std::cerr << "ERROR: " << str << std::endl;
          throw std::runtime_error( str );
          break;
      }
      if ( close )
      {
        exit( -1 );
      }

    }

  };

}

#endif

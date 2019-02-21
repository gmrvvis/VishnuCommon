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

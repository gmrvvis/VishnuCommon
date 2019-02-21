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

#ifndef VISHNUCOMMON_DEFINITIONS_HPP
#define VISHNUCOMMON_DEFINITIONS_HPP

namespace vishnucommon
{
  #define LIBRARY_NAME "Vishnu Common"

  #define DASH '-'

  #if defined(_WIN32) || defined(WIN32)
    #define SUPERUSER "powershell -Command \"Start-Process cmd -Verb -RunAs\""
  #else
    #define SUPERUSER "gksudo"
  #endif


  #define STR_CLINT "CLINT"
  #define STR_DCEXPLORER "DCEXPLORER"
  #define STR_PYRAMIDAL "PYRAMIDAL"

  #define STR_undefined "undefined"
  #define STR_categorical "categorical"
  #define STR_ordinal "ordinal"
  #define STR_quantitative "quantitative"
  #define STR_geometric "geometric"

  #define STR_none "none"
  #define STR_vec2 "vec2"
  #define STR_vec3 "vec3"
  #define STR_vec4 "vec4"
  #define STR_mat2 "mat2"
  #define STR_mat3 "mat3"
  #define STR_mat4 "mat4"

  #define STR_EMPTY ""
  #define STR_X "X"
  #define STR_Y "Y"
  #define STR_Z "Z"
  #define STR_XYZ "XYZ"

}

#endif

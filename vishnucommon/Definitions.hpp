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

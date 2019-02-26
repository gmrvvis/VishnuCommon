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

#ifndef VISHNUCOMMON_ENUMS_HPP
#define VISHNUCOMMON_ENUMS_HPP

#include <vishnucommon/api.h>
#include "Definitions.hpp"
#include "Strings.hpp"

#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

namespace vishnucommon
{

  enum class ApplicationType
  {
    CLINT,
    DCEXPLORER,
    PYRAMIDAL
  };

  inline static ApplicationType toApplicationType( const std::string& appType )
  {
    std::string upperAppType = vishnucommon::Strings::upper( appType );
    if ( upperAppType == STR_CLINT )
    {
      return ApplicationType::CLINT;
    }
    else if ( upperAppType == STR_DCEXPLORER )
    {
      return ApplicationType::DCEXPLORER;
    }
    else if ( upperAppType == STR_PYRAMIDAL )
    {
      return ApplicationType::PYRAMIDAL;
    }
    else
    {
      assert( 0 && "Error: Invalid ApplicationType enum constant!" );
      exit( -1 );
    }
  }

  inline static std::string toString( const ApplicationType& appType )
  {
    std::string result;
    switch( appType )
    {
      case ApplicationType::CLINT:
        result = STR_CLINT;
        break;
      case ApplicationType::DCEXPLORER:
        result = STR_DCEXPLORER;
        break;
      case ApplicationType::PYRAMIDAL:
        result = STR_PYRAMIDAL;
        break;
    }
    return result;
  }

  enum class DataCategory
  {    
    Undefined,
    Categorical,
    Ordinal,
    Quantitative,
    Geometric
  };

  inline static DataCategory toDataCategory( const std::string& dataCategory )
  {
    std::string lowerDataCategory = vishnucommon::Strings::lower( dataCategory );
    if ( lowerDataCategory == STR_categorical )
    {
      return DataCategory::Categorical;
    }
    else if ( lowerDataCategory == STR_ordinal )
    {
      return DataCategory::Ordinal;
    }
    else if ( lowerDataCategory == STR_quantitative )
    {
      return DataCategory::Quantitative;
    }
    else if ( lowerDataCategory == STR_geometric )
    {
      return DataCategory::Geometric;
    }
    else
    {
      return DataCategory::Undefined;
    }
  }

  inline static std::string toString( const DataCategory& dataCategory )
  {
    std::string result;
    switch ( dataCategory )
    {
    case DataCategory::Undefined:
      result = STR_undefined;
      break;
    case DataCategory::Categorical:
      result = STR_categorical;
      break;
    case DataCategory::Ordinal:
      result = STR_ordinal;
      break;
    case DataCategory::Quantitative:
      result = STR_quantitative;
      break;
    case DataCategory::Geometric:
      result = STR_geometric;
      break;
    }
    return result;
  }

  inline static std::vector<std::string> dataCategoriesToVector( )
  {
    /*std::vector< std::string > vector;
    vector.emplace_back( toString( DataCategory::Undefined ) );
    vector.emplace_back( toString( DataCategory::Categorical ) );
    vector.emplace_back( toString( DataCategory::Ordinal ) );
    vector.emplace_back( toString( DataCategory::Quantitative ) );
    vector.emplace_back( toString( DataCategory::Geometric ) );
    return vector;*/
    return
    {
      toString( DataCategory::Undefined ),
      toString( DataCategory::Categorical ),
      toString( DataCategory::Ordinal ),
      toString( DataCategory::Quantitative ),
      toString( DataCategory::Geometric )
    };
  }

  enum class DataStructureType
  {
    None,
    Vec2,
    Vec3,
    Vec4,
    Mat2,
    Mat3,
    Mat4
  };

  inline static DataStructureType toDataStructureType(
    const std::string& dataStructureType )
  {
    std::string lowerStructureType = vishnucommon::Strings::lower(
      dataStructureType );
    if ( lowerStructureType == STR_vec2 )
    {
      return DataStructureType::Vec2;
    }
    else if ( lowerStructureType == STR_vec3 )
    {
      return DataStructureType::Vec3;
    }
    else if ( lowerStructureType == STR_vec4 )
    {
      return DataStructureType::Vec4;
    }
    else if ( lowerStructureType == STR_mat2 )
    {
      return DataStructureType::Mat2;
    }
    else if ( lowerStructureType == STR_mat3 )
    {
      return DataStructureType::Mat3;
    }
    else if ( lowerStructureType == STR_mat4 )
    {
      return DataStructureType::Mat4;
    }
    else
    {
      return DataStructureType::None;
    }
  }

  inline static std::string toString(
    const DataStructureType& dataStructureType )
  {
    std::string result;
    switch ( dataStructureType )
    {
    case DataStructureType::None:
      result = STR_none;
      break;
    case DataStructureType::Vec2:
      result = STR_vec2;
      break;
    case DataStructureType::Vec3:
      result = STR_vec3;
      break;
    case DataStructureType::Vec4:
      result = STR_vec4;
      break;
    case DataStructureType::Mat2:
      result = STR_mat2;
      break;
    case DataStructureType::Mat3:
      result = STR_mat3;
      break;
    case DataStructureType::Mat4:
      result = STR_mat4;
      break;
    }
    return result;
  }

  enum class AxisType
  {
    None,
    X,
    Y,
    Z,
    XYZ
  };

  inline static AxisType toAxisType( const std::string& axisType )
  {
    std::string upperAxisType = vishnucommon::Strings::upper( axisType );
    if ( upperAxisType == STR_EMPTY )
    {
      return AxisType::None;
    }
    else if ( upperAxisType == STR_X )
    {
      return AxisType::X;
    }
    else if ( upperAxisType == STR_Y )
    {
      return AxisType::Y;
    }
    else if ( upperAxisType == STR_Z )
    {
      return AxisType::Z;
    }
    else if ( upperAxisType == STR_XYZ )
    {
      return AxisType::XYZ;
    }
    else
    {
      assert( 0 && "Error: Invalid AxisType enum constant!" );
      exit( -1 );
    }
  }

  inline static std::string toString( const AxisType& axisType )
  {
    std::string result;
    switch ( axisType )
    {
      case AxisType::None:
        result = STR_EMPTY;
        break;
      case AxisType::X:
        result = STR_X;
        break;
      case AxisType::Y:
        result = STR_Y;
        break;
      case AxisType::Z:
        result = STR_Z;
        break;
      case AxisType::XYZ:
        result = STR_XYZ;
        break;
    }
    return result;
  }

  inline static std::vector< std::string > axisTypesToVector(
    std::vector< AxisType > exclude = std::vector< AxisType >( ) )
  {
    std::vector< std::string > vector;
    vector.emplace_back( toString( AxisType::None ) );
    if ( std::find( exclude.begin( ), exclude.end( ), AxisType::X )
      == exclude.end( ) )
    {
      vector.emplace_back( toString( AxisType::X ) );
    }
    if ( std::find( exclude.begin( ), exclude.end( ), AxisType::Y )
      == exclude.end( ) )
    {
      vector.emplace_back( toString( AxisType::Y ) );
    }
    if ( std::find( exclude.begin( ), exclude.end( ), AxisType::Z )
      == exclude.end( ) )
    {
      vector.emplace_back( toString( AxisType::Z ) );
    }
    if ( std::find( exclude.begin( ), exclude.end( ), AxisType::XYZ )
      == exclude.end( ) )
    {
      vector.emplace_back( toString( AxisType::XYZ ) );
    }
    return vector;
  }
}

#endif

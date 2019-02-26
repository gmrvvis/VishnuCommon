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

#ifndef VISHNUCOMMON_XML_FEATURE_H
#define VISHNUCOMMON_XML_FEATURE_H

#include <QXmlStreamWriter>

#include <string>
#include <memory>

#include "../Enums.hpp"

#include <vishnucommon/api.h>

namespace vishnucommon
{

  class VISHNUCOMMON_API Feature;
  typedef std::shared_ptr< Feature > FeaturePtr;
  typedef std::vector< FeaturePtr > FeaturesVector;

  class VISHNUCOMMON_API Feature
  {
    public:
      Feature( void );
      Feature( const std::string& sourceColumn,
        const std::string& applicationLabel, const std::string& unitsLabel,
        const DataCategory& dataCategory,
        const DataStructureType& dataStructureType );
      ~Feature( void );

      std::string getSourceColumn( void ) const;
      void setSourceColumn( const std::string& sourceColumn );

      std::string getApplicationLabel( void ) const;
      void setApplicationLabel( const std::string& applicationLabel );

      std::string getUnitsLabel( void ) const;
      void setUnitsLabel( const std::string& unitsLabel );

      DataCategory getDataCategory( void ) const;
      void setDataCategory( const DataCategory& dataCategory );

      DataStructureType getDataStructureType( void ) const;
      void setDataStructureType( const DataStructureType& dataStructureType );

      void serialize( QXmlStreamWriter& streamWriter ) const;

    private:

      std::string _sourceColumn;
      std::string _applicationLabel;
      std::string _unitsLabel;
      DataCategory _dataCategory;
      DataStructureType _dataStructureType;

  };
}

#endif

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

#ifndef VISHNUCOMMON_XML_FEATURES_H
#define VISHNUCOMMON_XML_FEATURES_H

#include <QXmlStreamWriter>

#include <string>
#include <vector>
#include <memory>

#include "Feature.h"

#include <vishnucommon/api.h>

namespace vishnucommon
{

  class VISHNUCOMMON_API Features;
  typedef std::shared_ptr< Features > FeaturesPtr;

  class VISHNUCOMMON_API Features
  {
    public:
      Features( void );
      Features( const std::vector< std::string >& idColumns,
        const std::vector< std::string >& positionsXYZColumn,
        const std::string& geometryColumn, const FeaturesVector& features );
      ~Features( void );

      std::vector< std::string > getIdColumns( void ) const;
      void setIdColumns( const std::vector< std::string >& idColumns );

      std::vector< std::string > getPositionsXYZColumn( void ) const;
      void setPositionsXYZColumn(
        const std::vector< std::string >& positionsXYZColumn );

      std::string getGeometryColumn( void ) const;
      void setGeometryColumn( const std::string& geometryColumn );

      FeaturesVector getFeatures( void ) const;
      void setFeatures( const FeaturesVector& features );

      void serialize( QXmlStreamWriter& streamWriter ) const;

    private:
      std::vector< std::string > _idColumns;
      std::vector< std::string > _positionsXYZColumn;
      std::string _geometryColumn;
      FeaturesVector _features;
  };

}

#endif

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

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

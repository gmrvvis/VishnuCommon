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

#ifndef VISHNUCOMMON_PROPERTY_H
#define VISHNUCOMMON_PROPERTY_H

#include <QJsonObject>

#include <string>
#include <vector>
#include <memory>

#include "../Enums.hpp"

#include <vishnucommon/api.h>

namespace vishnucommon
{
  class VISHNUCOMMON_API Property;
  typedef std::shared_ptr< Property > PropertyPtr;
  typedef std::vector< PropertyPtr > Properties;

  class VISHNUCOMMON_API Property
  {

    public:
      Property( );
      Property( const std::string& name, const DataCategory& dataCategory,
        const DataStructureType& dataStructureType );
      ~Property( void );

      std::string getName( void ) const;
      void setName( const std::string& name );

      DataCategory getDataCategory( void ) const;
      void setDataCategory( const DataCategory& dataCategory );

      DataStructureType getDataStructureType( void ) const;
      void setDataStructureType( const DataStructureType& dataStructureType );

      void deserialize( const QJsonObject &jsonObject );
      void serialize( QJsonObject &jsonObject ) const;

    private:
      std::string _name;
      DataCategory _dataCategory;
      DataStructureType _dataStructureType;
  };

}

#endif

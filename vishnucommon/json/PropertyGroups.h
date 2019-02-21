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

#ifndef VISHNUCOMMON_PROPERTYGROUPS_H
#define VISHNUCOMMON_PROPERTYGROUPS_H

#include <QJsonObject>

#include <string>
#include <vector>
#include <memory>

#include <vishnucommon/api.h>

namespace vishnucommon
{
  class VISHNUCOMMON_API PropertyGroups;
  typedef std::shared_ptr< PropertyGroups > PropertyGroupsPtr;

  class VISHNUCOMMON_API PropertyGroups
  {

    public:
      PropertyGroups( );
      PropertyGroups( const std::vector< std::string >& usedPrimaryKeys,
        const std::vector< std::string >& usedNonPrimaryKeys,
        const std::string& xAxis, const std::string& yAxis,
        const std::string& zAxis );
      PropertyGroups( const std::vector< std::string >& usedPrimaryKeys,
        const std::vector< std::string >& usedNonPrimaryKeys,
        const std::string& axes );
      ~PropertyGroups( void );

      std::vector< std::string > getUsedPrimaryKeys( void ) const;
      void setUsedPrimaryKeys(
        const std::vector< std::string >& usedPrimaryKeys );
      void addUsedPrimaryKey( const std::string& usedPrimaryKey );

      std::vector< std::string > getUsedNonPrimaryKeys( void ) const;
      void setUsedNonPrimaryKeys(
        const std::vector< std::string >& nonPrimaryKeys );
      void addUsedNonPrimaryKey( const std::string& nonPrimaryKey );

      std::vector< std::string > getAxes( void ) const;
      void setAxes( const std::string& xAxis, const std::string& yAxis,
        const std::string& zAxis );
      void setAxes( const std::string& axes );

      std::vector< std::string > getHeaders( void ) const;

      void deserialize( const QJsonObject &jsonObject );
      void serialize( QJsonObject &jsonObject ) const;

    private:
      std::vector< std::string > _usedPrimaryKeys;
      std::vector< std::string > _usedNonPrimaryKeys;
      std::vector< std::string > _axes;

  };

}

#endif

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

#ifndef VISHNUCOMMON_DATASETS_H
#define VISHNUCOMMON_DATASETS_H

#include <QJsonObject>

#include <string>
#include <vector>
#include <memory>

#include "DataSet.h"
#include "PropertyGroups.h"

#include <vishnucommon/api.h>

namespace vishnucommon
{
  class VISHNUCOMMON_API DataSets;
  typedef std::shared_ptr< DataSets > DataSetsPtr;

  class VISHNUCOMMON_API DataSets
  {

    public:
      DataSets( void );
      DataSets( const DataSetVector& dataSets );
      ~DataSets( void );

      DataSetVector getDataSets( ) const;
      void setDataSets( const DataSetVector& dataSets );
      void addDataSet( const DataSetPtr& dataSet );

      PropertyGroupsPtr getPropertyGroups( void ) const;
      void setPropertyGroups( const PropertyGroupsPtr& propertyGroups );

      MetadataPtr getMetadata( void ) const;
      void setMetadata( const MetadataPtr& metaData );

      void deserialize( const QJsonObject& jsonObject );
      void serialize( QJsonObject& jsonObject ) const;

    private:
      DataSetVector _dataSets;
      PropertyGroupsPtr _propertyGroups;
      MetadataPtr _metadata;

  };

}

#endif

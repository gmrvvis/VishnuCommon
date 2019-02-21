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

#ifndef VISHNUCOMMON_DATASET_H
#define VISHNUCOMMON_DATASET_H

#include <QJsonObject>

#include <string>
#include <vector>
#include <memory>

#include "Property.h"
#include "Metadata.h"

#include <vishnucommon/api.h>

namespace vishnucommon
{
  class VISHNUCOMMON_API DataSet;
  typedef std::shared_ptr< DataSet > DataSetPtr;
  typedef std::vector< DataSetPtr > DataSetVector;

  class VISHNUCOMMON_API DataSet
  {

    public:
      DataSet( void );
      DataSet( const std::string& path );
      DataSet( const std::string& path, const Properties& dataSetProperties,
        const MetadataPtr& metadata );
      ~DataSet( void );

      std::string getPath( void ) const;
      void setPath( const std::string& path );

      Properties getProperties( void ) const;
      void setProperties( const Properties& properties );
      void addProperty( const PropertyPtr& property );
      std::vector< std::string > getPropertyNames (void ) const;

      MetadataPtr getMetadata( void ) const;
      void setMetadata( const MetadataPtr& metadata );

      void deserialize( const QJsonObject &jsonObject );
      void serialize( QJsonObject &jsonObject ) const;

    private:
      std::string _path;
      Properties _properties;
      MetadataPtr _metadata;
  };

}

#endif

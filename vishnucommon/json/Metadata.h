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

#ifndef VISHNUCOMMON_METADATA_H
#define VISHNUCOMMON_METADATA_H

#include <QJsonObject>

#include <string>
#include <map>
#include <memory>

#include <vishnucommon/api.h>

namespace vishnucommon
{
  class VISHNUCOMMON_API Metadata;
  typedef std::shared_ptr< Metadata > MetadataPtr;
  typedef std::map< std::string, std::string > MetadataMap;

  class VISHNUCOMMON_API Metadata
  {

    public:
      Metadata( );
      Metadata( const MetadataMap& metadata );
      ~Metadata( void );

      MetadataMap getMetadata( void ) const;
      void setMetadata( const MetadataMap& metadata );

      std::string getMetadata( const std::string& key ) const;
      void setMetadata( const std::string& key, const std::string& value );

      void deserialize( const QJsonObject &jsonObject );
      void serialize( QJsonObject &jsonObject ) const;

    private:
      MetadataMap _metadata;
  };

}

#endif

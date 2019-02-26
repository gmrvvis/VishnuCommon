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

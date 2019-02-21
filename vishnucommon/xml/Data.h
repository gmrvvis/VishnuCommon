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

#ifndef VISHNUCOMMON_XML_DATA_H
#define VISHNUCOMMON_XML_DATA_H

#include <QXmlStreamWriter>

#include <string>
#include <vector>
#include <memory>

#include "Features.h"
#include "Set.h"

#include <vishnucommon/api.h>

namespace vishnucommon
{

  class VISHNUCOMMON_API Data;
  typedef std::shared_ptr< Data > DataPtr;

  class VISHNUCOMMON_API Data
  {
    public:
      Data( void );
      Data( const std::string& objectsLabel,
        const std::string& additionalMeshesLabel, const FeaturesPtr& features,
        const Sets& sets );
      ~Data( void );

      std::string getObjectsLabel( void ) const;
      void setObjectsLabel( const std::string& objectsLabel );

      std::string getAdditionalMeshesLabel( void ) const;
      void setAdditionalMeshesLabel( const std::string& additionalMeshesLabel );

      FeaturesPtr getFeatures( void ) const;
      void setFeatures( const FeaturesPtr& features );

      Sets getSets( void ) const;
      void setSets( const Sets& sets );

      void serialize( QXmlStreamWriter& streamWriter ) const;

    private:
      std::string _objectsLabel;
      std::string _additionalMeshesLabel;
      FeaturesPtr _features;
      Sets _sets;
  };

}

#endif

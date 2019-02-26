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

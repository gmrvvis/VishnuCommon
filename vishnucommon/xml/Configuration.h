/* 
 * Copyright (c) 2018-2019 GMRV/URJC.
 * 
 * Authors: Gonzalo Bayo Martinez <gonzalo.bayo@urjc.es>
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

#ifndef VISHNUCOMMON_XML_CONFIGURATION_H
#define VISHNUCOMMON_XML_CONFIGURATION_H

#include <QXmlStreamWriter>

#include <string>
#include <memory>

#include "Data.h"
#include "Colors.h"
#include "Camera.h"

#include <vishnucommon/api.h>

namespace vishnucommon
{

  class VISHNUCOMMON_API Configuration;
  typedef std::shared_ptr< Configuration > ConfigurationPtr;

  class VISHNUCOMMON_API Configuration
  {
    public:
      Configuration( void );
      Configuration( const std::string& app, const std::string& version,
        const std::string& label, const DataPtr& data, const ColorsPtr& colors,
        const CameraPtr& camera );
      ~Configuration( void );

      std::string getApp( void ) const;
      void setApp( const std::string& app );

      std::string getVersion( void ) const;
      void setVersion( const std::string& version );

      std::string getLabel( void ) const;
      void setLabel( const std::string& label );

      DataPtr getData( void ) const;
      void setData( const DataPtr& data );

      ColorsPtr getColors( void ) const;
      void setColors( const ColorsPtr& colors );

      CameraPtr getCamera( void ) const;
      void setCamera( const CameraPtr& camera );

      void serialize( QXmlStreamWriter& streamWriter ) const;

    private:
      std::string _app;
      std::string _version;
      std::string _label;
      DataPtr _data;
      ColorsPtr _colors;
      CameraPtr _camera;
  };

}

#endif

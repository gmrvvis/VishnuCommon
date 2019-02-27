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

#ifndef VISHNUCOMMON_XML_PYRAMIDALXML_H
#define VISHNUCOMMON_XML_PYRAMIDALXML_H

#include <QXmlStreamWriter>

#include <string>
#include <memory>

#include "Configuration.h"

#include <vishnucommon/api.h>

namespace vishnucommon
{

  class VISHNUCOMMON_API PyramidalXML;
  typedef std::shared_ptr< PyramidalXML > PyramidalXMLPtr;

  class VISHNUCOMMON_API PyramidalXML
  {
    public:
      PyramidalXML( void );
      PyramidalXML( const std::string& dtd,
        const ConfigurationPtr& configuration );
      ~PyramidalXML( void );

      std::string getDTD( void ) const;
      void setDTD( const std::string& dtd );

      ConfigurationPtr getConfiguration( void ) const;
      void setConfiguration( const ConfigurationPtr& configuration );

      void serialize( QXmlStreamWriter& streamWriter ) const;

    private:
      std::string _dtd;
      ConfigurationPtr _configuration;
  };

}

#endif

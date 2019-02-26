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

#ifndef VISHNUCOMMON_XML_SET_H
#define VISHNUCOMMON_XML_SET_H

#include <QXmlStreamWriter>

#include <string>
#include <memory>

#include <vishnucommon/api.h>

namespace vishnucommon
{

  class VISHNUCOMMON_API Set;
  typedef std::shared_ptr< Set > SetPtr;  
  typedef std::vector< SetPtr > Sets;

  class VISHNUCOMMON_API Set
  {
    public:
      Set( void );
      Set( const std::string& objectsFeaturesCSV,
        const std::string& objectsMeshesPath = std::string( ),
        const std::string& additionalMeshesPath = std::string( ) );
      ~Set( void );

      std::string getObjectsFeaturesCSV( void ) const;
      void setObjectsFeaturesCSV( const std::string& objectsFeaturesCSV );

      std::string getObjectsMeshesPath( void ) const;
      void setObjectsMeshesPath( const std::string& objectsMeshesPath );

      std::string getAdditionalMeshesPath( void ) const;
      void setAdditionalMeshesPath( const std::string& additionalMeshesPath );

      void serialize( QXmlStreamWriter& streamWriter ) const;

    private:
      std::string _objectsFeaturesCSV;
      std::string _objectsMeshesPath;
      std::string _additionalMeshesPath;
  };

}

#endif

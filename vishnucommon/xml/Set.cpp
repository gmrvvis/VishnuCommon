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

#include "Set.h"

namespace vishnucommon
{

  Set::Set( void )
  {

  }

  Set::Set( const std::string& objectsFeaturesCSV,
    const std::string& objectsMeshesPath,
    const std::string& additionalMeshesPath )
      : _objectsFeaturesCSV( objectsFeaturesCSV )
      , _objectsMeshesPath( objectsMeshesPath )
      , _additionalMeshesPath( additionalMeshesPath )
  {

  }

  Set::~Set( void )
  {

  }

  std::string Set::getObjectsFeaturesCSV( void ) const
  {
    return _objectsFeaturesCSV;
  }

  void Set::setObjectsFeaturesCSV( const std::string& objectsFeaturesCSV )
  {
    _objectsFeaturesCSV = objectsFeaturesCSV;
  }

  std::string Set::getObjectsMeshesPath( void ) const
  {
    return _objectsMeshesPath;
  }

  void Set::setObjectsMeshesPath( const std::string& objectsMeshesPath )
  {
    _objectsMeshesPath = objectsMeshesPath;
  }

  std::string Set::getAdditionalMeshesPath( void ) const
  {
    return _additionalMeshesPath;
  }

  void Set::setAdditionalMeshesPath( const std::string& additionalMeshesPath )
  {
    _additionalMeshesPath = additionalMeshesPath;
  }

  void Set::serialize( QXmlStreamWriter& streamWriter ) const
  {
    streamWriter.writeStartElement( "set" );
    streamWriter.writeTextElement( "objectsFeaturesCSV",
      QString::fromStdString( _objectsFeaturesCSV ) );
    if ( !_objectsMeshesPath.empty( ) )
    {
      streamWriter.writeTextElement( "objectsMeshesPath",
        QString::fromStdString( _objectsMeshesPath ) );
    }
    if ( !_additionalMeshesPath.empty( ) )
    {
      streamWriter.writeTextElement( "additionalMeshesPath",
        QString::fromStdString( _additionalMeshesPath ) );
    }
    streamWriter.writeEndElement( );
  }

}

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

#include "PyramidalXML.h"

namespace vishnucommon
{
  PyramidalXML::PyramidalXML( void )
  {

  }

  PyramidalXML::PyramidalXML( const std::string& dtd,
    const ConfigurationPtr& configuration )
      : _dtd( dtd )
      , _configuration( configuration )
  {

  }

  PyramidalXML::~PyramidalXML( void )
  {

  }

  std::string PyramidalXML::getDTD( void ) const
  {
    return _dtd;
  }

  void PyramidalXML::setDTD( const std::string& dtd )
  {
    _dtd = dtd;
  }

  ConfigurationPtr PyramidalXML::getConfiguration( void ) const
  {
    return _configuration;
  }

  void PyramidalXML::setConfiguration( const ConfigurationPtr& configuration )
  {
    _configuration = configuration;
  }

  void PyramidalXML::serialize( QXmlStreamWriter& streamWriter ) const
  {
    streamWriter.writeDTD( QString::fromStdString( _dtd ) );
    _configuration->serialize( streamWriter );
  }
}

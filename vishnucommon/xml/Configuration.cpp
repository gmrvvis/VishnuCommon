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

#include "Configuration.h"

namespace vishnucommon
{

  Configuration::Configuration( void )
  {

  }

  Configuration::Configuration( const std::string& app,
    const std::string& version, const std::string& label, const DataPtr& data,
    const ColorsPtr& colors, const CameraPtr& camera )
      : _app( app )
      , _version( version )
      , _label( label )
      , _data( data )
      , _colors( colors )
      , _camera( camera )
  {

  }

  Configuration::~Configuration( void )
  {

  }

  std::string Configuration::getApp( void ) const
  {
    return _app;
  }

  void Configuration::setApp( const std::string& app )
  {
    _app = app;
  }

  std::string Configuration::getVersion( void ) const
  {
    return _version;
  }

  void Configuration::setVersion( const std::string& version )
  {
    _version = version;
  }

  std::string Configuration::getLabel( void ) const
  {
    return _label;
  }

  void Configuration::setLabel( const std::string& label )
  {
    _label = label;
  }

  DataPtr Configuration::getData( void ) const
  {
    return _data;
  }

  void Configuration::setData( const DataPtr& data )
  {
    _data = data;
  }

  ColorsPtr Configuration::getColors( void ) const
  {
    return _colors;
  }

  void Configuration::setColors( const ColorsPtr& colors )
  {
    _colors = colors;
  }

  CameraPtr Configuration::getCamera( void ) const
  {
    return _camera;
  }

  void Configuration::setCamera( const CameraPtr& camera )
  {
    _camera = camera;
  }

  void Configuration::serialize( QXmlStreamWriter& streamWriter ) const
  {
    streamWriter.writeStartElement( "configuration" );
    streamWriter.writeAttribute( "app", QString::fromStdString( _app ) );
    streamWriter.writeAttribute( "version",
      QString::fromStdString( _version ) );
    streamWriter.writeAttribute( "label", QString::fromStdString( _label ) );
    _data->serialize( streamWriter );
    _colors->serialize( streamWriter );
    _camera->serialize( streamWriter );
  }

}

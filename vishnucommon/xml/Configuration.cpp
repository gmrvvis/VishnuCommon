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

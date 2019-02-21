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

#include "Data.h"

namespace vishnucommon
{

  Data::Data( void )
  {

  }

  Data::Data( const std::string& objectsLabel,
    const std::string& additionalMeshesLabel, const FeaturesPtr& features,
    const Sets& sets )
      : _objectsLabel( objectsLabel )
      , _additionalMeshesLabel( additionalMeshesLabel )
      , _features( features )
      , _sets( sets )
  {

  }

  Data::~Data( void )
  {

  }

  std::string Data::getObjectsLabel( void ) const
  {
    return _objectsLabel;
  }

  void Data::setObjectsLabel( const std::string& objectsLabel )
  {
    _objectsLabel = objectsLabel;
  }

  std::string Data::getAdditionalMeshesLabel( void ) const
  {
    return _additionalMeshesLabel;
  }

  void Data::setAdditionalMeshesLabel( const std::string& additionalMeshesLabel )
  {
    _additionalMeshesLabel = additionalMeshesLabel;
  }

  FeaturesPtr Data::getFeatures( void ) const
  {
    return _features;
  }

  void Data::setFeatures( const FeaturesPtr& features )
  {
    _features = features;
  }

  Sets Data::getSets( void ) const
  {
    return _sets;
  }

  void Data::setSets( const Sets& sets )
  {
    _sets = sets;
  }

  void Data::serialize( QXmlStreamWriter& streamWriter ) const
  {
    streamWriter.writeStartElement( "data" );
    streamWriter.writeAttribute( "objectsLabel",
      QString::fromStdString( _objectsLabel ) );
    streamWriter.writeAttribute( "additionalMeshesLabel",
      QString::fromStdString( _additionalMeshesLabel ) );
    _features->serialize( streamWriter );
    for (const auto& set : _sets )
    {
      set->serialize( streamWriter );
    }
    streamWriter.writeEndElement( );
  }

}

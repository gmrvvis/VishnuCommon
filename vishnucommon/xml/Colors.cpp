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

#include "Colors.h"

namespace vishnucommon
{

  Colors::Colors( void )
  {

  }

  Colors::Colors( const Vec3Ptr& additionalMeshesColor,
    const Vec3Ptr& backgroundColor )
      : _additionalMeshesColor( additionalMeshesColor )
      , _backgroundColor( backgroundColor )
  {

  }

  Colors:: ~Colors( void )
  {
  }

  Vec3Ptr Colors::getAdditionalMeshesColor( void ) const
  {
    return _additionalMeshesColor;
  }

  void Colors::setAdditionalMeshesColor( const Vec3Ptr& additionalMeshesColor )
  {
    _additionalMeshesColor = additionalMeshesColor;
  }

  Vec3Ptr Colors::getBackgroundColor( void ) const
  {
    return _backgroundColor;
  }

  void Colors::setBackgroundColor( const Vec3Ptr& backgroundColor )
  {
    _backgroundColor = backgroundColor;
  }

  void Colors::serialize( QXmlStreamWriter& streamWriter ) const
  {
    streamWriter.writeStartElement( "colors" );
    _additionalMeshesColor->serialize( streamWriter, "additionalMeshesColor",
      { "r", "g", "b" } );
    _backgroundColor->serialize( streamWriter, "backgroundColor",
      { "r", "g", "b" } );
    streamWriter.writeEndElement( );
  }

}

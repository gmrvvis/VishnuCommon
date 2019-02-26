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

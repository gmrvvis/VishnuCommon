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

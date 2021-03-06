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

#include "Feature.h"

namespace vishnucommon
{

  Feature::Feature( void )
  {

  }

  Feature::Feature( const std::string& sourceColumn,
    const std::string& applicationLabel, const std::string& unitsLabel,
    const DataCategory& dataCategory, const DataStructureType& dataStructureType )
      : _sourceColumn( sourceColumn )
      , _applicationLabel( applicationLabel )
      , _unitsLabel( unitsLabel )
      , _dataCategory( dataCategory )
      , _dataStructureType( dataStructureType )
  {

  }

  Feature::~Feature( void )
  {

  }

  std::string Feature::getSourceColumn( void ) const
  {
    return _sourceColumn;
  }

  void Feature::setSourceColumn( const std::string& sourceColumn )
  {
    _sourceColumn = sourceColumn;
  }

  std::string Feature::getApplicationLabel( void ) const
  {
    return _applicationLabel;
  }

  void Feature::setApplicationLabel( const std::string& applicationLabel )
  {
    _applicationLabel = applicationLabel;
  }

  std::string Feature::getUnitsLabel( void ) const
  {
    return _unitsLabel;
  }

  void Feature::setUnitsLabel( const std::string& unitsLabel )
  {
    _unitsLabel = unitsLabel;
  }

  DataCategory Feature::getDataCategory( void ) const
  {
    return _dataCategory;
  }

  void Feature::setDataCategory( const DataCategory& dataCategory )
  {
    _dataCategory = dataCategory;
  }

  DataStructureType Feature::getDataStructureType( void ) const
  {
    return _dataStructureType;
  }

  void Feature::setDataStructureType( const DataStructureType& dataStructureType )
  {
    _dataStructureType = dataStructureType;
  }

  void Feature::serialize( QXmlStreamWriter& streamWriter ) const
  {
    streamWriter.writeStartElement( "feature" );
    streamWriter.writeAttribute( "sourceColumn",
      QString::fromStdString( _sourceColumn ) );
    streamWriter.writeAttribute( "applicationLabel",
      QString::fromStdString( _applicationLabel ) );
    streamWriter.writeAttribute( "unitsLabel",
      QString::fromStdString( _unitsLabel ) );
    streamWriter.writeAttribute( "dataCategory",
      QString::fromStdString( toString( _dataCategory ) ) );
    streamWriter.writeAttribute( "dataStructureType",
      QString::fromStdString( toString( _dataStructureType ) ) );
    streamWriter.writeEndElement( );
  }

}

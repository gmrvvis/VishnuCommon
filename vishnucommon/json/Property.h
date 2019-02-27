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

#ifndef VISHNUCOMMON_PROPERTY_H
#define VISHNUCOMMON_PROPERTY_H

#include <QJsonObject>

#include <string>
#include <vector>
#include <memory>

#include "../Enums.hpp"

#include <vishnucommon/api.h>

namespace vishnucommon
{
  class VISHNUCOMMON_API Property;
  typedef std::shared_ptr< Property > PropertyPtr;
  typedef std::vector< PropertyPtr > Properties;

  class VISHNUCOMMON_API Property
  {

    public:
      Property( );
      Property( const std::string& name, const DataCategory& dataCategory,
        const DataStructureType& dataStructureType );
      ~Property( void );

      std::string getName( void ) const;
      void setName( const std::string& name );

      DataCategory getDataCategory( void ) const;
      void setDataCategory( const DataCategory& dataCategory );

      DataStructureType getDataStructureType( void ) const;
      void setDataStructureType( const DataStructureType& dataStructureType );

      void deserialize( const QJsonObject &jsonObject );
      void serialize( QJsonObject &jsonObject ) const;

    private:
      std::string _name;
      DataCategory _dataCategory;
      DataStructureType _dataStructureType;
  };

}

#endif

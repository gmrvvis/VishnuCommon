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

#ifndef VISHNUCOMMON_PROPERTYGROUPS_H
#define VISHNUCOMMON_PROPERTYGROUPS_H

#include <QJsonObject>

#include <string>
#include <vector>
#include <memory>

#include <vishnucommon/api.h>

namespace vishnucommon
{
  class VISHNUCOMMON_API PropertyGroups;
  typedef std::shared_ptr< PropertyGroups > PropertyGroupsPtr;

  class VISHNUCOMMON_API PropertyGroups
  {

    public:
      PropertyGroups( );
      PropertyGroups( const std::vector< std::string >& usedPrimaryKeys,
        const std::vector< std::string >& usedNonPrimaryKeys,
        const std::string& xAxis, const std::string& yAxis,
        const std::string& zAxis );
      PropertyGroups( const std::vector< std::string >& usedPrimaryKeys,
        const std::vector< std::string >& usedNonPrimaryKeys,
        const std::string& axes );
      ~PropertyGroups( void );

      std::vector< std::string > getUsedPrimaryKeys( void ) const;
      void setUsedPrimaryKeys(
        const std::vector< std::string >& usedPrimaryKeys );
      void addUsedPrimaryKey( const std::string& usedPrimaryKey );

      std::vector< std::string > getUsedNonPrimaryKeys( void ) const;
      void setUsedNonPrimaryKeys(
        const std::vector< std::string >& nonPrimaryKeys );
      void addUsedNonPrimaryKey( const std::string& nonPrimaryKey );

      std::vector< std::string > getAxes( void ) const;
      void setAxes( const std::string& xAxis, const std::string& yAxis,
        const std::string& zAxis );
      void setAxes( const std::string& axes );

      std::vector< std::string > getHeaders( void ) const;

      void deserialize( const QJsonObject &jsonObject );
      void serialize( QJsonObject &jsonObject ) const;

    private:
      std::vector< std::string > _usedPrimaryKeys;
      std::vector< std::string > _usedNonPrimaryKeys;
      std::vector< std::string > _axes;

  };

}

#endif

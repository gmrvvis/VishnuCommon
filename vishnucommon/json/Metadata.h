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

#ifndef VISHNUCOMMON_METADATA_H
#define VISHNUCOMMON_METADATA_H

#include <QJsonObject>

#include <string>
#include <map>
#include <memory>

#include <vishnucommon/api.h>

namespace vishnucommon
{
  class VISHNUCOMMON_API Metadata;
  typedef std::shared_ptr< Metadata > MetadataPtr;
  typedef std::map< std::string, std::string > MetadataMap;

  class VISHNUCOMMON_API Metadata
  {

    public:
      Metadata( );
      Metadata( const MetadataMap& metadata );
      ~Metadata( void );

      MetadataMap getMetadata( void ) const;
      void setMetadata( const MetadataMap& metadata );

      std::string getMetadata( const std::string& key ) const;
      void setMetadata( const std::string& key, const std::string& value );

      void deserialize( const QJsonObject &jsonObject );
      void serialize( QJsonObject &jsonObject ) const;

    private:
      MetadataMap _metadata;
  };

}

#endif

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

#ifndef VISHNUCOMMON_XML_VEC3_H
#define VISHNUCOMMON_XML_VEC3_H

#include <QXmlStreamWriter>

#include <string>
#include <array>
#include <memory>

#include <vishnucommon/api.h>

namespace vishnucommon
{

  class VISHNUCOMMON_API Vec3;
  typedef std::shared_ptr< Vec3 > Vec3Ptr;

  class VISHNUCOMMON_API Vec3
  {
    public:
      Vec3( void );
      Vec3( const std::string& x, const std::string& y, const std::string& z);
      ~Vec3( void );

      std::string getX( void ) const;
      void setX( const std::string& x );

      std::string getY( void ) const;
      void setY( const std::string& y );

      std::string getZ( void ) const;
      void setZ( const std::string& z );

      void serialize( QXmlStreamWriter& streamWriter,
        const std::string& elementName,
        const std::vector< std::string >& attributeNames ) const;

    private:
      std::array< std::string, 3 > _xyz;

  };

}

#endif

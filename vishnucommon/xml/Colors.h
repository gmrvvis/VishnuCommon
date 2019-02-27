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

#ifndef VISHNUCOMMON_XML_COLORS_H
#define VISHNUCOMMON_XML_COLORS_H

#include <QXmlStreamWriter>

#include <memory>

#include "Vec3.h"

#include <vishnucommon/api.h>

namespace vishnucommon
{

  class VISHNUCOMMON_API Colors;
  typedef std::shared_ptr< Colors > ColorsPtr;

  class VISHNUCOMMON_API Colors
  {
    public:
      Colors( void );
      Colors( const Vec3Ptr& additionalMeshesColor,
        const Vec3Ptr& backgroundColor );
      ~Colors( void );

      Vec3Ptr getAdditionalMeshesColor( void ) const;
      void setAdditionalMeshesColor( const Vec3Ptr& additionalMeshesColor );

      Vec3Ptr getBackgroundColor( void ) const;
      void setBackgroundColor( const Vec3Ptr& backgroundColor );

      void serialize( QXmlStreamWriter& streamWriter ) const;

    private:
      Vec3Ptr _additionalMeshesColor;
      Vec3Ptr _backgroundColor;

  };
}

#endif

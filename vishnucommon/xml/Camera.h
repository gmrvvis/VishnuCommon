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

#ifndef VISHNUCOMMON_XML_CAMERA_H
#define VISHNUCOMMON_XML_CAMERA_H

#include <QXmlStreamWriter>

#include <memory>

#include "Vec3.h"

#include <vishnucommon/api.h>

namespace vishnucommon
{

  class VISHNUCOMMON_API Camera;
  typedef std::shared_ptr< Camera > CameraPtr;

  class VISHNUCOMMON_API Camera
  {
    public:
      Camera( void );
      Camera( const Vec3Ptr& eye, const Vec3Ptr& center, const Vec3Ptr& up );
      ~Camera( void );

      Vec3Ptr getEye( void ) const;
      void setEye( const Vec3Ptr& eye );

      Vec3Ptr getCenter( void ) const;
      void setCenter( const Vec3Ptr& center );

      Vec3Ptr getUp( void ) const;
      void setUp( const Vec3Ptr& up );

      void serialize( QXmlStreamWriter& streamWriter ) const;

    private:
      Vec3Ptr _eye;
      Vec3Ptr _center;
      Vec3Ptr _up;

  };
}

#endif

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

#ifndef VISHNUCOMMON_ARGS_H
#define VISHNUCOMMON_ARGS_H

#include <QJsonObject>

#include <string>
#include <map>

#include "Definitions.hpp"
#include "Strings.hpp"

#include <vishnucommon/api.h>

namespace vishnucommon
{

  typedef std::map< std::string, std::string > ArgsMap;

  class Args
  {

    public:

      VISHNUCOMMON_API
        explicit Args( );

      VISHNUCOMMON_API
        explicit Args( int argc, char* argv[ ] );

      VISHNUCOMMON_API
        explicit Args( const ArgsMap& args );

      VISHNUCOMMON_API
        bool has( const std::string& type ) const;

      VISHNUCOMMON_API
        std::string get( const std::string& type ) const;

      VISHNUCOMMON_API
        ArgsMap get( ) const;

      template< typename T = std::string >
      void set( const std::string& type, const T& value = std::string( ) )
      {
        _args[ type ] = Strings::to_string( value );
      }

      VISHNUCOMMON_API
        void deserialize( const QJsonObject &jsonObject );

      VISHNUCOMMON_API
        void serialize( QJsonObject &jsonObject ) const;

    private:

      ArgsMap _args;

      ArgsMap splitArgs( int argc, char *argv[ ] );

  };

}

#endif

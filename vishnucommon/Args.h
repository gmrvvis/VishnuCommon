/*
 * Copyright (c) 2018-2019 GMRV/URJC.
 *
 * Authors: Gonzalo Bayo Martinez <gonzalo.bayo@urjc.es>
 *
 * This file is part of VishnuCommon <https://gitlab.gmrv.es/cbbsp1/vishnucommon>
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License version 3.0 as published
 * by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
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

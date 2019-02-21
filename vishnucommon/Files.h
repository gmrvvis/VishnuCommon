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

#ifndef VISHNUCOMMON_FILES_H
#define VISHNUCOMMON_FILES_H

#include <memory>

#include <QString>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QTextStream>

#include "Error.hpp"
#include "Strings.hpp"
#include "Matrices.h"
#include <vishnucommon/api.h>

namespace vishnucommon
{

  class Files
  {
    
    public:

    VISHNUCOMMON_API
      static bool exist( const std::string& name );

    VISHNUCOMMON_API
      static bool remove( const std::string& name );

    VISHNUCOMMON_API
      static Matrix readCsv( const std::string& file );

    VISHNUCOMMON_API
      static std::string readRawCsv( const std::string& file );

    VISHNUCOMMON_API
      static std::vector< std::string > readCsvHeaders(
        const std::string& file );

    VISHNUCOMMON_API
      static bool writeCsv( const std::string& file, const std::string& content,
        const bool& append = false );

    VISHNUCOMMON_API
      static bool writeLine( const std::string& file, const std::string& content,
        const bool& append = false );

  };

}

#endif

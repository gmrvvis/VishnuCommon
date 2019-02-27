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

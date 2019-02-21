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

#include <vishnucommon/vishnucommon.h>
using namespace vishnucommon;

#include "Auxiliar.hpp"

int main( int /*argc*/, char** /*argv[]*/ )
{
  DataSetsPtr dataSets = Auxiliar::createDataSets( );

  //Serialize json data into file
  JSON::serialize( "./test.json", dataSets );

  //Deserialize json data from file
  DataSetsPtr deserializedJson = JSON::deserialize< DataSets >(
    "./test.json" );

  return 0;
}

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

#include <iostream>
#include <string>

int main( int argc, char* argv[] )
{

  //Parsing args
  Args args( argc, argv );

  /*
  Argument types (in priority order):
  1. -type value, e.g. -z hbp:://, or -f FILE_PATH
  2. -type (without value), e.g. -z, or --standalone
  3. value, e.g. SOME_VALUE1
  */

  //Boolean result to know if exist param -z (or -z value)
  if( args.has( "-z" ) )
  {
    std::cout << "exist" << std::endl;
  }

  //To get value of -z param
  //Returns an empty string if param has not value or doesn't exist
  std::string value = args.get( "-z" );
  if ( !value.empty( ) )
  {
    std::cout << value << std::endl;
  }

  //To set a param (normally not used)
  args.set( "-z", "hbp://" );
  args.set( "-somevalue", 124.4 );
  args.set( "--standalone" );
  args.set( "somevalue123" );

  return 0;
}

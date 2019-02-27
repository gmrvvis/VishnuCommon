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

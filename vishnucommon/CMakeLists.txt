# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#
#   Vishnu Common
#   2018-2019 (c) GMRV/URJC
#   Authors: Gonzalo Bayo Martinez <gonzalo.bayo@urjc.es>
#   http://gmrv.es/gmrvvis/
#
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

source_group( \\ FILES CMakeLists.txt )
  
set( VISHNUCOMMON_PUBLIC_HEADERS
  Definitions.hpp
  Enums.hpp
  Args.h
  Strings.hpp
  Vectors.hpp
  Files.h
  JSON.h
  XML.h
  CSV.h
  Maths.hpp
  Matrices.h
  Error.hpp
  Debug.hpp
  customobjects/ClickableLabel.h
  json/DataSets.h
  json/DataSet.h
  json/Property.h
  json/Metadata.h
  json/PropertyGroups.h
  xml/Camera.h
  xml/Colors.h
  xml/Configuration.h
  xml/Data.h
  xml/Feature.h
  xml/Features.h
  xml/Set.h
  xml/Vec3.h
  xml/PyramidalXML.h
)

set( VISHNUCOMMON_HEADERS

)
  
set( VISHNUCOMMON_SOURCES
  Args.cpp
  Strings.cpp
  Files.cpp
  Matrices.cpp
  customobjects/ClickableLabel.cpp
  json/DataSets.cpp
  json/DataSet.cpp
  json/Property.cpp
  json/Metadata.cpp
  json/PropertyGroups.cpp
  xml/Camera.cpp
  xml/Colors.cpp
  xml/Configuration.cpp
  xml/Data.cpp
  xml/Feature.cpp
  xml/Features.cpp
  xml/Set.cpp
  xml/Vec3.cpp
  xml/PyramidalXML.cpp
)

set( VISHNUCOMMON_LINK_LIBRARIES
  Qt5::Core
  Qt5::Gui
  Qt5::Widgets
)

if ( MSVC )
  add_definitions("/W4")
endif( )

common_library( vishnucommon )


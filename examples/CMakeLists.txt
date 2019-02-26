# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#
#   Vishnu Common
#   2018-2019 (c) GMRV/URJC
#   Authors: Gonzalo Bayo Martinez <gonzalo.bayo@urjc.es>
#   http://gmrv.es/gmrvvis/
#
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

include_directories(
  ${PROJECT_BINARY_DIR}/include
  ${PROJECT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
)

set( VISHNUCOMMON-ARGUMENTPARSING_HEADERS )  
set( VISHNUCOMMON-ARGUMENTPARSING_SOURCES vishnucommon-ArgumentParsing.cpp )
set( VISHNUCOMMON-ARGUMENTPARSING_LINK_LIBRARIES VishnuCommon )

common_application( vishnucommon-ArgumentParsing )

set( VISHNUCOMMON-JSONSERIALIZATION_HEADERS Auxiliar.hpp )  
set( VISHNUCOMMON-JSONSERIALIZATION_SOURCES vishnucommon-JsonSerialization.cpp )
set( VISHNUCOMMON-JSONSERIALIZATION_LINK_LIBRARIES VishnuCommon )

common_application( vishnucommon-JsonSerialization )

set( VISHNUCOMMON-XMLSERIALIZATION_HEADERS Auxiliar.hpp )
set( VISHNUCOMMON-XMLSERIALIZATION_SOURCES vishnucommon-XmlSerialization.cpp )
set( VISHNUCOMMON-XMLSERIALIZATION_LINK_LIBRARIES VishnuCommon )

common_application( vishnucommon-XmlSerialization )




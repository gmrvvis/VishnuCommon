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

#ifndef VISHNUCOMMON_AUXILIAR_HPP
#define VISHNUCOMMON_AUXILIAR_HPP

#include <vishnucommon/vishnucommon.h>

class Auxiliar
{

  public:

    static vishnucommon::DataSetsPtr createDataSets( )
    {
      //Dataset properties (columns)
      vishnucommon::PropertyPtr prop1( new vishnucommon::Property(
        "Spine Id",
        vishnucommon::DataCategory::Geometric,
        vishnucommon::DataStructureType::None ) );

      vishnucommon::PropertyPtr prop2( new vishnucommon::Property(
        "Spine Area",
        vishnucommon::DataCategory::Quantitative,
        vishnucommon::DataStructureType::None ) );

      vishnucommon::PropertyPtr prop3( new vishnucommon::Property(
        "Spine Length",
        vishnucommon::DataCategory::Quantitative,
        vishnucommon::DataStructureType::None ) );

      vishnucommon::PropertyPtr prop4( new vishnucommon::Property(
        "Spine Position X",
        vishnucommon::DataCategory::Quantitative,
        vishnucommon::DataStructureType::None ) );

      vishnucommon::PropertyPtr prop5( new vishnucommon::Property(
        "Spine Position Y",
        vishnucommon::DataCategory::Quantitative,
        vishnucommon::DataStructureType::None ) );

      vishnucommon::PropertyPtr prop6( new vishnucommon::Property(
        "Spine Position Z",
        vishnucommon::DataCategory::Quantitative,
        vishnucommon::DataStructureType::None ) );

      vishnucommon::PropertyPtr prop7( new vishnucommon::Property(
        "Model Matrix",
        vishnucommon::DataCategory::Ordinal,
        vishnucommon::DataStructureType::Mat3 ) );

      //DataSet Metadata
      vishnucommon::MetadataPtr dataSetMetadata( new vishnucommon::Metadata( ) );
      dataSetMetadata->setMetadata( "customKey1", "value1" );

      //DataSet
      vishnucommon::DataSetPtr dataSet( new vishnucommon::DataSet( ) );
      dataSet->setPath( "/media/DATA/csv/test1.csv" );
      dataSet->setProperties( { prop1, prop2, prop3, prop4, prop5, prop6,
        prop7 } );
      dataSet->setMetadata( dataSetMetadata );

      //Global Property Groups
      vishnucommon::PropertyGroupsPtr propertyGroups(
        new vishnucommon::PropertyGroups( ) );
      propertyGroups->setUsedPrimaryKeys( { "Spine Id" } ); //Order is important
      propertyGroups->setUsedNonPrimaryKeys( { "Spine Area", "Spine Length",
        "Model Matrix" } );
      propertyGroups->setAxes( "Spine Position X", "Spine Position Y",
        "Spine Position Z" );


      //Global Metadata
      vishnucommon::MetadataPtr globalMetadata( new vishnucommon::Metadata( ) );
      globalMetadata->setMetadata( "globalKey", "globalValue" );

      //Json data to serialize
      vishnucommon::DataSetsPtr dataSets( new vishnucommon::DataSets( ) );
      dataSets->setDataSets( { dataSet } );
      dataSets->setPropertyGroups( propertyGroups );
      dataSets->setMetadata( globalMetadata );

      return dataSets;
    }

    static vishnucommon::PyramidalXMLPtr createPyramidalXML( )
    {
      //Features
     vishnucommon::FeaturesVector featuresVector;
     featuresVector.emplace_back( vishnucommon::FeaturePtr( new vishnucommon::Feature(
       "Spine Area",
       "Area",
       "um2",
       vishnucommon::DataCategory::Quantitative,
       vishnucommon::DataStructureType::None ) ) );

     featuresVector.emplace_back( vishnucommon::FeaturePtr( new vishnucommon::Feature(
       "Spine Length",
       "Length",
       "um",
       vishnucommon::DataCategory::Quantitative,
       vishnucommon::DataStructureType::None ) ) );

     featuresVector.emplace_back( vishnucommon::FeaturePtr( new vishnucommon::Feature(
       "Spine Max Diameter",
       "Max Diam.",
       "um",
       vishnucommon::DataCategory::Quantitative,
       vishnucommon::DataStructureType::None ) ) );

     featuresVector.emplace_back( vishnucommon::FeaturePtr( new vishnucommon::Feature(
       "Spine Neck Min Diameter",
       "Neck Min Diam.",
       "um",
       vishnucommon::DataCategory::Quantitative,
       vishnucommon::DataStructureType::None ) ) );

     featuresVector.emplace_back( vishnucommon::FeaturePtr( new vishnucommon::Feature(
       "Spine Volume",
       "Volume",
       "um3",
       vishnucommon::DataCategory::Quantitative,
       vishnucommon::DataStructureType::None ) ) );

     featuresVector.emplace_back( vishnucommon::FeaturePtr( new vishnucommon::Feature(
       "Membrane Potential Peak",
       "Memb. Pot. Peak",
       "mV",
       vishnucommon::DataCategory::Quantitative,
       vishnucommon::DataStructureType::None ) ) );

     featuresVector.emplace_back( vishnucommon::FeaturePtr( new vishnucommon::Feature(
       "Kmeans_clustering",
       "Kmeans_clustering",
       "mV",
       vishnucommon::DataCategory::Quantitative,
       vishnucommon::DataStructureType::None ) ) );

     featuresVector.emplace_back( vishnucommon::FeaturePtr( new vishnucommon::Feature(
       "cl_idendrog_3clusters",
        "cl_idendrog_3clusters",
        "mV",
       vishnucommon::DataCategory::Quantitative,
       vishnucommon::DataStructureType::None ) ) );

     featuresVector.emplace_back( vishnucommon::FeaturePtr( new vishnucommon::Feature(
       "cl_idendrog_7clusters",
       "cl_idendrog_7clusters",
       "mV",
       vishnucommon::DataCategory::Quantitative,
       vishnucommon::DataStructureType::None ) ) );

     for(int i = 1; i <= 10; ++i)
     {
       featuresVector.emplace_back( vishnucommon::FeaturePtr(
         new vishnucommon::Feature(
         "kmeans" + std::to_string( i ),
         "kmeans" + std::to_string( i ),
         "mV",
         vishnucommon::DataCategory::Quantitative,
         vishnucommon::DataStructureType::None ) ) );
     }

     featuresVector.emplace_back( vishnucommon::FeaturePtr( new vishnucommon::Feature(
       "position3clusters",
       "position3clusters",
       "mV",
       vishnucommon::DataCategory::Quantitative,
       vishnucommon::DataStructureType::None ) ) );

     featuresVector.emplace_back( vishnucommon::FeaturePtr( new vishnucommon::Feature(
       "position5clusters",
       "position5clusters",
       "mV",
       vishnucommon::DataCategory::Quantitative,
       vishnucommon::DataStructureType::None ) ) );

     featuresVector.emplace_back( vishnucommon::FeaturePtr( new vishnucommon::Feature(
       "position7clusters",
       "position7clusters",
       "mV",
       vishnucommon::DataCategory::Quantitative,
       vishnucommon::DataStructureType::None ) ) );

     vishnucommon::FeaturesPtr features( new vishnucommon::Features(
       { "Spine Id" },
       { "Spine Position X", "Spine Position Y", "Spine Position Z" },
       "Spine Id",
       featuresVector));

     //Set
     vishnucommon::Sets sets;
     sets.emplace_back( vishnucommon::SetPtr( new vishnucommon::Set(
       "/media/External/data/spineretdata/m16 cing 1 9/v3/basal/csv/m16 cing 1 9basales SpineRet3.csv" ) ) );

     //Data
     vishnucommon::DataPtr data(
       new vishnucommon::Data( "Spine", "", features, sets ) );

     //Colors
     vishnucommon::Vec3Ptr additionalMeshesColor(
       new vishnucommon::Vec3( "60", "60", "60" ) );
     vishnucommon::Vec3Ptr backgroundColor( new vishnucommon::Vec3( "0", "0", "0" ) );
     vishnucommon::ColorsPtr colors(
       new vishnucommon::Colors( additionalMeshesColor, backgroundColor ) );

     //Camera
     vishnucommon::Vec3Ptr eye(
       new vishnucommon::Vec3( "577.183", "1106.67", "290.011" ) );
     vishnucommon::Vec3Ptr center(
       new vishnucommon::Vec3( "479.859", "-26.1715", "670.239" ) );
     vishnucommon::Vec3Ptr up(
       new vishnucommon::Vec3( "0.0183558", "-0.319558", "-0.947389" ) );
     vishnucommon::CameraPtr camera( new vishnucommon::Camera( eye, center, up ) );

     //Configuration
     vishnucommon::ConfigurationPtr configuration( new vishnucommon::Configuration(
       "PyramidalExplorer",
       "0.2.0",
       "m16 - cing - 1 - 9 - apical",
       data,
       colors,
       camera ) );

     //PyramidalXML
     std::string dtd =
       "<!DOCTYPE configuration SYSTEM \"http://gmrv.es/pyramidalexplorer/PyramidalExplorerData-0.2.0.dtd\">";
     vishnucommon::PyramidalXMLPtr pyramidalXML(
       new vishnucommon::PyramidalXML( dtd, configuration ) );
     return pyramidalXML;
    }
};

#endif

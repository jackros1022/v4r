/*
 * global_nn_classifier.cpp
 *
 *  Created on: Mar 9, 2012
 *      Author: aitor
 */

#include <v4r/recognition/impl/global_nn_classifier.hpp>
#include <v4r/recognition//metrics.h>

//Instantiation
template class v4r::rec_3d_framework::GlobalNNPipeline<flann::L1, pcl::PointXYZ, pcl::VFHSignature308>;
template class v4r::rec_3d_framework::GlobalNNPipeline<v4r::Metrics::HistIntersectionUnionDistance, pcl::PointXYZ, pcl::VFHSignature308>;
template class v4r::rec_3d_framework::GlobalNNPipeline<flann::L1, pcl::PointXYZ, pcl::ESFSignature640>;

template class v4r::rec_3d_framework::GlobalClassifier<pcl::PointXYZ>;
/**
 * $Id$
 *
 * Copyright (c) 2014, Johann Prankl
 * @author Johann Prankl (prankl@acin.tuwien.ac.at)
 */

#ifndef KP_CONVERT_CLOUD_HPP
#define KP_CONVERT_CLOUD_HPP

#include <float.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <v4r/common/impl/DataMatrix2D.hpp>
#include <v4r/keypoints/impl/PointTypes.hpp>


namespace v4r 
{


inline void convertCloud(const pcl::PointCloud<pcl::PointXYZRGB> &cloud, v4r::DataMatrix2D<v4r::PointXYZRGB> &kp_cloud)
{
  kp_cloud.resize(cloud.height, cloud.width);

  for (unsigned i=0; i<cloud.points.size(); i++)
  {
    const pcl::PointXYZRGB &pt = cloud.points[i];
    v4r::PointXYZRGB &kp = kp_cloud.data[i];

    kp.pt = pt.getVector4fMap();
    kp.rgb = pt.rgb;
  }
}

inline void convertCloud(const pcl::PointCloud<pcl::PointXYZRGB> &cloud, v4r::DataMatrix2D<Eigen::Vector3f> &kp_cloud, cv::Mat_<cv::Vec3b> &image)
{
  kp_cloud.resize(cloud.height, cloud.width);
  image = cv::Mat_<cv::Vec3b>(cloud.height, cloud.width);

  for (unsigned i=0; i<cloud.points.size(); i++)
  {
    const pcl::PointXYZRGB &pt = cloud.points[i];

    kp_cloud.data[i] = pt.getVector3fMap();
    image(i) = cv::Vec3b(pt.b,pt.g,pt.r);
  }
}

inline void convertCloud(const pcl::PointCloud<pcl::PointXYZRGB> &cloud, v4r::DataMatrix2D<Eigen::Vector3f> &kp_cloud)
{
  kp_cloud.resize(cloud.height, cloud.width);

  for (unsigned i=0; i<cloud.points.size(); i++)
  {
    const pcl::PointXYZRGB &pt = cloud.points[i];

    kp_cloud.data[i] = pt.getVector3fMap();
  }
}

inline void convertCloud(const v4r::DataMatrix2D<v4r::PointXYZRGB> &kp_cloud, pcl::PointCloud<pcl::PointXYZRGB> &pcl_cloud)
{
  pcl_cloud.points.resize(kp_cloud.data.size());
  pcl_cloud.width = kp_cloud.cols;
  pcl_cloud.height = kp_cloud.rows;
  pcl_cloud.is_dense = false;

  for (unsigned i=0; i<pcl_cloud.points.size(); i++)
  {
    const v4r::PointXYZRGB &kp = kp_cloud.data[i];
    pcl::PointXYZRGB &pt = pcl_cloud.points[i];

    pt.getVector4fMap() = kp.pt;
    pt.rgb = kp.rgb;
  }
}


} //--END--

#endif


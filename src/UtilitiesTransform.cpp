/*
 * UtilitiesTransform.cpp
 *
 *  Created on: Dec 12, 2016
 *      Author: phil
 */

#include "UtilitiesTransform.h"



namespace ohm_tsd_slam
{

UtilitiesTransform::UtilitiesTransform()
{
  // TODO Auto-generated constructor stub

}

UtilitiesTransform::~UtilitiesTransform()
{
  // TODO Auto-generated destructor stub
}

tf::Transform UtilitiesTransform::obviouslyMatrix3x3ToTf(obvious::Matrix& ob)
{
  tf::Transform tf;
  tf.setOrigin( tf::Vector3(ob(0,2), ob(1,2), 0.0) );
  tf.setRotation( tf::createQuaternionFromYaw( asin( ob(0,1) ) ) );

  return tf;
}

obvious::Matrix UtilitiesTransform::tfToObviouslyMatrix3x3(const tf::Transform& tf)
{
  obvious::Matrix ob(3,3);
  ob.setIdentity();

  double theta = tf::getYaw(tf.getRotation());
  double x = tf.getOrigin().getX();
  double y = tf.getOrigin().getY();

  // problem with sin() returns -0.0 (avoid with +0.0)
  ob(0, 0) = cos(theta) + 0.0;
  ob(0, 1) = -sin(theta) + 0.0;
  ob(0, 2) = x + 0.0;
  ob(1, 0) = sin(theta) + 0.0;
  ob(1, 1) = cos(theta) + 0.0;
  ob(1, 2) = y + 0.0;

  return ob;
}

} /* namespace ohm_tsd_slam */
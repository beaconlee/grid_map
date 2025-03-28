#pragma once

#include <Eigen/Dense>

namespace beacon::grid_map
{

using Matrix = Eigen::MatrixXf;
using DataType = Matrix::Scalar;
using Position = Eigen::Vector2d;
using Vector = Eigen::Vector2d;
using Position3 = Eigen::Vector3d;
using Vector3 = Eigen::Vector3d;
using Index = Eigen::Array2i;
using Size = Eigen::Array2i;
using Length = Eigen::Array2d;
using Time = uint64_t;

enum class InterpolationMethods
{
  INTER_NEAREST,           // nearest neighbor interpolation
  INTER_LINEAR,            // bilinear interpolation
  INTER_CUBIC_CONVOLUTION, //piecewise bicubic interpolation using convolution algorithm
  INTER_CUBIC              // standard bicubic interpolation
};

} // namespace beacon::grid_map
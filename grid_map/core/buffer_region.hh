#pragma once

#include "type_defs.hh"

namespace beacon::grid_map
{

class BufferRegion
{
public:
  enum class Quadrant
  {
    Undefined,
    TopLeft,
    TopRight,
    BottomLeft,
    BottomRight
  };

  BufferRegion()
    : start_index_(Index::Zero())
    , size_(Size::Zero())
    , quadrant_(Quadrant::Undefined)
  {}

  BufferRegion(Index start, Size size, Quadrant quadrant)
    : start_index_(std::move(start))
    , size_(std::move(size))
    , quadrant_(quadrant)
  {}

  const Index &
  start_index();
  void
  set_start_index(const Index &index);


  const Size &
  size();
  void
  set_size(const Size &size);


  const Quadrant &
  quadrant();
  void
  set_quadrant(const Quadrant &quadrant);


private:
  Index start_index_;
  Size size_;
  Quadrant quadrant_;

public:
  // Eigen 库在处理固定大小的向量或矩阵（如 Eigen::Vector4f 或 Eigen::Matrix4f）时，要求这些对象的内存地址按照特定的字节边界对齐（通常是 16 字节对齐，用于支持 SIMD 指令，如 SSE 或 AVX）。
  // C++ 的默认 new 操作符分配内存时，并不保证这种对齐，而 EIGEN_MAKE_ALIGNED_OPERATOR_NEW 会重载类的 operator new，使其分配的内存满足 Eigen 的对齐要求。
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW
};
} // namespace beacon::grid_map
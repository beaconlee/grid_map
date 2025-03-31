#pragma once

#include "grid_map/core/grid_map.hh"


namespace beacon::grid_map
{

class SubmapGeometry
{
public:
  SubmapGeometry(const GridMap *grid_map,
                 const Position &position,
                 const Length &length,
                 bool &is_succ);

  virtual ~SubmapGeometry() = default;

  [[nodiscard]] const GridMap *
  grid_map() const
  {
    return parent_;
  }

  [[nodiscard]] const Length &
  length() const
  {
    return length_;
  }

  [[nodiscard]] const Position &
  position() const
  {
    return position_;
  }

  [[nodiscard]] const Index &
  submap_start_index() const
  {
    return submap_start_index_;
  }

  [[nodiscard]] const Size &
  size() const
  {
    return size_;
  }

  [[nodiscard]] double
  resolution() const
  {
    return parent_->resolution();
  }

  [[nodiscard]] const Index &
  start_index() const
  {
    return start_index_;
  }

private:
  const GridMap *parent_;
  // Start index (typically top left) index of the submap
  Index start_index_;
  Size size_;
  Position position_;
  Length length_;
  // 子地图中与所请求的子地图位置相对应的索引。
  Index submap_start_index_;
};

} // namespace beacon::grid_map

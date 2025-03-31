
#include "grid_map/core/polygon.hh"



namespace beacon::grid_map
{


bool
Polygon::is_inside(const Position &position) const
{
  int cross = 0;
  size_t n = vertices_.size();
  for(size_t i = 0, j = n - 1; i < n; j = i, ++i)
  {
    const auto &vi = vertices_[i];
    const auto &vj = vertices_[j];

    if(on_edge(position, vi, vj))
    {
      return true;
    }

    // 这里表明 vi 和 vj 连线不在 position 的同一侧
    // 这里也可以确保, vi.y() 和 vj.y() 是不相同的
    if((vi.y() > position.y()) != (vj.y() > position.y()))
    {
      // (vi.x() - vj.x()) / (vi.y() - vj.y()) 斜率的倒数
      // (position.y() - vj.y()) * 1/k 横轴的移动范围
      double intersect_x = vj.x() + (position.y() - vj.y()) *
                                        (vi.x() - vj.x()) / (vi.y() - vj.y());

      // 这表明交点在 position 的左侧, 这里的射线是默认水平向右的
      if(position.x() < intersect_x)
      {
        ++cross;
      }
    }
  }

  return cross % 2 == 1;
}


// 辅助函数: 判断点是否在边上
bool
Polygon::on_edge(const Position &pose,
                 const Position &start,
                 const Position &end)
{
  double min_x = std::min(start.x(), end.x());
  double max_x = std::max(start.x(), end.x());
  double min_y = std::min(start.y(), end.y());
  double max_y = std::max(start.y(), end.y());

  //
  if(pose.x() >= min_x && pose.x() <= max_x && pose.y() >= min_y &&
     pose.y() <= max_y)
  {
    // 计算斜率是否一致（避免浮点数误差）
    double crossProduct = (pose.x() - start.x()) * (end.y() - start.y()) -
                          (pose.y() - start.y()) * (end.x() - start.x());
    return std::abs(crossProduct) < 1e-9;
    // 允许一定的精度误差
  }
  return false;
}

void
Polygon::add_vertex(const Position &vertex)
{
  vertices_.push_back(vertex);
  ++size_;
}

[[nodiscard]] const Position &
Polygon::get_vertex(size_t index) const
{
  assert(index < size_);
  return vertices_[index];
}

[[nodiscard]] const Position &
Polygon::operator[](size_t index) const
{
  return get_vertex(index);
}

void
Polygon::clear()
{
  vertices_.clear();
  size_ = 0;
}

[[nodiscard]] const std::vector<Position> &
Polygon::get_vertices() const
{
  return vertices_;
}


[[nodiscard]] double
Polygon::area() const
{
  double area = 0.0;
  size_t n = vertices_.size();
  size_t j = n - 1;
  for(size_t i = 0; i < n; i++)
  {
    // 下一个顶点，最后一个顶点连接到第一个顶点
    area += vertices_[i].x() * vertices_[j].y() -
            vertices_[j].x() * vertices_[i].y();
    j = i;
  }

  return std::abs(area) / 2.0;
}

} // namespace beacon::grid_map

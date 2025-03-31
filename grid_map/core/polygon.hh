#pragma once

#include "grid_map/core/type_defs.hh"


namespace beacon::grid_map
{

class Polygon
{
public:
  Polygon() = default;

  Polygon(std::vector<Position> vertices)
    : vertices_(std::move(vertices))
    , size_(vertices.size())
  {}

  [[nodiscard]] bool
  is_inside(const Position &position) const;

  [[nodiscard]] bool static on_edge(const Position &position,
                                    const Position &left,
                                    const Position &right);

  void
  add_vertex(const Position &vertex);

  [[nodiscard]] const Position &
  get_vertex(size_t index) const;

  const Position &
  operator[](size_t index) const;

  [[nodiscard]] const std::vector<Position> &
  get_vertices() const;

  [[nodiscard]] inline size_t
  size() const
  {
    return size_;
  }

  [[nodiscard]] inline const std::string &
  frame_id() const
  {
    return frame_id_;
  }

  inline void
  set_frame_id(const std::string &frame_id)
  {
    frame_id_ = frame_id;
  }

  inline void
  set_timestample(Time timestample)
  {
    timestample_ = timestample;
  }

  [[nodiscard]] inline Time
  timestample() const
  {
    return timestample_;
  }

  inline void
  reset_timestample()
  {
    timestample_ = 0;
  }

  void
  clear();

  [[nodiscard]] double
  area() const;

private:
  // Timestamp of the polygon
  Time timestample_{0};
  std::string frame_id_;
  std::vector<Position> vertices_;
  size_t size_{0};
};

} // namespace beacon::grid_map
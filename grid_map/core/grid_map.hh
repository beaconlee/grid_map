#pragma once

#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/Geometry>

#include "type_defs.hh"


namespace beacon::grid_map
{

class GridMap
{
public:
  GridMap();
  explicit GridMap(const std::vector<std::string> &layers_name);
  GridMap(const GridMap &) = default;
  GridMap &
  operator=(const GridMap &) = default;
  GridMap(GridMap &&) = default;
  GridMap &
  operator=(GridMap &&) = default;

  virtual ~GridMap() = default;

  void
  set_geometry(const Length &length,
               double resolution,
               const Position &position = Position::Zero());

  // td
  // void set_geometry(const )

  void
  add(const std::string &layer_name, const Matrix &data);

  void
  add(const std::string &layer_name, const float value = NAN);

  void
  clear_all();

  bool
  exist(const std::string &layer_name) const;

  const Matrix &
  get(const std::string &layer_name) const;

  Matrix &
  get(const std::string &layer_name);


  const Matrix &
  operator[](const std::string &layer_name) const;

  Matrix &
  operator[](const std::string &layer_name);

  bool
  erase(const std::string &layer_name);


  [[nodiscard]]
  inline const std::vector<std::string> &
  get_layers() const
  {
    return layers_;
  }

  inline void
  set_basic_layer(const std::vector<std::string> &basic_layer)
  {
    basic_layers_ = basic_layer;
  }

  [[nodiscard]]
  inline const std::vector<std::string> &
  basic_layer() const
  {
    return basic_layers_;
  }

  inline bool
  has_basic_layer() const
  {
    return !basic_layers_.empty();
  }

  bool
  has_same_layers(const GridMap &other) const;

  bool
  position_2_index(const Position &position, Index &index);

  float &
  at(const std::string &layer_name, const Index &index);

  float
  at(const std::string &layer_name, const Index &index) const;

  void
  set(const Position &position);

  double
  resolution() const
  {
    return resolution_;
  }

private:
  void
  resize(Index new_size);

  std::string frame_id_;
  std::vector<std::string> layers_;
  std::vector<std::string> basic_layers_;
  std::unordered_map<std::string, Matrix> data_;

  Time timestample_;

  // 是实际长度
  Length length_;
  // length / resolution，栅格的大小
  Size size_;
  Position position_;
  double resolution_;
  Index start_index_;

public:
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW
};

} // namespace beacon::grid_map
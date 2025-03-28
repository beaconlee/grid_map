#include "grid_map.hh"

namespace beacon::grid_map
{

GridMap::GridMap()
  : timestample_(0)
  , resolution_(0.0)
{}

GridMap::GridMap(const std::vector<std::string> &layers_name)
  : timestample_(0)
  , resolution_(0.0)
{}

void
GridMap::resize(Index new_size)
{
  size_ = new_size;
  for(auto layer : data_)
  {
    layer.second.resize(new_size[0], new_size[1]);
  }
}

void
GridMap::set_geometry(const Length &length,
                      double resolution,
                      const Position &position)
{
  assert(length.x() > 0.);
  assert(length.y() > 0.);
  assert(resolution > 0.);

  Size size;
  size.x() = static_cast<int>(std::round(length.x() / resolution));
  size.y() = static_cast<int>(std::round(length.y() / resolution));
  resize(size);
  clear_all();

  resolution_ = resolution;
  // td
  length_ = (size_.cast<double>() * resolution_).matrix();
  position_ = position;
  start_index_.setZero();
}

void
GridMap::add(const std::string &layer_name, const Matrix &data)
{
  if(exist(layer_name))
  {
    // data_.at(layer_name) = data;
    data_[layer_name] = data;
  }
  else
  {
    // td
    // data_.insert(std::make_pair(layer_name, data));
    data_.insert(std::pair<std::string, Matrix>(layer_name, data));
    layers_.push_back(layer_name);
  }
}

void
GridMap::add(const std::string &layer_name, const float value)
{
  add(layer_name, Matrix::Constant(size_[0], size_[1], value));
}

void
GridMap::clear_all()
{
  // td 这里没有注意到加了 const
  // for(const auto &layer : data_)
  for(auto &layer : data_)
  {
    layer.second.setConstant(NAN);
  }
}

bool
GridMap::exist(const std::string &layer_name)
{
  return data_.find(layer_name) != data_.end();
}

const Matrix &
GridMap::get(const std::string &layer_name) const
{
  try
  {
    return data_.at(layer_name);
  }
  catch(const std::out_of_range &exception)
  {
    throw std::out_of_range("GridMap::get(...) : No map layer '" + layer_name +
                            "' available.");
  }
}

Matrix &
GridMap::get(const std::string &layer_name)
{
  try
  {
    return data_.at(layer_name);
  }
  catch(const std::out_of_range &exception)
  {
    throw std::out_of_range("GridMap::get(...) : No map layer '" + layer_name +
                            "' available.");
  }
}

const Matrix &
GridMap::operator[](const std::string &layer_name) const
{
  return get(layer_name);
}

Matrix &
GridMap::operator[](const std::string &layer_name)
{
  return get(layer_name);
}

bool
GridMap::erase(const std::string &layer_name)
{
  auto data_iter = data_.find(layer_name);
  if(data_iter == data_.end())
  {
    return false;
  }
  data_.erase(layer_name);

  auto layer_iter = std::find(layers_.begin(), layers_.end(), layer_name);
  if(layer_iter == layers_.end())
  {
    return false;
  }
  layers_.erase(layer_iter);

  auto basic_iter =
      std::find(basic_layers_.begin(), basic_layers_.end(), layer_name);
  if(basic_iter != basic_layers_.end())
  {
    // basic_layers_.erase(layer_name);
    basic_layers_.erase(basic_iter);
  }

  return true;
}



} // namespace beacon::grid_map
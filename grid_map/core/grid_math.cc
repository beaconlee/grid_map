#include "grid_map/core/grid_math.hh"

namespace beacon::grid_map
{

bool
position_2_index(Index &index,
                 const Position &position,
                 const Length &length,
                 const Position &map_position,
                 double resolution,
                 const Size &buffer_size,
                 const Index &start_index)
{
  const Vector index_vector =
      ((position - map_position - map_offset(length)) / resolution).matrix();
  // 这里在传递时,会将 double 类型转换成 int 类型
  index = index_vec_2_index(index_vector, buffer_size, start_index);

  return false;
}


Index
index_vec_2_index(const Vector &index_vec,
                  const Size &buffer_size,
                  const Index &start_index)
{
  return {};
}


} // namespace beacon::grid_map

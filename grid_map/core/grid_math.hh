#pragma once

#include "grid_map/core/type_defs.hh"

namespace beacon::grid_map
{
bool
position_2_index(Index &index,
                 const Position &position,
                 const Length &length,
                 const Position &map_position,
                 double resolution,
                 const Size &buffer_size,
                 const Index &start_index);

inline Vector
map_offset(const Length &map_length)
{
  return (map_length / 2).matrix();
}

Index
index_vec_2_index(const Vector &index_vec,
                  const Size &buffer_size,
                  const Index &start_index);

bool
index_in_range();

bool
position_in_map();


} // namespace beacon::grid_map

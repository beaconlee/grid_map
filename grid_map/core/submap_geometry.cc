#include "grid_map/core/submap_geometry.hh"

namespace beacon::grid_map
{

SubmapGeometry::SubmapGeometry(const GridMap *grid_map,
                               const Position &position,
                               const Length &length,
                               bool &is_succ)
  : parent_(grid_map)
{
  
}

} // namespace beacon::grid_map
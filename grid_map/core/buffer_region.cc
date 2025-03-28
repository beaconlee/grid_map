#include "buffer_region.hh"


namespace beacon::grid_map
{

const Index &
BufferRegion::start_index()
{
  return start_index_;
}
void
BufferRegion::set_start_index(const Index &index)
{
  start_index_ = index;
}


const Size &
BufferRegion::size()
{
  return size_;
}
void
BufferRegion::set_size(const Size &size)
{
  size_ = size;
}


const BufferRegion::Quadrant &
BufferRegion::quadrant()
{
  return quadrant_;
}
void
BufferRegion::set_quadrant(const Quadrant &quadrant)
{
  quadrant_ = quadrant;
}

} // namespace beacon::grid_map
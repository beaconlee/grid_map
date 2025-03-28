#include "cubic_interpolation.hh"

namespace beacon::grid_map
{

unsigned int
clamp_index(unsigned int index, unsigned int max_size)
{
  if(index >= max_size)
  {
    return max_size - 1;
  }
  return index;
}


double
get_layer_value(const Matrix &layer_mat, unsigned int row, unsigned int col)
{
  const unsigned int row_clamped = clamp_index(row, layer_mat.rows());
  const unsigned int col_clamped = clamp_index(col, layer_mat.cols());
  return layer_mat(row_clamped, col_clamped);
}


} // namespace beacon::grid_map

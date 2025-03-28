#pragma once

#include "type_defs.hh"

namespace beacon::grid_map
{

unsigned int
clamp_index(unsigned int index, unsigned int max_size);


double
get_layer_value(const Matrix &layer_mat, unsigned int row, unsigned int col);


} // namespace beacon::grid_map
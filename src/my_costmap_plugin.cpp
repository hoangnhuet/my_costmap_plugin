#include "my_costmap_plugin/my_costmap_plugin.hpp"
#include "pluginlib/class_list_macros.hpp"

namespace my_costmap_plugin
{

MyCostmapPlugin::MyCostmapPlugin()
{
}

MyCostmapPlugin::~MyCostmapPlugin()
{
}

void MyCostmapPlugin::onInitialize()
{
  current_ = true;
}

void MyCostmapPlugin::updateBounds(
  double origin_x, double origin_y, double origin_yaw,
  double* min_x, double* min_y, double* max_x, double* max_y)
{
  // No bounds to update, but this is required by the interface
}

void MyCostmapPlugin::updateCosts(
  nav2_costmap_2d::Costmap2D& master_grid, int min_i, int min_j, int max_i, int max_j)
{
  for (int j = min_j; j < max_j; j++) {
    for (int i = min_i; i < max_i; i++) {
      master_grid.setCost(i, j, MAX_COST);  // Set each cell to the maximum cost
    }
  }
}

void MyCostmapPlugin::deactivate()
{
  // Handle deactivation (e.g., stop updating costs)
}

void MyCostmapPlugin::activate()
{
  // Handle activation (e.g., resume updating costs)
}

void MyCostmapPlugin::reset()
{
  // Handle reset (e.g., clear the layer)
  deactivate();
  activate();
}

// Implementation of the isClearable method
bool MyCostmapPlugin::isClearable()
{
  return true;  // Return true if the layer can be cleared (or false if it shouldn't be cleared)
}

}  // namespace my_costmap_plugin

// Register this plugin with the pluginlib system
PLUGINLIB_EXPORT_CLASS(my_costmap_plugin::MyCostmapPlugin, nav2_costmap_2d::Layer)


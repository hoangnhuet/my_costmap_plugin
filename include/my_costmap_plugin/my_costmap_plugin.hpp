#ifndef MY_COSTMAP_PLUGIN__MY_COSTMAP_PLUGIN_HPP_
#define MY_COSTMAP_PLUGIN__MY_COSTMAP_PLUGIN_HPP_

#include "nav2_costmap_2d/costmap_layer.hpp"
#include "pluginlib/class_list_macros.hpp"

namespace my_costmap_plugin
{

class MyCostmapPlugin : public nav2_costmap_2d::CostmapLayer
{
public:
  MyCostmapPlugin();
  virtual ~MyCostmapPlugin();

  virtual void onInitialize() override;
  virtual void updateBounds(
    double origin_x, double origin_y, double origin_yaw,
    double* min_x, double* min_y, double* max_x, double* max_y) override;
  virtual void updateCosts(
    nav2_costmap_2d::Costmap2D& master_grid, int min_i, int min_j, int max_i, int max_j) override;
  virtual void deactivate() override;
  virtual void activate() override;
  virtual void reset() override;

  // Implementing the pure virtual method from nav2_costmap_2d::Layer
  virtual bool isClearable() override;

private:
  const unsigned char MAX_COST = 254;  // Max value for a costmap cell
};

}  // namespace my_costmap_plugin

#endif  // MY_COSTMAP_PLUGIN__MY_COSTMAP_PLUGIN_HPP_

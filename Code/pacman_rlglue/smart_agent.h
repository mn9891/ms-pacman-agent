//~ Amen_Memmi_Assignment_3
#ifndef ALE_SMART_AGENT_H
#define ALE_SMART_AGENT_H

#include "../src/common/Constants.h"
#include "pacman_objects.h"
#include "constants.h"

class smart_agent {
private:
    double euclidean_distance(loc location1, loc location2);
    double ghost_reward(loc pacman_loc, loc ghost_loc);
    double corner_reward(loc pacman_loc);
    double teleport_reward(loc pacman_loc);
    double pellet_reward(loc pacman_loc, vector<loc> pellet_loc);

public:
    smart_agent();
    Action get_action(pacman_objects p_image, vector<loc> object_locations, vector<loc> edible_ghosts);
};

#endif

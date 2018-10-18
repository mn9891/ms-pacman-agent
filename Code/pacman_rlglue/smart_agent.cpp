//~ Amen_Memmi_Assignment_3
#include "smart_agent.h"

smart_agent::smart_agent() {}

double smart_agent::euclidean_distance(loc location1, loc location2) {
    return sqrt(pow(abs(location1.first - location2.first), 2) + pow(abs(location1.second - location2.second), 2));
}

double smart_agent::ghost_reward(loc pacman_loc, loc ghost_loc) {
    double reward = GHOST_REWARD / euclidean_distance(pacman_loc, ghost_loc);
    return reward;
}

double smart_agent::corner_reward(loc pacman_loc) {
    if (pacman_loc.first > SCREEN_HEIGHT / 2) pacman_loc.first = MAZE_HEIGHT - pacman_loc.first;
    if (pacman_loc.second > SCREEN_WIDTH / 2) pacman_loc.second = SCREEN_WIDTH - pacman_loc.second;
    if (pacman_loc.first < 1 && pacman_loc.second < 1) return CORNER_REWARD;
    else return CORNER_REWARD / euclidean_distance(pacman_loc, make_pair(0, 0));
}

double smart_agent::teleport_reward(loc pacman_loc) {
    return (TELE_REWARD/euclidean_distance(pacman_loc,
                                         make_pair(double(UPPER_TELEPORTATION_ROW), 0)) +
            TELE_REWARD/euclidean_distance(pacman_loc,
                                         make_pair(double(UPPER_TELEPORTATION_ROW),
                                                   SCREEN_WIDTH)) +
            TELE_REWARD/euclidean_distance(pacman_loc,
                                         make_pair(double(LOWER_TELEPORTATION_ROW), 0)) +
            TELE_REWARD/euclidean_distance(pacman_loc,
                                         make_pair(double(LOWER_TELEPORTATION_ROW),
                                                   SCREEN_WIDTH)));
}

double smart_agent::pellet_reward(loc pacman_loc, vector<loc> pellet_loc) {
    double total_reward = 0.0;
    for (int i = 0; i < pellet_loc.size(); ++i)
    {
        total_reward += PELLET_REWARD/euclidean_distance(pacman_loc, pellet_loc[i]);
    }
    return total_reward;
}

Action smart_agent::get_action(pacman_objects p_image, vector<loc> object_locations, vector<loc> edible_ghosts) {
    loc pacman_loc = object_locations[0];
    if (!std::isnan(pacman_loc.first) && !std::isnan(pacman_loc.second)){
        vector<direction> valid_moves = p_image.get_valid_moves(pacman_loc);
        direction least_reward_dir = NULL_DIR;
        double reward = GHOST_REWARD * 4 + TELE_REWARD * 4 + CORNER_REWARD;
        for (size_t i = 0; i < valid_moves.size(); ++i) {
            direction dir = valid_moves[i];
            loc next_pacman_loc;
            if (dir == UP_DIR) {
                next_pacman_loc = make_pair(pacman_loc.first - 1, pacman_loc.second);
            }
            else if (dir == DOWN_DIR) {
                next_pacman_loc = make_pair(pacman_loc.first + 1, pacman_loc.second);
            }
            else if (dir == LEFT_DIR) {
                next_pacman_loc = make_pair(pacman_loc.first, pacman_loc.second - 1);
            }
            else if (dir == RIGHT_DIR) {
                next_pacman_loc = make_pair(pacman_loc.first, pacman_loc.second + 1);
            }
            double dir_reward = 0;
            if (edible_ghosts.size() > 0) {
                for (size_t edible_ghost = 0; edible_ghost < edible_ghosts.size(); ++edible_ghost) {
                    dir_reward -= ghost_reward(next_pacman_loc, edible_ghosts[edible_ghost]);
                }
            }
            else {
                dir_reward += corner_reward(next_pacman_loc) + teleport_reward(next_pacman_loc) +
                            pellet_reward(next_pacman_loc, p_image.get_pellet_pos());
                for (int ghost = 0; ghost < 4; ++ghost) {
                    double c = ghost_reward(next_pacman_loc, object_locations[ghost + 1]);
                    dir_reward += (std::isnan(c) ? 0: c);
                }
            }
            if (dir_reward > reward) {
                reward = dir_reward;
                least_reward_dir = dir;
            }
        }
        // cout << "\n";
        if (least_reward_dir == NULL_DIR) return PLAYER_A_NOOP;
        else if (least_reward_dir == UP_DIR) return PLAYER_A_UP;
        else if (least_reward_dir == DOWN_DIR) return PLAYER_A_DOWN;
        else if (least_reward_dir == LEFT_DIR) return PLAYER_A_LEFT;
        else if (least_reward_dir == RIGHT_DIR) return PLAYER_A_RIGHT;
        else return PLAYER_A_NOOP;
    }
    else return PLAYER_A_NOOP;
}

# ms-pacman-agent


### Project 3 - AI course (ECSE 526) - McGill - Fall 2016
Check project instuctions [here](http://www.cim.mcgill.ca/~jer/courses/ai/assignments/as3.html).
  
In this project, I coded a reinforcement learning agent whose role is to play the famous Ms. Pacman game  within the Atari emulator (Stella) using the Arcade Learning Environment ALE. 

  ![mspacman](https://user-images.githubusercontent.com/44270915/47176769-727d7080-d2e4-11e8-8fdd-51ebbf725aa0.PNG)

The agent coded for this project uses RL-Glue interface to communicate with the ALE. 
The C++ code could be found in the [pacman_rlglue](Code/pacman_rlglue) folder.
The complete results of the simulation could be found in the [results_30_episodes](Code/pacman_rlglue/results_30_episodes.txt) file.
The agent was able to achieve a mean score of 4688 over the 30 episodes with a maximum of 8980.
Please check the [assignement report](ASSIGNMENT_3_REPORT.pdf) for details about performance and the reward funcion used.
 
  
## Installation instructions

Install RL-Glue core from [here](https://code.google.com/archive/p/rl-glue-ext/wikis/RLGlueCore.wiki)  
Install RL-Glue C/C++ codec from [here](https://code.google.com/archive/p/rl-glue-ext/wikis/CandCPP.wiki)  
  
1) Compilation of Environment (ALE)  
   RL Glue core and C/C++ codec must be installed on the system (links given above)  
   > sudo apt-get install cmake libsdl1.2-dev  
   > cd \<project_root_folder\>  
   > cmake -DUSE_SDL=ON -DUSE_RLGLUE=ON -DBUILD_EXAMPLES=ON  
   > \# ALE needs to be compiled with -DUSE_RLGLUE = ON to use rlglue controller  
   > make -j 4  
   
   For further details, check the [Manual for ALE](doc/manual/manual.pdf)
  
2) Compiling the Agent and the Experiment  
   Take the example of Ms. Pacman  
   > cd \<project_root_folder\>  
   > cd pacman_rlglue  
   > make 
  
 ## Start the game
   
   Now we need to start 4 processes from the Project root folder as follows:  
   > rl_glue  
   > ./pacman_rlglue/pacman_agent  
   > ./pacman_rlglue/pacman_experiment  
   > ./ale -display_screen true -game_controller rlglue roms/ms_pacman.bin  



# Amen_Memmi_Assignment_3
# Modified from the C/C++ RL-Glue codec RLGlueAgent's makefile.

AGENTLDFLAGS := -lm -lrlutils -lrlagent -lrlgluenetdev
EXPLDFLAGS := -lrlutils -lrlexperiment -lrlgluenetdev
CFLAGS := -Wall -pedantic -std=c++11

all: 
	AGENTLDFLAGS="$(AGENTLDFLAGS)" CFLAGS="$(CFLAGS)" make -f Makefile.agent
	EXPLDFLAGS="$(EXPLDFLAGS)" CFLAGS="$(CFLAGS)"  make -f Makefile.experiment


clean:
	make -f Makefile.agent  clean
	make -f Makefile.experiment clean

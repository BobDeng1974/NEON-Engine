GLFW_COMMANDS = -lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi -ldl
GLAD = ./src/glad.c

PROJECT_INCLUDE = -I./src/Graphics -I./src/System -I./src/ -I./src/Math -I./glad/
DEFINE = -DWIDTH=720 -DHEIGHT=480

build:
	g++ $(PROJECT_INCLUDE) $(DEFINE) $(GLAD) $(ASSETS) -oNEONEngine src/main.cpp $(GLFW_COMMANDS)
debug:
	g++ -Wall -DDEBUG $(DEFINE) $(GLAD) $(PROJECT_INCLUDE) -oNEONEngine src/main.cpp $(GLFW_COMMANDS)

test: debug
	clear 
	./'NEON Engine'
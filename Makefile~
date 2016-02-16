CC = g++
LDLIBS = -lglut -lGL -lGLU -lX11 -lm `sdl-config --cflags --libs`  -lSDL_mixer 
OBJ = Game.cpp \
      Car.cpp \
      ImageLoader.cpp \
      Jukebox.cpp \
		Obstacle.cpp
      
All: $(OBJ)
	$(CC) $(OBJ)  $(LDLIBS) -o game

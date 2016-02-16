#ifndef PLAYER_H_
#define PLAYER_H_

//#include "Jukebox.h"
#include <GL/freeglut.h>
#include "Obstacle.h"
class Obstacle;

class Player {  
   private:
    int m_x;  
    int m_y; 
    int m_size;
    int m_direction;//0=up,1=right,2=down,3=left
    int m_arraypos;
    float m_speed;
    
    bool stopup,stopdown,stopright,stopleft;

    GLuint m_PlayerTexture;   

   public:
    bool c_up, c_left, c_down, c_right;
    void left ();
    void right ();
    void up ();
    void down ();
    void attack ();
    void honk ();
    void display ();
    void displayTexture ();
    void update (Obstacle *obstacle[],int size, int quad);
    void collisions(int xpos, int ypos, int width, int height, int cond, int quad);
    void init();
    Player(int x = 500, int y = 500);
};

#endif /* Player_H_ */

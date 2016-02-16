// **********************************************
// Filename: Obstacle.h
// Author: Nathan Hogman
// Date: 2016-02-01
// Class: CSCI 331
// Project: Kitty Pirateer
// 
// Purpose: Parent class for obstacles found in the games 2D top down maps . 
// These obstacles as of now will all be simple rectangular structure.
// though they can be combined to form other more complex shapes. 
//
// For each map we will be building an list or array of these structures 
// unique to each tile that is displayed at a time
//    
// ************************************************



#ifndef OBSTACLE_H_
#define OBSTACLE_H_

#include "GameObject.h"
#include "Car.h"
class Car;

class Obstacle: public GameObject {

private:
	int m_x, m_y, m_width, m_height;
	int m_cond;
    
public:
	int getX() {return m_x;};
    int getY() {return m_y;};
    int getW() {return m_width;};
    int getH() {return m_height;};
    int getC() {return m_cond;};
	
	void update (){};
	void display (){};
	bool collide (Car *C){};
	Obstacle(int x, int y, int w, int h, int c);
   Obstacle(){};
	
};

#endif /*OBSTACLE_H_*/

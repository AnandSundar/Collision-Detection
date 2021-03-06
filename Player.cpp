#include "Player.h"
#include "Jukebox.h"
#include <GL/glut.h>    /* glut.h includes gl.h and glu.h */
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <GL/freeglut.h>
#include <iostream>

#include "ImageLoader.h" 
#include "Game.h"

class ImageLoader;

void Player::left ()
{
   if(!stopleft){
      m_arraypos = Game::getInstance().getArrayPos();
    
   	if(m_x-5 <= 0)
   	{
      	if(Game::getInstance().getArrayPos() != 3 && Game::getInstance().getArrayPos() != 1){
      		m_arraypos -= 1;
         	Game::getInstance().changeScreen(m_arraypos);
         	Game::getInstance().setArrayPos(m_arraypos);
	      	m_x = 968 ;
      	}
   	}else{
	   	m_x -= 4*m_speed;
   	}
   }
   m_direction = 3;
   m_PlayerTexture= ImageLoader::LoadTexture( "./imgs/Left.bmp" );
}
void Player::right ()
{
   if(!stopright){
      m_arraypos = Game::getInstance().getArrayPos();

   	if(m_x+55 >= 1023)
   	{
      	if(Game::getInstance().getArrayPos() != 2 && Game::getInstance().getArrayPos() != 4){
      		m_arraypos +=1;
	      	Game::getInstance().changeScreen(m_arraypos);
         	Game::getInstance().setArrayPos(m_arraypos);
	      	m_x = 5;
      	}
   	}else{
			m_x += 4*m_speed;
   	}
   }
   m_direction = 1;
   m_PlayerTexture= ImageLoader::LoadTexture( "./imgs/Right.bmp" );
}
void Player::up ()
{
   if(!stopup){
      m_arraypos = Game::getInstance().getArrayPos();

  		if(m_y+60 >= 731)
  		{
      	if(Game::getInstance().getArrayPos() != 1 && Game::getInstance().getArrayPos() != 2){
      		m_arraypos-=2;
	      	Game::getInstance().changeScreen(m_arraypos);
         	Game::getInstance().setArrayPos(m_arraypos);
	      	m_y = 5;
     		}
  		}else{
			m_y +=4*m_speed;
		}
   }
   m_direction = 0;
	m_PlayerTexture= ImageLoader::LoadTexture( "./imgs/Up.bmp" );
}
void Player::down ()
{
   if(!stopdown){
      m_arraypos = Game::getInstance().getArrayPos();

  		if(m_y-5 <= 0)
  		{
      	if(Game::getInstance().getArrayPos() != 3 && Game::getInstance().getArrayPos() != 4){
      		m_arraypos +=2;
	      	Game::getInstance().changeScreen(m_arraypos);
         	Game::getInstance().setArrayPos(m_arraypos);
	      	m_y = 676;
      	}
   	}else{
			m_y -= 4 * m_speed;
  		}
   }
	m_direction = 2;
  	m_PlayerTexture= ImageLoader::LoadTexture( "./imgs/Down.bmp" );
}
void Player::attack ()
{
  Game::getInstance().changeScreen(1);
}
void Player::honk ()
{
  Jukebox::PlaySound("./sounds/AHH.WAV");
}

void Player::display ()
{
   displayTexture ();
}

void Player::displayTexture ()
{
   // Draw the Player
   glEnable(GL_TEXTURE_2D);
   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_REPLACE);
   glBindTexture (GL_TEXTURE_2D, m_PlayerTexture);
   ImageLoader::rectangle(m_x,m_y, 50, 50);
   glDisable(GL_TEXTURE_2D);
   glFlush();

}
void Player::update (Obstacle *ob[],int size,int quad)
{
   for(int i=0;i<size;i++){
      int xpos = ob[i]->getX();
      int ypos = ob[i]->getY();
      int width = ob[i]->getW();
      int height = ob[i]->getH();
      int cond = ob[i]->getC();

      collisions(xpos, ypos, width, height, cond,quad);
      if(stopright == true || stopleft == true||stopup==true||stopdown==true)
      	break;   
   }
}

void Player::collisions(int xpos, int ypos, int width, int height, int cond,int quad)
{
	int quadrant = Game::getInstance().getArrayPos();
	if(quadrant == quad && height > 0){
      if(m_x+5+m_size > xpos && m_x < xpos + width && m_y+m_size > ypos && m_y < ypos+height){
         stopright = true;
         m_x -=4;
      }else if(m_x+m_size > xpos && m_x-5 < xpos + width && m_y+m_size > ypos && m_y < ypos+height){
         stopleft = true;
         m_x+=4;
      }else if(m_y-5 < ypos+height  && m_y > ypos && m_x +m_size > xpos && m_x < xpos+width){
         stopdown = true;
         m_y+=4;
      }else if(m_y+m_size+5> ypos && m_y < ypos+height && m_x+m_size > xpos && m_x < xpos+width){
         stopup = true;
         m_y-=4;
      }else{
         stopright = false;
         stopleft = false;
         stopup = false;
         stopdown = false;
      }
	}else if(quadrant == quad && height == 0){
		float circledistancex = abs(xpos - (m_x + (m_size/2)));
		float circledistancey = abs(ypos - (m_y + (m_size/2)));
		float corner = pow((circledistancex - m_size/2),2) +
							pow((circledistancey - m_size/2),2);
		if(circledistancex > (m_size/2 + width)){	
			//m_speed = 1;
		}else if(circledistancey > (m_size/2 + width)){	
			//m_speed = 1;
		}else if(circledistancex <= (m_size/2)){
      	//m_speed = 0.5;
      	if(c_up){
      		m_y -=4;
      	}
      	if(c_right){
      		m_x -=4;
      	}
      	if(c_down){
      		m_y +=4;
      	}
      	if(c_left){
      		m_x +=4;
      	}
		}else if(circledistancey <= (m_size/2)){
			//m_speed = 0.5;
			if(c_up){
      		m_y -=4;
      	}
      	if(c_right){
      		m_x -=4;
      	}
      	if(c_down){
      		m_y +=4;
      	}
      	if(c_left){
      		m_x +=4;
      	}
		}else if(corner <=pow(width,2)){
			//m_speed = 0.5;
      	if(c_up){
      		m_y -=4;
      	}
      	if(c_right){
      		m_x -=4;
      	}
      	if(c_down){
      		m_y +=4;
      	}
      	if(c_left){
      		m_x +=4;
      	}
		}
	}
}

void Player::init()
{
  m_PlayerTexture= ImageLoader::LoadTexture( "./imgs/Up.bmp" );
}


Player::Player(int x, int y)
{
	c_up=false;
	c_down=false;
	c_left=false;
	c_right=false;
   m_x=x;
   m_y=y;
   m_direction = 2;
   m_arraypos = 0;
   m_speed = 1;
   m_size = 48;
   stopright=false;
   stopleft=false;
   stopup=false;
   stopdown=false;
}


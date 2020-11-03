#ifndef obstacle_cpp
#define obstacle_cpp

#include "../drawable.h"

class Obstacle:  public Drawable{
    public:     
        Obstacle(Vec3 position): Drawable(position){}
        Obstacle(double x, double y, double z):Obstacle(Vec3{x,y,z}){}
        Obstacle():Obstacle(0,0,0){}
        
        void render(){
            //cout << "displaying obstacle [" << id << "] at: (" << position->to_string() << ")" << endl; 
            
            //save changes up to now
            glPushMatrix();
                glMatrixMode(GL_MODELVIEW);

                //glColor3f(0.8f, 0.1f, 0.1f);
                glTranslatef(position->x, position->y, position->z);
                //glRotatef(0, 0, 0, 0);
                //glutSolidCube(0.1f);
                glutSolidSphere(0.2f, 10, 10);
            //load old changes
            glPopMatrix();
        }
};

#endif
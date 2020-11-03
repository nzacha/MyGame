#ifndef player_cpp
#define player_cpp

#include "../drawable.h"

class Player : public Drawable{
    public:     
        Player(Vec3 position): Drawable(position){}
        Player(double x, double y, double z):Drawable(Vec3{x,y,z}){}
        Player():Player(0,0,0){}
        
        void render(){
            //cout << "displaying player at: (" << position->to_string() << ")" << endl; 
            
            //save changes up to now
            glPushMatrix();
                glMatrixMode(GL_MODELVIEW);

                //glColor3f(0.8f, 0.1f, 0.1f);
                glTranslatef(position->x, position->y, position->z);
                //glRotatef(0, 0, 0, 0);
                //glutSolidCube(0.1f);
                glutSolidSphere(0.5f, 10, 10);
            //load old changes
            glPopMatrix();
        }
};

#endif
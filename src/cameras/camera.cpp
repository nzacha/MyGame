#ifndef camera_cpp
#define camera_cpp

#include "../objects/drawable.h"

class Camera : public Drawable{
    public:
        Camera(Vec3 position): Drawable(position){
            lookAtTarget = false;
        }
        Camera(double x, double y, double z):Camera(Vec3{x,y,z}){}
        Camera():Camera(0,0,0){}

        void turnTo(Vec3 newTarget){
            if(lookAtTarget){
                lookTarget->update(newTarget);
            }else{
                lookDirection->update(newTarget - (*position));
                
                glMatrixMode(GL_MODELVIEW);
                //glLoadIdentity(); //Reset the drawing perspective
                //set camera position
                gluLookAt(position->x, position->y, position->z,
                    lookDirection->x, lookDirection->y, lookDirection->z,
                    up.x, up.y, up.z);
                horizontalAngle = lookDirection->z ==  0  ? 0 : atan(lookDirection->x / lookDirection->z);
                verticalAngle = lookDirection->z ==  0  ? 0 : atan(lookDirection->y / lookDirection->z);
                //cout << "look direction: " << lookDirection->to_string() << " - hangle: " << horizontalAngle << " - vangle: " << verticalAngle << endl;
            }
        }  

        void retarget(){
            if(lookAtTarget){
                glMatrixMode(GL_MODELVIEW);
                //glLoadIdentity(); //Reset the drawing perspective
                //set camera position
                gluLookAt(position->x, position->y, position->z,
                    lookTarget->x, lookTarget->y, lookTarget->z,
                    up.x, up.y, up.z);
            }else{
                horizontalAngle += turnSpeed * 0.1f * (offset_x);
                verticalAngle += turnSpeed * 0.1f * (offset_y);
                
                lookDirection->update(cos(verticalAngle) * sin(horizontalAngle), sin(verticalAngle), cos(verticalAngle) * cos(horizontalAngle));
                rightDirection->update(sin(horizontalAngle - 3.14f/2.0f), 0, cos(horizontalAngle - 3.14f/2.0f));
                upDirection->update(cross(*rightDirection, *lookDirection));

                glMatrixMode(GL_MODELVIEW);
                //glLoadIdentity(); //Reset the drawing perspective
                //set camera position
                gluLookAt(position->x, position->y, position->z,
                    position->x+lookDirection->x, position->y+lookDirection->y, position->z+lookDirection->z,
                    up.x, up.y, up.z);
            }
        }    

        void render(){
            //cout << "Camera is at: " << position->to_string() << endl;
            retarget();
        }
};

#endif
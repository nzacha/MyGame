#ifndef moveable_cpp
#define moveable_cpp

#include "../engine/types/vec3.h"

class Object{
    protected:
        bool lookAtTarget = true; 
        Vec3 *position = new Vec3(0,0,0) , *lookTarget = new Vec3(0,0,0);
        Vec3 *lookDirection = new Vec3(0,0,0), *rightDirection = new Vec3(1,0,0), *upDirection = new Vec3(0,1,0);
        float horizontalAngle = 0.0f, verticalAngle = 0.0f;
        float speed = 1.0f, turnSpeed = 0.005f;

        string name;
        
        Object(){}
        Object(Vec3 newPosition){
            this->position = new Vec3(newPosition.x, newPosition.y, newPosition.z);
        }

        public:
        void move(Vec3 offset){
            (*this->position) += offset;
        }

        void move(float x, float y, float z){
            (*this->position) += Vec3{x,y,z};
        }

        void moveTo(Vec3 newPosition){
            this->position->update(newPosition);
        }

        void moveTo(float x, float y, float z){
            this->position->update(x,y,z);
        }

        void moveTowards(Vec3 direction){
            (*this->position) += direction * deltaTime * speed;
        }

        void moveForward(){
            (*this->position) += (*lookDirection) * deltaTime * speed;
        }

        void moveBackwards(){
            (*this->position) -= (*lookDirection) * deltaTime * speed;
        }

        void moveRight(){
            (*this->position) += (*rightDirection) * deltaTime * speed;
        }

        void moveLeft(){
            (*this->position) -= (*rightDirection) * deltaTime * speed;
        }

        void moveUp(){
            (*this->position) += (*upDirection) * deltaTime * speed;
        }

        void moveDown(){
            (*this->position) -= (*upDirection) * deltaTime * speed;
        }

        void turnTo(Vec3 newTarget){
            if(lookAtTarget){
                lookTarget->update(newTarget);
            }else{
                lookDirection->update(newTarget - (*position));
            }
        }  

        Vec3* getPosition(){
            return position;
        }

        string to_string(){
            stringstream ss;
            ss << position->to_string() << flush;
            return ss.str();
        }
};
#endif
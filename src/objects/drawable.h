#ifndef drawable_cpp
#define drawable_cpp

#include <GL/glut.h>
#include "object.cpp"

int d_id = 0;
class Drawable : public Object{
    public:
        virtual void render() = 0;
        int id = d_id++;

        Drawable(Vec3 position) : Object(position){}
        Drawable(double x, double y, double z):Drawable(Vec3{x,y,z}){}
        Drawable():Drawable(0,0,0){}
};

#endif
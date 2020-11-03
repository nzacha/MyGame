#ifndef light_cpp
#define light_cpp

class Light : public Object{
    public:
        Light(Vec3 position):Object(position){
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, default_mat_specular);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, default_mat_shininess);

            glLightfv(GL_LIGHT0, GL_POSITION, default_light_position);
        }
        Light(double x, double y, double z):Light(Vec3{x,y,z}){}
        Light():Light(Vec3{0,0,0}){}
};

#endif
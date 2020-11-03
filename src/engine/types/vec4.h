#ifndef vec4_cpp
#define vec4_cpp

class Vec4{
    public:

    double x,y,z,w;    
    Vec4(double x, double y, double z, double w){
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    }

    Vec4():Vec4(0,0,0,0){}

    Vec4 operator+=(const Vec4 other){
      this->x += other.x;
      this->y += other.y;
      this->z += other.z;
      this->w += other.w;
      return *this;
    }

    Vec4 operator-=(const Vec4 other){
      this->x -= other.x;
      this->y -= other.y;
      this->z -= other.z;
      this->w -= other.w;
      return *this;
    }

    void update(double x, double y, double z, double w){
      this->x = x;
      this->y = y;
      this->z = z;
      this->w = w;
    }

    string to_string(){
      stringstream ss;
      ss << "[" << x << "," << y << "," << z << "," << w << "]" << flush;
      return ss.str();
    }
};
#endif
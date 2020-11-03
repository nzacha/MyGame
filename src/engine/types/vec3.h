#ifndef vec3_cpp
#define vec3_cpp

class Vec3{
    public:

    double x,y,z;    
    Vec3(double x, double y, double z){
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Vec3():Vec3(0,0,0){}

    Vec3 operator+=(const Vec3 other){
      this->x += other.x;
      this->y += other.y;
      this->z += other.z;
      return *this;
    }

    Vec3 operator-=(const Vec3 other){
      this->x -= other.x;
      this->y -= other.y;
      this->z -= other.z;
      return *this;
    }

    Vec3 operator*(const double other){
      this->x * other;
      this->y * other;
      this->z * other;
      return *this;
    }

    Vec3 operator*(const Vec3 other){
      this->x * other.x;
      this->y * other.y;
      this->z * other.z;
      return *this;
    }

    Vec3 operator+(const Vec3 other){
      return Vec3{x + other.x, y + other.y, z + other.z};
    }
    
    Vec3 operator-(const Vec3 other){
      return Vec3{x - other.x, y - other.y, z - other.z};
    }

    void normalize(){
      double max = x;
      if(y > max) max = y;
      if(z > max) max = z;
      
      x /= max;
      y /= max;
      z /= max;
    }

    void update(double x, double y, double z){
      this->x = x;
      this->y = y;
      this->z = z;
    }

    void update(Vec3 other){
      this->x = other.x;
      this->y = other.y;
      this->z = other.z;
    }

    string to_string(){
      stringstream ss;
      ss << "[" << x << "," << y << "," << z << "]" << flush;
      return ss.str();
    }
};

Vec3 up = {0,1,0};
Vec3 right = {1,0,0};
Vec3 down = {0,-1,0};
Vec3 left = {-1,0,0};

Vec3 cross(Vec3 A, Vec3 B){
  return Vec3{A.y * B.z - B.y * A.z, A.z * B.x - B.z * A.x, A.x * B.y - B.x * A.y};
}
#endif
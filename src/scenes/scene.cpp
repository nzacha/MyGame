#ifndef scene_cpp
#define scene_cpp

#include "../engine/types/vec3.h"
#include "../objects/drawable.h"
#include "../cameras/camera.cpp"
#include "../lights/light.cpp"
#include "../objects/entities/player.cpp"

class Scene : Drawable{
    public:
        Light* directional_light = new Light(default_light_position[0], default_light_position[1], default_light_position[2]);
        Camera* main_camera;
        Player* player;

        list<Drawable*> objects;

        //Default Constructor
        Scene(){
            glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, default_mat_specular);
            glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, default_mat_shininess);
            GLfloat position[] = {(GLfloat)directional_light->getPosition()->x, (GLfloat)directional_light->getPosition()->y, (GLfloat)directional_light->getPosition()->z, 0.0};
            glLightfv(GL_LIGHT0, GL_POSITION, position);

            glEnable(GL_LIGHTING);    
            glEnable(GL_LIGHT0);
        }

        void addObject(Drawable* obj){
            objects.push_back(obj);
        }

        void render(){
            if(main_camera)
                main_camera->render();
            if(player)
                player->render();
            for(Drawable* obj: objects){
                obj->render();
            }
        }
};

#endif
#ifndef freeroam_cpp
#define freeroam_cpp

#include <vector>

#include "gamestate.h"
#include "../../cameras/camera.cpp"
#include "../../objects/entities/player.cpp"
#include "../../objects/entities/obstacle.cpp"
#include "../../scenes/scene.cpp"

class FreeRoam : public GameState{
    public:
        Scene* scene;

        FreeRoam(){
            //make a new free roam scene
            scene = new Scene();
            scene->main_camera = new Camera(Vec3{0,50,-900}); 
            scene->main_camera->turnTo(Vec3{0,0,0});
            scene->player = new Player();
            
            vector<Vec3> items;
            items.push_back(Vec3{0,0,5});
            items.push_back(Vec3{5,0,5});
            items.push_back(Vec3{5,0,0});
            items.push_back(Vec3{5,0,-5});
            items.push_back(Vec3{0,0,-5});
            items.push_back(Vec3{-5,0,-5});
            items.push_back(Vec3{-5,0,0});
            items.push_back(Vec3{-5,0,5});
            
            for(Vec3 v: items){
                //add an obstacle to the scene
                Drawable* obj = new Obstacle();
                obj->moveTo(v);
                scene->addObject(obj);
                //cout << "Object " << obj->to_string() << " added" << endl;
            }
        }
        
        void update_physics(){
            Camera* camera = scene->main_camera;
            
            //WASD handlers
            if(key_handlers[KEY_W]){
                camera->moveForward();
            }
            if(key_handlers[KEY_A]){
                camera->moveLeft();
            }
            if(key_handlers[KEY_S]){
                camera->moveBackwards();
            }
            if(key_handlers[KEY_D]){
                camera->moveRight();
            }
            if(key_handlers[KEY_R]){
                camera->turnTo(Vec3{0,0,0});
                key_handlers[KEY_R] = false;
            }
        }

        //renders with specified state
        void render_state(int value){
            //draw scene
            scene->render();
        }
        
        //Called by glutPostRedisplay();
        void display_func(){
            glShadeModel(GL_SMOOTH);
            glEnable(GL_FRAMEBUFFER_SRGB);
            glEnable(GL_DEPTH_TEST);
            glDepthFunc(GL_LESS);
            glDepthMask(GL_TRUE);

            glEnable(GL_ALPHA_TEST);
            glAlphaFunc(GL_GREATER, 0.9f); 
            
            glEnable(GL_CULL_FACE);
            glCullFace(GL_BACK);
            
            glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
            glDepthRange(0.1f, 1.0f);

            glutSetCursor(GLUT_CURSOR_NONE);
            
            cout << "calling display funct" << endl;
            //render frame
            glutTimerFunc((1000 / GAME_FPS), GameManager::render_frame, 0); 
        }
        
        //Called when idle
        void idle_func(){}

        //Called when key is pressed
        void key_pressed(unsigned char key, int x, int y){
            switch (key){
                case 'w':
                    key_handlers[KEY_W] = true;
                    return;
                case 'a':
                    key_handlers[KEY_A] = true;
                    return;
                case 's':
                    key_handlers[KEY_S] = true;
                    return;
                case 'd':
                    key_handlers[KEY_D] = true;
                    return;
                case 'f':
                    key_handlers[KEY_F] = true;
                    return;
                case 'c':
                    key_handlers[KEY_C] = true;
                    return;
                case 'r':
                    key_handlers[KEY_R] = true;
                    return;
                default:
                    return;
            }
        }

        //Called when key is pressed
        void key_released(unsigned char key, int x, int y){
            switch (key){
                case 'w':
                    key_handlers[KEY_W] = false;
                    return;
                case 'a':
                    key_handlers[KEY_A] = false;
                    return;
                case 's':
                    key_handlers[KEY_S] = false;
                    return;
                case 'd':
                    key_handlers[KEY_D] = false;
                    return;
                case 'f':
                    key_handlers[KEY_F] = false;
                    return;
                case 'c':
                    key_handlers[KEY_C] = false;
                    return;
                case 'r':
                    key_handlers[KEY_R] = false;
                    return;
                default:
                    return;
            }
        }

        //Called when a special key is pressed
        void special_key_pressed(int key, int x, int y){
            switch (key){
                case GLUT_KEY_UP:
                    key_handlers[KEY_ARROW_UP] = true;
                    return;
                case GLUT_KEY_RIGHT:
                    key_handlers[KEY_ARROW_RIGHT] = true;
                    return;
                case GLUT_KEY_DOWN:
                    key_handlers[KEY_ARROW_DOWN] = true;
                    return;
                case GLUT_KEY_LEFT:
                    key_handlers[KEY_ARROW_LEFT] = true;
                    return;

                default:
                    return;
            }
        }

        //Called when a special key is released
        void special_key_released(int key, int x, int y){
            switch (key){
                case GLUT_KEY_UP:
                    key_handlers[KEY_ARROW_UP] = false;
                    return;
                case GLUT_KEY_RIGHT:
                    key_handlers[KEY_ARROW_RIGHT] = false;
                    return;
                case GLUT_KEY_DOWN:
                    key_handlers[KEY_ARROW_DOWN] = false;
                    return;
                case GLUT_KEY_LEFT:
                    key_handlers[KEY_ARROW_LEFT] = false;
                    return;

                default:
                    return;
            }
        }

        //Called when mouse is dragged
        void mouse_dragged(int x, int y){
            //cout << "mouse dragged (" << x << "," << y << ")" << endl;
        }

        //Called when mouse is moved
        void mouse_moved(int x, int y){
            cout << "mouse moved (" << x << "," << y << ") -> (" << x-center_x << "," << y-center_y << ")"<< endl;
            offset_x = center_x - x;
            offset_y = center_y - y; 

            prev_x = x;
            prev_y = y;
        }

        //Called when mouse is pressed
        void mouse_pressed(int button, int state, int x, int y){
            //cout << "mouse pressed (" << button << ") , ( " << state << ") -> (" << x << "," << y << ")" << endl;
        }
};

#endif
#ifndef gamestate_cpp
#define gamestate_cpp

#include "../main.h"

class GameState : public InputHandler{};

namespace GameManager{
    GameState* active_gamestate;
    
    int oldTimeSinceStart = 0;
    void update_physics(int value){
        int timeSinceStart = glutGet(GLUT_ELAPSED_TIME);
        deltaTime = (timeSinceStart - oldTimeSinceStart) / 1000.0;
        oldTimeSinceStart = timeSinceStart;
        
        active_gamestate->update_physics();
        glutTimerFunc((1000 / GAME_TICS), update_physics, 0);
    }

    void render_frame(int value){     
        glLoadIdentity();
        //warp pointer to center of window
        glutWarpPointer(center_x, center_y);
        //Clear information from last draw
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearDepth(1.0f);            

        //Render gamestate
        active_gamestate->render_state(0);
        //flush buffer
        glFlush();
        //swap buffers
        glutSwapBuffers();
        //call func again after certain frame time
        glutTimerFunc((1000 / GAME_FPS), GameManager::render_frame, 0);
    }

    //Called by glutPostRedisplay(); 
    static void display_func_callback(){
        active_gamestate->display_func();
    }

    static void idle_func_callback(){
        active_gamestate->idle_func();
    }

    static void keyboard_func_callback(unsigned char key, int x, int y){
        active_gamestate->key_pressed(key, x, y);
    }
    
    static void keyboard_up_func_callback(unsigned char key, int x, int y){
        active_gamestate->key_released(key, x, y);
    }

    static void special_key_func_callback(int key, int x, int y){
        active_gamestate->special_key_pressed(key, x, y);
    }

    static void special_key_up_func_callback(int key, int x, int y){
        active_gamestate->special_key_released(key, x, y);
    }

    static void mouse_dragged_func_callback(int x, int y){
        active_gamestate->mouse_dragged(x, y);
    }

    static void mouse_moved_func_callback(int x, int y){
        active_gamestate->mouse_moved(x, y);
    }

    static void mouse_pressed_func_callaback(int button, int state, int x, int y){
        active_gamestate->mouse_pressed(button, state, x, y);
    }

    //set glut callback funcs   
    void setCallBackFuncs(){
        //set display renderer
        glutDisplayFunc(display_func_callback);
        //glutReshapeFunc(handle_resize);
        glutIdleFunc(idle_func_callback);

        glutMouseFunc(mouse_pressed_func_callaback); 
        glutMotionFunc(mouse_dragged_func_callback);
        glutPassiveMotionFunc(mouse_moved_func_callback);

        glutKeyboardFunc(keyboard_func_callback);
        glutKeyboardUpFunc(keyboard_up_func_callback);
        glutSpecialFunc(special_key_func_callback);
        glutSpecialUpFunc(special_key_up_func_callback);
    }
}

#endif
#include "main.h"

void init_window(){
    cout << "initializing window" << endl;

    glutInitDisplayMode(GLUT_SINGLE | GLUT_DEPTH);
    glutInitWindowSize(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT);
    glutInitWindowPosition(DEFAULT_WINDOW_POS_X, DEFAULT_WINDOW_POS_Y);
    glutCreateWindow(WINDOW_NAME); 
}

void initGL(){     
    glClearColor(1, 1, 1, 1);

    glViewport(0,0, DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT);  

    //set projection frustrum
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(0.45f, DEFAULT_WINDOW_WIDTH * 1.0f / DEFAULT_WINDOW_HEIGHT, 10.0f, 1000.0f);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    
    //init window
    init_window();

    //init gl and light
    initGL();

    GameManager::active_gamestate = new FreeRoam();
    GameManager::setCallBackFuncs();
    GameManager::update_physics(0);

    //start glut game loop    
    glutMainLoop();

    return 0;
}
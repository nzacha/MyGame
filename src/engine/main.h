#ifndef main_h
#define main_h

using namespace std;

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <math.h>

#include "types/consts.h"
#include "types/vec3.h"
#include "types/vec4.h"

double deltaTime = 1000.0 / GAME_FPS;

//Camera movement
int offset_x = 0, offset_y = 0;
int prev_x = 0, prev_y = 0;
int center_x = DEFAULT_WINDOW_WIDTH/2, center_y = DEFAULT_WINDOW_HEIGHT/2;

#include "gamestates/inputhandler.h"
#include "gamestates/gamestate.h"
#include "gamestates/freeroam.cpp"

#include "../objects/object.cpp"
#include "../objects/drawable.h"
#include "../objects/entities/obstacle.cpp"
#include "../objects/entities/player.cpp"
#include "../cameras/camera.cpp"
#include "../lights/light.cpp"
#include "../scenes/scene.cpp"

void key_pressed(unsigned char key, int x, int y);
void special_key_pressed(int key, int x, int y);
void mouse_dragged(int x, int y);
void mouse_moved(int x, int y);
void mouse_pressed(int button, int state, int x, int y);
void idle();
void render_frame(int value);
void display_func();
void init_display();

#endif
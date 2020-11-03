#ifndef inputhandler_cpp
#define inputhandler_cpp

#include "../main.h"
 
#define KEY_Q 0
#define KEY_W 1
#define KEY_E 2
#define KEY_R 3 
#define KEY_T 4
#define KEY_Y 5
#define KEY_U 6
#define KEY_I 7
#define KEY_O 8
#define KEY_P 9
#define KEY_A 10
#define KEY_S 11
#define KEY_D 12
#define KEY_F 13
#define KEY_G 14
#define KEY_H 15
#define KEY_J 16
#define KEY_K 17
#define KEY_L 18
#define KEY_Z 19
#define KEY_X 20
#define KEY_C 21
#define KEY_V 22
#define KEY_B 23
#define KEY_N 24
#define KEY_M 25
#define KEY_NUMBER_1 26
#define KEY_NUMBER_2 27
#define KEY_NUMBER_3 28
#define KEY_NUMBER_4 29
#define KEY_NUMBER_5 30
#define KEY_NUMBER_6 31
#define KEY_NUMBER_7 32
#define KEY_NUMBER_8 33
#define KEY_NUMBER_9 34
#define KEY_NUMBER_0 35
#define KEY_SPACE 36
#define KEY_ENTER 37
#define KEY_ESCAPE 38
#define KEY_HYPHEN 39
#define KEY_BACKSPACE 40
#define KEY_DELETE 41
#define KEY_ARROW_UP 42
#define KEY_ARROW_RIGHT 43
#define KEY_ARROW_DOWN 44
#define KEY_ARROW_LEFT 45
#define KEY_LEFT_SHIFT 46
#define KEY_LEFT_CTRL 47
#define KEY_LEFT_ALT 48
#define KEY_TAB 49
#define KEY_RIGHT_SHIFT 50
#define KEY_RIGHT_CTRL 51
#define KEY_RIGHT_ALT 52
#define KEY_COMMA 53
#define KEY_FULLSTOP 54
#define KEY_PAGE_UP 55
#define KEY_PAGE_DOWN 56

#define MOUSE_LEFT_DOWN 57
#define MOUSE_MIDDLE_DOWN 58
#define MOUSE_RIGHT_DOWN 59

bool key_handlers[60] = {false};

class InputHandler{
    public:
        virtual void update_physics() = 0;
        virtual void render_state(int value) = 0;
        virtual void display_func() = 0;
        virtual void idle_func() = 0;
        virtual void key_pressed(unsigned char key, int x, int y) = 0;
        virtual void key_released(unsigned char key, int x, int y) = 0;
        virtual void special_key_pressed(int key, int x, int y) = 0;
        virtual void special_key_released(int key, int x, int y) = 0;
        virtual void mouse_dragged(int x, int y) = 0;
        virtual void mouse_moved(int x, int y) = 0;
        virtual void mouse_pressed(int button, int state, int x, int y) = 0;
};

#endif
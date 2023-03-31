#include "main.h" 
 
// define motor ports 
#define LEFT_FRONT_PORT 1 
#define LEFT_MIDDLE_PORT 2 
#define LEFT_BACK_PORT 3 
#define RIGHT_FRONT_PORT 4 
#define RIGHT_MIDDLE_PORT 5 
#define RIGHT_BACK_PORT 6 
 
// create motor objects 
pros::Motor left_front(LEFT_FRONT_PORT, pros::E_MOTOR_GEARSET_18, false); 
pros::Motor left_middle(LEFT_MIDDLE_PORT, pros::E_MOTOR_GEARSET_18, false); 
pros::Motor left_back(LEFT_BACK_PORT, pros::E_MOTOR_GEARSET_18, false); 
pros::Motor right_front(RIGHT_FRONT_PORT, pros::E_MOTOR_GEARSET_18, true); 
pros::Motor right_middle(RIGHT_MIDDLE_PORT, pros::E_MOTOR_GEARSET_18, true); 
pros::Motor right_back(RIGHT_BACK_PORT, pros::E_MOTOR_GEARSET_18, true); 
 
void opcontrol() { 
    while (true) { 
        // get joystick values for forward/backward and turning movements 
        int forward = pros::Controller(pros::E_CONTROLLER_MASTER).get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y); 
        int turn = pros::Controller(pros::E_CONTROLLER_MASTER).get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X); 
 
        // calculate motor speeds for tank drive control 
        int left_speed = forward + turn; 
        int right_speed = forward - turn; 
 
        // set motor speeds for all six wheels 
        left_front.move(left_speed); 
        left_middle.move(left_speed); 
        left_back.move(left_speed); 
        right_front.move(right_speed); 
        right_middle.move(right_speed); 
        right_back.move(right_speed); 
 
        pros::delay(20); // delay to prevent hogging CPU resources 
    } 
} 
/* ------------------------------------------------------------------------ */
/*																			*/
/*		Module:			autos.cpp											*/
/*		Author: 		Ayaan Goswami (285C)								*/
/*		Created: 		July 2, 2026										*/
/* 		Description:	Competition Template								*/
/*																			*/
/* ------------------------------------------------------------------------ */

#include "main.h"
#include "lemlib/api.hpp"
#include "robot/odometry.h"
#include "robot/functions.h"
#include "robot/autos.h"

/**
 * @brief runs the skip autonomous.
 *
 * Write any minimal movement that fulfills AWP while teammate runs a SAWP
 */
void skip(){}

/**
 * @brief runs the programming skills autonomous.
 *
 * Write your skills autonomous code here.
 */
void skills(){}

/* write any other autonomous routines here */

/**
 * @brief displays auton selector so user can select autos from one program
 *
 * Change to accomodate your number and types of autonomous routines
 */
void autonSelector(void*){
    // initialize variables
    int autonomousType = 0;             // skills, skip, left, right
    autonomousSelection = -1;           // default autonomous selection
    bool autonTypeSelected = false;     // initially unselected
    bool autonSelected = false;         // initially unselected

    Button autonType[] = {
        /*  Button(x, y, width, height, text, bg_color, text_color)  */

        /* ---------------------------------------------------------------------------------------- */
        /*  BASIC EXAMPLE:                                                                          */
        /*                                                                                          */
        /*  Button(10, 10, 225, 105, "Left", pros::Color::pale_violet_red, pros::Color::black),     */
        /*  Button(245, 10, 225, 105, "Right", pros::Color::cyan, pros::Color::black),              */
        /*  Button(10, 125, 225, 105, "Skills", pros::Color::white, pros::Color::black),            */
        /*  Button(245, 125, 225, 105, "Skip", pros::Color::light_green, pros::Color::black)        */
        /* ---------------------------------------------------------------------------------------- */

    }; // create a new selection of 4 auton types

    // gray background
    pros::screen::set_pen(pros::Color::light_gray);
    pros::screen::fill_rect(0, 0, 480, 240);
    
    // render the buttons and check for presses on the screen
    while(!autonTypeSelected){
        for(int i = 0; i < 4; i++){
            autonType[i].render();
            if(autonType[i].isClicked()){
                autonomousType = i;
                autonTypeSelected = true;
            }
        }
        pros::delay(20);
    }
    pros::screen::erase();

    Button* auton = nullptr;
    static Button leftAutons[] = {
        // up to 4 left autons
    };
    static Button rightAutons[] = {
        // up to 4 right autons
    };
    
    // based on the first selection, choose 
    switch(autonomousType){
        case 0: auton = leftAutons; break;                              // Left autons (for next selection)
        case 1: auton = rightAutons; break;                             // Right autons (for next selection)
        case 2: autonomousSelection = 0; autonSelected = true; break;   // Skills auton
        case 3: autonomousSelection = 1; autonSelected = true; break;   // Skip auton
    }

    // reset screen
    pros::screen::set_pen(pros::Color::dark_gray);

    // if auton hasn't already been selected, display new 4 buttons
    while(!autonSelected && autonTypeSelected){
        for(int i = 0; i < 4; i++){
            if(auton[i].isClicked()){
                autonomousSelection = i * 2 + 1 + autonomousType;
                auton[i].buttonColor = pros::Color::medium_violet_red;
                autonSelected = true;
            }
            auton[i].render();
        }

        pros::delay(20);
    }

    /* ------------------------------------------------------------------------ */
    /*  BY THE END OF THIS FUNCTION, autonomousSelection SHOULD BE ASSIGNED     */
    /*  A VALUE FOR USE IN main.cpp                                             */
    /* ------------------------------------------------------------------------ */
}
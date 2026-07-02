/* ------------------------------------------------------------------------ */
/*																			*/
/*		Module:			drivetrain.cpp										*/
/*		Author: 		Ayaan Goswami (285C)								*/
/*		Created: 		July 2, 2026										*/
/* 		Description:	Competition Template								*/
/*																			*/
/* ------------------------------------------------------------------------ */

#include "main.h"
#include "lemlib/api.hpp"
#include "robot/drivetrain.h"

/* creation of drivetrain motor groups */
// note that ports can be negative (positive = counterclockwise, negative = clockwise)
pros::MotorGroup left_mg({/* DEFINE YOUR PORTS HERE */}, pros::MotorGearset::blue);     // left motor group
pros::MotorGroup right_mg({/* DEFINE YOUR PORTS HERE */}, pros::MotorGearset::blue);    // right motor group

/* creation of drivetrain */
lemlib::Drivetrain drivetrain(&left_mg,                     // left motor group
                              &right_mg,                    // right motor group
                              0,                            // ____ inch track width
                              lemlib::Omniwheel::NEW_325,   // using new 3.25" omnis
                              0,                            // drivetrain rpm (___ = ___rpm * (__/__ gear ratio))
                              0                             // horizontal drift (8 if traction wheels, 2 otherwise)
);
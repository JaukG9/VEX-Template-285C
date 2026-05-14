#include "main.h"
#include "lemlib/api.hpp"
#include "robot/drivetrain.h"

/* creation of drivetrain motor groups */
pros::MotorGroup left_mg({}, pros::MotorGearset::blue);   // left motor group (motors spin clockwise --> wheels spin counterclockwise)
pros::MotorGroup right_mg({}, pros::MotorGearset::blue);    // right motor group (motors spin counterclockwise --> wheels spin clockwise)

/* creation of drivetrain */
lemlib::Drivetrain drivetrain(&left_mg,                     // left motor group
                              &right_mg,                    // right motor group
                              0,                            // ____ inch track width
                              lemlib::Omniwheel::NEW_325,   // using new 3.25" omnis
                              0,                            // drivetrain rpm (___ = ___rpm * (__/__ gear ratio))
                              0                             // horizontal drift (8 because of center traction wheels)
);
/* ------------------------------------------------------------------------ */
/*																			*/
/*		Module:			odometry.cpp										*/
/*		Author: 		Ayaan Goswami (285C)								*/
/*		Created: 		July 2, 2026										*/
/* 		Description:	Competition Template								*/
/*																			*/
/* ------------------------------------------------------------------------ */

#include "main.h"
#include "lemlib/api.hpp"
#include "robot/drivetrain.h"
#include "robot/odometry.h"

// odometry
pros::Imu imu(/* IMU PORT HERE, SET AS 1 FOR NOW */ 1);
/* ADD OTHER TRACKING WHEELS & ENCODERS AS NEEDED */

// odometry settings
lemlib::OdomSensors sensors(
    nullptr,                    // vertical tracking wheel 1
    nullptr,                    // vertical tracking wheel 2
    nullptr,                    // horizontal tracking wheel 1
    nullptr,                    // horizontal tracking wheel 2
    &imu                        // inertial sensor
);

/* TUNE LATERAL & ANGULAR PID THROUGH LEMLIB'S DOCS AT https://lemlib.readthedocs.io/en/stable/tutorials/4_pid_tuning.html */
//lateral PID controller
lemlib::ControllerSettings lateral_controller(0, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              0, // derivative gain (kD)
                                              0, // anti windup
                                              0, // small error range, in inches
                                              0, // small error range timeout, in milliseconds
                                              0, // large error range, in inches
                                              0, // large error range timeout, in milliseconds
                                              0  // maximum acceleration (slew)
);

// angular PID controller
lemlib::ControllerSettings angular_controller(0, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              0, // derivative gain (kD)
                                              0, // anti windup
                                              0, // small error range, in degrees
                                              0, // small error range timeout, in milliseconds
                                              0, // large error range, in degrees
                                              0, // large error range timeout, in milliseconds
                                              0  // maximum acceleration (slew)
);

// steering curve, change values until it feels right
lemlib::ExpoDriveCurve steer_curve(10,      // joystick deadband out of 127
                                   10,      // minimum output where drivetrain will move out of 127
                                   1.019   // expo curve gain
);

// chassis
lemlib::Chassis chassis(
    drivetrain,
    lateral_controller,
    angular_controller,
    sensors
);
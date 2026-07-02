/* ------------------------------------------------------------------------ */
/*																			*/
/*		Module:			main.cpp											*/
/*		Author: 		Ayaan Goswami (285C)								*/
/*		Created: 		July 2, 2026										*/
/* 		Description:	Competition Template								*/
/*																			*/
/* ------------------------------------------------------------------------ */

// include files from PROS, LemLib, and our custom files
#include "main.h"
#include "lemlib/api.hpp"
#include "robot/robot-config.h"
#include "robot/drivetrain.h"
#include "robot/functions.h"
#include "robot/odometry.h"
#include "robot/autos.h"


/* ------------------------------------------------------------------------ */
/*                       Pre-Autonomous (Initialize)                        */
/*                                                                          */
/*  You may want to perform some actions before the main program starts.    */
/*  Do them in the following function. Specifically, you can calibrate		*/
/*  and initialize the brain, any sensors, the chassis, and pneumatics.		*/
/*	This function is only called once, after the progam has started.        */
/*																			*/
/* ------------------------------------------------------------------------ */

void initialize(){
	// initialize the brain screen
	pros::lcd::initialize();

	// calibrate sensors
	chassis.calibrate();
}


/* ------------------------------------------------------------------------ */
/*                       			Disabled		                        */
/*                       							                        */
/*	Runs while the robot is in the disabled state of the Field Management	*/
/*	System or the VEX Competition Switch, following either autonomous or	*/
/*	opcontrol. When the robot is enabled, this task will exit. Use if you	*/
/*	want to update the screen or change any variables between autonomous	*/
/*	and driver control phases of the match.									*/
/*                       							                        */
/* ------------------------------------------------------------------------ */

void disabled(){}


/* ------------------------------------------------------------------------ */
/*                       	Competition Initialize                          */
/*                                                                          */
/*  You may want to perform some actions before the main program starts,    */
/*  but only in 'competition' mode. Do them in the following function		*/
/*	which will only run after initialize() and when connected with the		*/
/*	Field Management System or the VEX Competition Switch. You may want		*/
/*	to use this for competition-specific initialization routines, such		*/
/*	as an autonomous selector on the LCD.									*/
/*																			*/
/* ------------------------------------------------------------------------ */

void competition_initialize(){
	// runs the autonomous selector
	pros::Task selector(autonSelector);
}


/* ------------------------------------------------------------------------ */
/*                       	   Autonomous Task	                            */
/*                                                                          */
/* 	Runs the user autonomous code. This function will be started in its 	*/
/*	own task with the default priority and stack size whenever the robot 	*/
/*	is enabled via the Field Management System or the VEX Competition 		*/
/*	Switch in the autonomous mode. Alternatively, this function may be 		*/
/*	called in initialize or opcontrol for non-competition testing purposes.	*/
/*																			*/
/* 	You must modify the code to add your own robot specific commands here.	*/
/*																			*/
/* ------------------------------------------------------------------------ */

void autonomous(){
	// erase screen for autonomous start
	pros::screen::erase();

	// run the selected autonomous routine
	switch(autonomousSelection){
		case 0: skills(); break;
		case 1: skip(); break;
		case 2: /* call your function here */; break;
		/* add any more cases based on your number of autons */
		default: break;
	}
}


/* ------------------------------------------------------------------------ */
/*                       	  User Control Task	                            */
/*                                                                          */
/* 	Runs the operator control code. This function will be started in its 	*/
/*	own task with the default priority and stack size whenever the robot 	*/
/*	is enabled via the Field Management System or the VEX Competition 		*/
/*	Switch in the operator control mode.									*/
/*																			*/
/* 	You must modify the code to add your own robot specific commands here.	*/
/*																			*/
/* ------------------------------------------------------------------------ */

void opcontrol() {
	/* initialize any opcontrol specific variables here */


	/* run any one-time, start of opcontrol() code here */


	// infinite loop for inputs and robot control
	while (true) {
		// tank drive (you can choose to run arcade or others)
		tank();

		/* run any necessary robot functions based on controller input here */


		// 20ms downtime to prevent CPU starvation & resource exhaustion
		pros::delay(20);
	}
}
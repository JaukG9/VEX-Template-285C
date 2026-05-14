#include "main.h"
#include "lemlib/api.hpp"
#include "robot/drivetrain.h"
#include "robot/odometry.h"

// odometry
pros::Imu imu(11);
pros::Rotation vertical_sensor(2);
lemlib::TrackingWheel vertical_tracking_wheel(&vertical_sensor, 2, 0);

// odometry settings
lemlib::OdomSensors sensors(
    &vertical_tracking_wheel,   // vertical tracking wheel 1
    nullptr,                    // vertical tracking wheel 2
    nullptr,                    // horizontal tracking wheel 1
    nullptr,                    // horizontal tracking wheel 2
    &imu                        // inertial sensor
);
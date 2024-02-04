/**
 * @file devices.cpp
 * @author
 * @brief defines devices used by the robot, add new stuff here
 * @version 0.1
 * @date 2024-01-23
 * 
 * 
 */

#include "main.h"
#include "pros/adi.hpp"
#include "pros/misc.hpp"

pros::Controller ctr(pros::E_CONTROLLER_MASTER);

pros::Motor flywheel(FLYWHEEL, BLUE, REVERSED, ENCODER);
pros::Motor intake(INTAKE, GREEN, REVERSED, ENCODER);

pros::ADIDigitalOut pneum_wings(PNEUM_WINGS);
pros::ADIDigitalOut pneum_intake(PNEUM_INTAKE);
pros::ADIDigitalOut pneum_descore1(PNEUM_DESCORE1);

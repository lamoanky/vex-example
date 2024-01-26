/**
 * @file dev.hpp
 * @author 
 * @brief defines robot devices, modify definitions at devices.cpp
 * @version 0.1
 * @date 2024-01-23
 * 
 * 
 */

#ifndef __DEV_HPP__
#define __DEV_HPP__

#include "pros/motors.hpp"
#include "pros/adi.hpp"
#include "pros/misc.hpp"

#define GREEN pros::E_MOTOR_GEAR_GREEN
#define BLUE pros::E_MOTOR_GEAR_BLUE
#define RED pros::E_MOTOR_GEAR_RED

#define ENCODER pros::E_MOTOR_ENCODER_COUNTS

#define FORWARDS false
#define REVERSED true

extern pros::Controller ctr;

extern pros::Motor intake;
extern pros::Motor flywheel;

extern pros::ADIDigitalOut pneum_wings;
extern pros::ADIDigitalOut pneum_intake;

#endif
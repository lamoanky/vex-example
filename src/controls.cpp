/**
 * @file controls.cpp
 * @author
 * @brief 
 * @version 0.1
 * @date 2024-01-23
 * 
 * 
 */

#include "main.h"
#include "pros/misc.h"

// intake in l1
// intake out l2
// wings toggle r1
// intake arm toggle r2
// descore toggle a
// flywheel toggle x
// flip flywheel right button

bool pneum_intake_direction = false;
bool pneum_wings_direction = false;

void handle_input() {
    if (ctr.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
        intake = 127; // run intake at full blast
    }
    else if (ctr.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
        intake = -127;
    }
    else {
        intake = 0;
    }
}
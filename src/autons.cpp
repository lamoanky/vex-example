#include "main.h"


/////
// For instalattion, upgrading, documentations and tutorials, check out website!
// https://ez-robotics.github.io/EZ-Template/
/////


const int DRIVE_SPEED = 110; // This is 110/127 (around 87% of max speed).  We don't suggest making this 127.
                             // If this is 127 and the robot tries to heading correct, it's only correcting by
                             // making one side slower.  When this is 87%, it's correcting by making one side
                             // faster and one side slower, giving better heading correction.
const int TURN_SPEED  = 90;
const int SWING_SPEED = 90;



///
// Constants
///

// It's best practice to tune constants when the robot is empty and with heavier game objects, or with lifts up vs down.
// If the objects are light or the cog doesn't change much, then there isn't a concern here.

void default_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 6.5, 0.0015, 64, 0);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

// void one_mogo_constants() {
//   chassis.set_slew_min_power(80, 80);
//   chassis.set_slew_distance(7, 7);
//   chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
//   chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
//   chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
//   chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
//   chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
// }

// void two_mogo_constants() {
//   chassis.set_slew_min_power(80, 80);
//   chassis.set_slew_distance(7, 7);
//   chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
//   chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
//   chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
//   chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
//   chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
// }


void modified_exit_condition() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}




///
// Drive Example
///
void drive_example() {
  // The first parameter is target inches
  // The second parameter is max speed the robot will drive at
  // The third parameter is a boolean (true or false) for enabling/disabling a slew at the start of drive motions
  // for slew, only enable it when the drive distance is greater then the slew distance + a few inches


  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_drive_pid(-12, DRIVE_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-12, DRIVE_SPEED);
  chassis.wait_drive();
}



///
// Turn Example
///
void turn_example() {
  // The first parameter is target degrees
  // The second parameter is max speed the robot will drive at


  chassis.set_turn_pid(90, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();
}



///
// Combining Turn + Drive
///
void drive_and_turn() {
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_drive();
}



///
// Wait Until and Changing Max Speed
///
void wait_until_change_speed() {
  // wait_until will wait until the robot gets to a desired position


  // When the robot gets to 6 inches, the robot will travel the remaining distance at a max speed of 40
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_until(6);
  chassis.set_max_speed(40); // After driving 6 inches at DRIVE_SPEED, the robot will go the remaining distance at 40 speed
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  // When the robot gets to -6 inches, the robot will travel the remaining distance at a max speed of 40
  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_until(-6);
  chassis.set_max_speed(40); // After driving 6 inches at DRIVE_SPEED, the robot will go the remaining distance at 40 speed
  chassis.wait_drive();
}



///
// Swing Example
///
void swing_example() {
  // The first parameter is ez::LEFT_SWING or ez::RIGHT_SWING
  // The second parameter is target degrees
  // The third parameter is speed of the moving side of the drive


  chassis.set_swing_pid(ez::LEFT_SWING, 45, SWING_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_until(12);

  chassis.set_swing_pid(ez::RIGHT_SWING, 0, SWING_SPEED);
  chassis.wait_drive();
}



///
// Auto that tests everything
///
void combining_movements() {
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_swing_pid(ez::RIGHT_SWING, -45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_drive();
}



///
// Interference example
///
void tug (int attempts) {
  for (int i=0; i<attempts-1; i++) {
    // Attempt to drive backwards
    printf("i - %i", i);
    chassis.set_drive_pid(-12, 127);
    chassis.wait_drive();

    // If failsafed...
    if (chassis.interfered) {
      chassis.reset_drive_sensor();
      chassis.set_drive_pid(-2, 20);
      pros::delay(1000);
    }
    // If robot successfully drove back, return
    else {
      return;
    }
  }
}

// If there is no interference, robot will drive forward and turn 90 degrees. 
// If interfered, robot will drive forward and then attempt to drive backwards. 
void interfered_example() {
 chassis.set_drive_pid(24, DRIVE_SPEED, true);
 chassis.wait_drive();

 if (chassis.interfered) {
   tug(3);
   return;
 }

 chassis.set_turn_pid(90, TURN_SPEED);
 chassis.wait_drive();
}



// . . .
// Make your own autonomous functions here!
// . . .

void lamonky1(){

  // 5 ball
  pneum_intake.set_value(true);
  intake.move_voltage(12000);
  chassis.set_drive_pid(6, 80);
  chassis.wait_drive();

  pros::delay(750);

  //grabs the triball underneath the elevation bar

  chassis.set_drive_pid(-35, 60, true);
  chassis.wait_drive();

  chassis.set_turn_pid(-35, 127);
  chassis.wait_drive();

  chassis.set_drive_pid(-26, 80, true);
  chassis.wait_drive();

  //around here you could maybe set up the descore mech for a 6 ba;l

  chassis.set_turn_pid(90, 127);
  chassis.wait_drive();


  intake.move_voltage(-12000);  
  chassis.set_drive_pid(18, 127);
  chassis.wait_drive();

  //backs up from elevation bar, pushes alliance triball, turns around, pushes the two in

  intake.move_voltage(0);

  chassis.set_drive_pid(-11.5, 127);
  chassis.wait_drive();
  chassis.set_turn_pid(15, 127);
  chassis.wait_drive();

  intake.move_voltage(12000);
  chassis.set_drive_pid(49.5, 127, true);
  chassis.wait_drive();

  //backs up, turns to the corner triball, picks it up

  chassis.set_turn_pid(145, 127);
  chassis.wait_drive();
  chassis.set_drive_pid(25, 127, true);
  chassis.wait_drive();
  intake.move_voltage(-12000);
  chassis.set_drive_pid(-15, 127, true);
  chassis.wait_drive();

  //deposits corner triball near the net

  chassis.set_turn_pid(55, 127);
  chassis.wait_drive();  

  intake.move_voltage(12000);
  chassis.set_drive_pid(19.5, 127, true);
  chassis.wait_drive();
 
  chassis.set_turn_pid(180, 127);
  chassis.wait_drive();

  

  //grabs far middle triball, turns around

  pneum_wings.set_value(true);
  pros::delay(100);
  intake.move_voltage(-12000);
  chassis.set_drive_pid(120, 127);
  pros::delay(1000);

  pneum_wings.set_value(false);
  chassis.set_drive_pid(-15, 127);
  chassis.wait_drive();

  //extends wings and pushes the 3 triballs, backs up and closes wings
  




  // chassis.set_drive_pid(-30, DRIVE_SPEED, true);
  // chassis.wait_drive();
}

void AWPGG(){

  pneum_wings.set_value(true);
  pros::delay(500);
  pneum_wings.set_value(false);
  intake.move_voltage(12000);
  chassis.set_drive_pid(55, 127);
  chassis.wait_drive();
  chassis.set_turn_pid(80, 127);
  chassis.wait_drive();
  intake.move_voltage(-12000);
  pneum_wings.set_value(true);
  chassis.set_drive_pid(24, 127);
  chassis.wait_drive();
  pneum_wings.set_value(false);
  chassis.set_turn_pid(195, 127);
  chassis.wait_drive();
  intake.move_voltage(0);
  chassis.set_drive_pid(55, 127);
  chassis.wait_drive();
  chassis.set_turn_pid(300, 127);
  chassis.wait_drive();
  chassis.set_drive_pid(30, 80, true);
  chassis.wait_drive();
  chassis.set_turn_pid(345, 127);
  chassis.wait_drive();
  intake.move_voltage(-12000);
  chassis.set_drive_pid(7, 127);
  chassis.wait_drive();
  chassis.set_drive_pid(-10, 127);
  chassis.wait_drive();
  intake.move_voltage(0);
  chassis.set_turn_pid(480, 127);
  chassis.wait_drive();
  chassis.set_drive_pid(30, 127);
  chassis.wait_drive();
  chassis.set_turn_pid(360, 127);
  chassis.wait_drive();
  chassis.set_drive_pid(50, 127);
  chassis.wait_drive();

//   intake = 127;
//     chassis.set_drive_pid(12, 30, true);
//   chassis.wait_drive();
//   pneum_descore1.set_value(true);
//   chassis.set_drive_pid(-7.5, 60);
//   chassis.wait_drive();

//   pros::delay(250);
  
  
//   chassis.set_turn_pid(-45, 127);
//   chassis.wait_drive();
//   pros::delay(250);
//   pneum_descore1.set_value(false);
//   chassis.set_drive_pid(-13, 60, true);
//   chassis.wait_drive();  

//   chassis.set_turn_pid(45, 127);
//   chassis.wait_drive();
  

//   chassis.set_drive_pid(40, 127);
//   chassis.wait_drive();
//   chassis.set_turn_pid(-40.5, 127);
//   chassis.wait_drive();

  

//   intake = -127;

//   pros::delay(100);

//   chassis.set_drive_pid(-5, 127, true);
//   chassis.wait_drive();

//   chassis.set_turn_pid(135, 127);
//   chassis.wait_drive();

//   pneum_wings.set_value(true);
//   chassis.set_drive_pid(20, 127, true);
//   chassis.wait_drive();
//   pneum_wings.set_value(false);



//   chassis.set_drive_pid(-29, 127, true);
//   chassis.wait_drive();

//   chassis.set_drive_pid(6.5, 127);
//   chassis.wait_drive();

//   chassis.set_turn_pid(270-45, 127);
//   chassis.wait_drive();
// intake = 127;
//   chassis.set_drive_pid(48, 127);
//   chassis.wait_drive();

//   chassis.set_turn_pid(352-45, 127);
//   chassis.wait_drive();

//   chassis.set_drive_pid(-31, 127);
//   chassis.wait_drive();
}

void Iloveomnkyskill(){;

  intake.move_voltage(12000);
  chassis.set_drive_pid(24, 127);
  chassis.wait_drive();
  chassis.set_turn_pid(-105, 127);
  chassis.wait_drive();
  chassis.set_drive_pid(20, 60, true);
  chassis.wait_drive(); 
  pneum_wings.set_value(true);

  //fw for like 20-30 secs
  intake.move_voltage(0);
  flywheel.move_voltage(-12000);
  pros::delay(40000);
  flywheel.move_voltage(0);
  pneum_wings.set_value(false);
  chassis.set_turn_pid(90, 127);
  chassis.wait_drive();
  chassis.set_drive_pid(24, 127, true);
  chassis.wait_drive();
  chassis.set_turn_pid(0, 127);
  chassis.wait_drive();
  chassis.set_drive_pid(48, 127, true);
  chassis.wait_drive();
  chassis.set_turn_pid(90, 127);
  chassis.wait_drive();
  pneum_wings.set_value(true);
  chassis.set_drive_pid(1000, 127, true);
  chassis.wait_drive();
  pros::delay(1000);
  chassis.set_drive_pid(-24, 127, true);
  chassis.wait_drive();

}

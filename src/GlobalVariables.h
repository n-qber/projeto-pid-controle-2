#ifndef GLOBALVARIABLES_H
#define GLOBALVARIABLES_H

// Enum for error mode selection
enum ErrorMode {
    ANGLE = 1,
    DISTANCE = 2,
    COMBINED = 3
};

// Global variable to store the selected error mode
extern ErrorMode g_error_mode;

// Reference signal
extern double g_reference_signal;

// User input
extern double g_user_input;

// User period input
extern double g_period;

// Interlock status
extern bool g_interlock_status;

// Raw errors from sensors
extern double g_angle_error;
extern double g_distance_error;

// Combined error after user mode selection
extern double g_combined_error;

// Resultant error (reference - combined)
extern double g_resultant_error;

// PID constants
extern double g_kp, g_ki, g_kd;

// Control signal
extern double g_control_signal;

// Base velocity for the AGV
extern double g_vel_base;

#endif // GLOBALVARIABLES_H

#include "ServiceInitGlobalVariables.h"
#include "../../GlobalVariables.h"
#include <iostream>
using namespace std;

/**
 * @brief Initializes the global variables.
 * 
 * This function initializes all the global variables used in the system.
 */
void ServiceInitGlobalVariables::init_global_variables() {
    // TODO: Implement the logic to initialize the global variables.
    // Default interlock status to true
    g_interlock_status = true;

    // Default angle and distance errors
    g_angle_error = 0.0;
    g_distance_error = 0.0;

    // Initialize wheels speed to user input
    cout << "Inicializando velocidades das rodas para a velocidade base..." << endl << endl;
    wheelsSpeed.leftFront = g_vel_base;
    wheelsSpeed.rightFront = g_vel_base;
    wheelsSpeed.leftBack = g_vel_base;
    wheelsSpeed.rightBack = g_vel_base;

    cout << "Variaveis globais inicializadas." << endl;
}
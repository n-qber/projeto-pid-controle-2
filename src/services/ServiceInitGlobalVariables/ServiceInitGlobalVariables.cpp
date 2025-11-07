#include "ServiceInitGlobalVariables.h"
#include "../../GlobalVariables.h"

/**
 * @brief Initializes the global variables.
 * 
 * This function initializes all the global variables used in the system.
 */
void ServiceInitGlobalVariables::init_global_variables() {
    // TODO: Implement the logic to initialize the global variables.
    g_interlock_status = true; // Default interlock status to true
    g_angle_error = 0.0;
    
}
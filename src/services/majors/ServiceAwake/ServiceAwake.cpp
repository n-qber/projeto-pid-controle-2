#include "ServiceAwake.h"

/**
 * @brief Executes all startup services in the correct order.
 * 1. Initializes all global variables to their default states.
 * 2. Prompts the user for input (e.g., error mode selection).
 * 3. Generates the initial reference signal for the controller.
 */
void ServiceAwake::awake_all() {
    // 1. Initialize global variables
    serviceInitGlobalVariables.init_global_variables();

    // 2. Get user input
    serviceUserInput.read_user_input();

    // 3. Generate initial reference
    serviceGenerateReference.generate_reference();
}

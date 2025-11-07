#include "ServiceInputError.h"
#include "GlobalVariables.h"

/**
 * @brief Calculates the final resultant error for the PID controller.
 *
 * This function calculates the resultant error by taking the difference
 * between the reference signal (`g_reference_signal`) and the combined
 * error from the sensors (`g_combined_error`).
 * The result is stored in the global variable `g_resultant_error`.
 */
void ServiceInputError::calculate_input_error() {
    g_resultant_error = g_reference_signal - g_combined_error;
}
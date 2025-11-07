#include "ServiceCombineErrors.h"
#include "GlobalVariables.h"

/**
 * @brief Combines the raw errors based on the user-selected mode.
 *
 * This function reads `g_angle_error` and `g_distance_error` and calculates
 * `g_combined_error` based on the `g_error_mode` selection.
 *  - ANGLE: Uses only the angle error.
 *  - DISTANCE: Uses only the distance error.
 *  - COMBINED: Uses the mean of the two errors.
 * The result is stored in the global variable `g_combined_error`.
 */
void ServiceCombineErrors::combine_errors() {
    switch (g_error_mode) {
        case ErrorMode::ANGLE:
            g_combined_error = g_angle_error;
            break;
        case ErrorMode::DISTANCE:
            g_combined_error = g_distance_error;
            break;
        case ErrorMode::COMBINED:
            g_combined_error = (g_angle_error + g_distance_error) / 2.0;
            break;
        default:
            // Default to a safe value
            g_combined_error = 0.0;
            break;
    }
}
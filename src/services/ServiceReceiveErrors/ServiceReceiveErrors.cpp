#include "ServiceReceiveErrors.h"
#include "GlobalVariables.h"

/**
 * @brief Receives the raw angle and distance errors.
 *
 * This function obtains the angle and distance errors and stores them
 * in the global variables `g_angle_error` and `g_distance_error`.
 * We assume these values are always correctly obtained from their source.
 */
void ServiceReceiveErrors::receive_errors() {
    // TODO: Implement the actual logic to receive errors from sensors.
    // For now, we use placeholder values.
    g_angle_error = 5.0;    // Example value
    g_distance_error = 2.5; // Example value
}
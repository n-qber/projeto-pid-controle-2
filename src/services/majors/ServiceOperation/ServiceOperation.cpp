#include "ServiceOperation.h"

/**
 * @brief Executes the main control loop operations in sequence.
 * 1. Receives raw sensor errors (angle, distance).
 * 2. Combines errors based on the selected mode.
 * 3. Calculates the resultant error (reference - combined).
 * 4. Computes the PID control signal from the resultant error.
 * 5. Sends the control signal to move the car.
 */
void ServiceOperation::operate() {
    // 1. Receive raw errors
    serviceReceiveErrors.receive_errors();

    // 2. Combine errors
    serviceCombineErrors.combine_errors();

    // 3. Calculate resultant error
    serviceInputError.calculate_input_error();

    // 4. Calculate PID
    servicePID.calculate_pid();

    // 5. Move the car
    serviceMoveCar.move_car();
}

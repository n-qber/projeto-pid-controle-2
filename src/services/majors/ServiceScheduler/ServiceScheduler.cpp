#include "ServiceScheduler.h"
#include <iostream>
using namespace std;

/**
 * @brief Runs the system's main execution loop.
 * First, it runs the awake service once for setup.
 * Then, it enters an infinite loop for safety and operation.
 */
void ServiceScheduler::run() {
    // Run startup tasks once
    serviceAwake.awake_all();

    while (true) {
        // 1. Check safety conditions
        serviceSafety.check_safety();

        // If interlock is not ok, stop the car and skip the operation cycle
        if (!g_interlock_status) {
            g_control_signal = 0;
            serviceMoveCar.move_car();
            continue; // Skip to the next loop iteration
        }

        // 2. Run the main control loop operation
        cout << "Executando operacao..." << endl;
        serviceOperation.operate();
    }
}

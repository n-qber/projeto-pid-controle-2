#ifndef SERVICESAFETY_H
#define SERVICESAFETY_H

#include "services/ServiceInterlock/ServiceInterlock.h"

/**
 * @brief Major service responsible for system safety checks.
 * It calls the interlock service to ensure the system is in a safe state to operate.
 */
class ServiceSafety {
private:
    ServiceInterlock serviceInterlock;

public:
    /**
     * @brief Executes all safety checks.
     */
    void check_safety();
};

#endif // SERVICESAFETY_H

#ifndef SERVICESCHEDULER_H
#define SERVICESCHEDULER_H

#include "services/majors/ServiceAwake/ServiceAwake.h"
#include "services/majors/ServiceSafety/ServiceSafety.h"
#include "services/majors/ServiceOperation/ServiceOperation.h"
#include "services/ServiceMoveCar/ServiceMoveCar.h"
#include "GlobalVariables.h"

/**
 * @brief The main scheduler for the entire system.
 * It orchestrates the major services: Awake, Safety, and Operation.
 */
class ServiceScheduler {
private:
    ServiceAwake serviceAwake;
    ServiceSafety serviceSafety;
    ServiceOperation serviceOperation;
    ServiceMoveCar serviceMoveCar; // For emergency stops

public:
    /**
     * @brief Runs the system's main execution loop.
     */
    void run();
};

#endif // SERVICESCHEDULER_H
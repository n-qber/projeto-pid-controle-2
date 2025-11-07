#ifndef SERVICEOPERATION_H
#define SERVICEOPERATION_H

#include "services/ServiceReceiveErrors/ServiceReceiveErrors.h"
#include "services/ServiceCombineErrors/ServiceCombineErrors.h"
#include "services/ServiceInputError/ServiceInputError.h"
#include "services/ServicePID/ServicePID.h"
#include "services/ServiceMoveCar/ServiceMoveCar.h"

/**
 * @brief Major service responsible for the main control loop logic.
 * This includes error processing, PID calculation, and vehicle actuation.
 */
class ServiceOperation {
private:
    ServiceReceiveErrors serviceReceiveErrors;
    ServiceCombineErrors serviceCombineErrors;
    ServiceInputError serviceInputError;
    ServicePID servicePID;
    ServiceMoveCar serviceMoveCar;

public:
    /**
     * @brief Executes all control loop operations in sequence.
     */
    void operate();
};

#endif // SERVICEOPERATION_H

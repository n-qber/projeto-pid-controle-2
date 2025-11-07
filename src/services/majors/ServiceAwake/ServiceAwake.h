#ifndef SERVICEAWAKE_H
#define SERVICEAWAKE_H

#include "services/ServiceInitGlobalVariables/ServiceInitGlobalVariables.h"
#include "services/ServiceUserInput/ServiceUserInput.h"
#include "services/ServiceGenerateReference/ServiceGenerateReference.h"

/**
 * @brief Major service responsible for all system startup and configuration tasks.
 * It calls the services for initializing global variables, handling user input,
 * and generating the initial reference signal.
 */
class ServiceAwake {
private:
    ServiceInitGlobalVariables serviceInitGlobalVariables;
    ServiceUserInput serviceUserInput;
    ServiceGenerateReference serviceGenerateReference;

public:
    /**
     * @brief Executes all startup services in the correct order.
     */
    void awake_all();
};

#endif // SERVICEAWAKE_H

#include "ServiceSafety.h"

/**
 * @brief Executes the interlock check.
 * This function calls the underlying service to verify the system's interlock status.
 */
void ServiceSafety::check_safety() {
    serviceInterlock.check_interlock();
}

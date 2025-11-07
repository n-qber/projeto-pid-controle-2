#ifndef SERVICEPID_H
#define SERVICEPID_H

/**
 * @brief This service is responsible for the PID controller.
 */
class ServicePID {
public:
    // This service has no constructor.
    
    /**
     * @brief Calculates the PID control signal.
     */
    void calculate_pid();
};

#endif // SERVICEPID_H

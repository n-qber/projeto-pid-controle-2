#include "ServiceUserInput.h"
#include "GlobalVariables.h"
#include <iostream>

/**
 * @brief Reads the user input for error mode selection.
 *
 * This function prompts the user to select how errors are calculated.
 * 1: Use only angle error.
 * 2: Use only distance error.
 * 3: Use a combination (mean) of both angle and distance errors.
 * The selection is stored in the global variable `g_error_mode`.
 */
void ServiceUserInput::read_user_input() {
    int mode = 0;
    std::cout << "Selecione o modo de erro:\n";
    std::cout << "1. Apenas erro de angulo\n";
    std::cout << "2. Apenas erro de distancia\n";
    std::cout << "3. Combinacao de ambos os erros\n";
    std::cout << "Entrada: ";
    std::cin >> mode;

    if (mode >= 1 && mode <= 3) {
        g_error_mode = static_cast<ErrorMode>(mode);
    } else {
        // Default to a safe mode if input is invalid
        std::cout << "Entrada invalida. Usando modo padrao (Combinado).\n";
        g_error_mode = ErrorMode::COMBINED;
    }
}
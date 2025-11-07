#include "ServiceUserInput.h"
#include "GlobalVariables.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * @brief Reads the user input for error mode selection.
 *
 * This function prompts the user to select how errors are calculated.
 * 1: Use only angle error.
 * 2: Use only distance error.
 * 3: Use a combination (mean) of both angle and distance errors.
 * The selection is stored in the global variable 'g_error_mode'.
 */
void ServiceUserInput::read_user_input() {

    vector<string> errors = {"Distancia", "Angulo", "Combinado"};
    
    // Receive velocity base input
    cout << "Digite a velocidade desejada para o AGV (m/s): ";
    cin >> g_vel_base;

    // Receive error mode input
    cout << endl << "Selecione o modo de erro: 1, 2 ou 3." << endl;

    cout << "[1] Erro da distancia" << endl;
	cout << "[2] Erro do angulo" << endl;
	cout << "[3] Erro combinado" << endl;
	cout << "Erro: ";
    cin >> g_user_input;

    // Receive reference signal input
    cout << endl << "Digite a referencia do sistema (Sendo 0 o padrao): "; 
    cin >> g_reference_signal;

    // Receive frequency/period input
    cout << endl << "Digite o periodo do sistema (ms): ";
    cin >> g_period;

    // Receive PID parameters input
    cout << endl << "Digite os parametros do controlador PID (Kp, Ki, Kd): " << endl;
    cout << "Kp: ";
    cin >> g_kp;
    cout << "Ki: ";
    cin >> g_ki;
    cout << "Kd: ";
    cin >> g_kd;

    if (g_user_input >= 1 && g_user_input <= 3) {
        cout << endl << "----- ENTRADAS SELECIONADAS -----" << endl;
        cout << endl << "Modo de erro selecionado: " << errors[g_user_input-1] << endl;
        cout << "Velocidade base selecionada: " << g_vel_base << " m/s" << endl;
        cout << "Referencia do sistema: " << g_reference_signal << endl;
        cout << "Periodo da amostragem: " << g_period << " ms" << endl;
        cout << "Parametros do controlador PID: Kp = " << g_kp << ", Ki = " << g_ki << ", Kd = " << g_kd << endl << endl;

        g_error_mode = static_cast<ErrorMode>(g_user_input);
    } else {
        // Default to a safe mode if input is invalid
        cout << "Entrada invalida. Usando modo padrao (Combinado).\n";
        g_error_mode = ErrorMode::COMBINED;
    }
}
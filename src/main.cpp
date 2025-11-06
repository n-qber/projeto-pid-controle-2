#include <iostream>
using namespace std;

enum ERROR_TYPE {
	DISTANCE_ERROR = 1,
	ANGLE_ERROR = 2,
	COMBINED_ERROR = 3
};

bool alive = true;

static double velBase = 0.0;
static int errorType = 0;
static int debug_var = 5;
static float distance_error = 0;
static float angle_error = 0;

void initHardwareComponents(){
	cout << "[*] initHardwareComponents()" << endl;
};

bool interLocking(){
	bool result = --debug_var <= 0;

	cout << "[*] interLocking(): ";
	cout << (result ? "time to stop!" : "continuing...");
	cout << endl;

	return result;
};

void fetchError(){
	cout << "[*] fetchError()" << endl;
};

float mergeErrors(){
	cout << "[*] mergeErrors()" << endl;
	switch (errorType) {
		case DISTANCE_ERROR:
			return distance_error;
			break;
		case ANGLE_ERROR:
			return angle_error;
			break;
		case COMBINED_ERROR:
			return (distance_error + angle_error) / 2; // Average of both errors
			break;
		default:
			cout << "Ocorreu um erro!" << endl;
			return -1;
			break;
	}
};

void calculatePID(){
	cout << "[*] calculatePID()" << endl;
};

void calculateWheelsSpeed(){

	cout << "[*] calculateWheelsSpeed()" << endl;
};

void setWheelsSpeed(){
	cout << "[*] setWheelsSpeed()" << endl;
};

void stopWheels(){
	cout << "[*] stopWheels()" << endl;
};



int main()
{
	float error = 0.0;
	cout << "[*] Starting system..." << endl << endl;
	cout << "Digite a velocidade desejada para o AGV (m/s): " << endl;
	cin >> velBase;

	cout << endl << "Digite o tipo de erro voce deseja: 1, 2 ou 3." << endl;

	while (errorType < 1 || errorType > 3) {
		cout << "[1] Erro da distancia" << endl;
		cout << "[2] Erro do angulo" << endl;
		cout << "[3] Erro combinado" << endl;
		cout << "Erro: ";
		cin >> errorType;

		switch (errorType) {
			case 1:
				cout << endl << "Tipo de erro selecionado: Erro da distancia." << endl;
				break;
			case 2:
				cout << endl << "Tipo de erro selecionado: Erro do angulo." << endl;
				break;
			case 3:
				cout << endl << "Tipo de erro selecionado: Erro combinado." << endl;
				break;
			default:
				cout << endl << "Valor inválido! Digite novamente.\n" << endl;
		}
	}

	cout << "Velocidade base selecionada: " << velBase << " m/s" << endl << endl;

	// inicia variaveis
	initHardwareComponents();
	
	while(alive)
	{
		if(interLocking())
			goto halt;



		setWheelsSpeed();

		// M3
		try {

			// essa função pode acabar sendo a mais demorada
			// possívels soluções:
			// 	comunicação de erros assíncrona
			// 	gpio por interrupt do sistema
			fetchError();

			error = mergeErrors();
			calculatePID();
			calculateWheelsSpeed();

		} catch (...) { // in case of unexpected/unkown error
			goto halt;
		}


		cout << endl;
	}


halt:
	alive = false;
	// stop wheels
	stopWheels();
	cout << "[*] I'm going to sleep..." << endl;
}

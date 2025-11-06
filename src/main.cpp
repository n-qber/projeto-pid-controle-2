#include <iostream>
using namespace std;

bool alive = true;
static double velBase = 0.0;



static int debug_var = 5;

static const double MAX_PID = 100;
static const double MIN_PID = -MAX_PID;


static struct {
	double leftFront;
	double rightFront;
	double leftBack;
	double rightBack;
} wheelsSpeed = { 0 };


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
void fetchErrors(){
	cout << "[*] fetchErrors()" << endl;
};
double mergeErrors(){
	cout << "[*] mergeErrors()" << endl;
	return 21.5;
};
double calculatePID(double error){
	cout << "[*] calculatePID()" << endl;


	// TODO
	// clamp value
	return 42.4;
};
void calculateWheelsSpeed(double error, double& left, double& right){
	cout << "[*] calculateWheelsSpeed()" << endl;

	double pidValue = calculatePID(error);
	double K = 1;

	left = velBase + K * pidValue;
	right = velBase - K * pidValue;

	// (talvez) precisamo sabe as distancia entre as roda
};

void setWheelsLinearSpeed(double left, double right){
	cout << "[*] setWheelsLinearSpeed(" << left << ", " << right << ")" << endl;

	// TODO ENVIAR PARA A RODA DE VERDADE
	wheelsSpeed.leftFront = left;
	wheelsSpeed.leftBack = left;


	wheelsSpeed.rightFront = right;
	wheelsSpeed.rightBack = right;

};
void stopWheels(){
	cout << "[*] stopWheels()" << endl;
	setWheelsLinearSpeed(0, 0);
};



int main()
{

	// inicia variaveis
	initHardwareComponents();
	
	while(alive)
	{
		if(interLocking())
			goto halt;



		//setWheelsLinearSpeed(wheelsSpeed.leftFront, wheelsSpeed.rightFront);

		// M3
		try {

			// essa função pode acabar sendo a mais demorada
			// possívels soluções:
			// 	comunicação de erros assíncrona
			// 	gpio por interrupt do sistema
			fetchErrors();
			double error = mergeErrors();
			calculatePID(error);

			double left = 0, right = 0;
			calculateWheelsSpeed(error, left, right);
			setWheelsLinearSpeed(left, right);

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


// ver visão computacional como ta trazendo os dados
// merge de erros

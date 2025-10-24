#include <iostream>
using namespace std;

bool alive = true;


static int debug_var = 5;

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
void mergeErrors(){
	cout << "[*] mergeErrors()" << endl;
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

			mergeErrors();
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

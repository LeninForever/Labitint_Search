
#include"Application.h"
#include"Labirint.h"
#include"LabirintOptions.h"
#include"Main_Menu.h"
#include<locale.h>
#include<time.h>

int main() {

	srand(unsigned int(time(NULL)));

	Application app;

	app.work();

	return 0;
}
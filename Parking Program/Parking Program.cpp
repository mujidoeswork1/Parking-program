
#include <iostream>
#include "Parking.h"

int main()
{

	Parking Menu("file");
	Parking Bad1(nullptr);
	Parking Bad2("");

	Bad1.run();
	Bad2.run();
	Menu.run();

	cout << endl;
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	cout << endl;




	return 0;
}

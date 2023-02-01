#pragma once
#include <iostream>

using namespace std;

class Parking;

class MenuItem {

private:

	char title[50];


	//Friend class
	friend class Parking;

public:
	MenuItem(const char str[] = "") {

		strcpy_s(title, str);

		//cout << title << endl;
	}

	void operator << (const char str[]) {

		strcpy_s(title, str);
	}
	void operator = (const char str[]) {

		strcpy_s(this->title, str);
	}
};
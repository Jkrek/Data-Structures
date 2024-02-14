#pragma once
#ifndef WHEEL_H
#define WHEEL_H

#include <cstdlib>

class Wheel {
private:
	int val_min;
	int val_max;
public:

	//constructors

	Wheel();
	Wheel(int min, int max);
	
	// getters

	int getVal_min() const;
	int getVal_max() const;

	////setters
	//void setVal_min(int) const;
	//void setVal_max(int) const;

	
	
	//function spin
	int spin() const;

};

class player {
private:
	int Money{};
	Wheel playerw{};
public:
	//constructor
	player(int imoney, const Wheel& wheel);

	//getters
	int getMoney() const;

	int play_spin(int bet);

	
};
#endif 

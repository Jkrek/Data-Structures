#include<iostream>
#include<cstdlib> //for random numbers
#include<ctime> // to set a range for random numbers
#include "Header.h"

using namespace std;
// Source for random numbers //
	// https://www.simplilearn.com/tutorials/cpp-tutorial/random-number-generator-in-cpp#:~:text=Output%3A-,How%20to%20Generate%20Random%20Numbers%20in%20C%2B%2B%20Within%20a%20Range,(rand()%20%25%20100).

Wheel::Wheel(){
	val_min = 1;
	val_max = 10;
	srand(time(0));
};

Wheel::Wheel(int min, int max) {
	val_min = min;
	val_max = max;
	srand(time(0));
}

int Wheel::getVal_max()const {
	return val_max;
}
int Wheel::getVal_min() const {
	return val_min;
}


int Wheel::spin()const {
	return rand() % (val_max - val_min + 1) + val_min;
}


//void Wheel::setRango(int min, int max) {
//	val_min = min;
//	val_max = max;
//}

player::player(int imoney, const Wheel& wheel) {
	Money = imoney;
	playerw = wheel;
}

int player::getMoney()const {
	return Money;
 }

int player::play_spin(int bet) {
	int Result = playerw.spin();
	return Result;
}



int main(){
	
	return 0;
} 

#include <string>
#include <iostream>
#include "Measurement.h"
#include <sstream>
using namespace std;

int new_standard::getLittle()const {
	return little;
};
int new_standard::getLots() const {
	return lots;
};
int new_standard:: getHeaps()const {
	return heaps;
}


void new_standard::setLittle(int l) {
	if (l >= 0)
	{
		little = l;
	}
	else {
		cout << "Invalid value\n";
	}


}

void new_standard::setLots(int x) {
	if (x >= 0)
	{
		lots = x;
	}
	else {
		cout << "Invalid value\n";
	}

}
void new_standard::setHeaps(int h) {
		if (h >= 0) {
			heaps = h;
		}
		else {
		cout << "Invalid value\n";
	}
}





//constructors
new_standard::new_standard(int l, int x, int h) {
	little = l;
	lots = x;
	heaps = h;
}

new_standard::new_standard(int l) {
	little = l;
	lots = 0;
	heaps = 0;
}


new_standard::new_standard() {
	little = 0;
	lots = 0;
	heaps = 0;
}
//operator overload for +
new_standard operator+(const new_standard& arg1, const new_standard& arg2) {

	int temp_little = (arg1.getLittle() + arg2.getLittle());
	int temp_lots = (arg1.getLots() + arg2.getLots());
	int temp_heaps = (arg1.getHeaps() + arg2.getHeaps());

	int extra_little = floor(temp_little / 7);
	temp_lots += extra_little;
	temp_little -= extra_little * 7;
	
//check conditions for when littles are >=7 and when lots are >=23
	if (temp_little >= 7) {
		temp_lots += temp_little / 7;
		temp_little %= 7;
	}

	int extra_lots = floor(temp_lots / 23);
	temp_heaps += extra_lots;
	temp_lots -= extra_lots * 23;
	
	
	if (temp_lots >= 23) {
		temp_heaps += temp_lots / 23;
		temp_lots %= 23;
	}
	

	return new_standard(temp_little, temp_lots, temp_heaps);

}
//operator overload for -	  
new_standard operator-(const new_standard& arg1, const new_standard& arg2) {

	int temp_little = (arg1.getLittle() - arg2.getLittle());
	int temp_lots = (arg1.getLots() - arg2.getLots());
	int temp_heaps = (arg1.getHeaps() - arg2.getHeaps());

	int extra_little = floor(temp_little / 7);
	temp_lots += extra_little;
	temp_little -= extra_little * 7;

	if (temp_little >= 7) {
		temp_lots += temp_little / 7;
		temp_little %= 7;

	int extra_lots = floor(temp_lots / 23);
	temp_heaps += extra_lots;
	temp_lots -= extra_lots * 23;

	
	}
	if (temp_lots >= 23) {
		temp_heaps += temp_lots / 23;
		temp_lots %= 23;
	}

	return new_standard(temp_little, temp_lots, temp_heaps);
}
//operator overload for *
new_standard operator*(const new_standard& arg1, const new_standard& arg2) {


	int temp_little = (arg1.getLittle() * arg2.getLittle());
	int temp_lots = (arg1.getLots() * arg2.getLots());
	int temp_heaps = (arg1.getHeaps() * arg2.getHeaps());

	int extra_little = floor(temp_little / 7);
	temp_lots += extra_little;
	temp_little -= extra_little * 7;


	if (temp_little >= 7) {
		temp_lots += temp_little / 7;
		temp_little %= 7;
	}

	int extra_lots = floor(temp_lots / 23);
	temp_heaps += extra_lots;
	temp_lots -= extra_lots * 23;

	
	if (temp_lots >= 23) {
		temp_heaps += temp_lots / 23;
		temp_lots %= 23;
	}

	return new_standard(temp_little, temp_lots, temp_heaps);

}
//operator overload for /
new_standard operator/(const new_standard& arg1, const new_standard& arg2) {

	int temp_little = (arg1.getLittle() / arg2.getLittle());
	int temp_lots = (arg1.getLots() / arg2.getLots());
	int temp_heaps = (arg1.getHeaps() / arg2.getHeaps());

	int extra_little = floor(temp_little / 7);
	temp_lots += extra_little;
	temp_little -= extra_little * 7;

	if (temp_little >= 7) {
		temp_lots += temp_little / 7;
		temp_little %= 7;
	}

	int extra_lots = floor(temp_lots / 23);
	temp_heaps += extra_lots;
	temp_lots -= extra_lots * 23;

	
	if (temp_lots >= 23) {
		temp_heaps += temp_lots / 23;
		temp_lots %= 23;
	}

	return new_standard(temp_little, temp_lots, temp_heaps);

}
//operator overload for ==
bool operator==(const new_standard& arg1, const new_standard& arg2) {
	return (arg1.getLittle() == arg2.getLittle()
		&& arg1.getLots() == arg2.getLots() && 
		arg1.getHeaps() == arg2.getHeaps());

}
//operator overload for string
//for this ostream thing here is the source : https://stackoverflow.com/questions/28142239/overloading-ostream-operator-returning-address 
//also https://en.cppreference.com/w/cpp/io/basic_ostream/operator_ltlt2
ostream& operator<<(ostream& os, const new_standard& ans) {
	os  << "Little: "<< ans.getLittle() << endl
		<< "Lots: " << ans.getLots() <<endl
		<< "Heaps: " << ans.getHeaps()<< endl;
	return os;
}


int main()
{
	bool continue_operations = true;
// loop to ask user if he wants to continue
	while (continue_operations) {
		new_standard values_user1;
		new_standard values_user2;
		new_standard final_answer;

		int val_little1;
		int val_lot1;
		int val_heap1;
		string Operation;
		int val_little2;
		int val_lot2;
		int val_heap2;

		cout << "Input the values for Littles, Lots, and Heaps for the first object:" << endl;
		cout << "Little:"; cin >> val_little1;
		cout << "Lots:"; cin >> val_lot1;
		cout << "Heap:"; cin >> val_heap1;
		
// setting littles, lots and heaps from user input
		values_user1.setLittle(val_little1);
		values_user1.setLots(val_lot1);
		values_user1.setHeaps(val_heap1);

		cout << "Input the values for Littles, Lots, and Heaps for the Second object:" << endl;
		cout << "Little:"; cin >> val_little2;
		cout << "Lots:"; cin >> val_lot2;
		cout << "Heap:"; cin >> val_heap2;

		values_user2.setLittle(val_little2);
		values_user2.setLots(val_lot2);
		values_user2.setHeaps(val_heap2);

		cout << "Which operation do you wish to perform?";
		cout << " + , - , / , * , ==" << endl;
		cin >> Operation;
// check for conditions, what to do depending on chosen operation.
		if (Operation == "+") {
			final_answer = values_user1 + values_user2;
		}
		else if (Operation == "-") {
			final_answer = values_user1 - values_user2;
		}
		else if (Operation == "*") {
			final_answer = values_user1 * values_user2;
		}
		else if (Operation == "/") {
			final_answer = values_user1 / values_user2;
		}
		else if (Operation == "==") {
			if (values_user1 == values_user2) {
				cout << "Objects are the same" << endl;
			}
			else {
				cout << "Objects are different" << endl;
			}
		}
		else {
			cout << "Invalid operation." << endl;
		}
		// display final answer doing cout on an object. (string overload operator)
		cout << "The answer is:" << endl << final_answer << endl;
		
//ask the user if they want to continue, if not break the loop.
		cout << "Do you want to do more operations? (YES or NO)";
		string continue_operations;
		cin >> continue_operations;
		if (continue_operations == "YES") {
			continue;
		}
		else {
			break;
		}

	}
	
	return 0;
}


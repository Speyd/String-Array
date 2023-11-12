#include "Array.h"
#include <iostream>
using namespace std;

#pragma region Special_Abilities
void ClearScreanTask2() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
	cout << "\tArray" << endl;
}
extern void Enter();
#pragma endregion

bool PrintNum(Array& array) {

	int size = array.GetAmountNum();

	if (size != 0) {

		for (int i = 0; i != size; i++) {
			cout << i + 1 << "-th element array: " << array[i] << endl;
		}

		return true;
	}
	else cout << "Array is empty!" << endl;

	return false;

}

int ChoiceNum(Array& array) {

	ClearScreanTask2();
	if (PrintNum(array) == true) {

		int choiceNum = 1,size = array.GetAmountNum();

		do {

			if (choiceNum >= 1 && choiceNum <= size)cout << "Enter your choice: ";
			else cout << "There is no such choice!\nEnter your choice again: ";

			cin >> choiceNum;

			ClearScreanTask2();
			PrintNum(array);

		} while (choiceNum < 1 || choiceNum > size);

		return --choiceNum;
	}
	else return -1;

}

int Task2(){
	
	Array array;
	int choice = 0;
	double tempNum = 0;

	do {
		do {

			ClearScreanTask2();
			cout << "Action\n[1] - Print all num\n[2] - Add new num\n[3] - Change num\n[0] - Exit" << endl;

			if (choice >= 0 && choice <= 3)cout << "Enter your choice: ";
			else cout << "There is no such choice!\nEnter your choice again: ";

			cin >> choice;

		} while (choice < 0 || choice > 3);

		ClearScreanTask2();

		switch (choice) {

		case 1: PrintNum(array); break;

		case 2: cin >> array; break;

		case 3: cout << "Enter new number for change: "; cin >> tempNum; array[ChoiceNum(array)] = tempNum; break;

		}

		if (choice != 0)Enter();

	} while (choice != 0);

	return 0;
}
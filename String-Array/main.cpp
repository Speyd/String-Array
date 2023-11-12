#include "Task1.h"
#include "Task2.h"
#include <iostream>
#include <string>
using namespace std;

#pragma region Special_Abilities
void ClearScrean() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
	cout << "\tString & Array" << endl;
}
extern void Enter() {
	string enter;
	cin.ignore();
	do {
		cout << "Press enter to continue: "; getline(cin, enter);
	} while (!enter.empty());
}
#pragma endregion

int main(){
   
	int choice = 0;

	do {
		do {

			ClearScrean();
			cout << "Action\n[1] - String\n[2] - Array\n[0] - Exit" << endl;

			if (choice >= 0 && choice <= 2)cout << "Enter your choice: ";
			else cout << "There is no such choice!\nEnter your choice again: ";

			cin >> choice;

		} while (choice < 0 || choice > 2);

		if (choice == 1)Task1();
		else if (choice == 2)Task2();


	} while (choice != 0);

	return 0;
}
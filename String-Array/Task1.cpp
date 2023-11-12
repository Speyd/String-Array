#include "String.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

#pragma region Special_Abilities
void ClearScreanTask1() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
	cout << "\tString" << endl;
}
void EnterTask1(const int choice) {
	string enter;
	if (choice != 4 && choice != 5)cin.ignore();
	do {
		cout << "Press enter to continue: "; getline(cin, enter);
	} while (!enter.empty());
}
#pragma endregion

int PrintAllText(vector<String>& strings) {
	int size = String::GetAmountString();
	cout << size;
	if (size != 0) {

		for (int i = 0; i != size; i++) {

			cout << i + 1 << "-th string: " << strings[i].GetString() << endl;

		}

		return 1;

	}
	else {
		cout << "The number of lines is zero!\nYou can't take them out" << endl;
		return 0;
	}
}

void FillString(vector<String>& strings) {

	if (PrintAllText(strings) == 1) {

		int choice_string = 1, size = String::GetAmountString();
		char text[1000];

		do {

			ClearScreanTask1();
			PrintAllText(strings);

			cout << "Choose a string" << endl;

			if (choice_string >= 1 && choice_string <= size)cout << "Enter your choice: ";
			else cout << "There is no such choice!\nEnter your choice again: ";

			cin >> choice_string;


		} while (choice_string < 1 || choice_string > size);

		ClearScreanTask1();
		cout << "Enter new string text: ";

		cin.ignore();
		cin.getline(text, 1000);

		strings[--choice_string] = String(text);

		ClearScreanTask1();
		cout << "Text added successfully!" << endl;
	}
	else cin.ignore();


}

void DeleteString(vector<String>& strings) {

	if (PrintAllText(strings) == 1) {

		int index = 1, size = String::GetAmountString();

		do {

			ClearScreanTask1();
			cout << "Delete string" << endl;
			PrintAllText(strings) == 1;

			if (index >= 1 && index <= size) cout << "Enter the line number to be deleted: ";
			else cout << "There is no such choice!\nEnter the line number to be deleted again: ";

			cin >> index;

		} while (index < 1 || index > size);

		String::SetAmountString(size - 1);

		strings.erase(strings.begin() + --index);

		ClearScreanTask1();
		cout << "Text deleted successfully!" << endl;
	}
}

int String::amount_string{ 0 };

int Task1() {

	vector<String> strings;

	int choice = 0, size;

	char text[1000];

	do {

		do {

			ClearScreanTask1();
			cout << "Choose an action\n[1] - Print all strings\n[2] - Create string\n[3] - Create a string with a specific size\n"
				<< "[4] - Create a string and fill it\n[5] - Fill created string\n[6] - Delete string\n[0] - Exit" << endl;

			if (choice >= 0 && choice <= 6)cout << "Enter your choice: ";
			else cout << "There is no such choice!\nEnter your choice again: ";

			cin >> choice;

		} while (choice < 0 || choice > 6);

		ClearScreanTask1();

		switch (choice) {

		case 1:PrintAllText(strings); break;

		case 2:strings.push_back(String()); break;

		case 3:cout << "Enter size string: "; cin >> size; strings.push_back(String(size)); break;

		case 4:cout << "Enter text string: "; cin.ignore(); cin.getline(text, 1000);
			strings.push_back(String(text, strlen(text) + 1));
			String::SetAmountString(String::GetAmountString() - 1); break;

		case 5:FillString(strings); break;

		case 6:DeleteString(strings); break;

		}

		if (choice != 0)EnterTask1(choice);

	} while (choice != 0);

	return 0;
}
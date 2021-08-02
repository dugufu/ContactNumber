#include <iostream>
using namespace std;
#include <string>
#include "contact.h"

int AddContact(AddressBook* Address)
{
	cout << "Enter name : " << endl;
	string name;
	cin >> name;
	Address->personArray[Address->record_num].name = name;

	int age;
	cout << "Enter Age : " << endl;
	cin >> age;
	Address->personArray[Address->record_num].contactNumber = age;

	int gender;
jump:
	cout << "Please select gender : ( 1 / 2 ) \n1. Male \n2. Female" << endl;
	cin >> gender;
	Address->personArray[Address->record_num].gender = gender;

	if (gender == 1 || gender == 2) {
		if (gender == 1)
		{
			Address->personArray[Address->record_num].S_gender = "Male";
		}
		else
		{
			Address->personArray[Address->record_num].S_gender = "Female";
		}
		Address->record_num++;

	}
	else {
		cout << "Enter number only ...." << endl;
		goto jump;
	}

	return 0;
}

void DisplayContact(AddressBook * Address)
{
	for (int i = 0; i < Address->record_num ; i++)
	{
		cout << "Name :" << Address->personArray[i].name;
		cout << "\tContact Number : \t" << Address->personArray[i].contactNumber;
		cout << "\tGender : \t" << Address->personArray[i].S_gender;
		cout << "\n\n";
	}
}

void showMenu() {
	cout << "*****************************" << endl;
	cout << "*****" << "1. Add Contact" << "\t*****" << endl;
	cout << "*****" << "2. Display Contact" << "\t*****" << endl;
	cout << "*****" << "3. Delete Contact" << "\t*****" << endl;
	cout << "*****" << "4. Search Contact" "\t*****" << endl;
	cout << "*****" << "5. Edit Contact" << "\t*****" << endl;
	cout << "*****" << "6. Clean Contact" << "\t*****" << endl;
	cout << "*****" << "0. Exit " << "\t\t*****" << endl;
}


void DeleteContact(AddressBook* Address)
{
	char input_X_Y;
	jump:
	cout << "Are you sure to delete page ? ( y / n)" << endl;
	cin >> input_X_Y;

	if (input_X_Y == 'y' )
	{
		string deleteName;
		cout << "Please Enter the name you want to delete" << endl;
		cin >> deleteName;
		for (int i = 0; i < Address->record_num; i++)
		{
			if (deleteName == Address->personArray[i].name)
			{
				Address->personArray[i] = Address->personArray[i + 1];
				Address->record_num--;
				cout << "User deleted" << endl;
			}
		}
	}
	else if (input_X_Y == 'n') {
		//showMenu();
	}
	else {
		cout << "Please enter only small letter 'y' / 'n'" << endl;
		goto jump;
	}
	
}




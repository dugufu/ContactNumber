#include <iostream>
using namespace std;
#include <string>
#include "contact.h"

int AddContact(AddressBook* Address)
{
	string name;
	jump_name:
	cout << "Enter name : " << endl;
	
	cin >> name;
	int checkStatus = SearchContact(Address, name, 0);
	if (checkStatus == -1)
	{
		goto jump_name;
	}
	Address->personArray[Address->record_num].name = name;

	int age;
	cout << "Enter Contact Number : " << endl;
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
	for (int i = 0; i < Address->record_num; i++)
	{
		cout << "Name :" << Address->personArray[i].name;
		cout << "\tContact Number : \t" << Address->personArray[i].contactNumber;
		cout << "\tGender : \t" << Address->personArray[i].S_gender;
		cout << "\n\n";
		
	}
	if (Address->record_num < 1 )
	{
		cout << "No data exists !" << endl;
	}

	cout << sizeof(Address->personArray) << endl;
	cout << sizeof(Address) << endl;
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
// 
// int* getReturnValue(int i) {
// 	int* r_value = new int(10);
// 	r_value[0] = 0;
// 	r_value[1] = i;
// 	return r_value;
// }

int SearchContact(AddressBook* Address, string searchName, int searchStatus) {
	if (searchName != "" && searchStatus == 2)
	{
		for (int i = 0; i < Address->record_num; i++)
		{
			if (Address->personArray[i].name == searchName)
			{
				cout << "Person name found" << endl;
				return i;
			}
		}
		return -1;
	}else if (searchName != "")
	{
		for (int i = 0; i < Address->record_num; i++)
		{
			if (Address->personArray[i].name == searchName)
			{
				cout << "Name already exists by other person" << endl;
				return -1;
			}
		}
	}
	if (searchName == "" && searchStatus == 1)
	{
		string tempName;
		int searchNameFound = 0;
		cout << "Enter the name you want to search for ... :" << endl;
		cin >> tempName;
		for (int i = 0; i < Address->record_num; i++)
		{
			if (Address->personArray[i].name == tempName)
			{
				cout << "Record found :" << endl;
				cout << "Name :" << Address->personArray[i].name;
				cout << "\tContact Number : \t" << Address->personArray[i].contactNumber;
				cout << "\tGender : \t" << Address->personArray[i].S_gender;
				cout << "\n\n";
				searchNameFound = 1;

				return -1;
			}
		}

		if (searchNameFound != 1) {
			cout << "No person found" << endl;
			searchNameFound = 0;
		}

	}

	searchStatus = 0;
	return 0;
}


void cleanUpContact(AddressBook* Address) {
	char tempChar;
	jump:
	cout << "Are you sure to clean up your contact record ? ( y / n )" << endl;
	cin >> tempChar;
	if (tempChar == 'y') {
		Address->record_num = 0;
		cout << "Data clean up !" << endl;
	}
	else if (tempChar == 'n') {
		cout << "Exit to main menu ...." << endl;
	}else {
		cout << "Please enter only 'y' or 'n' " << endl;
		goto jump;
	}
}


void EditContact(AddressBook* Address, int i) {
	string name;
	int r_value;
	cout << "Enter a name that you want to edit :" << endl;
	cin >> name;

	 r_value = SearchContact(Address, name, 2);
	if (r_value != -1) {

	jump_edit:
	cout << "You want to edit this person's details ?" << endl;
	char tempChar;
	cout << "Press y or n in small letter ? ( y / n )" << endl;
	cin >> tempChar;
	if (tempChar == 'y') {
		string editName;
		int editContactNumber;
		int editGender;
		jump_name:
		cout << "Edit name :" << endl;
		cin >> editName;
		int checkStatus = SearchContact(Address, editName, 0);

		if (checkStatus == -1 && editName != Address->personArray[r_value].name)
		{
			goto jump_name;
		}

		cout << "Edit contact number :" << endl;
		cin >> editContactNumber;
		jump:
		cout << "Edit gender : \n1. Male\n2. Female" << endl;
		cin >> editGender;
		if (editGender == 1 || editGender == 2) {
			if (editGender == 1)
			{
				Address->personArray[r_value].S_gender = "Male";
			}
			else
			{
				Address->personArray[r_value].S_gender = "Female";
			}
		}
		else {
			cout << "Enter number only ...." << endl;
			goto jump;
		}
		Address->personArray[r_value].name = editName;
		Address->personArray[r_value].contactNumber = editContactNumber;

		cout << "Edited Record" << endl;
	}
	else if (tempChar == 'n') {
		cout << "Exit to main menu ...." << endl;
	}
	else {
		cout << "Please enter only 'y' or 'n' " << endl;
		goto jump_edit;

	}
	
	}
	else {
		cout << "No such person in contact book" << endl;
	};
}
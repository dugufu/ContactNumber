
#include <iostream>
using namespace std;
#include <string>
//1 Display menu
#include "contact.h"





int main() {
	struct AddressBook Address;
	int input = 0;
	string searchName = "";
	bool status = false;
	while (status == false) {

		showMenu();

		cin >> input;

		switch (input)
		{
		case 1:
			AddContact(&Address);
			break;
		case 2:
			DisplayContact(&Address);
			break;
		case 3:
			DeleteContact(&Address);
			break;
		case 4:
			SearchContact(&Address, searchName, 1);
			break;
		case 5:
			EditContact(&Address, 0);
			break;
		case 6:
			cleanUpContact(&Address);
			break;
		case 0:
			cout << "See you" << endl;
			system("pause");
			return 0;
			break;

		default:
			break;
		}
	}
	


	//system("pause");
	return 0;
}


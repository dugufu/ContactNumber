
#include <iostream>
using namespace std;
#include <string>
#define MaxContact 1000
//1 Display menu

struct Person {
	string name;
	int contactNumber;
	int gender;
};

struct AddressBook {
	struct Person personArray[MaxContact];
	int record_num;
};

void showMenu() {
	cout << "*****************************" << endl;
	cout << "*****" << "1. Add Contact" << "\t*****" << endl;
	cout << "*****" << "2. Display Contact" << "\t*****" << endl;
	cout << "*****" << "3. Delete Contact" << "\t*****" << endl;
	cout << "*****" << "4. Search Contact" "\t*****"<< endl;
	cout << "*****" << "5. Edit Contact" << "\t*****" << endl;
	cout << "*****" << "6. Clean Contact" << "\t*****" << endl;
	cout << "*****" << "7. Exit " << "\t\t*****" << endl;
}


int main() {
	int input = 0;
	bool status = false;
	while (status == false) {

		showMenu();

		cin >> input;

		switch (input)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
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

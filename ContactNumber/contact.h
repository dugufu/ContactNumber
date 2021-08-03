#pragma once
#define MAXContact 1000
struct Person {
	string name;
	int contactNumber;
	int gender;
	string S_gender;
};

struct AddressBook {
	struct Person personArray[MAXContact];
	int record_num = 0;
};

int AddContact(AddressBook *Address);
void DisplayContact( AddressBook * Address);
void showMenu();
void DeleteContact(AddressBook* Address);
int SearchContact(AddressBook* Address, string searchName, int searchStatus);
void cleanUpContact(AddressBook* Address);
void EditContact(AddressBook* Address, int i);
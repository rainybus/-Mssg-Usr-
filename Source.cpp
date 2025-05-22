#include "user.h"
#include "message.h"
#include <fstream>
#include <iostream>
#include <filesystem>
#include "message.cpp"

using namespace std;


namespace fs = std::filesystem;

int main()
{
	Person obj1("Oleg", "user1", "12345");
	Person obj2("Maria", "user2", "qwerty");
	Person obj3("Slava", "user3", "uuu123");
	Message mess1("Hello", "Oleg", "Slava");
	Message mess2("Hello", "Slava", "Oleg");
	Message mess3("Hello", "Oleg", "Maria");
	fstream user_file = std::fstream("User.txt", ios::in | ios::out);
	
	fs::permissions("User.txt",
		fs::perms::owner_all,
		fs::perm_options::add);
	fstream mess_file = std::fstream("Message.txt", ios::in | ios::out);
	
	fs::permissions("Message.txt",
		fs::perms::owner_all,
		fs::perm_options::add);
	user_file << obj1 << endl;
	user_file << obj2 << endl;
	user_file << obj3 << endl;
	mess_file << mess1 << endl;
	mess_file << mess2 << endl;
	mess_file << mess3 << endl;
	user_file.seekg(0, ios_base::beg);
	user_file >> obj1;
	cout << obj1 << endl;
	user_file >> obj2;
	cout << obj2 << endl;
	user_file >> obj3;
	cout << obj3 << endl;
	mess_file.seekg(0, ios_base::beg);
	mess_file >> mess1;
	cout << mess1 << endl;
	mess_file >> mess2;
	cout << mess2 << endl;
	mess_file >> mess3;
	cout << mess3 << endl;
	return 0;

	
	
}
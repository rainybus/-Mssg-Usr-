#include "user.h"
#include "message.h"
#include <fstream>
#include <iostream>
#include <filesystem>
#include <cstdio>
namespace fs = std::filesystem;
using namespace std;

void demo_perms(fs::perms p)
{
	cout << ((p & fs::perms::owner_read) != fs::perms::none ? "r" : "-")
		<< ((p & fs::perms::owner_write) != fs::perms::none ? "w" : "-")
		<< ((p & fs::perms::owner_exec) != fs::perms::none ? "x" : "-")
		<< ((p & fs::perms::group_read) != fs::perms::none ? "r" : "-")
		<< ((p & fs::perms::group_write) != fs::perms::none ? "w" : "-")
		<< ((p & fs::perms::group_exec) != fs::perms::none ? "x" : "-")
		<< ((p & fs::perms::others_read) != fs::perms::none ? "r" : "-")
		<< ((p & fs::perms::others_write) != fs::perms::none ? "w" : "-")
		<< ((p & fs::perms::others_exec) != fs::perms::none ? "x" : "-")
		<< '\n';
}


int main()
{
	Person obj1  ("Oleg",   "user1", " 12345");
	Person obj2  ("Maria",  "user2", "qwerty");
	Person obj3  ("Slava",  "user3", "uuu123");
	Message mess1("Hallo",  "Oleg",  "Slava");
	Message mess2("Annyoung","Slava", "Oleg");
	Message mess3("¢®Hola!",  "Oleg",  "Maria");
	fstream user_file = fstream("User.txt", ios::in | ios::out);
	if (!user_file)
		user_file = fstream("User.txt", ios::in | ios::out | ios::trunc);

	cout << "\tCurrent permissions: ";
	demo_perms(fs::status("Users.txt").permissions());
	fs::permissions("User.txt", fs::perms::others_all | fs::perms::group_all,
		fs::perm_options::remove);
	fs::permissions("User.txt", fs::perms::owner_all,
		fs::perm_options::add);
	

	if (user_file) {
		user_file  << obj1 << endl;
		user_file << obj2 << endl;
		user_file << obj3 << endl;
		user_file.seekg(0, ios_base::beg);
		user_file >> obj1;
		cout << obj1 << endl;
		user_file >> obj2;
		cout << obj2  << endl;
		user_file >> obj3;
		cout << obj3  << endl;
		user_file.close();
	}
	else {
		cout << "Could not open file users.txt !" << '\n';
		return 0;
	}
	
	fstream mess_file = fstream("Message.txt", ios::in | ios::out);
	if (!mess_file)
		mess_file = fstream("Message.txt", ios::in | ios::out | ios::trunc);

	cout << "\tCurrent permissions: ";
	demo_perms(fs::status("Message.txt").permissions());
	fs::permissions("Message.txt", fs::perms::others_all | fs::perms::group_all,
		fs::perm_options::remove);
	fs::permissions("Message.txt", fs::perms::owner_all,
		fs::perm_options::add);
	

	if (mess_file){
	mess_file << mess1 << endl;
	mess_file << mess2 << endl;
	mess_file << mess3 << endl;
	
	mess_file.seekg(0, ios_base::beg);
	mess_file >> mess1;
	cout << mess1 << endl;
	mess_file >> mess2;
	cout << mess2 << endl;
	mess_file >> mess3;
	cout << mess3 << endl; 
	mess_file.close();
	}
	else {
		cout << "Could not open file users.txt !" << '\n';
		return 0;
	}

	return 0;

}
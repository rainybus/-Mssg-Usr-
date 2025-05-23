#pragma once 

#include <string>

#include <fstream>


using namespace std;

class Person
{
	string _name;
	string _login;
	string _pass;

public:
	Person(string name, string login, string pass) : _name(name), _login(login), _pass(pass) {};

	~Person() = default;

	friend fstream& operator >>(fstream& is, Person& obj);
	friend ostream& operator <<(ostream& os, const Person& obj);
};


fstream& operator >>(fstream& is, Person& obj)
{
	is >> obj._name;
	is >> obj._login;
	is >> obj._pass;
	return is;
}
ostream& operator <<(ostream& os, const Person& obj)
{
	os << obj._name;
	os << ' ';
	os << obj._login;
	os << ' ';
	os << obj._pass;
	return os;
}


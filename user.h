#pragma once



class Person
{
	string _name;
	string _login;
	string _pass;
	

public:
	Person(string name, string login, string pass) :_name(name), _login(login), _pass(pass) {};
	string _text;
	string _sender;
	string _receiver;

	~Person() = default;

	friend fstream& operator >>(fstream& is, Person& obj);
	friend ostream& operator <<(ostream& os, const Person& obj);

	Person() = default;

	Person(const string& _name, const string& _login, const string& _pass)
		: _name(_name), _login(_login), _pass(_pass)
	{
	};
	
};
#pragma once
#include <string>
#include <iostream>
using namespace std;

class User
{
public:
    User(const string& name, const string& login, const string& pass) :
        _name(name), _login(login), _pass(pass) {
    }

    friend ostream& operator <<(ostream& os, User& user);

private:
    string _name;
    string _login;
    string _pass;
};
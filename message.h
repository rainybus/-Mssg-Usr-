#pragma once
#include <iostream>
#include "user.h"



class Message
{
	string _text;
	string _sender;
	string _receiver;

public:
	Message(string text, string sender, string receiver) : _text(text), _sender(sender), _receiver(receiver){};
	Message(string text, string sender, string receiver);
	// ¬Ü¬à¬ß¬ã¬ä¬â¬å¬Ü¬ä¬à¬â
	~Message(); // ¬Õ¬Ö¬ã¬ä¬â¬å¬Ü¬ä¬à¬â
	friend fstream& operator >>(fstream& is, Person& obj);
	friend ostream& operator <<(ostream& os,  Person& obj);
	Message() = default;
};
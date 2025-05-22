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
	// �ܬ�߬����ܬ���
	~Message(); // �լ֬����ܬ���
	friend fstream& operator >>(fstream& is, Person& obj);
	friend ostream& operator <<(ostream& os,  Person& obj);
	Message() = default;
};
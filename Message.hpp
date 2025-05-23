#pragma once
#include <string>
#include <iostream>
using namespace std;


class Message
{
public:
    Message(const string& text, const string& sender, const string& receiver)
        : _text(text), _sender(sender), _receiver(receiver) {
    }

    friend ostream& operator <<(ostream& os, Message& message);

private:
    string _text;
    string _sender;
    string _receiver;
};

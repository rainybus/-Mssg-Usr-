#include"File.hpp"
#include<fstream>
#include<vector>
#include<string>
#include<filesystem>
#include <sstream>
#include <iostream>
namespace fs = filesystem;

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

File::File() {};
File::~File() = default;

int File::userFile() {

    fstream users_file = fstream("Users.txt", ios::in | ios::out);

    if (!users_file)
    {
        users_file = fstream("Users.txt", ios::in | ios::out | ios::trunc);
    }

    if (!users_file.is_open())
    {
        cout << "\t¬¯¬Ö ¬å¬Õ¬Ñ¬Ý¬à¬ã¬î ¬à¬ä¬Ü¬â¬í¬ä¬î ¬æ¬Ñ¬Û¬Ý Users.txt" << endl;
        return -1;
    }
    else
    {

        _users.emplace_back("User1", "1usr", "passwd1");
        _users.emplace_back("User2", "2usr", "passwd2");
        _users.emplace_back("User3", "3usr", "passwd3");
        _users.emplace_back("User4", "4usr", "passwd4");
        _users.emplace_back("User5", "5usr", "passwd5");

        for (auto& user : _users)
        {
            users_file << user << endl;
        }

        cout << "\tUser.txt:" << endl;

        users_file.seekg(0, ios::beg);

        string userName, userLogin, userPass;
        string line;

        cout << endl;
        while (getline(users_file, line))
        {
            std::istringstream input{ line };
            getline(input, userName, ';');
            getline(input, userLogin, ';');
            getline(input, userPass);
            cout << "\tName: " << userName << "\tLogin: " << userLogin << "\tPassword: " << userPass << std::endl;
        }
        cout << endl;
        cout << "\tFile's built-in permissions: ";
        demo_perms(fs::status("Users.txt").permissions());
        fs::permissions("Users.txt",
            fs::perms::group_all | fs::perms::others_all, fs::perm_options::remove);
        fs::permissions("Users.txt",
            fs::perms::owner_all, fs::perm_options::add);

        cout << "\tCurrent permissions: ";
        demo_perms(fs::status("Users.txt").permissions());
    }
    return 0;
}

int File::messageFile() {
    fstream messages_file = fstream("Messages.txt", ios::in | std::ios::out);
    if (!messages_file)
    {
        messages_file = fstream("Messages.txt", ios::in | ios::out | ios::trunc);
    }
    if (!messages_file.is_open())
    {
        cout << "\tCouldn't open Messages.txt" << endl;
        return -1;
    }
    else
    {
        _messages.emplace_back("What's up?", "Oleg", "Maria");
        _messages.emplace_back("Morning!", "Sasha", "Helga");
        _messages.emplace_back("Hi!", "Helga", "Sasha");
        _messages.emplace_back("How do you do!", "Maria", "Boris");
        _messages.emplace_back("Hi, there!", "Boris", "Oleg");
        for (auto& message : _messages)
        {
            messages_file << message << endl;
        }
        cout << endl;
        cout << "\tAll data from Messages.txt:" << endl;
        cout << endl;
        messages_file.seekg(0, ios::beg);
        string messageText, messageSender, messageReceiver;
        string line;

        while (getline(messages_file, line))
        {
            istringstream input{ line };
            getline(input, messageText, ';');
            getline(input, messageSender, ';');
            getline(input, messageReceiver);
            cout << "\t(from) " << messageSender << "\t(to) " << messageReceiver << "\t(message) " << messageText << endl;
        }
        cout << endl;
        cout << "\tFile's built-in permissions: ";
        demo_perms(fs::status("Messages.txt").permissions());
        fs::permissions("Messages.txt",
            fs::perms::group_all | fs::perms::others_all, fs::perm_options::remove);
        fs::permissions("Messages.txt",
            fs::perms::owner_all, fs::perm_options::add);

        cout << "\tCurrent permissions: ";
        demo_perms(fs::status("Messages.txt").permissions());
    }
    return 0;
}

ostream& operator <<(ostream& os, Message& message)
{
    os << message._text;
    os << ';';
    os << message._sender;
    os << ';';
    os << message._receiver;
    return os;
}
ostream& operator <<(ostream& os, User& user)
{
    os << user._name;
    os << ';';
    os << user._login;
    os << ';';
    os << user._pass;
    return os;
}
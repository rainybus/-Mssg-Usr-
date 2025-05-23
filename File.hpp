#pragma once
#include<fstream>
#include<vector>
#include<string>
#include<filesystem>
#include <sstream>
#include"User.hpp"
#include"Message.hpp"
using namespace std;

namespace fs = filesystem;

void demo_perms(fs::perms p);

class File {
    vector<User> _users;
    vector<Message> _messages;

public:
    File();
    ~File();
    int userFile();
    int messageFile();
};
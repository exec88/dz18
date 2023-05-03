#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <cstdio>
using namespace std;


class User
{
public:
    string _name;
    string _login;
    string _pass;

    void save() const
    {
        ofstream out("user_data.txt", ios::binary);
        if (out.is_open())
        {
            out << _name << ' ' << _login << ' ' << _pass;
        }
        out.close();
        filesystem::permissions("user_data.txt", filesystem::perms::owner_all);
    }

    void load()
    {
        filesystem::permissions("user_data.txt", filesystem::perms::owner_all);
        ifstream in("user_data.txt", ios::binary);
        if (in.is_open())
        {
            in >> _name >> _login >> _pass;
        }
        in.close();
        filesystem::permissions("user_data.txt", filesystem::perms::owner_read);
    }
};

class Message
{
public:
    string _text;
    string _sender;
    string _receiver;

    void save() const
    {
        ofstream out("message_data.txt", ios::binary);
        if (out.is_open())
        {
            out << _text << ' ' << _sender << ' ' << _receiver;
        }
        out.close();
        filesystem::permissions("message_data.txt", filesystem::perms::owner_all);
    }

    void load()
    {
        filesystem::permissions("message_data.txt", filesystem::perms::owner_all);
        ifstream in("message_data.txt", ios::binary);
        if (in.is_open())
        {
            in >> _text >> _sender >> _receiver;
        }
        in.close();
        filesystem::permissions("message_data.txt", filesystem::perms::owner_read);
    }
};

int main()
{
    User user;
    user._name = "John";
    user._login = "john123";
    user._pass = "mypassword";
    user.save();
    user._name = "";
    user._login = "";
    user._pass = "";
    user.load();

    Message message;
    message._sender = "john123";
    message._receiver = "admin";
    message._text = "Hello!";
    message.save();
    message._sender = "";
    message._receiver = "";
    message._text = "";
    message.load();

    return 0;
}
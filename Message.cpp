//
// Created by amirh on 8/7/2019.
//

#include <iostream>
#include "Message.h"

using namespace std;

Message::Message(ifstream &_file)
{
    length = 0;
    number_of_headers = 0;
    getline(_file, start_line);
    string line_str;
    getline(_file, line_str);
    while (line_str.find(':') != string::npos)
    {
        if (line_str.find("Content-Length:") != string::npos)
        {
            length = stoi(&line_str[line_str.find_last_of(':') + 1]);
        }
        number_of_headers++;
        getline(_file, line_str);
    }
}

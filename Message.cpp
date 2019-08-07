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
    do
    {
        getline(_file, line_str);
        if (line_str.find("Content-Length:") == string::npos)
        {
            length = stoi(line_str);
        }
        number_of_headers++;
    } while (line_str.find(':') != string::npos);
}

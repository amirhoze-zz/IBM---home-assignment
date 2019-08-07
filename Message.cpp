//
// Created by amirh on 8/7/2019.
//

#include "Message.h"

Message::Message(ifstream _file)
{
    getline(_file, start_line);

    string line_str;
    while (line_str[0] != 'CRLF');
    {
        getline(_file, line_str);
        if (line_str.find("Content-Length:") != string::npos)
        {
            length = stoi(line_str);
        }
        number_of_headers++;
    }
}

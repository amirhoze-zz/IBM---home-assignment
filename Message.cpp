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
        if (line_str.find("Host:") != string::npos)
        {
            host_line = string(line_str.substr(line_str.find_first_of(':') + 1));
        }
        number_of_headers++;
        getline(_file, line_str);
    }
}

string Message::summary()
{
    string summary;
    std::size_t first_space_pos = start_line.find_first_of(' ');
    std::size_t second_space_pos = start_line.find_first_of(' ', first_space_pos + 1);
    if (start_line.find("HTTP/") == 0)
    {
        int code = stoi(start_line.substr(first_space_pos + 1));
        string phrase = start_line.substr(second_space_pos, start_line.size() - 1 - second_space_pos);
        summary = to_string(code) + phrase + " ";

    } else
    {
        string request_method = start_line.substr(0, first_space_pos);
        string request_url = start_line.substr(first_space_pos + 1, (second_space_pos) - (first_space_pos + 1));
        string host_str = host_line.substr(0, host_line.size() - 1);
        summary = request_method + host_str + request_url;
    }
    summary += "(" + to_string(number_of_headers) + " headers, " + to_string(length) + " bytes)";
    return summary;
}

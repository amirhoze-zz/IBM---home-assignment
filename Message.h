//
// Created by amirh on 8/7/2019.
//

#ifndef IBM_HOME_ASSIGNMENT_MESSAGE_H
#define IBM_HOME_ASSIGNMENT_MESSAGE_H

#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Message
{
    string start_line;
    int length;
    int number_of_headers;
public:
    Message(ifstream _file);
};

#endif //IBM_HOME_ASSIGNMENT_MESSAGE_H

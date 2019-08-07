#ifndef IBM_HOME_ASSIGNMENT_MESSAGE_H
#define IBM_HOME_ASSIGNMENT_MESSAGE_H

#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Message
{
    string start_line;
    string host_line;
    int length;
    int number_of_headers;

public:
    explicit Message(ifstream &_file);

    string summary();
};

#endif //IBM_HOME_ASSIGNMENT_MESSAGE_H

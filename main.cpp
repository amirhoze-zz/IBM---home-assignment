#include <iostream>
#include "Message.h"
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
    ifstream input_file_massage(argv[1]);
    if (input_file_massage.is_open())
    {
        Message message(input_file_massage);
        cout << message.summary();
        input_file_massage.close();
    } else
    {
        cout << "unable to open file" << endl;
    }
    return 0;
}
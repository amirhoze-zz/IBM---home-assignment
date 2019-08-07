#include <iostream>
#include "Message.h"

using namespace std;

int main(int argc, char **argv)
{
    ifstream input_file_massage("input_example.txt");
    if (input_file_massage.is_open())
    {
        Message massage(input_file_massage);
        cout << massage.start_line << endl;
        cout << "length = " << massage.length << endl;
        cout << "number_of_headers = " << massage.number_of_headers << endl;
        //input_file_massage.close();
    } else
    {
        cout << "Unable to open file";
    }
    std::cin.get();
    return 0;
}
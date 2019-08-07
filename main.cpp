#include <iostream>
#include "Message.h"
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
    ifstream input_file_massage("C:\\Users\\amirh\\Desktop\\misc\\career\\IBM--home-assignment\\input.txt");
    if (input_file_massage.is_open())
    {
        Message massage(input_file_massage);
        input_file_massage.close();
    } else
    {
        cout << "unable to open file" << endl;
    }

    return 0;
}
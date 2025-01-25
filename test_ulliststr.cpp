#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
    ULListStr dat;
    dat.push_back("1");
    dat.push_back("2");
    dat.push_back("3");
    dat.push_back("4");
    dat.push_back("5");
    dat.push_back("6");
    dat.push_back("7");
    dat.push_back("8");
    dat.push_back("9");
    dat.push_back("10");
    dat.push_back("11");
    dat.push_back("12");

    cout << dat.get(0) << endl;
    cout << dat.get(2) << endl;
    cout << dat.get(11) << endl;
    cout << dat.size() << endl;

    
}

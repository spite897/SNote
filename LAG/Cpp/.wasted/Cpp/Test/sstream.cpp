#include<sstream>
#include"Test.cpp"

using std::istringstream;
using std::ostringstream;
using std::stringstream;
using std::string;

string str;
int num1;
double num2;

int main(){
    istringstream iss{"10 2.5"};
    Alert(istringstream \t: get data from string);
    ostringstream oss{};
    Alert(ostringstream \t: send data to string);
    stringstream  ss{};
    Alert(stringstream \t:  both of io);
    Paging;

    iss >> num1;
    Alert(iss >> num1);
    AlertData(iss,iss.str());
    AlertData(num1,num1);
    iss >> num1 >> num2;
    Paging;

    oss << 45;
    Alert(oss << 45);
    AlertData(oss,oss.str());
    oss.str("");
    Alert(oss.str(""));
    AlertData(oss,oss.str());
    Paging;

    return 0;
}
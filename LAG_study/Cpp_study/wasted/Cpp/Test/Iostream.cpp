#include<iostream>

using std::cout;
using std::cin;
using std::cerr;
using std::clog;
using std::endl;
using std::getline;
using std::string;

int main(){
    int a;
    string str;
    cout << "cout" << endl ;
    cin  >> a;
    clog << "clog" << endl;
    cerr << "cerr" << endl;

    getline(cin,str);

    cout << "cin "     << a   << endl;
    cout << "getline " << str << endl;

    if(cin.fail())      cerr << "Input Invalid" << endl;
    cout << "cin.fail()" << endl;

    return 0;
}
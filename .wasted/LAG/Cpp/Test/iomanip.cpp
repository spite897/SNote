#include<iomanip>
#include"Test.cpp"

using std::setw;
using std::setfill;
using std::setprecision;
using std::fixed;
using std::scientific;
using std::setiosflags;
using std::resetiosflags;

int main(){
    Alert(setw()\t: set the output width);
    Alert(cout << setw(5) << 123);
    cout << setw(5) << 123 << endl;
    Paging;
    
    Alert(setfill()\t: set the char for filling);
    Alert(cout <<  setfill('*') << setw(5) << 123);
    cout<<  setfill('*') << setw(5) << 123 << endl;
    Paging;

    Alert(setprecision()\t: set the decimal );
    Alert(cout << setprecision(1) << 3.15);
    cout << setprecision(1) << 3.15 << endl;
    Paging;

    Alert(fixed\t: change the way outputs decimal );
    Alert(scientific\t: change the way output decimal );
    Alert(cout << fixed << 3.14 << scientific << 3.14);
    cout << fixed << 3.14 << '\t' << scientific << 3.14 << endl;
    Paging;

    Alert(setiosflags()\t: change output form);
    Alert(resetiosflags(\t: cancal the change));
    Alert(cout << std::setiosflags(std::ios::uppercase) <<std::hex <<255 <<'\t' \\\n
        << std::resetiosflags(std::ios::uppercase) << std::hex << 255);
    cout << std::setiosflags(std::ios::uppercase) <<std::hex <<255 <<'\t' << std::resetiosflags(std::ios::uppercase) << std::hex << 255 <<endl;
    return 0;
}
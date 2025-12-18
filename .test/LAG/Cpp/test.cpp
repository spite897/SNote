#include<iostream>
#include<vector>

using namespace std;

void test(){
    vector<int> V(5,4);
    V.push_back(6);
    for(auto p = V.begin();p!=V.end();cout << *(++p) << endl){}
}

int main(){
    test();
    return 0;
}

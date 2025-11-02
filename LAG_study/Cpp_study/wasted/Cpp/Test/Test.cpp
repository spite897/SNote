#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#define Alert(X)    cout << #X  << endl ;
#define AlertE(X)   cout << X   << endl ;
#define Input(X)    cin  >> X           ;
#define Print(X)    cout << #X          ;
#define PrintE(X)   cout << X           ;
#define Paging      Alert(--------------------------------------);
#define AlertData(X,Y)  cout << #X << "\t:" <<Y <<endl;

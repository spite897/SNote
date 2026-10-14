#include<array>
#include"Test.cpp"

using std::array;

int main(){
    array<int,5> A{1,2,3,4,5};
    Alert("array<int,5>\t: create new array");
    
    AlertData(A[0],A[0]);
    Paging;
    A[0] = 5;
    Alert(A[0] =5 );
    AlertData(A[0],A[0]);
    Paging;
    Alert(A.at(0) = 4);
    A.at(0) = 4;
    AlertData(A[0],A[0]);
    Paging;

    Alert(for(const auto& v : A));
    for(const auto& v : A){
        PrintE(v);
    }
    Alert();

    Paging;
    Alert(A.size() A.back() A.front);
    return 0;
}
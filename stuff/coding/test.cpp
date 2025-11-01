#define S_DEBUG

#ifdef S_DEBUG
#include<iostream>
#define Log(X)  std::cout << X << std::endl
#else
#define Log(X)
#endif

#include"Card.cpp"

int main(){
    Log("Test Start");
    return 0;
}

#include<iostream>
#include<string>

#include "LinkedList.h"

using namespace LinkedList_ns;

#define Alert(X)    std::cout << #X << std::endl
#define AlertE(X,Y) std::cout << X  << #Y  <<std::endl
#define Input(X)    std::cin  >> X

void menu(){
    Alert(*************************************);
    Alert(***1.new****2.check****3.add*********);
    Alert(***4.delete*5.elenum***6.getbyData***);
    Alert(*************************************);
}

void controlT(){    
    int rec , i , end =1;
    int tmp1 ,tmp2 , ele_num;
    LinkedList<int>* LL = nullptr; 
    LL = new LinkedList<int>();

    while(end){
    menu();
    Input(rec);
    switch (rec)
    {
    case (1):
        LL = new LinkedList<int>();
        break;
    case (2):
        for(i=0 ; i<ele_num ; i++){
            AlertE(LL->getByIndex(i)->data,->);
        }
        break;
    case (3):
        Alert(param? );
        Input(tmp1);
        LL->addAuto(tmp1);
        break;
    case (4):
        Alert(type? Tail(0) Head(1) Index(2));
        Input(tmp1);
        switch (tmp1)
        {
        case (0):
            LL->deleteTail();
            break;
        case (1):
            LL->deleteHead();
            break;
        default:
            Alert(Index? );
            Input(tmp2);
            LL->deleteByIndex(tmp2);
            break;
        }
        break;
    case(5):
        AlertE(LL->getEleNum() , ele_num);
        break;
    case(6):
        Alert(type? LLEp(0) index(1));
        Input(tmp1);
        Alert(data?);
        Input(tmp2);
        switch (tmp1)
        {
        case (0):
            AlertE(LL->getByData(tmp2),);
            break;
        default:
            AlertE(LL->getIndexByData(tmp2),);
            break;
        }
        break;
    default:
        end = 0;
        break;
    }
    if(LL->head!=nullptr) ele_num = LL->getEleNum();
    Alert(done);
    }
}

int main(){
    Alert(Test Starts);

    controlT();

    LinkedListElement<int> ll = LinkedListElement<int>(10);
    LinkedListElement<int> ll2 = LinkedListElement<int>(15);
    
    ll.next = &ll2;

    AlertE(+ll, );
    AlertE(-ll, );
    AlertE(ll.data, );
    ll.data++;
    ++ll;
    ll--;
    ll++;
    --ll;
    AlertE(ll.data, );
    AlertE(ll[0].data, );
    AlertE(ll[1].data, );

    AlertE(1+ll.data, );
    AlertE(1-ll.data, );

    Alert(Test Exit);
    return 0;
}

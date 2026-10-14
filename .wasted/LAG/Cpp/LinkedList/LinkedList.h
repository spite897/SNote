#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<iostream>

namespace LinkedList_ns{

template <class T>
class LinkedListElement{
public:    
    //指向下一个
    LinkedListElement<T>* next;
    T data;
    LinkedListElement()             : data(0) , next(nullptr){}
    LinkedListElement(const T data_): data(data_) , next(nullptr){}
    LinkedListElement(const T data_ , LinkedListElement<T>* ptr) : data(data_) , next(ptr){}

    std::string toString(){
        return std::to_string(data);
    }
    T operator-(){
        return -data;
    }
    T operator+(){
        return +data;
    }
    T operator++(){
        data++;
        return data;
    }
    T operator++(int){
        T ret = data;
        data++;
        return ret;
    }    
    T operator--(){
        data--;
        return data;
    }
    T operator--(int){
        T ret = data ;
        data--;
        return ret;
    }
    LinkedListElement<T> operator[](const int& index){
        int tmp ;
        LinkedListElement<T>* ret = this;
        for(tmp=0;tmp<index;tmp++)      ret = ret->next;
        return *ret;
    }
    T operator+(const T data_)        {return data+data_;}
    T operator-(const T data_)        {return data-data_;}
    T operator+(const LinkedListElement<T> LLE)        {return data+LLE.data;}
    T operator-(const LinkedListElement<T> LLE)        {return data-LLE.data;}    
    LinkedListElement<T> operator+=(const T data_){
        data += data_;
        return *this;
    }
    LinkedListElement<T> operator-=(const T data_){
        data -= data_;
        return *this;
    }
    LinkedListElement<T> operator+=(const LinkedListElement<T> LLE){
        data += LLE.data;
        return *this;
    }
    LinkedListElement<T> operator-=(const LinkedListElement<T> LLE){
        data -= LLE.data;
        return *this;
    }

    //获取链表元素个数
    int getEleNum(int ret = 1){
        if(next == nullptr)     return ret;
        else                    return next->getEleNum(++ret);
    }
    //根据索引获得元素 改递归为循环提高效率
    LinkedListElement<T>* getByIndex(int index){
        if(index)   return next->getByIndex(--index);
        else        return this;
    }
    //根据内容获取元素  失败返回nullptr
    LinkedListElement<T>* getByData(const T data_){
        if(data == data_)           return this;
        else if(next!=nullptr)      return next->getByData(data_);
        else                        return nullptr;
    }
    //根据内容获取索引  失败返回-1
    int getIndexByData(const T data_ , int ret = 0){
        if(data == data_)           return ret;
        else if(next!=nullptr)      return next->getIndexByData(data_ , ++ret);
        else                        return -1;
    }
    //获取链表最后一个元素
    LinkedListElement<T>* getTail(){
        if(next!=nullptr)     return next->getTail();
        else                  return this;
    }

    //在这个元素后新建一个元素 不会检查是否原有元素
    void addAfterThis(const T data_){
        next = new LinkedListElement<T>(data_);
    }
    //在这个元素后新建并插入一个元素 不会检查
    void insertAfterThis(const T data_){
        LinkedListElement<T>* tmp = next;
        addAfterThis(data_);
        next->next=tmp;
    }
    //自动判断并新建元素
    void addAutoAfterThis(const T data_){
        if(next == nullptr)   addAfterThis(data_);
        else                  insertAfterThis(data_);
    }

    //删除这个元素 无法重置指向他的元素
    void deleteThis(){
        delete this;
    }
    //删除下一个元素 并重置next指针
    void deleteAfterThisPlain(){
        delete next;
        next = nullptr;
    }
    //删除下一个元素 并指向下一个元素
    void deleteAfterThisRepoint(){
        LinkedListElement<T>* tmp = next;
        next = tmp->next;
        delete tmp;
    }
    //自动判断并删除下一个元素
    void deleteAutoAfterThis(){
        if(next == nullptr)   deleteAfterThisPlain();
        else                  deleteAfterThisRepoint();
    }
    //删除整个链表
    void deleteLinkedList(){
        if(next != nullptr)     next->deleteLinkedList();
        delete this;
    }
};

template <class T>
class LinkedList{
public:
    //链表一头
    LinkedListElement<T>* head;
    LinkedList():head(nullptr){}
    ~LinkedList(){
        head->deleteLinkedList();
    }
    
    std::string toString(){
        return head->toString();
    }

    
    //获取元素个数
    int getEleNum(){
        return head->getEleNum();
    }
    //获取链表最后一个元素
    LinkedListElement<T>* getTail(){
        return head->getTail();
    }
    //根据索引获取元素
    LinkedListElement<T>* getByIndex(int index){
        return head->getByIndex(index);
    }
    //根据内容获取元素  失败返回nullptr
    LinkedListElement<T>* getByData(const T data_){
        return head->getByData(data_);
    }
    //根据内容获取索引  失败返回-1
    int getIndexByData(const T data_){
        return head->getIndexByData(data_);
    }
    
    LinkedListElement<T> operator[](const int& index){
        return head[index];
    }

    //添加第一个元素
    void addInit(const T data_ = 0){
        head = new LinkedListElement<T>(data_);
    }
    //在链表最后添加元素
    void addTail(const T data_){
        head->getTail()->addAfterThis(data_);
    }
    //根据索引插入元素
    void addByIndex(const T data_ , int index){
        getByIndex(--index)->addAutoAfterThis(data_);
    }
    //自动新建元素 index为-1即从最后添加
    void addAuto(const T data_ , int index = -1){
        if(head == nullptr)   addInit(data_);
        else if(index == -1)  addTail(data_);
        else                  addByIndex(data_ , index);
    }
    
    //删除最后一个元素 不要在链表只有一个元素时调用
    void deleteTail(){
        head->getByIndex(getEleNum()-2)->deleteAfterThisPlain();
    }
    //删除第一个元素
    void deleteHead(){
        LinkedListElement<T>* tmp = head;
        head = head->next;
        tmp->deleteThis();
    }
    //按照索引删除元素
    void deleteByIndex(int index){
        head->getByIndex(index-1)->deleteAutoAfterThis();  
    }
    //自动删除元素 index为-1即从最后删除
    void deleteAuto(int index = -1){
        if(index=0)         deleteHead();
        else if(index=-1)   deleteTail();
        else                deleteByIndex(index);
    }
};


}; // namespace LL



#endif
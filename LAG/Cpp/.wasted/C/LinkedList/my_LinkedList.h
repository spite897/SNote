#ifndef MY_LINKEDLIST
#define MY_LINKEDLIST

#include<stdlib.h>

/*链表元素
prev -- 前一个链表元素指针 默认NULL下同
data -- 指向内容的指针
next -- 下一个链表元素指针*/
typedef struct linked_list_element {
	struct linked_list_element* prev;
	void* data;
	struct linked_list_element* next;
}LinkedListElement;
/*链表(禁止无链表元素的链表)
first --第一个链表元素
last --最后一个链表元素
ele_num --元素数量
size --内容大小*/
typedef struct linked_list {
	LinkedListElement* first;
	LinkedListElement* last;
	unsigned ele_num;
	unsigned size;
}LinkedList;

//新建链表并初始化 size为元素大小
LinkedList* newLinkedList( unsigned size);
//新建链表元素并初始化
LinkedListElement* newLinkedListElement();
//顺序查找链表 失败返回NULL
LinkedListElement* searchLinkedList(LinkedList* list , void* data);
//逆序查找链表 失败返回NULL
LinkedListElement* searchLinkedListFromLast(LinkedList* list, void* data);
//填充第一个链表元素
LinkedListElement* initLinkedList(LinkedList* list, void* data);
//在链表尾部添加元素
LinkedListElement* addLinkedListElementLast(LinkedList* list , void* data);
//在链表中间添加元素
LinkedListElement* addLinkedListElementMid(LinkedList* list, void* data, unsigned index);
//在链表头部添加元素
LinkedListElement* addLinkedListElementFirst(LinkedList* list, void* data);
//按索引添加元素
LinkedListElement* addLinkedListElement(LinkedList* list, void* data, unsigned index);
//顺序按索引得到链表元素
LinkedListElement* getLinkedListElement(LinkedList* list, unsigned index);
//逆序按索引得到链表元素
LinkedListElement* getLinkedListElementFromLast(LinkedList* list, unsigned index);
//删除第一个链表元素 返回新的first
LinkedListElement* removeLinkedListElementFirst(LinkedList* list);
//删除最后一个链表元素 返回NULL
LinkedListElement* removeLinkedListElementLast(LinkedList* list);
//删除指定的中间链表元素 返回原链表元素的next
LinkedListElement* removeLinkedListElementMid(LinkedList* list, LinkedListElement* target);
//按索引删除链表元素 返回原链表元素的next
LinkedListElement* removeLinkedListElement(LinkedList* list, unsigned index) ;

LinkedList* createLinkedListByArray(void* data,unsigned ele_num ,unsigned size);

/*链表元素
data -- 指向内容的指针 默认NULL下同
next -- 下一个链表元素指针*/
typedef struct slinked_list_element {
	void* data;
	struct slinked_list_element* next;
}sLinkedListElement;
/*链表(禁止无链表元素的链表)
first --第一个链表元素
ele_num --元素数量
size --内容大小*/
typedef struct slinked_list {
	sLinkedListElement first;
	unsigned ele_num;
	unsigned size;
}sLinkedList;


/*
//新建链表并初始化 size为元素大小
LinkedList* newLinkedList(unsigned size);
//新建链表元素并初始化
LinkedListElement* newLinkedListElement();
//顺序查找链表 失败返回NULL
LinkedListElement* searchLinkedList(LinkedList* list, void* data);
//填充第一个链表元素
LinkedListElement* initLinkedList(LinkedList* list, void* data);
//在链表尾部添加元素
LinkedListElement* addLinkedListElementFromLast(LinkedList* list, void* data);
//在链表头部添加元素
LinkedListElement* addLinkedListElement(LinkedList* list, void* data);*/



#endif
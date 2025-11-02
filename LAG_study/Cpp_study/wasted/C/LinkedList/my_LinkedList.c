#include "my_LinkedList.h"

static int _isEqual(void* e1, void* e2, unsigned size) {
	unsigned i = 0;
	for (i = 0; i < size; i++) {
		if (!(*((char*)e1 + i) == *((char*)e2 + i)))
			return 0;
	}
	return 1;
}
static int _write(void* dest, void* data, unsigned size) {
	unsigned i = 0;
	for (i = 0; i < size;i++)
		*((char*)dest + i) = *((char*)data + i);
	return 1;
}
static LinkedListElement* _searchLinkedList(LinkedListElement* list, void* data, unsigned size) {
	if (list == NULL || _isEqual(list->data, data, size)) {
		return list;
	}
	return _searchLinkedList(list->next, data, size);
}
static LinkedListElement* _searchLinkedListFromLast(LinkedListElement* list, void* data, unsigned size) {
	if (list == NULL || _isEqual(list->data, data, size)) {
		return list;
	}
	return _searchLinkedList(list->prev, data, size);
}

LinkedList* newLinkedList(unsigned size) {
	LinkedList *ret =  (LinkedList*)malloc(sizeof(LinkedList));
	if (ret) {
		ret->size = size;
		ret->ele_num = 1;
		ret->first = ret->last = newLinkedListElement();
	}
	return ret;
}
LinkedListElement* newLinkedListElement() {
	LinkedListElement *ret = (LinkedListElement*)malloc(sizeof(LinkedListElement));
	if(ret) ret->next = ret->prev = ret->data = NULL;
	return ret;
}

LinkedListElement* searchLinkedList(LinkedList* list, void* data) {
	return _searchLinkedList(list->first, data , list->size);
}
LinkedListElement* searchLinkedListFromLast(LinkedList* list, void* data) {
	return _searchLinkedListFromLast(list->last, data, list->size);
}

LinkedListElement* initLinkedList(LinkedList* list, void* data) {
	list->first->data = data;
	return list->first;
}

LinkedListElement* addLinkedListElementLast(LinkedList* list, void* data) {
	LinkedListElement* ret = newLinkedListElement();
	ret->data = data;
	ret->prev = list->last;
	list->last->next = ret;
	list->last = ret;
	list->ele_num++;
	return ret;
}
LinkedListElement* addLinkedListElementMid(LinkedList* list, void* data, unsigned index) {
	LinkedListElement* target = NULL , *ret = newLinkedListElement();
	if (index * 2 < list->ele_num) target = getLinkedListElement(list, index);
	else target = getLinkedListElementFromLast(list, index);
	ret->data = data;
	ret->prev = target->prev;
	ret->next = target;
	target->prev->next = ret;
	target->prev = ret;
	list->ele_num++;
	return ret;
}
LinkedListElement* addLinkedListElementFirst(LinkedList* list, void* data) {
	LinkedListElement* ret = newLinkedListElement();
	ret->data = data;
	ret->next = list->first;
	list->first->prev = ret;
	list->first = ret;
	list->ele_num++;
	return ret;
}
LinkedListElement* addLinkedListElement(LinkedList* list, void* data, unsigned index) {
	if (index == 0) {
		return addLinkedListElementFirst(list, data);
	}
	else if (index == list->ele_num - 1) {
		return addLinkedListElementLast(list, data);
	}
	return addLinkedListElementMid(list, data, index);
}

LinkedListElement* getLinkedListElement(LinkedList* list, unsigned index) {
	LinkedListElement *ret = list->first;
	for (;index--;) {
		ret = ret->next;
	}
	return ret;
}
LinkedListElement* getLinkedListElementFromLast(LinkedList* list, unsigned index) {
	LinkedListElement* ret = list->last;
	for (; index--;) {
		ret = ret->prev;
	}
	return ret;
}

LinkedListElement* removeLinkedListElementFirst(LinkedList* list) {
	LinkedListElement *ret = list->first;
	ret->next->prev = NULL;
	list->first = ret->next;
	free(ret);
	list->ele_num--;
	return list->first;
}
LinkedListElement* removeLinkedListElementLast(LinkedList* list) {
	LinkedListElement* ret = list->last;
	ret->prev->next = NULL;
	list->last = ret->prev;
	free(ret);
	list->ele_num--;
	return NULL;
}
LinkedListElement* removeLinkedListElementMid(LinkedList* list, LinkedListElement* target) {
	LinkedListElement* ret = target->prev;
	target->next->prev = target->prev;
	target->prev->next = target->next;
	free(target);
	list->ele_num--;
	return ret;
}
LinkedListElement* removeLinkedListElement(LinkedList* list, unsigned index) {
	LinkedListElement* ret = NULL;
	if (index == 0) {
		return removeLinkedListElementFirst(list);
	}
	else if (index == list->ele_num -1) {
		return removeLinkedListElementLast(list);
	}

	if (index * 2 < list->ele_num) ret = getLinkedListElement(list, index);	
	else ret = getLinkedListElementFromLast(list, index);
	return removeLinkedListElementMid(list, ret);
}

LinkedList* createLinkedListByArray(void* data,unsigned ele_num, unsigned size) {
	LinkedList* ret = newLinkedList(size);
	unsigned i = 0;
	initLinkedList(ret, data);

	for(i=1;i<ele_num;i++){
		addLinkedListElementLast(ret, (((char*)data) + i*size));
	}
	return ret;
}


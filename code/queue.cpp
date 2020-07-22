#include "pch.h"
#include <iostream>
using namespace std;
template <class T>
struct LinkNode {
	T data;
	LinkNode* next;
};
template <class T>
class queue {
public:
	//���캯��
	queue();
	//��������
	~queue();
	//�ж϶����Ƿ�Ϊ�գ�Ϊ�շ���true�����򷵻�false
	bool queueEmpty();
	//���
	void enQueue(T data);
	//����
	T deQueue();
	//��ȡ��ͷԪ��
	T getHead();
	//���ض��г���
	int getLength();
	//�������������Ԫ��
	void clearQueue();
private:
	LinkNode<T>* front;
	LinkNode<T>* rear;
	int length;
};
template <class T>
void queue<T>::clearQueue() {
	LinkNode<T> *p = front->next;
	while (p) {
		p = front->next;
		front = front->next;
		free(p);
		p = front;
	}
	length = 0;
}
template <class T>
int queue<T>::getLength() {
	return length;
}
template <class T>
T queue<T>::getHead() {
	if (length == 0) {
		throw range_error("the size of queue is zero");
	}
	else {
		LinkNode<T>* node = front->next;
		return node->data;
	}
}
template <class T>
T queue<T>::deQueue() {
	if (length == 0) {
		throw range_error("the size of queue is zero");
	}
	else {
		LinkNode<T>* node = front->next;
		front = front->next;
		length--;
		return node->data;
	}
}
template <class T>
void queue<T>::enQueue(T data) {
	LinkNode<T>* newNode = new LinkNode<T>[1];
	newNode->data = data;
	newNode->next = NULL;
	rear->next = newNode;
	rear = rear->next;
	length++;
}
template <class T>
bool queue<T>::queueEmpty() {
	if (length == 0) {
		return true;
	}
	else {
		return false;
	}
}
template <class T>
queue<T>::~queue() {
	LinkNode<T> *p=front->next;
	while (p) {
		p = front->next;
		front = front->next;
		free(p);
		p = front;
	}
	length = 0;
	free(front);
}
template <class T>
queue<T>::queue() {
	length = 0;
	front=new LinkNode<T>[1];
	rear = front;
	front->next = NULL;
}
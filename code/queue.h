#ifndef _QUEUE_H_
#define _QUEUE_H_
using namespace std;
template <class T>
struct LinkNode {
	T data;
	LinkNode* next;
};
template <class T>
class queue {
public:
	//构造函数
	queue() {
		length = 0;
		front = new LinkNode<T>[1];
		rear = front;
		front->next = NULL;
	};
	//析构函数
	~queue() {
		LinkNode<T> *p = front->next;
		while (p) {
			p = front->next;
			front = front->next;
			free(p);
			p = front;
		}
		length = 0;
		free(front);
	};
	//判断队列是否为空，为空返回true，否则返回false
	bool queueEmpty() {
		if (length == 0) {
			return true;
		}
		else {
			return false;
		}
	};
	//入队
	void enQueue(T data) {
		LinkNode<T>* newNode = new LinkNode<T>[1];
		newNode->data = data;
		newNode->next = NULL;
		rear->next = newNode;
		rear = rear->next;
		length++;
	};
	//出队
	T deQueue() {
		if (length == 0) {
			throw range_error("the size of queue is zero");
		}
		else {
			LinkNode<T>* node = front->next;
			front = front->next;
			length--;
			return node->data;
		}
	};
	//读取队头元素
	T getHead() {
		if (length == 0) {
			throw range_error("the size of queue is zero");
		}
		else {
			LinkNode<T>* node = front->next;
			return node->data;
		}
	};
	//返回队列长度
	int getLength() {
		return length;
	};
	//清除队列中所有元素
	void clearQueue() {
		LinkNode<T> *p = front->next;
		while (p) {
			p = front->next;
			front = front->next;
			free(p);
			p = front;
		}
		length = 0;
	};
private:
	LinkNode<T>* front;
	LinkNode<T>* rear;
	int length;
};
#endif

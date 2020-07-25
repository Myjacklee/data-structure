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
	//���캯��
	queue() {
		length = 0;
		front = new LinkNode<T>[1];
		rear = front;
		front->next = NULL;
	};
	//��������
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
	//�ж϶����Ƿ�Ϊ�գ�Ϊ�շ���true�����򷵻�false
	bool queueEmpty() {
		if (length == 0) {
			return true;
		}
		else {
			return false;
		}
	};
	//���
	void enQueue(T data) {
		LinkNode<T>* newNode = new LinkNode<T>[1];
		newNode->data = data;
		newNode->next = NULL;
		rear->next = newNode;
		rear = rear->next;
		length++;
	};
	//����
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
	//��ȡ��ͷԪ��
	T getHead() {
		if (length == 0) {
			throw range_error("the size of queue is zero");
		}
		else {
			LinkNode<T>* node = front->next;
			return node->data;
		}
	};
	//���ض��г���
	int getLength() {
		return length;
	};
	//�������������Ԫ��
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

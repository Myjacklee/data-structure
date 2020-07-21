#include "pch.h"
#include <iostream>
using namespace std;
template <class T> 
class vector {
private:
	int vectorSize;
	T *vectorNode;
	int initSize = 10;
public :
	vector(int capicity);
	vector();
	//插入元素
	bool push(T data);
	//弹出元素
	T pop();
	//返回容器的大小
	int size();
};
template<class T>
T vector<T>::pop() {
	if (vectorSize == 0) {
		return NULL;
	}
	else {
		return *vectorNode(--vectorSize);
	}
}
template<class T>
bool vector<T>::push(T data) {
	if (vectorSize == initSize) {
		T *newVector = new T[initSize * 2];
		for (int i = 0; i < vectorSize; i++) {
			*(newVector+i) = *(vectorNode+i);
		}
		free(vectorNode);
		vectorNode = newVector;
		initSize = initSize * 2;
	}
	*(vectorNode+vectorSize++) = data;
	return true;
}
template<class T>
vector<T>::vector(int capicity) {
	initSize = capicity;
	vectorNode = new T[initSize];
	vectorSize = 0;
}
template<class T>
vector<T>::vector() {
	vectorNode = new T[initSize];
	vectorSize = 0;
}
template<class T>
int vector<T>::size() {
	return vectorSize;
}

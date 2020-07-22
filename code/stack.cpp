#include "pch.h"
#include <iostream>
#include "vector.cpp"
using namespace std;
template <class T>
class stack :public vector<T> {
public:
	//����ջ��Ԫ��
	T top();
private:
	//�޸ĸ���at()�����ķ���Ȩ��
	T at(int location);
};
template <class T>
T stack<T>::top() {
	if (this->vectorSize == 0) {
		throw range_error("the size of vector is zero");
	}
	else {
		return *(this->vectorNode + this->vectorSize - 1);
	}
}
template <class T>
T stack<T>::at(int location) {
	if (location < 0 || location >= this->vectorSize) {
		throw range_error("index out of range");
	}
	else {
		return *(this->vectorNode + location);
	}
}
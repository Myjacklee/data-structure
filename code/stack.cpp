#include "pch.h"
#include <iostream>
#include "vector.cpp"
using namespace std;
template <class T>
class stack :public vector<T> {
public:
	//返回栈顶元素
	T top();
private:
	//修改父类at()方法的访问权限
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
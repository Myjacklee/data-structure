#ifndef _STACK_H_
#define _STACK_H_
#include "vector.h"
template <class T>
class stack :public vector<T> {
public:
	//����ջ��Ԫ��
	T top() {
		if (this->vectorSize == 0) {
			throw range_error("the size of vector is zero");
		}
		else {
			return *(this->vectorNode + this->vectorSize - 1);
		}
	};
private:
	//�޸ĸ���at()�����ķ���Ȩ��
	T at(int location) {
		if (location < 0 || location >= this->vectorSize) {
			throw range_error("index out of range");
		}
		else {
			return *(this->vectorNode + location);
		}
	};
	void erase(int location) {
		
	}
	bool push(T data, int location) {
		return false;
	}
};
#endif

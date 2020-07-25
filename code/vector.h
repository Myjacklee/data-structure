#ifndef _VECTOR_H_
#define _VECTOR_H_
using namespace std;
template <class T>
class vector {
protected:
	//当前容器内元素的个数
	int vectorSize;
	T *vectorNode;
	//当前容器的大小
	int initSize = 10;
public:
	//含参构造函数
	vector(int capicity) {
		initSize = capicity;
		vectorNode = new T[initSize];
		vectorSize = 0;
	};
	//构造函数
	vector() {
		vectorNode = new T[initSize];
		vectorSize = 0;
	};
	//析构函数
	~vector() {
		free(vectorNode);
	};
	//插入元素
	bool push(T data) {
		if (vectorSize == initSize) {
			T *newVector = new T[initSize * 2];
			for (int i = 0; i < vectorSize; i++) {
				*(newVector + i) = *(vectorNode + i);
			}
			free(vectorNode);
			vectorNode = newVector;
			initSize = initSize * 2;
		}
		*(vectorNode + vectorSize++) = data;
		return true;
	};
	//弹出元素
	T pop() {
		if (vectorSize == 0) {
			throw range_error("the size of vector is zero");
		}
		else {
			return *(vectorNode + --vectorSize);
		}
	};
	//返回容器的大小
	int size() {
		return vectorSize;
	};
	//返回指定位置的元素
	T at(int location) {
		if (location < 0 || location >= vectorSize) {
			throw range_error("index out of range");
		}
		else {
			return *(vectorNode + location);
		}
	};
	//清空容器中所有的元素
	void clear() {
		free(vectorNode);
		initSize = 10;
		vectorSize = 0;
	};
};

#endif

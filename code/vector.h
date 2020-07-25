#ifndef _VECTOR_H_
#define _VECTOR_H_
using namespace std;
template <class T>
class vector {
protected:
	//��ǰ������Ԫ�صĸ���
	int vectorSize;
	T *vectorNode;
	//��ǰ�����Ĵ�С
	int initSize = 10;
public:
	//���ι��캯��
	vector(int capicity) {
		initSize = capicity;
		vectorNode = new T[initSize];
		vectorSize = 0;
	};
	//���캯��
	vector() {
		vectorNode = new T[initSize];
		vectorSize = 0;
	};
	//��������
	~vector() {
		free(vectorNode);
	};
	//����Ԫ��
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
	//����Ԫ��
	T pop() {
		if (vectorSize == 0) {
			throw range_error("the size of vector is zero");
		}
		else {
			return *(vectorNode + --vectorSize);
		}
	};
	//���������Ĵ�С
	int size() {
		return vectorSize;
	};
	//����ָ��λ�õ�Ԫ��
	T at(int location) {
		if (location < 0 || location >= vectorSize) {
			throw range_error("index out of range");
		}
		else {
			return *(vectorNode + location);
		}
	};
	//������������е�Ԫ��
	void clear() {
		free(vectorNode);
		initSize = 10;
		vectorSize = 0;
	};
};

#endif

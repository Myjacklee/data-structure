#pragma once
#ifndef  _ALGORITHM_H_
#define _ALGORITHM_H_
#include <string>
using namespace std;
class algorithm
{
public:
	algorithm();
	~algorithm();
	int KMPsearch(string text,string pattern);
	/*Gennext���ɵ�next���������KMPsearch�г��ֲ�ƥ������ģʽ����ָ��ָ��next[j]
	���������ƥ�䣬����ģʽ���е��±��Ǵ�0����ʼ������
	*/
	void genNext(int *next,string pattern);
	void bookNext(string pattern, int *next);
};

#endif // ! _ALGORITHM_H_



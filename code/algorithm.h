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
	/*Gennext生成的next表中如果在KMPsearch中出现不匹配则令模式串的指针指向next[j]
	后继续进行匹配，且有模式串中的下标是从0，开始计数的
	*/
	void genNext(int *next,string pattern);
	void bookNext(string pattern, int *next);
};

#endif // ! _ALGORITHM_H_



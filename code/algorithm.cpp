#include "pch.h"
#include <iostream>
#include "algorithm.h"

int algorithm::KMPsearch(string text,string pattern) {
	if (text.length() < pattern.length()) {
		return -1;
	}
	int *next = new int[pattern.length() + 1];
	genNext(next,pattern);
	int i = 0, j = 0;
	while (j < pattern.length()) {
		if (text.at(i) == pattern.at(j)) {
			i++;
			j++;
		}
		else if (j == 0) {
			i++; //当模式串的游标处于串首时，模式串的j游标不变，主串的i游标+1
		}
		else {
			j = next[j - 1]; //当模式串游标对应字符与主串游标对应字符不相等时，模式串游标取左部对应next的值
		}
	}
	delete[] next;
	if (j == pattern.length()) {
		return (i - j);
	}
	else {
		return -1;
	}
}
void algorithm::genNext(int *next,string pattern) {
	next[0] = 0;
	int i = 0, j = 1;
	while (j < pattern.length()) {
		if ( pattern[i] == pattern[j]) {
			next[j] = i+1; //匹配成功后前后缀即意味着有重合的地方，在后缀尾部储存前缀尾部后一位的坐标，以方便在串匹配的时候查询模式串移动的位置
			i++; j++;
		}
		else if (i==0) {
			next[j] = next[0];
			j++;
		}
		else {
			i = next[i-1];
		}
	}
	//for (int i = 0; i < pattern.length(); i++) {
	//	std::cout << next[i] << " ";
	//}
	//std::cout << endl;
}

//王道教材数据结构 P116实现
void algorithm::bookNext(string pattern, int *next) {
	int i = 1, j = 0;
	next[1] = 0;
	while (i < pattern.length()) {
		if (j == 0 || pattern.at(i) == pattern.at(j)) {
			++i; ++j;
			next[i] = j;
		}
		else {
			j = next[j];
		}
	}
	for (int i = 0; i < pattern.length(); i++) {
		std::cout << next[i] << " ";
	}
	std::cout << endl;
}
algorithm::algorithm()
{
}


algorithm::~algorithm()
{
}

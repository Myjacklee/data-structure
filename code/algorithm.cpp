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
			i++; //��ģʽ�����α괦�ڴ���ʱ��ģʽ����j�α겻�䣬������i�α�+1
		}
		else {
			j = next[j - 1]; //��ģʽ���α��Ӧ�ַ��������α��Ӧ�ַ������ʱ��ģʽ���α�ȡ�󲿶�Ӧnext��ֵ
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
			next[j] = i+1; //ƥ��ɹ���ǰ��׺����ζ�����غϵĵط����ں�׺β������ǰ׺β����һλ�����꣬�Է����ڴ�ƥ���ʱ���ѯģʽ���ƶ���λ��
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

//�����̲����ݽṹ P116ʵ��
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

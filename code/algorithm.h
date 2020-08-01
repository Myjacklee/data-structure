#pragma once
#ifndef  _ALGORITHM_H_
#define _ALGORITHM_H_
#include <string>
#include <map>
using namespace std;
struct treeNode {
	char data;
	int weight;
	treeNode* lchild;
	treeNode* rchild;
};
class algorithm
{
public:
	algorithm();
	~algorithm();
	//KMP�����㷨
	int KMPsearch(string text,string pattern);
	/*Gennext���ɵ�next���������KMPsearch�г��ֲ�ƥ������ģʽ����ָ��ָ��next[j]
	���������ƥ�䣬����ģʽ���е��±��Ǵ�0����ʼ������
	*/
	void genNext(int *next,string pattern);
	void bookNext(string pattern, int *next);
	//huffman����
	void huffmanCode(string input);
	void huffmanCodeGenCode(treeNode* tree, string code, map<char, string> &res);
};

#endif // ! _ALGORITHM_H_



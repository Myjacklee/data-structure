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
	//���������ͼ��weightΪ0Ϊ��Ȩͼ��weightΪ1Ϊ��Ȩͼ
	int **genMap(int length,int weight);
	//BFS���ҵ�Դ���·��,��0��ʼ������Ϊlength��ͼ����������±�Ϊlength-1
	void BFS_MIN_Distance(int **Graph,int length, int u);
	//Dijkstra���Ȩͼ���·��
	void Dijkstra(int **Graph, int length, int u);
	//Dijkstra�㷨��Ѱ�ҵ�ǰ�Ƿ��л�û�б����ʵĽ��
	int DijkstraFn1(bool *final, int *dist, int length);
	//Floyd�㷨���Ȩͼ�����������֮������·��
	int Floyd(int **Graph, int length, int u);
	//Floyd�㷨������·��
	void FloydPrint(int **path, int l, int r);
};

#endif // ! _ALGORITHM_H_



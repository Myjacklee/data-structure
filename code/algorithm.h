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
	//KMP查找算法
	int KMPsearch(string text,string pattern);
	/*Gennext生成的next表中如果在KMPsearch中出现不匹配则令模式串的指针指向next[j]
	后继续进行匹配，且有模式串中的下标是从0，开始计数的
	*/
	void genNext(int *next,string pattern);
	void bookNext(string pattern, int *next);
	//huffman编码
	void huffmanCode(string input);
	void huffmanCodeGenCode(treeNode* tree, string code, map<char, string> &res);
	//生成随机地图，weight为0为无权图，weight为1为有权图
	int **genMap(int length,int weight);
	//BFS查找单源最短路径,从0开始，长度为length的图，最大坐标下标为length-1
	void BFS_MIN_Distance(int **Graph,int length, int u);
	//Dijkstra求带权图最短路径
	void Dijkstra(int **Graph, int length, int u);
	//Dijkstra算法中寻找当前是否有还没有被访问的结点
	int DijkstraFn1(bool *final, int *dist, int length);
	//Floyd算法求带权图任意两个结点之间的最短路径
	int Floyd(int **Graph, int length, int u);
	//Floyd算法输出最短路径
	void FloydPrint(int **path, int l, int r);
	//随机生成长度为n的数组，范围为0到range-1
	int *genArray(int arrayLength,int range);
	//直接插入排序
	void directInsertSort(int *arr,int length);
	//希尔排序
	void shellSort(int *arr, int length);
	//冒泡排序
	void bubbleSort(int *arr, int length);
	//快速排序
	void quickSort(int *arr, int low,int high);
	//快速排序辅助函数
	int partition(int *arr, int low, int high);
};

#endif // ! _ALGORITHM_H_



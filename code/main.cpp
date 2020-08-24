// code.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "pch.h"
#include <iostream>
#include "stack.h"
#include "queue.h"
#include "vector.h"
#include "algorithm.h"

using namespace std;
int main() {
	/*
	Dijkstra求带权图最短路径测试
	*/
	

	/*
	BFS广度优先遍历算法求无权图最短路径测试	
	*/
	algorithm ar;
	int **newMap = ar.genMap(6,0);
	ar.BFS_MIN_Distance(newMap, 6, 4);

	/*
	huffman编码测试
	*/
	//algorithm ar;
	//string code = "In computer science and information theory, a Huffman code is a particular type of optimal prefix code that is commonly used for lossless data compression. The process of finding or using such a code proceeds by means of Huffman coding, an algorithm developed by David A. Huffman while he was a Sc.D. student at MIT, and published in the 1952 paper A Method for the Construction of Minimum - Redundancy Codes.";
	//string code2 = "a";
	//ar.huffmanCode(code);

	/*
	KMP算法测试代码
	*/
	//algorithm ar;
	//string text = "abcbcglx";
	//string pattern = "bcgl";
	//cout << ar.KMPsearch(text, pattern)<<endl;

	//string s = "abcac";
	//string s2 = "abcdabca";
	//algorithm ar;
	//int* next = new int[20];
	////ababaaababaa
	////ar.genNext(next,s);
	//ar.bookNext(s, next);


	/*
	队列测试代码
	*/
	//queue<int> firstQueue;
	//for (int i = 0; i < 10; i++) {
	//	firstQueue.enQueue(i);
	//}
	//cout << "队列的长度为：" << firstQueue.getLength() << endl;
	//for (int i = 0; i < 10; i++) {
	//	
	//	cout << "成功删除 " << firstQueue.deQueue()<< " 个元素" << endl;
	//}
	//cout << "队列的长度为：" << firstQueue.getLength() << endl;


	/*
	栈测试代码
	*/
	//stack<int> firststack;
	//for (int i = 0; i < 10; i++) {
	//	firststack.push(i);
	//}
	//cout << "当前栈顶元素为：" << firststack.top() << endl;
	//for (int i = 0; i < 10; i++) {
	//	cout << "成功弹出元素 " << firststack.pop() << endl;
	//}



	/*
	vector测试代码
	*/
	//vector<int> firstVector;
	//for (int i = 0; i < 10; i++) {
	//	firstVector.push_back(i);
	//}
	//cout << firstVector.at(10) << endl;
	//for (int i = 0; i < 20; i++) {
	//	firstVector.push(i);
	//}
	//cout << firstVector.size() << endl;
	//try {
	//	for (int i = 0; i < 21; i++) {
	//		cout << firstVector.pop() << endl;
	//	}		
	//}
	//catch (range_error &e) {
	//	cout << e.what() << endl;
	//}
	//try {
	//	cout << firstVector.at(20)<<endl;
	//}
	//catch (range_error &e) {
	//	cout << e.what() << endl;
	//}
	
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

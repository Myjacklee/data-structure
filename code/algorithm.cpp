#include "pch.h"
#include <iostream>
#include <string>
#include "algorithm.h"
#include "vector.h"
#include "stack.h"
#include "queue.h"
#include <cstdlib>
#include <ctime>
#include <map>
#include <iomanip>
int algorithm::DijkstraFn1(bool *final, int *dist,int length) {
	int minNode=0;
	bool isIn = false;
	for (int i = 0; i < length; i++) {
		if (final[i] == false && dist[minNode] > dist[i]) {
			minNode = i;
			isIn = true;
		}
	}
	if (isIn) {
		return minNode;
	}
	else {
		return -1;
	}
}
void algorithm::Dijkstra(int **Graph, int length, int u) {
	//是否已找到最短路径
	bool *final = new bool[length];
	//当前最短路径长度
	int *dist = new int[length];
	//最短路径上的前驱结点
	int *path = new int[length];
	cout << "随机生成的无权图为：" << endl;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			cout << setw(4)<<Graph[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < length; i++) {
		dist[i] = INT_MAX;
		path[i] = -1;
		final[i] = false;
	}
	final[u] = true;
	dist[u] = 0;
	int nowNode = u;
	while (true) {
		for (int i = 0; i < length; i++) {
			if ((!final[i])&&Graph[nowNode][i] != 0 && dist[nowNode] + Graph[nowNode][i] < dist[i]) {
				dist[i] = dist[nowNode] + Graph[nowNode][i];
				path[i] = nowNode;
			}
		}
		int minNode=-1;
		bool isIn = false;
		for (int i = 0; i < length; i++) {
			if (!final[i]) {
				if (!isIn) {
					minNode = i;
					isIn = true;
				}
				if (dist[i] < dist[minNode]) {
					minNode = i;
				}
			}
		}
		if (!isIn) {
			break;
		}
		else {
			final[minNode] = true;
			nowNode = minNode;
		}
	}
	stack<int> temp;
	for (int i = 0; i < length; i++) {
		if (dist[i] == INT_MAX) {
			cout << "结点" << u << "到结点" << i << "没有路径" << endl;
		}
		else {
			cout << "结点" << u << "到结点" << i << "的路径长度为" << dist[i] << endl;
			int rout = i;
			while (rout != -1) {
				temp.push(rout);
				rout = path[rout];
			}
			while (temp.size() != 1) {
				cout << temp.pop() << "->";
			}
			cout << temp.pop() << endl;
		}
	}
	for (int i = 0; i < length; i++) {
		delete[]Graph[i];
	}
	delete[] Graph;
	delete[] path;
	delete[] dist;
	delete[] final;
}
void algorithm::BFS_MIN_Distance(int **Graph,int length, int u) {
	//当前结点是否被访问过
	bool *visited = new bool[length];
	//当前结点的路径长度
	int *path = new int[length];
	//当前结点的上一个结点
	int *from = new int[length];
	//广度优先遍历队列
	queue<int> BFSQueue;
	cout << "随机生成的无权图为：" << endl;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			cout << Graph[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < length; i++) {
		path[i] = INT_MAX; //初始化路径长度
		from[i] = -1;//初始化前驱结点
		visited[i] = false;
	}
	path[u] = 0;
	visited[u] = true;
	BFSQueue.enQueue(u);
	while (!BFSQueue.queueEmpty()) {
		int head = BFSQueue.deQueue();
		for (int i = 0; i < length; i++) {
			if (!visited[i]&&Graph[head][i]==1) {
				path[i] = path[head] + 1;
				from[i] = head;
				visited[i] = true;
				BFSQueue.enQueue(i);
			}
		}
	}
	stack<int> temp;
	for (int i = 0; i < length; i++) {
		if (path[i] == INT_MAX) {
			cout << "结点" << u << "到结点" << i << "没有任何路径" << endl;
		}
		else {
			cout << "结点" << u << "到结点" << i << "的路径长度为" <<path[i]<< endl;
			int rout = i;
			while (rout!=-1) {
				temp.push(rout);
				rout = from[rout];
			}
			while (temp.size() != 1) {
				cout << temp.pop() << "->";
			}
			cout << temp.pop()<<endl;
		}		
	}
	delete[] visited;
	delete[] path;	
	delete[] from;
	for (int i = 0; i < length; i++) {
		delete[]Graph[i];
	}
	delete[] Graph;
}
int **algorithm::genMap(int length,int weight) {
	int **newMap = new int*[length];
	for (int i = 0; i < length; i++) {
		newMap[i] = new int[length];
	}
	srand((int)time(0));
	if (weight == 0) {
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < length; j++) {
				if (i == j) {
					newMap[i][j] = 0;
				}
				else {
					newMap[i][j] = rand() % 2 ;
				}
			}
		}		
	}
	else {
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < length; j++) {
				if (i == j) {
					newMap[i][j] = 0;
				}
				else {
					newMap[i][j] = (rand() % 100)*(rand() % 2);
				}
			}
		}
	}

	//for (int i = 0; i < length; i++) {
	//	for (int j = 0; j < length; j++) {
	//		cout << newMap[i][j]<<" ";
	//	}
	//	cout << endl;
	//}
	return newMap;
}
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
//huffman编码递归辅助函数
void algorithm::huffmanCodeGenCode(treeNode* tree, string code, map<char, string> &res) {
	if (tree->lchild == NULL && tree->rchild == NULL) {
		res[tree->data] = code;
	}
	else {
		huffmanCodeGenCode(tree->lchild, code + "1", res);
		huffmanCodeGenCode(tree->rchild, code + "0", res);
	}
}
//huffman编码
void algorithm::huffmanCode(string input) {
	map<char, int> countChar;
	for (int i = 0; i < input.length(); i++) {
		if (countChar.count(input.at(i)) == 0) {
			countChar[input.at(i)] = 0;
		}
		countChar[input.at(i)]++;
	}
	cout << "输入的字符串为：" << endl << input << endl;
	cout << "各个字符的出现次数如下" << endl;
	for (map<char, int>::iterator it = countChar.begin(); it != countChar.end(); it++) {
		cout << it->first << " : " << it->second << endl;
	}
	if (countChar.size() == 1) {
		map<char, string> res;
		res[input.at(0)] = "1";
		cout << "编码结果为" << endl;
		for (map<char, string>::iterator it = res.begin(); it != res.end(); it++) {
			cout << it->first << " :" << it->second << endl;
		}
		cout << "对应输出为" << endl;
		for (int i = 0; i < input.length(); i++) {
			cout << res[input.at(i)];
		}
		cout << endl;
		return;
	}
	vector<treeNode*> storage;
	for (map<char, int>::iterator it = countChar.begin(); it != countChar.end(); it++) {
		treeNode *temp=new treeNode();
		temp->data = it->first;
		temp->weight = it->second;
		temp->lchild = NULL;
		temp->rchild = NULL;
		storage.push(temp);
	}
	treeNode *temp;
	for (int i = 0; i < storage.size()-1; i++) {
		for (int j = i + 1; j < storage.size(); j++) {
			if (storage.at(i)->weight < storage.at(j)->weight) {
				temp = storage.at(j);
				storage.at(j) = storage.at(i);
				storage.at(i) = temp;
			}
		}
	}
	cout << "排序后" << endl;
	for (int i = 0; i < storage.size(); i++) {
		cout << storage.at(i)->data << " :" << storage.at(i)->weight << endl;
	}
	while (storage.size() != 1) {
		treeNode *newTreeNode=new treeNode();
		newTreeNode->weight = storage.at(storage.size() - 1)->weight + storage.at(storage.size() - 2)->weight;
		if (storage.at(storage.size() - 1)->weight < storage.at(storage.size() - 2)->weight) {
			newTreeNode->lchild = storage.at(storage.size() - 1);
			newTreeNode->rchild = storage.at(storage.size() - 2);
		}
		else {
			newTreeNode->lchild = storage.at(storage.size() - 2);
			newTreeNode->rchild = storage.at(storage.size() - 1);
		}
		storage.erase(storage.size() - 1);
		storage.erase(storage.size() - 1);
		int i;
		for (i = 0; i < storage.size(); i++) {
			if (storage.at(i)->weight > newTreeNode->weight) {
				continue;
			}
			else {
				break;
			}
		}
		if (i == storage.size()||i==0) {
			storage.push(newTreeNode);
		}
		else {
			storage.push(newTreeNode, --i);
		}
	}
	treeNode *output = storage.pop();
	//左1右0进行编码
	map<char, string> res;
	huffmanCodeGenCode(output, "", res);
	cout<<"编码结果为"<<endl;
	for (map<char, string>::iterator it = res.begin(); it != res.end(); it++) {
		cout << it->first << " :" << it->second << endl;
	}
	cout << "对应输出为" << endl;
	for (int i = 0; i < input.length(); i++) {
		cout << res[input.at(i)];
	}
	cout << endl;
}

algorithm::algorithm()
{
}


algorithm::~algorithm()
{
}

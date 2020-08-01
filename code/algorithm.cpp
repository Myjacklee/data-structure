#include "pch.h"
#include <iostream>
#include <string>
#include "algorithm.h"
#include "vector.h"
#include "stack.h"
#include <map>

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

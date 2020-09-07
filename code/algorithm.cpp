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
int algorithm::partition(int *arr, int low, int high) {
	int pivot = arr[low];
	while (low < high) {
		while (low<high&&arr[high]>=pivot)
			high--;
		arr[low] = arr[high];
		while (low < high&&arr[low] <= pivot)
			low++;
		arr[high] = arr[low];
	}
	arr[low] = pivot;
	return low;
}
void algorithm::quickSort(int *arr, int low,int high) {
	if (low < high) {
		int mid = partition(arr, low, high);
		quickSort(arr, low, mid - 1);
		quickSort(arr, mid + 1, high);
	}
}
void algorithm::bubbleSort(int *arr, int length) {
	int count = 0;
	for (int i = length - 1; i>0; i--) {
		bool flag = false;
		for (int j = 0; j < i-1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				flag = true;
			}
		}
		if (flag) {
			cout << "�� " << ++count << " ��:" ;
			for (int i = 0; i < length; i++) {
				if (i >= length - count) {
					cout <<"["<<arr[i] << "] ";
				}
				else {
					cout << arr[i] << " ";
				}
			}
			cout << endl;		
		}
		else {
			cout << "���������Ѵ�������״̬�������ٱ���" << endl;
		}

	}
	cout << "����Ľ��Ϊ:";
	for (int i = 0; i < length; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	delete[]arr;
}
void algorithm::shellSort(int *arr, int length) {
	int temp;
	int j;
	int count = 0;
	for (int k = length / 2; k >= 1; k = k / 2) {
		for (int i = k; i < length; i+=k) {
			if (arr[i - k] > arr[i]) {
				temp = arr[i];
				for (j = i - k; j >= 0 && arr[j] > temp; j-=k)
					arr[j + k] = arr[j];
				arr[j + k] = temp;
			}
		}
		cout << "�� " << ++count << " ��(��ǰ���� "<<k<<" ):";
		for (int i = 0; i < length; i++) {
			if (i%k == 0) {
				cout << "[" << arr[i] << "] ";
			}
			else {
				cout << arr[i] << " ";
			}
		}
		cout << endl;
	}
	cout << "����Ľ��Ϊ:";
	for (int i = 0; i < length; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	delete[]arr;
}
void algorithm::directInsertSort(int *arr,int length) {
	int temp;
	int count = 0;
	for (int i = 1; i < length; i++) {
		if (arr[i] < arr[i - 1]) {
			temp = arr[i];
			int j;
			for (j = i - 1; j >= 0 && arr[j] > temp; j--)
				arr[j + 1] = arr[j];
			arr[j + 1] = temp;
		}
		cout << "�� " << ++count << " ��:";
		for (int i = 0; i < length; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	cout << "����Ľ��Ϊ:";
	for (int i = 0; i < length; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	delete[]arr;
}
int *algorithm::genArray(int arrayLength,int range) {
	srand((int)time(0));
	int *a = new int[arrayLength];
	for (int i = 0; i < arrayLength; i++) {
		a[i] = rand()%range;
	}
	cout << "���ɵ�����Ϊ:";
	for (int i = 0; i < arrayLength; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return a;
}
void algorithm::FloydPrint(int **path,int l,int r) {
	if (path[l][r] == -1) {
		return;
	}
	else {
		FloydPrint(path, l, path[l][r]);
		cout << path[l][r] << "->";
		FloydPrint(path, path[l][r], r);
	}
}
int algorithm::Floyd(int **Graph, int length, int n) {
	int **dist = new int*[length];
	int **path = new int*[length];
	for (int i = 0; i < length; i++) {
		dist[i] = new int[length];
		path[i] = new int[length];
	}
	cout << "������ɵ���ȨͼΪ��" << endl;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			//cout << setw(5) << Graph[i][j];
			cout << setw(4) << ((Graph[i][j] == INT_MAX) ? 0 : Graph[i][j]) << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			dist[i][j] = Graph[i][j];
			path[i][j] = -1;
		}
	}
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			for (int k = 0; k < length; k++) {
				if (dist[j][i]!=INT_MAX&&dist[i][k]!=INT_MAX&&dist[j][k] > dist[j][i] + dist[i][k]) {
					dist[j][k] = dist[j][i] + dist[i][k];
					path[j][k] = i;
				}
			}
		}
	}
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			if (dist[i][j] == INT_MAX) {
				cout << "���" << i << "�����" << j << "û���κ�·��" << endl;
			}
			else {
				cout << "���" << i << "�����" << j << "��·������Ϊ" << dist[i][j] << endl;
				cout << i << "->";
				FloydPrint(path, i, j);
				cout << j << endl;
			}
		}
	}
	return 1;
}
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
	//�Ƿ����ҵ����·��
	bool *final = new bool[length];
	//��ǰ���·������
	int *dist = new int[length];
	//���·���ϵ�ǰ�����
	int *path = new int[length];
	cout << "������ɵ���ȨͼΪ��" << endl;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			cout << setw(4)<<((Graph[i][j]==INT_MAX)?0:Graph[i][j]) << " ";
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
			if ((!final[i])&&Graph[nowNode][i] != 0&&Graph[nowNode][i] != INT_MAX && dist[nowNode] + Graph[nowNode][i] < dist[i]) {
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
			cout << "���" << u << "�����" << i << "û��·��" << endl;
		}
		else {
			cout << "���" << u << "�����" << i << "��·������Ϊ" << dist[i] << endl;
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
	//��ǰ����Ƿ񱻷��ʹ�
	bool *visited = new bool[length];
	//��ǰ����·������
	int *path = new int[length];
	//��ǰ������һ�����
	int *from = new int[length];
	//������ȱ�������
	queue<int> BFSQueue;
	cout << "������ɵ���ȨͼΪ��" << endl;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			cout << Graph[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < length; i++) {
		path[i] = INT_MAX; //��ʼ��·������
		from[i] = -1;//��ʼ��ǰ�����
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
			cout << "���" << u << "�����" << i << "û���κ�·��" << endl;
		}
		else {
			cout << "���" << u << "�����" << i << "��·������Ϊ" <<path[i]<< endl;
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
					if (rand() % 2 == 1) {
						newMap[i][j] = rand() % 100;
					}
					else {
						newMap[i][j] = INT_MAX;
					}
					//newMap[i][j] = (rand() % 100)*(rand() % 2);
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
//huffman����ݹ鸨������
void algorithm::huffmanCodeGenCode(treeNode* tree, string code, map<char, string> &res) {
	if (tree->lchild == NULL && tree->rchild == NULL) {
		res[tree->data] = code;
	}
	else {
		huffmanCodeGenCode(tree->lchild, code + "1", res);
		huffmanCodeGenCode(tree->rchild, code + "0", res);
	}
}
//huffman����
void algorithm::huffmanCode(string input) {
	map<char, int> countChar;
	for (int i = 0; i < input.length(); i++) {
		if (countChar.count(input.at(i)) == 0) {
			countChar[input.at(i)] = 0;
		}
		countChar[input.at(i)]++;
	}
	cout << "������ַ���Ϊ��" << endl << input << endl;
	cout << "�����ַ��ĳ��ִ�������" << endl;
	for (map<char, int>::iterator it = countChar.begin(); it != countChar.end(); it++) {
		cout << it->first << " : " << it->second << endl;
	}
	if (countChar.size() == 1) {
		map<char, string> res;
		res[input.at(0)] = "1";
		cout << "������Ϊ" << endl;
		for (map<char, string>::iterator it = res.begin(); it != res.end(); it++) {
			cout << it->first << " :" << it->second << endl;
		}
		cout << "��Ӧ���Ϊ" << endl;
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
	cout << "�����" << endl;
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
	//��1��0���б���
	map<char, string> res;
	huffmanCodeGenCode(output, "", res);
	cout<<"������Ϊ"<<endl;
	for (map<char, string>::iterator it = res.begin(); it != res.end(); it++) {
		cout << it->first << " :" << it->second << endl;
	}
	cout << "��Ӧ���Ϊ" << endl;
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

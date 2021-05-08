#include<iostream>
#include"AVL.h"

using namespace std;

/*Обход дерева в прямом порядке и вывод вершин*/
void printTree(Node* tree, int level = 0) {
	for (int i = 0; i < level; i++) cout << "\t";
	std::cout << tree->key << std::endl;
	level++;
	if (tree->leftChild != NULL) printTree(tree->leftChild, level);
	if (tree->rightChild != NULL) printTree(tree->rightChild, level);
}

int main() {
	system("chcp 1251");
	setlocale(LC_ALL, "Russian");
	Node *root=new Node(10);
	for (int i = 1; i < 12; i++) {
		 root = insert(root, i);
	}
	printTree(root);
	root = remove(root, 7);
	printTree(root);
	
	
	return 0;
}
#pragma once
#include<iostream>

struct Node
{
	int key;
	int height=1;
	Node* leftChild,
		*rightChild;
	Node(int key) : key(key) {
		leftChild = NULL;
		rightChild = NULL;
	};
};

/*������ ���� node*/
int height(Node* node) {
	if (node != NULL) return node->height;
	else return 0;
}

/*������� � ���� ����� ����� � ������ ����������*/
int diff(Node* node) {
	return height(node->leftChild) - height(node->rightChild);
}

/*�������� �������� ������ ���� � ����������� �� ������ ��������*/
void changeHeight(Node* node) {
	int leftHeight = height(node->leftChild);
	int rightHeight = height(node->rightChild);
	node->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

/*����� ������ ������� ������*/
Node* rightRotation(Node* root) {
	Node* temp = root->leftChild;
	root->leftChild = temp->rightChild;
	temp->rightChild = root;
	changeHeight(root);
	changeHeight(temp);
	return temp;
}

/*����� ����� ������� ������*/
Node* leftRotation(Node* root) {
	Node* temp = root->rightChild;
	root->rightChild = temp->leftChild;
	temp->leftChild = root;
	changeHeight(root);
	changeHeight(temp);
	return temp;
}

/*������� ����� ��� ����� ������� ������*/
Node* balance(Node* root) {

	changeHeight(root);

	// bigLeftRotate
	if(diff(root) == -2 ){
		Node* right = root->rightChild;
		if (height(right->leftChild)>height(right->rightChild)) root->rightChild = rightRotation(right); 
		return leftRotation(root);
	}
	else if (diff(root) == 2){ // bigRightRotate
		Node* left = root->leftChild;
		if (height(left->leftChild) < height(left->rightChild)) root->leftChild = leftRotation(left);
		return rightRotation(root);
	}
	return root;
}

/*������� ����� key � ������ � ������ root*/
Node* insert(Node* root, int key) {

	if (root == NULL) return new Node(key);
	else if (root->key > key) root->leftChild = insert(root->leftChild, key);
	else if (root->key == key) root->key=key;
	else root->rightChild = insert(root->rightChild, key);
	return balance(root);
}

/*����� ������������ ���� � ������ node*/
Node* getMin(Node* node) {
	if (node->leftChild != NULL) getMin(node->leftChild);
	else return node;
}

/* �������� ���� � ����������� ������ �� ������ node */
Node* removeMin(Node* node){
	if (node->leftChild == NULL) return node->rightChild;
	node->leftChild = removeMin(node->leftChild);
	node->height = 1 + height(node->leftChild) + height(node->rightChild);
	return node;
}

/*�������� ������� �� ����� key � ������ � ������ root*/
Node* remove(Node* root,int key) {
	if (root == NULL) return NULL;
	else if (root->key > key) root->leftChild = remove(root->leftChild, key);
	else if (root->key < key) root->rightChild = remove(root->rightChild, key);
	else {
		if (root->leftChild == NULL) return root->leftChild;
		if (root->rightChild == NULL) return root->rightChild;
		Node* temp = root;
		root = getMin(root->rightChild);
		root->rightChild = removeMin(temp->rightChild);
		root->leftChild = temp->leftChild;

		return balance(root);
	}
	return balance(root);
}
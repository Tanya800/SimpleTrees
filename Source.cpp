#include<iostream>
#include <algorithm>
#include "animalNode.h"


using namespace std;

/*���������� ����������� ������� ��� ��������, ���� ������������ ������� ����� ��������*/
void newQuestion(animalNode& question) {

	string animal, newQuestion, answer;

	cout << "����� �������� �� ��������?" << endl;
	cin >> animal;

	cout << "����� ������ ������� �������� " << question.getQuestion() << " �� " << animal << ":";
	cin.ignore();
	getline(cin, newQuestion);

	cout << "����� ��� " << animal << " ��������������?" << endl;
	cin >> answer;
	
	bool right ;
	if (answer.front() == '�' || answer.front() == '�')
		right = 1;
	else right = 0;

	question.addChild(newQuestion, animal, right);
}

/*������ ����� ����*/
void startGame(animalNode* question) {
	string answer;

	if (question->getYesChild() == NULL) {
		cout << "�� �������� " << question->getQuestion() << "?" << endl;
		cin >> answer;
		if (answer == "��") return;
		else newQuestion(*question);
	}
	else { 
		cout << question->getQuestion() << endl; 
		cin >> answer;

		if (answer == "��") {
			startGame(question->getYesChild());
		}
		else if (answer == "���") startGame(question->getNoChild());
	}
	
}



int main() {
	system("chcp 1251");
	setlocale(LC_ALL, "Russian");
	animalNode* root = new animalNode("��� �������������?", "������", "�����");
	
	while (1) {
		startGame(root);
		string pressContinue;
		cout << "������ ����������?(��/���)" << endl;
		cin >> pressContinue;
		if (pressContinue.front() == '�') break;
	}
	
	return 0;
}
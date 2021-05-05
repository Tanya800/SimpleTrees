#include<iostream>
#include <algorithm>
#include "animalNode.h"


using namespace std;

/*Добавление уточняющего вопроса про животное, если пользователь загадал новое животное*/
void newQuestion(animalNode& question) {

	string animal, newQuestion, answer;

	cout << "Какое животное вы загадали?" << endl;
	cin >> animal;

	cout << "Какой вопрос поможет отличить " << question.getQuestion() << " от " << animal << ":";
	cin.ignore();
	getline(cin, newQuestion);

	cout << "Ответ для " << animal << " утвердительный?" << endl;
	cin >> answer;
	
	bool right ;
	if (answer.front() == 'д' || answer.front() == 'Д')
		right = 1;
	else right = 0;

	question.addChild(newQuestion, animal, right);
}

/*Начало новой игры*/
void startGame(animalNode* question) {
	string answer;

	if (question->getYesChild() == NULL) {
		cout << "Вы загадали " << question->getQuestion() << "?" << endl;
		cin >> answer;
		if (answer == "да") return;
		else newQuestion(*question);
	}
	else { 
		cout << question->getQuestion() << endl; 
		cin >> answer;

		if (answer == "да") {
			startGame(question->getYesChild());
		}
		else if (answer == "нет") startGame(question->getNoChild());
	}
	
}



int main() {
	system("chcp 1251");
	setlocale(LC_ALL, "Russian");
	animalNode* root = new animalNode("Это млекопитающее?", "Собака", "Птица");
	
	while (1) {
		startGame(root);
		string pressContinue;
		cout << "Хотите продолжить?(да/нет)" << endl;
		cin >> pressContinue;
		if (pressContinue.front() == 'н') break;
	}
	
	return 0;
}
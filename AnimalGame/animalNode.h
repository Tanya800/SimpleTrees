#pragma once
#include<string>

class animalNode
{
	std::string question;
	animalNode* yesChild, * noChild;
public:
	animalNode() {};
	animalNode(std::string question) :question(question) {};
	animalNode(std::string question, std::string yesAnswer, std::string noAnswer) :question(question) {
		yesChild = new animalNode(yesAnswer);
		noChild = new animalNode(noAnswer);
	};
	void addChild(std::string, std::string, bool);

	std::string getQuestion() { return question; };
	void setQuestion(std::string newQuestion) { question = newQuestion; };

	animalNode* getYesChild() { return yesChild; };
	animalNode* getNoChild() { return noChild; };
};


#include "animalNode.h"

void animalNode::addChild(std::string newQuestion, std::string animal, bool right) {

	std::string oldQuestion = question;
	question = newQuestion;

	if (right) {
		yesChild = new animalNode(animal);
		noChild = new animalNode(oldQuestion);
	}
	else {
		yesChild = new animalNode(oldQuestion);
		noChild = new animalNode(animal);
	}

}

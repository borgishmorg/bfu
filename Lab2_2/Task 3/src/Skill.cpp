#include <HeroEditor.hpp>

using HeroEditor::Skill;

Skill::Skill(std::string name){
	name_ = name;
}

const std::string & Skill::getName() const{
	return name_;
}

void Skill::setName(const std::string name){
	name_ = name;
}

const std::map<std::string, int> & Skill::getRequaredAttributes() const{
	return requaredAttributeLevel_;
}

void Skill::addRequiredAttribute(std::string name, int level = 0){
	requaredAttributeLevel_.insert({name, level});
}

#include <HeroEditor.hpp>

using HeroEditor::Hero;

Hero::Hero(std::string name, int attributePointsPerLevel, int skillPointsPerLevel){
	name_ = name;
	level_ = 0;
	attributePoints_ = 0;
	skillPoints_ = 0;
	attributePointsPerLevel_ = attributePointsPerLevel;
	skillPointsPerLevel_ = skillPointsPerLevel;
}

/*

	Getters

*/	
	
const std::string & Hero::getName() const{
	return name_;
}

int Hero::getLevel() const{
	return level_;
}

int Hero::getAttributePoints() const{
	return attributePoints_;
}

int Hero::getSkillPoints() const{
	return skillPoints_;
}

int Hero::getAttributePointsPerlevel() const{
	return attributePointsPerLevel_;
}

int Hero::getSkillPointsPerLevel() const{
	return skillPointsPerLevel_;
}

const std::map<std::string, int> Hero::getAttributes() const{
	return attributes_;
}

const std::map<std::string, HeroEditor::Skill> Hero::getSkills() const{
	return skills_;
}

/*

	Setters

*/

void Hero::setName(std::string name){
	name_ = name;
}

void Hero::setLevel(int level){
	level_ = level;
}
void Hero::setAttributePoints(int attributePoints){
	attributePoints_ = attributePoints;
}

void Hero::setSkillPoints(int skillPoints){
	skillPoints_ = skillPoints;
}

void Hero::setAttributePointsPerLevel(int attributePointsPerLevel){
	attributePointsPerLevel_ = attributePointsPerLevel;
}

void Hero::setSkillPointsPerLevel(int skillPointsPerLevel){
	skillPointsPerLevel_ = skillPointsPerLevel;
}

void Hero::setAttributeLevel(std::string name, int level){
	if(attributes_.find(name) != attributes_.end())
		attributes_.at(name) = level;
}

/*

	Other methods

*/

void Hero::print(std::ostream & out) const{
	out << "Name         - " << name_ << "\n";
	out << "Level        - " << level_ << "\n";
	out << "AP           - " << attributePoints_ << "\n";
	out << "SP           - " << skillPoints_ << "\n";
	out << "AP per level - " << attributePointsPerLevel_ << "\n";
	out << "SP per level - " << skillPointsPerLevel_ << "\n";
	out << "Attributes:\n";
	for(auto & it: attributes_)
		out << "\t" << it.first << " " << it.second << "\n";
	out << "Skills:\n";
	for(auto & it: skills_)
		out << "\t" << it.first << "\n";
	out << "\n";
	
}

void Hero::levelUp(int dLevel = 1){
	level_ += dLevel;
	attributePoints_ += dLevel * attributePointsPerLevel_;
	skillPoints_ += dLevel * skillPointsPerLevel_;
}

void Hero::addAttribute(std::string name){
	if(HeroEditor::attributes.find(name) != HeroEditor::attributes.end())
		attributes_.insert({name, attributes.at(name).getValue()});
}

void Hero::addAttribute(std::string name, int level){
	if(HeroEditor::attributes.find(name) != HeroEditor::attributes.end()){
		attributes_.insert({name, level});
	}	
}

void Hero::deleteAttribute(std::string name){
	if(attributes_.find(name) != attributes_.end())
		attributes_.erase(name);
}

void Hero::levelUpAttribute(std::string name, int dLevel = 1){
	if(attributes_.find(name) == attributes_.end() ||
	   attributes_.at(name) + dLevel > HeroEditor::attributes.at(name).getRequiredPointsPerLevel().size())
		return;
	
	int cost = 0; 
	int attributeLevel = attributes_.at(name);
		
	for(int i = 0; i < dLevel; i++)
		cost += HeroEditor::attributes.at(name).getRequiredPointsPerLevel().at(attributeLevel + i);

	if(cost > attributePoints_)
		return;
	attributePoints_ -= cost;
	attributes_.at(name) += dLevel;
}

void Hero::addSkill(HeroEditor::Skill skill){
	if(skillPoints_ == 0) return;
	for(auto & it: skill.getRequaredAttributes())
		if(attributes_.find(it.first) == attributes_.end() ||
		   attributes_.at(it.first) < it.second)
			return;
	
	skillPoints_--;
	skills_.insert({skill.getName(), skill});
}
void Hero::deleteSkill(std::string name){
	if(skills_.find(name) == skills_.end())
		return;
	
	skills_.erase(name);
}

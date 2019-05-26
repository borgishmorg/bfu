#include <HeroEditor.hpp>
using HeroEditor::Attribute;

std::map<std::string, HeroEditor::Attribute> HeroEditor::attributes;


Attribute::Attribute(std::string name, int initialValue , int maxValue , std::vector<int> requiredPointsPerLevel){
	name_ = name;
	value_ = initialValue;
	maxValue_ = maxValue;
	requiredPointsPerLevel_ = requiredPointsPerLevel;
}

const std::string& Attribute::getName() const{
	return name_;
}

int Attribute::getValue() const{
	return value_;
}

int Attribute::getMaxValue() const{
	return maxValue_;
}

const std::vector<int>& Attribute::getRequiredPointsPerLevel() const{
	return requiredPointsPerLevel_;
}

void Attribute::setName(const std::string name){
	name_ = name;
}

void Attribute::setValue(int value){
	value_ = value;
}

void Attribute::setMaxValue(int maxValue){
	if(maxValue > maxValue){
		std::vector<int> requiredPointsPerLevel(requiredPointsPerLevel_);
		while(requiredPointsPerLevel.size() != requiredPointsPerLevel_.size()){
			requiredPointsPerLevel.push_back(requiredPointsPerLevel_.back());
		}
		requiredPointsPerLevel_ = requiredPointsPerLevel;
	}
	maxValue_ = maxValue;
}
void Attribute::setRequiredPointsPerLevel(const std::vector<int> requiredPointsPerLevel){
	requiredPointsPerLevel_ = requiredPointsPerLevel;
	maxValue_ = requiredPointsPerLevel_.size();
}


void Attribute::print(std::ostream& out) const{
	out << name_ << " " 
		<< value_ << " "
		<< maxValue_ << "\n";
	for(int i = 0; i < maxValue_; i++)
		out << requiredPointsPerLevel_[i] << " ";
	out << "\n";
}

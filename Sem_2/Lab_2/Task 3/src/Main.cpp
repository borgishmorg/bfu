#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <HeroEditor.hpp>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;

using namespace HeroEditor;

const string HelloMessage = "¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦\n¦-¦¦-¦¦---¦¦----¦¦----¦¦---¦¦----¦¦¦---¦¦---¦¦----¦¦----¦\n¦-¦¦-¦¦-¦¦¦¦-¦¦-¦¦-¦¦-¦¦-¦¦¦¦-¦¦--¦¦¦-¦¦¦¦-¦¦¦-¦¦-¦¦-¦¦-¦\n¦----¦¦---¦¦----¦¦-¦¦-¦¦---¦¦-¦¦--¦¦¦-¦¦¦¦-¦¦¦-¦¦-¦¦----¦\n¦-¦¦-¦¦-¦¦¦¦-¦-¦¦¦-¦¦-¦¦-¦¦¦¦-¦¦--¦¦¦-¦¦¦¦-¦¦¦-¦¦-¦¦-¦-¦¦\n¦-¦¦-¦¦---¦¦-¦-¦¦¦----¦¦---¦¦----¦¦¦---¦¦¦-¦¦¦----¦¦-¦-¦¦\n¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦\n";
const string AttributesPath = "saves\\attributes.save";


void hello(){
	cout << "Welcome to:\n" << HelloMessage;
	cout.flush();
}
void load(){
	std::ifstream in(AttributesPath);
	int n;
	in >> n;
	for(int i = 0; i < n; i++){
		string name;
		int value,
			maxValue;
			
		in >> name >> value >> maxValue;
		std::vector<int> requiredPointsPerLevel(maxValue);
		
		for(int j = 0; j < maxValue; j++) 
			in >> requiredPointsPerLevel[j];
		
		Attribute atr(name, value, maxValue, requiredPointsPerLevel);
		attributes.insert({name, atr});
	}
	in.close();
}

int main(){
	hello();
	load();
	
	Hero hero("Jenua", 5, 1);
	hero.addAttribute("Agility");
	hero.addAttribute("Intellingence");
	hero.addAttribute("Stamina");
	hero.addAttribute("Strength");
	
	Skill skill("Programming");
	skill.addRequiredAttribute("Agility", 5);
	
	hero.levelUpAttribute("Agility", 5);
	hero.addSkill(skill);
	hero.print(cout);
	
	hero.levelUp(5);
	hero.levelUpAttribute("Agility", 5);
	hero.addSkill(skill);
	hero.print(cout);
	
	
	
	return 0;
}

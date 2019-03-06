#include <iostream>
#include <fstream>
#include <string>
#include <HeroEditor.hpp>

using std::cin;
using std::cout;
using std::endl;
using std::string;

const string HelloMessage = "¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦\n¦-¦¦-¦¦---¦¦----¦¦----¦¦---¦¦----¦¦¦---¦¦---¦¦----¦¦----¦\n¦-¦¦-¦¦-¦¦¦¦-¦¦-¦¦-¦¦-¦¦-¦¦¦¦-¦¦--¦¦¦-¦¦¦¦-¦¦¦-¦¦-¦¦-¦¦-¦\n¦----¦¦---¦¦----¦¦-¦¦-¦¦---¦¦-¦¦--¦¦¦-¦¦¦¦-¦¦¦-¦¦-¦¦----¦\n¦-¦¦-¦¦-¦¦¦¦-¦-¦¦¦-¦¦-¦¦-¦¦¦¦-¦¦--¦¦¦-¦¦¦¦-¦¦¦-¦¦-¦¦-¦-¦¦\n¦-¦¦-¦¦---¦¦-¦-¦¦¦----¦¦---¦¦----¦¦¦---¦¦¦-¦¦¦----¦¦-¦-¦¦\n¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦\n";
const string AttributesPath = "saves\\attributes.save";
const string SkillsPath = "saves\\skills.save";
const string HeroesPath = "saves\\heroes.save";


void hello(){
	cout << "Welcome to:\n" << HelloMessage;
	cout.flush();
}
void problem(){
	cout << "Some problem" << endl;
	exit(0);
}
void createFile(const string &path){
	std::ofstream out(path);
	out << 0;
}
int loadAttributes(std::ifstream &in){
	
	return 0;
}
int loadSkills(std::ifstream &in){
	
	return 0;
}
int loadHeroes(std::ifstream &in){
	
	return 0;
}
int load(){
	std::ifstream in;
	//=======================================================
	
	cout << "Try to load " << AttributesPath << endl;
	in.open(AttributesPath);
	if(!in.is_open()){
		cout << "Can't open " << AttributesPath << ". Creating it" << endl;
		createFile(AttributesPath);
		in.open(AttributesPath);
	}
	if(!in.is_open()) return 1;
	if(loadAttributes(in)) return 1;
	in.close();
	cout << "Successfully loaded " << AttributesPath << endl;
	//=======================================================
	
	cout << "Try to load " << SkillsPath << endl;
	in.open(SkillsPath);
	if(!in.is_open()){
		cout << "Can't open " << SkillsPath << ". Creating it" << endl;
		createFile(SkillsPath);
		in.open(SkillsPath);
	}
	if(!in.is_open()) return 1;
	if(loadSkills(in)) return 1;
	cout << "Successfully loaded " << SkillsPath << endl;
	in.close();
	//========================================================
	
	cout << "Try to load " << HeroesPath << endl;
	in.open(HeroesPath);
	if(!in.is_open()){
		cout << "Can't open " << HeroesPath << ". Creating it" << endl;
		createFile(HeroesPath);
		in.open(HeroesPath);
	}
	if(!in.is_open()) return 1;
	if(loadHeroes(in)) return 1;
	cout << "Successfully loaded " << HeroesPath << endl;
	in.close();
	//=========================================================
	
	return 0;
}



int main(){
	hello();
	if(load()) problem();
	
	return 0;
}


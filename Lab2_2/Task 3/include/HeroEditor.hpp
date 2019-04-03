#ifndef __HeroEditor__
#define __HeroEditor__
#include <iostream>
#include <map>
#include <vector>
#include <string>

namespace HeroEditor{
	
	class Attribute{
		public:
			Attribute(std::string, int, int, std::vector<int>);
			
			const std::string& getName() const;
			int getValue() const;
			int getMaxValue() const;
			const std::vector<int>& getRequiredPointsPerLevel() const;
			
			void setName(const std::string);
			void setValue(int);
			void setMaxValue(int);
			void setRequiredPointsPerLevel(const std::vector<int>);
			
			void print(std::ostream&) const;
		private:
			std::string name_;
			int value_;
			int maxValue_;
			std::vector<int> requiredPointsPerLevel_;
	};
	
	class Skill{
		public:
			Skill(std::string name_);
			void addRequiredAttribute(std::string, int);
			const std::map<std::string, int> & getRequaredAttributes() const;
			
			void setName(const std::string);
			const std::string & getName() const;
		private:
			std::string name_;
			std::map<std::string, int> requaredAttributeLevel_;
	};
	
	class Hero{
		public:
			Hero(std::string, int, int);
			
			const std::string & getName() const;
			int getLevel() const;
			int getAttributePoints() const;
			int getSkillPoints() const;
			int getAttributePointsPerlevel() const;
			int getSkillPointsPerLevel() const;
			const std::map<std::string, int> getAttributes() const;
			const std::map<std::string, Skill> getSkills() const;
			
			
			void setName(std::string);
			void setLevel(int);
			void setAttributePoints(int);
			void setSkillPoints(int);
			void setAttributePointsPerLevel(int);
			void setSkillPointsPerLevel(int);
			void setAttributeLevel(std::string, int);
			
			void print(std::ostream& out) const;
			void levelUp(int);
			void addAttribute(std::string);
			void addAttribute(std::string, int);
			void deleteAttribute(std::string);
			void levelUpAttribute(std::string, int);
			void addSkill(Skill);
			void deleteSkill(std::string);
		private:
			std::string name_;
			int level_;
			std::map<std::string, int> attributes_;
			std::map<std::string, Skill> skills_;
			int attributePoints_;
			int skillPoints_;
			int attributePointsPerLevel_;
			int skillPointsPerLevel_;
	};
	
	extern std::map<std::string, HeroEditor::Attribute> attributes;
	
};
#endif

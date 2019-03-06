#include <map>
#include <vector>
#include <string>

namespace HeroEditor{
	
	class Attribute{
		public:
			
		private:
			std::string name_;
			int value_;
			int initialValue_;
			int maxValue_;
			std::vector<int> requiredPointsPerLevel_;
	};
	
	class Skill{
		public:
			
		private:
			std::string name_;
			std::map<std::string, int> requaredAttributeLevel_;
	};
	
	class Hero{
		public:
			
		private:
			std::string name_;
			int level_;
			std::map<std::string, Attribute> attributes;
			std::map<std::string, Skill> skills;
			int attributePoints;
			int skillPoints;
			int attributePointsperLevel;
			int skillPointsPerLevel;
	};
	
}


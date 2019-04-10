#ifndef __COOK__
#define __COOK__

#include <string>

namespace DataBaseNS
{
    class Cook{
        public:
            Cook(std::string name);
            ~Cook();
            const std::string & getName() const;
        private:
            std::string name_;
    };
} 
#endif
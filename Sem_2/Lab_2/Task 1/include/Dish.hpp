#ifndef __DISH__
#define __DISH__

#include <string>

namespace DataBaseNS
{
    class Dish{
        public:
            Dish(std::string name, std::string type, std::string country);
            ~Dish();
            const std::string & getName() const;
            const std::string & getType() const;
            const std::string & getCountry() const;
        private:
            std::string name_,
                        type_,
                        country_;
    };
} 
#endif
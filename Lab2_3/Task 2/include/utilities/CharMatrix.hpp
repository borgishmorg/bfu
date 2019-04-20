#ifndef __CHAR_MATRIX__
#define __CHAR_MATRIX__

#include <vector>
#include <string>

namespace BattleRoyale
{
    class CharMatrix{
        public:
            CharMatrix(unsigned int height, unsigned int weight, char pattern = ' ');
            ~CharMatrix();

            char & at(unsigned int hPos, unsigned int wPos);
            void fill(const CharMatrix & matrix, unsigned int hPos = 0, unsigned int wPos = 0);
            void fill(const std::string & str, unsigned int hPos = 0, unsigned int wPos = 0);
            void clear();

            const unsigned int getHeight() const;
            const unsigned int getWeight() const;
            const std::string toString() const;
        private:
            const bool AUTO_LINE_BREAK = false;

            unsigned int height_;
            unsigned int weight_;
            std::vector<std::vector<char> > data_;  
    };
}


#endif
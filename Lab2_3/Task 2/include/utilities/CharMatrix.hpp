#ifndef __CHAR_MATRIX__
#define __CHAR_MATRIX__

#include <vector>
#include <string>

namespace BattleRoyale
{
    class CharMatrix{
        public:
            CharMatrix(unsigned int height, unsigned int width, char pattern = ' ');
            ~CharMatrix();

            void fill(const CharMatrix & matrix, unsigned int hPos = 0, unsigned int wPos = 0);
            void fill(const std::string & str, unsigned int hPos = 0, unsigned int wPos = 0);
            void clear();

            char & at(unsigned int hPos, unsigned int wPos);
            const unsigned int getHeight() const;
            const unsigned int getWidth() const;
            const bool getAutoLineBreak() const;
            const std::string toString() const;

            void setAutoLineBreak(bool);
        private:
            unsigned int height_;
            unsigned int width_;
            std::vector<std::vector<char> > data_;  
            
            bool AUTO_LINE_BREAK_ = false;
    };
}
#endif
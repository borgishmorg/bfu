#include "CharMatrix.hpp"

using BattleRoyale::CharMatrix;

CharMatrix::CharMatrix(unsigned int height, unsigned int width, char pattern):
    height_(height), width_(width), data_(height, std::vector<char>(width, pattern)){}

CharMatrix::~CharMatrix(){}



char & CharMatrix::at(unsigned int hPos, unsigned int wPos){
    return data_.at(hPos).at(wPos);
}

void CharMatrix::fill(const CharMatrix & charMatrix, unsigned int hPos, unsigned int wPos){
    for(unsigned int i = 0; i < charMatrix.height_; i++)
        for(unsigned int j = 0; j < charMatrix.width_; j++)
            if(0 <= hPos + i && hPos + i < height_ &&
               0 <= wPos + j && wPos + j < width_)
                data_.at(hPos + i).at(wPos + j) = charMatrix.data_.at(i).at(j);
}

void CharMatrix::fill(const std::string & str, unsigned int hPos, unsigned int wPos){
    unsigned int i = hPos;
    unsigned int j = wPos;
    for(char c : str){
        if(j >= width_){
            ++i;
            j = 0;
        }
        if(i >= height_) break;

        if(c != '\n'){
            data_.at(i).at(j) = c;
            ++j;
        }else
            while(j < width_){
                data_.at(i).at(j) = ' ';
                ++j;
            }
    }
}

void CharMatrix::clear(){
    for(auto & v: data_)
        for(char & c: v)
            c = ' ';
}



const unsigned int CharMatrix::getHeight() const{
    return height_;
}

const unsigned int CharMatrix::getWidth() const{
    return width_;
}

const std::string CharMatrix::toString() const{
    std::string str;

    for (unsigned int i = 0; i < height_; i++){
        for (unsigned int j = 0; j < width_; j++)
            str.push_back(data_.at(i).at(j));
        if(AUTO_LINE_BREAK) str.push_back('\n');
    }
    
    return str;
}
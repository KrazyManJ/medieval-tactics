#ifndef Dictionary_hpp
#define Dictionary_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include "Word.hpp"

using namespace std;

class Dictionary {
private:
    vector<Word*> words;
public:
    Dictionary();
    
    Word* getNextWord(char ch) const;
};

#endif /* Dictionary_hpp */

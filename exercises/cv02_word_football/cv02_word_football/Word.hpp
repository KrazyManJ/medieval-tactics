#ifndef Word_hpp
#define Word_hpp

#include <stdio.h>
#include <string>

using namespace std;

class Word {
private:
    string value;
public:
    Word(string value);
    char getFirstChar() const;
    char getLastChar() const;
    string getValue() const;
};

#endif /* Word_hpp */

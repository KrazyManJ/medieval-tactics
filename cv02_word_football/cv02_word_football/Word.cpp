#include "Word.hpp"

Word::Word(string value) {
    this->value = value;
}

char Word::getFirstChar() const {
    return value.at(0);
}

char Word::getLastChar() const {
    return value.at(value.size()-1);
}

string Word::getValue() const {
    return value;
}

//
//  Dictionary.cpp
//  cv02_word_football
//
//  Created by Jaroslav Korčák on 03.10.2024.
//

#include "Dictionary.hpp"

Dictionary::Dictionary() {
    words = {
        new Word("Ahoj"),
        new Word("Banka"),
        new Word("Cizrna"),
        new Word("Denik"),
        new Word("Energie"),
        new Word("Fentanyl")
    };
}

Word* Dictionary::getNextWord(char ch) const {
    for (auto* word : words){
        if (word->getFirstChar() == ch) return word;
    }
    return nullptr;
}

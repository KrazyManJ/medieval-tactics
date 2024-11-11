#include "Conversation.hpp"
#include <algorithm>
#include <cctype>

bool Conversation::matches(std::string userSentence) {
    return std::regex_match(toLowerCase(userSentence),this->keyword);
}

std::string Conversation::toLowerCase(const std::string input) {
    std::string output;
    for(auto x: input) output += (char)tolower(x);
    return output;
}

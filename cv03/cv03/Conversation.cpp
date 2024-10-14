#include "Conversation.hpp"

bool Conversation::matches(std::string userSentence) {
    return std::regex_match(userSentence,this->keyword);
}

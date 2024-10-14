//
//  Conversation.hpp
//  Chatbot
//
//  Created by David Procházka on 11/10/2018.
//  Copyright © 2018 MENDELU. All rights reserved.
//

#ifndef Conversation_h
#define Conversation_h

#include <regex>
#include <iostream>

struct Conversation {
    std::regex keyword;
    std::string response;

    bool matches(std::string userSentence);
    std::string toLowerCase(const std::string input);
};

#endif /* Conversation_h */

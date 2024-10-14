//
//  Chatbot.cpp
//  Chatbot
//
//  Created by David Procházka on 11/10/2018.
//  Copyright © 2018 MENDELU. All rights reserved.
//

#include "Chatbot.hpp"

Chatbot::Chatbot(const std::string filename) {
    m_conversations = Loader().getConversations(filename);
}

void Chatbot::printIntroduction() const {
    const std::string INTRODUCTION = "Hey this is chatbot Pepa, nice to meet you, ask me anything.";
}

void Chatbot::chat() const {
    bool run = true;
    while (run) {
        std::string ahoj;
    }
}

std::string Chatbot::getUserSentence() const {
    // TODO
    return "";
}

std::string Chatbot::findAnswer(const std::string userSentence) const {
    // TODO
    return "";
}

void Chatbot::printAnswer(const std::string computerAnswer) const {
    std::cout << computerAnswer << std::endl;
}

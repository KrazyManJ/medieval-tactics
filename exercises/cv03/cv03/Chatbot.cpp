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
    const std::string INTRODUCTION_MESSAGE = "Hey this is chatbot Pepa, nice to meet you, ask me anything.";
    printAnswer(INTRODUCTION_MESSAGE);
}

void Chatbot::chat() const {
    printIntroduction();
    bool run = true;
    while (run) {
        std::cout << "Input: ";
        std::string input = getUserSentence();
        if (input == "end") run = false;
        else printAnswer(findAnswer(input));
    }
    const std::string FAREWELL_MESSAGE = "Okay, you want to end convo. Thanks for using me as an Chatbot. See ya!";
    printAnswer(FAREWELL_MESSAGE);
}

std::string Chatbot::getUserSentence() const {
    std::string input;
    getline(std::cin, input);
    return input;
}

std::string Chatbot::findAnswer(const std::string userSentence) const {
    for (auto conv : m_conversations){
        if (conv.matches(userSentence)) return conv.response;
    }
    const std::string UNKNOWN_ANSWER = "Sorry, I do not understand what you are saying, be patient with me, i am learning. Could you tell me something else?";
    return UNKNOWN_ANSWER;
}

void Chatbot::printAnswer(const std::string computerAnswer) const {
    std::cout << computerAnswer << std::endl;
}

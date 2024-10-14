//
//  Loader.cpp
//  Chatbot
//
//  Created by David Procházka on 11/10/2018.
//  Copyright © 2018 MENDELU. All rights reserved.
//

#include "Loader.hpp"
#include <fstream>

std::vector<Conversation> Loader::getConversations(const std::string filename) const{
    std::vector<Conversation> conversations;

    std::ifstream file(filename);
    
    if (file.is_open()) {
        std::string line;
        while (std::getline(file,line)) {
            conversations.push_back(splitLine(line));
        }
    }
    file.close();

    return conversations;
}

Conversation Loader::splitLine(const std::string line) const{
    return {
        std::regex(".*"+line.substr(0,line.find(" "))+".+"),
        line.substr(line.find(" ")+1,line.size()-1)
    };
}

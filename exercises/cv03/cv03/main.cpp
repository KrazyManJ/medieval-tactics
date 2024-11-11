//
//  main.cpp
//  Chatbot
//
//  Created by David Procházka on 11/10/2018.
//  Copyright © 2018 MENDELU. All rights reserved.
//

#include <iostream>
#include "Loader.hpp"
#include "Chatbot.hpp"

int main(int argc, const char * argv[]) {
    Chatbot chatbot("chat.txt");
    chatbot.chat();
    
    return 0;
}

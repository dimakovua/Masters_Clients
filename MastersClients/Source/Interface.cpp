//
//  Interface.cpp
//  MastersClients
//
//  Created by Dmytro Kovalenko on 27.04.2022.
//

#include "../Headers/Interface.hpp"

Interface::Interface(){
    m_tools = std::make_unique<Tools>();
}

bool Interface::Command_getter(){
    std::cout << "> ";
    std::getline(std::cin, m_command);
    Parser();
    return DoStaff();
}

void Interface::Parser(){
    m_tokens = {};
    std::string token = "";
    for(int i = 0; i < m_command.length(); i++){
        if(m_command[i] == ' '){
            m_tokens.push_back(token);
            token = "";
        }
        else{
            token.push_back(m_command[i]);
        }
    }
    m_tokens.push_back(token);
//    m_command = "";
//    std::cout << "=======\n";
//    for(auto a : m_tokens){
//        std::cout << a << std::endl;
//    }
}

bool Interface::DoStaff(){
    std::string what_to_do = m_tokens[0]; //command

    m_tokens.erase(m_tokens.begin());
    if(what_to_do == "STOP"){
        return false;
    }
    if(what_to_do == "ADD-M"){
        std::string table_name = m_tokens[0];
        m_tokens.erase(m_tokens.begin());
        
        try{
            m_tools->Add_m(table_name, m_tokens);
        }catch(std::exception& ex){
            std::cout << "Error: " << ex.what() << std::endl;
        }
    }
    if(what_to_do == "GET-M"){
        std::string table_name = m_tokens[0];
        try{
            m_tools->Get_m(table_name, m_tokens[1]);
        }catch(std::exception& ex){
            std::cout << "Error: " << ex.what() << std::endl;
        }
    }
    if(what_to_do == "GET-S"){
        std::string table_name = m_tokens[0];
        m_tokens.erase(m_tokens.begin());
        try{
            m_tools->Get_s(table_name, m_tokens);
        }catch(std::exception& ex){
            std::cout << "Error: " << ex.what() << std::endl;
        }
    }
    if(what_to_do == "DELETE"){
        std::string table_name = m_tokens[0];
        m_tokens.erase(m_tokens.begin());
        try{
            m_tools->Delete(table_name, m_tokens);
        }catch(std::exception& ex){
            std::cout << "Error: " << ex.what() << std::endl;
        }
    }
    if(what_to_do == "UPDATE"){
        std::string table_name = m_tokens[0];
        m_tokens.erase(m_tokens.begin());
        try{
            m_tools->Update(table_name, m_tokens);
        }catch(std::exception& ex){
            std::cout << "Error: " << ex.what() << std::endl;
        }
    }
    return true;
}

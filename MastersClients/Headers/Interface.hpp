//
//  Interface.hpp
//  MastersClients
//
//  Created by Dmytro Kovalenko on 27.04.2022.
//

#ifndef Interface_h
#define Interface_h

#include "Tools.hpp"

class Interface{
public:
    Interface();
    void Command_getter();
    void Parser();
    void DoStaff();
private:
    std::unique_ptr<Tools> m_tools;
    std::string m_command;
    std::vector<std::string> m_tokens;
};


#endif /* Interface_h */

//
//  Tools.cpp
//  MastersClients
//
//  Created by Dmytro Kovalenko on 27.04.2022.
//

#include "../Headers/Tools.hpp"

Tools::Tools(){
    m_db = std::make_unique<DataBase>();
}

bool Tools::Add_m(std::string table_name, std::vector<std::string> args){
    if(table_name == "MASTER"){
        if(args.size() != 6){
            throw std::runtime_error("Not enough args");
            return false;
        }
        else{
            m_db->Get_master_db()->Save(std::make_shared<Master>(args[0], args[1], args[2], args[3], args[4], args[5]));
            return true;
        }
    }
    return false;
}

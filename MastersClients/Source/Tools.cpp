//
//  Tools.cpp
//  MastersClients
//
//  Created by Dmytro Kovalenko on 27.04.2022.
//

#include "../Headers/Tools.hpp"

Tools::Tools(){
    m_db.release();
    m_db = std::make_unique<DataBase>();
}
void Tools::Delete(std::string table_name, std::vector<std::string> args){
    int ID;
    try{
        ID = std::stoi(args[0]);
    }catch(...){
        throw std::logic_error("Invalid ID");
    }
    if(table_name == "MASTER"){
        try{
            m_db->Get_master_db()->Delete(ID);
        }catch(...){
            throw std::runtime_error("Cannot delete!");
        }
    }
    else if(table_name == "CLIENT"){
        try{
            m_db->Get_client_db()->Delete(ID);
        }catch(...){
            throw std::runtime_error("Cannot delete!");
        }
    }
    else if(table_name == "DEVICE"){
        try{
            m_db->Get_device_db()->Delete(ID);
        }catch(...){
            throw std::runtime_error("Cannot delete!");
        }
    }
    else if(table_name == "OWNERSHIP"){
        try{
            m_db->Get_ownership_db()->Delete(ID);
        }catch(...){
            throw std::runtime_error("Cannot delete!");
        }
    }
    else if(table_name == "SPECIALIZATION"){
        try{
            m_db->Get_special_db()->Delete(ID);
        }catch(...){
            throw std::runtime_error("Cannot delete!");
        }
    }
    else if(table_name == "SERVICE"){
        try{
            m_db->Get_service_db()->Delete(ID);
        }catch(...){
            throw std::runtime_error("Cannot delete!");
        }
    }
    else if(table_name == "CONTRACT"){
        try{
            m_db->Get_contract_db()->Delete(ID);
        }catch(...){
            throw std::runtime_error("Cannot delete!");
        }
    }
    else{
        std::cout << "Unknown table!\n";
    }
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
    else if(table_name == "CLIENT"){
        if(args.size() != 6){
            throw std::runtime_error("Not enough args");
            return false;
        }
        else{
            m_db->Get_client_db()->Save(std::make_shared<Client>(args[0], args[1], args[2], args[3], args[4], args[5]));
            return true;
        }
    }
    else if(table_name == "DEVICE"){
        if(args.size() < 3){
            throw std::runtime_error("Not enough args");
            return false;
        }
        else{
            std::string descr = "";
            for(int i = 2; i < args.size(); i++){
                descr+=args[i];
                descr+=" ";
            }
            descr.pop_back();
            m_db->Get_device_db()->Save(std::make_shared<Device>(args[0], args[1], descr));
            return true;
        }
    }
    else if(table_name == "SERVICE"){
        if(args.size() != 3){
            throw std::runtime_error("Not enough args");
            return false;
        }
        else{
            m_db->Get_service_db()->Save(std::make_shared<Service>(args[0], args[1], args[2]));
            return true;
        }
    }
    else if(table_name == "CLIENT"){
        if(args.size() != 6){
            throw std::runtime_error("Not enough args");
            return false;
        }
        else{
            m_db->Get_client_db()->Save(std::make_shared<Client>(args[0], args[1], args[2], args[3], args[4], args[5]));
            return true;
        }
    }
    else if(table_name == "OWNERSHIP"){
        if(args.size() != 2){
            throw std::runtime_error("Not enough args");
            return false;
        }
        else{
            m_db->Get_ownership_db()->Save(std::make_shared<Ownership>(args[0], args[1]));
            return true;
        }
    }
    else if(table_name == "SPECIALIZATION"){
        if(args.size() != 2){
            throw std::runtime_error("Not enough args");
            return false;
        }
        else{
            m_db->Get_special_db()->Save(std::make_shared<Specialization>(args[0], args[1]));
            return true;
        }
    }
    else if(table_name == "CONTRACT"){
        if(args.size() != 5){
            throw std::runtime_error("Not enough args");
            return false;
        }
        else{
            m_db->Get_contract_db()->Save(std::make_shared<Contract>(args[0], args[1], args[2], args[3], args[4]));
            return true;
        }
    }
    else{
        throw std::runtime_error("Unknown table");
        return false;
    }
}

void Tools::Get_m(std::string table_name, std::string id){
    int ID;
    try{
        ID = std::stoi(id);
    }catch(...){
        throw std::runtime_error("Invalid ID");
    }
    if(table_name == "MASTER"){
        auto el = m_db->Get_master_db()->Get(ID);
        std::cout << "---Master-" << el->Get_ID() << "---\n" << "First name:\t" << el->Get_first_name() << "\nLast name:\t" << el->Get_last_name() << "\nFather name:\t" << el->Get_father_name() << "\nPhone number:\t" << el->Get_phone_number() << "\nSalary:\t"<< el->Get_Salary() << "\nExperience:\t" << el->Get_experience() << std::endl;
    }
    else if(table_name == "CLIENT"){
        auto el = m_db->Get_client_db()->Get(ID);
        std::cout << "---Client-" << el->Get_ID() << "---\n" << "First name:\t" << el->Get_first_name() << "\nLast name:\t" << el->Get_last_name() << "\nFather name:\t" << el->Get_father_name() << "\nPhone number:\t" << el->Get_phone_number() << "\nCard:\t"<< el->Get_card() << "\nEmail:\t" << el->Get_email()<< std::endl;
    }
    else if(table_name == "DEVICE"){
        auto el = m_db->Get_device_db()->Get(ID);
        std::cout << "---Device-" << el->Get_ID() << "---\n" << "Name:\t" << el->Get_name() << "\nModel:\t" << el->Get_model() << "\nBreakage:\t" << el->Get_breakage()<< std::endl;
    }
    else if(table_name == "OWNERSHIP"){
        auto el = m_db->Get_ownership_db()->Get(ID);
        std::cout << "---Ownership-" << el->Get_ID() << "---\n" << "Owner ID:\t" << el->Get_owner_id() << "\nDevice ID:\t" << el->Get_device_id() << std::endl;
    }
    else if(table_name == "SERVICE"){
        auto el = m_db->Get_service_db()->Get(ID);
        std::cout << "---Service-" << el->Get_ID() << "---\n" << "Service Name:\t" << el->Get_name() << "\nTime:\t" << el->Get_time() <<"\nCost:\t" << el->Get_cost() << std::endl;
    }
    else if(table_name == "SPECIALIZATION"){
        auto el = m_db->Get_special_db()->Get(ID);
        std::cout << "---Specialization-" << el->Get_ID() << "---\n" << "Master ID:\t" << el->Get_master_id() << "\nService ID:\t" << el->Get_service_id() << std::endl;
    }
    else if(table_name == "CONTRACT"){
        auto el = m_db->Get_contract_db()->Get(ID);
        std::cout << "---Contract-" << el->Get_ID() << "---\n" << "Master ID:\t" << el->Get_master_id() << "\nClient ID:\t" << el->Get_client_id() <<"\nService ID:\t" << el->Get_service_id() <<"\nDate:\t" << el->Get_date() << "\nStatus:\t" << el->Get_status() << std::endl;
    }
    else{
        throw std::runtime_error("Unknown table");
    }
}

void Tools::Get_s(std::string table_name, std::vector<std::string> fields){
    std::string ID;
    int id;
    try{
        ID = fields[0];
        id = std::stoi(ID);
        fields.erase(fields.begin());
    }catch(...){
        throw std::runtime_error("Unknown id");
    }
    if(table_name == "CLIENT"){
        auto el = m_db->Get_client_db()->Get(id);
        if(fields.size() == 0){
            std::cout << "Put args (FIRST_NAME, LAST_NAME, FATHER_NAME, PHONE_NUMBER, CARD, EMAIL):\n> ";
            std::string allwords;
            std::getline(std::cin, allwords);
            std::string word;
            std::istringstream iss(allwords);
            while(iss >> word) {fields.push_back(word); }
        }
        for(auto field : fields){
            if(field == "FIRST_NAME"){
                std::cout << el->Get_first_name() << std::endl;
            }
            else if(field == "LAST_NAME"){
                std::cout << el->Get_last_name() << std::endl;
            }
            else if(field == "FATHER_NAME"){
                std::cout << el->Get_father_name() << std::endl;
            }
            else if(field == "PHONE_NUMBER"){
                std::cout << el->Get_phone_number() << std::endl;
            }
            else if(field == "CARD"){
                std::cout << el->Get_card() << std::endl;
            }
            else if(field == "EMAIL"){
                std::cout << el->Get_email() << std::endl;
            }
            else{
                std::cout << "Unknown field " << field << std::endl;
            }
        }
    }
    else if(table_name == "MASTER"){
        auto el = m_db->Get_master_db()->Get(id);
        if(fields.size() == 0){
            std::cout << "Put args (FIRST_NAME, LAST_NAME, FATHER_NAME, PHONE_NUMBER, SALARY, EXPERIENCE):\n> ";
            std::string allwords;
            std::getline(std::cin, allwords);
            std::string word;
            std::istringstream iss(allwords);
            while(iss >> word) {fields.push_back(word); }
        }
        for(auto field : fields){
            if(field == "FIRST_NAME"){
                std::cout << el->Get_first_name() << std::endl;
            }
            else if(field == "LAST_NAME"){
                std::cout << el->Get_last_name() << std::endl;
            }
            else if(field == "FATHER_NAME"){
                std::cout << el->Get_father_name() << std::endl;
            }
            else if(field == "PHONE_NUMBER"){
                std::cout << el->Get_phone_number() << std::endl;
            }
            else if(field == "EXPERIENCE"){
                std::cout << el->Get_experience() << std::endl;
            }
            else if(field == "SALARY"){
                std::cout << el->Get_Salary() << std::endl;
            }
            else{
                std::cout << "Unknown field " << field << std::endl;
            }
        }
    }
    else if(table_name == "DEVICE"){
        auto el = m_db->Get_device_db()->Get(id);
        if(fields.size() == 0){
            std::cout << "Put args (NAME, MODEL, BREAKAGE):\n> ";
            std::string allwords;
            std::getline(std::cin, allwords);
            std::string word;
            std::istringstream iss(allwords);
            while(iss >> word) {fields.push_back(word); }
        }
        for(auto field : fields){
            if(field == "NAME"){
                std::cout << el->Get_name() << std::endl;
            }
            else if(field == "MODEL"){
                std::cout << el->Get_model() << std::endl;
            }
            else if(field == "BREAKAGE"){
                std::cout << el->Get_breakage() << std::endl;
            }
            else{
                std::cout << "Unknown field " << field << std::endl;
            }
        }
    }
    else if(table_name == "SERVICE"){
        auto el = m_db->Get_service_db()->Get(id);
        if(fields.size() == 0){
            std::cout << "Put args (NAME, COST, TIME):\n> ";
            std::string allwords;
            std::getline(std::cin, allwords);
            std::string word;
            std::istringstream iss(allwords);
            while(iss >> word) {fields.push_back(word); }
        }
        for(auto field : fields){
            if(field == "NAME"){
                std::cout << el->Get_name() << std::endl;
            }
            else if(field == "COST"){
                std::cout << el->Get_cost() << std::endl;
            }
            else if(field == "TIME"){
                std::cout << el->Get_time() << std::endl;
            }
            else{
                std::cout << "Unknown field " << field << std::endl;
            }
        }
    }
    else if(table_name == "OWNERSHIP"){
        if(fields.size() == 0){
            std::cout << "Put args (OWNER, DEVICE):\n> ";
            std::string allwords;
            std::getline(std::cin, allwords);
            std::string word;
            std::istringstream iss(allwords);
            while(iss >> word) {fields.push_back(word); }
        }
        auto el = m_db->Get_ownership_db()->Get(id);
        for(auto field : fields){
            if(field == "OWNER"){
                std::cout << el->Get_owner_id() << std::endl;
            }
            else if(field == "DEVICE"){
                std::cout << el->Get_device_id() << std::endl;
            }
            else{
                std::cout << "Unknown field " << field << std::endl;
            }
        }
    }
    else if(table_name == "SPECIALIZATION" || table_name == "SPECIAL"){
        auto el = m_db->Get_special_db()->Get(id);
        if(fields.size() == 0){
            std::cout << "Put args (MASTER, COST):\n> ";
            std::string allwords;
            std::getline(std::cin, allwords);
            std::string word;
            std::istringstream iss(allwords);
            while(iss >> word) {fields.push_back(word); }
        }
        for(auto field : fields){
            if(field == "MASTER"){
                std::cout << el->Get_master_id() << std::endl;
            }
            else if(field == "COST"){
                std::cout << el->Get_service_id() << std::endl;
            }
            else{
                std::cout << "Unknown field " << field << std::endl;
            }
        }
    }
    else if(table_name == "CONTRACT"){
        if(fields.size() == 0){
            std::cout << "Put args (MASTER, CLIENT, SERVICE, DATE, STATUS):\n> ";
            std::string allwords;
            std::getline(std::cin, allwords);
            std::string word;
            std::istringstream iss(allwords);
            while(iss >> word) {fields.push_back(word); }
        }
        auto el = m_db->Get_contract_db()->Get(id);
        for(auto field : fields){
            if(field == "MASTER"){
                std::cout << el->Get_master_id() << std::endl;
            }
            else if(field == "CLIENT"){
                std::cout << el->Get_client_id() << std::endl;
            }
            else if(field == "SERVICE"){
                std::cout << el->Get_service_id() << std::endl;
            }
            else if(field == "DATE"){
                std::cout << el->Get_date() << std::endl;
            }
            else if(field == "STATUS"){
                std::cout << el->Get_status() << std::endl;
            }

            else{
                std::cout << "Unknown field " << field << std::endl;
            }
        }
    }
    else{
        throw std::runtime_error("Unknown table");
    }
}


void Tools::Update(std::string table_name, std::vector<std::string> args){
    if(args.size() != 3){
        throw std::logic_error("Not enough arguments!");
    }
    int id;
    try{
        id = std::stoi(args[0]);
    }catch(...){
        throw std::runtime_error("Invalid argument!");
    }
    if(table_name == "CLIENT"){
        auto clients_db = m_db->Get_client_db();
        std::shared_ptr<Client> el;
        try{
            el = clients_db->Get(id);
        }catch(...){
            throw std::runtime_error("Invalid ID");
        }
        if(args[1] == "FIRST_NAME"){
            try{
                el->Set_first_name(args[2]);
                std::cout << "Done!\n";
            }catch(...){
                std::runtime_error("Setting error!");
            }
        }
        else if(args[1] == "LAST_NAME"){
            try{
                el->Set_last_name(args[2]);
                std::cout << "Done!\n";
            }catch(...){
                std::runtime_error("Setting error!");
            }
        }
        else if (args[1] == "FATHER_NAME"){
            try{
                el->Set_father_name(args[2]);
                std::cout << "Done!\n";
            }catch(...){
                std::runtime_error("Setting error!");
            }
        }
        else if (args[1] == "PHONE_NUMBER"){
            try{
                el->Set_phone_number(args[2]);
                std::cout << "Done!\n";
            }catch(...){
                std::runtime_error("Setting error!");
            }
        }
        else if (args[1] == "EMAIL"){
            try{
                el->Set_email(args[2]);
                std::cout << "Done!\n";
            }catch(...){
                std::runtime_error("Setting error!");
            }
        }
        else if (args[1] == "CARD"){
            try{
                el->Set_card(args[2]);
                std::cout << "Done!\n";
            }catch(...){
                std::runtime_error("Setting error!");
            }
        }
        else{
            throw std::logic_error("Invalid param!\nTry FIRTST_NAME/LAST_NAME/FATHER_NAME/PHONE_NUMBER/EMAIL/CARD\n");
        }
        return;
    }
    else if(table_name == "MASTER"){
        auto master_db = m_db->Get_master_db();
        std::shared_ptr<Master> el;
        try{
            el = master_db->Get(id);
        }catch(...){
            throw std::runtime_error("Invalid ID");
        }
        if(args[1] == "FIRST_NAME"){
            try{
                el->Set_first_name(args[2]);
                std::cout << "Done!\n";
            }catch(...){
                std::runtime_error("Setting error!");
            }
        }
        else if(args[1] == "LAST_NAME"){
            try{
                el->Set_last_name(args[2]);
                std::cout << "Done!\n";
            }catch(...){
                std::runtime_error("Setting error!");
            }
        }
        else if (args[1] == "FATHER_NAME"){
            try{
                el->Set_father_name(args[2]);
                std::cout << "Done!\n";
            }catch(...){
                std::runtime_error("Setting error!");
            }
        }
        else if (args[1] == "PHONE_NUMBER"){
            try{
                el->Set_phone_number(args[2]);
                std::cout << "Done!\n";
            }catch(...){
                std::runtime_error("Setting error!");
            }
        }
        else if (args[1] == "EXPERIENCE"){
            try{
                el->Set_experience(args[2]);
                std::cout << "Done!\n";
            }catch(...){
                std::runtime_error("Setting error!");
            }
        }
        else if (args[1] == "SALARY"){
            try{
                el->Set_Salary(args[2]);
                std::cout << "Done!\n";
            }catch(...){
                std::runtime_error("Setting error!");
            }
        }
        else{
            throw std::logic_error("Invalid param!\nTry FIRTST_NAME/LAST_NAME/FATHER_NAME/PHONE_NUMBER/SALARY/EXPERIENCE\n");
        }
        return;
    }
    else if(table_name == "DEVICE"){
        auto device_db = m_db->Get_device_db();
        std::shared_ptr<Device> el;
        try{
            el = device_db->Get(id);
        }catch(...){
            throw std::runtime_error("Invalid ID");
        }
        if(args[1] == "NAME"){
            try{
                el->Set_name(args[2]);
                std::cout << "Done!\n";
            }catch(...){
                std::runtime_error("Setting error!");
            }
        }
        else if(args[1] == "MODEL"){
            try{
                el->Set_model(args[2]);
                std::cout << "Done!\n";
            }catch(...){
                std::runtime_error("Setting error!");
            }
        }
        else if (args[1] == "BREAKAGE"){
            try{
                el->Set_breakage(args[2]);
                std::cout << "Done!\n";
            }catch(...){
                std::runtime_error("Setting error!");
            }
        }
        else{
            throw std::logic_error("Invalid param!\nTry NAME/MODEL/BREAKAGE\n");
        }
        return;
    }
    else if(table_name == "OWNERSHIP"){
        auto own_db = m_db->Get_ownership_db();
        std::shared_ptr<Ownership> el;
        try{
            el = own_db->Get(id);
        }catch(...){
            throw std::runtime_error("Invalid ID");
        }
        if(args[1] == "OWNER_ID"){
            try{
                el->Set_owner_id(args[2]);
                std::cout << "Done!\n";
            }catch(...){
                std::runtime_error("Setting error!");
            }
        }
        else if(args[1] == "DEVICE_ID"){
            try{
                el->Set_device_id(args[2]);
                std::cout << "Done!\n";
            }catch(...){
                std::runtime_error("Setting error!");
            }
        }
        else{
            throw std::logic_error("Invalid param!\nTry OWNER_ID/DEVICE_ID\n");
        }
        return;
    }
    else if(table_name == "SERVICE"){
        auto service_db = m_db->Get_service_db();
        std::shared_ptr<Service> el;
        try{
            el = service_db->Get(id);
        }catch(...){
            throw std::runtime_error("Invalid ID");
        }
        if(args[1] == "NAME"){
            try{
                el->Set_name(args[2]);
                std::cout << "Done!\n";
            }catch(...){
                std::runtime_error("Setting error!");
            }
        }
        else if(args[1] == "TIME"){
            try{
                el->Set_time(args[2]);
                std::cout << "Done!\n";
            }catch(...){
                std::runtime_error("Setting error!");
            }
        }
        else if (args[1] == "COST"){
            try{
                el->Set_cost(args[2]);
                std::cout << "Done!\n";
            }catch(...){
                std::runtime_error("Setting error!");
            }
        }
        else{
            throw std::logic_error("Invalid param!\nTry NAME/TIME/COST\n");
        }
        return;
    }
    else if(table_name == "SPECIALIZATION"){
        auto special_db = m_db->Get_special_db();
        std::shared_ptr<Specialization> el;
        try{
            el = special_db->Get(id);
        }catch(...){
            throw std::runtime_error("Invalid ID");
        }
        if(args[1] == "MASTER_ID"){
            try{
                el->Set_master_id(args[2]);
                std::cout << "Done!\n";
            }catch(...){
                std::runtime_error("Setting error!");
            }
        }
        else if(args[1] == "SERVICE_ID"){
            try{
                el->Set_service_id(args[2]);
                std::cout << "Done!\n";
            }catch(...){
                std::runtime_error("Setting error!");
            }
        }
        else{
            throw std::logic_error("Invalid param!\nTry MASTER_ID/SERVICE_ID\n");
        }
        return;
    }
    if(table_name == "CONTRACT"){
        auto contract_db = m_db->Get_contract_db();
        std::shared_ptr<Contract> el;
        try{
            el = contract_db->Get(id);
        }catch(...){
            throw std::runtime_error("Invalid ID");
        }
        if(args[1] == "CLIENT_ID"){
            try{
                el->Set_client_id(args[2]);
                std::cout << "Done!\n";
            }catch(...){
                std::runtime_error("Setting error!");
            }
        }
        else if(args[1] == "MASTER_ID"){
            try{
                el->Set_master_id(args[2]);
                std::cout << "Done!\n";
            }catch(...){
                std::runtime_error("Setting error!");
            }
        }
        else if (args[1] == "SERVICE_ID"){
            try{
                el->Set_service_id(args[2]);
                std::cout << "Done!\n";
            }catch(...){
                std::runtime_error("Setting error!");
            }
        }
        else if (args[1] == "DATE"){
            try{
                el->Set_date(args[2]);
                std::cout << "Done!\n";
            }catch(...){
                std::runtime_error("Setting error!");
            }
        }
        else if (args[1] == "STATUS"){
            try{
                el->Set_status(args[2]);
                std::cout << "Done!\n";
            }catch(...){
                std::runtime_error("Setting error!");
            }
        }
        else{
            throw std::logic_error("Invalid param!\nTry SERVICE_ID/CLIENT_ID/MASTER_ID/DATE/STATUS");
        }
        return;
    }
    else{
        throw std::logic_error("Unknown table!\nTry MASTER/CLIENT/DEVICE/OWNERSHIP/SPECIALIZATION/CONTRACT/SERVICE\n");
    }
}

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
    bool Command_getter();
    void Parser();
    bool DoStaff();
private:
    const std::string BigHelpMessage = "Commands: INSERT/UPDATE/GET-M/GET-S/DELETE/STOP\nTables: MASTER, CLIENT, DEVICE, OWNERSHIP, SPECIALIZATION, SERVICE, CONTRACT\nUse \"HELP table_or_command\" to get more information";
    const std::string Help_Insert = "Use \"INSERT TABLE_NAME args\" to add element to specific table";
    const std::string Help_Update = "Use \"UPDATE TABLE_NAME ID FIELD new_value\" to update field";
    const std::string Help_Get_m = "Use \"GET-M TABLE_NAME ID\" to see specific element";
    const std::string Help_Get_s = "Use \"GET-S TABLE_NAME ID FIELD_NAME\" to see the specific field of the element";
    const std::string Help_Delete = "Use \"DELETE TABLE_NAME ID\" to delete element";
    const std::string Help_Stop = "Use \"STOP\" to save database and quit";
    const std::string Help_Client = "{first_name, last_name, father_name, phone_number, email, card}";
    const std::string Help_Master = "{first_name, last_name, father_name, phone_number, experience, salary}";
    const std::string Help_Device = "{name, model, breakage}";
    const std::string Help_Service = "{name, time, cost}";
    const std::string Help_Ownership = "{owner_id, device_id}";
    const std::string Help_Specialization = "{master_id, service_id}";
    const std::string Help_Contract = "{service_id, master_id, client_id, date, status}";
    std::unique_ptr<Tools> m_tools;
    std::string m_command;
    std::vector<std::string> m_tokens;
};


#endif /* Interface_h */

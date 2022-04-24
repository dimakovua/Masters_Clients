
#ifndef Tables_h
#define Tables_h

#include <string>

class Client{
private:
    std::string m_last_name;
    std::string m_first_name;
    std::string m_father_name;
    std::string m_phone_number;
    static int Client_ID;
    int m_id;
    std::string m_email;
    std::string m_card;
public:
    Client(std::string first_name, std::string last_name, std::string father_name, std::string phone_number, std::string email, std::string card) : m_last_name(last_name), m_first_name(first_name), m_father_name(father_name), m_phone_number(phone_number), m_email(email), m_card(card) {
        Client_ID++;
        m_id = Client_ID;
    }
    std::string Get_last_name(){
        return m_last_name;
    }
    std::string Get_first_name(){
        return m_first_name;
    }
    std::string Get_father_name(){
        return m_father_name;
    }
    std::string Get_phone_number(){
        return m_phone_number;
    }
    std::string Get_email(){
        return m_email;
    }
    std::string Get_card(){
        return m_card;
    }
    int Get_ID(){
        return m_id;
    }
};



class Master{
private:
    std::string m_last_name;
    std::string m_first_name;
    std::string m_father_name;
    std::string m_phone_number;
    static int Master_ID;
    int m_id;
    int m_experience;
    int m_salary;
    std::string m_card;
public:
    Master(std::string first_name, std::string last_name, std::string father_name, std::string phone_number, int exp,  int salary) : m_last_name(last_name), m_first_name(first_name), m_experience(exp), m_father_name(father_name), m_phone_number(phone_number), m_salary(salary){
        Master_ID++;
        m_id = Master_ID;
    }
    
    std::string Get_last_name(){
        return m_last_name;
    }
    std::string Get_first_name(){
        return m_first_name;
    }
    std::string Get_father_name(){
        return m_father_name;
    }
    std::string Get_phone_number(){
        return m_phone_number;
    }
    int Get_experience(){
        return m_experience;
    }
    int Get_Salary(){
        return m_salary;
    }
    int Get_ID(){
        return m_id;
    }
};

class Device{
    static int Device_ID;
    int m_id;
    std::string m_name;
    std::string m_model;
    std::string m_breakage;
public:
    Device(std::string name, std::string model, std::string breakage) : m_name(name), m_model(model), m_breakage(breakage){
        Device_ID++;
        m_id = Device_ID;
    }
    std::string Get_name(){
        return m_name;
    }
    std::string Get_model(){
        return m_model;
    }
    std::string Get_breakage(){
        return m_breakage;
    }
    int Get_ID(){
        return m_id;
    }
};

class Service{
private:
    std::string m_service_name;
    std::string m_time;
    std::string m_cost;
    static int Service_ID;
    int m_id;
public:
    Service(std::string service_name, std::string time, std::string cost) : m_service_name(service_name), m_time(time), m_cost(cost){
        Service_ID++;
        m_id = Service_ID;
    }
    std::string Get_name(){
        return m_service_name;
    }
    std::string Get_time(){
        return m_time;
    }
    std::string Get_cost(){
        return m_cost;
    }
    int Get_ID(){
        return m_id;
    }
};


#endif /* Tables_h */

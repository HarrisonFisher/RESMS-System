//
// Created by Harrison on 1/4/2024.
//

#ifndef REMS_PROPERTY_H
#define REMS_PROPERTY_H

#include <iostream>
#include "Agent.h"
#include <string>

using std::string;

class Property {

private :
    Agent agent;
    float size;
    int roomtype;
    string Type;
    int PostalCode;
    float sellingPrice;

public :

    Property(float s, int p, float size, string type, Agent agent, int roomtype);


    void setSellingPrice(float x) { this->sellingPrice = x; }
    void setPostalCode(int x) { this->PostalCode = x; }
    void setsize(float x) { this->size = x; }
    void setType(string x) { this->Type = x; }
    void setroomtype(int x) { this->roomtype = x; }
    void setAgent(Agent x) { this->agent = x; }


    float getsellingPrice() { return this->sellingPrice; }
    int getPostalCode() { return this->PostalCode; }
    float getsize() { return this->size; }
    string getType() { return this->Type; }
    int getroomtype() { return this->roomtype; }
    Agent getagent() { return agent; }
};

Property::Property(float s, int p, float size, string type, Agent agent, int roomtype) {
    this->agent = agent;
    this->Type = type;
    this->size = size;
    this->roomtype = roomtype;
    PostalCode = p;
    sellingPrice = s;


}


#endif //REMS_PROPERTY_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>

#include <algorithm>  // Add this line for find_if
#include <iomanip>

#include "Data.h"
//#include "Property.h"
using std::cout;
using std:: cin;
using std::endl;
using std::ofstream;

void addProperty(std::list<Data> &l)
{
    Data datos;
    string agentid,contact,size,roomtype,location,sellingprice;
    cout<<"welcome to the propperty adding menu"<<endl;

    cout<<"Please insert your Agent ID:"<<endl;
    cin >> agentid;
    datos.setAgentId(agentid);
    cout<<"please insert your Contact:"<<endl;
    cin >> contact;
    datos.setContact(contact);
    cout<<"please insert your Property Size:"<<endl;
    cin >> size;
    datos.setPropertySize(size);
    cout<<"please insert your RoomType:"<<endl;
    cin >> roomtype;
    datos.setRoomType(roomtype);
    cout<<"please insert your Location:"<<endl;
    cin >> location;
    datos.setLocation(location);
    cout<<"please insert your Selling Price:"<<endl;
    cin >> sellingprice;
    datos.setSellingPrice(sellingprice);
    l.push_back(datos);
}

void OrderList(std::list<Data> &l)
{
    char resp;
    do{
        cout<<"What order do you want? ascending=a or descending=d"<<endl;
        cin>> resp;
        if(resp!='a'&&resp!='d')
        {
            cout<<"ERROR, Please be careful"<<endl;
        }
    }while(resp!='a'&&resp!='d');
    l.sort();
    if(resp=='d'){
        l.reverse();
    }
}

bool findpass(string pass, string id)
{
    string pas,ag;
    bool found=false;
    std::ifstream passwords;
    passwords.open("data/passwords.in");
    while(!passwords.eof() && !found) // To get you all the lines.
        {
        passwords>>pas>>ag;


        if(pass==pas && ag == id)
        {
            found=true;

        }
        }
    passwords.close();
    return found;
}

bool login(string agentid,string password )
{
    bool pass,granted =false;



    pass=findpass(password,agentid);
    if(pass)
    {

        cout<<"access granted"<<endl;
        granted=true;

    }else{
        cout<<"\nLogin Failed!!\n";
    }
    return (granted);
}




void changepass(string id)
{
    std::list<string> passw, agentid;
    string pas, ag;
    std::ifstream passwords;
    std::ofstream p;
    passwords.open("data/passwords.in");

    while (!passwords.eof())
    {
        passwords >> pas >> ag;
        passw.push_back(pas);
        agentid.push_back(ag);
    }

    passwords.close();

    cout << "Just for security, I will need you to re-login" << endl;
    cout << "What is your current password?" << endl;
    cin >> pas;

    p.open("data/passwords.in");

    if (login(id, pas))
    {
        cout << "Access granted, please input the new password" << endl;
        cin >> pas;

        // Iterate through the lists and write to the file
        auto passIt = passw.begin();
        auto agentIt = agentid.begin();

        while (passIt != passw.end() && agentIt != agentid.end())
        {
            p << *passIt << ' ' << *agentIt << '\n';
            ++passIt;
            ++agentIt;
        }
    }

    p.close();
}







char menu ()
{
    char option;

    cout<<"Menu"<<endl;
    cout<<"(a) Add new property"<<endl;
    cout<<"(b) Remove property "<<endl;
    cout<<"(c) Edit sales entries"<<endl;
    cout<<"(d) Inquire or search property sales"<<endl;
    cout<<"(e) Monthly property sales transaction report"<<endl;
    cout<<"(f) List property sale items in ascending or descending order"<<endl;
    cout<<"(g) Administration - add / remove property agent"<<endl;
    cout<<"(h) Administration - change password"<<endl;
    cout<<"(i) Quit"<<endl;
    cin>>option;
    return (option);
}

void load(std::list<Data>& l) {
    Data datos;

    int i = 0;
    unsigned int encontro, anterior;
    std::string STRING, agentid, contact, size, roomtype, location, sellingprice;
    std::ifstream infile;
    infile.open("data/data.in");

    while (getline(infile, STRING)) {
        encontro = STRING.find(':', 0);

        if (encontro != std::string::npos) {
            agentid = STRING.substr(0, encontro);
            datos.setAgentId(agentid);
        }

        anterior = encontro + 1;
        encontro = STRING.find(':', anterior);

        if (encontro != std::string::npos) {
            contact = STRING.substr(anterior, encontro - anterior);
            datos.setContact(contact);
        }

        anterior = encontro + 1;
        encontro = STRING.find(':', anterior);

        if (encontro != std::string::npos) {
            size = STRING.substr(anterior, encontro - anterior);
            datos.setPropertySize(size);
        }

        anterior = encontro + 1;
        encontro = STRING.find(':', anterior);

        if (encontro != std::string::npos) {
            roomtype = STRING.substr(anterior, encontro - anterior);
            datos.setRoomType(roomtype);
        }

        anterior = encontro + 1;
        encontro = STRING.find(':', anterior);

        if (encontro != std::string::npos) {
            location = STRING.substr(anterior, encontro - anterior);
            datos.setLocation(location);
        }

        anterior = encontro + 1;
        sellingprice = STRING.substr(anterior, STRING.length() - anterior);
        datos.setSellingPrice(sellingprice);

        // Append data to the end of the list
        l.push_back(datos);

        i++;
    }

    infile.close();
}




void show()
{
    char option;

    do{
        cout<<"please insert (a) to see the list in ascending order"<<endl;
        cout<<"please insert (b) to see the is in 	descending order"<<endl;
        cout<<"else for returning to main menu"<<endl;
        cin>>option;
        switch (option)
        {
            case 'a':
                break;
            case 'b':
                break;
            default:option=' ';
        }

    }while(option!=' ' &&option !='a' &&option!='b');




}


///////////////////////////////////////////////////////////////////////////////////


//void printList(const std::list<Data>& l) {
//    for (const auto& property : l) {
//        cout << "Agent ID: " << property.getAgentId() << endl;
//        cout << "Contact: " << property.getContact() << endl;
//        cout << "Property Size: " << property.getPropertySize() << endl;
//        cout << "Room Type: " << property.getRoomType() << endl;
//        cout << "Location: " << property.getLocation() << endl;
//        cout << "Selling Price: " << property.getSellingPrice() << endl;
//        cout << "--------------------------" << endl;
//    }
//}

void removeProperty(std::list<Data> &l)
{
    string agentIdToRemove;
    cout << "Enter the Agent ID of the property to remove: ";
    cin >> agentIdToRemove;

    auto it = std::find_if(l.begin(), l.end(), [agentIdToRemove](const Data &property) {
        return property.getAgentId() == agentIdToRemove;
    });

    if (it != l.end())
    {
        // Property found, erase it from the list
        l.erase(it);
        cout << "Property with Agent ID " << agentIdToRemove << " removed successfully." << endl;
    }
    else
    {
        cout << "Property with Agent ID " << agentIdToRemove << " not found." << endl;
    }
}


void editSalesEntries(std::list<Data> &l)
{
    string agentIdToEdit;
    cout << "Enter the Agent ID of the property to edit sales entries: ";
    cin >> agentIdToEdit;

    auto it = std::find_if(l.begin(), l.end(), [agentIdToEdit](const Data &property) {
        return property.getAgentId() == agentIdToEdit;
    });

    if (it != l.end())
    {
        // Property found, allow user to edit sales entries
        string newSellingPrice;
        cout << "Enter the new Selling Price for the property with Agent ID " << agentIdToEdit << ": ";
        cin >> newSellingPrice;

        // Update the Selling Price of the property
        it->setSellingPrice(newSellingPrice);

        cout << "Sales entries for property with Agent ID " << agentIdToEdit << " updated successfully." << endl;
    }
    else
    {
        cout << "Property with Agent ID " << agentIdToEdit << " not found." << endl;
    }
}

void inquirePropertySales(const std::list<Data> &l)
{
    string agentIdToInquire;
    cout << "Enter the Agent ID to inquire about property sales: ";
    cin >> agentIdToInquire;

    auto it = std::find_if(l.begin(), l.end(), [agentIdToInquire](const Data &property) {
        return property.getAgentId() == agentIdToInquire;
    });

    if (it != l.end())
    {
        // Property found, display sales information
        cout << "Sales information for property with Agent ID " << agentIdToInquire << ":" << endl;
        cout << "Agent ID: " << it->getAgentId() << endl;
        cout << "Contact: " << it->getContact() << endl;
        cout << "Property Size: " << it->getPropertySize() << endl;
        cout << "Room Type: " << it->getRoomType() << endl;
        cout << "Location: " << it->getLocation() << endl;
        cout << "Selling Price: " << it->getSellingPrice() << endl;
    }
    else
    {
        cout << "Property with Agent ID " << agentIdToInquire << " not found." << endl;
    }
}

void monthlyPropertySalesReport(const std::list<Data> &l)
{
    string monthToReport;
    cout << "Enter the month for the sales report (e.g., January): ";
    cin >> monthToReport;

    // Filter properties based on the specified month
    std::list<Data> filteredProperties;
    std::copy_if(l.begin(), l.end(), std::back_inserter(filteredProperties), [monthToReport](const Data &property) {
        // Assuming that the month information is part of the property data structure
        // For simplicity, let's assume the Location field stores the month of sale
        return property.getLocation() == monthToReport;
    });

    if (!filteredProperties.empty())
    {
        // Display the sales report
        cout << "Monthly Property Sales Transaction Report for " << monthToReport << ":" << endl;
        cout << std::setw(15) << "Agent ID" << std::setw(15) << "Contact" << std::setw(15) << "Property Size"
        << std::setw(15) << "Room Type" << std::setw(15) << "Location" << std::setw(15) << "Selling Price" << endl;

        for (const auto &property : filteredProperties)
        {
            cout << std::setw(15) << property.getAgentId() << std::setw(15) << property.getContact()
            << std::setw(15) << property.getPropertySize() << std::setw(15) << property.getRoomType()
            << std::setw(15) << property.getLocation() << std::setw(15) << property.getSellingPrice() << endl;
        }
    }
    else
    {
        cout << "No sales transactions found for " << monthToReport << "." << endl;
    }
}

void saveToFile(const std::list<Data> &l)
{
    std::ofstream outFile("data/data.in"); // You can change the filename as needed

    if (outFile.is_open())
    {
        for (const auto &property : l)
        {
            outFile << property.getAgentId() << ":" << property.getContact() << ":" << property.getPropertySize()
            << ":" << property.getRoomType() << ":" << property.getLocation() << ":" << property.getSellingPrice() << "\n";
        }

        outFile.close();
        std::cout << "Data saved successfully to data.out." << std::endl;
    }
    else
    {
        std::cerr << "Error opening the file for saving." << std::endl;
    }
}

///////////////////////////////////////////////////////////////////////////////////

int main()
{
    std::list<Data> l;
    string agentid,password;
    cout<<"please insert your AgentID"<<endl;
    cin>>agentid;
    cout<<" please insert your password"<<endl;
    cin>>password;
    if(login(agentid,password)){

        load(l);
        printList(l);
        char option ; // the variable used for storing the users option data
        do{
            option=menu();

            switch (option)
            {
                case 'a':
                    // Add new property
                    addProperty(l); // Add new property

                    break;
                case 'b':
                    // Remove property
                    removeProperty(l);
                    break;
                case 'c':
                    //Edit sales entries
                    editSalesEntries(l);
                    break;
                case 'd':
                    //  Inquire or search property sales
                    inquirePropertySales(l);
                    break;
                case 'e':
                    // Monthly property sales transaction report
                    monthlyPropertySalesReport(l);
                    break;
                case 'f':
                    // List property sale items in ascending or descending order
                    show();
                    break;
                case 'g':
                    // Administration - add / remove property agent

                    break;
                case 'i':
                    // Save data before exiting
                    saveToFile(l);
                    cout << "good bye" << endl;
                    break;

                case 'h':
                    changepass(agentid);
                    break;

                default:
                    cout << "wrong selection" << endl;


            }


        }while(option!='i');
    }
    return (0);

}
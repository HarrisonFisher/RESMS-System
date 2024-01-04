#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Data.h"
#include "Property.h"
#include <list>
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

void load(std::list<Data> l)
{
    Data datos;

    int i=0;
    unsigned int encontro,anterior;
    std::string STRING,agentid,contact,size,roomtype,location,sellingprice;
    std::ifstream infile;
    infile.open ("data/data.in");
    while(!infile.eof()) // To get you all the lines.
        {
        getline(infile,STRING); // Saves the line in STRING.
        encontro = STRING.find(':', 0);
        if(encontro != std::string::npos )
        {
            agentid = STRING.substr(0, encontro);
            datos.setAgentId(agentid);

        }
        anterior=encontro+1;
        encontro= STRING.find(':', anterior);

        if(encontro != std::string::npos )
        {
            contact = STRING.substr(anterior, encontro-anterior);
            datos.setContact(contact);
        }
        anterior=encontro+1;
        encontro= STRING.find(':', anterior);

        if(encontro != std::string::npos )
        {
            size = STRING.substr(anterior, encontro-anterior);
            datos.setPropertySize(size);
        }

        anterior=encontro+1;

        encontro= STRING.find(':', anterior+1);

        if(encontro != std::string::npos )
        {
            roomtype = STRING.substr(anterior, encontro-anterior);
            datos.setRoomType(roomtype);
        }

        anterior=encontro+1;

        encontro= STRING.find(':', anterior+1);

        if(encontro != std::string::npos )
        {
            location = STRING.substr(anterior, encontro-anterior);
            datos.setLocation(location);
        }

        anterior=encontro+1;





        sellingprice= STRING.substr(anterior, STRING.length()-anterior);
        datos.setSellingPrice(sellingprice);

        l.push_back(datos); //Saved each data from "data.in" to the end of the list





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
        char option ; // the variable used for storing the users option data
        do{
            option=menu();

            switch (option)
            {
                case 'a':

                    break;
                case 'b':
                    break;
                case 'c':
                    break;
                case 'd':
                    break;
                case 'e':
                    break;
                case 'f':
                    show();
                    break;
                    case 'g':
                        break;
                    case 'i': cout<<"good bye"<<endl;
                    break;

                    case 'h':changepass(agentid);
                    break;

                    break;
                    default:cout<<"wrong selection"<<endl;


            }


        }while(option!='i');
    }
    return (0);

}
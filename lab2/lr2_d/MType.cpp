#include <iostream>
#include "MType.h"
#include <string>
#include <fstream>

using namespace std;
using namespace Records;

MalfunctionType::MalfunctionType()
{
    TypeNumber = 0;
    ModelNumber = 0;
    Description = "";
    MalfunctionSymptoms = "";
    RepairMethods = "";
    SparePartNumber_1 = 0;
    SparePartNumber_2 = 0;
    SparePartNumber_3 = 0;
    CostOfWork = 0;
    Done = false;
}

MalfunctionType::~MalfunctionType()
{
}

int MalfunctionType::getTypeNumber()
{
    return TypeNumber;
}
void MalfunctionType::setTypeNumber(int typeNumber)
{
    TypeNumber = typeNumber;
}
int MalfunctionType::getModelNumber()
{
    return ModelNumber;
}
void MalfunctionType::setModelNumber(int model)
{
    ModelNumber = model;
}
string MalfunctionType::getDescription()
{
    return Description;
}
void MalfunctionType::setDescription(string description)
{
    Description = description;
}
string MalfunctionType::getMalfunctionSymptoms()
{
    return MalfunctionSymptoms;
}
void MalfunctionType::setMalfunctionSymptoms(string symptoms)
{
    MalfunctionSymptoms = symptoms;
}
string MalfunctionType::getRepairMethods()
{
    return RepairMethods;
}
void MalfunctionType::setRepairMethods(string repair)
{
    RepairMethods = repair;
}
int MalfunctionType::getSparePartNumber_1()
{
    return SparePartNumber_1;
}
void MalfunctionType::setSparePartNumber_1(int num)
{
    SparePartNumber_1 = num;
}
int MalfunctionType::getSparePartNumber_2()
{
    return SparePartNumber_2;
}
void MalfunctionType::setSparePartNumber_2(int num)
{
    SparePartNumber_2 = num;
}
int MalfunctionType::getSparePartNumber_3()
{
    return SparePartNumber_3;
}
void MalfunctionType::setSparePartNumber_3(int num)
{
    SparePartNumber_3 = num;
}
int MalfunctionType::getCostOfWork()
{
    return CostOfWork;
}
void MalfunctionType::setCostOfWork(int cost)
{
    int symptomsLength = this->getMalfunctionSymptoms().length();
    CostOfWork = cost + (symptomsLength * 0.5);
}

bool MalfunctionType::getDone()
{
    return Done;
}
void MalfunctionType::setDone(bool done)
{
    Done = done;
}


void MalfunctionType::premium(int inExtraCost)
{
    string costline = "Cost of work: " + std::to_string(getCostOfWork());
    setCostOfWork(getCostOfWork() + inExtraCost);

    std::ifstream i_file;
    std::ofstream o_file;
    std::string line;
    bool found = false;
    i_file.open("db.txt");
    o_file.open("db_new.txt", std::ios_base::app);

    while(std::getline(i_file, line))
    {
        if(line.find("Type number: " + std::to_string(getTypeNumber())) != std::string::npos)
        {
            found = true;
        }
        if(found && line.find(costline) != std::string::npos)
        {
            line = "Cost of work: " + std::to_string(getCostOfWork());
        }
        o_file << line + "\n";
    }
    i_file.close();
    o_file.close();

    remove("db.txt");
    rename("db_new.txt", "db.txt");
}
void MalfunctionType::discount(int inDiscount)
{
    string costline = "Cost of work: " + std::to_string(getCostOfWork());
    setCostOfWork(getCostOfWork() - inDiscount);

    std::ifstream i_file;
    std::ofstream o_file;
    std::string line;
    bool found = false;
    i_file.open("db.txt");
    o_file.open("db_new.txt", std::ios_base::app);

    while(std::getline(i_file, line))
    {
        if(line.find("Type number: " + std::to_string(getTypeNumber())) != std::string::npos)
        {
            found = true;
        }
        if(found && line.find(costline) != std::string::npos)
        {
            line = "Cost of work: " + std::to_string(getCostOfWork());
        }
        o_file << line + "\n";
    }
    i_file.close();
    o_file.close();

    remove("db.txt");
    rename("db_new.txt", "db.txt");
}
void MalfunctionType::done()
{
    string doneline = "Done: " + std::to_string(getDone());
    Done = true;

    std::ifstream i_file;
    std::ofstream o_file;
    std::string line;
    bool found = false;
    i_file.open("db.txt");
    o_file.open("db_new.txt", std::ios_base::app);

    while(std::getline(i_file, line))
    {
        if(line.find("Type number: " + std::to_string(getTypeNumber())) != std::string::npos)
        {
            found = true;
        }
        if(found && line.find(doneline) != std::string::npos)
        {
            line = "Done: " + std::to_string(getDone());
        }
        o_file << line + "\n";
    }
    i_file.close();
    o_file.close();

    remove("db.txt");
    rename("db_new.txt", "db.txt");

}
void MalfunctionType::display()
{
    /*
    cout << "Type number: " << getTypeNumber() << endl;
    cout << "Model number: " << getModelNumber() << endl;
    cout << "Description: " << getDescription() << endl;
    cout << "Malfunction symptoms: " << getMalfunctionSymptoms() << endl;
    cout << "Repair methods: " << getRepairMethods() << endl;
    cout << "Part number 1: " << getSparePartNumber_1() << endl;
    cout << "Part number 2: " << getSparePartNumber_2() << endl;
    cout << "Part number 3: " << getSparePartNumber_3() << endl;
    cout << "Cost of work: " << getCostOfWork() << endl;
    cout << "Is work done: " << getDone() << endl;
    cout << endl;
    */

    std::ifstream file;
    std::string line;
    int counter = 0;
    file.open("db.txt");

    while(std::getline(file, line))
    {
        if(line.find("Type number: " + std::to_string(getTypeNumber())) != std::string::npos)
        {
            counter++;
        }
        if(counter > 0)
        {
            cout << line << endl;
            counter++;
        }
        if(counter > 11)
        {
            break;
        }
    }
    file.close();
}

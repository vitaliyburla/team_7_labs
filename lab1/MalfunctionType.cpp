#include <iostream>
#include "MalfunctionType.h"
#include <string>

using namespace std;

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

void MalfunctionType::getInformationAboutMalfunction()
{
    cout << "Type number: " << getTypeNumber() << endl;
    cout << "Model number: " << getModelNumber() << endl;
    cout << "Description: " << getDescription() << endl;
    cout << "Malfunction symptoms: " << getMalfunctionSymptoms() << endl;
    cout << "Repair methods: " << getRepairMethods() << endl;
    cout << "Part number 1: " << getSparePartNumber_1() << endl;
    cout << "Part number 2: " << getSparePartNumber_2() << endl;
    cout << "Part number 3: " << getSparePartNumber_3() << endl;
    cout << "Cost of work: " << getCostOfWork() << endl;
    cout << endl;
}

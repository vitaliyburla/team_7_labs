#include <iostream>
#include "MalfunctionType.h"
#include <string>

using namespace std;

void inpText();

int main()
{
    // stack-based
    MalfunctionType malType1;
    MalfunctionType malType2;
    MalfunctionType malType3;

    malType1.setTypeNumber(1);
    malType1.setModelNumber(1111);
    malType1.setDescription("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.");
    malType1.setMalfunctionSymptoms("Lorem, ipsum, dolor, sit, amet, consectetur, adipiscing ,elit");
    malType1.setRepairMethods("Ut, enim, ad, minim, veniam");
    malType1.setSparePartNumber_1(10);
    malType1.setSparePartNumber_2(11);
    malType1.setSparePartNumber_3(12);
    malType1.setCostOfWork(500);

    malType2.setTypeNumber(2);
    malType2.setModelNumber(2222);
    malType2.setDescription("Lorem ipsum dolor sit amet, consectetur adipiscing elit");
    malType2.setMalfunctionSymptoms("Duis, aute, irure, dolor, in, reprehenderit");
    malType2.setRepairMethods("Excepteur, sint, occaecat");
    malType2.setSparePartNumber_1(20);
    malType2.setSparePartNumber_2(21);
    malType2.setSparePartNumber_3(22);
    malType2.setCostOfWork(400);

    malType3.setTypeNumber(3);
    malType3.setModelNumber(3333);
    malType3.setDescription("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt");
    malType3.setMalfunctionSymptoms("Duis, aute, irure");
    malType3.setRepairMethods("Ut, enim, ad, minim, veniam");
    malType3.setSparePartNumber_1(30);
    malType3.setSparePartNumber_2(31);
    malType3.setSparePartNumber_3(32);
    malType3.setCostOfWork(300);

    // heap-based
    MalfunctionType *malType4;
    MalfunctionType *malType5;

    malType4 = new MalfunctionType();
    malType4->setTypeNumber(4);
    malType4->setModelNumber(4444);
    malType4->setDescription("Pulvinar proin gravida hendrerit lectus.");
    malType4->setMalfunctionSymptoms("Tellus, orci, ac, auctor");
    malType4->setRepairMethods("Facilisis, mauris, sit, amet");
    malType4->setSparePartNumber_1(40);
    malType4->setSparePartNumber_2(41);
    malType4->setSparePartNumber_3(42);
    malType4->setCostOfWork(450);

    malType5 = new MalfunctionType();
    malType5->setTypeNumber(5);
    malType5->setModelNumber(5555);
    malType5->setDescription("Pulvinar proin gravida hendrerit lectus sed cras ornare arcu");
    malType5->setMalfunctionSymptoms("Donec, enim, diam, vulputate");
    malType5->setRepairMethods("Facilisis, mauris, sit, amet, massa, vitae");
    malType5->setSparePartNumber_1(50);
    malType5->setSparePartNumber_2(51);
    malType5->setSparePartNumber_3(52);
    malType5->setCostOfWork(610);

    malType1.getInformationAboutMalfunction();
    malType2.getInformationAboutMalfunction();
    malType3.getInformationAboutMalfunction();
    malType4->getInformationAboutMalfunction();
    malType5->getInformationAboutMalfunction();

    inpText();

    return 0;
}
void inpText()
{
    MalfunctionType m;
    int typeN;
    int modelN;

    string nonestr;
    string description;
    string symptoms;
    string methods;

    int partN1;
    int partN2;
    int partN3;
    int cost;

    cout << "Enter type number: \n";
    cin >> typeN;
    m.setTypeNumber(typeN);

    cout << "Enter model number: \n";
    cin >> modelN;
    m.setModelNumber(modelN);

    getline(cin, description);

    cout << "Enter description:\n";
    getline(cin, description);
    m.setDescription(description);

    cout << "Enter malfunction symptoms:\n";
    getline(cin, symptoms);
    m.setMalfunctionSymptoms(symptoms);

    cout << "Enter repair methods:\n";
    getline(cin, methods);
    m.setRepairMethods(methods);

    cout << "Enter part number 1: \n";
    cin >> partN1;
    m.setSparePartNumber_1(partN1);

    cout << "Enter part number 2: \n";
    cin >> partN2;
    m.setSparePartNumber_2(partN2);

    cout << "Enter part number 3: \n";
    cin >> partN3;
    m.setSparePartNumber_3(partN3);

    cout << "Enter cost of work: \n";
    cin >> cost;
    m.setCostOfWork(cost);

    m.getInformationAboutMalfunction();
}
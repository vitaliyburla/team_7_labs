#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>

#include "Database.h"

using namespace std;
using namespace Records;

int displayMenu();
void doShow(Database& inDB);
void doNew(Database& inDB);
void doPremium(Database& inDB);
void doDiscount(Database& inDB);
void testDB(Database& myDB);

int main(int argc, char** argv)
{
  Database MTypeDB;
  testDB(MTypeDB);

  bool exit = false;

  while (!exit) {
    int selection = displayMenu();

    switch (selection) {
    case 1:
      doNew(MTypeDB);
      break;
    case 2:
      doPremium(MTypeDB);
      break;
    case 3:
      doDiscount(MTypeDB);
      break;
    case 4:
      MTypeDB.displayAll();
      break;
    case 5:
      MTypeDB.displayCurrent();
      break;
    case 6:
      MTypeDB.displayClosed();
      break;
    case 7:
      doShow(MTypeDB);
      break;
    case 0:
      exit = true;
      break;
    default:
      cerr << "Unknown command." << endl;
    }
  }
}

int displayMenu()
{
  int selection;

  cout << endl;
  cout << "Malfunction Database" << endl;
  cout << "-----------------" << endl;
  cout << "1) Took new order" << endl;
  cout << "2) Set premium prize" << endl;
  cout << "3) Set dicount prize" << endl;
  cout << "4) List all Malfunction Types" << endl;
  cout << "5) List all current Malfunction Types" << endl;
  cout << "6) List all closed Malfunction Types" << endl;
  cout << "7) Show particular order details" << endl;
  cout << "0) Quit" << endl;
  cout << endl;
  cout << "---> ";

  cin >> selection;

  return selection;
}

void doNew(Database& inDB)
{
    int modelNumber;
    std::string description;
    std::string mSymptoms;
    std::string repairMethods;
    int sPartNum_1;
    int sPartNum_2;
    int sPartNum_3;
    int costOfWork;

  cout << "Enter model number: \n";
  cin >> modelNumber;

  getline(cin, description);

  cout << "Enter description:\n";
  getline(cin, description);

  cout << "Enter malfunction symptoms:\n";
  getline(cin, mSymptoms);

  cout << "Enter repair methods:\n";
  getline(cin, repairMethods);

  cout << "Enter part number 1: \n";
  cin >> sPartNum_1;

  cout << "Enter part number 2: \n";
  cin >> sPartNum_2;

  cout << "Enter part number 3: \n";
  cin >> sPartNum_3;

  cout << "Enter cost of work: \n";
  cin >> costOfWork;

  try {
    inDB.addMType(modelNumber,
                  description,
                  mSymptoms,
                  repairMethods,
                  sPartNum_1,
                  sPartNum_2,
                  sPartNum_3,
                  costOfWork);
  } catch (std::exception ex) {
    cerr << "Unable to add new Malfunction Type!" << endl;
  }
}

void doPremium(Database& inDB)
{
  int MTypeNumber;
  int extraPrize;

  cout << "Malfunction Type number? ";
  cin >> MTypeNumber;

  cout << "How much of a raise? ";
  cin >> extraPrize;

  try {
    MalfunctionType& mt = inDB.getMType(MTypeNumber);
    mt.premium(extraPrize);
    cout << "Prize for " << MTypeNumber << " has been raised." << endl;
  } catch (std::exception ex) {
    cerr << "Unable to set premium prize!" << endl;
  }
}

void doDiscount(Database& inDB)
{
  int MTypeNumber;
  int discountPrize;

  cout << "Malfunction Type number? ";
  cin >> MTypeNumber;

  cout << "How much of a discount? ";
  cin >> discountPrize;

  try {
    MalfunctionType& mt = inDB.getMType(MTypeNumber);
    mt.discount(discountPrize);
    cout << "Prize for " << MTypeNumber << " has been lowered." << endl;
  } catch (...) {
    cerr << "Unable to set a discount!" << endl;
  }
}
void doShow(Database& inDB)
{
    int MTypeNumber;

    cout << "Malfunction Type number? ";
    cin >> MTypeNumber;

    try {
      MalfunctionType& mt = inDB.getMType(MTypeNumber);
      mt.display();
    } catch (...) {
      cerr << "Unable to find this order!" << endl;
    }
}
void testDB(Database& myDB)
{
    std::ofstream file;
    file.open("db.txt", std::ofstream::out | std::ofstream::trunc);
    file.close();

    MalfunctionType& mt1 = myDB.addMType(7777, "aaaa", "bbbb", "cccc", 4, 2, 8, 200);
    mt1.premium();

    MalfunctionType& mt2 = myDB.addMType(9999, "mmmm", "nnnn", "oooo", 9, 21, 1, 300);
    mt2.done();

    MalfunctionType& mt3 = myDB.addMType(8888, "kkkk", "tttt", "llll", 13, 16, 7, 400);
    mt3.discount();

    MalfunctionType& mt4 = myDB.addMType(4444,"Pulvinar proin gravida hendrerit lectus.",
                                         "Tellus, orci, ac, auctor", "Facilisis, mauris, sit, amet",
                                         40, 41, 42, 450);
    mt4.premium(600);

    MalfunctionType& mt5 = myDB.addMType(5555, "Pulvinar proin gravida hendrerit lectus sed cras ornare arcu",
                                         "Donec, enim, diam, vulputate",
                                         "Facilisis, mauris, sit, amet, massa, vitae",
                                         50, 51, 52, 610);
    mt5.done();

    /*
    cout << "All Malfuction Types: " << endl;
    cout << endl;
    myDB.displayAll();

    cout << endl;
    cout << "Current Malfuction Types: " << endl;
    cout << endl;
    myDB.displayCurrent();

    cout << endl;
    cout << "Closed Malfuction Types: " << endl;
    cout << endl;
    myDB.displayClosed();
    */
}


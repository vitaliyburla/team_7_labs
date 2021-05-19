#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>

#include "Database.h"

using namespace std;

namespace Records {

  Database::Database()
  {
    mNextSlot = 0;
    mNextMTypeNumber = kFirstMTypeNumber;
  }
  Database::~Database()
  {
  }

  MalfunctionType& Database::addMType(int modelNumber,
                                      std::string description,
                                      std::string mSymptoms,
                                      std::string repairMethods,
                                      int sPartNum_1,
                                      int sPartNum_2,
                                      int sPartNum_3,
                                      int costOfWork)
  {
    if (mNextSlot >= kMaxMTypes) {
      cerr << "There is no more room to add the new MType!" << endl;
      throw exception();
    }
    std::ofstream file;
    file.open("db.txt", std::ios_base::app);

    MalfunctionType& theMType = mMTypes[mNextSlot++];
    theMType.setTypeNumber(mNextMTypeNumber++);
    file << "Type number: " + std::to_string(theMType.getTypeNumber()) + "\n";
    theMType.setModelNumber(modelNumber);
    file << "Model number: " + std::to_string(theMType.getModelNumber()) + "\n";
    theMType.setDescription(description);
    file << "Description: " + theMType.getDescription() + "\n";
    theMType.setMalfunctionSymptoms(mSymptoms);
    file << "Malfunction symptoms: " + theMType.getMalfunctionSymptoms() + "\n";
    theMType.setRepairMethods(repairMethods);
    file << "Repair methods: " + theMType.getRepairMethods() + "\n";
    theMType.setSparePartNumber_1(sPartNum_1);
    file << "Part number 1: " + std::to_string(theMType.getSparePartNumber_1()) + "\n";
    theMType.setSparePartNumber_2(sPartNum_2);
    file << "Part number 2: " + std::to_string(theMType.getSparePartNumber_2()) + "\n";
    theMType.setSparePartNumber_3(sPartNum_3);
    file << "Part number 3: " + std::to_string(theMType.getSparePartNumber_3()) + "\n";
    theMType.setCostOfWork(costOfWork);
    file << "Cost of work: " + std::to_string(theMType.getCostOfWork()) + "\n";
    theMType.setDone(false);
    file << "Done: " + std::to_string(theMType.getDone()) + "\n";
    file << "\n";
    file.close();

    return theMType;
  }
  MalfunctionType& Database::getMType(int inMTypeNumber)
  {
    for (int i = 0; i < mNextSlot; i++) {
      if (mMTypes[i].getTypeNumber() == inMTypeNumber) {
    return mMTypes[i];
      }
    }

    cerr << "No MType with MType number " << inMTypeNumber << endl;
    throw exception();
  }

  MalfunctionType& Database::getMtype(int modelNumber,
                                      std::string description,
                                      std::string mSymptoms,
                                      std::string repairMethods)
  {
    for (int i = 0; i < mNextSlot; i++) {
      if (mMTypes[i].getModelNumber() == modelNumber &&
      mMTypes[i].getDescription() == description &&
      mMTypes[i].getMalfunctionSymptoms() == mSymptoms &&
      mMTypes[i].getRepairMethods() == repairMethods) {
    return mMTypes[i];
      }
    }

    cerr << "No match with name " << modelNumber << " "
            << description << " "
               << mSymptoms << " "
                  << repairMethods << endl;
    throw exception();
  }
  void Database::displayAll()
  {
    for (int i = 0; i < mNextSlot; i++) {
      mMTypes[i].display();
    }
  }

  void Database::displayCurrent()
  {
    for (int i = 0; i < mNextSlot; i++) {
      if (!mMTypes[i].getDone()) {
    mMTypes[i].display();
      }
    }
  }

  void Database::displayClosed()
  {
    for (int i = 0; i < mNextSlot; i++) {
      if (mMTypes[i].getDone()) {
    mMTypes[i].display();
      }
    }
  }
}

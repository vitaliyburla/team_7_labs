#include <iostream>
#include "MType.h"

namespace Records {

  const int kMaxMTypes = 100;
  const int kFirstMTypeNumber = 1000;
    class Database
      {
      public:
    Database();
    ~Database();

    MalfunctionType& addMType(int modelNumber,
                              std::string description,
                              std::string mSymptoms,
                              std::string repairMethods,
                              int sPartNum_1,
                              int sPartNum_2,
                              int sPartNum_3,
                              int costOfWork);
    MalfunctionType& getMType(int inMTypeNumber);
    MalfunctionType& getMtype(int modelNumber,
                              std::string description,
                              std::string mSymptoms,
                              std::string repairMethods);
    void        displayAll();
    void        displayCurrent();
    void        displayClosed();
      protected:
    MalfunctionType    mMTypes[kMaxMTypes];
    int         mNextSlot;
    int         mNextMTypeNumber;
      };
}

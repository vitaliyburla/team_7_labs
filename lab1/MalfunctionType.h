#include <string>

class MalfunctionType
{
public:
    MalfunctionType();
    ~MalfunctionType();

    int getTypeNumber();
    void setTypeNumber(int typeNumber);
    int getModelNumber();
    void setModelNumber(int modelNumber);
    std::string getDescription();
    void setDescription(std::string description);
    std::string getMalfunctionSymptoms();
    void setMalfunctionSymptoms(std::string symptoms);
    std::string getRepairMethods();
    void setRepairMethods(std::string methods);
    int getSparePartNumber_1();
    void setSparePartNumber_1(int number);
    int getSparePartNumber_2();
    void setSparePartNumber_2(int number);
    int getSparePartNumber_3();
    void setSparePartNumber_3(int number);
    int getCostOfWork();
    void setCostOfWork(int cost);
    void getInformationAboutMalfunction();

private:
    int TypeNumber;
    int ModelNumber;
    std::string Description;
    std::string MalfunctionSymptoms;
    std::string RepairMethods;
    int SparePartNumber_1;
    int SparePartNumber_2;
    int SparePartNumber_3;
    int CostOfWork;
};
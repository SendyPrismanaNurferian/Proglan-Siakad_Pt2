#ifndef __MATAKULIAH_HPP__
#define __MATAKULIAH_HPP__

#include <iostream>
#include <vector>

struct DataMhs{
    std::string nama;
    std::string nrp;
    std::string departemen;
};

struct DataDsn{
    std::string nama;
    std::string npp;
    std::string departemen;
};

class MataKuliah{
private:
    std::string id;
    std::string nama_matakuliah;
    int bebansks;
    std::vector <DataMhs> databaseMhs;
    std::vector <DataDsn> databaseDsn;

public:
    MataKuliah(std::string id, std::string nama, int sks);

    void fillDatabaseMhs(DataMhs inputData);
    void fillDatabaseDsn(DataDsn inputData);
    std::string getId();
    std::string getNama();
    int getBebanSKS();
    std::vector<DataDsn> getDatabaseDsn();
    std::vector<DataMhs> getDatabaseMhs();
};

#endif
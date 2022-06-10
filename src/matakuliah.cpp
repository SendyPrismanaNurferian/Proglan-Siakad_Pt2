#include <iostream>
#include <vector>
#include "include/matakuliah.hpp"

MataKuliah::MataKuliah(std::string id, std::string nama, int sks)
        : id(id), nama_matakuliah(nama), bebansks(sks) {}

void MataKuliah::fillDatabaseMhs(DataMhs inputData){
    this->databaseMhs.push_back(inputData);
}

void MataKuliah::fillDatabaseDsn(DataDsn inputData){
    this->databaseDsn.push_back(inputData);
}

std::string MataKuliah::getId(){
    return this->id;
}

std::string MataKuliah::getNama(){
    return this->nama_matakuliah;
}

int MataKuliah::getBebanSKS(){
    return this->bebansks;
}

std::vector<DataDsn> MataKuliah::getDatabaseDsn(){
    return this->databaseDsn;
}

std::vector<DataMhs> MataKuliah::getDatabaseMhs(){
    return this->databaseMhs;
}
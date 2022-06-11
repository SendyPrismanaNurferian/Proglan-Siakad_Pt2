#include <iostream>
#include <vector>
#include "include/mahasiswa.hpp"

//ada penambahan jenis kelamin yang saya buat
mahasiswa::mahasiswa(std::string id, std::string nama, std::string jeniskelamin, int dd, int mm, int yy, 
				std::string nrp, std::string departemen, int tahunmasuk)
		: person(id, nama, jeniskelamin, dd, mm, yy), nrp(nrp), departemen(departemen), tahunmasuk(tahunmasuk)

{
	this->ipk = 0.0;
	this->semesterke = 1;
	this->skslulus = 0;

	this->ips = std::vector<float>(14,0);
}
//Inisialisasi fungsi versi saya  
void mahasiswa::setNRP(std::string nrp)
{
    this->nrp = nrp;
}

std::string mahasiswa::getNRP()
{
    return this->nrp;
}

void mahasiswa::setDepartemen(std::string departemen)
{
    this->departemen = departemen;
}

std::string mahasiswa::getDepartemen()
{
    return this->departemen;
}

void mahasiswa::setTahunmasuk(int tahunmasuk)
{
    this->tahunmasuk = tahunmasuk;
}

int mahasiswa::getTahunmasuk()
{
    return this->tahunmasuk;
}

float mahasiswa::getIPK()
{
    return this->ipk;
}

void mahasiswa::setSemester(int semesterke)
{
	this->semesterke = semesterke;
}

int mahasiswa::getSemester()
{
	return this->semesterke;
}

void mahasiswa::setSKSLulus(int skslulus)
{
	this->skslulus = skslulus;
}

int mahasiswa::getSKSLulus()
{
	return this->skslulus;
}

void mahasiswa::hitungIPK()
{ float total = 0;
    for(long unsigned int i = 0; i < ips.size(); i++){
        total += ips[i];
    }
    total /= (this->getSemester()-1);
    this->ipk = total;
}

void mahasiswa::setIPS(int semester, float ips)
{
	// semester mulai dari 1
	if (semester < 15) {
		this->ips[semester-1] = ips;
		this->hitungIPK();
	}
}

float mahasiswa::getIPS(int semester)
{
	if (semester < 15)
		return this->ips[semester-1];

	return -1.0;
}

std::vector<float> mahasiswa::getAllIPS()
{
	return this->ips;
}

int mahasiswa::getSKSTempuh()
{
	return this->skstempuhsemesterini;
}

void mahasiswa::TambahMataKuliah(std::string MataKuliah, int sks)
{
	if ((this->skstempuhsemesterini + sks) > 24){
		std::cout <<"Mohon maaf SKS sudah melebihi batas maksimal, mohon di cek kembali!" << std::endl;
	} else{
		this->skstempuhsemesterini += sks;
		this->DaftarMataKuliah.push_back(MataKuliah + " (" + std::to_string(sks) + " sks)");
	}
}

void mahasiswa::TampilDaftarMatkul()
{
	for(unsigned int i = 0; i < this->DaftarMataKuliah.size(); i++){
		std::cout << this->DaftarMataKuliah[i];
		if(i != (this->DaftarMataKuliah.size()-1)){
			std::cout << ", ";
		}
	}
}
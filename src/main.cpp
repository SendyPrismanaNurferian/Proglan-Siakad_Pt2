#include <iostream>
#include <vector>
#include <algorithm> //saya tambahkan agar nantinya tidak terjadi error saat matkul
//include*****.hpp merupakan header file code yang sudah dibuat dan bisa digunakan kembali
#include "include/person.hpp"
#include "include/mahasiswa.hpp"
#include "include/dosen.hpp"
#include "include/tendik.hpp"
#include "include/matakuliah.hpp"

using namespace std;

template <typename T> int DatabaseCariNama(T &rec, string nama);

int main(){
	vector<mahasiswa> recMhs;
	vector<dosen> recDosen;
	vector<tendik> recTendik;
    vector<MataKuliah> recMatkul;

    //Menu untuk pilihan user awal
	int menu_terpilih;
    //Menu untuk pilihan user akhir
    char EndNext;
    //Pemberi ID pada tiap person di ID Mahasiswa, Dosen, Tendik
    int IDMhsw = 0;
    int IDDsn = 0;
    int IDTndk = 0;
    int IDMataKuliah = 0;

	while(1){
        system("clear");
		cout << "Selamat datang di Universitas Kembang Lambe Tunas Bangsa" << endl << endl;
		cout << "Data Statistik:" << endl;
		cout << "  1. Jumlah Mahasiswa             : " << recMhs.size() << "mahasiswa" << endl;
		cout << "  2. Jumlah Dosen                 : " << recDosen.size() << "dosen" << endl;
		cout << "  3. Jumlah Tenaga Kependidikan   : " << recTendik.size() << "tenaga kependidikan" << endl;
		cout << "  4. Jumlah Mata Kuliah           : " << recMatkul.size() << "mata kuliah" << endl;
        cout << endl;
        cout << "Silahkan Pilih Salah Satu Menu";
		cout << "Menu: " << endl;
		cout << "  1. Tambah Mahasiswa" << endl;
		cout << "  2. Tambah Dosen" << endl;
		cout << "  3. Tambah Tenaga Kependidikan" << endl;
        cout << "  4. Tambah Mata Kuliah" << endl;
        cout << "  5. Tambah Dosen mengisi Mata Kuliah" << endl;
        cout << "  6. Tambah Mahasiswa di Mata Kuliah" << endl;
		cout << "  7. Tampilkan semua Mahasiswa" << endl;
		cout << "  8. Tampilkan semua Dosen" << endl;
		cout << "  9. Tampilkan semua Tenaga Kependidikan" << endl;
        cout << "  10. Tampilkan Semua Mata Kuliah" << endl;
		cout << "-> Silahkan memilih salah satu Menu : ";
		cin >> menu_terpilih;

		switch(menu_terpilih){
			case 1:{
                system("clear"); //system akan membersihkan layar konsol
                IDMhsw++;
                string id, nama, jeniskelamin, nrp, departemen;
                int dd, mm, yy, tahunmasuk, semesterke, skslulus;
                float ips_temp; //tempat menampung ips sementara sebelum dilanjut ke push_back ke vector ips
                vector <float> ips;
                // Program mengambil input
                id = "mhsw" + to_string(IDMhsw);
                cout << "Masukkan Nama Mahasiswa : ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan Jenis Kelamin (Pria/Wanita) : ";
                cin >> jeniskelamin;
                cout << "Masukkan Tanggal Lahir : ";
                cin >> dd;
                cout << "Masukkan Bulan Lahir : ";
                cin >> mm;
                cout << "Masukkan Tahun Lahir : ";
                cin >> yy;
                cout << "Masukkan NRP/NIM : ";
                cin >> nrp;
                cout << "Masukkan Departemen : ";
                cin.ignore();
                getline(cin, departemen);
                cout << "Masukkan Tahun Masuk : ";
                cin >> tahunmasuk;
                cout << "Masukkan Semester saat ini : ";
                cin >> semesterke;
                if(semesterke > 1){
                cout << "Masukkan Jumlah SKS Lulus Semester Lalu (mohon diisi apa adanya) :";
                cin >> skslulus;
                }
                for(int i = 1; i < semesterke; i++){
                    cout << "Masukkan IPS Semester anda sekarang/ke=" << i << " : ";
                    cin >> ips_temp; cin.ignore();
                    ips.push_back(ips_temp);
                }
                //Menetapkan inputan yang di masukkan ke object penyimpan yaitu inputMhs
                mahasiswa inputMhs = mahasiswa(id, nama, jeniskelamin, dd, mm, yy, nrp, departemen, tahunmasuk);
                inputMhs.setSemester(semesterke);
                inputMhs.setSKSLulus(skslulus);
                for(int i = 1; i < semesterke; i++){
                    inputMhs.setIPS(i, ips[i-1]);
                }
                //Data di push_back dari inputMhs ke vector recMhs dijadikan sebagai database
                recMhs.push_back(inputMhs);
            } break;

			case 2:{
                system("clear");
                IDDsn++;
                string id, nama,jeniskelamin, npp, departemen, pendidikan;
                int dd, mm, yy;
                //Program mengambil input
                id = "dsn" + to_string(IDDsn);
                cout << "Masukkan Nama Dosen : ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan Jenis Kelamin (Pria/Wanita) : ";
                cin >> jeniskelamin;
                cout << "Masukkan Tanggal Lahir : ";
                cin >> dd;
                cout << "Masukkan Bulan Lahir : ";
                cin >> mm;
                cout << "Masukkan Tahun Lahir : ";
                cin >> yy;
                cout << "Masukkan NPP : ";
                cin >> npp;
                cout << "Masukkan Departemen : ";
                cin.ignore();
                getline(cin, departemen);
                cout << "Masukkan Pendidikan : ";
                getline(cin, pendidikan);
                //Menetapkan inputan yang di masukkan ke object penyimpan yaitu inputDosen
                dosen inputDosen = dosen(id, nama, jeniskelamin, dd, mm, yy, npp, departemen, pendidikan);
                //Data di push_back dari inputDosen ke vector recDosen dijadikan sebagai database
                recDosen.push_back(inputDosen);
            } break;

			case 3:{
                system("clear");
                IDTndk++;
                string id, nama, jeniskelamin, npp, unit;
                int dd, mm, yy;
                //Program mengambil input
                id = "tndk" + to_string(IDTndk);
                cout << "Masukkan Nama Tendik : ";
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan Jenis Kelamin (Pria/Wanita) : ";
                cin >> jeniskelamin;
                cout << "Masukkan Tanggal Lahir : ";
                cin >> dd;
                cout << "Masukkan Bulan Lahir : ";
                cin >> mm;
                cout << "Masukkan Tahun Lahir : ";
                cin >> yy;
                cout << "Masukkan NPP : ";
                cin >> npp;
                cout << "Masukkan Unit : ";
                cin.ignore();
                getline(cin, unit);
                //Menetapkan inputan yang di masukkan ke object penyimpan yaitu inputDosen
                tendik inputTendik = tendik(id, nama, jeniskelamin, dd, mm, yy, npp, unit);
                //Data di push_back dari inputTendik ke vector recDosen dijadikan sebagai database
                recTendik.push_back(inputTendik);
            } break;

			case 4:{
                 system("clear");
                 char tampilkanIPS;
                // pilihan buat nunjukin detail ips atau tidak
                label2:
                cout << "apakah anda ingin melihat rincian ip per semester (IPS) juga (y/n): ";
                cin >> tampilkanIPS;
                if(tampilkanIPS != 'y' && tampilkanIPS != 'Y' && tampilkanIPS != 'n' && tampilkanIPS != 'N'){
                    cout << "input salah" << endl;
                    goto label2;
                }
                // menampilkan data
                for(int i = 0; i < IDMhsw; i++){
                    cout << i+1 << ". data mahasiswa dengan id: " << recMhs[i].getId() << endl;
                    cout << "Nama        : " << recMhs[i].getNama() << endl;
                    cout << "Jenis Kelamin   : " << recMhs[i].getjeniskelamin() << endl;
                    cout << "dd/mm/yy    : " << recMhs[i].getTglLahir() << "/" << recMhs[i].getBulanLahir() << "/" << recMhs[i].getTahunLahir() << endl;
                    cout << "NRP         : " << recMhs[i].getNRP() << endl;
                    cout << "Departemen  : " << recMhs[i].getDepartemen() << endl;
                    cout << "Tahun Masuk : " << recMhs[i].getTahunmasuk() << endl;
                    cout << "Semester ke : " << recMhs[i].getSemester() << endl;
                    cout << "SKS Lulus   : " << recMhs[i].getSKSLulus() << endl;
                    printf ("IPK         : %.2f\n", recMhs[i].getIPK());
                    // menampilkan detail ips
                    if(tampilkanIPS == 'y' || tampilkanIPS == 'Y'){
                        cout << "   rincian IPS :\n";
                        for(int j = 1; j < recMhs[i].getSemester(); j++){
                            cout << "\tsem" << j;
                        }
                        cout << endl;
                        for(int j = 1; j < recMhs[i].getSemester(); j++){
                            cout << "\t" << recMhs[i].getIPS(j);
                        }
                        cout << endl;
                    }
                    // menampilkan matkul dan sks semester ini
                    cout << "\tSKS Tempuh Semester ini : ";
                    if(recMhs[i].getSKSTempuh() == 0){
                        cout << "belum menempuh sks di semester ini" << endl;
                    } else{
                        cout << recMhs[i].getSKSTempuh() << endl;
                    }
                    recMhs[i].TampilDaftarMatkul();
                    cout << endl;
                }
            } break;

			case 5:{
                // Menampilkan data dari Dosen
                for(int i = 0; i < IDDsn; i++){
                    cout << i+1 << ". Data Dosen ber-ID: " << recDosen[i].getId() << endl;
                    cout << "Nama            : " << recDosen[i].getNama() << endl;
                    cout << "Jenis Kelamin   : " << recDosen[i].getjeniskelamin() << endl;
                    cout << "dd/mm/yy        : " << recDosen[i].getTglLahir() << "-" << recDosen[i].getBulanLahir() << "-" << recDosen[i].getTahunLahir() << endl;
                    cout << "NPP             : " << recDosen[i].getNPP() << endl;
                    cout << "Departemen      : " << recDosen[i].getDepartemen() << endl;
                    cout << "Pendidikan      : " << recDosen[i].getPendidikan() << endl << endl;
                }
            } break;

			case 6:{
                // Menampilkan data dari Tendik
                for(int i = 0; i < IDTndk; i++){
                    cout << i+1 << ". Data Tendik ber-ID: " << recTendik[i].getId() << endl;
                    cout << "Nama            : " << recTendik[i].getNama() << endl;
                    cout << "Jenis Kelamin   : " << recTendik[i].getjeniskelamin() << endl;
                    cout << "dd/mm/yy        : " << recTendik[i].getTglLahir() << "-" << recTendik[i].getBulanLahir() << "-" << recTendik[i].getTahunLahir() << endl;
                    cout << "NPP             : " << recTendik[i].getNPP() << endl;
                    cout << "Unit            : " << recTendik[i].getUnit() << endl << endl;
                }
            } break;

            case 7:{
                system("clear");
                //Menampilkan Menu Mata Kuliah 
                IDMataKuliah++;
                string nama_matakuliah;
                string id;
                int bebansks;
                //Input Data Mata Kuliah
                id  = "matkul" + to_string(IDMataKuliah);
                cout << "Masukkan Mata Kuliah : ";
                cin.ignore();
                getline(cin, nama_matakuliah);
                cout << "Masukkan Beban SKS dari 2-6 : ";
                cin >> bebansks;
                cin.ignore();
                //Menetapkan inputan yang di masukkan ke object penyimpan yaitu inputDosen
                MataKuliah inputMataKuliah = MataKuliah(id, nama_matakuliah, bebansks);
                //Data di push_back dari inputDosen ke vector recDosen dijadikan sebagai database
                recMatkul.push_back(inputMataKuliah);
            } break;

            case 8:{
                system("clear");
                // Menginput dan Mengambil Data Dosen yang ingin didaftarkan ke Mata Kuliah 
                int IndeksDosen, IndeksMataKuliah;
                string nama;
                cout << "Mohon Tulis Nama Dosen yang akan ditambahkan : ";
                cin.ignore();
                getline(cin, nama);

                //Mencari nama Dosen di Database 
                IndeksDosen = DatabaseCariNama(recDosen, nama);
                if(IndeksDosen == -1){
                    cout << "Nama Dosen yang dimaksud tidak ditemukan!(Mohon konfirmasi Ulang!)" <<endl;
                    break;
                }

                //Menginput dan Mengambil Data Mata Kuliah
                nama.clear();
                cout << "Mohon Tulis Nama Mata Kuliah : ";
                getline(cin, nama);

                //Mencari Nama Mata Kuliah di Database
                IndeksMataKuliah = DatabaseCariNama(recMatkul, nama);
                if(IndeksMataKuliah == -1){
                    cout << "Mata Kuliah yang dimaksud tidak ditemukan!(Mohon konfirmasi Ulang!)" <<endl;
                    break;
                }

                //Menetapkan Dosen ke Mata Kuliah
                DataDsn temp;
                temp.nama = recDosen[IndeksDosen].getNama();
                temp.npp = recDosen[IndeksDosen].getNPP();
                temp.departemen = recDosen[IndeksDosen].getDepartemen();
                recMatkul[IndeksMataKuliah].fillDatabaseDsn(temp);
            } break;

            case 9:{
                system("clear");
                //Menginput dan Mengambil Data Mahasiswa yang ingin ditambakan menjadi peserta di dalam Database Matkul
                int IndeksMhs, IndeksMataKuliah;
                string nama;
                cout << "Mohon Tulis Nama Mahasiswa yang akan ditambahkan : ";
                cin.ignore();
                getline(cin, nama);

                //Mencari nama Mahasiswa di Database
                IndeksMhs = DatabaseCariNama(recMhs, nama);
                if(IndeksMhs == -1){
                    cout << "Nama Mahasiswa yang dimaksud tidak ditemukan!(Mohon konfirmasi Ulang!)";
                    break;
                }

                //Menginput dan Mengambil Data Mata Kuliah
                nama.clear();
                cout << "Mohon Tulis Nama Mata Kuliah : ";
                getline(cin, nama);

                //Mencari Nama Mata Kuliah di Database
                IndeksMataKuliah = DatabaseCariNama(recMatkul, nama);
                if(IndeksMataKuliah == -1){
                    cout << "Mata Kuliah yang dimaksud tidak ditemukan!(Mohon konfirmasi Ulang!)" <<endl;
                    break;
                }

                //Menetapkan Dosen ke Mata Kuliah
                DataMhs temp;
                temp.nama = recMhs[IndeksMhs].getNama();
                temp.nrp = recMhs[IndeksMhs].getNRP();
                temp.departemen = recMhs[IndeksMhs].getDepartemen();
                recMatkul[IndeksMataKuliah].fillDatabaseMhs(temp);
            } break;

            case 10:{
                system("clear");
                char tampilkanDatabase;
                label3:
                //Chosse menu apakah ingin lihat list nahasiswa dan dosen yang ada di dalam suatu mata kuliah
                cout << "Apakah Anda Ingin Melihat list Nama Dosen dan Mahasiswa yang ada dalam Mata Kuliah? Tekan y/Y untuk Ya dan n/N untuk Tidak (y/n) : ";
                cin >> tampilkanDatabase;
                cin.ignore();
                if(tampilkanDatabase != 'y' && tampilkanDatabase != 'Y' && tampilkanDatabase != 'n' && tampilkanDatabase != 'N'){
                    cout << "Input yang Anda masukkan salah!!!" << endl;
                    goto label3;
                }

                //Fungsi Menampilkan Database yang Terkait Mata Kuliah (Nama Matkul,Dosen Matkul,Mahasiswa Matkul)
                //Menampilkan Data Mata Kuliah 
                for(int i = 0; i < IDMataKuliah; i++){
                    cout << i+1 << "Data Mata Kuliah dengan ID : " << recMatkul[i].getId() << endl;
                    cout << "\tNama Mata Kuliah : " << recMatkul[i].getNama() << endl;
                    cout << "\tBeban SKS Mata Kuliah ini :  " << recMatkul[i].getBebanSKS();
                    if(tampilkanDatabase == 'y' || tampilkanDatabase == 'Y'){
                    //Menampilkan Database Dosen
                    cout << "\tData dari Dosen pada Mata Kuliah ini : " << recMatkul[i].getNama() <<": \n";
                    for(int j = 0; j < recMatkul[i].getDatabaseDsn().size(); j++){
                        cout << "\t\t" << j+1 << "." << (recMatkul[i].getDatabaseDsn())[j].nama;
                        cout << "(" << (recMatkul[i].getDatabaseDsn())[j].npp << ") - ";
                        cout << (recMatkul[i].getDatabaseDsn())[j].departemen << endl;
                    }
                    //Menampilkan Database Mahasiswa
                    cout << "\t Data dari Mahasiswa pada Mata Kuliah ini : " << recMatkul[i].getNama() <<" :\n";
                    for(int j = 0; j < recMatkul[i].getDatabaseMhs().size(); j++){
                        cout << "\t\t" << j+1 << "." << (recMatkul[i].getDatabaseMhs())[j].nama;
                        cout << "(" << (recMatkul[i].getDatabaseMhs())[j].nrp << ") - ";
                        cout << (recMatkul[i].getDatabaseMhs())[j].departemen << endl;
                    } 
                }
                cout << endl;
            }
		} break;

          default:
            cout << "Inpuy yang Anda masukkan salah!!!" << endl;
            break;
            }
        //Choose menu untuk menjalankan/melanjutkan program lagi atau tidak
        label:
        cout << "Apakah Anda akan menjalankan atau melanjutkan program? Tekan y/Y untuk Ya dan n/N untuk Tidak (y/n) : ";
        cin >> EndNext;
        if(EndNext == 'n' || EndNext == 'N'){
            cout << "Terimakasih telah mengunjungi Siakad Universitas Kembang Lambe Tunas Bangsa" << endl;
            break;
        } else if(EndNext == 'y' || EndNext == 'Y'){
        } else{
            cout << "Input yang Anda masukkan salah!!!" << endl;
            goto label;
        }
	}
	return 0;
}

template <typename T> int DatabaseCariNama(T &rec, string inputNama){
    string inputNama_hurufbesar, inputNama_hurufkecil, nama_hurufkecil, nama_hurufbesar;

    inputNama_hurufkecil = inputNama;
    transform(inputNama_hurufkecil.begin(), inputNama_hurufkecil.end(), inputNama_hurufkecil.begin(), ::tolower);
    inputNama_hurufbesar = inputNama;
    transform(inputNama_hurufbesar.begin(), inputNama_hurufbesar.end(), inputNama_hurufbesar.begin(), ::toupper);

    for(int i + 0; i < rec.size(); i++){
        nama_hurufkecil = rec[i].getNama();
        transform(inputNama_hurufkecil.begin(), inputNama_hurufkecil.end(), inputNama_hurufkecil.begin(), ::tolower);
        nama_hurufbesar = rec[i].getNama();
        transform(inputNama_hurufbesar.begin(), inputNama_hurufbesar.end(), inputNama_hurufbesar.begin(), ::toupper);

        if((nama_hurufkecil == inputNama_hurufkecil) || (nama_hurufbesar == inputNama_hurufbesar)){
            return i;
        }
    }
    return -1;
}
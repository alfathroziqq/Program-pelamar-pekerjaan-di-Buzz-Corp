//Alfath Roziq Widhayaka
//L0122012
//RESPONSI PSDA 2023

#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>

using namespace std;

struct Division 
{
    string divisionName;
    string headofDivision;
    string phone;
};

struct Applicant 
{
    string name;
    int age;
    string position;
    string qualification;
    string certificate;
};

struct DisjointSet 
{
    map<string, string> induk;
    map<string, int> urutan;

    void makeSet(const string& element) 
    {
        induk[element] = element;
        urutan[element] = 0;
    }

    string find(const string& element) 
    {
        if (induk[element] != element)
            induk[element] = find(induk[element]);
        return induk[element];
    }

    void unionSets(const string& x, const string& y) 
    {
        string akarX = find(x);
        string akarY = find(y);

        if (urutan[akarX] < urutan[akarY])
            induk[akarX] = akarY;
        else if (urutan[akarX] > urutan[akarY])
            induk[akarY] = akarX;
        else {
            induk[akarY] = akarX;
            urutan[akarX]++;
        }
    }
};

int main() 
{
    string applicantName;
    map<string, Division> dataDivision;

    Division divisi;

    divisi.divisionName = "Penjualan/Distribusi";
    divisi.headofDivision = "Bobby Hardian";
    divisi.phone = "62823415243";
    dataDivision["1"] = divisi;

    divisi.divisionName = "Engineering";
    divisi.headofDivision = "Ali Mulyono";
    divisi.phone = "62874829137";
    dataDivision["2"] = divisi;

    divisi.divisionName = "Marketing/Sales";
    divisi.headofDivision = "Edy Purwanto";
    divisi.phone = "62836774284";
    dataDivision["3"] = divisi;

    divisi.divisionName = "Informasi dan Teknologi";
    divisi.headofDivision = "Asep Kusnadi";
    divisi.phone = "62884729337";
    dataDivision["4"] = divisi;

    divisi.divisionName = "Keuangan/Akuntansi";
    divisi.headofDivision = "Ida Darningsih";
    divisi.phone = "62843493949";
    dataDivision["5"] = divisi;

    list<Applicant> applicantList;
    map<string, Applicant> applicantMap;
    queue<string> applicantQueue;
    set<string> certificateSet;

    DisjointSet disjointSet;

    for (const auto& division : dataDivision)
        disjointSet.makeSet(division.first);

    int pilih;
    bool exit = false;

    while (!exit) 
    {
        cout << " " << endl;
        cout << "========================================================================================" << endl;
        cout << "                           Program Pelamar Pekerjaan Buzz Corp                          " << endl;
        cout << "========================================================================================" << endl;
        cout << "[1] Tambah Antrian Pelamar                                                              " << endl;
        cout << "[2] Panggil Antrian Pelamar                                                             " << endl;
        cout << "[3] Input Data Pelamar                                                                  " << endl;
        cout << "[4] Tampilkan Data Pelamar                                                              " << endl;
        cout << "[5] Cari Data Pelamar                                                                   " << endl;
        cout << "[6] Hapus Antrian Pelamar                                                               " << endl;
        cout << "[7] Daftar Sertifikat Pelamar                                                           " << endl;
        cout << "[8] Informasi Kepala Divisi                                                             " << endl;
        cout << "[0] Keluar                                                                              " << endl;
        cout << "========================================================================================" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilih;

        switch (pilih) 
        {
            case 1: 
            {
                //Menambah Antrian
                string applicantName;
                cout << " " << endl;
                cout << "Masukkan Nama Pelamar: ";
                cin >> applicantName;
                applicantQueue.push(applicantName);

                break;
            }
            case 2: 
            {
                //Memanggil Antrian
                if (!applicantQueue.empty()) 
                {
                    cout << " " << endl;
                    cout << "Pelamar atas nama " << applicantQueue.front() << "," << endl;
                    cout << "Silahkan masuk ke ruangan HRD!" << endl;
                    applicantQueue.pop();
                } 
                else 
                {
                    cout << "Antrian Kosong!" << endl;
                }
                break;
            }
            case 3: 
            {
                //Input Data Pelamar
                Applicant pelamar;
                cout << " " << endl;
                cout << "Nama Pelamar: ";
                cin >> pelamar.name;
                cout << "Usia Pelamar: ";
                cin >> pelamar.age;
                cout << "Posisi Dituju Pelamar: ";
                cin >> pelamar.position;
                cout << "Kualifikasi Pelamar: ";
                cin >> pelamar.qualification;
                cout << "Sertifikat Pelamar: ";
                cin >> pelamar.certificate;

                applicantList.push_back(pelamar);
                applicantMap[pelamar.name] = pelamar;
                certificateSet.insert(pelamar.certificate);
                disjointSet.makeSet(pelamar.name);
                cout << "Data Pelamar Ditambahkan!" << endl;
                
                break;
            }
            case 4: 
            {
                //Tampilkan Data Pelamar
                if (!applicantList.empty()) 
                {
                    for (const auto& pelamar : applicantList) 
                    {
                        cout << "--------------------------------------------" << endl;
                        cout << "Nama Pelamar            : " << pelamar.name << endl;
                        cout << "Usia Pelamar            : " << pelamar.age << endl;
                        cout << "Posisi Dituju Pelamar   : " << pelamar.position << endl;
                        cout << "Kualifikasi Pelamar     : " << pelamar.qualification << endl;
                        cout << "Sertifikat Pelamar      : " << pelamar.certificate << endl;
                        cout << "--------------------------------------------" << endl;
                    }
                } 
                else 
                {
                    cout << "Tidak ada data pelamar!" << endl;
                }
                break;
            }
            case 5: 
            {
                //Mencari Data Pelamar
                string applicantName;
                cout << "Masukkan Nama Pelamar yang Dicari: ";
                cin >> applicantName;
                if (applicantMap.count(applicantName) > 0) 
                {
                    const Applicant& pelamar = applicantMap[applicantName];
                    cout << "Data Pelamar Ditemukan" << endl;
                    cout << "--------------------------------------------" << endl;
                    cout << "Nama Pelamar              : " << pelamar.name << endl;
                    cout << "Usia Pelamar              : " << pelamar.age << endl;
                    cout << "Posisi Dituju Pelamar     : " << pelamar.position << endl;
                    cout << "Kualifikasi Pelamar       : " << pelamar.qualification << endl;
                    cout << "Sertifikat Pelamar        : " << pelamar.certificate << endl;
                    cout << "--------------------------------------------" << endl;
                } 
                else 
                {
                    cout << "Data pelamar tidak ada!" << endl;
                }
                break;
            }
            case 6: 
            {
                //Hapus Semua Daftar Antrian
                while (!applicantQueue.empty()) 
                {
                    applicantQueue.pop();
                }
                cout << "Semua daftar antrian pelamar telah dihapus!" << endl;
                break;
            }
            case 7: 
            {
                //Daftar Sertifikat Pelamar
                cout << " " << endl;
                cout << "Sertifikat dari Berbagai Pelamar:" << endl;
                if (certificateSet.empty()) 
                {
                    cout << "Belum ada sertifikat yang didaftarkan!" << endl;
                } 
                else 
                {
                    for (const auto& sertificate : certificateSet) 
                    {
                        cout << sertificate << endl;
                    }
                }
                break;
            }
            case 8: 
            {
                //Informasi divisi perusahaan Buzz Corp
                cout << " " << endl;
                cout << "--------------------------------------------" << endl;
                cout << "   Informasi Divisi Perusahaan Buzz Corp    " << endl;
                cout << "--------------------------------------------" << endl;
                cout << "[1] Penjualan/Distribusi" << endl;
                cout << "[2] Engineering" << endl;
                cout << "[3] Marketing/Sales" << endl;
                cout << "[4] Informasi dan Teknologi" << endl;
                cout << "[5] Keuangan/Akuntansi" << endl;
                cout << "Pilihan Anda (1-5) : ";
                cin >> applicantName;
                if (dataDivision.count(applicantName) == 1) 
                {
                    Division divisi = dataDivision[applicantName];

                    cout << "Divisi             : " << divisi.divisionName << endl;
                    cout << "Kepala Divisi      : " << divisi.headofDivision << endl;
                    cout << "Nomor Telepon      : " << divisi.phone << endl;

                    //Menggabungkan divisi yang dipilih dengan semua pelamar dalam divisi tersebut
                    for (const auto& applicant : applicantMap) 
                    {
                        if (applicant.second.position == divisi.divisionName)
                            disjointSet.unionSets(applicant.second.name, applicantName);
                    }

                    //Menampilkan pelamar yang tergabung dalam divisi yang sama
                    cout << " " << endl;
                    cout << "Pelamar dalam Divisi yang Sama:" << endl;
                    for (const auto& applicant : applicantMap) 
                    {
                        if (disjointSet.find(applicant.second.name) == disjointSet.find(applicantName)) 
                        {
                            cout << "--------------------------------------------" << endl;
                            cout << "Nama Pelamar            : " << applicant.second.name << endl;
                            cout << "Usia Pelamar            : " << applicant.second.age << endl;
                            cout << "Posisi Dituju Pelamar   : " << applicant.second.position << endl;
                            cout << "Kualifikasi Pelamar     : " << applicant.second.qualification << endl;
                            cout << "Sertifikat Pelamar      : " << applicant.second.certificate << endl;
                            cout << "--------------------------------------------" << endl;
                        }
                        else 
                        {
                            cout << "Tidak ada pelamar di Divisi ini" << endl;
                        }
                    }

                    } 
                    else 
                    {
                    cout << "Divisi tidak ada!" << endl;
                    }
                break;
            }
            case 0: 
            {
                //Keluar Program
                cout << "Terimakasih sudah menggunakan program kami!" << endl;
                exit = true;
                break;
            }
            default:
                cout << "Pilihan salah!" << endl;
                break;
        }
    }
    return 0;
}

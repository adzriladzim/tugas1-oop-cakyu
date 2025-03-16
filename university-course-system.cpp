#include <iostream>
#include <vector>
using namespace std;

class Student
{
private:
    string nama;
    int studentID;

public:
    Student(string nama, int studentID)
    {
        this->nama = nama;
        this->studentID = studentID;
    }

    string getNama()
    {
        return nama;
    }
    int getID()
    {
        return studentID;
    }
};

class Course
{
private:
    string namaKursus;
    int batasMaksimum;
    vector<Student> daftarMahasiswa;

public:
    Course(string namaKursus, int batas)
    {
        this->namaKursus = namaKursus;
        this->batasMaksimum = batas;
    }

    bool enroll(Student mahasiswa)
    {
        if (daftarMahasiswa.size() < batasMaksimum)
        {
            daftarMahasiswa.push_back(mahasiswa);
            cout << mahasiswa.getNama() << " berhasil mendaftar di " << namaKursus << endl;
            return true;
        }
        cout << "Pendaftaran gagal: Kursus " << namaKursus << " sudah penuh!" << endl;
        cout << endl;
        return false;
    }

    bool drop(Student mahasiswa)
    {
        for (auto it = daftarMahasiswa.begin(); it != daftarMahasiswa.end(); ++it)
        {
            if (it->getID() == mahasiswa.getID())
            {
                daftarMahasiswa.erase(it);
                cout << mahasiswa.getNama() << " telah keluar dari " << namaKursus << endl;
                cout << endl;
                return true;
            }
        }
        cout << "Penghapusan gagal: " << mahasiswa.getNama() << " tidak terdaftar di " << namaKursus << endl;
        return false;
    }

    void getEnrolledStudents()
    {
        cout << "Mahasiswa terdaftar di " << namaKursus << ":" << endl;
        for (auto &mhs : daftarMahasiswa)
        {
            cout << "- " << mhs.getNama() << endl;
        }
    }
};

int main()
{
    Course OOP("Object Oriented Programming", 2);

    Student zilan("Zilan", 101);
    Student yaasiin("Yaasiin", 102);
    Student aziz("Aziz", 103);

    OOP.enroll(zilan);
    OOP.enroll(yaasiin);
    OOP.enroll(aziz); // Gagal karena kursus penuh

    OOP.getEnrolledStudents();

    OOP.drop(zilan);
    OOP.getEnrolledStudents();

    return 0;
}

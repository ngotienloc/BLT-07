#ifndef MEDICINE_H
#define MEDICINE_H
#include <iostream>
#include <string>
#define MAX_MEDICINE 10
using namespace std; 
struct Time {
    int ngay;
    int thang;
    int nam;
};

struct Medicine {
    int MaThuoc;
    string TenThuoc;
    int DonGia;
    Time NSX;
    Time HSD;
};

struct Prescription{
	int MaToa;
	Time NgayKeToa;
	Medicine Medicines;
}; 


extern Medicine Medicines[MAX_MEDICINE]; // Khai bao mang Medicines
void DisplayMedicines();
void Display1Medicine();
void UpdateMedicine();
void FindMedicine();

#endif // MEDICINE_H



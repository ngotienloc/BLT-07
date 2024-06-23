#ifndef PATIENTSLIST_H
#define PATIENTSLIST_H
#include <string>
using namespace std; 
struct Patient { 
	int id; 
	string name; 
	int age; 
	string address;
	bool status; 
	Patient* next;  
};
typedef Patient* PatientsList; 
// Khoi tao danh sach benh nhan rong: 
void InitializeP(PatientsList &B);
// Ham them benh nhan theo kieu stack: 
void InsertPatient(PatientsList & B);
// Ham hien thi toan bo benh nhan
void DisplayPatients(PatientsList B);
// Ham tim kiem mot benh nhan theo id
Patient* SearchPatient(PatientsList B,int id);
// Ham hien thi benh nhan theo ID
void Display1Patient(PatientsList B);
// Ham kiem tra xem con benh nhan nao chua kham hay khong
bool CheckUnexaminedPatients(PatientsList B);
// Ham kiem tra trang thai cua mot benh nhan theo id
bool CheckUnexamined1Patients(PatientsList B);
// Ham sua du lieu cua mot benh nhan
void UpdatePatient(PatientsList &B);
// Ham chen mot benh nhan vao sau mot benh nhan co ID cho truoc
void InsertPatientAfterID(PatientsList & B);
// Ham xoa mot benh nhan co ID
void DeletePatient(PatientsList &B);
// Ham xem hoa don cua mot benh nhan
	
#endif // PATIENTSLIST_H

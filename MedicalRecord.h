#ifndef MEDICALRECORD_H
#define MEDICALRECORD_H
#include<iostream>
#include "Patient.h"
#include "Appointment.h"
#include "Medicine.h"
#include "Dentist.h"
using namespace std;

struct MedicalRecord {
    int id;
    Medicine Me[10];
    Appointment* A;
    Date RecordDate;
    time RecordTime;
    string diagnosis;
    string treatment;
    MedicalRecord* next;
}; 
typedef MedicalRecord* ListMedicalRecords;
//Xep don kham theo danh sach benh nhan: 
void InitalizeM(ListMedicalRecords &M);
void InsertMedicalRecord(ListMedicalRecords& M,ListAppointments A);
void UpdateMedicalRecord(ListMedicalRecords &M,PatientsList& P);
void DisplayMedicalRecord(ListMedicalRecords M);
#endif

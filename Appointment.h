#ifndef APPOINTMENT_H
#define APPOINTMENT_H
#include <iostream>
#include <string>
#include "Patient.h"
#include "Dentist.h"
using namespace std;
struct Date {
	int day;
	int month;
	int year; 
};
struct time{
	int hour; 
	int minute; 
	int second; 
};
struct Appointment {
    int id;
    Date date;
    time time;
    Patient* P; //Lien ket den benh nhan lich hen
    Dentist* D; //Lien ket nha sy voi lich hen
    Appointment* next;
};
typedef Appointment* ListAppointments;
// Khoi tao mot danh sach lich hen: 
void InitalizeA(ListAppointments  &A); 
// Them lich hen vao danh sach:
void InsertAppointment(ListAppointments &A,PatientsList O,ListDentist D);
//Hien thi danh sach lich hen: 
void DisplayListAppointment(ListAppointments A);
//Xoa lich hen theo id benh nhan: 
void DeleteAppointment(ListAppointments &A,PatientsList P);
//Hien thi lich hen cua benh nhan co id:
void DisplayAppointmentPatient(ListAppointments A);
//Hien thi toan bo lich hen cua 1 nha sy:
void DisplayAppointmentDentist(ListAppointments A);
//Sua thong tin lich hen:
void UpdateAppointment(ListAppointments A);
#endif

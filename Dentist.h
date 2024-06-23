#ifndef DENTIST_H
#define DENTIST_H

#include <string>
#include "Patient.h"

using namespace std;

struct Dentist {
    int id;
    string name;
    string title;
    int age;
    bool status;

    PatientsList P;
    Dentist* next;
};

typedef Dentist* ListDentist;

void InitializeD(ListDentist &D);
void InsertDentistBegin(ListDentist &D, PatientsList O);
Dentist* SearchDentistID(ListDentist D, int id);
void DeleteDentist(ListDentist &D);
void DisplayDentists(ListDentist D);
void AddPatientToDentist(ListDentist D,  PatientsList O);
void DisplayDentistInfo(ListDentist D);
void EditDentistInfo(ListDentist &D);
void SortDentistsByID(ListDentist &D);

#endif // DENTIST_H

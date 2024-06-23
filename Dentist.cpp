#include <iostream>
#include <string>
#include "Dentist.h"
using namespace std;
void InitializeD(ListDentist &D){
	D = NULL; 
}
void InsertDentistBegin(ListDentist &D, PatientsList O) {
    int id, age;
    string name, title;
    Dentist* Q = new Dentist;

    cout << "Id Nha Sy: "; cin >> id;
    cout << "Ten Nha Sy: "; cin.ignore(); getline(cin, name);
    cout << "Tuoi: "; cin >> age;
    cout << "Chuc Danh: "; cin.ignore(); getline(cin, title);

    Q->id = id;
    Q->name = name;
    Q->title = title;
    Q->age = age;
    Q->P = NULL; 

    Q->next = D;
    D = Q;
    cout<<"da them nha sy!";
}
void AddPatientToDentist(ListDentist D,  PatientsList O) {
	int dentistID;
	cout<<"nhap id nha sy: ";
	cin>>dentistID;
    
    Dentist* dentist = SearchDentistID(D, dentistID);
    if (dentist == NULL) {
        cout << "Khong tim thay nha sy co id " << dentistID << std::endl;
        return;
    }

  
    int patientID;
  cout << "Nhap ID cua benh nhan can them: ";
    cin >> patientID;


    Patient* patient = SearchPatient(O, patientID);
    if (patient == NULL) {
        cout << "Khong tim thay benh nhan co id " << patientID << std::endl;
        return;
    }


    patient->next = dentist->P;
    dentist->P = patient;

    cout << "Da them benh nhan vao danh sach cua nha sy co id " << dentistID << std::endl;
}
Dentist* SearchDentistID(ListDentist D, int id) {
    Dentist* current = D;
    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL; 
}

void DeleteDentist(ListDentist &D) {
	int id;
	cout<<"nhap vao id cua nha sy can xoa: ";
    cin>>id;
    Dentist *current = D;
    Dentist *prev = NULL;


    while (current != NULL && current->id != id) {
        prev = current;
        current = current->next;
    }


    if (current != NULL) {

        if (prev == NULL) {
            D = current->next;
        } else {
            prev->next = current->next;
        }
        delete current;
        cout << "Da xoa nha sy co id " << id << endl;
    } else {
        cout << "Khong tim thay nha sy co id " << id << endl;
    }
}

void DisplayDentists(ListDentist D) {
    Dentist* temp = D;


    cout << "\nID    | Name                 | Title                | Age  | Patients   \n";
    cout << "------+----------------------+----------------------+------+---------------\n";


    while (temp != NULL) {

        cout << temp->id << "   | " << temp->name;
        for (int i = 0; i < 20 - temp->name.length(); ++i) cout << " ";
        cout << " | " << temp->title;
        for (int i = 0; i < 20 - temp->title.length(); ++i) cout << " "; 
        cout << " | " << temp->age << "  | ";
        Patient* patient = temp->P;
        while (patient != NULL) {
            cout << patient->id << " ";
            patient = patient->next;
        }
        
        temp = temp->next;
        cout <<"\n";
    }

    cout << "------+----------------------+---------------------+-----+------------\n";
}


void DisplayDentistInfo(ListDentist D) {
    int id;
    cout << "Nhap id nha sy: ";
    cin >> id;

    Dentist* dentist = SearchDentistID(D, id);
    if (dentist != NULL) {
  
        cout << "\nID    | Name                 | Title               | Age | Patients\n";
        cout << "------+----------------------+---------------------+-----+---------\n";
        cout << dentist->id << "   | " << dentist->name;
        for (int i = 0; i < 20 - dentist->name.length(); ++i) cout << " "; 
        cout << " | " << dentist->title;
        for (int i = 0; i < 20 - dentist->title.length(); ++i) cout << " "; 
        cout << " | " << dentist->age << "  | ";

     
        Patient* patient = dentist->P;
        while (patient != NULL) {
            cout << patient->id << " ";
            patient = patient->next;
        }
        cout << "\n";
        cout << "------+----------------------+---------------------+-----+---------\n";
    } else {
        cout << "Khong tim thay nha sy co id " << id << endl;
    }
}
// sua thong tin nha sy
void EditDentistInfo(ListDentist &D) {
	int id;
    cout << "Nhap id nha sy: ";
    cin >> id;
    Dentist* dentist = SearchDentistID(D, id);
    if (dentist != NULL) {
        cout << "Nhap thong tin muon sua cho nha sy co id " << id << ":" << endl;
        cout << "1. Ten nha sy: " << dentist->name << endl;
        cout << "2. Tuoi nha sy: " << dentist->age << endl;
        cout << "3. Chuc danh: " << dentist->title << endl;
        cout << "Chon muc muon sua (1-3): ";
        
        int choice;
        cin >> choice;
        cin.ignore(); // Xóa b? d?m nh?p sau khi nh?p s?
        
        switch (choice) {
            case 1:
                cout << "Ten moi: ";
                getline(cin, dentist->name);
                break;
            case 2:
                cout << "Tuoi moi: ";
                cin >> dentist->age;
                break;
            case 3:
                cout << "Chuc danh moi: ";
                cin.ignore(); // Xóa b? d?m nh?p sau khi nh?p s?
                getline(cin, dentist->title);
                break;
            default:
                cout << "Lua chon khong hop le." << endl;
                break;
        }
        
        cout << "Thong tin nha sy da duoc cap nhat." << endl;
    } else {
        cout << "Khong tim thay nha sy co id " << id << endl;
    }
}
//Sap xep nha sy
void SortDentistsByID(ListDentist &D) {
    Dentist *current, *nextNode;
    int tempId;
    string tempName, tempTitle;
    int tempAge;
    PatientsList tempPatients;

    if (D == NULL) return; // Danh sách r?ng

    current = D;
    while (current != NULL) {
        nextNode = current->next;
        while (nextNode != NULL) {
            if (current->id > nextNode->id) {
                
                tempId = current->id;
                current->id = nextNode->id;
                nextNode->id = tempId;

                tempName = current->name;
                current->name = nextNode->name;
                nextNode->name = tempName;

                tempTitle = current->title;
                current->title = nextNode->title;
                nextNode->title = tempTitle;

                tempAge = current->age;
                current->age = nextNode->age;
                nextNode->age = tempAge;

                tempPatients = current->P;
                current->P = nextNode->P;
                nextNode->P = tempPatients;
            }
            nextNode = nextNode->next;
        }
        current = current->next;
    }
    cout<<"da sap xep xong!";
}

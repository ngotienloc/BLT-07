#include "Patient.h"
#include <string>
#include <iostream>
using namespace std; 
// Khoi tao danh sach benh nhan rong: 
void InitializeP(PatientsList &B){
	B = NULL; 
}
// Ham them benh nhan theo kieu queue: 
void InsertPatient(PatientsList & B){
	PatientsList P  = new Patient;
	cout << "ID: "; cin >> P->id;
	cout << "Ten: "; cin.ignore(); getline(cin,P->name);
	cout << "Tuoi: "; cin >> P->age;
	cout << "Dia chi: "; cin.ignore(); getline(cin,P->address); 
	P->status = 0;
	if(B==NULL){
		P->next = NULL; 
		B = P;
	}
	else{
		P->next = B; 
		B = P;
	}
	
}
//Ham tim kiem benh nhan co id
Patient* SearchPatient(PatientsList B, int id){
    Patient* temp = B; 
    while(temp != NULL){
        if(temp->id == id)
            return temp; 
        temp = temp->next;
    }
    return NULL; 
}

//Hien thi du lieu 1 benh nhan: 
void Display1Patient(PatientsList B) {
    int id; 
    cout <<"Id benh nhan: "; 
    cin >> id; 
    Patient* P = SearchPatient(B,id);
	// In tiêu de
    cout << "\n+----------------------+------------------+\n";
    cout << "| Thong tin benh nhan |                  |\n";
    cout << "+----------------------+------------------+\n";
    
    // In du lieu benh nhan
    cout << "| 1.ID:     " << P->id << "\t\t\t|\n";
    cout << "| 2.Ten:    " << P->name << "\t\t|\n";
    cout << "| 3.Tuoi:   " << P->age << "\t\t\t|\n";
    cout << "| 4.Dia chi: " << P->address << "\t|\n";
    cout << "| 5.Trang thai: " <<( P->status ? "Da kham" : "Chua kham") << "\t|\n";

    // In chan bang
    cout << "+----------------------+------------------+\n";
}

// Ham hien thi toan bo benh nhan
void DisplayPatients(PatientsList B) {
    Patient* temp = B;
    
    // Tieu de bang
    cout << "\nID    | Name                 | Age | Address           | Status     \n";
    cout << "------+----------------------+-----+-------------------+------------\n";

    // Thong tin benh nhan duoi dang bang 
    while (temp != NULL) {
        // In thong tin benh nhan duoi dinh dang phu hop 
        cout << temp->id << "   | " << temp->name;
        for (int i = 0; i < 20 - temp->name.length(); ++i) cout << " "; //Dieu chinh trung cot ten
        cout << " | " << temp->age << "  | " << temp->address;
        for (int i = 0; i < 16 - temp->address.length(); ++i) cout << " "; // Dieu chinh trung cot dia chi
        cout << "  | " << (temp->status ? "Da kham" : "Chua kham") << "\n";
        temp = temp->next;
    }

    // In chan bang 
    cout << "------+----------------------+-----+-------------------+------------\n";
}
//Ham kiem tra trang thai cua mot benh nhan theo id
bool CheckUnexamined1Patients(PatientsList B){
	int id; 
	cout << "Nhap id: ";
	cin >> id ; 
	Patient* P = SearchPatient(B,id); 
	return P->status; 
}
// Ham kiem tra xem con benh nhan chua kham hay khong
bool CheckUnexaminedPatients(PatientsList B){
    Patient* temp = B;
    while (temp != NULL) {
        if (!temp->status) {
            return false;
        }
        temp = temp->next;
    }
    return true;
}

// Ham sua du lieu cua mot benh nhan
void UpdatePatient(PatientsList &B){
	int id,a; 
	cout << "Nhap ID: ";
	cin >> id ; 
	Patient* P = SearchPatient(B,id);
	if(P==NULL)
		cout << "Khong co thong tin benh nhan! ";
	else{
	Display1Patient(P);
	cout << "\nNhap dong can chinh sua: ";
	cin >> a; 
		switch(a){
			case 1: 
				cout <<"ID: ";
				cin >> P->id; 
				cout << "Cap nhat thanh cong!";
				break;
			case 2:
				cout << "Name: ";
				cin.ignore();
				getline(cin,P->name);
				cout << "Cap nhat thanh cong!";
				break;
			case 3:
				cout << "Age: ";
				cin >> P->age;
				cout << "Cap nhat thanh cong!";
				break;
			case 4:
				cout << "Address: "; 
				cin.ignore(); 
				getline(cin,P->address); 
				cout << "Cap nhat thanh cong!";
				break;
			case 5: 
				cout << "Status(Da Kham:1-Chua kham:0): "; 
				cin >> P->status;
				cout << "Cap nhat thanh cong!";
				break;
			default:
				cout <<"Khong hop le. Thu lai! "; 
		}
	}
}
// Ham chen mot benh nhan vao sau mot benh nhan co ID cho truoc
void InsertPatientAfterID(PatientsList & B){
	int id;
	PatientsList P  = new Patient;
	cout << "Nhap thong tin benh nhan moi:\n "; 
	cout << "ID: "; cin >> P->id;
	cout << "Ten: "; cin.ignore(); getline(cin,P->name);
	cout << "Tuoi: "; cin >> P->age;
	cout << "Dia chi: "; cin.ignore(); getline(cin,P->address); 
	P->status = 0;
	cout << "Nhap ID benh nhan cho truoc:\n";
	cout << "ID: "; cin >> id; 
	Patient *Q = SearchPatient(B,id); 
	if(B==NULL){
		P->next = NULL;
		B = P; 
		
	}
	else{
		if(Q==NULL){
			cout << "Khong co benh nhan nao co id "<<id<<"trong danh sach!";
			return; 
		}
		P->next = Q->next;
		Q->next = P; 
		cout << "da them benh nhan thanh cong!";
	}
}
// Ham xoa mot benh nhan co ID
void DeletePatient(PatientsList &B){
    int id; 
    cout << "ID benh nhan can xoa: ";
    cin >> id; 
    if(B == NULL){
        cout << "Danh sach rong!";
        return; 
    }
    Patient* P = SearchPatient(B, id); 
     if(P == NULL){
        cout << "Khong tim thay benh nhan voi ID " << id << endl;
        return;
    }
    if(B == P){    // Neu benh nhan la dau danh sach
        B = P->next; 
        delete P;
        cout << "Da xoa thanh cong benh nhan!" << endl;
    }
    else{
        Patient* Q = B; 
        while(Q->next != P && Q->next != NULL)   
            Q = Q->next;    
        
        if(Q->next == P){
            Q->next = P->next; 
            delete P;
            cout << "Da xoa thanh cong benh nhan!" << endl;
        } else {
            cout << "Khong tim thay benh nhan voi ID " << id << endl;
        }
    }
}


// Ham xem don kham cua mot benh nhan




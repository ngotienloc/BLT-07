#include "Appointment.h"
using namespace std; 
 // Khoi tao mot danh sach lich hen: 
void InitalizeA(ListAppointments &A){
	A = NULL; 
}
// So sanh thoi gian:
// Hàm so sánh th?i gian gi?a hai l?ch h?n
// Tr? v?:
// -1 n?u th?i gian c?a A s?m hon B
//  0 n?u th?i gian c?a A b?ng B
//  1 n?u th?i gian c?a A sau B
int CompareDateTime(const Date& dateA, const time& timeA, const Date& dateB, const time& timeB) {
    if (dateA.year < dateB.year) return -1;
    if (dateA.year > dateB.year) return 1;
    
    if (dateA.month < dateB.month) return -1;
    if (dateA.month > dateB.month) return 1;
    
    if (dateA.day < dateB.day) return -1;
    if (dateA.day > dateB.day) return 1;
    
    if (timeA.hour < timeB.hour) return -1;
    if (timeA.hour > timeB.hour) return 1;
    
    if (timeA.minute < timeB.minute) return -1;
    if (timeA.minute > timeB.minute) return 1;
    
    if (timeA.second < timeB.second) return -1;
    if (timeA.second > timeB.second) return 1;
    
    return 0; // Các th?i di?m b?ng nhau
}

//Them lich hen vao danh sach:
void InsertAppointment(ListAppointments &H, PatientsList O, ListDentist D) {
    Appointment* A = new Appointment;
    int idp, idd;
    
    cout << "ID: ";
    cin >> A->id;
    
    cout << "Date: ";
    cin >>A->date.day >>A->date.month >> A->date.year;
    
    cout << "Time: ";
    cin >> A->time.hour >> A->time.minute >> A->time.second;
    
    cout << "Id benh nhan: ";
    cin >> idp;
    
    cout << "Id nha sy: ";
    cin >> idd;
    
    Patient* P = SearchPatient(O, idp);
    Dentist* d = SearchDentistID(D, idd);
    
    if (P == NULL || d == NULL) {
        cout << " Thong tin nha sy hoac benh nhan khong dung! ";
        delete A;
        return;
    }
    
    A->P = P;
    A->D = d;
    
    // Tìm vi trí thich hop de chen lich hen A vào danh sach H
    Appointment* prev = NULL;
    Appointment* current = H;
    
    while (current != NULL && CompareDateTime(A->date, A->time, current->date, current->time) > 0) {
        prev = current;
        current = current->next;
    }
    
    if (prev == NULL) {
        // Chèn vào d?u danh sách H
        A->next = H;
        H = A;
    } else {
        // Chèn vào gi?a ho?c cu?i danh sách H
        prev->next = A;
        A->next = current;
    }
    cout<<"da them thanh cong!";
}
	void DisplayListAppointment(ListAppointments head) {
	    cout << "\nID    | Date        | Time     | Patient Name | Dentist Name \n";
	   	cout << "------+-------------+----------+--------------+--------------\n";
	
	    Appointment* temp = head;
	    while (temp != NULL) {
	        // In thông tin l?ch h?n du?i d?ng b?ng
	        cout << temp->id << "   | " << temp->date.day << "/" << temp->date.month << "/" << temp->date.year;
	        cout << " | " << temp->time.hour << ":" << temp->time.minute << ":" << temp->time.second;
	        cout << " | " << temp->P->name;
	        for (int i = 0; i < 14 - temp->P->name.length(); ++i) cout << " "; // Ði?u ch?nh can l? cho tên b?nh nhân
	        cout << " | " << temp->D->name << "\n";
	        temp = temp->next;
	    }
	
	    // In dòng cu?i cùng c?a b?ng
	    cout << "------+-------------+----------+--------------+--------------\n";
	}
//ham xoa lich hen voi benh nhan
void DeleteAppointment(ListAppointments &A, PatientsList P) {
    int id;
    cout << "ID lich hen voi benh nhan can xoa: ";
    cin >> id;

    Appointment* temp = A;
    Appointment* prev = NULL; 

    while (temp != NULL) { 
        if (temp->P->id == id) {
            break;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }

    if (temp == NULL) { 
        cout << "Khong tim thay lich hen voi id" << id << endl;
        return;
    }

    if (temp == A && A->next == NULL) { 
        A = NULL; 
    } else {
        if (temp == A) {
            A = A->next;
        } else {
            prev->next = temp->next; 
        }
        delete temp;
    }

    cout << "da xoa thanh cong lich hen" << endl;
}


//Hien thi lich hen cua benh nhan co id: 
void DisplayAppointmentPatient(ListAppointments A){
	int id;
	cout << "Id benh nhan ";
	cin >> id;
	Appointment* temp = new Appointment;
	temp = A;
	while(temp!=NULL){
		if(temp->P->id==id)
			break;
		else 
			temp = temp->next;
	}
	if(temp==NULL)
		cout << "Khong co benh nhan co id:"<<id; 
	else{ 
	    cout << "\nID    | Date        | Time     | Patient Name | Dentist Name \n";
	   	cout << "------+-------------+----------+--------------+--------------\n";
		cout << temp->id << "   | " << temp->date.day << "/" << temp->date.month << "/" << temp->date.year;
        cout << " | " << temp->time.hour << ":" << temp->time.minute << ":" << temp->time.second;
        cout << " | " << temp->P->name;
        for (int i = 0; i < 14 - temp->P->name.length(); ++i) cout << " "; // Ði?u ch?nh can l? cho tên b?nh nhân
        cout << " | " << temp->D->name << "\n";
        temp = temp->next;
        cout << "------+-------------+----------+--------------+--------------\n";
	}
}
//Hien thi lich hen cua nha sy co id: 
void DisplayAppointmentDentist(ListAppointments A){ 
	int id; 
	cout << "Id nha sy: ";
	cin >> id; 
	Appointment* temp = new Appointment;
	temp = A;
	int found = false; 
	cout << "\nLich hen cua nha sy co ID " << id << ":" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "| Ten Benh Nhan           | Ngay Hen   | Gio Hen |" << endl;
    cout << "------------------------------------------------------------" << endl;

 	while (temp != NULL) {
        if (temp->D->id == id) {
            found = true;
            // In ten benh nhan
            cout << "| " << temp->P->name;
            // Dam bao ten benh nhan du 32 ky tu 
            for (int i = temp->P->name.length(); i < 23; ++i) {
                cout << " ";
            }
            // In ngay hen
            cout << "| " << (temp->date.day < 10 ? "0" : "") << temp->date.day << "/"
                 << (temp->date.month < 10 ? "0" : "") << temp->date.month << "/"
                 << temp->date.year << " ";
            // In gio hen
            cout << "| " << (temp->time.hour < 10 ? "0" : "") << temp->time.hour << ":"
                 << (temp->time.minute < 10 ? "0" : "") << temp->time.minute << ":"
                 << (temp->time.second < 10 ? "0" : "") << temp->time.second << " |" << endl;
        }
        temp = temp->next;
    }
    cout << "------------------------------------------------------------" << endl;

    if (!found) {
        cout << "Khong co lich hen nao cho nha sy voi ID: " << id << endl;
    }
}
// sua doi lich hen
void UpdateAppointment(ListAppointments A) {
    int id;
    cout << "Nhap id Lich hen can chinh sua: ";
    cin >> id;

    Appointment* temp = A;
    Appointment* prev = NULL; 

   
    while (temp != NULL) { 
        if (temp->id == id) {
            break;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }

   
    if (temp == NULL) { 
        cout << "ID khong hop le hoac khong tim thay lich hen voi ID " << id << endl;
        return;
    }

   
    cout << "\nID    | Date        | Time     | Patient Name | Dentist Name \n";
    cout << "------+-------------+----------+--------------+--------------\n";
    cout << temp->id << "   | " << temp->date.day << "/" << temp->date.month << "/" << temp->date.year;
    cout << " | " << temp->time.hour << ":" << temp->time.minute << ":" << temp->time.second;
    cout << " | " << temp->P->name;
    for (int i = 0; i < 14 - temp->P->name.length(); ++i) cout << " "; // Ði?u ch?nh can l? cho tên b?nh nhân
    cout << " | " << temp->D->name << "\n";
    cout << "------------------------------------------------------------" << endl;

    int choice;
   
    cout << "\nChon thong tin can cap nhat:" << endl;
    cout << "1. Ngay hen (ngay/thang/nam)" << endl;
    cout << "2. Gio hen (gio/phut/giay)" << endl;
    cout << "3. Benh nhan (id)" << endl;
    cout << "4. Nha si (id)" << endl;
    cout << "Lua chon: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Nhap ngay hen moi (ngay/thang/nam): ";
            cin >> temp->date.day >> temp->date.month >> temp->date.year;
            cout << "Cap nhat thanh cong!" << endl;
            break;
        case 2:
            cout << "Nhap gio hen moi (gio/phut/giay): ";
            cin >> temp->time.hour >> temp->time.minute >> temp->time.second;
            cout << "Cap nhat thanh cong!" << endl;
            break;
        case 3:
            cout << "Nhap ten benh nhan moi: ";
            cin.ignore();
            getline(cin, temp->P->name);
            cout << "Cap nhat thanh cong!" << endl;
            break;
        case 4:
            cout << "Nhap ten nha si moi: ";
            cin.ignore();
            getline(cin, temp->D->name);
            cout << "Cap nhat thanh cong!" << endl;
            break;
        default:
            cout << "Lua chon khong hop le. Vui long thu lai!" << endl;
            break;
    }
}



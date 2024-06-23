#include <iostream>
#include <string>
#include <stdlib.h>
#include "MedicalRecord.h"
using namespace std;
int main() {
    int a;
    PatientsList P; 
    InitializeP(P);
    ListAppointments A;
    InitalizeA(A);
	ListDentist D; 
	InitializeD(D);
	ListMedicalRecords M; 
	InitalizeM(M);
    while (true) {
        MENU:
        system("cls");
        cout << "\n\t===================================\n";
        cout << "\t       QUAN LY PHONG KHAM          \n";
        cout << "\t===================================\n";
        cout << "\t| 1. Quan ly nha sy               |\n";
        cout << "\t| 2. Quan ly benh nhan            |\n";
        cout << "\t| 3. Quan ly lich hen             |\n";
        cout << "\t| 4. Quan ly danh sach don thuoc  |\n";
        cout << "\t| 5. Quan ly don kham             |\n";
        cout << "\t===================================\n";
        cout << "\n\tChon mot lua chon: ";		
        cin >> a;
        switch (a) {
            case 1: {
                int a1;
                while (true) {
                	system("cls");
                    cout << "\n\t----------------------------------------------\n";
				    cout << "\t              QUAN LY NHA SY                  \n";
				    cout << "\t----------------------------------------------\n";
				    cout << "\t| 1. Them nha sy                             |\n";
				    cout << "\t|--------------------------------------------|\n";
				    cout << "\t| 2. Xoa nha sy                              |\n";
				    cout << "\t|--------------------------------------------|\n";
				    cout << "\t| 3. Hien thi danh sach cac nha sy           |\n";
				    cout << "\t|--------------------------------------------|\n";
				    cout << "\t| 4. Them benh nhan cho mot nha sy           |\n";
				    cout << "\t|--------------------------------------------|\n";
				    cout << "\t| 5. Hien thi thong tin cua mot nha sy       |\n";
				    cout << "\t|--------------------------------------------|\n";
				    cout << "\t| 6. Sua thong tin nha sy                    |\n";
				    cout << "\t|--------------------------------------------|\n";
				    cout << "\t| 7. Sap xep nha sy theo thu tu tang dan id  |\n";
				    cout << "\t|--------------------------------------------|\n";
				    cout << "\t| 0. Tro lai menu chinh                      |\n";
				    cout << "\t----------------------------------------------\n";
				    cout << "\n\tChon mot lua chon: ";
                    cin >> a1;
                    switch (a1) {
                        case 1:
                        	InsertDentistBegin(D,P);
                        	break;
                        case 2:
                        	DeleteDentist(D);
                        	break;
                        case 3:
                        	DisplayDentists(D);
                        	break;
                        case 4:
                            AddPatientToDentist(D,P);
                        	break;
                        case 5:
                        	DisplayDentistInfo(D);
                        	break;
                        case 6:
                        	EditDentistInfo(D);
                        	break;
                        case 7:
                        	SortDentistsByID(D);
                        	DisplayDentists(D);
                        	break;
                        case 0:
                            goto MENU;
                        default:
                            cout << "Lua chon khong hop le. Vui long nhap lai!";
                            break;
                    }
                    cin.ignore();
       				getchar(); 
                }
            }
            break;
            case 2:
				int a2;
                while (true) {
                	system("cls");
                	cout << "\n\t--------------------------------------------------\n";
                    cout << "\n\t---          Quan ly benh nhan                 ---\n\n";
				    cout << "\t+--------------------------------------------------+\n";
				    cout << "\t| 1. Them benh nhan                                |\n";
				    cout << "\t|-------------------------------------------       |\n";
				    cout << "\t| 2. Xoa benh nhan                                 |\n";
				    cout << "\t|-------------------------------------------       |\n";
				    cout << "\t| 3. Hien thi danh sach cac benh nhan              |\n";
				    cout << "\t|-------------------------------------------       |\n";
				    cout << "\t| 4. Hien thi thong tin cua mot benh nhan          |\n";
				    cout << "\t|-------------------------------------------       |\n";
				    cout << "\t| 5. Kiem tra trang thai cua mot benh nhan theo id |\n";
				    cout << "\t|--------------------------------------------------|\n";
				    cout << "\t| 6. Sua thong tin benh nhan                       |\n";
				    cout << "\t|--------------------------------------------------|\n";
				    cout << "\t| 7. Kiem tra co benh nhan nao chua kham hay khong |\n";
				    cout << "\t|--------------------------------------------------|\n";
				    cout << "\t| 8. Chen mot benh nhan vao sau benh nhan co id    |\n";
				    cout << "\t|--------------------------------------------------|\n";
				    cout << "\t| 0. Tro lai Menu chinh                            |\n";
				    cout << "\t+--------------------------------------------------+\n";
 				    cout << "\n\tChon mot lua chon: ";
                    cin >> a2;
                    switch (a2) {
                        case 1:
                        	InsertPatient(P);
                        	break;
                        case 2:
                        	DeletePatient(P);
                        	break;
                        case 3:
                        	DisplayPatients(P); 
                        	break;
                        case 4:
                        	Display1Patient(P); 
                        	break;
                        case 5:
                        if (CheckUnexamined1Patients(P)) {
                          cout << "Da kham";
                        } else {
                          cout << "Chua kham";
                        }
                           break;
                        case 6:
                        	UpdatePatient(P); 
                        	break;
                        case 7:
                        	cout << ((CheckUnexaminedPatients(P)==1)?"Khong":"Co");
                        	break;
                        case 8:
                        	InsertPatientAfterID(P); 
                        	break; 
                        case 0:
                            goto MENU;
                        default:
                            cout << "Lua chon khong hop le. Vui long nhap lai!";
                            break;
    
                    }
                    cin.ignore();
       				getchar(); 
                }
				break; 
            case 3:
            	int a3;
                while (true) {
                	system("cls");
                	cout << "\n\t---------------------------------------------------\n";
                    cout << "\n\t---------- Quan ly danh sach lich hen -------------\n\n";
				    cout << "\t+---------------------------------------------------+\n";
				    cout << "\t| 1. Them lich hen vao danh sach                    |\n";
				    cout << "\t|---------------------------------------------------|\n";
				    cout << "\t| 2. Hien thi danh sach lich hen                    |\n";
				    cout << "\t|---------------------------------------------------|\n";
				    cout << "\t| 3. Xoa lich hen theo id benh nhan                 |\n";
				    cout << "\t|---------------------------------------------------|\n";
				    cout << "\t| 4. Hien thi lich hen cua benh nhan co id          |\n";
				    cout << "\t|---------------------------------------------------|\n";
				    cout << "\t| 5. Hien thi toan bo lich hen cua mot nha sy co id |\n";
				    cout << "\t|---------------------------------------------------|\n";
				    cout << "\t| 6. Sua thong tin lich hen                         |\n";
				    cout << "\t|---------------------------------------------------|\n";
				    cout << "\t| 0. Tro lai menu chinh                             |\n";
				    cout << "\t+---------------------------------------------------+\n";
    				cout << "\n\tChon mot lua chon: ";
                    cin >> a3;
                    switch (a3) {
                        case 1:
                        	InsertAppointment(A,P,D);
                        	break;
                        case 2:
                        	DisplayListAppointment(A); 
                        	break;
                        case 3:
                        	DeleteAppointment(A,P);
                        	break;
                        case 4:
                        	DisplayAppointmentPatient(A);
                        	break;
                        case 5:
                        	DisplayAppointmentDentist(A);
                        	break;
                        case 6:
                        	UpdateAppointment(A); 
                        	break;
                        case 0:
                            goto MENU;
                        default:
                            cout << "Lua chon khong hop le. Vui long nhap lai!";
                            break;
                    
                    }
                    cin.ignore();
       				getchar(); 
                }
                break;
            case 4:
            int a4;
                while (true) {
                	system("cls");
                	cout << "\n\t---------------------------------------------------\n";
                    cout << "\n\t---------- Quan ly danh sach don thuoc -------------\n\n";
				    cout << "\t+---------------------------------------------------+\n";
				    cout << "\t| 1. Hien thi thong tin thuoc                       |\n";
				    cout << "\t|---------------------------------------------------|\n";
				    cout << "\t| 2. Sua thong tin mot loai thuoc                   |\n";
				    cout << "\t|---------------------------------------------------|\n";
				    cout << "\t| 3. Hien thi thong tin mot loai thuoc              |\n";
				    cout << "\t|---------------------------------------------------|\n";
				    cout << "\t| 0. Tro lai menu chinh                             |\n";
				    cout << "\t+---------------------------------------------------+\n";
    				cout << "\n\tChon mot lua chon: ";
                    cin >> a4;
                    switch (a4) {
                        case 1:
                        	DisplayMedicines();
                        	break;
                        case 2:
                        	UpdateMedicine();
                        	break;
                        case 3:
                        	FindMedicine();
                        	break;
                        case 0:
                            goto MENU;
                        default:
                            cout << "Lua chon khong hop le. Vui long nhap lai!";
                            break;
                    
                    }
                    cin.ignore();
       				getchar(); 
                }
                break;
            case 5:
            int a5;
                while (true) {
                	system("cls");
                	cout << "\n\t---------------------------------------------------\n";
                    cout << "\n\t---------- Quan ly danh sach ban don kham ---------\n\n";
				    cout << "\t+---------------------------------------------------+\n";
				    cout << "\t| 1. Hoan thien danh sach don kham                  |\n";
				    cout << "\t|---------------------------------------------------|\n";
				    cout << "\t| 2. Cap nhat danh sach don kham                    |\n";
				    cout << "\t|---------------------------------------------------|\n";
				    cout << "\t| 3. Hien thi                                       |\n";
				    cout << "\t|---------------------------------------------------|\n";
				    cout << "\t| 0. Tro lai menu chinh                             |\n";
				    cout << "\t+---------------------------------------------------+\n";
    				cout << "\n\tChon mot lua chon: ";
                    cin >> a5;
                    switch (a5) {
                        case 1:
                       		InsertMedicalRecord(M,A);
                        	break;
                        case 2:
                        	UpdateMedicalRecord(M,P);
                        	break;
                        case 3:
                        	DisplayMedicalRecord(M);
                        	break;	
                        case 0:
                            goto MENU;
                        default:
                            cout << "Lua chon khong hop le. Vui long nhap lai!";
                            break;
                    
                    }
                    cin.ignore();
       				getchar(); 
                }
                break;
        }
    cin.ignore();
    getchar(); 
	}
    return 0;
}


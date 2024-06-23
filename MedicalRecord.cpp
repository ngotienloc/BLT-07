#include "MedicalRecord.h"

void InitalizeM(ListMedicalRecords &M){
	M = NULL;
}
void InsertMedicalRecord(ListMedicalRecords& M, ListAppointments A) {
    int id, ida;
    // Input record id
    cout << "Nhap id ban ghi: ";
    cin >> id;
    // Input appointment id
    cout << "Nhap id lich hen: ";
    cin >> ida;

    // Create a new medical record
    MedicalRecord* newRecord = new MedicalRecord;
    newRecord->id = id;

    // Find the appointment with ida in list A
    ListAppointments temp = A;
    bool foundAppointment = false;
    while (temp != NULL) {
        if (temp->id == ida) {
            newRecord->A = temp;
            foundAppointment = true;
            break; // Exit loop since found matching appointment
        }
        temp = temp->next;
    }

    // Check and notify if no matching appointment is found
    if (!foundAppointment) {
        cout << "Khong tim thay cuoc hen voi id " << ida << endl;
        delete newRecord; // Delete the new medical record as it is not needed anymore
        return;
    }

    // Add the new medical record to the beginning of list M
    newRecord->next = M;
    M = newRecord;
}

void UpdateMedicalRecord(ListMedicalRecords &M, PatientsList &P) {
    int id;
    // Input record id
    cout << "Nhap Id Ban ghi: ";
    cin >> id;
    
    // Initialize temp to iterate through the list
    ListMedicalRecords temp ;
    temp = M; 
    
    // Search for the record with the given id
    while (temp != NULL) {
        if (temp->id == id)
            break;
        else
            temp = temp->next;
    }
    
    // If record with the given id is not found, print a message and return
    if (temp == NULL) {
        cout << "Khong co Ban ghi co id " << id << endl;
        return; 
    }
    
    // Print the details of the found medical record
    cout << "--------------------------------------------------------------" << endl;
    cout << "| Thong tin ban ghi y te                                      |" << endl;
    cout << "--------------------------------------------------------------" << endl;
    
    cout << "| Ngay lap: ";
    cout << (temp->RecordDate.day < 10 ? "0" : "") << temp->RecordDate.day << "/"
         << (temp->RecordDate.month < 10 ? "0" : "") << temp->RecordDate.month << "/"
         << temp->RecordDate.year << " ";
    cout << (temp->RecordTime.hour < 10 ? "0" : "") << temp->RecordTime.hour << ":"
         << (temp->RecordTime.minute < 10 ? "0" : "") << temp->RecordTime.minute << ":"
         << (temp->RecordTime.second < 10 ? "0" : "") << temp->RecordTime.second << " |" << endl;

    cout << "| Chan doan: " << temp->diagnosis << " |" << endl;
    cout << "| Lieu phap: " << temp->treatment << " |" << endl;
    
    cout << "| Danh sach thuoc: ";
    // Assuming temp->Me is an array of Medicines and the loop prints up to 10 medicines
   	for (int n = 0; n < 10; n++) {
    if (n > 0) {
        cout << ", "; 
    }
    cout << temp->Me[n].TenThuoc;
	}
	cout << " |" << endl;
    cout << "| Danh sach lich hen: ";
    Appointment* currentAppointment = temp->A;
    while (currentAppointment != NULL) {
        cout << (currentAppointment->date.day < 10 ? "0" : "") << currentAppointment->date.day << "/"
             << (currentAppointment->date.month < 10 ? "0" : "") << currentAppointment->date.month << "/"
             << currentAppointment->date.year << " ";
        cout << (currentAppointment->time.hour < 10 ? "0" : "") << currentAppointment->time.hour << ":"
             << (currentAppointment->time.minute < 10 ? "0" : "") << currentAppointment->time.minute << ":"
             << (currentAppointment->time.second < 10 ? "0" : "") << currentAppointment->time.second << " ";
        currentAppointment = currentAppointment->next;
    }
    cout << " |" << endl;
    
    cout << "--------------------------------------------------------------" << endl;

    int choice;
    // Allow the user to choose what information to update
    cout << "\nChon thong tin can cap nhat:" << endl;
    cout << "1. Ngay lap" << endl;
    cout << "2. Chuan doan benh" << endl;
    cout << "3. Lieu phap chua tri" << endl;
    cout << "4. Don thuoc" << endl;
    cout << "5. Trang thai benh nhan" << endl;
    cout << "Lua chon: ";
    cin >> choice;
    
    switch (choice) {
        case 1:
            cout << "Nhap ngay lap (ngay thang nam): ";
            cin >> temp->RecordDate.day >> temp->RecordDate.month >> temp->RecordDate.year;
            cout << "Nhap gio lap (gio phut giay): ";
            cin >> temp->RecordTime.hour >> temp->RecordTime.minute >> temp->RecordTime.second;
            break;
        case 2:
            cout << "Nhap chuan doan: ";
            cin.ignore(); // Clear the input buffer
            getline(cin, temp->diagnosis);
            break;
        case 3:
            cout << "Nhap lieu phap chua tri: ";
            cin.ignore(); // Clear the input buffer
            getline(cin, temp->treatment);
            break;
        case 4:
            int s;
            cout << "Nhap so luong thuoc can cap nhat: ";
            cin >> s;
            cout << "Nhap ma cac loai thuoc: ";
            int id;
            for (int i = 0; i < s; i++) {
                cout << "ID thuoc " << i + 1 << ": ";
                cin >> id;
                for (int n = 0; n < 10; n++) {
                    if (id == Medicines[n].MaThuoc) {
                        temp->Me[i] = Medicines[n];
                        break; // Exit loop if medicine is found
                    }
                }
            }
            break;
        case 5:
            // Cap nhat trang thai benh nhan
            PatientsList Q ;
            Q = P;
            while (Q != NULL) {
                if (Q->id == M->A->P->id) {
                    break;
                } else {
                    Q = Q->next;
                }
            }
            if (Q == NULL) {
                cout << "Khong tim thay benh nhan!";
                return; 
            }else{
            cout << "Cap nhat trang thai benh nhan: ";
            cin >> Q->status;
            cout << "Cap nhat trang thai benh nhan thanh cong";
        	}
            break;
        default:
            cout << "Lua chon khong hop le!" << endl;
            break;
    }
}
void DisplayMedicalRecord(ListMedicalRecords M) {
    // Check if the list M is empty
    if (M == NULL) {
        cout << "Danh sach ban ghi y te trong!" << endl;
        return;
    }
    
    ListMedicalRecords temp = M;
    int recordCount = 0;
    
    while (temp != NULL) {
        recordCount++;
        cout << "--------------------------------------------------------------" << endl;
        cout << "| Thong tin ban ghi y te #" << recordCount << "                                     |" << endl;
        cout << "--------------------------------------------------------------" << endl;
        
        cout << "| Ngay lap: ";
        cout << (temp->RecordDate.day < 10 ? "0" : "") << temp->RecordDate.day << "/"
             << (temp->RecordDate.month < 10 ? "0" : "") << temp->RecordDate.month << "/"
             << temp->RecordDate.year << " ";
        cout << (temp->RecordTime.hour < 10 ? "0" : "") << temp->RecordTime.hour << ":"
             << (temp->RecordTime.minute < 10 ? "0" : "") << temp->RecordTime.minute << ":"
             << (temp->RecordTime.second < 10 ? "0" : "") << temp->RecordTime.second << " |" << endl;

        cout << "| Chan doan: " << temp->diagnosis << " |" << endl;
        cout << "| Lieu phap: " << temp->treatment << " |" << endl;
        
        cout << "| Danh sach thuoc: ";
        for (int n = 0; n < 10; n++) {
            if (n > 0) {
                cout << ", "; 
            }
            cout << temp->Me[n].TenThuoc;
        }
        cout << " |" << endl;
        
        cout << "| Danh sach lich hen: ";
        Appointment* currentAppointment = temp->A;
        while (currentAppointment != NULL) {
            cout << (currentAppointment->date.day < 10 ? "0" : "") << currentAppointment->date.day << "/"
                 << (currentAppointment->date.month < 10 ? "0" : "") << currentAppointment->date.month << "/"
                 << currentAppointment->date.year << " ";
            cout << (currentAppointment->time.hour < 10 ? "0" : "") << currentAppointment->time.hour << ":"
                 << (currentAppointment->time.minute < 10 ? "0" : "") << currentAppointment->time.minute << ":"
                 << (currentAppointment->time.second < 10 ? "0" : "") << currentAppointment->time.second << " ";
            currentAppointment = currentAppointment->next;
        }
        cout << " |" << endl;
        
        cout << "--------------------------------------------------------------" << endl;

        // Move to the next medical record in the list
        temp = temp->next;
    }
}




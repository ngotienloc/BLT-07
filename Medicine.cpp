#include <iostream>
#include <string>
#include "Medicine.h"
#define MAX_MEDICINE 10
using namespace std; 

Medicine Medicines[MAX_MEDICINE] = {
    {1, "Thuoc A", 10000, {1, 1, 2023}, {1, 1, 2025}},
    {2, "Thuoc B", 20000, {2, 2, 2023}, {2, 2, 2025}},
    {3, "Thuoc C", 30000, {3, 3, 2023}, {3, 3, 2025}},
    {4, "Thuoc D", 40000, {4, 4, 2023}, {4, 4, 2025}},
    {5, "Thuoc E", 50000, {5, 5, 2023}, {5, 5, 2025}},
    {6, "Thuoc F", 60000, {6, 6, 2023}, {6, 6, 2025}},
    {7, "Thuoc G", 70000, {7, 7, 2023}, {7, 7, 2025}},
    {8, "Thuoc H", 80000, {8, 8, 2023}, {8, 8, 2025}},
    {9, "Thuoc I", 90000, {9, 9, 2023}, {9, 9, 2025}},
    {10, "Thuoc K", 100000, {10, 10, 2023}, {10, 10, 2025}}
};

// Ham in thong tin cua thuoc 
void DisplayMedicines() {
    for (int i = 0; i < 10; ++i) {
        cout << "Thong tin cho thuoc " << i + 1 << ":" << endl;
        cout << "Ma Thuoc: " << Medicines[i].MaThuoc << endl;
        cout << "Ten Thuoc: " << Medicines[i].TenThuoc << endl;
        cout << "Don Gia: " << Medicines[i].DonGia << endl;
        cout << "Ngay San Xuat: " << Medicines[i].NSX.ngay << "/" << Medicines[i].NSX.thang << "/" << Medicines[i].NSX.nam << endl;
        cout << "Han Su Dung: " << Medicines[i].HSD.ngay << "/" << Medicines[i].HSD.thang << "/" << Medicines[i].HSD.nam << endl;
        cout << endl;
    }
}
int BinarySearchMedicine(Medicine Medicines[], int MaThuoc) {
    int F = 0, L = 9;
    while (F <= L) {
        int m = (F + L) / 2;
        if (MaThuoc == Medicines[m].MaThuoc)
            return m;
        else if (MaThuoc < Medicines[m].MaThuoc)
            L = m - 1;
        else
            F = m + 1;
    }
    return -1; 
}
void UpdateMedicine() {
	int MaSoThuoc, luaChon;
    cout << "Nhap ma so thuoc can cap nhat: ";
    cin >> MaSoThuoc;
    //Tim kiem nhi phan
    int i = BinarySearchMedicine(Medicines,MaSoThuoc); 
    if(i==-1){
    	cout << "Khong tim thay thong tin thuoc! "<<endl; 
    	return; 
	}
	cout << "Ma thuoc: " << Medicines[i].MaThuoc << endl;
    cout << "Ten thuoc: " << Medicines[i].TenThuoc << endl;
    cout << "Don gia: " << Medicines[i].DonGia << endl;
    cout << "Ngay san xuat: " << Medicines[i].NSX.ngay << "/" << Medicines[i].NSX.thang << "/" << Medicines[i].NSX.nam << endl;
    cout << "Han su dung: " << Medicines[i].HSD.ngay << "/" << Medicines[i].HSD.thang << "/" << Medicines[i].HSD.nam << endl;
    // Cho phép ngu?i dùng ch?n thông tin c?n c?p nh?t
    cout << "\nChon thong tin can cap nhat:" << endl;
    cout << "1. Ma thuoc" << endl;
    cout << "2. Ten thuoc" << endl;
    cout << "3. Don gia" << endl;
    cout << "4. Ngay san xuat (ngay/thang/nam)" << endl;
    cout << "5. Han su dung (ngay/thang/nam)" << endl;
    cout << "Lua chon: ";
    cin >> luaChon;
     switch (luaChon) {
        case 1:
            cout << "Nhap ma thuoc moi: ";
            cin >> Medicines[i].MaThuoc;
            cout << "Cap nhat thanh cong!" << endl;
            break;
        case 2:
            cout << "Nhap ten thuoc moi: ";
            cin.ignore(); // Xóa b? nh? d?m d? nh?p tên m?i
            getline(cin, Medicines[i].TenThuoc);
            cout << "Cap nhat thanh cong!" << endl;
            break;
        case 3:
            cout << "Nhap don gia moi: ";
            cin >> Medicines[i].DonGia;
            cout << "Cap nhat thanh cong!" << endl;
            break;
        case 4:
            cout << "Nhap ngay san xuat moi (ngay/thang/nam): ";
            cin >> Medicines[i].NSX.ngay >> Medicines[i].NSX.thang >> Medicines[i].NSX.nam;
            cout << "Cap nhat thanh cong!" << endl;
            break;
        case 5:
            cout << "Nhap han su dung moi (ngay/thang/nam): ";
            cin >> Medicines[i].HSD.ngay >> Medicines[i].HSD.thang >> Medicines[i].HSD.nam;
            cout << "Cap nhat thanh cong!" << endl;
            break;
        default:
            cout << "Lua chon khong hop le. Vui long thu lai!" << endl;
            break;
    }
}


void FindMedicine() {
    string tenThuoc;
    cout << "Nhap ten thuoc can tim: "; cin.ignore(); getline(cin, tenThuoc);

    bool found = false;
    for (int i = 0; i < MAX_MEDICINE; ++i) {
        if (Medicines[i].TenThuoc == tenThuoc) {
            cout << "Thong tin cho thuoc " << i + 1 << ":" << endl;
            cout << "Ma Thuoc: " << Medicines[i].MaThuoc << endl;
            cout << "Ten Thuoc: " << Medicines[i].TenThuoc << endl;
            cout << "Don Gia: " << Medicines[i].DonGia << endl;
            cout << "Ngay San Xuat: " << Medicines[i].NSX.ngay << "/" << Medicines[i].NSX.thang << "/" << Medicines[i].NSX.nam << endl;
            cout << "Han Su Dung: " << Medicines[i].HSD.ngay << "/" << Medicines[i].HSD.thang << "/" << Medicines[i].HSD.nam << endl;
            cout << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Khong tim thay thuoc co ten '" << tenThuoc << "'" << endl;
    }
}


 






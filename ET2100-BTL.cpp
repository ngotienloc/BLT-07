#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Struct NhaSy
struct NhaSy {
    int id;
    string ten;
    unsigned int tuoi;
    string chucdanh;
    bool TT;
    NhaSy* next;
};
typedef NhaSy* N;
typedef NhaSy* ListN;

// Khoi tao danh sach nha sy rong
void InitializeN(ListN& A) {
    A = NULL;
}

// Template ham hoan doi gia tri
template <class T>
void Swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// Ham them nha sy
void InSertDentist(ListN& n) {
    N a = new NhaSy;
    cout << "Nhap ten: " ; getline(cin, a -> ten);
    cout << "Nhap ID: "; cin >> a -> id;
    cout << "Nhap tuoi: "; cin >> a -> tuoi; cin.ignore();
    cout << "Nhap chuc danh: "; getline(cin, a -> chucdanh);
    a -> TT = rand() % 2 == 0;
    a -> next = NULL;
    if (n == NULL) {
        n = a;
    } else {
        N temp = n;
        while (temp -> next != NULL) {
            temp = temp -> next;
        }
        temp -> next = a;
    }
}

// Ham xoa nha sy
void DeleteDentist(ListN& n, int MaSo) {
    if (n == NULL) {
        cout << "Danh sach rong!" << endl;
        return;
    }
    if (n -> id == MaSo) {
        N temp = n;
        n = n -> next;
        delete temp;
        return;
    }
    N current = n;
    while (current -> next != NULL) {
        if (current -> next -> id == MaSo) {
            N temp = current -> next;
            current -> next = current -> next -> next;
            delete temp;
            return;
        }
        current = current -> next;
    }
    cout << "Khong tim thay nha sy voi ID: " << MaSo << endl;
}

// Ham hien thi danh sach nha sy
void DisplayDentist(ListN n) {
    if (n == NULL) {
        cout << "Danh sach rong!" << endl;
        return;
    }
    while (n != NULL) {
        cout << "Ten: " << n -> ten << endl;
        cout << "Tuoi: " << n -> tuoi << endl;
        cout << "ID: " << n -> id << endl;
        cout << "Chuc Danh: " << n -> chucdanh << endl;
        cout << "Trang Thai: " << (n -> TT ? "dang ranh" : "dang ban" ) << endl;
        n = n -> next;
    }
}

// Ham tim kiem nha sy theo ID
void SearchDentist(ListN n, int MaSo) {
    if (n == NULL) {
        cout << "Danh sach rong!" << endl;
        return;
    }
    N temp = n;
    while (temp != NULL) {
        if (temp -> id == MaSo) {
            cout << "Ten: " << temp -> ten << endl;
            cout << "Tuoi: " << temp -> tuoi << endl;
            cout << "ID: " << temp -> id << endl;
            cout << "Chuc Danh: " << temp -> chucdanh << endl;
            cout << "Trang Thai: " << (temp -> TT ? "dang ranh" : "dang ban" ) << endl;
            return;
        }
        temp = temp -> next;
    }
    cout << "Khong tim thay nha sy voi ID: " << MaSo << endl;
}

// Ham sua thong tin nha sy
void UpdateDentist(ListN& n, int MaSo) {
    if (n == NULL) {
        cout << "Danh sach rong!" << endl;
        return;
    }
    N temp = n;
    while (temp != NULL) {
        if (temp -> id == MaSo) {
            cout << "Nhap ten moi: "; cin.ignore(); getline(cin, temp -> ten);
            cout << "Nhap ID moi: "; cin >> temp -> id; cin.ignore();
            cout << "Nhap tuoi moi: "; cin >> temp -> tuoi; cin.ignore();
            cout << "Nhap chuc danh moi: "; getline(cin, temp -> chucdanh);
            temp -> TT = rand() % 2 == 0;
            return;
        }
        temp = temp -> next;
    }
    cout << "Khong tim thay nha sy voi ID: " << MaSo << endl;
}

// Ham sap xep danh sach nha sy theo ID tang dan
void SortDentistbyID(ListN& n) {
    if (n == NULL) {
        cout << "Danh sach rong!" << endl;
        return;
    }

    bool swapped;
    do {
        swapped = false;
        N current = n;
        while (current -> next != NULL) {
            if (current -> id > current -> next -> id) {
                Swap(current -> id, current -> next -> id);
                Swap(current -> ten, current -> next -> ten);
                Swap(current -> tuoi, current -> next -> tuoi);
                Swap(current -> chucdanh, current -> next -> chucdanh);
                Swap(current -> TT, current -> next -> TT);
                swapped = true;
            }
            current = current -> next;
        }
    } while (swapped);
}

int main() {
    srand(time(0)); // khoi tao time ngau nhien

    ListN danhSachNhaSy;
    InitializeN(danhSachNhaSy);

    cout << "Nhap thong tin cho 3 nha sy:" << endl;
    for (int i = 0; i < 3; ++i) {
        InSertDentist(danhSachNhaSy);
    }

    cout << "\nDanh sach nha sy truoc khi sap xep:" << endl;
    DisplayDentist(danhSachNhaSy);

    SortDentistbyID(danhSachNhaSy);

    cout << "\nDanh sach nha sy sau khi sap xep theo ID tang dan:" << endl;
    DisplayDentist(danhSachNhaSy);

    int searchID, updateID, deleteID;

    cout << "\nNhap ID nha sy can tim: ";
    cin >> searchID;
    SearchDentist(danhSachNhaSy, searchID);

    cout << "\nNhap ID nha sy can cap nhat: ";
    cin >> updateID;
    UpdateDentist(danhSachNhaSy, updateID);

    cout << "\nDanh sach nha sy sau khi cap nhat:" << endl;
    DisplayDentist(danhSachNhaSy);

    cout << "\nNhap ID nha sy can xoa: ";
    cin >> deleteID;
    DeleteDentist(danhSachNhaSy, deleteID);

    cout << "\nDanh sach nha sy sau khi xoa:" << endl;
    DisplayDentist(danhSachNhaSy);

    return 0;
}


#include<iostream>
#include<vector>
#include<string>
using namespace std;



class Mon {
    private:
        int ID;
        string TEN;
        int GIA;
    public:
        Mon(int id, string ten, int gia);
        void setTen(string ten);
        void setGia(int gia);
        int getId();
        string getTen();
        int getGia();

};

void Mon::setGia (int gia) {
    GIA = gia;
}

void Mon::setTen (string ten) {
    TEN = ten;
}

int Mon::getGia() {
    return GIA;
}

string Mon::getTen() {
    return TEN;
}

int Mon::getId() {
    return ID;
}

Mon::Mon(int id, string ten, int gia) {
    this->ID = id;
    this->TEN = ten;
    this->GIA = gia;
}



class Ban {
    private:
        int STT;
        string TRANGTHAI;
    public:
        Ban(int stt, string trangThai);
        void setStt(int stt);
        void setTrangThai(string trangThai);
        int getStt();
        string getTrangThai();
};

Ban::Ban(int stt, string trangThai) {
    this->STT = stt;
    this->TRANGTHAI = trangThai;
};

void Ban::setStt(int stt) {
    STT = stt;
}

void Ban::setTrangThai(string trangThai) {
    TRANGTHAI = trangThai;
}

int Ban::getStt() {
    return STT;
}

string Ban::getTrangThai() {
    return TRANGTHAI;
}



class ChucVu {
    public:
        ChucVu();
};

class QuanLi {
    protected:
        vector<Mon> database;
    public:
        QuanLi();
        void themMon();
        void suaMon();
};

class NhanVien{
    private:
        vector<Ban> databaseBan;
    public:
        NhanVien();
};

ChucVu::ChucVu() {
    int phim = 0;
    do
    {
        cout << "1: Quan li\n2: Nhan vien\n0: Thoat\nNhap phim: ";
        cin >> phim;

        if(phim == 1) QuanLi quanli;
        else if(phim == 2) NhanVien nhanvien; 
        else if(phim == 0) return;
        else cout << "Nhap phim khong hop le. Vui long nhap lai !\n";

    } while(phim);
}

QuanLi::QuanLi() {
    int phim = 0;
    do
    {
        cout << "1: Them mon\n2: Sua mon\n0: Quay lai\nNhap phim: ";
        cin >> phim;

        if(phim == 1) themMon();
        else if(phim == 2) suaMon();
        else if(phim == 0) return;
        else cout << "Nhap so khong hop le. Vui long nhap lai\n";
    } while (phim); 
        
}

void QuanLi::suaMon() {
    int phim = 0;
    if (database.size() == 0) {
        cout <<"Menu trong. Vui long them vao menu!\n";
        return;
        
    }
    do
    {     
        cout << "Danh sach mon an\n"
             << "-----------------------------------------\n"
             << "ID" << "\t\t" << "Ten" << "\t\t" << "Gia\t\n";

        for (int i = 0; i < database.size() ; i++) {
            cout << database[i].getId() << "\t\t" 
                 << database[i].getTen() << "\t\t"
                 << database[i].getGia() << "\t\t\n";
            }
        cout << "-----------------------------------------\n";


        int id;
        int checkId = 0;
        again3:
        cout << "Nhap ID mon can sua: "; cin >> id;
        for(int i = 0; i < database.size(); i++) {
            if(database[i].getId() == id) checkId++;
        }
        if(checkId == 0) {
            cout << "ID khong ton tai. Vui long nhap lai\n";
            goto again3;
        }
        again2:
        cout << "1: Sua ten\n2: Sua gia\n0: Quay lai\n";
        cout << "Nhap phim: "; cin >> phim;
        if(phim == 1) {
            string ten;
            cout << "Nhap lai ten: "; cin >> ten;
            database[id - 100].setTen(ten);
        }
        else if(phim == 2) {
            int gia;
            cout << "Nhap lai gia: "; cin >> gia;
            database[id - 100].setGia(gia);
        }
        else if(phim == 0) return;
        else {
            cout << "Nhap phim khong hop le. Vui long nhap lai!\n";
            goto again2;
        }
        cout << "Sua doi thanh cong\n"
             << "-----------------------------------------\n"
             << "ID" << "\t\t" << "Ten" << "\t\t" << "Gia\t\n";

        for (int i = 0; i < database.size() ; i++) {
            cout << database[i].getId() << "\t\t" 
                 << database[i].getTen() << "\t\t"
                 << database[i].getGia() << "\t\t\n";
            }
        cout << "-----------------------------------------\n";

        again:
        cout << "1: Tiep tuc sua\n0: Quay lai\n";
        cin >> phim;

        if(phim == 0) return;
        else if(phim != 1) {
            cout << "Nhap phim khong hop le. Vui long nhap lai!\n";
            goto again;
        } 
    }while(phim == 1);
    




}

void QuanLi::themMon() {
    static int id = 100;
    string ten;
    int gia;
    int phim = 0;
    do {
        cout << "Nhap ten: "; cin >> ten;
        cout << "Nhap gia: "; cin >> gia;

        Mon mon(id, ten, gia);
        database.push_back(mon);
        
        cout << "Them mon thanh cong !\n"
             << "-----------------------------------------\n";
        cout << "ID" << "\t\t" << "Ten" << "\t\t" << "Gia\t\n";

        for (int i = 0; i <= id -100 ; i++) {
            cout << database[i].getId() << "\t\t" 
                 << database[i].getTen() << "\t\t"
                 << database[i].getGia() << "\t\t\n";
        }
        cout << "-----------------------------------------\n";
        id++;

        again:
        cout << "1: Tiep tuc them\n0: Quay lai\nNhap phim: ";
        cin >> phim;

        if(phim == 0) return;
        else if(phim != 0 && phim != 1) {
            cout << "Nhap phim khong hop le. Vui long nhap lai!\n";
            goto again;
        } 

    } while(phim == 1);
}

NhanVien::NhanVien() {

    for (int i = 0; i < 10; i++) {
        Ban ban(i + 1, " ");
        databaseBan.push_back(ban);
    }
    
    cout << "--------------------------------------------\n"
         << "       Ban: ";
    for(int j = 0; j < 10; j++) {
        cout << databaseBan[j].getStt() << "  ";     
    }
    cout << "\n"
         << "Trang thai: ";
    for(int k = 0; k < 10; k++) {
        cout << databaseBan[k].getTrangThai() << "  ";
    }
    cout << "\n"
         << "--------------------------------------------\n";
     
    int phim = 0; 
    cout << "Chon ban: "; cin >> phim;
    // switch (phim)
    // {
    // case 1:
    //     /* code */
    //     break;
    // case 2:
    // case 3:
    // case 4:
    // case 5:
    // case 6:
    // case 7:
    // case 8:
    // case 9:
    // case 10:
    // default:
    //     break;
    // }
 
    
} 


int main() {

    ChucVu chucvu;

}

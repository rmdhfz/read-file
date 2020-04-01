#include <iostream>
#include <fstream>

using namespace std;

int main(){
	string namafile, teks;
	/*buat file berdasarkan nama file yang di input*/
	cout << "1) Buat file dengan nama : "; 
	if (getline(cin, namafile)){
		ofstream createfile;
		/*buat file*/
		createfile.open(namafile);
		/*cek file, apakah berhasil dibuat ? */
		ifstream file (namafile);
		if (file.is_open()){
			cout << "-------------------------------------------" << endl;
			cout << "-> Status: File terbaca, berarti file berhasil terbuat" << endl;
			cout << "-------------------------------------------" << endl;
			cout << "2) Masukan isi pesan untuk file " << namafile << endl;
			cout << "-------------------------------------------" << endl;
			cout << "Tulis pesan kamu : ";
			if (getline(cin, teks)){
				createfile << teks << endl;
				cout << "-------------------------------------------" << endl;
				cout << "-> Status: File berhasil ditulis, saatnya membaca file." << endl;
				cout << "-------------------------------------------" << endl;
				string isi;
				while(getline(file, isi)){
					cout << "3) Yang kamu tulis adalah " << endl;
					cout << "-> " << isi << endl;
				}
				file.close();
			}else{
				cout << "Gagal mengambil isi dari variabel teks" << endl;
			}
		}else{
			cout << "File tidak terbaca, berarti file gagal terbuat" << endl;
		}
	}
	return 0;
}

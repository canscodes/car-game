#include <iostream>
#include <string>
#include <locale.h>
#include <iomanip>
#include <Windows.h>
#include <fstream>
using namespace std;
struct client {
	string name, surname, clientNumber, PESEL;
};
struct room {
	string roomNo, price;
};
int main() {
	system("color 20");
	setlocale(LC_ALL, "turkish");
	ofstream WriteFile;
	ifstream ReadFile;
	client cl;
	room ROOM;
	string choice;		//Menü seçimlerinde kullanılan değişken.
	do {
		system("cls");
		cout << "HOTEL PROCEDURES\n";
		for (int i = 0; i < 20; i++)
			cout << "-";
		cout << endl;
		cout << "1- ROOM PROCEDURES\n";
		cout << "2- CLIENT PROCEDURES\n";
		cout << "3- ROOM REGISTRATION PROCEDURES\n";
		cout << "99- EXIT\n";
		cout << "YOUR CHOICE: ";
		cin >> choice;

		//------------------------------------------------------ANA_MENU_1.SECENEK_GIRIS-----------------------------------------------
		if (choice == "1") {
			string choiceFIRST;		//Menü seçimlerinde kullanılan değişken.
			do {
				system("cls");
				cout << "ROOM PROCEDURES\n";
				for (int i = 0; i < 20; i++)
					cout << "-";
				cout << endl;
				cout << "1- ADD ROOM\n";
				cout << "2- DELETE ROOM\n";
				cout << "3- LIST ROOMS\n";
				cout << "99- TOP MENU\n";
				cout << "YOUR CHOICE: ";
				cin >> choiceFIRST;
				//------------------------------------1 in icindeki 1 giris-------------
				if (choiceFIRST == "1") {
					string control;			//işlem sonunda devam edilip edilmeyeceği sorulurken kullanılan değişken.
					do {
						system("cls");
						string keep;
						int controlx = 0, control2x = 0;  //oda numaraları daha önce kullanılmış mı ve nizami mi diye kontrol ederken kullanılan yardımcı değişken.
						do {
							controlx = 0, control2x = 0;
							ReadFile.open("roomRegistration.txt");
							cout << "Enter 4-digit room number: ";
							cin >> ROOM.roomNo;
							keep = ROOM.roomNo;
							while (ReadFile >> ROOM.roomNo >> ROOM.price) {

								if (keep == ROOM.roomNo)
									controlx = 1;         //eğer oda numarası daha öncee kullanılmışsa değişkene 1 değeri atanıyor.
							}
							ReadFile.close();
							for (int i = 0; i < keep.length(); i++) {
								if (!(keep[i] > 47 && keep[i] < 58))
									control2x = 1;       //eğer oda numarasına rakamdandan başka birşey yazıldıysa kontrol2x değişkenine 1 atanıyor.
							}
							if (controlx == 1) {
								system("cls");
								cout << "THIS ROOM NUMBER IS USED. CHOOSE ANOTHER NUMBER...\n";				//kontrolx değişkenine 1 atanmışsa kullanıcıya uyarı yapılıyor.
								system("pause");
								system("cls");
							}
							else if (control2x == 1) {
								system("cls");
								cout << "THE ROOM NUMBER MUST CONSIST OF NUMBERS...\n";						//kontrol2x değişkenine 1 atanmışsa kullanıcıya uyarı yapılıyor.
								system("pause");
								system("cls");
							}
							else if (keep.length() != 4) {
								system("cls");
								cout << "ROOM NUMBER MUST BE 4 DIGITS...\n";			//oda numarası 4 haneden fazla ise kullanıcıya uyarı yapılıyor.
								system("pause");
								system("cls");
							}

						} while (controlx == 1 || control2x == 1 || keep.length() != 4);		//yukarıdaki uyarılardan en az biri bile yapıldıysa tekrardan numara girmesi isteniyor.
						controlx = 0, control2x = 0;
						int control4x;		//eğer harf harici bir karakter kullanılmışsa kullanıcıyı uyarmak için kullanılacak değişken.
						string uctut; //oda ucreti girilirken rakam harici bir karakter kullanılmış mı diye kontrol etmek icin kullanılan değişken.
						do {
							control4x = 0;				//kontrol4x değişkenine random olarak 0 atanır.
							cout << "ENTER ROOM PRICE: ";
							cin >> ROOM.price;
							uctut = ROOM.price;
							int nn;
							char li;
							for (int i = 0; i < uctut.length(); i++) {
								li = uctut[i];
								nn = static_cast<int>(li);
								if (!((nn > 47) && (nn < 58)))
									control4x = 1;				//eğer rakam harici bir karakter kullanılmışsa kontrol4x değişkenine 1 atanır.
							}
							if (control4x == 1) {
								system("cls");
								cout << "ONLY NUMBERS CAN BE ENTERED IN THE PRICE FIELD ...\n";			//eğer kontrol4x değişkenine 1 atanmışsa uyarı verir.
								system("pause");
								system("cls");
							}
						} while (control4x == 1);	//kontrol4x değişkeni 1 ise uyarıdan sonra yeniden ücret girilmesi istenir.

						WriteFile.open("roomRegistration.txt", ios::app);
						WriteFile << keep << "\t" << ROOM.price << endl;
						WriteFile.close();
						system("cls");
						cout << "ROOM REGISTRATION SUCCESSFUL\n";
						do {
							system("cls");
							cout << "WOULD YOU LIKE TO CONTINUE WITH THE REGISTRATON PROCESS ? (y/n): ";
							cin >> control;
							if (control != "y"&&control != "n") {
								cout << "\n-y- OR -n- ENTER ONE OF THESE LETTERS...\n";
								system("pause");
								system("cls");
							}

						} while (control != "y"&&control != "n");
					} while (control == "y");

				}
				//-----------------------------1 icindeki 2 giris-------------------
				else if (choiceFIRST == "2") {

					string choice1;
					int  nul;		//oda silerken silinecek odanın olup olmadığını söylemek için kullanılan değişken.
					string no;		//girilen oda numarasının olup olmadığını kontrol ederken kullanılan değişken.
					do {
						do {
							nul = 0;
							system("cls");
							cout << "ENTER THE NUMBER OF ROOMS TO BE DELETED: ";
							cin >> no;
							ReadFile.open("roomRegistration.txt");
							while (ReadFile >> ROOM.roomNo >> ROOM.price) {
								if (no == ROOM.roomNo)
									nul = 1;							//böyel bir numara varsa nul değişkenine 1 atanır.
							}
							ReadFile.close();
							if (nul == 0) {
								system("cls");
								cout << "THERE IS NO ROOM WITH THIS NUMBER.\n";    // böyle bir numara yoksa nul değişkeni varsayılan olarak sıfır olur ve uyarı verir.
								system("pause");
							}
						} while (nul == 0);  //girilen oda numarası yoksa yeniden numara ister.

											 //---------------------------------------------------------------------------------
						WriteFile.open("rezervKeep.txt");                                               //eğer silinen odanın rezervasyonu varsa onu da siler.
						ReadFile.open("rezerv.txt");
						while (ReadFile >> ROOM.roomNo >> cl.clientNumber >> cl.name) {
							if (ROOM.roomNo != no)
								WriteFile << ROOM.roomNo << "\t" << cl.clientNumber << "\t" << cl.name << endl;
						}
						ReadFile.close();
						WriteFile.close();
						WriteFile.open("rezerv.txt");
						ReadFile.open("rezervKeep.txt");
						while (ReadFile >> ROOM.roomNo >> cl.clientNumber >> cl.name) {

							WriteFile << ROOM.roomNo << "\t" << cl.clientNumber << "\t" << cl.name << endl;
						}
						ReadFile.close();
						WriteFile.close();

						//---------------------------------------------------------------------------------
						WriteFile.open("roomRegistrationKeep.txt");
						ReadFile.open("roomRegistration.txt");
						while (ReadFile >> ROOM.roomNo >> ROOM.price) {
							if (ROOM.roomNo != no)
								WriteFile << ROOM.roomNo << "\t" << ROOM.price << endl;
						}
						ReadFile.close();
						WriteFile.close();
						WriteFile.open("roomRegistration.txt");
						ReadFile.open("roomRegistrationTut.txt");
						while (ReadFile >> ROOM.roomNo >> ROOM.price) {

							WriteFile << ROOM.roomNo << "\t" << ROOM.price << endl;
						}
						ReadFile.close();
						WriteFile.close();
						system("cls");
						cout << "DELETION SUCCESSFUL\n";

						do {
							system("cls");
							cout << "WOULD YOU LİKE TO CONTİNUE THE DELETION PROCESS ? (y/n): ";
							cin >> choice1;
							if (choice != "y"&&choice1 != "n") {
								cout << "\n-y- OR -n- ENTER ONE OF THESE LETTERS...\n";
								system("pause");
								system("cls");
							}

						} while (choice1 != "y"&&choice1 != "n");
					} while (choice1 == "y");
				}
				//-------------------1 icindeki 3 giris--------------------------------
				else if (choiceFIRST == "3") {
					system("cls");
					cout << "room Number" << "\t" << "Price\n";
					for (int i = 0; i < 18; i++) {
						cout << "_";
						if (i == 11)
							cout << "\t";
					}
					cout << endl;
					ReadFile.open("roomRegistration.txt");
					while (ReadFile >> ROOM.roomNo >> ROOM.price) {
						cout << "    " << left << setw(8) << ROOM.roomNo << "\t" << " " << ROOM.price << " TL" << endl;
					}
					ReadFile.close();

					system("pause");
					system("cls");
				}
				if ((choiceFIRST != "1") && (choiceFIRST != "2") && (choiceFIRST != "3") && (choiceFIRST != "99")) {
					system("cls");
					cout << "INCORRECT CHOICE\n";
					system("pause");
				}

			} while (choiceFIRST != "99");

		}
		//------------------------------------------------------------------------ANA_MENU_1.SECENEK_CIKIS--------------------------------------


		//------------------------------------------------------------------------ANA_MENU_2.SECENEK_GIRIS-------------------------------------

		if (choice == "2") {
			string choiceFIRST;   //menü seçimde kullanılacak değişken.
			do {
				system("cls");
				cout << "CLIENT PROCESS\n";
				for (int i = 0; i < 20; i++)
					cout << "-";
				cout << endl;
				cout << "1- ADD CLIENT\n";
				cout << "2- DELETE CLIENT\n";
				cout << "3- LIST CLIENTS\n";
				cout << "99- TOP MENU\n";
				cout << "YOUR CHOICE: ";
				cin >> choiceFIRST;
				//------------------------------------2 nin icindeki 1 giris-------------
				if (choiceFIRST == "1") {
					string control;
					string a;
					int pl; //ad ve soyadda rakam ve kullanılamayan karakterilerin kontrolü için oluşturulan değişken.
					do {

						system("cls");
						do {
							pl = 0;
							cout << "ENTER CLIENT NAME: ";
							cin >> cl.name;
							for (int i = 0; i < ((cl.name).length()); i++) {
								int n = static_cast<int>(cl.name[i]);
								if (!((n > 64 && n < 91) || (n > 96 && n < 123))) {
									pl = 1;

								}
							}
							if (pl == 1) {
								system("cls");
								cout << "ONLY ENGLISH LETTERS ARE USED IN THE NAME SECTION\n";
								system("pause");
								system("cls");
							}
						} while (pl == 1);

						do {
							pl = 0;
							cout << "ENTER CLIENT SURNAME: ";
							cin >> cl.surname;
							for (int i = 0; i < ((cl.surname).length()); i++) {
								int n = static_cast<int>(cl.surname[i]);
								if (!((n > 64 && n < 91) || (n > 96 && n < 123))) {
									pl = 1;

								}
							}
							if (pl == 1) {
								system("cls");
								cout << "ONLY ENGLISH LETTERS ARE USED IN THE SURNAME SECTION\n";
								system("pause");
								system("cls");
							}
						} while (pl == 1);
						int u = 0, olo = 0;  //tc no ve müşteri no'ları nizamimi ve daha önceden kullanılmış mı diye kontrol ederken kullanılan değişkenler.
						char n;
						string keepPESEL, tg, yh, th; //dosyada nokuma esnasında ad,soyad ve tcnin karışmaması için kullanılan değişkenler.
						do {
							ReadFile.open("clientRegistration.txt");
							u = 0, olo = 0; int p = 0;
							cout << "ENTER CLIENT'S 11-DİGİT PESEL NUMBER: ";
							cin >> cl.PESEL;
							keepPESEL = cl.PESEL;
							while (ReadFile >> tg >> th >> cl.PESEL >> yh) {
								if (keepPESEL == cl.PESEL)          //eğer tckn sistemde kayıtlıysa olo değişkenine 1 atar.
									olo = 1;
							}
							ReadFile.close();

							for (int i = 0; i < (keepPESEL.length()); i++) {
								n = keepPESEL[i];
								p = static_cast<int>(n);
								if (!(p > 47 && p < 58))						//eğer tckn de rakamdan farklı bir karakter kulllanılmışsa u değişkenine 1 atar.
									u = 1;
							}
							if (u == 1) {
								system("cls");
								cout << "PESEL NUMBER MUST BE NUMBERS ONLY...\n";			//u değişkenine 1 atanmışsa uyarı verir.
								system("pause");
								system("cls");
							}
							else if (keepPESEL.length() != 11) {
								system("cls");
								cout << "PESEL MUST BE 11 DIGITS...\n";					//tckn 11 haneli değilse uyarı verir.
								system("pause");
								system("cls");
							}

							else if (olo == 1) {
								system("cls");
								cout << "THIS PESEL IS ALREADY REGISTERED. ENTER ANOTHER PESEL...\n";			//olo değikenine 1 atanmışsa uyarı verir.
								system("pause");
								system("cls");
							}
						} while (u == 1 || keepPESEL.length() != 11 || olo == 1); //eğer uyarılardan biri bile olduysa tckn nin yeniden girilmesini ister.

						int tutucu, tutucu2;   //musteri numarası daha önceden alınmış mı ve nizami mi diye kontrol edilirken kullanılan değişkenler.
						string clno;
						do {
							tutucu = 0, tutucu2 = 0;
							cout << "ENTER CLIENT'S 5-DIGET CLIENT NUMBER: ";
							cin >> cl.clientNumber;
							clno = cl.clientNumber;
							ReadFile.open("clientRegistration.txt");
							while (ReadFile >> tg >> th >> cl.PESEL >> cl.clientNumber) {
								if (clno == cl.clientNumber)
									tutucu = 1;                              // müşteri numarası daha önceden kayıtlanmışsa tutucu değişkenine 1 atar.
							}
							char u;
							int y;
							ReadFile.close();
							for (int i = 0; i < clno.length(); i++) {
								u = clno[i];
								y = static_cast<int>(u);
								if (!(y > 47 && 58 > y))					//eğer müşteri numarasında rakamdan farklı bir karakter varsa tutucu2 değişkenine 1 atar.
									tutucu2 = 1;
							}
							if (tutucu == 1) {
								system("cls");
								cout << "THIS CLIENT NUMBER IS USED BY ANOTHER PERSON...\n";
								system("pause");
								system("cls");
							}
							else if (tutucu2 == 1) {
								system("cls");
								cout << "CLIENT NUMBER MUST BE NUMBERS ONLY...\n";
								system("pause");
								system("cls");
							}
							else if (clno.length() != 5) {						//müşeri numarası 5 haneden farklı ise uyarı verir.
								system("cls");
								cout << "CLIENT NUMBER MUST HAVE 5 DIGITS...\n";
								system("pause");
								system("cls");
							}
						} while (tutucu == 1 || tutucu2 == 1 || clno.length() != 5);  //uyarılardan biri bile verildiyse yeninen numara girmenizi ister.

						WriteFile.open("clientRegistration.txt", ios::app);
						WriteFile << cl.name << "\t" << cl.surname << "\t" << keepPESEL << "\t" << clno << endl;
						WriteFile.close();
						system("cls");
						cout << "CLIENT REGISTERED\n";
						system("pause");
						do {
							system("cls");
							cout << "NEW REGISTRATION(y/n): ";
							cin >> control;
							if (control != "Y"&&control != "N") {
								cout << "\n-y- OR -n- ENTER ONE OF THESE LETTERS...\n";
								system("pause");
								system("cls");
							}

						} while (control != "y"&&control != "n");
					} while (control == "y");

				}
				//-----------------------------2 nin icindeki 2 giris-------------------
				else if (choiceFIRST == "2") {

					string choice1;
					string no;  //müşteri numarası sistemde varmı diye kontrol eden değişken.

					do {
						int g = 0;      //silinmesi için girilen numaranın var olup olmadığını anlamak için kullanılan değişken.
						do {
							g = 0;
							system("cls");
							cout << "ENTER THE CLIENT NUMBER TO BE DELETED: ";
							cin >> no;
							ReadFile.open("clientRegistration.txt");
							while (ReadFile >> cl.name >> cl.surname >> cl.PESEL >> cl.clientNumber)
							{
								if (no == cl.clientNumber)
									g = 1;
							}
							ReadFile.close();
							if (g == 0) {
								system("cls");
								cout << "THERE IS NO SUCH RECORD.\n";
								system("pause");
								system("cls");
							}
						} while (g == 0);
						//-----------------------------------------
						WriteFile.open("rezervKeep.txt");
						ReadFile.open("rezerv.txt");
						while (ReadFile >> ROOM.roomNo >> cl.clientNumber >> cl.name) {
							if (cl.clientNumber != no)
								WriteFile << ROOM.roomNo << "\t" << cl.clientNumber << "\t" << cl.name << endl;
						}
						ReadFile.close();
						WriteFile.close();
						WriteFile.open("rezerv.txt");
						ReadFile.open("rezervKeep.txt");
						while (ReadFile >> ROOM.roomNo >> cl.clientNumber >> cl.name) {

							WriteFile << ROOM.roomNo << "\t" << cl.clientNumber << "\t" << cl.name << endl;
						}
						ReadFile.close();
						WriteFile.close();


						//---------------------------------------------
						WriteFile.open("clientRegistrationKeep.txt");
						ReadFile.open("clientRegistration.txt");
						while (ReadFile >> cl.name >> cl.surname >> cl.PESEL >> cl.clientNumber) {
							if (cl.clientNumber != no)
								WriteFile << cl.name << "\t" << cl.surname << "\t" << cl.PESEL << "\t" << cl.clientNumber << endl;
						}
						ReadFile.close();
						WriteFile.close();
						WriteFile.open("clientRegistration.txt");
						ReadFile.open("clientRegistrationKeep.txt");
						while (ReadFile >> cl.name >> cl.surname >> cl.PESEL >> cl.clientNumber) {

							WriteFile << cl.name << "\t" << cl.surname << "\t" << cl.PESEL << "\t" << cl.clientNumber << endl;
						}
						ReadFile.close();
						WriteFile.close();
						system("cls");
						cout << "DELETION COMPLETE\n";
						system("pause");
						do {
							system("cls");
							cout << "WOULD YOU LIKE TO CONTINUE THE DELETING PROCESS?(y/n): ";
							cin >> choice1;
							if (choice1 != "y"&&choice1 != "n") {
								cout << "\n-y- OR -n- ENTER ONE OF THESE LETTERS...\n";
								system("pause");
								system("cls");
							}

						} while (choice1 != "y"&&choice1 != "n");
					} while (choice1 == "y");
				}
				//-------------------2 nin icindeki 3 giris--------------------------------
				else if (choiceFIRST == "3") {
					system("cls");
					cout << "CLIENT NAME" << "\t" << "CLIENT SURNAME" << "\t" << "CLIENT PESEL" << "\t" << "CLIENT NUMBER\n";
					for (int i = 0; i < 53; i++) {
						cout << "_";
						if (i == 10)
							cout << "\t";
						if (i == 24)
							cout << "\t";
						if (i == 36)
							cout << "\t";

					}
					cout << endl;
					ReadFile.open("clientRegistration.txt");
					while (ReadFile >> cl.name >> cl.surname >> cl.PESEL >> cl.clientNumber) {
						string name = cl.name, surname = cl.surname;

						cout << left << setw(18 - (name.length())) << cl.name << "\t" << left << setw(16 - (surname.length())) << cl.surname << "\t" << cl.PESEL << "\t" << setw(5) << cl.clientNumber << endl;
					}
					ReadFile.close();

					system("pause");
					system("cls");
				}
				if ((choiceFIRST != "1") && (choiceFIRST != "2") && (choiceFIRST != "3") && (choiceFIRST != "99")) {
					system("cls");
					cout << "INCORRECT CHOICE\n";
					system("pause");
				}

			} while (choiceFIRST != "99");

		}
		//------------------------------------------------------------------------ANA_MENU_2.SECENEK_CIKIS-------------------------------------

		//------------------------------------------------------------------------ANA_MENU_3.SECENEK_GIRIS-------------------------------------
		if (choice == "3") {
			string choiceFIRST;   //menü seçimlerinde kullanılan değişken.
			do {
				system("cls");
				cout << "ROOM REGISTRATION PROCEDURES\n";
				for (int i = 0; i < 20; i++)
					cout << "-";
				cout << endl;
				cout << "1- ROOM RESERVATION\n";
				cout << "2- DELETING A RESERVATION\n";
				cout << "3- LIST RESERVATIONS\n";
				cout << "99- TOP MENU\n";
				cout << "YOUR CHOICE: ";
				cin >> choiceFIRST;

				//------------------------3 icindeki 1 giris-----------------------------------------------------------

				if (choiceFIRST == "1") {
					int  b = 0, d = 0, t = 0, y, o = 0;   //oda daha önce tutulmuşsa veya böyle bir oda yoksa bu bilgileri saklamak için kullanılan değişkenler.
					string q;  //yeni rezeervasyon yapılıp yapılmayacağını tutan değişken.
					string namekeep, a, tutt, c;    //odanın daha öne tutulup tutulmadığını ve böyle bir odanın olup olmadığını kontrol ederken kullanılan değiken.

					do {
						system("cls");
						do {
							b = 0, t = 0, o = 0;
							cout << "ROOM NUMBER TO BE RESERVED: ";
							cin >> a;
							tutt = a;
							ReadFile.open("rezerv.txt");
							while (ReadFile >> ROOM.roomNo >> cl.clientNumber >> cl.name) {
								if (a == ROOM.roomNo)
									o = 1;
							}
							ReadFile.close();
							ReadFile.open("roomRegistration.txt");
							while (ReadFile >> ROOM.roomNo >> ROOM.price) {
								if (a == ROOM.roomNo)
									b = 1;
							}
							ReadFile.close();
							if (b == 1) {
								ROOM.roomNo = tutt;
							}
							if (b == 0) {
								system("cls");
								cout << "INCORRECT ROOM NUMBER...\n";
								system("pause");
								system("cls");
							}
							if (o == 1) {
								system("cls");
								cout << "THIS ROOM IS ALREADY RESERVED...\n";
								system("pause");
								system("cls");
							}

						} while (b == 0 || o == 1);
						do {
							d = 0;        // girilen numaranın rezervasyonu daha önceden yapılmış mı ve girilen numara sistemde kayıtlı mı diye kontrol eden değişkenler.
							t = 0;
							cout << "NUMBER OF THE CLIENT TO BE PLACED IN THE ROOM: ";
							cin >> c;
							ReadFile.open("rezerv.txt");
							while (ReadFile >> ROOM.roomNo >> cl.clientNumber >> cl.name)
							{
								if (c == cl.clientNumber)				//numaranın daha önceden rezervasyonu yapılmışsa t değişkenine 1 atar.
									t = 1;

							}
							ReadFile.close();
							ReadFile.open("clientRegistration.txt");
							while (ReadFile >> cl.name >> cl.surname >> cl.PESEL >> cl.clientNumber) {
								if (c == cl.clientNumber) {							//müşteri numarası sistemde kayıtlıysa d değişkenine 1 atar.
									d = 1;
									namekeep = cl.name;
								}


							}
							ReadFile.close();

							if (d == 1 && t == 0) {
								cl.clientNumber = c;
								cl.name = namekeep;
							}
							else if (d == 0) {
								system("cls");
								cout << "INCORRECT CLIENT NUMBER...\n";
								system("pause");
								system("cls");
							}
							else if (t == 1)   // t değişkenine 1 atanmışsa uyarı verir.
							{
								system("cls");
								cout << "THE NUMBER YOU ENTERED IS RESERVED...\n";
								system("pause");
								system("cls");
							}

						} while (d == 0 || t == 1);   //t değişkenine 1 atanmışsa veya d değişkeni 0 sa yeniden numara girilmesini ister.
						WriteFile.open("rezerv.txt", ios::app);
						WriteFile << tutt << "\t" << cl.clientNumber << "\t" << cl.name << endl;
						WriteFile.close();
						do {
							system("cls");
							cout << "NEW RESERVATION(y/n): ";
							cin >> q;
							if (q != "y" && q != "n") {
								cout << "-y- OR -n- ENTER ONE OF THESE LETTERS...\n";
								system("pause");
							}

						} while (q != "y"&&q != "n");



					} while (q == "y");//oda kayit devam
				}

				//------------------------3 icindeki 2 giris-------------------------------------------------

				if (choiceFIRST == "2") {
					int lol;		//numara var mı yok mu diye kontrol edilirken kullanılan değişken.
					string choice1;
					string no;  //silinecek nmaranın rezervasyonu var mı diye kontrol etmek için kullanılan değişken.
					do {
						do {
							lol = 0;
							system("cls");
							cout << "ENTER THE NUMBER OF THE CUSTOMER TO DELETE THE RESERVATION: ";
							cin >> no;
							ReadFile.open("rezerv.txt");
							while (ReadFile >> ROOM.roomNo >> cl.clientNumber >> cl.name)
							{
								if (no == cl.clientNumber)                        //numaranın rezervasyonu varsa lol değişkenine 1 atanır.
									lol = 1;
							}
							ReadFile.close();
							if (lol == 0) {									//eğer lol değişkeni sıfırsa yani bu numaranın rezervasyonu yoksa uyarı verir.
								system("cls");
								cout << "THIS NUMBER DOES NOT HAVE A RESERVATION.\n";
								system("pause");
							}
						} while (lol == 0);  // lol değişkeni sıfırsa yeniden numara ister.

						WriteFile.open("rezervKeep.txt");
						ReadFile.open("rezerv.txt");
						while (ReadFile >> ROOM.roomNo >> cl.clientNumber >> cl.name) {
							if (cl.clientNumber != no)
								WriteFile << ROOM.roomNo << "\t" << cl.clientNumber << "\t" << cl.name << endl;
						}
						ReadFile.close();
						WriteFile.close();
						WriteFile.open("rezerv.txt");
						ReadFile.open("rezervKeep.txt");
						while (ReadFile >> ROOM.roomNo >> cl.clientNumber >> cl.name) {

							WriteFile << ROOM.roomNo << "\t" << cl.clientNumber << "\t" << cl.name << endl;
						}
						ReadFile.close();
						WriteFile.close();
						system("cls");
						cout << "RESERVATION DELETED SUCCESSFULLY\n";
						system("pause");
						do {
							system("cls");
							cout << "WOULD YOU LIKE TO CONTINUE THE DELETING PROCESS?(y/n): ";
							cin >> choice1;
							if (choice1 != "y"&&choice1 != "n") {
								cout << "\n-y- OR -n- ENTER ONE OF THESE LETTERS...\n";
								system("pause");
								system("cls");
							}

						} while (choice1 != "y"&&choice1 != "n");

					} while (choice1 == "y");

				}

				//------------------------------------3 ic 2 cıkıs-----------------------------------------------

				if (choiceFIRST == "3") {
					system("cls");
					ReadFile.open("rezerv.txt");
					cout << setw(15) << "                        --------------------------REZERVASYONLAR--------------------------\n";
					cout << "ROOM NUMBER" << "\t" << "CLIENT NUMBER" << "\t" << "CLIENT NAME" << endl;
					for (int i = 0; i < 40; i++) {
						cout << "_";
						if (i == 12)
							cout << "\t";
						if (i == 28)
							cout << "\t";

					}
					cout << endl;
					while (ReadFile >> ROOM.roomNo >> cl.clientNumber >> cl.name) {



						cout << left << setw(16) << ROOM.roomNo << left << setw(24) << cl.clientNumber << cl.name << endl;


					}
					ReadFile.close();

					system("pause");

				}
				//-----------------------------------3 ic 3  cıkıs-----------------------------------------------




				if (choiceFIRST != "1" && choiceFIRST != "2" && choiceFIRST != "3" && choiceFIRST != "99") {
					system("cls");
					cout << "INCORRECT CHOICE.\n";
					system("pause");
				}




			} while (choiceFIRST != "99");

		}
		if ((choice != "1") && (choice != "2") && (choice != "3") && (choice != "99")) {
			system("cls");
			cout << "INCORRECT CHOICE\n";
			system("pause");
		}
	} while (choice != "99");
	system("cls");

	system("del clientRegistrationKeep.txt");
	system("del rezervKeep.txt");
	system("del roomRegistrationKeep.txt");
	system("cls");
	cout << "EXIT THE PROGRAM.\n";
	system("pause");
	return 0;
}

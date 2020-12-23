#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include"windows.h"
using namespace std;
int AGE{ 0 };
char n[255]{ 0 };
char O[255]{ 0 };
class Human {
private:
	int sizeName;
	int sizeOtherInfo;
	char* Name;
	int age;
	char* otherInfo;
public:
	Human(const char* n, int a, const char* o) {
		sizeName = (int)strlen(n) + 1;
		Name = new char[sizeName];
		strcpy(Name, n);
		age = a;
		sizeOtherInfo = (int)strlen(o) + 1;
		otherInfo = new char[sizeOtherInfo];
		strcpy(otherInfo, o);
	}
	Human() : sizeName{ 0 }, sizeOtherInfo{ 0 }, Name{ nullptr }, age{ 0 }, otherInfo{ nullptr }{
	}
	Human(const Human& otherHuman) {//����������� �����������
		this->sizeName = otherHuman.sizeName;
		this->Name = new char[sizeName];
		strcpy(Name, otherHuman.Name);
		this->age = otherHuman.age;
		this->sizeOtherInfo = otherHuman.sizeOtherInfo;
		this->otherInfo = new char[sizeOtherInfo];
		strcpy(otherInfo, otherHuman.otherInfo);
	}
	Human& operator = (const Human& otherHuman) {//���������� ��������� ������������
		this->sizeName = otherHuman.sizeName;
		this->Name = new char[sizeName];
		strcpy(Name, otherHuman.Name);
		this->age = otherHuman.age;
		this->sizeOtherInfo = otherHuman.sizeOtherInfo;
		this->otherInfo = new char[sizeOtherInfo];
		strcpy(otherInfo, otherHuman.otherInfo);
		return *this;
	}
	void SetName(const char* n) {
		sizeName = (int)strlen(n) + 1;
		Name = new char[sizeName];
		strcpy(Name, n);
	}
	char* GetName() { return Name; }
	void SetAge(int a) {
		age = a;
	}
	int GetAge() { return age; }
	void SetOtherInf(const char* O) {
		sizeOtherInfo = (int)strlen(O) + 1;
		otherInfo = new char[sizeOtherInfo];
		strcpy(otherInfo, O);
	}
	char* GetOtherInf() { return otherInfo; }
	Human CreateHuman() {//������� ��������
		cout << "������� ���, ������� � �������� ������: ";
		cin.get(n, 255);
		cout << "�������(����� ������ ���): "; 	cin >> AGE; cin.ignore(32767, '\n');
		cout << "�������������� ����������: ";
		cin.get(O, 255);
		return Human(n, AGE, O);
	}
	void Print() {
		if (Name) {
			cout << "���: ";
			for (int i = 0; i < sizeName; i++) { cout << Name[i]; }
			cout << endl;
		}
		else { cout << "��� �����" << endl; }
		cout << "�������: "<< age<< endl; 
		if (otherInfo) {
			cout << "�������������� ����������: ";
			for (int i = 0; i < sizeOtherInfo; i++) { cout << otherInfo[i]; }
			cout << endl;
		}
		else { cout << "��� ����������" << endl; }
	}
	~Human() {
		if (Name != nullptr) {
			delete[] Name; Name = nullptr;
		}
		if (otherInfo != nullptr) {
			delete[] otherInfo; otherInfo = nullptr;
		}
	}
};
class Apartment {
	Human* X;
	int countHumans{ 0 };
public:
	int NumberAp{ 0 };
	Apartment(int NAp) { NumberAp = NAp; countHumans; X = nullptr; }
	Apartment() : countHumans{ 0 }, X{ nullptr } {}
	~Apartment() {
		if (X != nullptr) {
			delete[] X; X = nullptr;
		}
	}
	Human& operator[](int s) {
		return X[s];
	}
	void PrintAp() {
		cout << "�������� �����: " << NumberAp << endl;
		for (int i = 0; i < countHumans; i++) {
			X[i].Print(); 	cout << endl;
		}
	}
	void AddHuman(const Human& xz) {//��������� ��������
		if (countHumans == 0) {
			++countHumans;
			X = new Human[countHumans];
			X[0] = xz;
		}
		else {
			++countHumans;
			Human* Temp = new Human[countHumans];
			for (int i = 0; i < countHumans-1; i++) {Temp[i] = X[i];}
			Temp[countHumans - 1] = xz;
			delete[] X;
			X = Temp;
		}
	};
};
class Building {
	static const int sizeB = 10;
	Apartment Y[sizeB];
public:
	Building() : Y{ Apartment() } {}
	Apartment& operator[](int s) {
		return Y[s];
	}
	int IfApIsFull(int Xata) {// ���� �� ��� �������� � ����� �������
		for (int i = 0; i < sizeB; i++) {
			if (Xata == Y[i].NumberAp) return i+1;
		}
		return 0;
	}
	int IfApIsEmpty() {// ���� �� ������� ������ � �������
		for (int i = 0; i < sizeB; i++) {
			if (Y[i].NumberAp==0) return i + 1;
		}
		return 0;
	}
	void PrintBild() {
		for (int i = 0; i < sizeB; i++) {
			if (Y[i].NumberAp != 0) {
				Y[i].PrintAp(); cout << endl;
			}
		}
	}
};
int main() {
	setlocale(LC_ALL, "ru");
	Building One;
	int NumbAp{ 0 };
	int IndikVvoda{ 0 };
	int IndikVvoda2{ 0 };
	cout << "������� ��� �� 10 ������� ����� � ���������!" << endl;
	do {
		cout << "����� �������� ��������?"<<endl; 
		cout << "������� 0 ��� ���������� ���������" << endl;
		cout << "������� 11 ��� ������ ���� �������" << endl;
		cin >> IndikVvoda; cin.ignore(32767, '\n');
		if (IndikVvoda == 11) { system("cls"); One.PrintBild(); }
		else if (IndikVvoda < 0 || IndikVvoda>11) cout << "������ ������ ������� � ����� ���� ���" << endl;
		else if (IndikVvoda > 0 && IndikVvoda < 11){
			NumbAp = One.IfApIsFull(IndikVvoda);
			if (NumbAp) {
				system("cls");
				cout << "�������� ��� ��������, �������� ������ - ������� 1?" << endl;
				cout << "������� 0 ��� ��������" << endl;
				cin >> IndikVvoda2; cin.ignore(32767, '\n');
				if (IndikVvoda2 == 1) {
					Human xz;									
					One[NumbAp-1].AddHuman(xz.CreateHuman());
					cout << "������ ��������" << endl;
				}
			}
			else {
				system("cls");
				NumbAp = One.IfApIsEmpty();
				Human xz;
				One[NumbAp - 1] = Apartment(IndikVvoda);
				One[NumbAp-1].AddHuman(xz.CreateHuman());
				cout << "����� �������� ��������" << endl;
			}
		}
	} while (IndikVvoda != 0);
		cout << "����� �������! �������� � ��� ���" << endl;
	
	


}
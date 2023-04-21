#pragma once
#include <iostream>
#include <fstream>
#include<Windows.h>
using namespace std;

class man
{
	int age;
	char* name;
	char* suname;
public:
	man(char* n, char* s, int a) :name{ new char[strlen(n) + 1] },
		suname{ new char[strlen(s) + 1] },
		age{ a } {
		strcpy_s(name, strlen(n) + 1, n);
		strcpy_s(suname, strlen(s) + 1, s);

	};
	man();
	~man();
	void Put() {
		char temp[1024];
		cout << "веедите имя ";
		cin >> temp;
		if (name) delete[]name;
		name = new char[strlen(temp) + 1];
		strcpy_s(name, strlen(temp) + 1, temp);


		char temp[1024];
		cout << "веедите F ";
		cin >> temp;
		if (suname) delete[]name;
		suname = new char[strlen(temp) + 1];
		strcpy_s(suname, strlen(temp) + 1, temp);


		cout << " Age";
		cin >> age;

	}
	void Show() {
		cout << " Name" << name;
		cout << "\n Suname" << suname;
		cout << "\n Age" << age;
	}
	void SaveToFile() {
		int size;
		fstream f{ "man.txt ", ios::out | ios::binary | ios::app };// если в файле что то есть то мы дозапишем
		if (!f)cout << "ERROR ";

		f.write((char*)&age, sizeof(int));//записываем 
		size = strlen(name);
		f.write((char*)&size, sizeof(int));
		f.write(name, size*sizeof(char));

		//записываем 
		size = strlen(suname);
		f.write((char*)&size, sizeof(int));
		f.write(suname, size * sizeof(char));
		f.close();


	};
	static void LoadFromFile() {

		fstream f{ "man.txt ", ios::in | ios::binary | ios::app };// считываем 
		if (!f) cout << "ошибка  ";
		char* n, * s;
		int a;
		int temp;

		while (f.read((char*)&a, sizeof(int))){//открываем для чтения будем списывать пока биты не закончатся
			cout << " name ";
			f.read((char*)temp, sizeof(int));
			n = new char[temp + 1];
			f.read(n, temp * sizeof(char));
			n[temp] = '\0';
			cout << n << endl;


			cout << " suname ";
			f.read((char*)temp, sizeof(int));
			s = new char[temp + 1];
			f.read(s, temp * sizeof(char));
			s[temp] = '\0';
			cout << s << endl;
		}

	};

};


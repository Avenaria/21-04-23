
///потоки 

#include <iostream>
#include <fstream>
#include<Windows.h>
using namespace std;
//open(const char* filename, int mode, int proection);//передавать либо название или полны йпуть , режим, защита файла jnrhsnbt afqkf
//close();//закытие, сам очищает буфер, закрфвает потоки 
//read(char* buf, int len);//буфер куда нужно записать, лен  максимальная длинна символов которые из потока извлекаются в буфер баф
//write(const char* buf, int len);//запись из потокаб 
//
//
//get();// извлекает один символ из потока 
//get(char&);// какой именно симво лд нужно забрать из потока
//put(char);// помещает один символ в поток
//
//
//getline(char buf, int n, char c = '\n');// извлекает из потока определнной длины, пок ане найдет нужный1 символ 
//ignore(int n = 1, int d = EOF);//извлекает символны из потока, пока не встретит ограничитель д, или пока не извлечент н кол во символов
//gcount();// число символов извлеченных функциями выше
//peek();// находит симво но из потока не вытаскивае
//putback(char c);// помещает в поток символс , следующий извлекаемый из потока
//seekg(long pos);// ПОЗИЦИЯ ЧТЕНИЯ ИЗ ПОТОКА, ЧТО ПРИШЛО В ФУНКЦИЮ, возможно указать 2 параметр который укажит в какую сторону считывать
//seekp(long pos);// обсалютная позиция записи в потоке , 
//tellg();// текущая позиция чтени\ из потока
//tellp();// текущая позиция записи в поток




int main()
{
	setlocale(LC_ALL, " ");
	//cin//istream
		//cout//ostream
		//cerr//ostream ошибки \
	//clog //
	//fstream();//
	//fstream(const char* name,
	//	int mode,
	//	int = filebuf:operator)//
	//	fstream(int f)//дискрип
	//	fstream(int f, char* buf, // буфер int len////буфер )//дискрип+2
	//		modde : in - толкь чтение 
	//		out -только запись 
	//		ate-указатель на конец файла 
	//		app -  дописывает в конец файла 
	//		trunc- усекает до нулевой длины 
	//		_Nocreate - если файла нет будет ошибка открытия 
	//		_Norepleca -tckb ceotcndetn nj jib,rf
	//		binare - для двоичного обмена 


	char answer;
	const int massegCount = 8;
	int i, j;
	enum{CHOICE =3, INPUT_FILENAME, INPUT_DEMENSIONS, INPUT_ELEMENT, FILE_ERROR};
	char Msg[massegCount][50] = {
		"1 вывести данные из файла\n",
		"2 Записать данные в файл\n",
		"3  Выход из пр\n",
		"4  Ваш выбор ->\n",
		"Введите имя файла \n",
		" Введите размер матрици \n",
		" Введите эелементы матрицы\n",
		" невозможно октрыть файл \n"

	};
	do {
		for (i = 0; i < 4; i++) {
			cout << Msg[i];
			cin >> answer;
		}

	} while (answer < '1' || answer>'3');
		if (answer == 3) exit(0);

		char filename[50];
		int m, n;
		int num; 
		cout << "\n " << Msg[INPUT_FILENAME];
		cin >> filename;

		if (answer == '1') {
			ifstream inF( filename, ios::in | ios::_Nocreate );//как нужно открыть фал б обьявили обьект класса
			if (!inF) {
				cout << Msg[FILE_ERROR];
				exit(0);
			}
			inF >> m;//размер матрицы из файла
			inF >> n;


			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					inF >> num;//запись в нам
					cout << num << " ";//выводим что пришло 
				}

			}
			inF.close();
		}
		else {
			ofstream outF(filename, ios::out);// открываем для записи файл 
				if (!outF) {
					cout << Msg[FILE_ERROR];
					exit(0);
				}
			cout << Msg[INPUT_DEMENSIONS];
			cout << " m ="; cin >> m;
			cout << " n ="; cin >> n;
			outF << m << ' ' << n << '\n';
			cout << Msg[INPUT_ELEMENT];
			for (i = 0; i < m; i++) {
				for (j = 0; j < n; j++) {
					
					cout << " arr [" << i << "]";
					cin >> num;
					outF << num << " ";
				}
				outF << '\n';
			}

			outF.close();

		}




}




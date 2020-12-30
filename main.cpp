#include<iostream>
#include<string>
#include<fstream>
#include "aircraft.h"
#include<Windows.h>

/*Создать класс «Конвейер сборки летательных аппаратов», в результате работы которого мы можем получить: 
пассажирский самолет, боевой самолет, вертолет, квадрокоптер. Использовать паттерн «Строитель». 
Результат создания летательных аппаратов и все их характеристики (военный или гражданский, тип военного аппарата, тип гражданского аппарата, взлетная масса, тип двигателей, число двигателей, 
количество крыльев, расположение крыльев, тип шасси, скорость полета, по типу взлета и посадки, способ управления, экипаж 
(число человек), год производства, тип вооружения) записываются в разные выходные файлы, разделенные по типу летательного аппарата. Пользователь может вводить данные из консоли и загружать из файлов.*/

using namespace std;
int main(void)
{
	setlocale(LC_ALL, "rus");
	Director* director = new Director();
	fstream fc("saveCevilian.txt", ios_base::in);
	fstream fm("saveMilitary.txt", ios_base::in);
	fstream fh("saveHelocopter.txt", ios_base::in);
	fstream fq("saveQuadrocopter.txt", ios_base::in);
	bool fopen_error = false;
	if (!fc.is_open())
	{
		cerr << "Файл с кешем прошлых запусков не был открыт, создан новый файл с базой гражданской авиации..." << endl;
	}
	if (!fm.is_open())
	{
		cerr << "Файл с кешем прошлых запусков не был открыт, создан новый файл с базой военной авиации..." << endl;
	}
	if (!fc.is_open())
	{
		cerr << "Файл с кешем прошлых запусков не был открыт, создан новый файл с базой вертолетов..." << endl;
	}
	if (!fm.is_open())
	{
		cerr << "Файл с кешем прошлых запусков не был открыт, создан новый файл с базой квадрокоптеров..." << endl;
	}
	while (1)
	{
		cout << "Введите требуемый для создания объект: " << endl;
		cout << "|1| - гражданский самолет;" << endl;
		cout << "|2| - военный самолет;" << endl;
		cout << "|3| - вертолет;" << endl;
		cout << "|4| - квадрокоптер;" << endl;
		cout << "|5| - Загрузить базу гражданских самолетов" << endl;
		cout << "|6| - Загрузить базу военных самолетов" << endl;
		cout << "|7| - Загрузить базу вертолетов" << endl;
		cout << "|8| - Загрузить базу квадрокоптеров" << endl;
		cout << "|0| - Выход;" << endl;
		int ans;
		cin >> ans;

		switch (ans)
		{
		case 0:
		{
			cout << "Работа успешно окончена, осуществляется выход из программы..." << endl;
			cin.get(); cin.get(); return 0;
		}
		case 1:
		{
			CevilianBuilder* c = new CevilianBuilder();
			director->setBuilder(c);
			aircraft* AircraftObject = director->buildAircraft();
			AircraftObject->getAircraft(cout);
			fc.close();
			fc.open("saveCevilian.txt", ios_base::app);
			AircraftObject->getAircraft(fc);
			delete AircraftObject;
			break;
		}
		case 2:
		{
			MilitaryBuilder* c = new MilitaryBuilder();
			director->setBuilder(c);
			aircraft* AircraftObject = director->buildAircraft();
			AircraftObject->getAircraft(cout);
			fm.close();
			fm.open("saveMilitary.txt", ios_base::app);
			AircraftObject->getAircraft(fm);
			delete AircraftObject;
			break;
		}
		case 3:
		{
			helicopterBuilder* c = new helicopterBuilder();
			director->setBuilder(c);
			aircraft* AircraftObject = director->buildAircraft();
			AircraftObject->getAircraft(cout);
			fh.close();
			fh.open("saveHelocopter.txt", ios_base::app);
			AircraftObject->getAircraft(fh);
			delete AircraftObject;
			break;
		}
		case 4:
		{
			quadrocopterBuilder* c = new quadrocopterBuilder();
			director->setBuilder(c);
			aircraft* AircraftObject = director->buildAircraft();
			AircraftObject->getAircraft(cout);
			fq.close();
			fq.open("saveQuadrocopter.txt", ios_base::app);
			AircraftObject->getAircraft(fq);
			delete AircraftObject;
			break;
		}
		case 5:
		{
			string fs;
			cout << endl;
			fc.close();
			fc.open("saveCevilian.txt", ios_base::in);
			if (!fc.is_open())
			{
				cerr << "Непредвиденная ошибка открытия файла, создайте новый гражданский самолет, чтобы создать новый файл..." << endl;
			}
			getline(fc, fs);
			while (!fs.empty())
			{
				cout << fs << endl;
				getline(fc, fs);
			}
			cout << endl;
			break;
		}
		case 6:
		{
			string fs;
			cout << endl;
			fm.close();
			fm.open("saveMilitary.txt", ios_base::in);
			if (!fm.is_open())
			{
				cerr << "Непредвиденная ошибка открытия файла, создайте новый военный самолет, чтобы создать новый файл..." << endl;
			}
			getline(fm, fs);
			while (!fs.empty())
			{
				cout << fs << endl;
				getline(fm, fs);
			}
			cout << endl;
			break;
		}
		case 7:
		{
			string fs;
			cout << endl;
			fh.close();
			fh.open("saveHelocopter.txt", ios_base::in);
			if (!fh.is_open())
			{
				cerr << "Непредвиденная ошибка открытия файла, создайте новый вертолет, чтобы создать новый файл..." << endl;
			}
			getline(fh, fs);
			while (!fs.empty())
			{
				cout << fs << endl;
				getline(fh, fs);
			}
			cout << endl;
			break;
		}
		case 8:
		{
			string fs;
			cout << endl;
			fq.close();
			fq.open("saveQuadrocopter.txt", ios_base::in);
			if (!fq.is_open())
			{
				cerr << "Непредвиденная ошибка открытия файла, создайте новый квадрокоптер, чтобы создать новый файл..." << endl;
			}
			getline(fq, fs);
			while (!fs.empty())
			{
				cout << fs << endl;
				getline(fq, fs);
			}
			cout << endl;
			break;
		}
		default:
			cerr << "Некорректный ввод." << endl;
		}
		cin.get();
		cin.get();
		system("cls");
	}
	return 0;
}

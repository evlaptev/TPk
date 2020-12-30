#include "aircraft.h"


//методы класса aircraf 
void aircraft::aircraft::setType(string in)
{
	type = in;
}
void aircraft::setMass(float in)
{
	max_mass = in;
}
void aircraft::setET(string in)
{
	ET = in;
}
void aircraft::setCE(int in)
{
	CE = in;
}
void aircraft::setYear(int in)
{
	year = in;
}
void aircraft::setCW(int in)
{
	CW = in;
}
void aircraft::setLocation(int in)
{
	location = in;
}
void aircraft::setChassis(int in)
{
	chassis_type = in;
}
void aircraft::setSpeed(float in)
{
	maxSpeed = in;
}
void aircraft::setRise(int in) //steering_type
{
	riseType = in;
}
void aircraft::setLanding(int in)
{
	landing_type = in;
}
void aircraft::setCrew(int in)
{
	crew = in;
}
void aircraft::setGun(int in)
{
	gun_type = in;
}
void aircraft::setControl(int in)
{
	control_method = in;
}
//вывод всех полей класса aircraft
void aircraft::getAircraft(ostream& out)
{
	out << "Информация по летательному аппарту:" << endl;
	out << "Тип ЛА: " + type << endl;
	out << "Максимальная взлетная масса: " << max_mass << "(т)" << endl;
	out << "Тип двигателя: " << ET << endl;
	out << "Количество двигателей: " << CE << endl;
	out << "Год выпуска: " << year << "г." << endl;
	out << "Количество крыльев: " << CW << endl;
	out << "Максимальная скорость: " << maxSpeed << endl;
	out << "Экипаж: " << crew << endl;
	//вывод расположения крыльев
	out << "Расположение крыльев: ";
	switch (location)
	{
	case 0:
	{
		out << "Низкопланы" << endl;
		break;
	}
	case 1:
		out << "Среднепланы" << endl;
		break;
	case 2:
		out << "Высокопланы" << endl;
		break;
	default:
		cerr << "Некорректный тип пулевого управления." << endl;
	}
	cout << endl;

	//вывод типа шасси
	out << "Тип шасси: ";
	switch (chassis_type)
	{
	case 0:
	{
		out << "Колёсный" << endl;
		break;
	}
	case 1:
		out << "Лыжный" << endl;
		break;
	case 2:
		out << "Поплавковый" << endl;
		break;
	default:
		cerr << "Некорректный тип пулевого управления." << endl;
	}
	cout << endl;
	//вывода типа взлета 
	out << "Тип взлета: ";
	switch (riseType)
	{
	case 0:
	{
		out << "с тормозов" << endl;
		break;
	}
	case 1:
		out << "с разбега" << endl;
		break;
	case 2:
		out << "вертикальный" << endl;
		break;
	case 3:
		out << "со спецоборудованием" << endl;
		break;
	default:
		cerr << "Некорректный тип пулевого управления." << endl;
	}
	cout << endl;
	//вид типа посадки
	out << "Тип посадки: ";
	switch (landing_type)
	{
	case 0:
	{
		out << "в авторежиме" << endl;
		break;
	}
	case 1:
		out << "в директорном режиме" << endl;
		break;
	case 2:
		out << "по ОСП" << endl;
		break;
	case 3:
		out << "по КГС" << endl;
		break;
	default:
		cerr << "Некорректный тип пулевого управления." << endl;
	}
	cout << endl;
	//вывод метода контроля
	out << "По методу контроля: ";
	if (control_method == 0)
	{
		out << "БПЛА" << endl;
	}
	else { out << "ручное управление" << endl; }
	//вывод типа оружия
	out << "Вооружение: ";
	switch (gun_type)
	{
	case 0:
	{
		out << "нет вооружения" << endl;
		break;
	}
	case 1:
		out << "ракеты" << endl;
		break;
	case 2:
		out << "бомбы" << endl;
		break;
	case 3:
		out << "пулеметы" << endl;
		break;
	default:
		cerr << "Некорректный тип пулевого управления." << endl;
	}
	cout << endl;
}

// методы класса CeviliaBuilder

void CevilianBuilder::TypeBuild() 
{
point:
	try {
		string in;
		cout << "Введите тип гражданского самолета: ";
		cin.get();
		getline(cin, in);
		cout << endl;
		v->setType(in);
		for (int i = 0; i < in.length(); i++)
		{
			if (in[i] > 127 || in[i] < 0 || in.empty()) throw "Были введены некорректные данные.";
		}
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
		goto point;
	}
}

void CevilianBuilder::MassBuild()  {
point:
	try {
		float in;
		cout << "Введите массу гражданского самолета(т): ";
		cin >> in;
		cout << endl;
		v->setMass(in);
		if (in <= 0) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}

void CevilianBuilder::ETBuild()  {
point:
	try {
		string in;
		cout << "Введите тип двигателя гражданского самолета: ";
		cin.get();
		getline(cin, in);
		cout << endl;
		v->setET(in);
		for (int i = 0; i < in.length(); i++)
		{
			if (in[i] > 127 || in[i] < 0 || in.empty()) throw "Были введены некорректные данные.";
		}
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
		goto point;
	}
}

void CevilianBuilder::CEBuild()  {

point:
	try {
		int in;
		cout << "Введите количество двигателей: ";
		cin >> in;
		cout << endl;
		v->setCE(in);
		if (in < 1 && in > 10) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}

void CevilianBuilder::YearBuild()  {
point:
	try {
		int in;
		cout << "Введите год производства: ";
		cin >> in;
		cout << endl;
		v->setYear(in);
		if (in < 1950 || in > 2020) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}

void CevilianBuilder::CWBuild()  {
point:
	try {
		int in;
		cout << "Введите количество крыльев: ";
		cin >> in;
		cout << endl;
		v->setCW(in);
		if (in < 0 || in >6 || in % 2 == 1) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}

void CevilianBuilder::LocationBuild()  {
point:
	try {
		int in;
		cout << "Введите нахождение крыльев: " << endl;
		cout << "|0| - низкопланы; \n |1| - среднепланы; \n |2| - высокопланы;" << endl;
		cin >> in;
		cout << endl;
		v->setLocation(in);
		if (in < 0 || in > 2) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}

void CevilianBuilder::ChassisBuild()  {
point:
	try {
		int in;
		cout << "Введите тип шасси: " << endl;
		cout << "|0| - колесное; \n |1| - лыжное; \n |2| - поплавковое;" << endl;
		cin >> in;
		cout << endl;
		v->setChassis(in);
		if (in < 0 || in > 2) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}

void CevilianBuilder::SpeedBuild()  {
point:
	try {
		float in;
		cout << "Введите максимальную скорость гражданского самолета (км/ч): ";
		cin >> in;
		cout << endl;
		v->setSpeed(in);
		if (in < 100 || in > 2000) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}

void CevilianBuilder::RiseBuild()  {
point:
	try {
		int in;
		cout << "Введите тип взлета самолета: " << endl;
		cout << "|0| - с тормозов; \n |1| - с разбега;\n |2| - вертикальный;\n |3| -со спец оборудованием;" << endl;
		cin >> in;
		cout << endl;
		v->setRise(in);
		if (in < 0 || in > 3) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}

void CevilianBuilder::LandingBuild()  {
point:
	try {
		int in;
		cout << "Введите тип посадки гражданского самолета: " << endl;
		cout << "|0| - в авторежиме;\n |1| - в директорном режиме;\n |2| - по ОСП;\n |3| - по КГС" << endl;
		cin >> in;
		cout << endl;
		v->setLanding(in);
		if (in < 0 || in > 3) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}

void CevilianBuilder::CrewBuild() 
{
point:
	try {
		int in;
		cout << "Введите максимальное количество человек: ";
		cin >> in;
		cout << endl;
		v->setCrew(in);
		if (in < 0) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}

void CevilianBuilder::ControlBuild()
{
point:
	try {
		int in;
		cout << "Введите тип управления летательным аппаратом: " << endl;
		cout << "|0| - в режиме БПЛА;\n |1| - в ручном режиме;" << endl;
		cin >> in;
		cout << endl;
		v->setControl(in);
		if (in != 0 && in != 1) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}
void CevilianBuilder::GunBuild() 
{
	int in = 0;
	cout << "У гражданских самолетов нет вооружения. ";
	cout << endl;
	v->setGun(in);
}


//методы класса militaryBuilder

void MilitaryBuilder::TypeBuild() 
{
point:
	try {
		string in;
		cout << "Введите тип военного самолета: ";
		cin.get();
		getline(cin, in);
		cout << endl;
		v->setType(in);
		for (int i = 0; i < in.length(); i++)
		{
			if (in[i] > 127 || in[i] < 0 || in.empty()) throw "Были введены некорректные данные.";
		}
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
		goto point;
	}
}

void MilitaryBuilder::MassBuild()  {
point:
	try {
		float in;
		cout << "Введите массу военноо самолета(т): ";
		cin >> in;
		cout << endl;
		v->setMass(in);
		if (in < 0) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}

void MilitaryBuilder::ETBuild()  {
point:
	try {
		string in;
		cout << "Введите тип двигателя военного самолета: ";
		cin.get();
		getline(cin, in);
		cout << endl;
		v->setET(in);
		for (int i = 0; i < in.length(); i++)
		{
			if (in[i] > 127 || in[i] < 0 || in.empty()) throw "Были введены некорректные данные.";
		}
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
		goto point;
	}
}

void MilitaryBuilder::CEBuild()  {
point:
	try {
		int in;
		cout << "Введите количество двигателей: ";
		cin >> in;
		cout << endl;
		v->setCE(in);
		if (in < 1 && in > 10) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}

void MilitaryBuilder::YearBuild()  {
point:
	try {
		int in;
		cout << "Введите год производства: ";
		cin >> in;
		cout << endl;
		v->setYear(in);
		if (in < 1950 || in > 2020) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}

void MilitaryBuilder::CWBuild()  {
point:
	try {
		int in;
		cout << "Введите количество крыльев: ";
		cin >> in;
		cout << endl;
		v->setCW(in);
		if (in < 0 || in >6 || in % 2 == 1) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}

void MilitaryBuilder::LocationBuild()  {
point:
	try {
		int in;
		cout << "Введите нахождение крыльев: " << endl;
		cout << "|0| - низкопланы; \n |1| - среднепланы; \n |2| - высокопланы;" << endl;
		cin >> in;
		cout << endl;
		v->setLocation(in);
		if (in < 0 || in > 2) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}

void MilitaryBuilder::ChassisBuild()  {
point:
	try {
		int in;
		cout << "Введите тип шасси: " << endl;
		cout << "|0| - колесное; \n |1| - лыжное; \n |2| - поплавковое;" << endl;
		cin >> in;
		cout << endl;
		v->setChassis(in);
		if (in < 0 || in > 2) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}

void MilitaryBuilder::SpeedBuild()  {
point:
	try {
		float in;
		cout << "Введите максимальную скорость военного самолета (км/ч): ";
		cin >> in;
		cout << endl;
		v->setSpeed(in);
		if (in < 100 || in > 2000) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}

void MilitaryBuilder::RiseBuild()  {
point:
	try {
		int in;
		cout << "Введите тип взлета самолета: " << endl;
		cout << "|0| - с тормозов; \n |1| - с разбега;\n |2| - вертикальный;\n |3| -со спец оборудованием;" << endl;
		cin >> in;
		cout << endl;
		v->setRise(in);
		if (in < 0 || in > 3) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}

void MilitaryBuilder::LandingBuild()  {
point:
	try {
		int in;
		cout << "Введите тип посадки гражданского самолета: " << endl;
		cout << "|0| - в авторежиме;\n |1| - в директорном режиме;\n |2| - по ОСП;\n |3| - по КГС" << endl;
		cin >> in;
		cout << endl;
		v->setLanding(in);
		if (in < 0 || in > 3) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}

void MilitaryBuilder::CrewBuild() 
{
point:
	try {
		int in;
		cout << "Введите максимальное количество человек: ";
		cin >> in;
		cout << endl;
		v->setCrew(in);
		if (in < 0) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}

void MilitaryBuilder::ControlBuild()
{
point:
	try {
		int in;
		cout << "Введите тип управления летательным аппаратом: " << endl;
		cout << "|0| - в режиме БПЛА;\n |1| - в ручном режиме;" << endl;
		cin >> in;
		cout << endl;
		v->setControl(in);
		if (in != 0 && in != 1) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}
void MilitaryBuilder::GunBuild() 
{
point:
	try {
		int in;
		cout << "Введите тип посадки гражданского самолета: " << endl;
		cout << "|0| - none;\n |1| - ракеты;\n |2| - бомбы;\n |3| - пулеметы" << endl;
		cin >> in;
		cout << endl;
		v->setGun(in);
		if (in < 0 || in > 3) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}


//методы класса helicopter

void helicopterBuilder::TypeBuild()
{
point:
	try {
		string in;
		cout << "Введите тип вертолета: ";
		cin.get();
		getline(cin, in);
		cout << endl;
		v->setType(in);
		for (int i = 0; i < in.length(); i++)
		{
			if (in[i] > 127 || in[i] < 0 || in.empty()) throw "Были введены некорректные данные.";
		}
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
		goto point;
	}
}
void helicopterBuilder::MassBuild() {
point:
	try {
		float in;
		cout << "Введите массу вертолета(т): ";
		cin >> in;
		cout << endl;
		v->setMass(in);
		if (in < 0) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}

void helicopterBuilder::ETBuild() {
point:
	try {
		string in;
		cout << "Введите тип двигателя вертолета: ";
		cin.get();
		getline(cin, in);
		cout << endl;
		v->setET(in);
		for (int i = 0; i < in.length(); i++)
		{
			if (in[i] > 127 || in[i] < 0 || in.empty()) throw "Были введены некорректные данные.";
		}
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
		goto point;
	}
}

void helicopterBuilder::CEBuild() {
point:
	try {
		int in;
		cout << "Введите количество двигателей: ";
		cin >> in;
		cout << endl;
		v->setCE(in);
		if (in < 1 && in > 10) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}

void helicopterBuilder::YearBuild() {
point:
	try {
		int in;
		cout << "Введите год производства: ";
		cin >> in;
		cout << endl;
		v->setYear(in);
		if (in < 1950 || in > 2020) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}

void helicopterBuilder::CWBuild() {
point:
	try {
		int in;
		cout << "Введите количество крыльев: ";
		cin >> in;
		cout << endl;
		v->setCW(in);
		if (in < 0 || in >6 || in % 2 == 1) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}

void helicopterBuilder::LocationBuild() {
point:
	try {
		int in;
		cout << "Введите нахождение крыльев: " << endl;
		cout << "|0| - низкопланы; \n |1| - среднепланы; \n |2| - высокопланы;" << endl;
		cin >> in;
		cout << endl;
		v->setLocation(in);
		if (in < 0 || in > 2) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}

void helicopterBuilder::ChassisBuild() {
point:
	try {
		int in;
		cout << "Введите тип шасси: " << endl;
		cout << "|0| - колесное; \n |1| - лыжное; \n |2| - поплавковое;" << endl;
		cin >> in;
		cout << endl;
		v->setChassis(in);
		if (in < 0 || in > 2) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}

void helicopterBuilder::SpeedBuild() {
point:
	try {
		float in;
		cout << "Введите максимальную скорость вертолета (км/ч): ";
		cin >> in;
		cout << endl;
		v->setSpeed(in);
		if (in < 100 || in > 2000) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}

void helicopterBuilder::RiseBuild() {
point:
	try {
		int in;
		cout << "Введите тип взлета самолета: " << endl;
		cout << "|0| - с тормозов; \n |1| - с разбега;\n |2| - вертикальный;\n |3| -со спец оборудованием;" << endl;
		cin >> in;
		cout << endl;
		v->setRise(in);
		if (in < 0 || in > 3) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}

void helicopterBuilder::LandingBuild() {
point:
	try {
		int in;
		cout << "Введите тип посадки гражданского самолета: " << endl;
		cout << "|0| - в авторежиме;\n |1| - в директорном режиме;\n |2| - по ОСП;\n |3| - по КГС" << endl;
		cin >> in;
		cout << endl;
		v->setLanding(in);
		if (in < 0 || in > 3) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}

void helicopterBuilder::CrewBuild()
{
point:
	try {
		int in;
		cout << "Введите максимальное количество человек: ";
		cin >> in;
		cout << endl;
		v->setCrew(in);
		if (in < 0) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}

void helicopterBuilder::ControlBuild()
{
point:
	try {
		int in;
		cout << "Введите тип управления летательным аппаратом: " << endl;
		cout << "|0| - в режиме БПЛА;\n |1| - в ручном режиме;" << endl;
		cin >> in;
		cout << endl;
		v->setControl(in);
		if (in != 0 && in != 1) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}
void helicopterBuilder::GunBuild()
{
	
	point:
		try {
			int in;
			cout << "Введите тип посадки гражданского самолета: " << endl;
			cout << "|0| - none;\n |1| - ракеты;\n |2| - бомбы;\n |3| - пулеметы" << endl;
			cin >> in;
			cout << endl;
			v->setGun(in);
			if (in < 0 || in > 3) throw "Были введены некорректные данные.";
		}
		catch (const char* a)
		{
			cerr << a << endl;
			cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
		}
}




	//методы класса quadrocopter
void quadrocopterBuilder::TypeBuild()
{
point:
	try {
		string in;
		cout << "Введите тип вертолета: ";
		cin.get();
		getline(cin, in);
		cout << endl;
		v->setType(in);
		for (int i = 0; i < in.length(); i++)
		{
			if (in[i] > 127 || in[i] < 0 || in.empty()) throw "Были введены некорректные данные.";
		}
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
		goto point;
	}
}
void quadrocopterBuilder::MassBuild() {
point:
	try {
		float in;
		cout << "Введите массу вертолета(т): ";
		cin >> in;
		cout << endl;
		v->setMass(in);
		if (in < 0) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}

void quadrocopterBuilder::ETBuild() {
point:
	try {
		string in;
		cout << "Введите тип двигателя вертолета: ";
		cin.get();
		getline(cin, in);
		cout << endl;
		v->setET(in);
		for (int i = 0; i < in.length(); i++)
		{
			if (in[i] > 127 || in[i] < 0 || in.empty()) throw "Были введены некорректные данные.";
		}
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
		goto point;
	}
}

void quadrocopterBuilder::CEBuild() {
point:
	try {
		int in;
		cout << "Введите количество двигателей: ";
		cin >> in;
		cout << endl;
		v->setCE(in);
		if (in < 1 && in > 10) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}

void quadrocopterBuilder::YearBuild() {
point:
	try {
		int in;
		cout << "Введите год производства: ";
		cin >> in;
		cout << endl;
		v->setYear(in);
		if (in < 1950 || in > 2020) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}

void quadrocopterBuilder::CWBuild() {
point:
	try {
		int in;
		cout << "Введите количество крыльев: ";
		cin >> in;
		cout << endl;
		v->setCW(in);
		if (in < 0 || in >6 || in % 2 == 1) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}

void quadrocopterBuilder::LocationBuild() {
point:
	try {
		int in;
		cout << "Введите нахождение крыльев: " << endl;
		cout << "|0| - низкопланы; \n |1| - среднепланы; \n |2| - высокопланы;" << endl;
		cin >> in;
		cout << endl;
		v->setLocation(in);
		if (in < 0 || in > 2) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}

void quadrocopterBuilder::ChassisBuild() {
point:
	try {
		int in;
		cout << "Введите тип шасси: " << endl;
		cout << "|0| - колесное; \n |1| - лыжное; \n |2| - поплавковое;" << endl;
		cin >> in;
		cout << endl;
		v->setChassis(in);
		if (in < 0 || in > 2) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}

void quadrocopterBuilder::SpeedBuild() {
point:
	try {
		float in;
		cout << "Введите максимальную скорость вертолета (км/ч): ";
		cin >> in;
		cout << endl;
		v->setSpeed(in);
		if (in < 100 || in > 2000) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}

void quadrocopterBuilder::RiseBuild() {
point:
	try {
		int in;
		cout << "Введите тип взлета самолета: " << endl;
		cout << "|0| - с тормозов; \n |1| - с разбега;\n |2| - вертикальный;\n |3| -со спец оборудованием;" << endl;
		cin >> in;
		cout << endl;
		v->setRise(in);
		if (in < 0 || in > 3) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}

void quadrocopterBuilder::LandingBuild() {
point:
	try {
		int in;
		cout << "Введите тип посадки гражданского самолета: " << endl;
		cout << "|0| - в авторежиме;\n |1| - в директорном режиме;\n |2| - по ОСП;\n |3| - по КГС" << endl;
		cin >> in;
		cout << endl;
		v->setLanding(in);
		if (in < 0 || in > 3) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}

void quadrocopterBuilder::CrewBuild()
{
point:
	try {
		int in;
		cout << "Введите максимальное количество человек: ";
		cin >> in;
		cout << endl;
		v->setCrew(in);
		if (in < 0) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}

void quadrocopterBuilder::ControlBuild()
{
point:
	try {
		int in;
		cout << "Введите тип управления летательным аппаратом: " << endl;
		cout << "|0| - в режиме БПЛА;\n |1| - в ручном режиме;" << endl;
		cin >> in;
		cout << endl;
		v->setControl(in);
		if (in != 0 && in != 1) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}
void quadrocopterBuilder::GunBuild()
{

point:
	try {
		int in;
		cout << "Введите тип посадки гражданского самолета: " << endl;
		cout << "|0| - none;\n |1| - ракеты;\n |2| - бомбы;\n |3| - пулеметы" << endl;
		cin >> in;
		cout << endl;
		v->setGun(in);
		if (in < 0 || in > 3) throw "Были введены некорректные данные.";
	}
	catch (const char* a)
	{
		cerr << a << endl;
		cerr << "Попробуйте ввести данные еще раз. " << endl; goto point;
	}
}

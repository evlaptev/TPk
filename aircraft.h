#pragma once
#include<iostream>
#include<string>
using namespace std;
/*
(военный или гражданский, тип военного аппарата, тип гражданского аппарата, взлетная масса, тип двигателей, число двигателей, 
количество крыльев, расположение крыльев, тип шасси, скорость полета, по типу взлета и посадки, способ управления, экипаж 
(число человек), год производства, тип вооружения) */
class aircraft
{
protected:
	string type;		// тип летательного объекта
	float max_mass= -1;		//максимальная взлетная масса
	string ET;			//тип двигателя
	int CE = -1;		//count of engine количество двигателей
	int CW = -1;		//count of wings
	int location = -1;		//расположение крыльев (низкопланы - 0, среднепланы - 1, высокопланы - 2)
	int chassis_type = -1;	// типы шасси (0 - колесное, 1 - лыжное, 2 - поплавковое)
	float maxSpeed = -1;		// размеры, видимо, имеется ввиду габариты, для простоты будет объем ТС
	int riseType = -1;		// тип взлета (0 - с тормозов, 1 - с разбега, 2 - вертикальный, 3 -со спец оборудованием)
	int landing_type = -1;	// тип посадки (0 - в авторежиме, 1 - в директорном режиме, 2 - по ОСП, 3 - по КГС)
	int control_method = -1; //0 - БПЛА, 1 - ручной по способу управления
	int crew = -1;			// экипаж - коичество человек
	int year = -1;			//год производства
	int gun_type = -1;		//тип вооружения 0- none 1 - ракеты 2 - бомбы 3 - пулеметы

public:
	//здесь пошли сеты для свойств объекта
	void setType(string in);
	void setMass(float in);
	void setET(string in);
	void setCE(int in);
	void setYear(int in);
	void setCW(int in);
	void setLocation(int in);
	void setChassis(int in);
	void setSpeed(float in);
	void setRise(int in);
	void setLanding(int in);
	void setCrew(int in);
	void setGun(int in);
	void setControl(int in);
	//вывод всех полей 
	void getAircraft(ostream& out);
};

class AircraftBuilder // строитель основного объекта
{
protected:
	aircraft* v; // экземпляр основного объекта

public:
	aircraft* createAircraft()
	{
		v = new aircraft();
		return v;
	}
	virtual void TypeBuild() =0;
	virtual void MassBuild() =0;
	virtual void ETBuild() =0;
	virtual void CEBuild() =0;
	virtual void YearBuild() =0;
	virtual void CWBuild() =0;
	virtual void LocationBuild() =0;
	virtual void ChassisBuild() =0;
	virtual void SpeedBuild() =0;
	virtual void RiseBuild() =0; 
	virtual void LandingBuild() =0;
	virtual void CrewBuild() =0;
	virtual void GunBuild() =0;
	virtual void ControlBuild() =0;
	aircraft* getAircraft()
	{
		return v;
	}
	friend class CevilianBuilder;
	friend class MilitaryBuilder;
	~AircraftBuilder()
	{
		delete v;
	}
};

class CevilianBuilder :
	public AircraftBuilder
{
	void TypeBuild() override;

	void MassBuild() override;

	void ETBuild() override;

	void CEBuild() override;

	void YearBuild() override;

	void CWBuild() override;

	void LocationBuild() override;

	void ChassisBuild() override;

	void SpeedBuild() override;

	void RiseBuild() override;

	void LandingBuild() override;

	void CrewBuild() override;
	
	void ControlBuild();
	void GunBuild() override;
};

class MilitaryBuilder :
	public AircraftBuilder
{
	void TypeBuild() override
	{
	point:
		try {
			string in;
			cout << "Введите тип военного самолета: ";
			cin.get();
			getline(cin,in);
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

	void MassBuild() override {
	point:
		try {
			float in;
			cout << "Введите массу военного самолета(т): ";
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

	void ETBuild() override {
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

	void CEBuild() override {
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

	void YearBuild() override {
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

	void CWBuild() override {
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

	void LocationBuild() override {
	point:
		try {
			int in;
			cout << "Введите нахождение крыльев: "<<endl;
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

	void ChassisBuild() override {
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

	void SpeedBuild() override {
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

	void RiseBuild() override {
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

	void LandingBuild() override {
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

	void CrewBuild() override
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

	void ControlBuild()
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
	void GunBuild() override
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
};

class helicopterBuilder :
	public AircraftBuilder
{
	void TypeBuild() override;

	void MassBuild() override;

	void ETBuild() override;

	void CEBuild() override;

	void YearBuild() override;

	void CWBuild() override;

	void LocationBuild() override;

	void ChassisBuild() override;

	void SpeedBuild() override;

	void RiseBuild() override;

	void LandingBuild() override;

	void CrewBuild() override;

	void ControlBuild()override;
	void GunBuild() override;
};

class quadrocopterBuilder :
	public AircraftBuilder
{
	void TypeBuild() override;

	void MassBuild() override;

	void ETBuild() override;

	void CEBuild() override;

	void YearBuild() override;

	void CWBuild() override;

	void LocationBuild() override;

	void ChassisBuild() override;

	void SpeedBuild() override;

	void RiseBuild() override;

	void LandingBuild() override;

	void CrewBuild() override;

	void ControlBuild();
	void GunBuild() override;
};

class Director
{
	AircraftBuilder* builder;

public:
	void setBuilder(AircraftBuilder* b)
	{
		builder = b;
	}

	aircraft* buildAircraft()
	{
		builder->createAircraft();
		builder->TypeBuild();
		builder->MassBuild();
		builder->ETBuild();
		builder->CEBuild();
		builder->YearBuild();
		builder->CWBuild();
		builder->LocationBuild();
		builder->ChassisBuild();
		builder->SpeedBuild();
		builder->RiseBuild(); 
		builder->LandingBuild();
		builder->CrewBuild();
		builder->GunBuild();
		builder->ControlBuild();
		aircraft* v = builder->getAircraft();
		return v;
	}
	~Director()
	{
		delete builder;
	}
};

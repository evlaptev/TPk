#pragma once
#include<iostream>
#include<string>
using namespace std;

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

#include <iostream>
#include <string>
class vehicle
{
private:
	std::string m_brand;
public:
	vehicle(const std::string& brand): m_brand(brand) 
	{
		std::cout << "vehicle ctor \n";
	}
	const std::string& getbrand()
	{
		return m_brand;
	}
	virtual ~vehicle()
	{
		std::cout << "dtor vehicle\n";
	}
	virtual void getnoise()
	{
		std::cout << "?????" << std::endl;
	}
	virtual void getclass()
	{
		std::cout << "vehicle \n";
	}
};
class wheel
{
public:
	wheel()
	{
		std::cout << "wheel ctor\n";
	}
	~wheel()
	{
		std::cout << "wheel dtor\n";
	}
	
};
class plane : public vehicle
{
public:
	plane(const std::string& brand) : vehicle(brand) 
	{
		std::cout << "plane ctor \n ";
	}
	~plane()
	{
		std::cout << "dtor plane \n";
	}
	void getnoise()
	{
		std::cout << "viouummm" << std::endl;
	}
	void getclass()
	{
		std::cout << "plane \n";
	}
};
class car : public vehicle ,public wheel 
{
public:
	car(const std::string& brand) : vehicle(brand), wheel() 
	{
		std::cout << "Car ctor\n ";
	}

	~car()
	{
		std::cout << "dtor car\n";
	}
	void getnoise()
	{
		std::cout << "vroum" << std::endl;
	}
	void getclass()
	{
		std::cout << "car \n";
	}
};
vehicle* createvehicle()
{
	std::string type;
	std::cout << "vehicle type : ";
	std::cin >> type;
	if (type == "car")
		return new  car{ "" };
	else if (type == "plane")
		return new plane{ "" };
	else
		return nullptr;

}
int main()
{
	vehicle* v = createvehicle();
	v->getnoise();
	v->getclass();
	delete v;
}

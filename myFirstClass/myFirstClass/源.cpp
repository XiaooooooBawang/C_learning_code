#include<iostream>
#include<string>
class Animal
{
public:
	std::string mouth;
	void eat();
	void sleep();
	void drool();
	Animal();
	~Animal();

private:

};

Animal::Animal()
{
}

Animal::~Animal()
{
}
class Pig :public Animal
{
public:
	void climb();
};
class Turtle :public Animal
{
public:
	void swim();
};
void Animal::eat()
{
	std::cout << "I'm easting" << std::endl;
}
void Animal::sleep()
{
	std::cout << "I'm sleeping" << std::endl;
}
void Animal::drool()
{
	std::cout << "I'm drooling" << std::endl;
}
void Pig::climb()
{
	std::cout << "I'm climbing" << std::endl;
}
void Turtle::swim()
{
	std::cout << "I'm swimming" << std::endl;
}

int main()
{
	Pig pig;
	Turtle turtle;
	pig.eat();
	turtle.eat();
	pig.climb();
	turtle.swim();
	return 0;
}
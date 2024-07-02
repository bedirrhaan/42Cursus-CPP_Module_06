#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

Base * generate(void)
{
	std::srand(time(NULL));
	int i = std::rand() % 3;
	std::cout << "Created: ";
	if (i == 0)
	{
		std::cout << "A" << std::endl;
		return (new A);
	}
	else if (i == 1)
	{
		std::cout << "B" << std::endl;
		return (new B);
	}
	else
	{
		std::cout << "C" << std::endl;
		return (new C);
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Pointer identify: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Pointer identify: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Pointer identify: C" << std::endl;
}


void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		std::cout << "Reference identify: A" << std::endl;
		(void)a;
	}
	catch (std::exception &e)
	{
		try
		{
			B &b = dynamic_cast<B&>(p);
			std::cout << "Reference identify: B" << std::endl;
			(void)b;
		}
		catch (std::exception &e)
		{
			try
			{
				C &c = dynamic_cast<C&>(p);
				std::cout << "Reference identify: C" << std::endl;
				(void)c;
			}
			catch (std::exception &e)
			{
				std::cout << "Error" << std::endl;
			}
		}
	}
}


int main()
{

	Base *p = generate();
	identify(p);
	identify(*p);
	delete p;
	return (0);

}
#include <iostream>
#include "../TemplateVector/Vector.h"
#include <initializer_list>

using namespace Miit::Vector;
int main()
{
	try
	{
		Vector<int> vector1{ 1, 2,3,4,5 };
		Vector<int> vector2{ 2, 3 ,4, 5 };
		//std::cout << vector1 << std::endl;
		//std::cout << vector2 << std::endl;
	}
	catch (const std::exception& error)
	{
		std::cout << error.what();
	}
	return 0;
}
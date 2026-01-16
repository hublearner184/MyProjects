#include <iostream>
int main()
{
	char* buffer = new char[8];
	memset(buffer, 0, 8);
	char** ptr = &buffer;

	delete buffer;
	std::cin.get();
}
#include <iostream>
class Singleton
{
private:
	static Singleton* s_Instance;
public:
	static Singleton& Get() { return *s_Instance; }

	void Hello(){}
};
/*int s_Variable = 10;

struct Entity
{
	static int x, y;
	void Print()
	{
		std::cout << x << "," << y << std::endl;
	}
};
int Entity::x;
int Entity::y;
class Log
{
public:
	const int LogLevelError = 0;
	const int LogLevelWarning = 1;
	const int LogLevelInfo = 2;
private:
	int m_LogLevel = LogLevelInfo;
public:
	void SetLevel(int level)
	{
		m_LogLevel = level;

	}
	void Error(const char* message)
	{
		if (m_LogLevel >= LogLevelError)
			std::cout << "[ERROR]:" << message << std::endl;
	}
	void Warn(const char* message)
	{
		if (m_LogLevel >= LogLevelWarning)
			std::cout << "[WARNING]:" << message << std::endl;
	}
	void Info(const char* message)
	{
		if (m_LogLevel >= LogLevelInfo)
			std::cout << "[Info]:" << message << std::endl;
	}
};
*/
Singleton* Singleton::s_Instance = nullptr;

int main()
{
	/*Log log;
	log.SetLevel(log.LogLevelInfo);
	log.Warn("Hello!");
	log.Error("Hello!");
	log.Info("Hello!");
	std::cout << "s_Variable" << std::endl;
	Entity e;
	e.x = 2;
	e.y = 3;

	Entity e1;
	e1.x = 5;
	e1.y = 8;
	e.Print();
	e1.Print();*/
	Singleton::Get().Hello();
	std::cin.get();
}

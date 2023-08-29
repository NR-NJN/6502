#include <iostream>
#define Log(x) std::cout<<x<<std::endl
#define stay std::cin.get()
#define win_stay system("PAUSE")

class Entity
{
private:
	int x, y;
public:
	Entity(int x, int y) 
	{
		this->x = x;
		this->y = y;
	}
};
int main()
{
	int x = 90;
	int* y = &x;
	Log(y);
	stay;
	

}
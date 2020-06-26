#include<iostream>
using namespace std;

class Object{
	
	private:
		char c;
		int a;
		double b;
		char *pc;

	public:

		Object(): a(0), b(0)
		{
		
		}

		int getInt()
		{
			return a;
		}

		double getDouble()
		{
			return b;
		}

		char getChar()
		{
			return c;
		}

		char getStarChar()
		{
			return *pc;
		}

};

int main()

{
	Object *o = new Object();
	char pc = 'p';
	*((int *)o + 1) = 1;
	*((double*)o + 1) = 2;
	*((char*)o) = 'a';

	*((char**)o + 2) = &pc;

	cout << o->getInt() << endl;
	cout << o->getDouble() << endl;
	cout << o->getChar() << endl;
	cout << o->getStarChar() << endl;
		
	return 0;
}

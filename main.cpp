#include <iostream>
#include <fstream>

using namespace std;

void checkValidInput()
{
	if (cin.fail())
	{
		throw "Incorrect input";
	}
}

void checkValidParams(int n)
{
	if (n <= 0)
	{
		throw "Input correct data";
	}
}

void checkValidRange(int from, int to, int step)
{
	if (from >= to || step <= 0)
	{
		throw "Incorrect range";
	}
}

double calculate(int x, int n)
{
	double y = 0;

	if (x < 0)
	{

		for (int i = 1; i < n; i++)
		{
			double s = 0;

			for (int j = 1; j <= n; j++)
			{
				s += x - pow(i, 2) + j;
			}

			y += s;
		}

	}
	else
	{

		for (int i = 0; i < n; i++)
		{
			y += double((x - 1)) / (i + 1);
		}

	}

	return y;
}

void printInALoop(int n, int a, int b, int h, bool toWrite, ofstream& fout)
{
	checkValidRange(a, b, h);

	if (toWrite)
	{
		fout.open("results.txt");
	}

	for (int x = a; x < b; x += h)
	{
		double y = calculate(x, n);

		cout << "x=" << x << "; " << "y=" << y << endl;

		if (toWrite && fout.is_open())
		{
			fout << "x=" << x << "; " << "y=" << y << endl;
		}
	}
}

int main()
{
	int n, a, b, h;
	bool toWrite = 0;

	ofstream fout;

	try 
	{
		cout << "Enter n=";
		cin >> n;
		checkValidInput();
		checkValidParams(n);

		cout << "Enter a range (a, b)" << endl;
		cout << "Enter a=";
		cin >> a;
		checkValidInput();

		cout << "Enter b=";
		cin >> b;
		checkValidInput();

		cout << "Enter step h=";
		cin >> h;
		checkValidInput();

		cout << "Write the results of each step to a file - 1, do not write - 0: ";
		cin >> toWrite;
		checkValidInput();

		printInALoop(n, a, b, h, toWrite, fout);

		return 0;
	}
	catch (const char* ex)
	{
		cout << ex << endl;
		return -1;
	}
	catch (...)
	{
		cout << "Unknown error" << endl;
		return -2;
	}
}
#include<iostream>
#include<string>
using namespace std;

int main();

class DayOfYear
{
	int day;
	string month[12] = {"January", "February", "March", "April", "May",
						"June", "July", "August", "September", 
						"October", "November", "December"};
						
	public:
	DayOfYear(int day)
	{
		if(day > 0 && day <= 365)
		{
			this -> day = day;
		}
		else
		{
			cout << "Invalid Input" << endl << endl;
			main();
		}
	}					
	
	void printData()
	{
		int nDaysOfMonth [12] = {31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30};
		int totalDays = 365;
		int counter;
		
		for(int i = 11; i > 0; i--)
		{
			if(day <= totalDays)
			{
				counter = i;
				totalDays -= nDaysOfMonth[i];
			}
		}
		
		cout << "Day " << day;
		
		for(int j = 0; j < counter; j++)
		{
			int *ptrDate = &day;
			*ptrDate -= nDaysOfMonth[j];
		}
		
		cout << " would be " << month[counter] << " " << day;
	}
};

int main()
{
	int input;
	cout << "Enter the number of days: ";
	cin >> input;
	
	DayOfYear day(input);
	
	day.printData();
	
	return 0;
}

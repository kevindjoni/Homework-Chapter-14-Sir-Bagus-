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
	int nDaysOfMonth [12] = {31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30};					
						
	public:
	int counter;	
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
		int totalDays = 365;
		
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
	
	DayOfYear operator++()
	{
		++day;
		simplify();
		return *this;
	}
	
	DayOfYear operator--()
    {
        --day;
        --day;
        simplify();
        return *this;
    }
    
    int getDay()
    {
        return day;
    }

    string getMonth ()
    {
        return month[counter];
    }
    
    int simplify()
    {
    	if(day > nDaysOfMonth[counter])
    	{
    		day -= nDaysOfMonth[counter];
    		++counter;
		}
		else if(day <= 0)
		{
			--counter;
			if(counter == -1)
			{
				counter == 11;
			}
			day += nDaysOfMonth[counter];
		}
		else;
	}
};

int main()
{
	int input;
	cout << "Enter the number of days: ";
	cin >> input;
	
	DayOfYear day(input);
	
	day.printData();
	
	DayOfYear tomorrow(input);
	DayOfYear yesterday(input);
	
	tomorrow = ++day;
	yesterday = --day;
	
	cout << endl << "Tomorrow is " << tomorrow.getDay() << " " << tomorrow.getMonth();
    cout << endl << "Yesterday is " << yesterday.getDay() << " " << yesterday.getMonth(); 
	
	return 0;
}

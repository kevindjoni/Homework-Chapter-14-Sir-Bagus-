#include <iostream>
#include <string>
using namespace std;

int main();

class Numbers
{
	int number;
	string tens [8] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
	string lessThan20 [20] = {"zero", "one", "two", "three", "four", "five", 
							 "six", "seven", "eight", "nine", "ten", "eleven", 
							 "twelve", "thirteen", "fourteen", "fifteen", "sixteen", 
							 "seventeen", "eighteen", "nineteen"};
	string hundred = "hundred";
	string thousand = "thousand";
	
	public:
	Numbers(int number)
	{
		if(number >= 0 && number <= 9999)
		{
			this -> number = number;
		}
		else
		{
			cout << "Invalid Input" << endl;
			main();	
		}
	}
	
	void printData()
	{
    	if (number < 20)
        {
            cout << lessThan20[number];
        }
        else if (number >= 20 && number < 100)
        {
            int num = (number % 10);
            int ten = number/ 10 - 2;
            cout << tens[ten] << " " << lessThan20[num] << endl;
        }
        else if (number >= 100 && number<= 999)
        {
            if ((number%100) > 19)
            {
                int a = number/100;
                int b = (number%100)/10 - 2;
                int c = ((number%100)%10);
                cout << lessThan20[a] << " " << hundred << " and " << tens[b] << lessThan20 [c];
            }
			else
            {
                int a = number/100;
                int b = (number%100);
                cout << lessThan20[a] << " " << hundred << " and " << lessThan20 [b];
            }
        }
        else if (number >= 1000 && number <= 9999)
        {
            if (((number%1000)%100) > 19)
            {
                int a = number/1000;
                int b = ((number%1000)/100);
                int c = ((number%1000)%100)/10 - 2;
                int d = ((number%1000)%100)%10;
                cout << lessThan20[a] << " " << thousand << " " << lessThan20 [b] << " " << hundred << " " << tens[c] << " and " << lessThan20[d];
            }
			else
            {
                int a = number/1000;
                int b = ((number%1000)/100);
                int c = ((number%1000)%100);
                cout << lessThan20[a] << " " << thousand << " " << lessThan20 [b] << " " << hundred << " and " << lessThan20[c];
            }
        }
    }
};

int main()
{
	int input;
	
	cout << "Enter any number (from 0 to 9999) and i will display its English description: " << endl;
	cin >> input;
	
	Numbers printD(input);
	cout << endl << "Result" << endl;
	cout << "------" << endl;
	cout << "English Description: ";
	printD.printData();
	cout << endl;
	
	return 0;
}

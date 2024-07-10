// libraries
#include <iostream> 
#include <string>

// namespace
using namespace std;

// ****  FUNCTION HEADERS  ****

bool isInteger(string str);	
bool isDouble(string str);
int getMenuOption();
void getAndPrintStatistics();
void temperatureConversion();
void calcAndPrintCircleFacts();
void calcAndPrintFactorial();
void calcAndPrintWeightedAvg();
void calcAndPrintSingleInputFacts();
void calcAndPrintQuadraticFormula();
void calcAndPrintRectInGrid();

/*
	MAIN
*/
int main()
{
	int menu = 00;
	while (menu != 99)
	{
		menu = getMenuOption();
		switch (menu)
		{
		case 1:
			cout << "** Statistics **" << endl;
			getAndPrintStatistics();
			break;
		case 2:
			cout << "** Temperature Conversion **" << endl;
			temperatureConversion();
			break;
		case 3: 
			cout << "** Circle **" << endl;
			calcAndPrintCircleFacts();
			break;
		case 4:
			cout << "** Factorial **" << endl;
			calcAndPrintFactorial();
			break;
		case 5:
			cout << "** Weighted Average **" << endl;
			calcAndPrintWeightedAvg();
			break;
		case 6:
			cout << "** Single Number Input **" << endl;
			calcAndPrintSingleInputFacts();
			break;
		case 7: 
			cout << "** Quadratic Formula **" << endl;
			calcAndPrintQuadraticFormula();
			break;
		case 8:
			cout << "** Rectangle in grid **" << endl;
			calcAndPrintRectInGrid();
			break;
		}
		cout << "------------------------------" << endl;
	}

}

/*
	checks a string to see if it is an integer
	@param string to be checked
	@return bool (true if string is an integer)
*/
bool isInteger(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i])) { return false; }
	}
	return true;
}

/*
	checks a string to see if it is an double
	@param string to be checked
	@return bool (true if string is an double)
*/
bool isDouble(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]) && str[i] != '.') { return false; }
	}
	return true;
}

/*
	displays all available user functions, gets user selection choice
	@param none
	@return integer corresponding to the user selection
*/
int getMenuOption()
{
	// display menu options
	cout << "*** Menu ***" << endl;
	cout << "1) Statistics: sum, mean, number, range" << endl;
	cout << "2) Temperature: conversion, water's state of matter" << endl;
	cout << "3) Circle: radius, circumference, diameter" << endl;
	cout << "4) Factorial" << endl;
	cout << "5) Weighted Average" << endl;
	cout << "6) Single Number Input: number of digits, even/odd, postive/negative, prime/composite" << endl;
	cout << "7) Quadratic Formula" << endl;
	cout << "8) Rectangle in grid: area, if coordinate is inside, length of diagonal" << endl;
	cout << "9) Multiplication Table" << endl;
	cout << "10) Rectable: perimeter, area, diagonal" << endl;
	cout << "11) To the power: sqaures, cubes, squareroots" << endl; 
	cout << "12) Divisors" << endl;
	cout << "13) Seconds Conversions" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "99) Exit" << endl;
	
	// get user input
	string input = "a";
	while (!isInteger(input))
	{
		cout << "Choice: ";
		cin >> input;
	}
	return stoi(input);
}

/*
	allows unlimited entries from user, takes numbers and finds sum, count, min, max, range, mean || MENU OPTION 1
	@param none
	@return none
*/
void getAndPrintStatistics()
{	
	double sum = 0;
	int count = 0;
	double min = 0;
	double max = 0;
	while (true)
	{
		// get input
		string input;
		cout << "Enter a number (to quit, enter a letter): ";
		cin >> input;
		
		// check input
		bool dubCheck= isDouble(input);
		if (!dubCheck) { cout << "Invalid input" << endl;  break; }
		else
		{
			// convert if number 
			double num = stod(input);

			// updates
			count++;
			sum += num;

			// find max and min
			if (count == 1)
			{
				min = num;
				max = num;
			}
			else
			{
				if (num < min) { min = num; }
				if (num > max) { max = num; }
			}
		}
	}

	cout << "Range: " << max - min << "\t" << "Max: " << max << "\t" << "Min: " << min << endl;
	cout << "Number of Values: " << count << endl;
	cout << "Sum: " << sum << endl;
	cout << "Mean: " << (sum / count) << endl;
}

/*
	gets user input temperature (celsius/fahrenheit/kelvin and number), converts to other measurement, output's water's state of matter at that temp || MENU OPTION 2
	@param none
	@return none
*/
void temperatureConversion()
{
	// get user input
	cout << "Celsius or Fahrenheit or Kelvin: ";
	string label;
	cin >> label;
	cout << "Temperature: ";
	string temp_str;
	cin >> temp_str;
	bool dubCheck = isDouble(temp_str);
	if (!dubCheck) { cout << "Invalid input" << endl;  return; }
	double temp = stod(temp_str);
	// conversions
	double celsius, fahrenheit, kelvin; 
	if (tolower(label[0]) == 'c')
	{
		// from celsius
		celsius = temp;
		fahrenheit = temp * 9 / 5 + 32;
		kelvin = temp + 273.15;
	}
	else if (tolower(label[0]) == 'f')
	{
		// from fahrenheit
		fahrenheit = temp;
		celsius = (temp - 32) * 5 / 9;
		kelvin = celsius + 273.15;
	}
	else if (tolower(label[0]) == 'k')
	{
		// from kelvin
		kelvin = temp;
		celsius = temp - 273.15;
		fahrenheit = celsius * 9 / 5 + 32;
	}
	else { cout << "Invalid Temperature" << endl; return; }

	cout << "Output ---------" << endl;
	// print conversions
	cout << "Fahreneheit: " << fahrenheit << endl;
	cout << "Celsius: " << celsius << endl;
	cout << "Kelvin: " << kelvin << endl;

	// print water's state of matter at temp
	cout << "Water's State of Matter: ";
	if (celsius < 0) { cout << "Solid"; }
	else if (celsius == 0) { cout << "Solid and Liquid"; }
	else if (celsius < 100) { cout << "Liquid"; }
	else if (celsius == 100) { cout << "Liquid and Gas"; }
	else { cout << "Gas"; }
	cout << endl;

}

/*
	takes radius as user input and prints diameter, circumference, & area of a circle of that radius || MENU OPTION 3
	@param none
	@return none
*/
void calcAndPrintCircleFacts()
{
	// get input
	cout << "Enter Radius: ";
	string rad_str;
	cin >> rad_str;
	// verify input
	if (!isDouble(rad_str)) { cout << "Invalid Input"; return; }

	// calculate if valid input
	double rad = stod(rad_str);
	double area = 3.14159 * (rad * rad);
	double circ = 2 * 3.14159 * rad;
	double dia = 2 * rad;
	
	// print
	cout << "Diameter: " << dia << endl;
	cout << "Circumference: " << circ << endl;
	cout << "Area: " << area << endl;
}

/*
	gets user input (integer) and finds the factorial of it || MENU OPTION 4
	@param none
	@return none
*/
void calcAndPrintFactorial()
{
	// get input
	cout << "Inetger to find factorial of: ";
	string input_str;
	cin >> input_str;

	// validate input
	if (!isInteger(input_str)) { cout << "Invalid Input"; return; }
	int num = stoi(input_str);
	if (num < 0 ) { cout << "Invalid Input"; return; }
	if (num == 0) { cout << "0! = 0" << endl;  return; }

	// calculate if valid input
	int total = 1;
	for (int i = 2; i <= num; i++) { total *= i; }

	// print
	cout << num << "! = " << total << endl;
}

/*
	 || MENU OPTION 5
	@param none
	@return none
*/
void calcAndPrintWeightedAvg()
{

}

/*
	gets users input and finds: number of digits, even/odd, postive/negative, prime/composit || MENU OPTION 6
	@param none
	@return none
*/
void calcAndPrintSingleInputFacts()
{
	// user inpput
	string input_str;
	cout << "Enter a number: ";
	cin >> input_str;

	int length_adjustment = 0;
	bool double_check = isDouble(input_str);
	string even_odd_str = "";

	// check if it's a double or NaN
	if (double_check)
	{
		length_adjustment = 1;
		// even/odd
		even_odd_str = "n/a (numbers with decimal values are not even/odd)";
	}
	else if(!isInteger(input_str)) { cout << "Invalid Input" << endl; return; }

	// ** input is an integer **
	int num = stoi(input_str);

	// digit count
	cout << "Number of digits: " << input_str.length() - length_adjustment << endl;

	// even/odd
	cout << "Even/odd: ";
	if (!double_check)
	{
		if (num % 2 == 0) { even_odd_str = "EVEN"; }
		else { even_odd_str = "ODD"; }
	}
	cout << even_odd_str << endl;

	//positive/negative
	cout << "+/-/0: ";
	if (num > 0)
	{
		cout << "POSITIVE" << endl;
		//prime/compsite
		cout << "Prime/composite: ";
		bool prime = true;
		// check if prime
		for (int i = 2; i < num && prime; i++)
		{
			if (num % i == 0) { prime = false; }
		}
		// print output
		if (!prime || double_check) { cout << "COMPOSITE"; }
		if (num == 1) { cout << "NEITHER"; }
		else if (prime) { cout << "PRIME"; }
	}
	else if (num < 0)
	{
		cout << "NEGATIVE" << endl;
		cout << "Prime/compsite: Composite (all negative numbers are composite numbers";
	}
	else { cout << "ZERO"; }
	cout << endl;
}

/*
	 || MENU OPTION 7
	@param none
	@return none
*/
void calcAndPrintQuadraticFormula()
{

}

/*
	 || MENU OPTION 8
	@param none
	@return none
*/
void calcAndPrintRectInGrid()
{

}

#include <ctime> // time and localtime
#include "date.h"
#include <iostream>
#include <ostream>
#include <istream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
using std::ios_base;
using std::istream;
using std::ostream;
using std::string;

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date()
{
	time_t timer = time(0);			 // time in seconds since 1970-01-01
	tm *locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}

int Date::getYear() const
{
	return year;
}

int Date::getMonth() const
{
	return month;
}

int Date::getDay() const
{
	return day;
}

void Date::next()
{
}

ostream &operator<<(ostream &output, const Date &D)
{
	output << D.getYear() << "-" << D.getMonth() << '-' << D.getDay();
	return output;
}

template <typename T>
string toString(T s)
{
	std::ostringstream input;
	input << s;
	return input.str();
}

std::vector<string> split_string_by_dash(string text_row)
{
	std::vector<string> splitted_strings;
	std::string s;
	std::stringstream s_stream(text_row);
	const char delim = '-';
	while (getline(s_stream, s, delim))
	{
		splitted_strings.push_back(s);
	}
	return splitted_strings;
}

istream &operator>>(istream &input, Date &D)
{
	string s;
	input >> s;

	std::vector<string> v = split_string_by_dash(s);

	std::cout << " " << v[1] << " ";

	try
	{
		if (year >= 0 && year <= 2022)
		{
			D.year = year;
		}
		if (month > 0 && month <= 12)
		{
			D.month = month;
			if (day > 0 && day <= D.daysPerMonth[day])
			{
				D.day = day;
			}
		}
	}
	catch (const std::exception &e)
	{
		input.setstate(ios_base::failbit);
	}
	return input;
}

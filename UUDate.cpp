/*
* UUDate.cpp
*
* Version information
* Author: TODO - Add your name here
* Date: TODO - Add date you started working on the code
* Description: This file is the implementation file for the UUDate class and defines (implements) the functions of the class
*
* Copyright notice -
*/


#include "UUDate.h"
#include <sstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <array>

bool UUDate::validateLeapYear(int year) {
	if (year % 4 == 0) {
		return true;
	}
	else if (year % 100 == 0) {
		return false;
	}
	else if (year % 400 == true) {
		return true;
	}
}


UUDate::UUDate(){
	//Initialise the date to 01/01/2000
	//TODO - Add your implementation here
	SetYear(2000);
	SetMonth(01);
	SetDay(01);
}

UUDate::UUDate(int day, int month, int year){
	//TODO - Add your implementation here
	year = 2000;
	month = 01;
	day = 01;
	SetYear(year);
	SetMonth(month);
	SetDay(day);

}

UUDate::UUDate(std::string date) {
	//TODO - Add your implementation here
	int day, month, year;

	std::stringstream Date(date);
    std::string tmpStr;
	std::vector <std::string> dateVector;
	while (std::getline(Date, tmpStr, '/')) {
		dateVector.push_back(tmpStr);
	}
	day = atoi(dateVector[0].c_str());
	month = atoi(dateVector[1].c_str());
	year = atoi(dateVector[2].c_str());

	SetDay(day);
	SetMonth(month);
	SetYear(year);

}

void UUDate::IncrementDate() {
	//TODO - Add your implementation here
	if (month_ = 2 && validateLeapYear(year_) == true) {
		if (day_ > 0 && day_ < 29) {
			day_++;
		}
		else if (day_ == 29) {
			month_++;
			day_ = 1;
		}
	} else if (month_ = 2 && validateLeapYear(year_) != true) {
		if (day_> 0 && day_< 28) {
			day_++;
		}
		else if (day_ == 28) {
			month_++;
			day_ = 1;
		}
	} else if (month_ == 1 || month_ == 3 || month_ == 5 || month_ == 7 || month_ == 8 || month_ == 10) {
		if (day_ > 0 && day_ < 31) {
			day_++;
		}
		else if (day_ == 31) {
			month_++;
			day_ = 1;
		}
	}
	else if (month_ == 4 || month_ == 6 || month_ == 9 || month_ == 11) {
		if (day_ > 0 && day_ < 30) {
			day_++;
		}
		else if (day_ == 30) {
			month_++;
			day_ = 1;
		}
	}
	else if (month_ == 12) {
		if (day_ > 0 && day_ < 31) {
			day_++;
		}
		else if (day_ == 31) {
			year_++;
			month_ = 1;
			day_ = 1;
		}
	}
	else {
		day_ = 1;
	}
}

int UUDate::Between(UUDate date) {
	//TODO - Add your implementation here
	return 0;
}

int UUDate::GetDay() const {
	//TODO - Add your implementation here
	return day_;
}

void UUDate::SetDay(int day) {
	//TODO - Add your implementation here
	
		day_ = day;
		
}

int UUDate::GetMonth() const {
	//TODO - Add your implementation here
	return month_;
}

void UUDate::SetMonth(int month) {
	//TODO - Add your implementation here
	if(month > 0 && month < 13) {
		month_ = month;
	}
}

int UUDate::GetYear() const {
	//TODO - Add your implementation here
		return year_;
}

void UUDate::SetYear(int year) {
	//TODO - Add your implementation here
	if (year > 1000 && year < 10000) {
	year_ = year;
	}
}

std::string UUDate::GetDate() {
	//TODO - Add your implementation here
	char buffer[40] = { 0 };
	int i;
	i = sprintf(buffer, "%02d/%02d/%02d", month_, year_);
    std::string Date = buffer;
	return Date;

}

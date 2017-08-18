#include "stdafx.h"
#include<iostream>
#include<string>

using namespace std;

/*
10. Create a class named DentalAppointment. 
--> Include fields for a patient’s data (use the Person class from Exercise 3),
--> the date (using the Date class from Exercise 2), 
--> the time (use the Time class from Exercise 4), 
--> and the duration of the appointment in minutes.
--> Also include a field that contains the ending time of the appointment; 
//this field will be calculated based on the start time and the duration using the Time class function that
//adds minutes to a Time object. 
//The DentalAppointment constructor requires a first
and last name, and a month, day, year, hour, and minute for the appointment. Allow a
DentalAppointment to be constructed with or without an additional argument for
appointment duration, and force the duration to 30 minutes when no argument is supplied.
The constructor does not allow any appointment over 240 minutes. The constructor
calculates the appointment ending time based on the start time and the duration. Also
include a display function for the DentalAppointment class. Write a main()function
that loops at least three times, prompting the user for DentalAppointment data and
displaying all the information. (Note, if you use the Person class display function, the zip
code will be “X”; this is acceptable.) Figure 8-35 shows the output after a typical patient
has been entered. Save the file as DentalAppointment.cpp.
*/


//PERSON class
class Person {
private:
	string lastName;
	string firstName;
	string zipCode;
public:
	Person(string, string, string);


	void display();
};
Person::Person(string lName, string fName, string zCode) {
	lastName = lName;
	firstName = fName;
	zipCode = zCode;
}

void Person::display() {
	cout << "Full Name: " << firstName << " " << lastName << "\nAddress ZipCode: "<<zipCode << endl;
}

//DATE class
class Date {
private:
	int month;
	int day;
	int year;
public:
	Date(int, int, int);
	
	void display();
};
Date::Date(int _month, int _day, int _year) {
	month = _month;
	day = _day;
	year = _year;
}


void Date::display() {
	cout << "Date: " << month << "/" << day << "/" << year<<endl;
}


//TIME class
class Time {
private:
	int hour;
	int minutes;
	

public:
	int setHour();
	Time(int, int);
	void display();
};

int Time::setHour() {

	return hour;
}
//
//int Time::setDuration(int _duration) {
//	duration = _duration;
//
//	int totalMinute = duration + minutes;
//
//	if (totalMinute < 60) {
//
//		minutes = totalMinute;
//		return minutes;
//	}
//	else {
//		hour = hour + 1;
//		minutes = totalMinute - 60;
//
//		return minutes;
//	}
//
//}

Time::Time(int _hour, int _minutes) {
	hour = _hour;
	minutes = _minutes;

}

void Time::display() {
	
	cout << "Start Time(24hr format): " << hour << ":" << minutes << endl;
	}


//Dental Appointment Class

class DentalAppointment {

private:
	Person patientData;
	Date aptDate;
	Time aptTime;
	int endHour;
	int endMinute;

public:
	
	DentalAppointment(string, string, string, int, int, int, int, int, int);
	void display();
};

DentalAppointment::DentalAppointment(string patientName, string patientLname, string zipCode, int month, int day, int year, int hour, int minute, int duration) 
	: patientData( patientName, patientLname, zipCode),aptDate(month, day, year), aptTime(hour, minute){


	//endHour = hour;
	//endMinute = minute + duration;

	int totalMinute = minute + duration;

	if (totalMinute < 60) {
		endMinute = totalMinute;
		endHour = hour;
	}
	else {
		endHour = hour + 1;
		endMinute = totalMinute - 60;
	}

}

void DentalAppointment::display(){

	patientData.display();
	aptDate.display();
	aptTime.display();
	cout << "End Time: " << endHour << ":"<< endMinute <<endl;

	/*timeDuration(30);*/

	/*cout << "End Time: " << endl;*/
}

int main()
{

	//TO BE CHECKED FOR END TIME!!!!!!!!!!!!!!!!!!!
	string lastName;
	string firstName;
	string zipCode;
	int month;
	int day;
	int year;
	int hour;
	int minute;
	int duration;

	cout << "First Name: ";
	cin >> firstName;
	cout << "Last Name: ";
	cin >> lastName;
	cout << "ZipCode: ";
	cin >> zipCode;
	cout<< "Month: ";
	cin >> month;
	cout << "Day: ";
	cin >> day;
	cout << "Year: ";
	cin >> year;
	cout << "Hour: ";
	cin >> hour;
	cout << "Minute: ";
	cin >> minute;
	cout << "Duration: ";
	cin >> duration;


	DentalAppointment dent(firstName, lastName, zipCode, month, day, year, hour, minute, duration);
	dent.display();
    return 0;
}


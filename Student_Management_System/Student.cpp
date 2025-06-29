#include"Student.h"
#include<string>
#include<iomanip>
Student::Student(const std::string&id,const std::string&name,double score):id(id),name(name),score(score){}

std::string Student::getId()const {
	return id;
}

std::string Student::getName()const {
	return name;
}

double Student::getScore()const {
	return score;
}

void Student::setScore(double s) {
	score = s;
}

void Student::display()const {
	std::cout << std::left << std::setw(10) << id
		<< std::setw(10) << name
		<< std::right << std::fixed << std::setprecision(2) << score << "\n";
}
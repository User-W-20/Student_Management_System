#pragma once
#include<iostream>

class Student {
private:
	std::string id;
	std::string name;
	double score;

public:
	Student() = default;
	Student(const std::string&, const std::string&, double);

	std::string getId()const;
	std::string getName()const;
	double getScore()const;

	void setScore(double);

	void display()const;

	void exportToCSV(const std::string& filename)const;
};
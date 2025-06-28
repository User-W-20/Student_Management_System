#pragma once
#include"Student.h"
#include<vector>
#include<algorithm>
class StudentManager {
private:
	std::vector<Student>students;

public:
	void addStudent(const Student&);
	void removeStudent(const std::string& id);
	void updateScore(const std::string& id, double newScore);
	void showall()const;
	Student* findById(const std::string& id);
	void sortByScore(bool ascending = true);
};
#pragma once
#include"Student.h"
#include<vector>
#include<algorithm>
#include<fstream>
#include<iomanip>
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
	void saveToFile(const std::string& filename)const;
	void loadFromFile(const std::string& filename);
	void findByNamePart(const std::string& keyword)const;
	void showStatistics()const;
	bool exists(const std::string& id)const;
};
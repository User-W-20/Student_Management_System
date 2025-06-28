#include"StudentManager.h"

void StudentManager::addStudent(const Student& s) {
	students.push_back(s);
}

void StudentManager::removeStudent(const std::string& id) {
	auto result = std::find_if(students.begin(), students.end(), [&](const Student& student) {return student.getId() == id; });
	
	if (result != students.end()) {
		students.erase(result);
	}
	
}

void StudentManager::updateScore(const std::string& id, double newScore) {
	auto it = std::find_if(students.begin(), students.end(), [&](Student& student) {return student.getId() == id; });

	if (it != students.end()) {
		it->setScore(newScore);
	}
}

void StudentManager::showall()const {
	for (const auto& student : students) {
		student.display();
	}
}

Student* StudentManager::findById(const std::string& id) {
	auto it = std::find_if(students.begin(), students.end(), [&](Student& student) {return student.getId() == id; });
	if (it != students.end()) {
		return &(*it);
	}
	else {
		return nullptr;
	}
}

void StudentManager::sortByScore(bool ascending) {
	if (ascending) {
		std::sort(students.begin(), students.end(),
			[](const Student& a, const Student& b) {
				return a.getScore() < b.getScore();
			});
	}
	else {
		std::sort(students.begin(), students.end(),
			[](const Student& a, const Student& b) {
				return a.getScore() > b.getScore();
			});
	}
}
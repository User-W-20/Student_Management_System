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
	std::cout << std::left
		<< std::setw(10) << "ID"
		<< std::setw(10) << "Name"
		<< std::right << "Score\n";
	std::cout << "-------------------------------\n";
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
void StudentManager::saveToFile(const std::string& filename)const {
	std::ofstream out(filename);
	 
	for (const auto& student : students) {
		out << student.getId() << " "
			<< student.getName() << " "
			<< student.getScore() << "\n";
	}
}

void StudentManager::loadFromFile(const std::string& filename){
	std::ifstream in(filename);
	std::string id, name;
	double score;
	students.clear();
	while (in >> id >> name >> score) {
		students.emplace_back(id, name, score);
	}
}

void StudentManager::findByNamePart(const std::string& keyword)const {
	bool found = false;

	std::cout << std::left << std::setw(10) << "ID"
		<< std::setw(10) << "Name"
		<< std::right << "Score\n";
	std::cout << "-------------------------------\n";

	for (const auto& student : students) {
		if (student.getName().find(keyword) != std::string::npos) {
			student.display();
			found = true;
		}
	}

	if (!found) {
		std::cout << "未找到包含 \"" <<keyword<< "\" 的学生。\n";
	}
}
void StudentManager::showStatistics()const {
	size_t total = students.size();
	if (total == 0) {
		std::cout << "暂无学生数据。\n";
		return;
	}

	double sum = 0.0, maxScore = students[0].getScore(), minScore = students[0].getScore();
	int passCount = 0, failCount = 0, rangeCount = 0;

	for (auto& student : students){
		double score = student.getScore();
		sum += score;
		if (score > maxScore)maxScore = score;
		if (score < minScore)minScore = score;
		if (score >= 60)passCount++;
		else failCount;
		if (score >= 60 && score < 70)rangeCount++;
		if (score >= 70 && score < 80)rangeCount++;
		if (score >= 80 && score < 90)rangeCount++;
		if (score >= 90 && score < 100)rangeCount++;
}
	double avg = sum / total;
	double passRate = 100 * passCount / total;

	std::cout << std::fixed << std::setprecision(2);
	std::cout << "总人数：" << total << std::endl;
	std::cout << "平均分：" << avg << std::endl;
	std::cout << "最高分：" << maxScore << std::endl;
	std::cout << "最低分：" << minScore << std::endl;
	std::cout << "及格人数：" << passCount << "（占比 " << passRate << "%）" << std::endl;
	std::cout << "不及格人数：" << failCount << std::endl;
	std::cout << "60~70分人数：" << rangeCount << std::endl;
	std::cout << "70~80分人数：" << rangeCount << std::endl;
	std::cout << "80~90分人数：" << rangeCount << std::endl;
	std::cout << "90~100分人数：" << rangeCount << std::endl;
}

bool StudentManager::exists(const std::string& id)const {
	return std::any_of(students.begin(), students.end(), [&](const Student& s) {return s.getId() == id; });
}
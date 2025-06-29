#include<iostream>
#include"Student.h"
#include"StudentManager.h"

int main() {
	StudentManager manager;
	std::string id, name;
	double score;
	int choice;
	manager.loadFromFile("students.txt");
	do {
		std::cout << "\n===== 学生管理系统 =====\n";
		std::cout << "1. 添加学生\n";
		std::cout << "2. 显示所有学生\n";
		std::cout << "3. 删除学生\n";
		std::cout << "4. 修改学生成绩\n";
		std::cout << "5. 查找学生\n";
		std::cout << "6. 成绩排序\n";
		std::cout << "7. 模糊查找学生（按姓名）\n";
		std::cout << "8. 成绩统计分析 \n";
		std::cout << "0. 退出\n";
		std::cout << "请输入选项：";
		std::cin >> choice;
		
		switch (choice) {
		case 1:
			std::cout << "输入ID 姓名 成绩：";
			std::cin >> id >> name >> score;
			if (manager.exists(id)) {
				std::cout << "学号已存在，添加失败！\n";
			}
			else {
				manager.addStudent(Student(id, name, score));
				std::cout << "添加成功\n";
			}
			break;
		case 2:
			manager.showall();
			break;
		case 3:
			std::cout << "输入要删除的学号：";
			std::cin >> id;
			manager.removeStudent(id);
			break;
		case 4:
			std::cout << "输入学号与新成绩：";
			std::cin >> id >> score;
			manager.updateScore(id,score);
			break;
		case 5:
			std::cout << "输入学号：";
			std::cin >> id;
			if (auto* p = manager.findById(id)) {
				p->display();
			}
			else {
				std::cout << "未找到该学生\n";
			}
			break;
		case 6:
			std::cout << "选择排序方式（1-升序，0-降序）：";
			bool asc;
			std::cin >> asc;
			manager.sortByScore(asc);
			manager.showall();
			break;
		case 7:{
			std::string keyword;
			std::cout << "请输入要查找的关键字：";
			std::cin >> keyword;
			manager.findByNamePart(keyword);
			break;
		}
		case 8:
			manager.showStatistics();
			break;
		case 0:
			manager.saveToFile("students.txt");
			std::cout << "程序结束。\n";
			break;
		default:
			std::cout << "无效选项，请重新输入！\n";
		}
	} while (choice != 0);

	//测试
	//StudentManager manager;

	//// 添加学生
	//manager.addStudent(Student("001", "Alice", 85.5));
	//manager.addStudent(Student("002", "Bob", 92.0));
	//manager.addStudent(Student("003", "Charlie", 78.0));

	//std::cout << "\n所有学生信息：" << std::endl;
	//manager.showall();

	//// 修改成绩
	//std::cout << "\n修改 Bob 的成绩为 95.0：" << std::endl;
	//manager.updateScore("002", 95.0);
	//manager.showall();

	//// 查找学生
	//std::cout << "\n查找 Charlie：" << std::endl;
	//Student* found = manager.findById("003");
	//if (found)
	//	found->display();
	//else
	//	std::cout << "找不到 Charlie" << std::endl;

	//// 排序
	//std::cout << "\n按成绩降序排序后：" << std::endl;
	//manager.sortByScore(false);// false 表示降序
	//manager.showall();

	//// 删除学生
	//std::cout << "\n删除 Alice 后：" << std::endl;
	//manager.removeStudent("001");
	//manager.showall();

	return 0;
}
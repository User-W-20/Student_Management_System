#include<iostream>
#include"Student.h"
#include"StudentManager.h"

int main() {
	StudentManager manager;

	// 添加学生
	manager.addStudent(Student("001", "Alice", 85.5));
	manager.addStudent(Student("002", "Bob", 92.0));
	manager.addStudent(Student("003", "Charlie", 78.0));

	std::cout << "\n所有学生信息：" << std::endl;
	manager.showall();

	// 修改成绩
	std::cout << "\n修改 Bob 的成绩为 95.0：" << std::endl;
	manager.updateScore("002", 95.0);
	manager.showall();

	// 查找学生
	std::cout << "\n查找 Charlie：" << std::endl;
	Student* found = manager.findById("003");
	if (found)
		found->display();
	else
		std::cout << "找不到 Charlie" << std::endl;

	// 排序
	std::cout << "\n按成绩降序排序后：" << std::endl;
	manager.sortByScore(false);// false 表示降序
	manager.showall();

	// 删除学生
	std::cout << "\n删除 Alice 后：" << std::endl;
	manager.removeStudent("001");
	manager.showall();

	return 0;
}
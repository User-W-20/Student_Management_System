#include<iostream>
#include"Student.h"
#include"StudentManager.h"

int main() {
	StudentManager manager;

	// ���ѧ��
	manager.addStudent(Student("001", "Alice", 85.5));
	manager.addStudent(Student("002", "Bob", 92.0));
	manager.addStudent(Student("003", "Charlie", 78.0));

	std::cout << "\n����ѧ����Ϣ��" << std::endl;
	manager.showall();

	// �޸ĳɼ�
	std::cout << "\n�޸� Bob �ĳɼ�Ϊ 95.0��" << std::endl;
	manager.updateScore("002", 95.0);
	manager.showall();

	// ����ѧ��
	std::cout << "\n���� Charlie��" << std::endl;
	Student* found = manager.findById("003");
	if (found)
		found->display();
	else
		std::cout << "�Ҳ��� Charlie" << std::endl;

	// ����
	std::cout << "\n���ɼ����������" << std::endl;
	manager.sortByScore(false);// false ��ʾ����
	manager.showall();

	// ɾ��ѧ��
	std::cout << "\nɾ�� Alice ��" << std::endl;
	manager.removeStudent("001");
	manager.showall();

	return 0;
}
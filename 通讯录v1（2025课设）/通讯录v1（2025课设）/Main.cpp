#include <iostream>
#include <string>
using namespace std;

struct Person {
	string m_Name;    // 姓名
	string m_Phone;   // 电话
	string m_Addr;    // 单位
	string m_Category;// 类别（办公/个人）
};

#define MAX 1000
struct AddressBook {
	Person personArray[MAX];//通讯录
	int m_Size = 0;//初始化通讯录下标，一开始为“0”
};

AddressBook g_addressBook; // 全局通讯录变量(一个数组)

void showMenu() {
	cout 
		<< "》》欢迎访问通讯录系统v1.0！《《" << endl
		<< "********************************" << endl
		<< "***********通讯录系统***********" << endl
		<< "**********1.添加联系人**********" << endl
		<< "**********2.显示联系人**********" << endl
		<< "**********3.删除联系人**********" << endl
		<< "**********4.查找联系人**********" << endl
		<< "**********5.修改联系人**********" << endl
		<< "**********6.清空联系人**********" << endl
		<< "**********0.退出通讯录**********" << endl
		<< "********************************" << endl;
}

void Exit() {
	cout << "欢迎下次使用！" << endl;
	exit(0);//程序正常退出
}
//添加
void Add() {
	if (g_addressBook.m_Size >= MAX) {
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}

	Person newPerson;
	cout << "请输入姓名：";
	cin >> newPerson.m_Name;

	cout << "请输入类别（办公/个人）：";
	cin >> newPerson.m_Category;
	if (newPerson.m_Category != "办公" && newPerson.m_Category != "个人") {
		cout << "类别输入错误！" << endl;//类别判断
		return;
	}

	// 检查同类别下是否存在同名
	for (int i = 0; i < g_addressBook.m_Size; i++) {
		if (g_addressBook.personArray[i].m_Name == newPerson.m_Name &&
			g_addressBook.personArray[i].m_Category == newPerson.m_Category) {
			cout << "该类别下已存在该联系人！" << endl;
			return;
		}
	}

	cout << "请输入电话：";
	cin >> newPerson.m_Phone;
	cout << "请输入单位：";
	cin >> newPerson.m_Addr;

	g_addressBook.personArray[g_addressBook.m_Size] = newPerson;//存入通讯录
	g_addressBook.m_Size++;
	cout << "添加成功！" << endl;
}
//展示
void Show() {
	string category;
	cout << "请输入要显示的类别（办公/个人）：";
	cin >> category;

	if (category != "办公" && category != "个人") {
		cout << "类别错误！" << endl;
		return;
	}

	bool found = false;//根据类别遍历addressBook，找到符合的person
	for (int i = 0; i < g_addressBook.m_Size; i++) {
		if (g_addressBook.personArray[i].m_Category == category) {
			cout << "姓名：" << g_addressBook.personArray[i].m_Name << endl
				<< "电话：" << g_addressBook.personArray[i].m_Phone << endl
				<< "单位：" << g_addressBook.personArray[i].m_Addr << endl
				<< "-------------------" << endl;
			found = true;//更新found，表示找到对应的person
		}
	}
	if (!found) cout << "该类别无联系人！" << endl;
}
//删除
void Delete() {
	string name, category;
	cout << "请输入要删除的姓名：";
	cin >> name;
	cout << "请输入类别（办公/个人）：";
	cin >> category;
	//遍历addressBook，寻找person
	int index = -1;
	for (int i = 0; i < g_addressBook.m_Size; i++) {
		if (g_addressBook.personArray[i].m_Name == name &&
			g_addressBook.personArray[i].m_Category == category) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		cout << "联系人不存在！" << endl;
		return;
	}

	// 前移数据
	for (int i = index; i < g_addressBook.m_Size - 1; i++) {
		g_addressBook.personArray[i] = g_addressBook.personArray[i + 1];
	}
	g_addressBook.m_Size--;
	cout << "删除成功！" << endl;
}
//查找
void Find() {
	string name;
	cout << "请输入要查找的姓名：";
	cin >> name;

	bool found = false;
	for (int i = 0; i < g_addressBook.m_Size; i++) {
		if (g_addressBook.personArray[i].m_Name == name) {
			cout << "姓名：" << g_addressBook.personArray[i].m_Name << endl
				<< "电话：" << g_addressBook.personArray[i].m_Phone << endl
				<< "单位：" << g_addressBook.personArray[i].m_Addr << endl
				<< "类别：" << g_addressBook.personArray[i].m_Category << endl
				<< "-------------------" << endl;
			found = true;
		}
	}
	if (!found) cout << "未找到该联系人！" << endl;
}
//修改
void Modify() {
	string name, category;
	cout << "请输入要修改的姓名：";
	cin >> name;
	cout << "请输入原类别（办公/个人）：";
	cin >> category;

	int index = -1;
	for (int i = 0; i < g_addressBook.m_Size; i++) {
		if (g_addressBook.personArray[i].m_Name == name &&
			g_addressBook.personArray[i].m_Category == category) {
			index = i;
			break;
		}
	}

	if (index == -1) {
		cout << "联系人不存在！" << endl;
		return;
	}

	Person &p = g_addressBook.personArray[index];

	cout << "请输入新电话（原：" << p.m_Phone << "）：";
	cin >> p.m_Phone;
	cout << "请输入新单位（原：" << p.m_Addr << "）：";
	cin >> p.m_Addr;

	string newCategory;
	cout << "请输入新类别（原：" << p.m_Category << "）：";
	cin >> newCategory;
	if (newCategory != "办公" && newCategory != "个人") {
		cout << "类别错误，修改失败！" << endl;
		return;
	}

	// 检查新类别下是否有同名
	if (newCategory != category) {
		for (int i = 0; i < g_addressBook.m_Size; i++) {
			if (i != index && g_addressBook.personArray[i].m_Name == name &&
				g_addressBook.personArray[i].m_Category == newCategory) {
				cout << "新类别下已存在同名联系人！" << endl;
				return;
			}
		}
	}
	p.m_Category = newCategory;
	cout << "修改成功！" << endl;
}
//清空
void Clear() {
	g_addressBook.m_Size = 0;//清空数组
	cout << "通讯录已清空！" << endl;
}

int main() {
	int select = 0;
	while (true) {
		showMenu();
		cout << "请输入选择：";
		cin >> select;
		switch (select) {
		case 1:
			Add(); break;
		case 2:
			Show(); break;
		case 3:
			Delete(); break;
		case 4:
			Find(); break;
		case 5: 
			Modify(); break;
		case 6:
			Clear(); break;
		case 0:
			Exit(); break;
		default:
			cout << "输入错误，请重新输入！" << endl;
			break;
		}
		system("pause"); // 按任意键继续
		system("cls");   // 清屏
	}
	return 0;
}
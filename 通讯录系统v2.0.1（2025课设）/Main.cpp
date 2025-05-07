#include "addressbook.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void showMenu() {
    cout << endl
        << "╔══════════════════════════╗" << endl
        << "║  通讯录管理系统 v2.0     ║" << endl
        << "╠══════════════════════════╣" << endl
        << "║ 1. 添加联系人            ║" << endl
        << "║ 2. 显示联系人            ║" << endl
        << "║ 3. 删除联系人            ║" << endl
        << "║ 4. 查找联系人            ║" << endl
        << "║ 5. 修改联系人            ║" << endl
        << "║ 6. 清空通讯录            ║" << endl
        << "║ 0. 退出系统              ║" << endl
        << "╚══════════════════════════╝" << endl
        << "请选择操作：" << endl;
}

int main() {
    AddressBook ab;
    ab.loadFromFile("contacts.dat");

    int choice;
    while (true) {
        showMenu();
        cin >> choice;
        switch (choice) {
        case 1: 
            ab.addContact(); break;
        case 2:
            ab.showContactsByCategory(); break;
        case 3:
            ab.deleteContact(); break;
        case 4:
            ab.findContact(); break;
        case 5:
            ab.modifyContact(); break;
        case 6:
            ab.clearAll(); break;
        case 0:
            ab.saveToFile("contacts.dat");
            cout << "数据已保存，欢迎下次使用！" << endl;
//			return 0;
            exit(0);
        default:
            cout << "输入错误，请重新输入！" << endl;
            break;
        }
        system("pause");

        system("cls");
    }
    return 0;
}
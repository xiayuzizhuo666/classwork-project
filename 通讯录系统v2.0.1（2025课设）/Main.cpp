#include "addressbook.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void showMenu() {
    cout << endl
        << "�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[" << endl
        << "�U  ͨѶ¼����ϵͳ v2.0     �U" << endl
        << "�d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g" << endl
        << "�U 1. �����ϵ��            �U" << endl
        << "�U 2. ��ʾ��ϵ��            �U" << endl
        << "�U 3. ɾ����ϵ��            �U" << endl
        << "�U 4. ������ϵ��            �U" << endl
        << "�U 5. �޸���ϵ��            �U" << endl
        << "�U 6. ���ͨѶ¼            �U" << endl
        << "�U 0. �˳�ϵͳ              �U" << endl
        << "�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a" << endl
        << "��ѡ�������" << endl;
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
            cout << "�����ѱ��棬��ӭ�´�ʹ�ã�" << endl;
//			return 0;
            exit(0);
        default:
            cout << "����������������룡" << endl;
            break;
        }
        system("pause");

        system("cls");
    }
    return 0;
}
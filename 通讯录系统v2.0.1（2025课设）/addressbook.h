#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include "person.h"
#include <string>
using namespace std;
const int MAX_CONTACTS = 1000; // ͨѶ¼�������

// ͨѶ¼�࣬�ṩ��ϵ�˹�����
class AddressBook {
public:
    AddressBook(); // ���캯��

    void addContact();          // �����ϵ��
    void showContactsByCategory() const; // ��������ʾ��ϵ��
    void deleteContact();       // ɾ����ϵ��
    void findContact() const;   // ������ϵ��
    void modifyContact();       // �޸���ϵ��
    void clearAll();            // ���ͨѶ¼

    bool saveToFile(const string& filename) const; // ���浽�ļ�
    bool loadFromFile(const string& filename);     // ���ļ�����

private:
    Person contacts[MAX_CONTACTS]; // ��ϵ�˴洢����
    int size;                      // ��ǰ��ϵ������

    bool isContactExist(const string& name, const string& category) const; // �����ϵ���Ƿ����
};

#endif // ADDRESSBOOK_H
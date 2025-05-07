#include "addressbook.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

AddressBook::AddressBook() : size(0) {} // ���캯������ʼ����ϵ����Ϊ0

void AddressBook::addContact() {        // �����ϵ�ˣ�����������ظ����������
    if (size >= MAX_CONTACTS) {
        cout << "ͨѶ¼�������޷���ӣ�" << endl;
        return;
    }

    Person newContact;
    cout << "������������";
    cin >> newContact.m_Name;

    cout << "��������𣨰칫/���ˣ���";
    cin >> newContact.m_Category;
    if (newContact.m_Category != "�칫" && newContact.m_Category != "����") {
        cout << "����������" << endl;
        return;
    }
//����isContactExist,�����Ƿ�����ظ�����
    if (isContactExist(newContact.m_Name, newContact.m_Category)) {
        cout << "��������Ѵ��ڸ���ϵ�ˣ�" << endl;
        return;
    }

    cout << "������绰��";
    cin >> newContact.m_Phone;
    cout << "�����뵥λ��";
    cin >> newContact.m_Addr;

    contacts[size++] = newContact;
    cout << "��ӳɹ���" << endl;
}

void AddressBook::showContactsByCategory() const { // ��ָ�������ʾ������ϵ����Ϣ
    string category;
    cout << "������Ҫ��ʾ����𣨰칫/���ˣ���";
    cin >> category;

    if (category != "�칫" && category != "����") {
        cout << "������" << endl;
        return;
    }

    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (contacts[i].m_Category == category) {
            cout << "������" << contacts[i].m_Name << endl
                << "�绰��" << contacts[i].m_Phone << endl
                << "��λ��" << contacts[i].m_Addr << endl
                << "-------------------" << endl;
            found = true;
        }
    }
    if (!found) cout << "���������ϵ�ˣ�" << endl;
}

void AddressBook::deleteContact() {     // ɾ��ָ����ϵ�˲�ǰ�ƺ�����¼
    string name, category;
    cout << "������Ҫɾ����������";
    cin >> name;
    cout << "��������𣨰칫/���ˣ���";
    cin >> category;

    int index = -1;
    for (int i = 0; i < size; ++i) {
        if (contacts[i].m_Name == name && contacts[i].m_Category == category) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "��ϵ�˲����ڣ�" << endl;
        return;
    }

    // ǰ�Ƹ���ɾ��λ�õļ�¼
    for (int i = index; i < size - 1; ++i) {
        contacts[i] = contacts[i + 1];
    }
    size--;
    cout << "ɾ���ɹ���" << endl;
}

void AddressBook::findContact() const { // �����������Ҳ���ʾ��ϸ��Ϣ
    string name;
    cout << "������Ҫ���ҵ�������";
    cin >> name;

    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (contacts[i].m_Name == name) {
            cout << "������" << contacts[i].m_Name << endl
                << "�绰��" << contacts[i].m_Phone << endl
                << "��λ��" << contacts[i].m_Addr << endl
                << "���" << contacts[i].m_Category << endl
                << "-------------------" << endl;
            found = true;
        }
    }
    if (!found) cout << "δ�ҵ�����ϵ�ˣ�" << endl;
}

void AddressBook::modifyContact() {     // �޸���ϵ����Ϣ��֧���޸���������
    string name, category;
    cout << "������Ҫ�޸ĵ�������";
    cin >> name;
    cout << "������ԭ��𣨰칫/���ˣ���";
    cin >> category;

    int index = -1;
    for (int i = 0; i < size; ++i) {
        if (contacts[i].m_Name == name && contacts[i].m_Category == category) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "��ϵ�˲����ڣ�" << endl;
        return;
    }

    Person& p = contacts[index];
    cout << "�������µ绰��ԭ��" << p.m_Phone << "����";
    cin >> p.m_Phone;
    cout << "�������µ�λ��ԭ��" << p.m_Addr << "����";
    cin >> p.m_Addr;

    string newCategory;
    cout << "�����������ԭ��" << p.m_Category << "����";
    cin >> newCategory;
    if (newCategory != "�칫" && newCategory != "����") {
        cout << "�������޸�ʧ�ܣ�" << endl;
        return;
    }

    if (newCategory != category && isContactExist(name, newCategory)) {
        cout << "��������Ѵ���ͬ����ϵ�ˣ�" << endl;
        return;
    }

    p.m_Category = newCategory;
    cout << "�޸ĳɹ���" << endl;
}

void AddressBook::clearAll() {          // ���������ϵ�ˣ����ü�����
    size = 0;
    cout << "ͨѶ¼����գ�" << endl;
}

bool AddressBook::saveToFile(const string& filename) const { // �������ݵ�CSV�ļ�
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "�޷������ļ���" << endl;
        return false;
    }

    for (int i = 0; i < size; ++i) {
        outFile << contacts[i].m_Name << ","
            << contacts[i].m_Phone << ","
            << contacts[i].m_Addr << ","
            << contacts[i].m_Category << "\n";
    }
    return true;
}

bool AddressBook::loadFromFile(const string& filename) { // ��CSV�ļ���������
    ifstream inFile(filename);
    if (!inFile) return false;

    string line;
    while (getline(inFile, line) && size < MAX_CONTACTS) {
        stringstream ss(line);
        Person p;
        getline(ss, p.m_Name, ',');
        getline(ss, p.m_Phone, ',');
        getline(ss, p.m_Addr, ',');
        getline(ss, p.m_Category, ',');

        if (p.m_Category == "�칫" || p.m_Category == "����") {
            contacts[size++] = p;
        }
    }
    return true;
}

bool AddressBook::isContactExist(const string& name, const string& category) const {
    for (int i = 0; i < size; ++i) {    // �������ͬ��ͬ�����ϵ��
        if (contacts[i].m_Name == name && contacts[i].m_Category == category) {
            return true;
        }
    }
    return false;
}
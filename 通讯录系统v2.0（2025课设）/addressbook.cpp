#include "addressbook.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

AddressBook::AddressBook() : size(0) {} // 构造函数，初始化联系人数为0

void AddressBook::addContact() {        // 添加联系人，检查容量和重复后存入数组
    if (size >= MAX_CONTACTS) {
        cout << "通讯录已满，无法添加！" << endl;
        return;
    }

    Person newContact;
    cout << "请输入姓名：";
    cin >> newContact.m_Name;

    cout << "请输入类别（办公/个人）：";
    cin >> newContact.m_Category;
    if (newContact.m_Category != "办公" && newContact.m_Category != "个人") {
        cout << "类别输入错误！" << endl;
        return;
    }

    if (isContactExist(newContact.m_Name, newContact.m_Category)) {
        cout << "该类别下已存在该联系人！" << endl;
        return;
    }

    cout << "请输入电话：";
    cin >> newContact.m_Phone;
    cout << "请输入单位：";
    cin >> newContact.m_Addr;

    contacts[size++] = newContact;
    cout << "添加成功！" << endl;
}

void AddressBook::showContactsByCategory() const { // 按指定类别显示所有联系人信息
    string category;
    cout << "请输入要显示的类别（办公/个人）：";
    cin >> category;

    if (category != "办公" && category != "个人") {
        cout << "类别错误！" << endl;
        return;
    }

    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (contacts[i].m_Category == category) {
            cout << "姓名：" << contacts[i].m_Name << endl
                << "电话：" << contacts[i].m_Phone << endl
                << "单位：" << contacts[i].m_Addr << endl
                << "-------------------" << endl;
            found = true;
        }
    }
    if (!found) cout << "该类别无联系人！" << endl;
}

void AddressBook::deleteContact() {     // 删除指定联系人并前移后续记录
    string name, category;
    cout << "请输入要删除的姓名：";
    cin >> name;
    cout << "请输入类别（办公/个人）：";
    cin >> category;

    int index = -1;
    for (int i = 0; i < size; ++i) {
        if (contacts[i].m_Name == name && contacts[i].m_Category == category) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "联系人不存在！" << endl;
        return;
    }

    // 前移覆盖删除位置的记录
    for (int i = index; i < size - 1; ++i) {
        contacts[i] = contacts[i + 1];
    }
    size--;
    cout << "删除成功！" << endl;
}

void AddressBook::findContact() const { // 根据姓名查找并显示详细信息
    string name;
    cout << "请输入要查找的姓名：";
    cin >> name;

    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (contacts[i].m_Name == name) {
            cout << "姓名：" << contacts[i].m_Name << endl
                << "电话：" << contacts[i].m_Phone << endl
                << "单位：" << contacts[i].m_Addr << endl
                << "类别：" << contacts[i].m_Category << endl
                << "-------------------" << endl;
            found = true;
        }
    }
    if (!found) cout << "未找到该联系人！" << endl;
}

void AddressBook::modifyContact() {     // 修改联系人信息，支持修改类别和详情
    string name, category;
    cout << "请输入要修改的姓名：";
    cin >> name;
    cout << "请输入原类别（办公/个人）：";
    cin >> category;

    int index = -1;
    for (int i = 0; i < size; ++i) {
        if (contacts[i].m_Name == name && contacts[i].m_Category == category) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "联系人不存在！" << endl;
        return;
    }

    Person& p = contacts[index];
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

    if (newCategory != category && isContactExist(name, newCategory)) {
        cout << "新类别下已存在同名联系人！" << endl;
        return;
    }

    p.m_Category = newCategory;
    cout << "修改成功！" << endl;
}

void AddressBook::clearAll() {          // 清空所有联系人，重置计数器
    size = 0;
    cout << "通讯录已清空！" << endl;
}

bool AddressBook::saveToFile(const string& filename) const { // 保存数据到CSV文件
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "无法保存文件！" << endl;
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

bool AddressBook::loadFromFile(const string& filename) { // 从CSV文件加载数据
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

        if (p.m_Category == "办公" || p.m_Category == "个人") {
            contacts[size++] = p;
        }
    }
    return true;
}

bool AddressBook::isContactExist(const string& name, const string& category) const {
    for (int i = 0; i < size; ++i) {    // 遍历检查同名同类别联系人
        if (contacts[i].m_Name == name && contacts[i].m_Category == category) {
            return true;
        }
    }
    return false;
}
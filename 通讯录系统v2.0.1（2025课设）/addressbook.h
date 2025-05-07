#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include "person.h"
#include <string>
using namespace std;
const int MAX_CONTACTS = 1000; // 通讯录最大容量

// 通讯录类，提供联系人管理功能
class AddressBook {
public:
    AddressBook(); // 构造函数

    void addContact();          // 添加联系人
    void showContactsByCategory() const; // 按分类显示联系人
    void deleteContact();       // 删除联系人
    void findContact() const;   // 查找联系人
    void modifyContact();       // 修改联系人
    void clearAll();            // 清空通讯录

    bool saveToFile(const string& filename) const; // 保存到文件
    bool loadFromFile(const string& filename);     // 从文件加载

private:
    Person contacts[MAX_CONTACTS]; // 联系人存储数组
    int size;                      // 当前联系人数量

    bool isContactExist(const string& name, const string& category) const; // 检查联系人是否存在
};

#endif // ADDRESSBOOK_H
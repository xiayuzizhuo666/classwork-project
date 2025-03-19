#ifndef PERSON_H
#define PERSON_H

#include <string>

struct Person {
    std::string m_Name;    // 姓名
    std::string m_Phone;   // 电话
    std::string m_Addr;    // 单位
    std::string m_Category;// 类别（办公/个人）
};

#endif // PERSON_H
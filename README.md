# 通讯录管理系统 v2.0

📖 课程设计项目 | C++面向对象实践 | 数据持久化存储

[![License](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)
[![C++](https://img.shields.io/badge/C++-17-blue.svg)](https://isocpp.org/)

## 📌 项目简介
基于C++实现的通讯录管理系统，支持办公/个人双类别管理。通过面向对象设计和文件I/O操作实现以下功能：
- **分类存储**：按"办公/个人"双维度管理联系人
- **持久化存储**：采用CSV格式保存通讯录数据
- **终端交互**：提供图形化菜单操作界面
- **数据校验**：支持电话号码格式验证和重复检查

## 🚀 功能特性
### 核心功能
| 功能                | 描述                           |
|---------------------|-------------------------------|
| ✨ 添加联系人        | 支持姓名/电话/单位/类别录入    |
| 🔍 分类显示          | 按办公/个人类别筛选显示        |
| 🗑️ 删除联系人        | 按姓名+类别精准删除            |
| 📝 修改信息          | 支持修改全部字段（含类别迁移） |
| 💾 文件存储          | 启动自动加载，退出自动保存      |

### 增强特性
- 联系人容量限制（MAX 1000）
- 输入合法性校验（电话格式、类别限制）
- 重复录入防御机制（姓名+类别联合校验）
- Unicode字符绘制终端界面
- 异常输入友好提示

## 🛠️ 技术栈
- **编程语言**: C++17
- **设计模式**: 面向对象（OOP）
- **数据存储**: CSV文件持久化（ifstream/ofstream）
- **核心算法**:
  - 数组遍历查找（O(n)）
  - 文件流序列化/反序列化
- **开发工具**:
  - CLion 2023.1
  - Windows Terminal
  - Git版本控制

## 📂 项目结构
classwork-project/
├── include/
│   ├── Person.h         # 联系人数据结构定义
│   └── AddressBook.h    # 通讯录类声明
├── src/
│   ├── AddressBook.cpp  # 通讯录类方法实现
│   └── main.cpp         # 主程序与用户交互
└── contacts.dat         # 数据存储文件（CSV格式）


## 🖥️ 使用说明
### 快速开始
```bash
# 克隆项目
git clone https://github.com/xiayuzizhuo666/classwork-project.git

# 编译运行（需配置C++17环境）
g++ -std=c++17 src/*.cpp -o addressbook && ./addressbook
```
##操作指南
启动程序后自动加载 contacts.dat
###通过数字键选择菜单功能：
1 - 添加联系人（自动校验重复）
2 - 按类别显示联系人
3 - 删除指定联系人
4 - 按姓名查找详细信息
5 - 修改联系人信息
6 - 清空所有联系人
0 - 保存退出


##✅ 测试验证
###关键测试用例
| 测试场景	| 验证方法| 	预期结果| 
|-------------|-------------|-------------| 
| 重复添加同类别联系人| 	addContact()相同姓名+类别| 	提示"已存在"拒绝添加| 
|-------------|-------------|-------------| 
| 文件异常操作	| 删除/修改contacts.dat	| 启动时自动重建数据文件| 
|-------------|-------------|-------------| 
| 容量边界测试	| 连续添加1000联系人| 	第1001次提示"通讯录已满"| 


##📅 未来计划
 实现正则表达式模糊搜索
 增加AES数据加密功能
 开发Qt图形界面
 支持多分类标签（非仅办公/个人）
 添加生日提醒功能
 
##🤝 参与贡献
欢迎提交Issue或PR，请遵循以下流程：
Fork项目仓库
创建特性分支（git checkout -b feature/新功能）
提交修改（git commit -m '添加新功能'）
推送分支（git push origin feature/新功能）
发起Pull Request
课程设计成果 | 开发者：夏雨子卓 | 2025级计算机科学与技术专业

#include <iostream>
#include <string>
#include "PlantHead.h"

using namespace std;

ostream& operator<< (ostream &output, Plant &needOutput) {
	//输出流运算符重载，输出植物名字 
	output << needOutput.name_;
	
	return output;
} 

Plant::Plant() {
	// Plant 无参构造 
	name_ = "植物";
	pHP_ = new int(0);
	attack_ = 0;
	defence_ = 0;
}

Plant::Plant(const string name) {
	// Plant 有参构造 
	name_ = name;
}

Plant::Plant(int HP, int attack, int defence) {
	// Plant 有参构造 
	pHP_ = new int(0);
	*pHP_ = HP;
	attack_ = attack;
	defence_ = defence;
}

Plant::Plant(string name, int HP, int attack, int defence) {
	// Plant 有参构造 
	name_ = name;
	pHP_ = new int(0);
	*pHP_ = HP;
	attack_ = attack;
	defence_ = defence;
}

Plant::~Plant() {
	// Plant 析构函数 
	delete pHP_;
}

Pear::Pear():Plant() {
	// Pear 无参构造 
	attackBonus_ = 0;
}

Pear::Pear(int attackBonus) {
	// Pear 有参构造
	attackBonus_ = attackBonus;
} 

Pear::Pear(string name, int HP, int attack, int defence ,int attackBonus):Plant(name, HP, attack, defence) {
	// Pear 有参构造 
	attackBonus_ = attackBonus;
	//当前攻击力为初始攻击力加上攻击力加成 
	attack_ = attack_ + attackBonus_; 
}

Pear::~Pear() {
	// Pear 析构函数 
	delete pHP_;
}

void Pear::setPear(string name, int HP, int attack, int defence ,int attackBonus) {
	//设置 Pear 的属性 
	name_ = name;
	*pHP_ = HP;
	attack_ = attack;
	defence_ = defence;
	attackBonus_ = attackBonus;
	
	attack_ = attack_ + attackBonus_;
} 

void Pear::display() {
	//展示 Pear 的属性 
	cout << "植物名称: " << name_ << endl;
	cout << "  生命值: " << *pHP_ << endl;
	cout << "  攻击力: " << attack_ << endl;
	cout << "  防御力: " << defence_ << endl;
	cout << "攻击加成: " << attackBonus_ << endl << endl; 
}

Apple::Apple():Plant() {
	// Apple 无参构造 
	defenceBonus_ = 0;
}

Apple::Apple(int defenceBonus) {
	// Apple 有参构造 
	defenceBonus_ = defenceBonus;
}

Apple::Apple(string name, int HP, int attack, int defence ,int defenceBonus):Plant(name, HP, attack, defence) {
	// Apple 有参构造
	defenceBonus_ = defenceBonus;
	
	defence_ = defence_ + defenceBonus_; 
}

Apple::~Apple() {
	// Apple 析构函数
	delete pHP_; 
}

void Apple::setApple(string name, int HP, int attack, int defence, int defenceBonus) {
	//设置 Apple 的属性 
	name_ = name;
	*pHP_ = HP;
	attack_ = attack;
	defence_ = defence;
	defenceBonus_ = defenceBonus;
	
	defence_ = defence_ + defenceBonus_;
}

void Apple::display() {
	//展示 Apple 的属性 
	cout << "植物名称: " << name_ << endl;
	cout << "  生命值: " << *pHP_ << endl;
	cout << "  攻击力: " << attack_ << endl;
	cout << "  防御力: " << defence_ << endl;
	cout << "防御加成: " << defenceBonus_ << endl << endl;	
} 

ApplePear::ApplePear():Plant(), Apple(), Pear() {
	// ApplePear 无参构造 
} 

ApplePear::ApplePear(int attackBonus, int defenceBonus):Plant(), Pear(attackBonus), Apple(defenceBonus) {
	// ApplePear 有参构造 
}

ApplePear::ApplePear(string name, int HP, int attack, int defence, int attackBonus, int defenceBonus)
		  			:Plant(name, HP, attack, defence), Pear(attackBonus), Apple(defenceBonus) {
	// ApplePear 有参构造 
	attack_ = attack_ + attackBonus_;
	defence_ = defence_ + defenceBonus_;
}

ApplePear::~ApplePear() {
	// ApplePear 析构函数 
	delete pHP_;
}

void ApplePear::setApplePear(string name, int HP, int attack, int defence, int attackBonus, int defenceBonus) {
	//设置 ApplePear 的属性 
	name_ = name;
	*pHP_ = HP;
	attack_ = attack;
	defence_ = defence;
	attackBonus_ = attackBonus; 
	defenceBonus_ = defenceBonus;
	
	attack_ = attack_ + attackBonus_;
	defence_ = defence_ + defenceBonus_;
}

void ApplePear::display() {
	//展示 ApplePear 的属性 
	cout << "植物名称: " << name_ << endl;
	cout << "  生命值: " << *pHP_ << endl;
	cout << "  攻击力: " << attack_ << endl;
	cout << "  防御力: " << defence_ << endl;
	cout << "攻击加成: " << attackBonus_ << endl; 
	cout << "防御加成: " << defenceBonus_ << endl << endl;
}

void displayPlant(Plant &plant) {
	//展示植物的属性 
	plant.display();
} 

string Pear::getName() {
	return name_;
}

int Pear::getHP() {
	return *pHP_;
}

int Pear::getAttack() {
	return attack_;
}

int Pear::getDefence() {
	return  defence_;
}

string Apple::getName() {
	return name_;
}

int Apple::getHP() {
	return *pHP_;
}

int Apple::getAttack() {
	return attack_;
}

int Apple::getDefence() {
	return  defence_;
}

string ApplePear::getName() {
	return name_;
}

int ApplePear::getHP() {
	return *pHP_;
}

int ApplePear::getAttack() {
	return attack_;
}

int ApplePear::getDefence() {
	return  defence_;
}

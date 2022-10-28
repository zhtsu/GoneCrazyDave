#include <iostream>
#include <string>
#include "ZombieHead.h"

using namespace std;

ostream& operator<< (ostream &output, Zombie &needOutput) {
	//输出流运算符重载，输出僵尸名字 
	output << needOutput.name_;
	
	return output;
} 

Zombie::Zombie() {
	// Zombie 无参构造 
	name_ = "僵尸";
	pHP_ = new int(0);
	attack_ = 0;
	defence_ = 0;
}

Zombie::Zombie(const string name) {
	// Zombie 有参构造 
	name_ = name;
}

Zombie::Zombie(int HP, int attack, int defence) {
	// Zombie 有参构造 
	pHP_ = new int(0);
	*pHP_ = HP;
	attack_ = attack;
	defence_ = defence;
}

Zombie::Zombie(string name, int HP, int attack, int defence) {
	// Zombie 有参构造 
	name_ = name;
	pHP_ = new int(0);
	*pHP_ = HP;
	attack_ = attack;
	defence_ = defence;
}

Zombie::~Zombie() {
	// Zombie 析构函数 
	delete pHP_;
}

CommonZombie::CommonZombie():Zombie() {
	//CommonZombie 无参构造 
}

CommonZombie::CommonZombie(string name, int HP, int attack, int defence):Zombie(name, HP, attack, defence) {
	//CommonZombie 有参构造 
}

CommonZombie::~CommonZombie() {
	//CommonZombie 析构函数 
	delete pHP_;
}

void CommonZombie::setCommonZombie(string name, int HP, int attack, int defence) {
	//设置 CommonZombie 的属性
	name_ = name;
	*pHP_ = HP;
	attack_ = attack;
	defence_ = defence;
}

void CommonZombie::display() {
	//展示 CommonZombie 的属性 
	cout << "僵尸名称: " << name_ << endl;
	cout << "  生命值: " << *pHP_ << endl;
	cout << "  攻击力: " << attack_ << endl;
	cout << "  防御力: " << defence_ << endl;
}

FlagZombie::FlagZombie():Zombie() {
	// FlagZombie 无参构造 
	attackBonus_ = 0; 
}

FlagZombie::FlagZombie(int attackBonus):Zombie() {
	// FlagZombie 有参构造 
	attackBonus_ = attackBonus;
}

FlagZombie::FlagZombie(string name, int HP, int attack, int defence ,int attackBonus):Zombie(name, HP, attack, defence) {
	// FlagZombie 有参构造 
	attackBonus_ = attackBonus;
	
	attack_ = attack_ + attackBonus_;
}

FlagZombie::~FlagZombie() {
	// FlagZombie 析构函数 
	delete pHP_;
} 

void FlagZombie::setFlagZombie(string name, int HP, int attack, int defence ,int attackBonus) {
	//设置旗帜僵尸的属性
	name_ = name;
	*pHP_ = HP;
	attack_ = attack;
	defence_ = defence;
	attackBonus_ = attackBonus;
	
	attack_ = attack_ + attackBonus_; 
}

void FlagZombie::display() {
	//展示 FlagZombie 的属性 
	cout << "僵尸名称: " << name_ << endl;
	cout << "  生命值: " << *pHP_ << endl;
	cout << "  攻击力: " << attack_ << endl;
	cout << "  防御力: " << defence_ << endl;
	cout << "攻击加成: " << attackBonus_ << endl;  
}

GiantZombie::GiantZombie():Zombie() {
	// GiantZombie 无参构造 
	defenceBonus_ = 0;
}

GiantZombie::GiantZombie(int defenceBonus):Zombie() {
	// GiantZombie 有参构造 
	defenceBonus_ = defenceBonus;
}

GiantZombie::GiantZombie(string name, int HP, int attack, int defence ,int defenceBonus):Zombie(name, HP, attack, defence) {
	// GiantZombie 有参构造 
	defenceBonus_ = defenceBonus;
	
	defence_ = defence_ + defenceBonus_;
}

GiantZombie::~GiantZombie() {
	// GiantZombie 析构函数 
	delete pHP_;
} 

void GiantZombie::setGiantZombie(string name, int HP, int attack, int defence ,int defenceBonus) {
	//设置巨人僵尸的属性
	name_ = name;
	*pHP_ = HP;
	attack_ = attack;
	defence_ = defence;
	defenceBonus_ = defenceBonus;
	
	defence_ = defence_ + defenceBonus_; 
}

void GiantZombie::display() {
	//展示 GiantZombie 的属性 
	cout << "僵尸名称: " << name_ << endl;
	cout << "  生命值: " << *pHP_ << endl;
	cout << "  攻击力: " << attack_ << endl;
	cout << "  防御力: " << defence_ << endl;
	cout << "防御加成: " << defenceBonus_ << endl;  
}

void displayZombie(Zombie &zombie) {
	//展示僵尸的属性 
	zombie.display();
}

string CommonZombie::getName() {
	return name_;
}

int CommonZombie::getHP() {
	return *pHP_;
}

int CommonZombie::getAttack() {
	return attack_;
}

int CommonZombie::getDefence() {
	return  defence_;
}

string FlagZombie::getName() {
	return name_;
}

int FlagZombie::getHP() {
	return *pHP_;
}

int FlagZombie::getAttack() {
	return attack_;
}

int FlagZombie::getDefence() {
	return  defence_;
}

string GiantZombie::getName() {
	return name_;
}

int GiantZombie::getHP() {
	return *pHP_;
}

int GiantZombie::getAttack() {
	return attack_;
}

int GiantZombie::getDefence() {
	return  defence_;
}

#include <iostream>
#include <string.h>
#include "ZombieHead.h"
#include "PlantHead.h"
#include "CombatHead.h"
#include "MyBrushHead.h"

using namespace std;

CombatantMSG CombatantMSG::operator=(Zombie &zombie) {
	//赋值运算符 = 重载，用于将 Zombie 和 Plant 类型转换为 CombatantMSG 类型
	_name = zombie.name_;
	_HP = *zombie.pHP_;
	_attack = zombie.attack_;
	_defence = zombie.defence_;

	return *this;
}

CombatantMSG CombatantMSG::operator=(Plant &plant) {
	//用于将 Zombie 和 Plant 类型转换为 CombatantMSG 类型
	_name = plant.name_;
	_HP = *plant.pHP_;
	_attack = plant.attack_;
	_defence = plant.defence_;

	return *this;
}

bool CombatantMSG::operator== (Zombie &zombie) {
	//通过判断 name 判断 CombatantMSG 内的数据是否和 Zombie 或 Plant 类相等
	bool flag = true;
	
	if (strcmp(_name.c_str(), zombie.name_.c_str()) != 0) {
		flag = false;
	}
	
	return flag;
}

bool CombatantMSG::operator== (Plant &plant) {
	//通过判断 name 判断 CombatantMSG 内的数据是否和 Zombie 或 Plant 类相等
	bool flag = true;
	
	if (strcmp(_name.c_str(), plant.name_.c_str()) != 0) {
		flag = false;
	}
	
	return flag;
}

Combat::Combat() {
	//无参构造
	flag_ = 1;
	gapSeconds_ = 0;
	zombie_ = NULL;
	plant_ = NULL;
}

Combat::Combat(Zombie *zombie, Plant *plant) {
	//有参构造
	flag_ = 1;
	gapSeconds_ = 0;
	zombie_ = zombie;
	plant_ = plant;
}

void Combat::setCombatant(Zombie *zombie, Plant *plant) {
	//设置作战人员
	zombie_ = zombie;
	plant_ = plant;
}

void Combat::setDisplayGapSenonds(double gapSeconds) {
	//设置播放每回合战斗信息的时间间隔
	gapSeconds_ = gapSeconds;
}

bool Combat::isNoResult() {
	//通过计算血量判断游戏是否继续
	bool flag = true;

	if (*(plant_->pHP_) <= 0 || *(zombie_->pHP_) <= 0) {
		flag = false;
	}

	return flag;
}

void Combat::switchSound() {
	//根据 flag_ 的单双数切换回合，即设定当前回合进攻方和防守方
	if (flag_ % 2 != 0) {
		offensive_ = *plant_;
		defender_ = *zombie_;
	} else {
		offensive_ = *zombie_;
		defender_ = *plant_;
	}
}

void Combat::calculateHurt() {
	//从此处开始战斗，判断攻击方攻击力是否大于防御方防御力，大于则计算出伤害，否则伤害为 1
	if (offensive_._attack > defender_._defence) {
		hurt_ = offensive_._attack - defender_._defence;
	} else {
		hurt_ = 1;
	}
} 

void Combat::calculateHP() {
	//判断出当前的防守方，并对其血量进行操作 
	calculateHurt();
	defender_._HP -= hurt_;
	
	if (defender_ == *plant_) {
		*(plant_->pHP_) -= hurt_;
	} else {
		*(zombie_->pHP_) -= hurt_;
	}
}

void Combat::showHP() {
	//输出当前剩余血量 
	MyBrush drawHP;
	
	drawHP.earse_in_lateral(15, 10, 50);
	drawHP.setOriginPosition(15, 10);
	cout << plant_->name_ << " HP: "  << *(plant_->pHP_);
	drawHP.setOriginPosition(43, 10);
	cout << zombie_->name_ << " HP: " << *(zombie_->pHP_);
	drawHP.setOriginPosition(15, 6);
} 

void Combat::drawPlant(int namePositionX, int namePositionY, int bodyPositionX, int bodyPositionY) {
	//绘制植物类战斗形象 
	MyBrush drawPlant;
	
	drawPlant.draw_in_lateral(namePositionX, namePositionY, plant_->name_);
	drawPlant.drawTriangle(bodyPositionX, bodyPositionY, 'P', 5); 
} 

void Combat::drawZombie(int namePositionX, int namePositionY, int bodyPositionX, int bodyPositionY) {
	//绘制僵尸类战斗形象 
	MyBrush drawZombie;
	
	drawZombie.draw_in_lateral(namePositionX, namePositionY, zombie_->name_);
	drawZombie.drawTriangle(bodyPositionX, bodyPositionY, 'Z', 5); 
}

void Combat::earsePlant(int namePositionX, int namePositionY, int bodyPositionX, int bodyPositionY) {
	//擦除植物类战斗形象 
	MyBrush drawPlant;
	
	drawPlant.earse_in_lateral(namePositionX, namePositionY, plant_->name_.length());
	drawPlant.earseTriangle(bodyPositionX, bodyPositionY, 5); 	
}

void Combat::earseZombie(int namePositionX, int namePositionY, int bodyPositionX, int bodyPositionY) {
	//擦除僵尸类战斗形象 
	MyBrush drawZombie;
	
	drawZombie.earse_in_lateral(namePositionX, namePositionY, zombie_->name_.length());
	drawZombie.earseTriangle(bodyPositionX, bodyPositionY, 5); 
}

void Combat::displayCombatAnimation(double FramesGapSenonds) {
	//播放战斗动画, 可设置每一帧间隔的秒数 
	drawPlant(18, 14, 15, 15); drawZombie(47, 14, 45, 15);
	Sleep(FramesGapSenonds * 1000);
	earsePlant(18, 14, 15, 15); earseZombie(47, 14, 45, 15);

	drawPlant(27, 14, 24, 15); drawZombie(37, 14, 35, 15);
	Sleep(FramesGapSenonds * 1000);
	earsePlant(27, 14, 24, 15); earseZombie(37, 14, 35, 15);
	
	drawPlant(18, 14, 15, 15); drawZombie(47, 14, 45, 15);
	Sleep(FramesGapSenonds * 1000);
} 

void Combat::showDead(CombatantMSG nowCharacter) {
	//展示死亡时的角色情况，即擦除死亡角色 
	if (nowCharacter == *plant_) {
		earsePlant(18, 14, 15, 15);
	} else {
		earseZombie(47, 14, 45, 15);
	}
}

void Combat::showTextLog() {
	//输出当前战斗信息 
	if (offensive_._HP <= 0) {
		cout << offensive_._name << " 战败了。。。 ";
		showDead(offensive_);
	} else if (defender_._HP <= 0) {
		cout << defender_._name << " 战败了。。。 ";
		showDead(defender_);
	} else {
		cout << offensive_._name << " 攻击了 " << defender_._name << "。" << "造成了 " << hurt_ << " 点伤害" << endl; 
	};
	Sleep(gapSeconds_ * 1000); 
}

void Combat::displayBoutCombatLog() {
	//播放一个回合的战斗
	if (isNoResult() == true) {
		switchSound();
		calculateHP();
		showHP();
		showTextLog();
	} 
	
	flag_++;//切换回合 
}

void Combat::displayAllCombatLog() {
	//播放所有战斗
	MyBrush brush;
	
	system("cls");//清理上一个界面 
	brush.drawRectangle(0, 0, 74 , 24, '@');//绘制边框
	brush.setOriginPosition(27, 3);
	cout << '@' << plant_->name_ << " VS "	<< zombie_->name_ << '@';

	brush.draw_in_lateral(30, 10, "战斗即将开始", 1, 0.3);
	brush.earse_in_lateral(30, 10, 12);
	showHP();
	
	while (isNoResult() == true) {
		displayCombatAnimation(1);
		brush.earse_in_lateral(15, 6, 40);
		brush.setOriginPosition(15, 6);
		displayBoutCombatLog();
	}
}

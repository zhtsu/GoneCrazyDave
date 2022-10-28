#include <iostream>
#include <string.h>
#include <conio.h>

#include "ZombieHead.h"
#include "PlantHead.h"
#include "CombatHead.h"
#include "MyBrushHead.h"
#include "MyHead.h"
#include "MyFileHead.h"

using namespace std;

void startGameOfFile() {
	//从文件读档
	MyFile file("GameMSG.dat");
	int level;
	
	try {
		level = file.getFileData(); 
	} catch (bool) {
		showMainMenu();	
	}
	
	showNeededLevel(level); 
}

void showNeededLevel(int level) {
	//根据 level 的值读取不同的关卡 
	Apple apple("苹果", 10, 10, 3, 2);
	Pear pear("梨子", 10, 10, 3, 2);
	ApplePear applePear ("苹果梨", 5, 20, 6, 6, 6);
	
	if (level == 1) {
		showOneLevel();
		showPlantAttributeInGame(&applePear);
		OneLevelMovePlant(&applePear);
	} else if (level == 2) {
		showTwoLevel();
		showPlantAttributeInGame(&applePear);
		twoLevelMovePlant(&applePear);
	} else {
		
	}
}

void SaveGame(double level) {
	//进行游戏存档 
	MyFile file("GameMSG.dat");
	 
	file.addUserData(level); 
}

void twoLevelBeforeCombat(Plant *plant, int level) {
	//第二关卡战斗前提示 
	MyBrush brush;
	GiantZombie one("戴夫僵尸", 10, 10, 10, 5);
	
	brush.earse_in_lateral(20, 21, 50);
	brush.draw_in_lateral(20, 20, "这只僵尸看起来很像疯狂戴夫 , 该怎么办..."); 
	brush.draw_in_lateral(24, 22, "ENTER进攻       ESC撤退");
	
	if (isEnterCombat() == true) {
		showTransition();
		displayCombat(&one, plant);
		showWin();
	} else {
		showTwoLevel();
		showPlantAttributeInGame(plant);
		twoLevelMovePlant(plant);
	}
}

void beforeBack(Plant *plant, int level) {
	//返回上一级提示 
	MyBrush brush;
	
	brush.earse_in_lateral(20, 21, 50);
	brush.draw_in_lateral(24, 20, "确定返回吗？"); 
	brush.draw_in_lateral(24, 22, "ENTER确定       ESC取消");
	
	if (isEnterCombat() == true) {
		showOneLevel();
		showPlantAttributeInGame(plant);
		OneLevelMovePlant(plant);
	} else {
		showTwoLevel();
		showPlantAttributeInGame(plant);
		twoLevelMovePlant(plant);
	}
} 

void twoLevelMovePlant(Plant *plant) {
	//第一关根据键盘键入值移动植物
	char key;
	COORD pos = {36, 12};
	
	showPlant(36, 12, plant);
	for (; ; key = getch()) {	
		if (key == 72) {
			pos = upMove(pos.X, pos.Y, plant);
		} else if (key == 80) {
			pos = downMove(pos.X, pos.Y, plant);
		} else if (key == 75) {
			pos = leftMove(pos.X, pos.Y, plant);
		} else if (key == 77) {
			pos = rightMove(pos.X, pos.Y, plant);		
		} else {}
		if (pos.X == 53) {
			twoLevelBeforeCombat(plant, 1);
		} else if (pos.X == 20) {
			beforeBack(plant, 1);
		}
	} 
}

void showTwoLevel() {
	//输出第二关关卡地图
	MyBrush brush;
	
	system("cls"); 
	brush.draw_in_vertical(0, 0, '@', 25);
	brush.draw_in_vertical(74, 0, '@', 25);//绘制边框
	brush.drawRectangle(1, 0, 73, 6, '!');
	brush.drawRectangle(1, 18, 73, 24, '!');
	brush. drawTriangle(2, 7, '*', 4);
	brush. drawTriangle(12, 7, '*', 4);
	brush. drawTriangle(2, 12, '*', 4);
	brush. drawTriangle(12, 12, '*', 4);
	brush.draw_in_lateral(8, 12, "密林外围");
	brush. drawTriangle(55, 7, '*', 4);
	brush. drawTriangle(65, 7, '*', 4);
	brush. drawTriangle(55, 12, '*', 4);
	brush. drawTriangle(65, 12, '*', 4);
	brush.draw_in_lateral(61, 12, "密林深处");
	brush.draw_in_lateral(5, 3, "当前位置：密林");
	brush.draw_in_lateral(20, 21, "密林深处入口那有一只巨人僵尸..."); 
} 

void OneLevelBeforeCombat(Plant *plant, int level) {
	//第一关卡战斗前提示 
	MyBrush brush;
	CommonZombie one("普通僵尸", 10, 3, 3);
	
	brush.earse_in_lateral(20, 21, 50);
	brush.draw_in_lateral(20, 20, "密林外有一只普通僵尸，击杀他进入密林！"); 
	brush.draw_in_lateral(24, 22, "ENTER进攻       ESC撤退");
	
	if (isEnterCombat() == true) {
		showTransition();
		displayCombat(&one, plant);
		showTwoLevel();
		showPlantAttributeInGame(plant);
		twoLevelMovePlant(plant);
	} else {
		showOneLevel();
		showPlantAttributeInGame(plant);
		OneLevelMovePlant(plant);
	}
}

void showWin() {
	//游戏胜利界面 
	MyBrush brush;
	
	system("cls");
	brush.drawRectangle(0, 0, 74 , 24, '@');//绘制边框
	brush.draw_in_lateral(30, 6, "Happy End"); 
	brush.draw_in_lateral(26, 8, "当你消灭了所有僵尸", 1, 0.1); Sleep(900);
	brush.draw_in_lateral(26, 9, "你发现你来晚了", 1, 0.1); Sleep(900);
	brush.draw_in_lateral(26, 10, "疯狂戴夫已经被吃掉了", 1, 0.1); Sleep(900);
	brush.draw_in_lateral(26, 11, "所幸你找回了他的尸骨", 1, 0.1); Sleep(900);
	brush.draw_in_lateral(26, 12, "歪比巴卜依旧回荡在耳边...", 1, 0.1); Sleep(900);
	getch();
	gameMain(); 
}

bool isEnterCombat() {
	//判断玩家是否进入战斗
	bool flag = true; 
	char key; 
	
	for (; key != '\r' || key != 27; key = getch()) {
		if (key == 27) {
			flag = false; break;
		} else if(key == '\r') {
			break;
		}
	}

	return flag;
}

void showOneLevel() {
	//输出第一关关卡地图
	MyBrush brush;
	
	system("cls"); 
	brush.draw_in_vertical(0, 0, '@', 25);
	brush.draw_in_vertical(74, 0, '@', 25);//绘制边框
	brush.drawRectangle(1, 0, 73, 6, '!');
	brush.drawRectangle(1, 18, 73, 24, '!');
	brush. drawTriangle(55, 7, '*', 4);
	brush. drawTriangle(65, 7, '*', 4);
	brush. drawTriangle(55, 12, '*', 4);
	brush. drawTriangle(65, 12, '*', 4);
	brush.draw_in_lateral(62, 13, "密林");
	brush.draw_in_lateral(5, 3, "当前位置：郊外");
	brush.draw_in_lateral(20, 21, "密林是僵尸的地盘...我本不想踏足的"); 
} 

void showPlantAttributeInGame(Plant *plant) {
	//在游戏地图内显示植物的属性
	MyBrush brush; 
	
	brush.draw_in_lateral(32, 2,  "植物：");
	brush.draw_in_lateral(50, 2, "生命值：");
	brush.draw_in_lateral(30, 4, "攻击力：");
	brush.draw_in_lateral(50, 4, "防御力：");
	brush.earse_in_lateral(40, 2, 4);
	brush.setOriginPosition(40, 2); cout << plant->getName();
	brush.earse_in_lateral(60, 2, 4);
	brush.setOriginPosition(60, 2); cout << plant->getHP();
	brush.earse_in_lateral(40, 4, 4);
	brush.setOriginPosition(40, 4); cout << plant->getAttack();
	brush.earse_in_lateral(60, 4, 4);
	brush.setOriginPosition(60, 4); cout << plant->getDefence();
}

void showPlant(int originX, int originY, Plant *plant) {
	//在地图中输出植物形象 , 需指定位置 
	MyBrush brush;
	
	if (plant->getName() == "苹果") {
			brush.draw_in_lateral(originX, originY, "●");
	} else if(plant->getName() == "梨子") {
			brush.draw_in_lateral(originX, originY, "◆");
	} else if(plant->getName() == "苹果梨") { 
			brush.draw_in_lateral(originX, originY, "★");
	} else {}
}

void OneLevelMovePlant(Plant *plant) {
	//第一关根据键盘键入值移动植物
	char key;
	COORD pos = {5, 12};
	
	showPlant(5, 12, plant);
	for (; ; key = getch()) {	
		if (key == 72) {
			pos = upMove(pos.X, pos.Y, plant);
		} else if (key == 80) {
			pos = downMove(pos.X, pos.Y, plant);
		} else if (key == 75) {
			pos = leftMove(pos.X, pos.Y, plant);
		} else if (key == 77) {
			pos = rightMove(pos.X, pos.Y, plant);		
		} else {}
		if (pos.X == 53) {
			OneLevelBeforeCombat(plant, 1);
		}
	} 
}

COORD upMove(int originX, int originY, Plant *plant) {
    //向上移动指定位置的字符,返回存储此时字符坐标的结构体 
    MyBrush brush;
	COORD pos; 
	if (originY > 7) {
		brush.earse_in_lateral(originX, originY, 1);
		showPlant(originX, originY - 1, plant);
		brush.setOriginPosition(originX, originY - 1);
		pos.X = brush.getNowX();
		pos.Y = brush.getNowY();
	} else {
		showPlant(originX, originY, plant);
		brush.setOriginPosition(originX, originY);
		pos.X = brush.getNowX();
		pos.Y = brush.getNowY();
	}
	
	return pos;
}

COORD downMove(int originX, int originY, Plant *plant) {
	//向下移动
    MyBrush brush;
	COORD pos;
	
	if (originY < 17) {
		brush.earse_in_lateral(originX, originY, 1);
		showPlant(originX, originY + 1, plant);
		brush.setOriginPosition(originX, originY + 1);
		pos.X = brush.getNowX();
		pos.Y = brush.getNowY();
	} else {
		showPlant(originX, originY, plant);
		brush.setOriginPosition(originX, originY);
		pos.X = brush.getNowX();
		pos.Y = brush.getNowY();
	}
	
	return pos;
}

COORD leftMove(int originX, int originY, Plant *plant) {
    //向左移动 
    MyBrush brush;
	COORD pos;
	
	if (originX > 2) {
		brush.earse_in_lateral(originX, originY, 1);
		showPlant(originX - 1, originY, plant);  
		brush.setOriginPosition(originX - 1, originY);
		pos.X = brush.getNowX();
		pos.Y = brush.getNowY();
	} else {
		showPlant(originX, originY, plant);
		brush.setOriginPosition(originX, originY);
		pos.X = brush.getNowX();
		pos.Y = brush.getNowY();
	}

	return pos; 
}

COORD rightMove(int originX, int originY, Plant *plant) {
	//向右移动
    MyBrush brush;
	COORD pos;
	
	if (originX < 71) {
		brush.earse_in_lateral(originX, originY, 1);
		showPlant(originX + 1, originY, plant);	 
		brush.setOriginPosition(originX + 1, originY);
		pos.X = brush.getNowX();
		pos.Y = brush.getNowY();
	} else {
		showPlant(originX, originY, plant);
		brush.setOriginPosition(originX, originY);
		pos.X = brush.getNowX();
		pos.Y = brush.getNowY();
	}

	return pos;
}

void showTransition() {
	//输出过场动画
	MyBrush brush;
	
	system("mode con cols=75 lines=25");//设置 CMD 窗口大小
	for (int i = 0; i < 2; i++) {
		system("cls");
		brush.draw_in_lateral(30, 8, "游戏加载中...");
		brush.draw_in_lateral(30, 10, "▇", 8, 0.1);
	}
} 

void showGameBackground() {
	//文字输出游戏背景
	MyBrush brush;
	
	system("cls");
	brush.drawRectangle(0, 0, 74 , 24, '@');//绘制边框
	brush.draw_in_lateral(20, 8, "你像往常一样给向日葵浇水", 1, 0.09); Sleep(900);
	brush.draw_in_lateral(20, 9, "但今天和平时似乎有一些不一样", 1, 0.09); Sleep(900);
	brush.draw_in_lateral(20, 10, "疯狂戴夫不见了！", 1, 0.09); Sleep(900);
	brush.draw_in_lateral(20, 11, "一定是被僵尸抓走了", 1, 0.09); Sleep(900);
	brush.draw_in_lateral(20, 12, "你决定挑选一株植物前去营救疯狂戴夫...", 1, 0.09); Sleep(900);
	getch();
}

void showSelected(int originX, int originY) {
	//输出选择框
	MyBrush brush;
	
	brush.draw_in_lateral(originX, originY, ">>");
	brush.draw_in_lateral((originX + 12), originY, "<<");
}

int moveSelected(int originX, int originY, int finishX, int finishY ) {
	//移动指定位置的选择框到达目标位置 , 返回光标最后的 Y 坐标 
	MyBrush brush; 
	
	brush.earse_in_lateral(originX, originY, 2);
	brush.earse_in_lateral((originX + 12), originY, 2);
	brush.draw_in_lateral(finishX, finishY, ">>");
	brush.draw_in_lateral((finishX + 12), finishY, "<<");
	
	return finishY;
}

void displayCombat(Zombie *zombie, Plant *plant) {
	//根据对象指针播放战斗动画 
	system("cls");
	Combat fight(zombie, plant);
	fight.setDisplayGapSenonds(1.5);
	fight.displayAllCombatLog();
	getch();
	if (plant->getHP() < 0) {
		system("cls");
		MyBrush brush;
		brush.draw_in_lateral(30, 10, "你死掉了!");
		getch();
		showMainMenu(); 
	}
} 

void showPlantAttribute(Plant *plant) {
	//展示植物角色属性 
	MyBrush brush;
	
	showPlant(36, 12, plant);
	brush.earse_in_lateral(40, 9, 8);
	brush.setOriginPosition(40, 9); cout << plant->getName();
	brush.draw_in_lateral(30, 20, "植物");
	brush.earse_in_lateral(50, 20, 4);
	brush.setOriginPosition(50, 20); cout << plant->getHP();
	brush.earse_in_lateral(30, 22, 4);
	brush.setOriginPosition(30, 22); cout << plant->getAttack();
	brush.earse_in_lateral(50, 22, 4);
	brush.setOriginPosition(50, 22); cout << plant->getDefence();
}

int selectPlantMoveCommand(Plant *apple, Plant *pear, Plant *applePear) {
	//植物选择菜单 内根据键盘键入值切换植物,返回此时植物的代号
	int attempts = 1;//用于判断当前植物 
	char key; 
	
	for (; key != '\r'; key = getch()) {
		if (key == 75 || key == 77) {
			attempts++;
			if (attempts > 3) {
				attempts -= 3;
			}
		} 
	switch (attempts) {
		case 1:
			showPlantAttribute(apple);
			break;
		case 2:
			showPlantAttribute(pear);
			break;
		case 3:
			showPlantAttribute(applePear);
			break;
		default:{
			break;
		}	
	}
	} 
	
	return attempts;
}

void selectPlantCommand(Plant *apple, Plant *pear, Plant *applePear) {
	//选择植物界面操作响应 
	switch (selectPlantMoveCommand(apple, pear, applePear)) {
		case 1:
			showOneLevel();
			showPlantAttributeInGame(apple);
			OneLevelMovePlant(apple);
			break;
		case 2:
			showOneLevel();
			showPlantAttributeInGame(pear);
			OneLevelMovePlant(pear);
			break;
		case 3:
			showOneLevel();
			showPlantAttributeInGame(applePear);
			OneLevelMovePlant(applePear);
			break;
		default:{
			break;
		}	
	}
}

void showSelectPlant(Plant *apple, Plant *pear, Plant *applePear) {
	//显示植物选择界面
	MyBrush brush;
	
	system("cls");//清理上一个界面 
	brush.draw_in_vertical(0, 0, '@', 25);
	brush.draw_in_vertical(74, 0, '@', 25);//绘制边框
	brush.drawRectangle(1, 0, 73, 6, '!');
	brush.drawRectangle(1, 18, 73, 24, '!');
	brush.draw_in_lateral(30, 3, "请选择外出的植物");
	brush.draw_in_lateral(30, 9, "植物姓名：");
	brush.draw_in_lateral(22, 20, "种族：");
	brush.draw_in_lateral(40, 20, "生命值：");
	brush.draw_in_lateral(20, 22, "攻击力：");
	brush.draw_in_lateral(40, 22, "防御力：");
	brush.draw_in_lateral(5, 12, "<<<"); 
	brush.draw_in_lateral(67, 12, ">>>");
	
	selectPlantCommand(apple, pear, applePear); 
}

void showMainMenu() {
	//展示主菜单 
	MyBrush brush;
	
	system("cls");//清理上一个界面 
	brush.drawRectangle(0, 0, 74 , 24, '@');//绘制边框
	brush.draw_in_lateral(30, 5, "GoneCrazyDave");
	brush.draw_in_lateral(32, 8, "开始游戏");
	brush.draw_in_lateral(32, 10, "读取存档");
	brush.draw_in_lateral(32, 12, "退出游戏");
	brush.draw_in_lateral(27, 16, "↑↓选择 ENTER进入");
	
	mainMenuCommand(); 
}

int mainMenuMoveCommand() {
	// 主菜单 内根据键盘键入值移动光标,返回此时光标所指命令的代号
	int attempts = 1;//用于判断玩家的操作 
	char key; 
	
	showSelected(29,8);//绘制光标 
	for (; key != '\r'; key = getch()) {
		if (key == 72) {//为 ↑键时
			if (attempts == 1) {
			} else if (attempts == 2){
				moveSelected(29, 10, 29, 8);
				attempts = 1;
			} else {
				moveSelected(29, 12, 29, 10);
				attempts = 2;
			}
		} 
		else if (key == 80) {//为 ↓键时 
			if (attempts == 1) {
				moveSelected(29, 8, 29, 10);
				attempts = 2;
			} else if (attempts == 2) {
				moveSelected(29, 10, 29, 12);
				attempts = 3;
			} else {
			}
		} else {
			continue;
		}
	} 
	
	return attempts; 
}

void mainMenuCommand() {
	//响应主菜单的键盘输入 
	Apple apple("苹果", 10, 10, 3, 2);
	Pear pear("梨子", 10, 10, 3, 2);
	ApplePear applePear ("苹果梨", 5, 20, 6, 6, 6);
	
	switch (mainMenuMoveCommand()) {
		case 1:
			showGameBackground(); 
			showSelectPlant(&apple, &pear, &applePear);
			break;
		case 2:
			startGameOfFile();
			break;
		case 3:
			system("cls");
			SaveGame(2); 
			exit(1); break;
		default: {
		}
	}
} 

void gameMain() {
	//游戏入口，游戏的主要逻辑实现
	showTransition();
	showMainMenu(); 
}

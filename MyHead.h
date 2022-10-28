#include <iostream>
#include <string>

using namespace std;

//全局函数声明部分 

void gameMain();            //游戏入口
void startGameOfFile();     //从文件读档 
void SaveGame(double level);//游戏存档 
void showNeededLevel(int level); //输出对应的关卡 
void showWin();         //游输出戏胜利界面  
void showTwoLevel();    //输出第二关关卡地图
void twoLevelMovePlant(Plant *plant);//第二关移动植物 
void beforeBack(Plant *plant, int level); //返回上一级提示
void twoLevelBeforeCombat(Plant *plant, int level);//第二关卡战都前提示 
void OneLevelBeforeCombat(Plant *plant, int level);//关卡战斗前提示 
bool isEnterCombat();                              //判断玩家是否进图战斗 
void showGameBackground();                         //输出游戏背景故事
void showTransition();                             //输出过场动画 
void showSelectPlant(Plant *apple, Plant *pear, Plant *applePear);       //显示选择植物界面
int selectPlantMoveCommandr(Plant *apple, Plant *pear, Plant *applePear);//根据键盘键入值切换植物 
void selectPlantCommand(Plant *apple, Plant *pear, Plant *applePear);    //选择植物界面操作响应 
void showPlant(int originX, int originY, Plant *plant);//输出植物角色形象 
void showOneLevel();                                   //输出第一关地图 
void OneLevelMovePlant(Plant *plant);				   //第一关卡内移动植物角色形象 
void showPlantAttribute(Plant *plant);      //展示植物角色属性 
void showPlantAttributeInGame(Plant *plant);//在游戏内显示角色属性 
void showMainMenu();                  //显示主菜单
int mainMenuMoveCommand();            //根据键盘键入值移动选择框 
void mainMenuCommand();               //主菜单操作命令 
void showSelected(int originX, int originY);                         //在指定位置显示用于选择的选择框 
int moveSelected(int originX, int originY, int finishX, int finishY);//移动指定位置的选择框到末位置 
void displayCombat(Zombie *zombie, Plant *plant);                    //播放第一层的战斗动画 
COORD upMove(int originX, int originY, Plant *plant);           //向上移动指定位置的字符
COORD downMove(int originX, int originY, Plant *plant);         //向下移动
COORD leftMove(int originX, int originY, Plant *plant);         //向左移动 
COORD rightMove(int originX, int originY, Plant *plant);        //向右移动 




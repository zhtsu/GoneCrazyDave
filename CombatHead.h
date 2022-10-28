#include <iostream>
#include <string>

using namespace std;

class CombatantMSG {
	//用于接收战斗人员的相关属性，方便处理(当做结构体使用)
	public:
		string _name;
		int _HP;
		int _attack;
		int _defence;

		//赋值运算符 = 重载，用于将 Zombie 和 Plant 类型转换为 CombatantMSG 类型
		CombatantMSG operator= (Zombie &zombie);
		CombatantMSG operator= (Plant &plant);
		//关系运算符 == 重载，判断 CombatantMSG 类型内的数据是否和 Zombie 或 Plant 类型内相等 
		bool operator== (Zombie &zombie);
		bool operator== (Plant &plant);
};

class Combat {
	//作战类，用于处理对战信息
	public:
		Combat();
		Combat(Zombie *zombie, Plant *plant);//构造函数

	public:
		void setCombatant(Zombie *zombie, Plant *plant); //设置战斗人员
		void setDisplayGapSenonds(double gapSeconds);       //设置播放信息的时间间隔秒数
		bool isNoResult();           //判断游戏是否继续
		void switchSound();          //切换回合
		void calculateHurt();		 //计算伤害 
		void calculateHP();          //计算剩余血量
		void showHP();               //输出剩余血量
		void showTextLog();          //文字输出当前战斗信息 
		void displayBoutCombatLog(); //播放一回合战斗
		void displayAllCombatLog();  //播放所有战斗
		
	private:
		//播放战斗动画 ,可设置每帧之间间隔秒数
		void displayCombatAnimation(double FramesGapSenonds = 0.1); 
		void drawPlant(int namePositionX, int namePositionY, int bodyPositionX, int bodyPositionY);//指定位置绘制植物类角色
		void drawZombie(int namePositionX, int namePositionY, int bodyPositionX, int bodyPositionY);//指定位置绘制僵尸类角色
		void earsePlant(int namePositionX, int namePositionY, int bodyPositionX, int bodyPositionY);//擦除植物类角色
		void earseZombie(int namePositionX, int namePositionY, int bodyPositionX, int bodyPositionY);//擦除僵尸类角色
		void showDead(CombatantMSG nowCharacter);//展示死亡时的角色情况 

	private:
		int flag_;              //标记当前回合
		double gapSeconds_;     //播放战斗信息间隔秒数
		Zombie *zombie_;        //僵尸类角色
		Plant *plant_;		    //植物类角色
		CombatantMSG offensive_;//接收进攻方属性
		CombatantMSG defender_; //接收防守方属性
		int hurt_;              //一次攻击的伤害
};

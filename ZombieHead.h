#include <iostream>
#include <string>

using namespace std;

class Zombie {
	//僵尸类 (抽象类)
	friend class Combat; 
	friend class CombatantMSG;
	friend ostream& operator<< (ostream &output, Zombie &needOutput);//流运算符，仅输出名字 
	
	public:
		Zombie();
		Zombie(const string name);
		Zombie(int HP, int attack, int defence);
		Zombie(string name, int HP, int attack, int defence);//构造函数 
		virtual ~Zombie();//虚析构函数 
		
	public:
		virtual void display() = 0;
		virtual string getName() = 0;//各种 get 
		virtual int getHP() = 0;
		virtual int getAttack() = 0;
		virtual int getDefence() = 0;
	
	protected:
		string name_; //姓名 
		int *pHP_;    //生命值 
		int attack_;  //攻击力 
		int defence_; //防御力 
};

class CommonZombie:public Zombie {
	//普通僵尸类 
	public:
		CommonZombie();
		CommonZombie(string name, int HP, int attack, int defence);
		~CommonZombie();//析构函数 
		
	public:
		string getName();//各种 get 
		int getHP();
		int getAttack();
		int getDefence();
		
	public:
		void setCommonZombie(string name, int HP, int attack, int defence);//设置普通僵尸的属性 
		void display();
}; 

class FlagZombie:public Zombie {
	//旗帜僵尸类 
	public:
		FlagZombie();
		FlagZombie(int attackBonus);
		FlagZombie(string name, int HP, int attack, int defence ,int attackBonus);//构造函数 
		~FlagZombie();
		
	public:
		void setFlagZombie(string name, int HP, int attack, int defence ,int attackBonus);
		void display();
		string getName();//各种 get 
		int getHP();
		int getAttack();
		int getDefence();
		
	protected:
		int attackBonus_;//攻击力加成 
};

class GiantZombie:public Zombie {
	//巨人僵尸类
	public:
		GiantZombie();
		GiantZombie(int defenceBonus);
		GiantZombie(string name, int HP, int attack, int defence ,int defenceBonus);//构造函数 
		~GiantZombie();//析构函数 
		
	public:
		void setGiantZombie(string name, int HP, int attack, int defence ,int defencBonus);
		void display();
		string getName();//各种 get 
		int getHP();
		int getAttack();
		int getDefence();
		
	protected:
		int defenceBonus_;//防御力加成 
}; 

void displayZombie(Zombie &zombie);

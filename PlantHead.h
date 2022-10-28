#include <iostream>
#include <string>

using namespace std;

class Plant {
	//植物类 (抽象类)
	friend class Combat;
	friend class CombatantMSG;
	friend ostream& operator<< (ostream &output, Plant &needOutput);
	
	public:  
		Plant();
		Plant(const string name);
		Plant(int HP, int attack, int defence);
		Plant(string name, int HP, int attack, int defence);//构造函数
		virtual ~Plant();//虚析构函数
		
	public: 
		virtual void display() = 0;//展示植物属性（纯虚函数） 
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

class Pear:virtual public Plant {
	//梨子类 
	public:
		Pear();
		Pear(int attackAddition);
		Pear(string name, int HP, int attack, int defence ,int attackBonus);//构造函数 
		~Pear();
		
	public:
		void setPear(string name, int HP, int attack, int defence ,int attackBonus);
		void display();
		string getName();//各种 get 
		int getHP();
		int getAttack();
		int getDefence();
		
	protected:
		int attackBonus_;//攻击力加成 
};

class Apple:virtual public Plant {
	//苹果类
	public:
		Apple();
		Apple(int defenceAddition);
		Apple(string name, int HP, int attack, int defence ,int defenceBonus);//构造函数 
		~Apple();//析构函数 
		
	public:
		void setApple(string name, int HP, int attack, int defence ,int defenceBonus);
		void display();
		string getName();//各种 get 
		int getHP();
		int getAttack();
		int getDefence();
		
	protected:
		int defenceBonus_;//防御力加成 
}; 

class ApplePear:public Apple, public Pear {
	//苹果梨类 
	public:
		ApplePear();
		ApplePear(int attackAddition, int defenceBonus);
		ApplePear(string name, int HP, int attack, int defence, int attackBonus, int defenceBonus);
		~ApplePear();//析构函数 
		
	public:
		void setApplePear(string name, int HP, int attack, int defence, int attackBonus, int defenceBonus);//设置苹果梨的属性 
		void display();
		string getName();//各种 get 
		int getHP();
		int getAttack();
		int getDefence();
}; 

void displayPlant(Plant &plant);

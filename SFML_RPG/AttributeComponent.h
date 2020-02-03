#pragma once
class AttributeComponent
{
public:
	//Leveling
	int level;
	int exp;
	int expNext;
	int attributePoints;

	//Attribute
	int strength; //����
	int vitality; //���������
	int dexterity; //��������
	int agillity; //�����������
	int intelligence; //��������

	//Stats
	int hp;
	int hpMax;
	int damageMin;
	int damageMax;
	int accuracy;
	int defence;
	int luck;

	//const /destr
	AttributeComponent(int level);
	virtual ~AttributeComponent();

	//func
	std::string debugPrint() const;

	void gainExp(const int exp);
	void updateStats(const bool reset);
	void updateLevel();

	void update();
};


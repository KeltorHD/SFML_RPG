#pragma once
class AttributeComponent
{
public:
	//Leveling
	unsigned level;
	unsigned exp;
	unsigned expNext;
	unsigned attributePoints;

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
	AttributeComponent(unsigned level);
	virtual ~AttributeComponent();

	//func
	std::string debugPrint() const;

	void gainExp(const unsigned exp);
	void updateStats(const bool reset);
	void updateLevel();

	void update();
};


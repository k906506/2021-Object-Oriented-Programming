#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
	string name;	// �̸�
	string kind;	// ����
public:
	Animal(string name, string kind) : name(name), kind(kind) {}
};

class Bird : public Animal {
protected:
	string size;	// ũ��
	string activeTime;	// Ȱ�� �ð�
public:
	Bird(string name, string kind, string size, string activeTime) : size(size), activeTime(activeTime), Animal(name, kind) {}
	virtual void showInfo1() { cout << "Name : " << name << " / Kind : " << kind << endl; }
	virtual void showInfo2() { cout << "Size : " << size << " / ActiveTime : " << activeTime << endl; }
};

class Dog : public Animal {
protected:
	string purpose;	// ����
	string country;	// ��� ����
public:
	Dog(string name, string kind, string purpose, string country) : purpose(purpose), country(country), Animal(name, kind) {}
	virtual void showInfo1() { cout << "Name : " << name << " / Kind : " << kind << endl; }
	virtual void showInfo2() { cout << "Purpose : " << purpose << " / Country : " << country << endl; }
};

class Jindo : public Dog {	// ������
	int jindoAge;
	int jindoSpeed;
public:
	Jindo(string name, string kind, string purpose, string country, int jindoAge, int jindoSpeed) : jindoAge(jindoAge), jindoSpeed(jindoSpeed), Dog(name, kind, purpose, country) {}
	void showInfo1() { cout << "Name : " << name << " / Age : " << jindoAge << " / Kind : " << kind << endl; }
	void showInfo2() { cout << "Purpose : " << purpose << " / Speed : " << jindoSpeed << "km/s / Country : " << country << endl; }
};

class Doberman : public Dog {	// ��������
	int dobermanAge;
	int dobermanSpeed;
public:
	Doberman(string name, string kind, string purpose, string country, int dobermanAge, int dobermanSpeed) : dobermanAge(dobermanAge), dobermanSpeed(dobermanSpeed), Dog(name, kind, purpose, country) {}
	void showInfo1() { cout << "Name : " << name << " / Age : " << dobermanAge << " / Kind : " << kind << endl; }
	void showInfo2() { cout << "Purpose : " << purpose << " / Speed : " << dobermanSpeed << "km/s / Country : " << country << endl; }
};

class Pomeranian : public Dog {	// ���޶�Ͼ�
	int pomeranianAge;
	int pomeranianSpeed;
public:
	Pomeranian(string name, string kind, string purpose, string country, int pomeranianAge, int pomeranianSpeed) : pomeranianAge(pomeranianAge), pomeranianSpeed(pomeranianSpeed), Dog(name, kind, purpose, country) {}
	void showInfo1() { cout << "Name : " << name << " / Age : " << pomeranianAge << " / Kind : " << kind << endl; }
	void showInfo2() { cout << "Purpose : " << purpose << " / Speed : " << pomeranianSpeed << "km/s / Country : " << country << endl; }
};

class Sparrow : public Bird {	// ����
	int spaAge;
	string spaFood;
public:
	Sparrow(string name, string kind, int spaAge, string size, string activeTime, string spaFood) : spaAge(spaAge), spaFood(spaFood), Bird(name, kind, size, activeTime) {}
	void showInfo1() { cout << "Name : " << name << " / Age : " << spaAge << " / Kind : " << kind << endl; }
	void showInfo2() { cout << "Size : " << size << " / ActiveTime : " << activeTime << " / Food : " << spaFood << endl; }
};

class Owl : public Bird {	// �û���
	int owlAge;
	string owlFood;
public:
	Owl(string name, string kind, int owlAge, string size, string activeTime, string owlFood) : owlAge(owlAge), owlFood(owlFood), Bird(name, kind, size, activeTime) {}
	void showInfo1() { cout << "Name : " << name << " / Age : " << owlAge << " / Kind : " << kind << endl; }
	void showInfo2() { cout << "Size : " << size << " / ActiveTime : " << activeTime << " / Food : " << owlFood << endl; }
};

class Eagle : public Bird {	// ������
	int eagleAge;
	string eagleFood;
public:
	Eagle(string name, string kind, int eagleAge, string size, string activeTime, string eagleFood) : eagleAge(eagleAge), eagleFood(eagleFood), Bird(name, kind, size, activeTime) {}
	void showInfo1() { cout << "Name : " << name << " / Age : " << eagleAge << " / Kind : " << kind << endl; }
	void showInfo2() { cout << "Size : " << size << " / ActiveTime : " << activeTime << " / Food : " << eagleFood << endl; }
};

int main() {
	Sparrow* sparrow = new Sparrow("����", "Bird", 3, "Small", "DayTime", "Insect");
	sparrow->showInfo1();
	sparrow->showInfo2();
	printf("\n");

	Owl* owl = new Owl("�û���", "Bird", 5, "Medium Large", "Night", "Insect");
	owl->showInfo1();
	owl->showInfo2();
	printf("\n");

	Eagle* eagle = new Eagle("������", "Bird", 4, "Large", "DayTime", "Meat");
	eagle->showInfo1();
	eagle->showInfo2();
	printf("\n");

	Jindo* jindo = new Jindo("������", "Dog", "Safety", "Korea", 3, 20);
	jindo->showInfo1();
	jindo->showInfo2();
	printf("\n");

	Doberman* doberman = new Doberman("��������", "Dog", "Hunt", "Germnary", 5, 30);
	doberman->showInfo1();
	doberman->showInfo2();
	printf("\n");

	Pomeranian* pomeranian = new Pomeranian("���޶�Ͼ�", "Dog", "Cute", "Germany", 1, 5);
	pomeranian->showInfo1();
	pomeranian->showInfo2();
	printf("\n");

	return 0;
}
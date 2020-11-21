#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
	string name;	// 이름
	string kind;	// 종류
public:
	Animal(string name, string kind) : name(name), kind(kind) {}
};

class Bird : public Animal {
protected:
	string size;	// 크기
	string activeTime;	// 활동 시간
public:
	Bird(string name, string kind, string size, string activeTime) : size(size), activeTime(activeTime), Animal(name, kind) {}
	virtual void showInfo1() { cout << "Name : " << name << " / Kind : " << kind << endl; }
	virtual void showInfo2() { cout << "Size : " << size << " / ActiveTime : " << activeTime << endl; }
};

class Dog : public Animal {
protected:
	string purpose;	// 목적
	string country;	// 출생 국가
public:
	Dog(string name, string kind, string purpose, string country) : purpose(purpose), country(country), Animal(name, kind) {}
	virtual void showInfo1() { cout << "Name : " << name << " / Kind : " << kind << endl; }
	virtual void showInfo2() { cout << "Purpose : " << purpose << " / Country : " << country << endl; }
};

class Jindo : public Dog {	// 진돗개
	int jindoAge;
	int jindoSpeed;
public:
	Jindo(string name, string kind, string purpose, string country, int jindoAge, int jindoSpeed) : jindoAge(jindoAge), jindoSpeed(jindoSpeed), Dog(name, kind, purpose, country) {}
	void showInfo1() { cout << "Name : " << name << " / Age : " << jindoAge << " / Kind : " << kind << endl; }
	void showInfo2() { cout << "Purpose : " << purpose << " / Speed : " << jindoSpeed << "km/s / Country : " << country << endl; }
};

class Doberman : public Dog {	// 도베르만
	int dobermanAge;
	int dobermanSpeed;
public:
	Doberman(string name, string kind, string purpose, string country, int dobermanAge, int dobermanSpeed) : dobermanAge(dobermanAge), dobermanSpeed(dobermanSpeed), Dog(name, kind, purpose, country) {}
	void showInfo1() { cout << "Name : " << name << " / Age : " << dobermanAge << " / Kind : " << kind << endl; }
	void showInfo2() { cout << "Purpose : " << purpose << " / Speed : " << dobermanSpeed << "km/s / Country : " << country << endl; }
};

class Pomeranian : public Dog {	// 포메라니안
	int pomeranianAge;
	int pomeranianSpeed;
public:
	Pomeranian(string name, string kind, string purpose, string country, int pomeranianAge, int pomeranianSpeed) : pomeranianAge(pomeranianAge), pomeranianSpeed(pomeranianSpeed), Dog(name, kind, purpose, country) {}
	void showInfo1() { cout << "Name : " << name << " / Age : " << pomeranianAge << " / Kind : " << kind << endl; }
	void showInfo2() { cout << "Purpose : " << purpose << " / Speed : " << pomeranianSpeed << "km/s / Country : " << country << endl; }
};

class Sparrow : public Bird {	// 참새
	int spaAge;
	string spaFood;
public:
	Sparrow(string name, string kind, int spaAge, string size, string activeTime, string spaFood) : spaAge(spaAge), spaFood(spaFood), Bird(name, kind, size, activeTime) {}
	void showInfo1() { cout << "Name : " << name << " / Age : " << spaAge << " / Kind : " << kind << endl; }
	void showInfo2() { cout << "Size : " << size << " / ActiveTime : " << activeTime << " / Food : " << spaFood << endl; }
};

class Owl : public Bird {	// 올빼미
	int owlAge;
	string owlFood;
public:
	Owl(string name, string kind, int owlAge, string size, string activeTime, string owlFood) : owlAge(owlAge), owlFood(owlFood), Bird(name, kind, size, activeTime) {}
	void showInfo1() { cout << "Name : " << name << " / Age : " << owlAge << " / Kind : " << kind << endl; }
	void showInfo2() { cout << "Size : " << size << " / ActiveTime : " << activeTime << " / Food : " << owlFood << endl; }
};

class Eagle : public Bird {	// 독수리
	int eagleAge;
	string eagleFood;
public:
	Eagle(string name, string kind, int eagleAge, string size, string activeTime, string eagleFood) : eagleAge(eagleAge), eagleFood(eagleFood), Bird(name, kind, size, activeTime) {}
	void showInfo1() { cout << "Name : " << name << " / Age : " << eagleAge << " / Kind : " << kind << endl; }
	void showInfo2() { cout << "Size : " << size << " / ActiveTime : " << activeTime << " / Food : " << eagleFood << endl; }
};

int main() {
	Sparrow* sparrow = new Sparrow("참새", "Bird", 3, "Small", "DayTime", "Insect");
	sparrow->showInfo1();
	sparrow->showInfo2();
	printf("\n");

	Owl* owl = new Owl("올빼미", "Bird", 5, "Medium Large", "Night", "Insect");
	owl->showInfo1();
	owl->showInfo2();
	printf("\n");

	Eagle* eagle = new Eagle("독수리", "Bird", 4, "Large", "DayTime", "Meat");
	eagle->showInfo1();
	eagle->showInfo2();
	printf("\n");

	Jindo* jindo = new Jindo("진돗개", "Dog", "Safety", "Korea", 3, 20);
	jindo->showInfo1();
	jindo->showInfo2();
	printf("\n");

	Doberman* doberman = new Doberman("도베르만", "Dog", "Hunt", "Germnary", 5, 30);
	doberman->showInfo1();
	doberman->showInfo2();
	printf("\n");

	Pomeranian* pomeranian = new Pomeranian("포메라니안", "Dog", "Cute", "Germany", 1, 5);
	pomeranian->showInfo1();
	pomeranian->showInfo2();
	printf("\n");

	return 0;
}
#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
	string name;	//이름
	string kind;	//종류
public:
	Animal(string name, string kind) : name(name), kind(kind) {}
};

class Dog : public Animal {
protected:
	string purpose;
	string country;
public:
	Dog(string name, string kind, string purpose, string country) : purpose(purpose), country(country), Animal(name, kind) {}
	virtual void showInfo1() { cout << "Name : " << name << " / Kind : " << kind << endl; }
	virtual void showInfo2() { cout << "Purpose : " << purpose << " / Country" << country << endl; }
};

class Jindo : public Dog {
	int jindoAge, jindoSpeed;
public:
	Jindo(string name, string kind, int jindoAge, string purpose, int jindoSpeed, string country) : jindoAge(jindoAge), jindoSpeed(jindoSpeed), Dog(name, kind, purpose, country) {}
	void showInfo1() { cout << "Name : " << name << " / Kind : " << kind << " / Age : " << jindoAge << endl; }
	void showInfo2() { cout << "Purpose : " << purpose << " / Speed : " << jindoSpeed << " / Country : " << country << endl; }
};

class Doberman : public Dog {
	int dobermanAge, dobermanSpeed;
public:
	Doberman(string name, string kind, int dobermanAge, string purpose, int dobermanSpeed, string country) : dobermanAge(dobermanAge), dobermanSpeed(dobermanSpeed), Dog(name, kind, purpose, country) {}
	void showInfo1() { cout << "Name : " << name << " / Kind : " << kind << " / Age : " << dobermanAge << endl; }
	void showInfo2() { cout << "Purpose : " << purpose << " / Speed : " << dobermanSpeed << " / Country : " << country << endl; }
};

class Pomeranian : public Dog {
	int pomeranianAge, pomeranianSpeed;
public:
	Pomeranian(string name, string kind, int pomeranianAge, string purpose, int pomeranianSpeed, string country) : pomeranianAge(pomeranianAge), pomeranianSpeed(pomeranianSpeed), Dog(name, kind, purpose, country) {}
	void showInfo1() { cout << "Name : " << name << " / Kind : " << kind << " / Age : " << pomeranianAge << endl; }
	void showInfo2() { cout << "Purpose : " << purpose << " / Speed : " << pomeranianSpeed << " / Country : " << country << endl; }
};

int main() {
	Jindo* jindo = new Jindo("Jindo", "Dog", 5, "Hunt", 10, "Korea");
	jindo->showInfo1();
	jindo->showInfo2();
	printf("\n");

	Doberman* doberman = new Doberman("Doberman", "Dog", 5, "Hunt", 20, "Germany");
	doberman->showInfo1();
	doberman->showInfo2();
	printf("\n");

	Pomeranian* pomeranian = new Pomeranian("Pomeranian", "Dog", 5, "Cute", 3, "Germany");
	pomeranian->showInfo1();
	pomeranian->showInfo2();
	printf("\n");

	return 0;
}



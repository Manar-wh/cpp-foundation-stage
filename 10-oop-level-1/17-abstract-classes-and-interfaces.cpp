#include <iostream>
using namespace std;

class clsPhone {
public:
	virtual void Dial(string PhoneNumber) = 0;
	virtual void TurnOnFlashLight() = 0;
	virtual void ShowRegulatoryInfo() = 0;
};

class clsIphone12 : public clsPhone {

public:
	void Dial(string PhoneNumber) {
		cout << "iPhone is dialing " << PhoneNumber << "...\n";
	}

	void TurnOnFlashLight() {

		cout << "Flashlight is now ON! \n";

	}

	void ShowRegulatoryInfo() {

		cout << "Designed in 2020. Complies with international telecom standards.\n";
	}


};

class clsSamsungS23: public clsPhone{
public:
	void Dial(string PhoneNumber) {

		cout << "Samsung is dialing " << PhoneNumber << "...\n";

	}

	void TurnOnFlashLight() {

		cout << "Flashlight is now ON! \n";
	}

	void ShowRegulatoryInfo() {

		cout << "Designed in 2023. Complies with international telecom standards.\n";
	}

};

int main() {

	clsIphone12 Iphone12;
	clsSamsungS23 SamsungS23;

	Iphone12.Dial("05699929222");
	Iphone12.ShowRegulatoryInfo();
	Iphone12.TurnOnFlashLight();

	cout << "\n-----------------\n";

	SamsungS23.Dial("0549998888");
	SamsungS23.ShowRegulatoryInfo();
	SamsungS23.TurnOnFlashLight();

	return 0;
}

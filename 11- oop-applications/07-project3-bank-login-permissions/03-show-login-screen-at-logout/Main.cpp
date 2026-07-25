#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "clsMainScreen.h"
#include "clsScreen.h"
#include "clsLoginScreen.h"
int main()
{
	while (true)
	{
		clsLoginScreen::ShowLoginScreen();
	}
}

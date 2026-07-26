#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "clsLoginScreen.h"
using namespace std;

int main()
{
	while (true)
	{
		if (!clsLoginScreen::ShowLoginScreen())
		{
			break;
		}
	}
}

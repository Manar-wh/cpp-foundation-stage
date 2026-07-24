#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUsersListScreen.h"
using namespace std;

class clsManageUsersScreen : protected clsScreen {
private:
    enum enManageUsersOptions {
        eListUsers = 1,
        eAddNewUser = 2,
        eDeleteUser = 3,
        eUpdateUser = 4,
        eFindUser = 5,
        eMainMenu = 6
    };

    static short _ReadManageUsersOption() {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]: ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6: ");
        return Choice;
    }

    static void _GoBackToManageUsersMenu() {
        cout << "\n\nPress any key to go back to Manage Users Menu...";
        system("pause>nul");
        ShowManageUsersMenu();
    }

    static void _ShowListUsersScreen() {
        clsUsersListScreen::ShowUsersList();
    }

    static void _ShowAddNewUserScreen() {
        cout << "\nAdd New User Screen will be available soon...\n";
    }

    static void _ShowDeleteUserScreen() {
        cout << "\nDelete User Screen will be available soon...\n";
    }

    static void _ShowUpdateUserScreen() {
        cout << "\nUpdate User Screen will be available soon...\n";
    }

    static void _ShowFindUserScreen() {
        cout << "\nFind User Screen will be available soon...\n";
    }

    static void _PerformManageUsersOption(enManageUsersOptions ManageUsersOption) {
        switch (ManageUsersOption)
        {
        case enManageUsersOptions::eListUsers:
            system("cls");
            _ShowListUsersScreen();
            _GoBackToManageUsersMenu();
            break;

        case enManageUsersOptions::eAddNewUser:
            system("cls");
            _ShowAddNewUserScreen();
            _GoBackToManageUsersMenu();
            break;

        case enManageUsersOptions::eDeleteUser:
            system("cls");
            _ShowDeleteUserScreen();
            _GoBackToManageUsersMenu();
            break;

        case enManageUsersOptions::eUpdateUser:
            system("cls");
            _ShowUpdateUserScreen();
            _GoBackToManageUsersMenu();
            break;

        case enManageUsersOptions::eFindUser:
            system("cls");
            _ShowFindUserScreen();
            _GoBackToManageUsersMenu();
            break;

        case enManageUsersOptions::eMainMenu:
            break;
        }
    }

public:
    static void ShowManageUsersMenu() {
        system("cls");
        _DrawScreenHeader("\t Manage Users Screen");

        cout << setw(37) << left << "" << "==============================================\n";
        cout << setw(37) << left << "" << "\t\t  Manage Users Menu\n";
        cout << setw(37) << left << "" << "==============================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "==============================================\n";

        _PerformManageUsersOption((enManageUsersOptions)_ReadManageUsersOption());
    }
};

#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"

using namespace std;

class clsAddNewUserScreen : protected clsScreen {
private:
    static int _ReadPermissionsToSet() {
        char Answer = 'n';
        int Permissions = 0;

        cout << "\nDo You Want To Give Full Access? [Y/N]: ";
        cin >> Answer;

        if (toupper(Answer) == 'Y') {
            return -1; // -1 تعني صلاحة كاملة (Enum / Bitwise All Access)
        }

        cout << "\nDo you want to give access to:\n";

        cout << "\nShow Client List? [Y/N]: ";
        cin >> Answer;
        if (toupper(Answer) == 'Y') {
            Permissions += clsUser::pShowClientList;
        }

        cout << "\nAdd New Client? [Y/N]: ";
        cin >> Answer;
        if (toupper(Answer) == 'Y') {
            Permissions += clsUser::pAddNewClient;
        }

        cout << "\nDelete Client? [Y/N]: ";
        cin >> Answer;
        if (toupper(Answer) == 'Y') {
            Permissions += clsUser::pDeleteClient;
        }

        cout << "\nUpdate Client? [Y/N]: ";
        cin >> Answer;
        if (toupper(Answer) == 'Y') {
            Permissions += clsUser::pUpdateClient;
        }

        cout << "\nFind Client? [Y/N]: ";
        cin >> Answer;
        if (toupper(Answer) == 'Y') {
            Permissions += clsUser::pFindClient;
        }

        cout << "\nTransactions? [Y/N]: ";
        cin >> Answer;
        if (toupper(Answer) == 'Y') {
            Permissions += clsUser::pTransactions;
        }

        cout << "\nManage Users? [Y/N]: ";
        cin >> Answer;
        if (toupper(Answer) == 'Y') {
            Permissions += clsUser::pManageUsers;
        }

        return Permissions;
    }

    static void _ReadUserInfo(clsUser& User) {
        cout << "Enter FirstName: ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "Enter LastName: ";
        User.LastName = clsInputValidate::ReadString();

        cout << "Enter Email: ";
        User.Email = clsInputValidate::ReadString();

        cout << "Enter Phone: ";
        User.Phone = clsInputValidate::ReadString();

        cout << "Enter Password: ";
        User.Password = clsInputValidate::ReadString();

        cout << "Enter Permissions: ";
        User.Permissions = _ReadPermissionsToSet();
    }

    static void _PrintUser(clsUser User) {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";
    }

public:
    static void ShowAddNewUserScreen() {
        _DrawScreenHeader("\t  Add New User Screen");

        string Username = "";
        cout << "\nPlease Enter Username: ";
        Username = clsInputValidate::ReadString();

        while (clsUser::IsUserExist(Username)) {
            cout << "\nUsername is already used, Please enter another Username: ";
            Username = clsInputValidate::ReadString();
        }

        clsUser NewUser = clsUser::GetAddNewUserObject(Username);

        _ReadUserInfo(NewUser);

        clsUser::enSaveResults SaveResult;
        SaveResult = NewUser.Save();

        switch (SaveResult)
        {
        case clsUser::enSaveResults::svSucceeded:
            cout << "\nUser Added Successfully :-)\n";
            _PrintUser(NewUser);
            break;

        case clsUser::enSaveResults::svFaildEmptyObject:
            cout << "\nError: User was not saved because it is Empty!";
            break;

        case clsUser::enSaveResults::svFaildUserExists:
            cout << "\nError: User was not saved because Username already exists!\n";
            break;
        }
    }
};

#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

using namespace std;

class clsUpdateUserScreen : protected clsScreen {
private:
    static void _PrintUser(clsUser User)
    {
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

    static int _ReadPermissionsToSet() {
        char Answer = 'n';
        int Permissions = 0;

        cout << "\nDo You Want To Give Full Access? [Y/N]: ";
        cin >> Answer;

        if (toupper(Answer) == 'Y') {
            return -1;
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

        cout << "\nShow Login Register? [Y/N]: ";
        cin >> Answer;
        if (toupper(Answer) == 'Y') {
            Permissions += clsUser::pShowLoginRegisterScreen;
        }

        return Permissions;
    }

    static void _ReadUserInfo(clsUser& User) {
        cout << "\nEnter FirstName: ";
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

public:

    static void ShowUpdateUserScreen() {
        _DrawScreenHeader("\tUpdate User Screen");

        string UserName = "";
        cout << "\nPlease Enter Username: ";
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUsername is not found, Enter Another Username: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User1 = clsUser::Find(UserName);
        _PrintUser(User1);

        cout << "\n\nUpdate User Info:";
        cout << "\n____________________\n";
        _ReadUserInfo(User1);

        clsUser::enSaveResults SaveResult;
        SaveResult = User1.Save();

        switch (SaveResult)
        {
        case clsUser::svSucceeded:
            cout << "\nUser Updated Successfully :-)\n";
            _PrintUser(User1);
            break;

        case clsUser::svFaildEmptyObject:
            cout << "\nError: User was not saved because it's Empty.";
            break;
        }
    }
};

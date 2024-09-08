#include "User.h"

using namespace std;

int main() {
setlocale (LC_ALL,"");

User user ("Alexandr", "alex", "alex124");

cout << "Начальные данные: " << endl;
cout << "Name:" << user.getName() << endl;
cout << "Login:" << user.getLogin() << endl;
cout << "Password:" << user.getPassword() << endl;

string newName = "Ivan";
string newLogin = "vanya";
string newPassword  = "ivan123";

user.setName(newName);
user.setLogin(newLogin);
user.setPassword(newPassword);

cout << "Текущие данные: " << endl;
cout << "Name:" << user.getName() << endl;  
cout << "Login:" << user.getLogin() << endl;
cout << "Password:" << user.getPassword() << endl;

}

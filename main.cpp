#include "User.h"
#include <vector>
#include <cstdlib>
using namespace std;

constexpr auto user_cnt = "/home/amalya/MyProject_Linux/user_count.txt";

int main() {
setlocale (LC_ALL,"");

vector <User> user;
User usr;
char c = 'y';
string line;
int user_count = 0;

fstream file (user_cnt, ios::in);

if (file.is_open()) {
	getline(file, line);
	user_count = stoi(line);	
}

file.close();

if (user_count !=0 ) {
	for (int i = 0; i < user_count; i++) {
	        usr.readUser();
		user.push_back(usr);
	}

	cout << "\nДанные из файла:" << endl;

	for (int i = 0; i < user.size(); i++) {
	        cout << "Name:" << user[i].getName() << endl;
	        cout << "Login:" << user[i].getLogin() << endl;
	        cout << "Password:" << user[i].getPassword() << endl;
	}

	user.clear();
	user_count = 0;
}

while (c != 'n') {
	
	string newName; // имя пользователя
	string newLogin; // логин
	string newPassword; // пароль
	
	cout << "\nВведите имя пользователя:" << endl;
	cin >> newName;

	cout << "Введите логин пользователя:" << endl;
	cin >> newLogin;

	cout << "Введите пароль пользователя:" << endl;
	cin >> newPassword;

	user.push_back({newName, newLogin, newPassword});
	user_count++;
	cout << "\nХотите зарегистрировать ещё одного пользователя? (y/n)" << endl;
	cin >> c;
}

fstream file_w (user_cnt, ios::out | ios::trunc); // записываем кол-во пользователей в файл user_cnt
file_w << user_count;
file_w.close();

for (int i = 0; i < user.size(); i++) {
	cout << "Name:" << user[i].getName() << endl;
	cout << "Login:" << user[i].getLogin() << endl;
	cout << "Password:" << user[i].getPassword() << endl;
}

for (int i = 0; i < user.size(); i++) {
	        user[i].writeUser();
	}
}

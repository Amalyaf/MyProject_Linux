#pragma once
#include <fstream> // Для работы с файлом, как с потоком
#include <iostream>
// ifstream - для чтения данных из файла
// ofstream - для записи в файлы
// fstream - запись и считывание данных

constexpr auto userData = "/home/amalya/MyProject_Linux/userData.txt";

class User
{
public:
	User(std::string name, std::string login, std::string password);
	~User();
	void readUser();
	void writeUser() const;
	const std::string getLogin() const;
	const std::string getName() const;
	const std::string getPassword() const;
	void setName(std::string name);
	void setLogin(std::string login);
	void setPassword(std::string password);
	friend std::fstream& operator >>(std::fstream& is, User& obj);
	friend std::ostream& operator <<(std::ostream& os, const User& obj);
private:
	std::string _name;
	std::string _login;
	std::string _password;
};

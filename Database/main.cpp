#include <iostream>
#include <Windows.h>
#include <map>
#include <string>
#include <vector>
#include <time.h>
using namespace std;
class Receipt
{
	string receipt;//����� ��������� ������ � ����������
	string nameFine;//�������� ������
	double Sum;
public:
	Receipt()
	{
		receipt = "var";
		nameFine = "name";
		Sum = 0;
		cout << "RCtor: " << this << endl;
	}
	Receipt(string var, string name, double sum)
	{
		receipt = var;
		nameFine = name;
		Sum = sum;
		cout << "RCtor: " << this << endl;
	}
	void RandSet(string number_car, vector<string>Fine, vector<double>sum)//�������� ����� ������ ������� ����� � 2 ������ � �������� �������� � �������
	{
		time_t rtime;//������� ����� � ������������
		time(&rtime);//�������� ������� �����
		tm mytime;//��������� ��� �������� ������ ��� ������� ����
		localtime_s(&mytime, &rtime);//���������� ���������� ���� �� ���� ���������
		receipt = number_car + to_string(mytime.tm_mday) + to_string(mytime.tm_mon) + to_string(mytime.tm_year + 1900) + to_string(100 + rand() % 900);
		int var = rand() % Fine.size();
		nameFine = Fine[var];
		Sum = sum[var];
	}
	void PrintReceipt()
	{
		cout << "N: " << receipt << "\t" << "name: " << nameFine << "\t" << "sum: " << Sum << endl;
	}
};
class Car
{
	string Number;
	vector<Receipt>allReceipt;
public:
	void RandNumber()
	{
		string temp;
		temp.push_back('A' + rand() % ('Z' - 'A'));
		temp += to_string(100 + rand() % 900);
		temp.push_back('A' + rand() % ('Z' - 'A'));
		temp.push_back('A' + rand() % ('Z' - 'A'));
		Number = temp;
	}
	void AddReceipt(Receipt var)
	{
		allReceipt.push_back(var);

	}
	void PrintReceipt()
	{
		cout << "Car: " << Number << endl;
		for (Receipt var : allReceipt)
		{
			var.PrintReceipt();
		}
	}
	Car()
	{
		Number = "non";
	}
	Car(string number)
	{
		Number = number;
		cout << "CCtor: " << this << endl;
	}
	string getNumber()const
	{
		return Number;
	}
	~Car()
	{
		cout << "CDisrt: " << this << endl;
	}
};
class Database
{
	int Size;
	map<string, vector<Receipt>>database;
public:
	Database(int size)
	{
		Size = size;
	}
	void setDatabase(Car car, vector<Receipt>allReceipt)
	{
		//pear 
		database.insert(pair<string, vector<Receipt>>(car.getNumber(), allReceipt));
	}
};
void main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	vector<string>fine = { "���������� ��������","�����","����������� ��������","������ ������������","��� �����������","�������� �� ���������� �����������" };
	vector<double>sum = { 2000,3000,2500,500,1000,5000 };
	for (size_t i = 0; i < 10; i++)
	{

	}
	Car car;
	car.RandNumber();
	Receipt receipt;
	receipt.RandSet(car.getNumber(), fine, sum);
	//receipt.PrintReceipt();
	car.AddReceipt(receipt);
	car.PrintReceipt();

}
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void search (string str, string s)
{
	int status = str.find(s);
	if (status != -1)
	{
		cout << "Search results: " << "Yes, find!" << endl;
		cout << "The position of the first character of the entered string: " << status <<endl;
	}
	else
		cout << "Search results: " << "No!" << endl;
}

int main ()
{
	string str;
	char symbol;
	ifstream text_file("home/file.txt");
	if (text_file.is_open())
	{
		text_file.unsetf(ios::skipws);
		while (text_file >> symbol)
		{
			str += symbol;
		}
	}
	else
		return 0;
	//cin >> str;
	string s;

	cout << "The path to the file: home/file.txt" << endl;
	cout << "Text from file: " << str <<endl;
	cout << "Enter the search string: ";
	cin >> s;
	cout << endl;

	search(str, s);

	text_file.close();
	cin.get();
	//system("pause");
	return 0;
}

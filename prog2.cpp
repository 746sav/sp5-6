#include <iostream>
#include <thread>
#include <fstream>
#include <cstring>
#include <chrono>
#include <mutex>


using namespace std;


mutex mtx;
void search (string &str, char str2[], int format)
{
	
	cout << "ID " << format <<" thread: " << this_thread::get_id() << endl;
	cout << "My string: " << str << endl;
	this_thread::sleep_for(chrono::seconds(1));
	mtx.lock();
	//lock_guard<mutex> guard (mtx);
	char *s = new char[str.size() + 1];
	strcpy(s, str.c_str());
	char *p = strtok(s, " ");
	while (p != NULL)
	{
		int flag = strcmp (p, str2);
		if (flag == 0 && format == 1)
		{
			str = "I find! I am 1 thread";
		}
		if (flag == 0 && format == 2)
	
			str = "I find! I am 2 thread";
		p = strtok(NULL, " ");
		mtx.unlock();
	}
}

void read (string mass[])
{
	ifstream text_file("file.txt");
	if(text_file.is_open())
	{
		for (int i = 0; i < 2; i++)
			getline(text_file, mass[i]);
			
	}

	text_file.close();
}



int main()
{
	string str, str2, str3;
	string mass[2];
	read(mass);
	
	cout << "--------------Text---------------" << endl;
	for (int i = 0; i < 2; i++)
		cout << mass[i] << endl;	
	cout << "Enter the search word: ";
	cin >> str2;
	char *s = new char[str2.size() + 1];
	cout << "-----------THREADS WORK-----------" << endl;
	strcpy(s, str2.c_str());
	
//	thread th(search, std::ref(mass[1]), s, 2);
	cout << "ID main thread: " << this_thread::get_id() << endl;
	cout << "How many threads the system can execute at one time: " << thread::hardware_concurrency() << endl;
	thread th (search, std::ref(mass[0]), s, 1);
	thread th2 (search, std::ref(mass[1]), s, 2);

	th.join();
	th2.join();
	cout << "-------------RESULT---------------" << endl;
	for (int i = 0; i < 2; i++)
		cout << mass[i] << endl;
	return 0;
}


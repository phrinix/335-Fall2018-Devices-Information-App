
#include <iostream>
#include <fstream>

using namespace std;

class device
{
protected:
	char serialNumber[20];
	char device_description[200];
public:
	device ()
	{
		serialNumber[20] = 0;
		device_description[20] = 0;
	}
};

class test
{
protected:
	char test_description[200];
	int month, month1;
	int date, date1;
	int year, year1;
	int monthDifference;
public:
	test ()
	{
		monthDifference =  0;
		month = 0;
		month1 = 0;
		date = 0;
		date1 = 0;
		year = 0;
		year1 = 0;
		test_description[200] = 0;
	}
	void next_date(void)
	{
		date1 = date;
		month1 = month;
		year1 = year;
		month1 = month + monthDifference;
		while (month1 > 12)
		{
			year1++;
			month1 -= 12;
		}
		if ((month1 == 2) & (year1 % 4 != 0) & (date1 > 28))
		{
			date1 = 28;
		}
		if (month <= 7)
			if (month1 % 2 == 0)
			{
					if (date1 > 30)
						date1 = 30;
			}
		else if (month > 7)
			if (month1 % 2 == 1)
			{
					if (date1 > 30)
						date1 = 30;
			}
	}
};

class data: public device, public test
{
public:
	data()
	{
	}
	static void file_write(int n)
	{
		data *dev = new data[n];
		if (dev == 0)
		{
			cout << "Memory allocation error";
			exit(1);
		}
		for (int i = 0; i < n; i++)
		{
			cin >> dev[i];
			dev[i].next_date();
		}
		ofstream fdata("devices.dat", ios::binary | ios::app);
		fdata.seekp(0, ios::end);
		fdata.write((char*) dev, n*sizeof(data));
		fdata.close();

		delete []dev;
	}

	static void serial_file_read(char serial[20])
	{
		int n;
		ifstream fdata2("devices.dat", ios::binary);
		if (fdata2==0)
		{cout << "File Does not exist";
		exit(1);
		}
		fdata2.seekg(0,ios::end);
		n = fdata2.tellg() / sizeof(data);
		data *dev1 = new data[n];
		if (dev1 == 0)
		{
			cout << "Memory allocation error";
			exit(1);
		}
		fdata2.seekg(0,ios::beg);
		fdata2.read((char*) dev1 , n*sizeof(data));

		for (int i = 0 ; i < n ; i++)
		{
		if (strcmp(serial,dev1[i].serialNumber) ==0)
				cout << dev1[i];
		}
		fdata2.close();
		delete []dev1;
	}

	static void date_file_read(int d, int m, int y)
	{
		int n;
		ifstream fdata2("devices.dat", ios::binary);
		if (fdata2==0)
		{cout << "File Does not exist";
		exit(1);
		}
		fdata2.seekg(0,ios::end);
		n = fdata2.tellg() / sizeof(data);
		data *dev1 = new data[n];
		if (dev1 == 0)
		{
			cout << "Memory allocation error";
			exit(1);
		}
		fdata2.seekg(0,ios::beg);
		fdata2.read((char*) dev1 , n*sizeof(data));

		for (int i = 0 ; i < n ; i++)
		{
		if ((d == dev1[i].date1) & (m == dev1[i].month1) & (y == dev1[i].year1))
				cout << dev1[i];
		}
		fdata2.close();
		delete []dev1;
	}

	friend istream &operator >> (istream &in , data &obj)
	{
		cout << " Enter device serial Number: ";
		in >> obj.serialNumber;
		cout << " Enter device description: ";
		in.ignore();
		cin.getline(obj.device_description,200);
		cout << " Enter date of most recent Test(DD MM YYYY): " ;
		in >> obj.date >> obj.month >> obj.year ;
		cout << " Enter number of months between test: ";
		in >> obj.monthDifference;
		cout << " Enter test description: ";
		in.ignore();
		cin.getline(obj.test_description,200);
		cout << endl;
		return in;
	}
	friend ostream &operator << (ostream &out , data &obj)
	{
		out << "    Serial No: " << obj.serialNumber << endl << "    Device description: " << obj.device_description << endl;
		out	<< "    Recent Test date(DD MM YYYY): " << obj.date << "/" << obj.month << "/" << obj.year << endl;
		out << "    Test description: " << obj.test_description << endl << "    Next Test date(DD MM YYYY):";
		out << obj.date1 << "/" << obj.month1 << "/" << obj.year1 << endl << endl;
		return out;
	}
};

void main (void)
{ 
	int n;
	char gate;
	int date, month, year;	
	char serialn[20];

	do
	{
		cout << "1. Add new devices" << endl;
		cout << "2. Search for device using serial number" << endl;
		cout << "3. Search for device using next test date" << endl;
		cout << "4. Quit" << endl;
		cout << "Choose the option: ";
		cin >> gate;
		cout << endl;
		if (gate == '1')
			{
				cout << "Enter the number of devices you want to add: ";
				cin >> n;
				data::file_write(n);

			}
		else if (gate == '2')
			{
				cout << "Enter serial number: ";		
				cin >> serialn;
				cout << endl;
				data::serial_file_read(serialn);
			}
		else if (gate == '3')
			{
				cout << "Enter the date(DD MM YYYY): ";
				cin >> date >> month >> year;
				cout << endl;
				data::date_file_read(date,month,year);
			}
		else if (gate == '4')
			cout << "Have a good day!" << endl;
		else 
			cout << "Wrong option!!! Choose Again" << endl;
	}while(gate != '4');
	system ("pause");
}

/* ________________OUTPUT_________________

1. Add new devices
2. Search for device using serial number
3. Search for device using next test date
4. Quit
Choose the option: 1

Enter the number of devices you want to add: 1
 Enter device serial Number: 10
 Enter device description: Testing program
 Enter date of most recent Test(DD MM YYYY): 01 10 2018
 Enter number of months between test: 2
 Enter test description: pass

1. Add new devices
2. Search for device using serial number
3. Search for device using next test date
4. Quit
Choose the option: 2

Enter serial number: 10

    Serial No: 10
    Device description: Testing program
    Recent Test date(DD MM YYYY): 1/10/2018
    Test description: pass
    Next Test date(DD MM YYYY):1/12/2018

1. Add new devices
2. Search for device using serial number
3. Search for device using next test date
4. Quit
Choose the option: 3

Enter the date(DD MM YYYY): 01 12 2018

    Serial No: 10
    Device description: Testing program
    Recent Test date(DD MM YYYY): 1/10/2018
    Test description: pass
    Next Test date(DD MM YYYY):1/12/2018

1. Add new devices
2. Search for device using serial number
3. Search for device using next test date
4. Quit
Choose the option: 4

Have a good day!
Press any key to continue . . .

*/
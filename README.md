# 335-Fall2018-Devices-Information-App
# OOP C++
Design an OOP program that can be used to create, update and read a file, which contains data about devices and tests/measurements to be performed on these devices.
Your program should create and use a Device class to store and process the device data, such as a device description and its serial number. The program should also use a Test class to store and process the test data, such as a test description, a number of months between two tests, the date of the most recent test, and the date of the next test. The program should get all necessary data from the user except the date of the next test, which will be computed by the program. The Test class should contain a function that will compute the date of the next test using the date of the last test and the number of months between two tests. Your program should also create and use a third class that will inherit the Device and Test classes. This class should contain all necessary functions to write and read the device and test data into/from a file.

The program should enable the user to:

- Create a file and store the device and its test records/data into the file

- Search for a specific device in the file using its serial number and display all its
tests’ records

- Search for a specific date and display all devices that have to be tested on this date

Program requirements: 
It is required to use the following C++ language constructs/tools:
1. File I/O
2. Inheritance
3. Operator functions (at least two)
4. Constructor functions
5. Error checking and handling

# OUTPUT

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

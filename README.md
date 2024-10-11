# Assignment 1 for ICT283 Data Structures & Abstractions

### Summary
This program is designed to processe meteorological data from a specified CSV file, analyzing date, time, wind speed, temperature, and solar radiation readings. This program does the following:
- Loads meteorological data from CSV file
- Calculates and displays average wind speeds and the standard deviation of wind speeds
- Calculates and displays average temperature and the standard deviation of temperatures
- Calculates and displays the total solar radiation for each month in a given year
- Exports the wind speed, temperature, and solar radiation data to a CSV file

### Running the program
To run the program:

1. Compile the source code: 
```
g++ Date.cpp DateTest.cpp DataProcessor.cpp Time.cpp TimeTest.cpp VectorTest.cpp main.cpp
```
2. Execute the program:
```
./a.out  
```

### Running tests on the program
In this project, you will notice that there are test files for the following classes:
- **DateTest.cpp** (Test file for Date class)
- **TimeTest.cpp** (Test file for Time class)
- **VectorTest.cpp** (Test file for Vector class)
- **DataProcessorTest.cpp** (Test file for DataProcessor class)

To run the tests:
1. Compile the test files (I am using the Vector template class as an example):
```
g++ VectorTest.cpp -o VectorTest
```
2. Run the compiled VectorTest executable:
```
./VectorTest
```

*The output of runing the tests would show what we are testing for and the actual result. This allows us to verify our code is working as expected. The expected output are commented out within the actual code itself.*



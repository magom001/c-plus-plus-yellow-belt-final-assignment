# Coursera: C++ Development Yellow Belt: Final Assignment

[Link to assignment description](https://www.coursera.org/learn/c-plus-plus-yellow/programming/n1Nbg/kursovoi-proiekt)

## Usage example

#### Command Del example:

Input:
```
Add 2017-06-01 1st of June
Add 2017-07-08 8th of July
Add 2017-07-08 Someone's birthday
Del date == 2017-07-08
```
Output:
```
Removed 2 entries
```

#### Command Print example:

Input:
```
Add 2017-01-01 Holiday
Add 2017-03-08 Holiday
Add 2017-1-1 New Year
Add 2017-1-1 New Year
Print
```
Output:
```
2017-01-01 Holiday
2017-01-01 New Year
2017-03-08 Holiday
```

#### Command Find example:

Input:
```
Add 2017-01-01 Holiday
Add 2017-03-08 Holiday
Add 2017-01-01 New Year
Find event != "working day"
Add 2017-05-09 Holiday
```
Output:
```
2017-01-01 Holiday
2017-01-01 New Year
2017-03-08 Holiday
Found 3 entries
```

#### Command Last example:

Input:
```
Add 2017-01-01 New Year
Add 2017-03-08 Holiday
Add 2017-01-01 Holiday
Last 2016-12-31
Last 2017-01-01
Last 2017-06-01
Add 2017-05-09 Holiday
```

Output:
```
No entries
2017-01-01 Holiday
2017-03-08 Holiday
```
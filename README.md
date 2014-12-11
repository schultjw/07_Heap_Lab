07_HeapLab
==============

Implement a heap in C++

Requirements
------------

1. `add` and `remove` should be O(log n), except for `grow` which can be O(n)
2. Do not leak memory

Reading
=======
"Open Data Structures," Chapter 10, just the intro and section 1. http://opendatastructures.org/ods-cpp/10_Heaps.html

Questions
=========

#### 1. Which of the above requirements work, and which do not? For each requirement, write a brief response.

1. Ought to work based on reading.
2. Works. delete[] called when necessary.

#### 2. Exercises 10.1 and 10.2 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html
10.1 Add 7 as a child of 16. begin swapping upwards.
		7 and 16 swap. 7 > 6, so we're done.
	Add 3 as child of 7 (in its final spot). Begin swapping upwards.
		3 and 7 swap.
		3 and 6 swap.
		3 and 4 swap.
	Order is now:
	3 9 4 17 26 8 6 19 69 32 93 55 50 16 7
10.2
#### 3. Exercise 10.4 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html

#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

TODO
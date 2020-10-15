PP=g++
CPPFLAGS=-I.

all : task1 task2 task3 task4 task5 task6 task7
	task1
	task2
	task3
	task4
	task5
	task6
	task7

task1 :
	$(PP) -w -o task1 Lab1_task1.cpp $(CPPFLAGS)

task2 :
	$(PP) -w -o task2 Lab1_task2.cpp $(CPPFLAGS)

task3 :
	$(PP) -w -o task3 Lab1_task3.cpp $(CPPFLAGS)

task4 :
	$(PP) -w -o task4 Lab1_task4.cpp $(CPPFLAGS)

task5 :
	$(PP) -w -o task5 Lab1_task5.cpp $(CPPFLAGS)

task6 :
	$(PP) -w -o task6 Lab1_task6.cpp $(CPPFLAGS)

task7 :
	$(PP) -w -o task6 Lab1_task7.cpp $(CPPFLAGS)

clean :
	rm task1 task2 task3 task4 task5 task6 task7

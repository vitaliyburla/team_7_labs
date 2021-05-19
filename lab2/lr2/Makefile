malfdb: UserInterface.o libmalf.a
	g++ -o malfdb UserInterface.o -L. -lmalf

UserInterface.o: UserInterface.cpp
	g++ -c UserInterface.cpp

libmalf.a: Database.o MType.o
	ar cr libmalf.a Database.o MType.o

Database.o: Database.cpp
	g++ -c Database.cpp

MType.o: MType.cpp
	g++ -c MType.cpp

clean:
	rm -rf *.o malfdb


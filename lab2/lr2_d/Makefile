malfdb: UserInterface.o libmalf.so
	g++ -o malfdb UserInterface.o -L. -lmalf -Wl,-rpath,.

UserInterface.o: UserInterface.cpp
	g++ -c UserInterface.cpp

libmalf.so: Database.o MType.o
	g++ -shared -o libmalf.so Database.o MType.o

Database.o: Database.cpp
	g++ -c Database.cpp

MType.o: MType.cpp
	g++ -c MType.cpp

clean:
	rm -rf *.o malfdb


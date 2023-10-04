Main.out: ORM.o SQLGrammar.o NewDatabaseGrammar.o main.o
	g++ ORM.o SQLGrammar.o NewDatabaseGrammar.o main.o -o Main.out

ORM.o: ORM.cpp
	g++ -c -g ORM.cpp

SQLGrammar.o: SQLGrammar.cpp
	g++ -c -g SQLGrammar.cpp

NewDatabaseGrammar.o: NewDatabaseGrammar.cpp
	g++ -c -g NewDatabaseGrammar.cpp

main.o: main.cpp
	g++ -c -g main.cpp

run:
	./Main.out

clean:
	rm *.o Main.out
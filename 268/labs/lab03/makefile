prog1: BankAccount.o bankbranch.o main.o
	g++ BankAccount.o bankbranch.o main.o -o main
BankAccount.o: BankAccount.cpp BankAccount.h
	g++ -c BankAccount.cpp  
bankbranch.o: bankbranch.cpp bankbranch.h BankAccount.h
	g++ -c bankbranch.cpp 
main.o: main.cpp bankbranch.h
	g++ -c main.cpp
clean:
	rm *.o

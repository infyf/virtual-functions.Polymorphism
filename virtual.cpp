#include <iostream>

using namespace std;

class Worker  {
protected:
	char name[10];
	int age;

public:
	Worker(const char* name, int age) :age(age) {
		strcpy_s(this->name, name);
		cout << "ctor Worker" << endl;
	}
	Worker(char* name) :Worker(name,age) {}
	Worker(int age) :Worker("", age) {}
	virtual ~Worker() {
		cout << "dtor Worker" << endl;
	}

	virtual void Show() {
		cout << "name:" << name << " age: " << age << endl;
	}

	 void Print() {
		cout << "im not virtual class Worker" << endl;
	}


};

class Engenner :public Worker {
	int salary;

public:
	Engenner(const char* name, int age, int salary) :Worker(name, age) {
		this->salary = salary;
	}
	Engenner(const Engenner& engenner) :Worker(engenner) {
		this->salary = engenner.salary;

	}
	~Engenner() override {
		cout << "dtor Engenner" << endl;
	}



	void Show() override {
		Worker::Show();
		cout << "im virtual salary:" << salary << endl;
	}

	void Print()  {
		cout << "im not virtual class Engenner " << endl;
	}
	
};

class Absclass {
public:
	virtual void abs() const = 0;
	virtual ~Absclass() {}
};

void Comon1(Worker& worker) {
	worker.Show();
	worker.Print();
}

void Comon2(Worker* worker) {
	worker->Show();
	worker->Print();
}

int main() {

	Engenner engenner1("Boris", 40, 5600);
	//engenner1.Show();
	//engenner1.Print();

	Comon1(engenner1);

	//Comon2(&engenner1);

	// Absclass abs
	cout << "_____________" << endl;

	Worker* ptrVirtual = new Engenner("Andre", 55, 5467);
	ptrVirtual->Show();
	delete ptrVirtual;
	cout << "_____________" << endl;

	Worker* arr[] = {
	    new Worker("Worker1",43),
		new Engenner("Engenner1",73,5324),
		new Engenner("Engenner2",33,2224),
	};

	for (int i = 0; i < 3; i++) {
		arr[i]->Show();
		arr[i]->Print();
		
		delete arr[i];
		cout << "_____________" << endl;
	}

	return 0;
}

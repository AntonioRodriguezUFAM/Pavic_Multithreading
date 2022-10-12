// Pavic Multithreading C++ - 2022

#include<iostream>
#include<thread>
using namespace std;

void call_from_thread() {
	cout << "Hello, World from Thread" << endl;
}

int main() {

	// Launch a thread

	thread t1(call_from_thread);
	cout << "Hello, World from CPU" << endl;

	t1.join();
	cout << "Hello, World from CPU - after Join" << endl;

	return 0;



}
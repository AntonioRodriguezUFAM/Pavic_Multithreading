/*
* @file: Aula-05 01-Multithreading.cpp
* @program: Pavic-Lab_Computação_Parallel 2022
* @brief: Multithreading
* @group: Motorola - UFAC
* @author: Antonio Souto Rodriguez
*/

// Pavic Multithreading C++ - 2022

// To use the std::cout / printf!!
#include<iostream>

// This function will be called from a thread
#include<thread>

//using namespace std; // Removed std::

void Antonio(int tid) {
	printf("Antonio threads \n");
	std::cout << "Launched by thread = " << tid << std::endl;
}

void call_from_thread() {
	std::cout << "Hello, World from Thread" << std::endl;
}

// Code Main

int main() {

	// Launch a thread

	std::thread t1(call_from_thread);
	std::thread antonio(Antonio);

	//Join the thread with the main thread
	// For this particular code, the main function creates a thread 
	// and wait for the thread to finish at t1.join()

	std::cout << "Hello, World from CPU" << std::endl;

	antonio.join();
	t1.join();
	// If you forget to wait for a thread to finish his work, 
	//it is possible that main will finish first and the program
	//will exit killing the previously created thread regardless if “call_from_thread” has finished or not.


	std::cout << "Hello, World from CPU - after Join" << std::endl;

	return 0;

}
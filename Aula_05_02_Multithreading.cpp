/*
* @file: Aula-05 02-Multithreading.cpp
* @program: Pavic-Lab_Computa��o_Parallel 2022
* @brief: Multithreading
* @group: Motorola - UFAC
* @author: Antonio Souto Rodriguez
*/


#include <iostream>
#include <thread>

//This function will be called from a thread
void call_from_thread() {
	std::cout << "Launched by thread" << std::endl;
}
static const int num_threads = 10;

int main() {
	std::thread t[num_threads];

	//Launch a group of threads
	for (int i = 0; i < num_threads; ++i) {
		t[i] = std::thread(call_from_thread);
	}
	std::cout << "Launched from the main\n";

	//Join the threads with the main thread
	for (int i = 0; i < num_threads; ++i) {
		t[i].join();
	}

	return 0;

}
#include <iostream>
#include <thread>
#include <chrono>

// Функция, которую будет выполнять первый поток
void threadFunction1() {
    while (true) {
        std::cout << "Thread 1 is running" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

// Функция, которую будет выполнять второй поток
void threadFunction2() {
    while(true) {
        std::cout << "Thread 2 is running" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

int main() {
    std::thread thread1(threadFunction1);
    std::thread thread2(threadFunction2);

    // Ожидание завершения работы потоков
    thread1.join();
    thread2.join();

    std::cout << "All threads have completed" << std::endl;

    return 0;
}

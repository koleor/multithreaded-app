#include <iostream>
#include <thread>
#include <chrono>

int i = 0;
int j = 0;
// Функция, которую будет выполнять первый поток
void threadFunction1(bool& finished) {
    while (i <= 5) {
        i++;
        std::cout << "Thread 1 is running" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        // Проверка условия завершения потока
        if (finished) {
            break;
        }
    }
}

// Функция, которую будет выполнять второй поток
void threadFunction2(bool& finished) {
    while (j<=10) {
        j++;
        std::cout << "Thread 2 is running" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        // Проверка условия завершения потока
        if (finished) {
            break;
        }
    }
}

int main() {


    bool finished = false; // Флаг для проверки завершения потоков

    std::thread thread1(threadFunction1, std::ref(finished));
    std::thread thread2(threadFunction2, std::ref(finished));

    // Ожидание завершения работы потоков
    thread1.join();
    thread2.join();

    finished = true; // Установка флага завершения потоков

    std::cout << "Both threads have finished execution" << std::endl;

    return 0;
}

#include <iostream>
#include <thread>
#include <mutex>

const int NUM_PHILOSOPHERS = 5;
std::mutex forks[NUM_PHILOSOPHERS];

void philosopher(int id) {
    int left_fork = id;
    int right_fork = (id + 1) % NUM_PHILOSOPHERS;

    while (true) {
    
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        // Блокировка левой и правой вилки
        forks[left_fork].lock();
        forks[right_fork].lock();

        std::cout << "Philosopher " << id << " is eating" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        // Разблокировка вилок
        forks[left_fork].unlock();
        forks[right_fork].unlock();
    }
}

int main() {
    std::thread philosophers[NUM_PHILOSOPHERS];

    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        philosophers[i] = std::thread(philosopher, i);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        philosophers[i].join();
    }

    return 0;
}
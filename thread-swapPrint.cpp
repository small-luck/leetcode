/*
 *两个线程n次交替打印各自函数中的数据
 *思路：使用互斥量和条件变量
 */

#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>

class Print {
public:
    Print(int count) : m_count(count) {}

    void printFoo() {
        for (int i = 0; i < m_count; i++) {
            std::unique_lock<std::mutex> locker(m_mutex);
            m_cond.wait(locker, [&](){return m_flag;});     //cond使用lambda表达式，如果返回true，则条件成立不阻塞，如果返回false，阻塞
            std::cout << "foo" << std::endl;
            m_flag = false;
            locker.unlock();
            m_cond.notify_one();
        }
    }

    void printBar() {
        for (int i = 0; i < m_count; i++) {
            std::unique_lock<std::mutex> locker(m_mutex);
            m_cond.wait(locker, [&](){return !m_flag;});
            std::cout << "bar" << std::endl;
            m_flag = true;
            locker.unlock();
            m_cond.notify_one();
        }
    }

    void test() {
        std::thread t1(&Print::printFoo, this);
        std::thread t2(&Print::printBar, this);
        t1.join();
        t2.join();
    }

private:
    int m_count;
    bool m_flag = true;
    std::mutex m_mutex;
    std::condition_variable m_cond;
};

int main()
{
    Print *p = new Print(10);
    p->test();

    delete p;
    p = nullptr;
    

    return 0;
}


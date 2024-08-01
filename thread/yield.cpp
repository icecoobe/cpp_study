#include <iostream>
#include <thread>

using namespace std;

__thread int a = 0;

int main()
{
    thread t = thread([](){
        for (int i = 0; i < 10; i++)
        {
            this_thread::yield();
            a += i;
            cout << hex << "[" << this_thread::get_id() << "] : " << a << endl;
            this_thread::yield();
            cout << "2222" << endl;
        }
    });

    thread t2 = thread([](){
        for (int i = 0; i < 10; i++)
        {
            this_thread::yield();
            a += i;
            cout << hex << this_thread::get_id() << ": " << a << endl;
            this_thread::yield();
            cout << "2222" << endl;
        }
    });

    t.join();
    t2.join();
    return 0;
}

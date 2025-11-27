#include <thread>
#include "Publisher.h"
#include "Subscriber.h"

int main()
{
    PublisherApp pub;

    if (!pub.init())
        return -1;

    //MyType data{ 1, 3.14 };
    //MyType2 data{ 1, 4 };
    //MyType3 data{ 1, true,3.61 };
    //MyType4 data{ 1, "naber?"};
    //MyType5 data{ 1, 5,12,13 };


    std::thread t1(&PublisherApp::FirstPublisherLoop, &pub);
    std::thread t2(&PublisherApp::SecondPublisherLoop, &pub);
    std::thread t3(&PublisherApp::ThirdPublisherLoop, &pub);
    std::thread t4(&PublisherApp::FourthPublisherLoop, &pub);
    std::thread t5(&PublisherApp::FifthPublisherLoop, &pub);

    // Threadleri çalýþmaya býrak
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    return 0;
}

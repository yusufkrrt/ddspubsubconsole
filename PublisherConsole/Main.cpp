#include "Publisher.h"
#include "Subscriber.h"
int main()
{
    PublisherApp pub;

    if (!pub.init()) return -1;

    MyType data{ 1, 3.14 };
    pub.publishLoop();

    std::this_thread::sleep_for(std::chrono::seconds(2));
}

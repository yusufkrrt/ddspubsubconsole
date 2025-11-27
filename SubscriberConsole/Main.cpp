#include "Subscriber.h"
#include <csignal>
#include <atomic>

std::atomic<bool> run(true);

void handler(int)
{
    run = false;
}

int main()
{
    signal(SIGINT, handler);

    SubscriberApp sub;

    if (!sub.init())
        return -1;

    std::cout << "Subscriber calisiyor... CTRL+C ile cikabilirsiniz...\n";

    while (run)
        std::this_thread::sleep_for(std::chrono::milliseconds(200));

    return 0;
}

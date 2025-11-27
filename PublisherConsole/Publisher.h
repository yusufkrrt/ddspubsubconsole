#pragma once
#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/publisher/Publisher.hpp>
#include <fastdds/dds/publisher/DataWriter.hpp>
#include <fastdds/dds/topic/Topic.hpp>
#include <fastdds/dds/core/status/StatusMask.hpp>
#include <iostream>
#include "MyType.h"

using namespace eprosima::fastdds::dds;

class PublisherApp
{
public:
    PublisherApp();
    ~PublisherApp();

    bool init();
    void FirstPublisherLoop();
    void SecondPublisherLoop();
    void ThirdPublisherLoop();
    void FourthPublisherLoop();
    void FifthPublisherLoop();
    void publish(const MyType& data);
    void publishLoop();

private:
    DomainParticipant* participant,*participant1,*participant2, *participant3, *participant4, *participant5;
    Publisher* publisher,*publisher1, *publisher2, *publisher3, *publisher4, *publisher5;
    Topic* topic1, *topic2, *topic3, *topic4, *topic5;
    DataWriter* writer1, *writer2, *writer3,* writer4, *writer5 ;
};

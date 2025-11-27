#pragma once
#include <fastdds/dds/domain/DomainParticipant.hpp>
#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
#include <fastdds/dds/subscriber/Subscriber.hpp>
#include <fastdds/dds/subscriber/DataReader.hpp>
#include <fastdds/dds/topic/Topic.hpp>
#include <fastdds/dds/subscriber/DataReaderListener.hpp>
#include <fastdds/dds/core/status/StatusMask.hpp>
#include <iostream>
#include "MyType.h"

using namespace eprosima::fastdds::dds;

class MyListener : public DataReaderListener
{
public:
    void on_data_available(DataReader* reader) override;

};

class SubscriberApp
{
public:
    SubscriberApp();
    ~SubscriberApp();

    bool init();

private:
    DomainParticipant* participant1,*participant2, * participant3, * participant4, * participant5;
    Subscriber* subscriber1, * subscriber2, * subscriber3, * subscriber4, * subscriber5;
    Topic* topic1, * topic2, * topic3, * topic4, * topic5;
    DataReader* reader1, * reader2, * reader3, * reader4, * reader5;
    MyListener listener1, listener2, listener3, listener4, listener5 ;
};

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
    void publish(const MyType& data);
    void publishLoop();

private:
    DomainParticipant* participant_;
    Publisher* publisher_;
    Topic* topic_;
    DataWriter* writer_;
};

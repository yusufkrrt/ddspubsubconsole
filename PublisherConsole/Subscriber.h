//#pragma once
//#include <fastdds/dds/domain/DomainParticipant.hpp>
//#include <fastdds/dds/domain/DomainParticipantFactory.hpp>
//#include <fastdds/dds/subscriber/Subscriber.hpp>
//#include <fastdds/dds/subscriber/DataReader.hpp>
//#include <fastdds/dds/topic/Topic.hpp>
//#include <fastdds/dds/subscriber/DataReaderListener.hpp>
//#include <fastdds/dds/core/status/StatusMask.hpp>
//#include <iostream>
//#include "MyType.h"
//
//using namespace eprosima::fastdds::dds;
//
//class MyListener : public DataReaderListener
//{
//public:
//    void on_data_available(DataReader* reader) override;
//};
//
//class SubscriberApp
//{
//public:
//    SubscriberApp();
//    ~SubscriberApp();
//
//    bool init();
//
//private:
//    DomainParticipant* participant1;
//    Subscriber* subscriber1;
//    Topic* topic1;
//    DataReader* reader1;
//    MyListener listener_;
//};
//NOT USED FOR NOW
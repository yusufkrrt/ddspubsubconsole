#include "Subscriber.h"
#include <fastdds/dds/topic/TypeSupport.hpp>
#include "TopicDataType_MyType.h"
#include "TopicDataType_MyType2.h"
#include "TopicDataType_MyType3.h"
#include "TopicDataType_MyType4.h"
#include "TopicDataType_MyType5.h"

using namespace eprosima::fastdds::dds;
/// <summary>
/// Variable identify and start variables
/// </summary>
SubscriberApp::SubscriberApp()
    : participant1(nullptr), participant2(nullptr), participant3(nullptr), participant4(nullptr), participant5(nullptr),
    subscriber1(nullptr), subscriber2(nullptr), subscriber3(nullptr),subscriber4(nullptr), subscriber5(nullptr),
    topic1(nullptr), topic2(nullptr), topic3(nullptr), topic4(nullptr), topic5(nullptr),
    reader1(nullptr), reader2(nullptr), reader3(nullptr), reader4(nullptr), reader5(nullptr)
{
}
/// <summary>
/// This works when task killed or goes out of scope
/// </summary>
SubscriberApp::~SubscriberApp()
{
    if (participant1)
    {
        participant1->delete_contained_entities();
        DomainParticipantFactory::get_instance()->delete_participant(participant1);
    }
    //if (participant2)
    //{
    //    participant2->delete_contained_entities();
    //    DomainParticipantFactory::get_instance()->delete_participant(participant2);
    //}    
    //if (participant3)
    //{
    //    participant3->delete_contained_entities();
    //    DomainParticipantFactory::get_instance()->delete_participant(participant3);
    //}    
    //if (participant4)
    //{
    //    participant4->delete_contained_entities();
    //    DomainParticipantFactory::get_instance()->delete_participant(participant4);
    //}    
    //if (participant5)
    //{
    //    participant5->delete_contained_entities();
    //    DomainParticipantFactory::get_instance()->delete_participant(participant5);
    //}
}
/// <summary>
/// This works when app initialize
/// </summary>
/// <returns></returns>
bool SubscriberApp::init()
{
    // DomainParticipant oluştur
    DomainParticipantQos participantQos;
	participantQos.transport().use_builtin_transports = true; //This must be true to use built-in transport layers
    //We need only one subscriber and only one participant for all topics and 
    participant1 = DomainParticipantFactory::get_instance()->create_participant(0, participantQos);
    if (!participant1) { std::cerr << "Participant olusturulamadi\n"; return false; }

    // TypeSupport


    TypeSupport type(new TopicDataType_MyType());
    TypeSupport type1(new TopicDataType_MyType2());
    TypeSupport type2(new TopicDataType_MyType3());
    TypeSupport type3(new TopicDataType_MyType4());
    TypeSupport type4(new TopicDataType_MyType5());

    if (type.register_type(participant1) != RETCODE_OK) return false;
    if (type1.register_type(participant1) != RETCODE_OK) return false;
    if (type2.register_type(participant1) != RETCODE_OK) return false;
    if (type3.register_type(participant1) != RETCODE_OK) return false;
    if (type4.register_type(participant1) != RETCODE_OK) return false;

	//We need only one subscriber and only one participant for all topics and readers
    subscriber1 = participant1->create_subscriber(SUBSCRIBER_QOS_DEFAULT);
    if (!subscriber1) return false;

	// Topics and datareaders
    topic1 = participant1->create_topic("MyTopic1", type.get_type_name(), TOPIC_QOS_DEFAULT);
    topic2 = participant1->create_topic("MyTopic2", type1.get_type_name(), TOPIC_QOS_DEFAULT);
    topic3 = participant1->create_topic("MyTopic3", type2.get_type_name(), TOPIC_QOS_DEFAULT);
    topic4 = participant1->create_topic("MyTopic4", type3.get_type_name(), TOPIC_QOS_DEFAULT);
    topic5 = participant1->create_topic("MyTopic5", type4.get_type_name(), TOPIC_QOS_DEFAULT);

    reader1 = subscriber1->create_datareader(topic1, DATAREADER_QOS_DEFAULT, &listener1);
    reader2 = subscriber1->create_datareader(topic2, DATAREADER_QOS_DEFAULT, &listener2);
    reader3 = subscriber1->create_datareader(topic3, DATAREADER_QOS_DEFAULT, &listener3);
    reader4 = subscriber1->create_datareader(topic4, DATAREADER_QOS_DEFAULT, &listener4);
    reader5 = subscriber1->create_datareader(topic5, DATAREADER_QOS_DEFAULT, &listener5);

    std::cout << "Subscriberlar baslatildi\n";
    return true;
}

/// <summary>
/// This works when we have availabe datas
/// </summary>
/// <param name="reader"></param>
void MyListener::on_data_available(DataReader* reader)
{
    //first topic is MyType, second is MyType2, third is MyType3, fourth is MyType4, fifth is MyType5
	// Take type names to identify which topic the data belongs to
    std::string type = reader->get_topicdescription()->get_type_name();
    if (type == "MyType")
    {
        MyType data;
        SampleInfo info;
        if (reader->take_next_sample(&data, &info) == RETCODE_OK)
            std::cout << "[MyType] id=" << data.id
            << " value=" << data.value << "\n" <<std::endl;
    }

    else if (type == "MyType2")
    {
        MyType2 data;
        SampleInfo info;
        if (reader->take_next_sample(&data, &info) == RETCODE_OK)
            std::cout << "[MyType2] Sensor id=" << data.sensor_id
            << " temperature=" << data.temperature<< "\n" <<std::endl;
    }

    else if (type == "MyType3")
    {
        MyType3 data;
        SampleInfo info;
        if (reader->take_next_sample(&data, &info) == RETCODE_OK)
            std::cout << "[MyType3] device id=" << data.device_id 
            << " isOk=" << data.status<< "voltage=" <<data.voltage<< "\n" << std::endl;
    }

    else if (type == "MyType4")
    {
        MyType4 data;
        SampleInfo info;
        if (reader->take_next_sample(&data, &info) == RETCODE_OK)
            std::cout << "[MyType4] id=" << data.channel
            << " msg=" << data.message << "\n" << std::endl;
    }

    else if (type == "MyType5")
    {
        MyType5 data;
        SampleInfo info;
        if (reader->take_next_sample(&data, &info) == RETCODE_OK)
            std::cout << "[MyType5] id=" << data.index
            << " a=" << data.x
            << " b=" << data.y
            << " c=" << data.z << "\n" << std::endl;
    }
}


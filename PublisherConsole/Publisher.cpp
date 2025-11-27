#include "Publisher.h"
#include <fastdds/dds/topic/TypeSupport.hpp>
#include "TopicDataType_MyType.h"
#include "TopicDataType_MyType2.h"
#include "TopicDataType_MyType3.h"
#include "TopicDataType_MyType4.h"
#include "TopicDataType_MyType5.h"
#include <cstring>
#include <chrono>
#include <thread>
#include <iostream>

/// <summary>
/// Variable identify and start variables
/// </summary>
PublisherApp::PublisherApp()
    : participant(nullptr), publisher(nullptr),
      topic1(nullptr), topic2(nullptr), topic3(nullptr), topic4(nullptr), topic5(nullptr),
      writer1(nullptr), writer2(nullptr), writer3(nullptr), writer4(nullptr), writer5(nullptr)
{
}
/// <summary>
/// This works when task killed or goes out of scope
/// </summary>
PublisherApp::~PublisherApp()
{
    if (participant)
    {
        participant->delete_contained_entities();
        DomainParticipantFactory::get_instance()->delete_participant(participant);
    }
}
/// <summary>
/// This works when app initialize
/// </summary>
bool PublisherApp::init()
{
    DomainParticipantQos participantQos;
    participantQos.transport().use_builtin_transports = true; //This must be true to use built-in transport layers


    participant = DomainParticipantFactory::get_instance()->create_participant(0, participantQos);
    if (!participant)
    {
        std::cerr << "Participant oluþturulamadý\n";
        return false;
    }

    // TypeSupport
    TypeSupport type1(new TopicDataType_MyType());
    TypeSupport type2(new TopicDataType_MyType2());
    TypeSupport type3(new TopicDataType_MyType3());
    TypeSupport type4(new TopicDataType_MyType4());
    TypeSupport type5(new TopicDataType_MyType5());

    if (type1.register_type(participant) != RETCODE_OK ||
        type2.register_type(participant) != RETCODE_OK ||
        type3.register_type(participant) != RETCODE_OK ||
        type4.register_type(participant) != RETCODE_OK ||
        type5.register_type(participant) != RETCODE_OK)
    {
        std::cerr << "Type register edilemedi\n";
        return false;
    }

    //Just one publisher for all topics and writers
    publisher = participant->create_publisher(PUBLISHER_QOS_DEFAULT);
    if (!publisher)
    {
        std::cerr << "Publisher oluþturulamadý\n";
        return false;
    }

    // Topics
    topic1 = participant->create_topic("MyTopic1", "MyType", TOPIC_QOS_DEFAULT);
    topic2 = participant->create_topic("MyTopic2", "MyType2", TOPIC_QOS_DEFAULT);
    topic3 = participant->create_topic("MyTopic3", "MyType3", TOPIC_QOS_DEFAULT);
    topic4 = participant->create_topic("MyTopic4", "MyType4", TOPIC_QOS_DEFAULT);
    topic5 = participant->create_topic("MyTopic5", "MyType5", TOPIC_QOS_DEFAULT);

    if (!topic1 || !topic2 || !topic3 || !topic4 || !topic5)
    {
        std::cerr << "Topic oluþturulamadý\n";
        return false;
    }

    // DataWriters
    writer1 = publisher->create_datawriter(topic1, DATAWRITER_QOS_DEFAULT);
    writer2 = publisher->create_datawriter(topic2, DATAWRITER_QOS_DEFAULT);
    writer3 = publisher->create_datawriter(topic3, DATAWRITER_QOS_DEFAULT);
    writer4 = publisher->create_datawriter(topic4, DATAWRITER_QOS_DEFAULT);
    writer5 = publisher->create_datawriter(topic5, DATAWRITER_QOS_DEFAULT);

    if (!writer1 || !writer2 || !writer3 || !writer4 || !writer5)
    {
        std::cerr << "Writer oluþturulamadý\n";
        return false;
    }

    std::cout << "Publisherlar baþlatýldý\n";
    return true;
}

// 1. Publisher Loop
void PublisherApp::FirstPublisherLoop()
{
    int counter = 1;
    while (true)
    {
        if (!writer1) break;

        MyType data;
        data.id = counter;
        data.value = counter * 3.14f;

        writer1->write(&data);
        std::cout << "[MyType 1] id=" << data.id << " value=" << data.value << "\n";

        counter++;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

// 2. Publisher Loop
void PublisherApp::SecondPublisherLoop()
{
    int counter = 1;
    while (true)
    {
        if (!writer2) break;

        MyType2 data;
        data.sensor_id = counter;
        data.temperature = counter + 1.1;

        writer2->write(&data);
        std::cout << "[MyType 2] Sensor id=" << data.sensor_id << " Temperature=" << data.temperature << "\n";

        counter++;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

// 3. Publisher Loop
void PublisherApp::ThirdPublisherLoop()
{
    int counter = 1;
    while (true)
    {
        if (!writer3) break;

        MyType3 data;
        data.device_id = counter;
        data.status = counter % 2 == 0;
        data.voltage = counter * 1.5f;

        writer3->write(&data);
        std::cout << "[MyType 3] id=" << data.device_id << " status=" << data.status << " voltage=" << data.voltage << "\n";

        counter++;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

// 4. Publisher Loop
void PublisherApp::FourthPublisherLoop()
{
    int counter = 1;
    while (true)
    {
        if (!writer4) break;

        MyType4 data;
        data.channel = counter;
        strcpy_s(data.message, sizeof(data.message), ("Selam " + std::to_string(counter)).c_str());

        writer4->write(&data);
        std::cout << "[MyType 4] Channel=" << data.channel << " message=" << data.message << "\n";

        counter++;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

// 5. Publisher Loop
void PublisherApp::FifthPublisherLoop()
{
    int counter = 1;
    while (true)
    {
        if (!writer5) break;

        MyType5 data;
        data.index = counter;
        data.x = counter * 1.1f;
        data.y = counter * 2.2f;
        data.z = counter * 3.3f;

        writer5->write(&data);
        std::cout << "[MyType 5] index=" << data.index << " x=" << data.x << " y=" << data.y << " z=" << data.z << "\n";

        counter++;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

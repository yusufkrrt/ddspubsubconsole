#include "Publisher.h"
#include <fastdds/dds/topic/TypeSupport.hpp>
#include "TopicDataType_MyType.h"

PublisherApp::PublisherApp()
    : participant_(nullptr), publisher_(nullptr), topic_(nullptr), writer_(nullptr)
{
}

PublisherApp::~PublisherApp()
{
    if (participant_)
    {
        participant_->delete_contained_entities();
        DomainParticipantFactory::get_instance()->delete_participant(participant_);
    }
}

bool PublisherApp::init()
{
    DomainParticipantQos participantQos;
    participantQos.transport().use_builtin_transports = true;
    participant_ = DomainParticipantFactory::get_instance()->create_participant(0, participantQos);
    if (!participant_) { std::cerr << "Participant oluþturulamadý\n"; return false; }
    // MyType için TypeSupport oluþtur ve register et
    TypeSupport type(new TopicDataType_MyType());
    if (type.register_type(participant_) != RETCODE_OK)
    {
        std::cerr << "Type register edilemedi\n";
        return false;
    }

    publisher_ = participant_->create_publisher(PUBLISHER_QOS_DEFAULT);
    if (!publisher_) { std::cerr << "Publisher oluþturulamadý\n"; return false; }

    topic_ = participant_->create_topic("MyTopic", "MyType", TOPIC_QOS_DEFAULT);
    if (!topic_) { std::cerr << "Topic oluþturulamadý\n"; return false; }

    writer_ = publisher_->create_datawriter(topic_, DATAWRITER_QOS_DEFAULT);
    if (!writer_) { std::cerr << "Writer oluþturulamadý\n"; return false; }

    std::cout << "Publisher baþlatýldý\n";
    return true;
}
//
//void PublisherApp::publish(const MyType& data)
//{
//    if (!writer_) return;
//
//    // C-style yazým, serialize yok, yalnýzca örnek
//    writer_->write((void*)&data);
//    std::cout << "Gönderildi: id=" << data.id << " value=" << data.value << "\n";
//}
void PublisherApp::publishLoop()
{
    int counter = 1;
    while (true)
    {
        MyType data;
        data.id = counter;
        data.value = counter * 3.14f;

        writer_->write(&data);
        std::cout << "Gönderildi: id=" << data.id << " value=" << data.value << "\n";

        counter++;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
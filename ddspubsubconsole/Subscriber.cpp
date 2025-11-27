#include "Subscriber.h"
#include <fastdds/dds/topic/TypeSupport.hpp>
#include "TopicDataType_MyType.h"

using namespace eprosima::fastdds::dds;

SubscriberApp::SubscriberApp()
    : participant_(nullptr), subscriber_(nullptr), topic_(nullptr), reader_(nullptr)
{
}

SubscriberApp::~SubscriberApp()
{
    if (participant_)
    {
        participant_->delete_contained_entities();
        DomainParticipantFactory::get_instance()->delete_participant(participant_);
    }
}

bool SubscriberApp::init()
{
    // DomainParticipant oluþtur
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

    // Subscriber oluþtur
    subscriber_ = participant_->create_subscriber(SUBSCRIBER_QOS_DEFAULT);
    if (!subscriber_) { std::cerr << "Subscriber oluþturulamadý\n"; return false; }

    // Topic oluþtur
    topic_ = participant_->create_topic("MyTopic", type.get_type_name(), TOPIC_QOS_DEFAULT);
    if (!topic_) { std::cerr << "Topic oluþturulamadý\n"; return false; }

    // DataReader oluþtur
    reader_ = subscriber_->create_datareader(topic_, DATAREADER_QOS_DEFAULT, &listener_);
    if (!reader_) { std::cerr << "Reader oluþturulamadý\n"; return false; }

    std::cout << "Subscriber baþlatýldý\n";
    return true;
}

// Listener callback
void MyListener::on_data_available(DataReader* reader)
{
    MyType data;
    SampleInfo info;
    if (reader->take_next_sample(&data, &info) == RETCODE_OK)
    {
        if (info.valid_data)
        {
            std::cout << "Alýndý: id=" << data.id << " value=" << data.value << "\n";
        }
    }
}

//#include "Subscriber.h"
//#include <fastdds/dds/topic/TypeSupport.hpp>
//#include "TopicDataType_MyType.h"
//
//using namespace eprosima::fastdds::dds;
//
//SubscriberApp::SubscriberApp()
//    : participant1(nullptr), subscriber1(nullptr), topic1(nullptr), reader1(nullptr)
//{
//}
//
//SubscriberApp::~SubscriberApp()
//{
//    if (participant1)
//    {
//        participant1->delete_contained_entities();
//        DomainParticipantFactory::get_instance()->delete_participant(participant1);
//    }
//}
//
//bool SubscriberApp::init()
//{
//    // DomainParticipant oluþtur
//    DomainParticipantQos participantQos;
//    participantQos.transport().use_builtin_transports = true;
//    participant1 = DomainParticipantFactory::get_instance()->create_participant(0, participantQos);
//    if (!participant1) { std::cerr << "Participant oluþturulamadý\n"; return false; }
//
//    // MyType için TypeSupport oluþtur ve register et
//    TypeSupport type(new TopicDataType_MyType());
//    if (type.register_type(participant1) != RETCODE_OK)
//    {
//        std::cerr << "Type register edilemedi\n";
//        return false;
//    }
//
//    // Subscriber oluþtur
//    subscriber1 = participant1->create_subscriber(SUBSCRIBER_QOS_DEFAULT);
//    if (!subscriber1) { std::cerr << "Subscriber oluþturulamadý\n"; return false; }
//
//    // Topic oluþtur
//    topic1 = participant1->create_topic("MyTopic", type.get_type_name(), TOPIC_QOS_DEFAULT);
//    if (!topic1) { std::cerr << "Topic oluþturulamadý\n"; return false; }
//
//    // DataReader oluþtur
//    reader1 = subscriber1->create_datareader(topic1, DATAREADER_QOS_DEFAULT, &listener_);
//    if (!reader1) { std::cerr << "Reader oluþturulamadý\n"; return false; }
//
//    std::cout << "Subscriber baþlatýldý\n";
//    return true;
//}
//
//// Listener callback
//void MyListener::on_data_available(DataReader* reader)
//{
//    MyType data;
//    SampleInfo info;
//    if (reader->take_next_sample(&data, &info) == RETCODE_OK)
//    {
//        if (info.valid_data)
//        {
//            std::cout << "Alýndý: id=" << data.id << " value=" << data.value << "\n";
//        }
//    }
//}

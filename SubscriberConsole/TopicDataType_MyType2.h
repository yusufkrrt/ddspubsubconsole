#pragma once
#include <fastdds/dds/topic/TopicDataType.hpp>
#include <fastdds/rtps/common/SerializedPayload.hpp>
#include "MyType.h"
//My types greeting with TopicDataType

class TopicDataType_MyType2 : public eprosima::fastdds::dds::TopicDataType
{
public:
    TopicDataType_MyType2()
    {
        set_name("MyType2");
        max_serialized_type_size = static_cast<uint32_t>(sizeof(MyType2));
        is_compute_key_provided = false;
    }

    bool serialize(const void* data, eprosima::fastdds::rtps::SerializedPayload_t & payload, eprosima::fastdds::dds::DataRepresentationId_t) override
    {
        const MyType2* mydata = static_cast<const MyType2*>(data);
        if (payload.max_size < sizeof(MyType2))
            return false;
        std::memcpy(payload.data, mydata, sizeof(MyType2));
        payload.length = static_cast<uint32_t>(sizeof(MyType2));
        return true;
    }

    bool deserialize(eprosima::fastdds::rtps::SerializedPayload_t & payload, void* data) override
    {
        if (payload.length < sizeof(MyType2))
            return false;
        std::memcpy(data, payload.data, sizeof(MyType2));
        return true;
    }

    uint32_t calculate_serialized_size(const void* /*data*/, eprosima::fastdds::dds::DataRepresentationId_t) override
    {
        return static_cast<uint32_t>(sizeof(MyType2));
    }

    void* create_data() override { return new MyType2(); }
    void delete_data(void* data) override { delete static_cast<MyType2*>(data); }

    bool compute_key(eprosima::fastdds::rtps::SerializedPayload_t&, eprosima::fastdds::rtps::InstanceHandle_t&, bool) override { return false; }
    bool compute_key(const void* /*data*/, eprosima::fastdds::rtps::InstanceHandle_t&, bool) override { return false; }
};
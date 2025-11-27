#pragma once
#include <fastdds/dds/topic/TopicDataType.hpp>
#include <fastdds/rtps/common/SerializedPayload.hpp>
#include "MyType.h"
//My types greeting with TopicDataType

class TopicDataType_MyType5 : public eprosima::fastdds::dds::TopicDataType
{
public:
    TopicDataType_MyType5()
    {
        set_name("MyType5");
        max_serialized_type_size = static_cast<uint32_t>(sizeof(MyType5));
        is_compute_key_provided = false;
    }

    bool serialize(const void* data, eprosima::fastdds::rtps::SerializedPayload_t& payload, eprosima::fastdds::dds::DataRepresentationId_t) override
    {
        const MyType5* mydata = static_cast<const MyType5*>(data);
        if (payload.max_size < sizeof(MyType5))
            return false;
        std::memcpy(payload.data, mydata, sizeof(MyType5));
        payload.length = static_cast<uint32_t>(sizeof(MyType5));
        return true;
    }

    bool deserialize(eprosima::fastdds::rtps::SerializedPayload_t& payload, void* data) override
    {
        if (payload.length < sizeof(MyType5))
            return false;
        std::memcpy(data, payload.data, sizeof(MyType5));
        return true;
    }

    uint32_t calculate_serialized_size(const void* /*data*/, eprosima::fastdds::dds::DataRepresentationId_t) override
    {
        return static_cast<uint32_t>(sizeof(MyType5));
    }

    void* create_data() override { return new MyType5(); }
    void delete_data(void* data) override { delete static_cast<MyType5*>(data); }

    bool compute_key(eprosima::fastdds::rtps::SerializedPayload_t&, eprosima::fastdds::rtps::InstanceHandle_t&, bool) override { return false; }
    bool compute_key(const void* /*data*/, eprosima::fastdds::rtps::InstanceHandle_t&, bool) override { return false; }
};
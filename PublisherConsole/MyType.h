#pragma once

struct MyType
{
    int id;
    float value;
};

struct MyType2
{
    int sensor_id;
    double temperature;
};

struct MyType3
{
    int device_id;
    bool status;
    float voltage;
};

struct MyType4
{
    int channel;
    char message[512];
};

struct MyType5
{
    int index;
    float x;
    float y;
    float z;
};
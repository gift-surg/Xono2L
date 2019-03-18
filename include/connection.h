#pragma once

enum Interface
{
    Ulterius,
    Epiphan
};

class Stream
{
protected:
    enum Interface interface;
    bool initialised;
protected:
    Stream();
public:
    ~Stream();
public:
    static Stream& get_instance();
    void set_interface(const char *device_ident);
    Interface get_interface();
};

static Stream& stream = Stream::get_instance();

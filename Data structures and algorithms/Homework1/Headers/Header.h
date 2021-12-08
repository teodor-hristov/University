#ifndef HOMEWORK1_HEADER_H
#define HOMEWORK1_HEADER_H
enum class EventType{
    clientCome,
    clientGone,
    workerSend,
    workerCome
};

struct Resource{
    int bananas;
    int schweppes;
};

struct Event{
    EventType type;
    void* objectRole;

    Event(EventType type,void* const object) : type(type), objectRole(object){};
};

struct Worker{
    unsigned departTime;
    unsigned returnTime;
    ResourceType resourceType;
};



#endif //HOMEWORK1_HEADER_H

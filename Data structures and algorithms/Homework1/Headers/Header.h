#pragma once

#ifndef HOMEWORK1_HEADER_H
#define HOMEWORK1_HEADER_H

#include "../Interfaces/interface.h"

const int WORKER_TIME_COST = 60;
const int WORKER_RETURN_QUANTITY = 100;

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

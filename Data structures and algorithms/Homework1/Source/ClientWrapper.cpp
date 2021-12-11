#include "../Headers/ClientWrapper.h"

ClientWrapper::ClientWrapper(const Client &client, int id) : Client(client), isDeparted(false), id(id){
}

bool ClientWrapper::operator<(const ClientWrapper &rhs) const {
    return this->arriveMinute + this->maxWaitTime <
    rhs.arriveMinute + rhs.maxWaitTime;
}

bool ClientWrapper::operator>(const ClientWrapper &rhs) const {
    return !(*this < rhs);
}

bool ClientWrapper::operator<=(const ClientWrapper &rhs) const {
    return (*this < rhs) && (*this == rhs);
}

bool ClientWrapper::operator>=(const ClientWrapper &rhs) const {
    return (*this > rhs) && (*this == rhs);
}

bool ClientWrapper::operator==(const ClientWrapper &rhs) const {
    return this->arriveMinute + this->maxWaitTime ==
           rhs.arriveMinute + rhs.maxWaitTime;
}



#ifndef HOMEWORK1_CLIENTWRAPPER_H
#define HOMEWORK1_CLIENTWRAPPER_H
#include "../Interfaces/interface.h"

struct ClientWrapper : Client{
    bool isDeparted;

    explicit ClientWrapper(const Client& client);
    bool operator==(const ClientWrapper &rhs) const;
    bool operator<(const ClientWrapper &rhs) const;
    bool operator>(const ClientWrapper &rhs) const;
    bool operator<=(const ClientWrapper &rhs) const;
    bool operator>=(const ClientWrapper &rhs) const;
};

#endif //HOMEWORK1_CLIENTWRAPPER_H

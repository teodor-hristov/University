#ifndef HOMEWORK1_MYSTORE_H
#define HOMEWORK1_MYSTORE_H

#include <vector>
#include "Header.h"
#include "../Headers/linked_list.hpp"
#include "../Headers/ClientWrapper.h"
#include "../Headers/Utils.h"
#include "../Interfaces/interface.h"

struct MyStore : Store{
private:
    int clientsCount;
    int workersCount;
    Resource resources{};
    linked_list<Worker> workersSend;
    linked_list<ClientWrapper*> clientsComing;
    linked_list<ClientWrapper*> clientsGoing;

    std::vector<ClientWrapper*> allClients;
    std::vector<ClientWrapper*> clientsWaitlist;
    ActionHandler *actionHandler;

public:
    MyStore();
    ~MyStore() override;
    void init(int workerCount, int startBanana, int startSchweppes) override;
    void setActionHandler(ActionHandler *handler) override;
    void addClients(const Client *clients, int count) override;
    void advanceTo(int minute) override;
    int getBanana() const override;
    int getSchweppes() const override;

    void sendWorker(unsigned minute, ResourceType resource);
    void retrieveWorker();

    ClientWrapper& getLastClientByGoingTime();

    void clientDepart(ClientWrapper& client, size_t minute, int banana, int schweppes);

    linked_list<Worker> getWorkers();
};
#endif //HOMEWORK1_MYSTORE_H
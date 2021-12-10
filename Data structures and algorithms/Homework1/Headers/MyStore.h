#ifndef HOMEWORK1_MYSTORE_H
#define HOMEWORK1_MYSTORE_H

#include <list>
#include <vector>
#include "../Interfaces/interface.h"
#include "../Headers/ClientWrapper.h"
#include "Header.h"

struct MyStore : Store{
private:
    int clientsCount;
    int workersCount;
    Resource resources{};
    std::list<Worker> workersSend;
    std::list<ClientWrapper*> clientsComing;
    std::list<ClientWrapper*> clientsGoing;
    std::vector<ClientWrapper*> clientsWaitlist;

    void sort();
public:
    ActionHandler *actionHandler = nullptr;

    MyStore();
    MyStore(const int bananasAvailable, const int schweppesAvailable);
    void init(int workerCount, int startBanana, int startSchweppes) override;
    void setActionHandler(ActionHandler *handler) override;
    void addClients(const Client *clients, int count) override;
    void advanceTo(int minute) override;
    int getBanana() const override;
    int getSchweppes() const override;

    void sendWorker(unsigned minute, ResourceType resource);
    void retrieveWorker();

    ClientWrapper& getLastClientByGoingTime();
    ClientWrapper& getFirstByComingTime();
    ClientWrapper& getFirstByGoingTime();

    void clientDepart(ClientWrapper& client, size_t minute, int banana, int schweppes);

    std::list<Worker> getWorkers();
};
#endif //HOMEWORK1_MYSTORE_H
#ifndef HOMEWORK1_MYSTORE_H
#define HOMEWORK1_MYSTORE_H

#include <list>
#include "../Interfaces/interface.h"
#include "Header.h"

struct MyStore : Store{
private:
    Resource resources{};
    std::list<Worker> workers;
    std::list<Client> clients;
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
};
#endif //HOMEWORK1_MYSTORE_H
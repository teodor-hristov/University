#include <list>
#include <stdexcept>
#include "../Headers/MyStore.h"

MyStore::MyStore() : resources({0, 0}) {};

MyStore::MyStore(const int bananasAvailable, const int schweppesAvailable) {
    if (bananasAvailable < 0 || schweppesAvailable < 0) {
        throw std::invalid_argument("Amount cannot be negative!");
    }

    resources = {bananasAvailable, schweppesAvailable};
}

void MyStore::setActionHandler(ActionHandler *handler) {
    actionHandler = handler;
}

void MyStore::init(int workerCount, int startBanana, int startSchweppes) {
    MyStore(startBanana, startSchweppes);
    //TODO:do we need worker count??
}

void MyStore::addClients(const Client *client, int count) {
    if (!client) {
        return;
    }

    for (int i = 0; i < count; ++i) {
        clients.push_back(client[i]);
    }
}

void MyStore::advanceTo(int minute) {
    actionHandler->onWorkerSend(0, ResourceType::banana);
    actionHandler->onWorkerBack(0, ResourceType::schweppes);
    actionHandler->onClientDepart(0, 0, 1, 2);
}

int MyStore::getBanana() const {
    return resources.bananas;
}

int MyStore::getSchweppes() const {
    return resources.schweppes;
}

Store *createStore() {
    return new MyStore();
}


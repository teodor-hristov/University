#include <iostream>
#include <vector>
#include "../Interfaces/interface.h"
#include "../Headers/MyStore.h"

using namespace std;

int clientGoingMinute(const Client& client){
    return client.arriveMinute + client.maxWaitTime;
}

int main() {
    int workers;
    int clients;
    Client tempClient{};
    vector<Client> clientVect;
    auto *store = (MyStore *) createStore();

    cout << "Add workers, than clients." << endl;
    cin >> workers >> clients;

    store->init(workers, 0, 0);

    cout << "Add " << clients << " clients." << endl;
    for (int i = 0; i < clients; ++i) {
        cin >> tempClient.arriveMinute >> tempClient.banana >> tempClient.schweppes >> tempClient.maxWaitTime;
        clientVect.push_back(tempClient);
    }

    store->addClients(clientVect.data(), clients);
    int lastMin = clients ? clientGoingMinute(store->getLastClientByGoingTime()) : 0;
    store->advanceTo(lastMin);

    delete store;
}

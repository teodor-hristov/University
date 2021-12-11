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

    cin >> workers >> clients;

    store->init(workers, 0, 0);

    for (int i = 0; i < clients; ++i) {
        cin >> tempClient.arriveMinute >> tempClient.banana >> tempClient.schweppes >> tempClient.maxWaitTime;
        clientVect.push_back(tempClient);
    }

    store->addClients(clientVect.data(), clients);
    int lastMin = clientGoingMinute(store->getLastClientByGoingTime());
    store->advanceTo(lastMin);

    delete store;
}

/*
5 6
0 250 300 500
10 50 0 50
60 101 30 20
110 1000 50 490
130 50 50 210
160 90 70 20

5 6
0 250 300 500
10 50 0 50
60 101 30 20
110 1000 50 490
130 100 70 210
160 90 70 20
 */

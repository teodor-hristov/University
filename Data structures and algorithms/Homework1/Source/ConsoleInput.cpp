#include <iostream>
#include "../Interfaces/interface.h"
#include "../Headers/MyStore.h"

using namespace std;

void clientToString(const Client& client){
    cout << "Client to string: " << client.arriveMinute <<
    " " << client.banana <<
    " " << client.schweppes <<
    " " << client.maxWaitTime << endl;
}

int main() {
    int workers;
    int clients;
    Client tempClient{};
    MyStore *store = (MyStore *) createStore();

    cin >> workers >> clients;

    store->init(clients, 0, 0);

    for (int i = 0; i < clients; ++i) {
        cin >> tempClient.arriveMinute >> tempClient.banana >> tempClient.schweppes >> tempClient.maxWaitTime;
        store->addClients(&tempClient, 1);
        clientToString(tempClient);
    }


}

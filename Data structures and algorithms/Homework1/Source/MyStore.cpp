#include <iostream>
#include <list>
#include <stdexcept>
#include "../Headers/MyStore.h"

static int clientGoingMinute(const Client& client){
    return client.arriveMinute + client.maxWaitTime;
}

MyStore::MyStore() : resources({0, 0}),
clientsCount(0), workersCount(0) {};

MyStore::MyStore(const int bananasAvailable, const int schweppesAvailable) : clientsCount(0),
workersCount(0){
    if (bananasAvailable < 0 || schweppesAvailable < 0) {
        throw std::invalid_argument("Amount cannot be negative!");
    }

    resources = {bananasAvailable, schweppesAvailable};
}

void MyStore::setActionHandler(ActionHandler *handler) {
    actionHandler = handler;
}

void MyStore::init(int workerCount, int startBanana, int startSchweppes) {
    *this = MyStore(startBanana, startSchweppes);
    this->workersCount = workerCount;
}

//======= do not commit ======
bool PComp(const ClientWrapper * const & a, const ClientWrapper * const & b)
{
    return *a < *b;
}
//===========================

void MyStore::sort(){
    this->clientsGoing.sort(PComp);
}

void MyStore::addClients(const Client *client, int count) {
    if (!client) {
        return;
    }
    ClientWrapper* tempWrapper = nullptr;
    //TODO: opravi pametta

    clientsCount = count;

    for (int i = 0; i < count; ++i) {
        tempWrapper = new ClientWrapper(client[i]);
        clientsComing.push_back(tempWrapper);
        clientsGoing.push_back(tempWrapper);
    }

    sort();
}

void MyStore::advanceTo(int minute) {
    Resource tempRes = {0,0};
    ClientWrapper* temp;
    int availableWorkers = workersCount;
    int expectedBananas = 0;
    int expectedSchweppes = 0;

    for (size_t i = 0; i <= minute; ++i) {
        /*Send workers*/
        if (!clientsComing.empty() && clientsComing.front()->arriveMinute == i)
        {
            temp = clientsComing.front();
            if (getBanana() >= temp->banana && getSchweppes() >= temp->schweppes)
            {
                clientDepart(*temp, i,temp->banana, temp->schweppes);
            }
            else
            {
                while(availableWorkers > 0)
                {
                    if ((getBanana() < temp->banana) && (temp->banana - (getBanana() + expectedBananas)) > (temp->schweppes - (getSchweppes() + expectedSchweppes)))
                    {
                        sendWorker(i, ResourceType::banana);
                        expectedBananas += WORKER_RETURN_QUANTITY;
                        availableWorkers--;
                    }

                    if ((getBanana() < temp->schweppes) && (temp->schweppes - (getSchweppes() + expectedSchweppes)) > (temp->banana - (getBanana() + expectedBananas)))
                    {
                        sendWorker(i, ResourceType::schweppes);
                        expectedSchweppes += WORKER_RETURN_QUANTITY;
                        availableWorkers--;
                    }
                }

                clientsWaitlist.push_back(clientsComing.front());
                clientsComing.pop_front();
            }
        }

        /*Retrieve workers*/
        if (!workersSend.empty() && workersSend.front().returnTime == i)
        {
            while(!workersSend.empty() && workersSend.front().returnTime == i)
            {
                retrieveWorker();
                availableWorkers++;

                if (workersSend.front().resourceType == ResourceType::banana)
                {
                    expectedBananas -= WORKER_RETURN_QUANTITY;
                }
                else
                {
                    expectedSchweppes -= WORKER_RETURN_QUANTITY;
                }
            }

#if 1
            for (int j = 0; j < clientsWaitlist.size(); ++j)
            {
                temp = clientsWaitlist[j];
                if (getBanana() >= temp->banana && getSchweppes() >= temp->schweppes)
                {
                    clientDepart(*temp, i,temp->banana, temp->schweppes);
                }
            }
#endif
        }

        /*Client gone*/
        if (!clientsGoing.empty() && clientGoingMinute(*clientsGoing.front()) == i)
        {
            temp = clientsGoing.front();

            if (resources.bananas < temp->banana)   {tempRes.bananas = resources.bananas;}
            else {tempRes.bananas = temp->banana;}

            if (resources.schweppes < temp->schweppes)  {tempRes.schweppes = resources.schweppes;}
            else {tempRes.schweppes = temp->schweppes;}

            clientDepart(*temp, i,tempRes.bananas, tempRes.schweppes);
        }
    }
}

int MyStore::getBanana() const {
    return resources.bananas;
}

int MyStore::getSchweppes() const {
    return resources.schweppes;
}

ClientWrapper &MyStore::getLastClientByGoingTime() {
    return *clientsGoing.back();
}

ClientWrapper &MyStore::getFirstByComingTime() {
    return *clientsComing.front();
}

ClientWrapper &MyStore::getFirstByGoingTime() {
    return *clientsGoing.front();
}

std::list<Worker> MyStore::getWorkers() {
    return workersSend;
}

void MyStore::retrieveWorker() {
    if (workersSend.empty()){
        return;
    }

#ifdef TESTING
    actionHandler->onWorkerBack(workersSend.front().returnTime, workersSend.front().resourceType);
#endif
    std::cout << "D " << workersSend.front().returnTime << (workersSend.front().resourceType == ResourceType::banana ? " BANANA" : " SCHWEPPES") << std::endl;

    if (workersSend.front().resourceType == ResourceType::banana){
        resources.bananas += WORKER_RETURN_QUANTITY;
    }else{
        resources.schweppes += WORKER_RETURN_QUANTITY;
    }

    workersSend.pop_front();
}

void MyStore::sendWorker(const unsigned minute, ResourceType resource)
{
    workersSend.push_back({minute, minute + WORKER_TIME_COST, resource});
#ifdef TESTING
actionHandler->onWorkerSend(minute, resource);
#endif
    std::cout << "W " << minute << (resource == ResourceType::banana ? " BANANA" : " SCHWEPPES") << std::endl;
}

void MyStore::clientDepart(ClientWrapper& client, size_t minute, int banana, int schweppes) {
    static int id = 0;

    if (client.isDeparted)
        return;

    id++;
    client.isDeparted = true;

    std::cout << id << " " << minute << " " << banana << " " << schweppes << std::endl;
#ifdef TESTING
    actionHandler->onClientDepart(id, minute, banana, schweppes);
#endif

    if (resources.schweppes < client.schweppes)
    {
        resources.schweppes = 0;
    }
    else
    {
        this->resources.schweppes -= client.schweppes;
    }

    if (resources.bananas < client.banana)
    {
        resources.bananas = 0;
    }
    else
    {
        this->resources.bananas -= client.banana;
    }


    while(!clientsGoing.empty() && clientsGoing.front()->isDeparted){
            clientsGoing.pop_front();
    }

    while(!clientsComing.empty() && clientsComing.front()->isDeparted) {
            clientsComing.pop_front();
    }
}

Store *createStore() {
    return new MyStore();
}

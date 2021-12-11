#include <iostream>
#include <algorithm>
#include <stdexcept>
#include "../Headers/MyStore.h"

static int clientGoingMinute(const Client& client){
    return client.arriveMinute + client.maxWaitTime;
}

static void sendWorkers(MyStore& store, const int& workersForBanana, const int& workersForSchweppes, const int& minute){
    for (int i = 0; i < workersForBanana; ++i) {
        store.sendWorker(minute, ResourceType::banana);
    }

    for (int i = 0; i < workersForSchweppes; ++i) {
        store.sendWorker(minute, ResourceType::schweppes);
    }
}

/*Predicate for sorting*/
static bool PComp(const ClientWrapper * const & a, const ClientWrapper * const & b)
{
    return *a < *b;
}

MyStore::MyStore() : resources({0, 0}),
clientsCount(0), workersCount(0), actionHandler(nullptr) {};

void MyStore::setActionHandler(ActionHandler *handler) {
    if (!handler)
        return;

    actionHandler = handler;
}

void MyStore::init(int workerCount, int startBanana, int startSchweppes) {
    if (startBanana < 0 || startSchweppes < 0) {
        throw std::invalid_argument("Amount cannot be negative!");
    }

    this->resources = {startBanana, startSchweppes};
    this->workersCount = workerCount;
}

void MyStore::addClients(const Client *client, int count) {
    ClientWrapper* tempWrapper = nullptr;

    if (!client) {
        return;
    }

    clientsCount = count;

    for (int i = 0; i < count; ++i) {
        tempWrapper = new ClientWrapper(client[i], i);
        clientsComing.push_back(tempWrapper);
        allClients.push_back(tempWrapper);
    }

    topToBottomMergeSort(allClients, 0, allClients.size() - 1, PComp);

    for (int i = 0; i < count; ++i) {
        clientsGoing.push_back(allClients[i]);
    }
}

void MyStore::advanceTo(int minute) {
    Resource tempRes = {0,0};
    ClientWrapper* temp;
    int availableWorkers = workersCount;
    int expectedBananas = 0;
    int expectedSchweppes = 0;
    int sendWorkersCount[2] = {0};

    if (clientsComing.empty()){
        return;
    }

    unsigned i = 0;
    while(!clientsComing.empty() || !clientsGoing.empty())
    {
        i = std::min((int)(!workersSend.empty() ? workersSend.front().returnTime : INT32_MAX),
             std::min((!clientsGoing.empty() ? clientGoingMinute(*clientsGoing.front()) : INT32_MAX),
                      (!clientsComing.empty() ? clientsComing.front()->arriveMinute : INT32_MAX)));

        if (i > minute)
            break;

        /*Send workers*/
        if (!clientsComing.empty() && clientsComing.front()->arriveMinute == i)
        {
            temp = clientsComing.front();
            if (getBanana() >= temp->banana && getSchweppes() >= temp->schweppes)
            {
                /*There is resource for this client -> remove it*/
                clientDepart(*temp, i,temp->banana, temp->schweppes);
            }
            else
            {
                while(availableWorkers > 0)
                {
                    if ((getBanana() + expectedBananas >= temp->banana) && (getSchweppes() + expectedSchweppes >= temp->schweppes)){
                        break;
                    }

                    if ((getBanana() + expectedBananas < temp->banana) && availableWorkers > 0)
                    {
                        if ((temp->banana - (getBanana() + expectedBananas)) > (temp->schweppes - (getSchweppes() + expectedSchweppes)))
                        {
                            sendWorkersCount[0]++;
                            expectedBananas += WORKER_RETURN_QUANTITY;
                            availableWorkers--;
                        }
                    }

                    if ((getSchweppes() + expectedSchweppes < temp->schweppes) && availableWorkers > 0)
                    {
                        if ((temp->schweppes - (getSchweppes() + expectedSchweppes)) > (temp->banana - (getBanana() + expectedBananas)))
                        {
                            sendWorkersCount[1]++;
                            expectedSchweppes += WORKER_RETURN_QUANTITY;
                            availableWorkers--;
                        }
                    }
                }

                /*Send banana workers first*/
                sendWorkers(*this, sendWorkersCount[0], sendWorkersCount[1], i);
                memset(sendWorkersCount,0,sizeof(sendWorkersCount));

                /*Add to wait list and remove from coming*/
                clientsWaitlist.push_back(clientsComing.front());
                clientsComing.pop_front();
            }
        }

        /*Retrieve workers*/
        if (!workersSend.empty() && workersSend.front().returnTime == i)
        {
            while(!workersSend.empty() && workersSend.front().returnTime == i)
            {
                if (workersSend.front().resourceType == ResourceType::banana)
                {
                    expectedBananas -= WORKER_RETURN_QUANTITY;
                }
                else
                {
                    expectedSchweppes -= WORKER_RETURN_QUANTITY;
                }

                retrieveWorker();
                availableWorkers++;
            }

            /*Wait list check*/
            for (int j = 0; j < clientsWaitlist.size(); ++j)
            {
                temp = clientsWaitlist[j];
                if (getBanana() >= temp->banana && getSchweppes() >= temp->schweppes)
                {
                    clientDepart(*temp, i,temp->banana, temp->schweppes);
                }
            }
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

linked_list<Worker> MyStore::getWorkers() {
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
    if (client.isDeparted)
        return;

    client.isDeparted = true;

    std::cout << client.id << " " << minute << " " << banana << " " << schweppes << std::endl;
#ifdef TESTING
    actionHandler->onClientDepart(client.id, (int)minute, banana, schweppes);
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

MyStore::~MyStore() {
    for (int i = 0; i < allClients.size(); ++i) {
        delete allClients[i];
    }
}

Store *createStore() {
    return new MyStore();
}

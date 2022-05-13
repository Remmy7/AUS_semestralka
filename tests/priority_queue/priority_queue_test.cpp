#include "priority_queue_test.h"
#include "../../structures/priority_queue/heap.h"
#include "../../structures/priority_queue/priority_queue_limited_sorted_array_list.h"
#include "../../structures/priority_queue/priority_queue_linked_list.h"
#include "../../structures/priority_queue/priority_queue_sorted_array_list.h"
#include "../../structures/priority_queue/priority_queue_two_lists.h"
#include "../../structures/priority_queue/priority_queue_unsorted_array_list.h"

namespace tests
{
    PriorityQueueTestInterface::PriorityQueueTestInterface() :
        SimpleTest("Interface")
    {
    }

    void PriorityQueueTestInterface::test()
    {
        int x = 0;
        structures::PriorityQueue<int>* queue = this->makePriorityQueue();
        structures::PriorityQueue<int>* queue2 = this->makePriorityQueue();
        queue->push(0, x);
        queue->peek();
        queue->peekPriority();
        queue->pop();
        queue->assign(*queue);

        queue->assign(*queue2);

        for (int i = 0; i < 100; i++) {
            queue->push(i, x);
        }
        
        //TODO TESTS

        delete queue;
        delete queue2;
        this->logPass("Compiled.");

        
    }

    structures::PriorityQueue<int>* PriorityQueueUnsortedArrayListTestInterface::makePriorityQueue()
    {
        return new structures::PriorityQueueUnsortedArrayList<int>();
    }

    structures::PriorityQueue<int>* PriorityQueueSortedArrayListTestInterface::makePriorityQueue()
    {
        return new structures::PriorityQueueSortedArrayList<int>();
    }

    structures::PriorityQueue<int>* PriorityQueueLimitedSortedArrayListTestInterface::makePriorityQueue()
    {
        return new structures::PriorityQueueLimitedSortedArrayList<int>();
    }

    structures::PriorityQueue<int>* PriorityQueueLinkedListTestInterface::makePriorityQueue()
    {
        return new structures::PriorityQueueLinkedList<int>();
    }

    structures::PriorityQueue<int>* PriorityQueueTwoListsTestInterface::makePriorityQueue()
    {
        return new structures::PriorityQueueTwoLists<int>();
    }

    structures::PriorityQueue<int>* HeapTestInterface::makePriorityQueue()
    {
        return new structures::Heap<int>();
    }

    PriorityQueueUnsortedArrayListTestOverall::PriorityQueueUnsortedArrayListTestOverall() :
        ComplexTest("PriorityQueueUnsortedArray")
    {
        addTest(new PriorityQueueUnsortedArrayListTestInterface());
    }

    PriorityQueueSortedArrayListTestOverall::PriorityQueueSortedArrayListTestOverall() :
        ComplexTest("PriorityQueueSortedArrayList")
    {
        addTest(new PriorityQueueSortedArrayListTestInterface());
    }

    PriorityQueueLimitedSortedArrayListTestOverall::PriorityQueueLimitedSortedArrayListTestOverall() :
        ComplexTest("PriorityQueueLimitedSortedArrayList")
    {
        addTest(new PriorityQueueLimitedSortedArrayListTestInterface());
    }

    PriorityQueueLinkedListTestOverall::PriorityQueueLinkedListTestOverall() :
        ComplexTest("PriorityQueueLinkedList")
    {
        addTest(new PriorityQueueLinkedListTestInterface());
    }

    PriorityQueueTwoListsTestOverall::PriorityQueueTwoListsTestOverall() :
        ComplexTest("PriorityQueueTwoLists")
    {
        addTest(new PriorityQueueTwoListsTestInterface());
    }

    HeapTestOverall::HeapTestOverall() :
        ComplexTest("Heap")
    {
        addTest(new HeapTestInterface());
    }

    PriorityQueueTestOverall::PriorityQueueTestOverall() :
        ComplexTest("PriorityQueue")
    {
        addTest(new PriorityQueueUnsortedArrayListTestOverall());
        addTest(new PriorityQueueSortedArrayListTestOverall());
        addTest(new PriorityQueueLimitedSortedArrayListTestOverall());
        addTest(new PriorityQueueLinkedListTestOverall());
        addTest(new PriorityQueueTwoListsTestOverall());
        addTest(new HeapTestOverall());
    }
    void ScenarioTest::scenarioTest(int type, int scenario, std::string filePath)
    {
        structures::FileLogConsumer* fileLogConsumer = new structures::FileLogConsumer(filePath);
        int operationCount = 100000;
        int push  = 0;
        int pop    = 0;
        int peek   = 0;
        std::string queueType = "";

        if (type == 1) {
            queueType = "Heap";
        }
        else if (type == 2) {
            queueType = "PriorityQueueTwoLists";
        }
        else {
            SimpleTest::logInfo("Wrong type.");
            return;
        }
        structures::PriorityQueue<int>* queueTest = this->makeQueueType(type);
        switch (scenario) {
        case 1:
            push = 35;
            pop = 35;
            peek = 30;
            break;
        case 2:
            push = 50;
            pop = 30;
            peek = 20;
            break;
        case 3:
            push = 70;
            pop = 25;
            peek = 5;
            break;
        default:
            SimpleTest::logInfo("Wrong scenario.");
            return;
        }

        int pushCount = (operationCount / 100) * push;
        int popCount = (operationCount / 100) * pop;
        int peekCount = (operationCount / 100) * peek;

        DurationType pushTime = tests::DurationType::zero();
        DurationType popTime = tests::DurationType::zero();
        DurationType peekTime = tests::DurationType::zero();

        srand(time(NULL));

        SimpleTest::logInfo(queueType + " scenario: " + std::to_string(scenario));
        SimpleTest::logInfo("Push [%]:	" + std::to_string(push));
        SimpleTest::logInfo("Pop [%]:	" + std::to_string(pop));
        SimpleTest::logInfo("Peek [%]:		" + std::to_string(peek));

        fileLogConsumer->log(queueType + " ;scenario: " + std::to_string(scenario));
        fileLogConsumer->log("Push [%]:;	" + std::to_string(push));
        fileLogConsumer->log("Pop [%]:;	" + std::to_string(pop));
        fileLogConsumer->log("Peek [%]:;		" + std::to_string(peek));
        fileLogConsumer->log("�as[ms];typ_oper�cie");

        for (int replication = 1; replication <= operationCount; replication++) {
            int randChance = rand() % 100;
            if (randChance < push && pushCount != 0) {
                pushCount--;
                int randNumber = (rand() * rand()) % 100000;
                int randPriority = (rand() * rand()) % 100000;
                SimpleTest::startStopwatch();
                queueTest->push(randPriority, randNumber);
                SimpleTest::stopStopwatch();
                pushTime += SimpleTest::getElapsedTime();
                fileLogConsumer->log(std::to_string(SimpleTest::getElapsedTime().count()) + ";push");
            }
            else if (randChance < push + pop && popCount != 0) {
                if (queueTest->size() == 0) {
                    int randNumber = (rand() * rand()) % 100000;
                    int randPriority = (rand() * rand()) % 100000;
                    queueTest->push(randPriority, randNumber);
                }
                popCount--;
                SimpleTest::startStopwatch();
                queueTest->pop();
                SimpleTest::stopStopwatch();
                popTime += SimpleTest::getElapsedTime();
                fileLogConsumer->log(std::to_string(SimpleTest::getElapsedTime().count()) + ";pop");                           
            }
            else if (randChance < push + pop + peek && peekCount != 0) {
                if (queueTest->size() == 0) {
                    int randNumber = (rand() * rand()) % 100000;
                    int randPriority = (rand() * rand()) % 100000;
                    queueTest->push(randPriority, randNumber);
                }
                peekCount--;
                SimpleTest::startStopwatch();
                queueTest->peek();
                SimpleTest::stopStopwatch();
                peekTime += SimpleTest::getElapsedTime();
                fileLogConsumer->log(std::to_string(SimpleTest::getElapsedTime().count()) + ";peek");
                /*if (queueTest->size() == 1) {
                    queueTest->pop();
                }*/
                            
            }         
        }
        fileLogConsumer->log("----------------------------------");
        fileLogConsumer->log("----------------------------------");
        fileLogConsumer->log("Dokopy �as push: ;" + std::to_string(pushTime.count()) + ";mikrosek�nd");
        fileLogConsumer->log("Dokopy �as pop: ;" + std::to_string(popTime.count()) + ";mikrosek�nd");
        fileLogConsumer->log("Dokopy �as peek: ;" + std::to_string(peekTime.count()) + " ;mikrosek�nd");
        fileLogConsumer->log("Priemern� �as push: ;" + std::to_string(pushTime.count() / ((operationCount / 100) * push)) + ";mikrosek�nd");
        fileLogConsumer->log("Priemern� �as pop: ;" + std::to_string(popTime.count() / ((operationCount / 100) * pop)) + ";mikrosek�nd");
        fileLogConsumer->log("Priemern� �as peek: ;" + std::to_string(peekTime.count() / ((operationCount / 100) * peek)) + " ;mikrosek�nd");
        fileLogConsumer->log("Celkov� �as: ;" + std::to_string(pushTime.count() + popTime.count() + peekTime.count()));
        fileLogConsumer->log("----------------------------------");
        delete queueTest;
        delete fileLogConsumer;
    }
    ScenarioTest::ScenarioTest(std::string name) :
        SimpleTest(std::move(name))
    {
    }
    structures::PriorityQueue<int>* ScenarioTest::makeQueueType(int type)
    {
        if (type == 1) {
            return new structures::Heap<int>();
        }
        return new structures::PriorityQueueTwoLists<int>();     
    }


    PriorityQueueScenarios::PriorityQueueScenarios() 
        : ComplexTest("PriorityQueueScenarios")
    {
        addTest(new HeapScenarios());
        addTest(new PriorityQueueTwoListScenarios());
        addTest(new TimeComplexityScenarios());

        addTest(new PriorityQueueTwoListsTestOverall());
        addTest(new HeapTestOverall());
    }


    HeapScenarios::HeapScenarios() 
        : ComplexTest("HeapScenarios")
    {
        addTest(new HeapScenarioA());
        addTest(new HeapScenarioB());
        addTest(new HeapScenarioC());
    }
    HeapScenarioA::HeapScenarioA()
        : ScenarioTest("HeapScenarioA")
    {
    }
    void HeapScenarioA::test()
    {
        scenarioTest(1, 1, "zadanie3_uloha2/Heap_scenarioA.csv");
        SimpleTest::assertTrue(1 == 1, "End of scenario Heap A.");
    }
    HeapScenarioB::HeapScenarioB()
        : ScenarioTest("HeapScenarioB")
    {
    }
    void HeapScenarioB::test()
    {
        scenarioTest(1, 2, "zadanie3_uloha2/Heap_scenarioB.csv");
        SimpleTest::assertTrue(1 == 1, "End of scenario Heap B.");
    }
    HeapScenarioC::HeapScenarioC()
        : ScenarioTest("HeapScenarioC")
    {
    }
    void HeapScenarioC::test()
    {
        scenarioTest(1, 3, "zadanie3_uloha2/Heap_scenarioC.csv");
        SimpleTest::assertTrue(1 == 1, "End of scenario Heap C.");
    }


    PriorityQueueTwoListScenarios::PriorityQueueTwoListScenarios()
        : ComplexTest("PriorityQueueTwoListsScenarios")
    {
        addTest(new PriorityQueueTwoListsScenarioA());
        addTest(new PriorityQueueTwoListsScenarioB());
        addTest(new PriorityQueueTwoListsScenarioC());
    }
    PriorityQueueTwoListsScenarioA::PriorityQueueTwoListsScenarioA()
        : ScenarioTest("PriorityQueueTwoListsScenarioA")
    {
    }
    void PriorityQueueTwoListsScenarioA::test()
    {
        scenarioTest(2, 1, "zadanie3_uloha2/PriorityQueueTwoLists_scenarioA.csv");
        SimpleTest::assertTrue(1 == 1, "End of scenario PriorityQueueTwoListsScenario A.");
    }
    PriorityQueueTwoListsScenarioB::PriorityQueueTwoListsScenarioB()
        : ScenarioTest("PriorityQueueTwoListsScenarioB")
    {
    }
    void PriorityQueueTwoListsScenarioB::test()
    {
        scenarioTest(2, 2, "zadanie3_uloha2/PriorityQueueTwoLists_scenarioB.csv");
        SimpleTest::assertTrue(1 == 1, "End of scenario PriorityQueueTwoListsScenario B.");
    }
    PriorityQueueTwoListsScenarioC::PriorityQueueTwoListsScenarioC()
        : ScenarioTest("PriorityQueueTwoListsScenarioC")
    {
    }
    void PriorityQueueTwoListsScenarioC::test()
    {
        scenarioTest(2, 3, "zadanie3_uloha2/PriorityQueueTwoLists_scenarioC.csv");
        SimpleTest::assertTrue(1 == 1, "End of scenario PriorityQueueTwoListsScenario C.");
    }


    ///�loha 3
   
    /// <summary>
    /// Spolo�n� funkcia pre v�etky testy anal�z �asov�ch zlo�itost�.
    /// </summary>
    /// <param name="type">Typ priorityqueue, 1=heap 2=PQTL</param>
    /// <param name="operation">Oper�cia na vykonanie 1=push 2=pop 3=peek</param>
    /// <param name="filePath">Miesto ulo�enia s�boru</param>
    void TimeComplexityTests::complexityTest(int type, int operation, std::string filePath)
    {
        structures::FileLogConsumer* fileLogConsumer = new structures::FileLogConsumer(filePath);
        int maxCount = 100000;
        int currentSize = 0;
        int increaseSizeBy = 100;
        int operationCount = 100;
        std::string queueType = "";
        if (type == 1) {
            queueType = "Heap";
        }
        else if (type == 2) {
            queueType = "PriorityQueueTwoLists";
        }
        else {
            SimpleTest::logInfo("Wrong type.");
            return;
        }
        //structures::PriorityQueue<int>* queueTest = this->makeQueueType(type);
        structures::PriorityQueue<int>* queueTest;
        srand(time(NULL));
        DurationType pushTime = tests::DurationType::zero();
        DurationType popTime = tests::DurationType::zero();
        DurationType peekTime = tests::DurationType::zero();
       
        SimpleTest::logInfo(queueType + " operation: " + std::to_string(operation));
        fileLogConsumer->log(queueType + " ;operation: " + std::to_string(operation));
        fileLogConsumer->log("po�et prvkov;�as[ms]");

        for (int i = 0; i < 10; i++) {
            currentSize = 0;
            structures::PriorityQueue<int>* queueTest = this->makeQueueType(type);
            if (operation == 1) {
                while (currentSize < maxCount) {
                    currentSize += increaseSizeBy;
                    for (int i = 0; i < increaseSizeBy; i++) {
                        int randNumber = (rand() * rand()) % 100000;
                        int randPriority = (rand() * rand()) % 100000;
                        queueTest->push(randPriority, randNumber);
                    }
                    for (int i = 0; i < operationCount; i++) {
                        int randNumber = (rand() * rand()) % 100000;
                        int randPriority = (rand() * rand()) % 100000;
                        SimpleTest::startStopwatch();
                        queueTest->push(randPriority, randNumber);
                        SimpleTest::stopStopwatch();
                        pushTime += SimpleTest::getElapsedTime();
                        queueTest->pop();
                    }
                    fileLogConsumer->log(std::to_string(currentSize) + ";" + std::to_string(pushTime.count()));
                    pushTime = tests::DurationType::zero();                   
                }
            }
            else if (operation == 2) {
                while (currentSize < maxCount) {
                    currentSize += increaseSizeBy;
                    for (int i = 0; i < increaseSizeBy; i++) {
                        int randNumber = (rand() * rand()) % 100000;
                        int randPriority = (rand() * rand()) % 100000;
                        queueTest->push(randPriority, randNumber);
                    }
                    for (int i = 0; i < operationCount; i++) {
                        SimpleTest::startStopwatch();
                        queueTest->pop();
                        SimpleTest::stopStopwatch();
                        popTime += SimpleTest::getElapsedTime();                       
                        int randNumber = (rand() * rand()) % 100000;
                        int randPriority = (rand() * rand()) % 100000;
                        queueTest->push(randPriority, randNumber);
                    }
                    fileLogConsumer->log(std::to_string(currentSize) + ";" + std::to_string(popTime.count()));
                    popTime = tests::DurationType::zero();                
                }
            }
            else if (operation == 3) {
                while (currentSize < maxCount) {
                    currentSize += increaseSizeBy;
                    for (int i = 0; i < increaseSizeBy; i++) {
                        int randNumber = (rand() * rand()) % 100000;
                        int randPriority = (rand() * rand()) % 100000;
                        queueTest->push(randPriority, randNumber);
                    }
                    for (int i = 0; i < operationCount; i++) {
                        SimpleTest::startStopwatch();
                        queueTest->peek();
                        SimpleTest::stopStopwatch();
                        peekTime += SimpleTest::getElapsedTime();
                    }
                    fileLogConsumer->log(std::to_string(currentSize) + ";" + std::to_string(peekTime.count()));
                    peekTime = tests::DurationType::zero();
                }
            }
            else {
                logInfo("Wrong operation type");
            }
            queueTest->clear();
            delete queueTest;
        }
        fileLogConsumer->log("----------------------------------");
        fileLogConsumer->log("----------------------------------");
        if (operation == 1) {
            fileLogConsumer->log("Priemern� �as push: ;" + std::to_string(pushTime.count() / ((currentSize / increaseSizeBy) * 10)) + ";mikrosek�nd");
        }
        else if (operation == 2) {
            fileLogConsumer->log("Priemern� �as pop: ;" + std::to_string(popTime.count() / ((currentSize / increaseSizeBy) *10 )) + ";mikrosek�nd");
        }
        else {
            fileLogConsumer->log("Priemern� �as peek: ;" + std::to_string(peekTime.count() / ((currentSize / increaseSizeBy) * 10)) + " ;mikrosek�nd");
        }
        fileLogConsumer->log("Celkov� �as: ;" + std::to_string(pushTime.count() + popTime.count() + peekTime.count()));
        
        delete fileLogConsumer;
        //delete queueTest;
    }

    TimeComplexityTests::TimeComplexityTests(std::string name) :
        SimpleTest(std::move(name))
    {
    }

    structures::PriorityQueue<int>* TimeComplexityTests::makeQueueType(int type)
    {
        if (type == 1) {
            return new structures::Heap<int>();
        }
        return new structures::PriorityQueueTwoLists<int>();
    }

    TimeComplexityScenarios::TimeComplexityScenarios() :
        ComplexTest("TimeComplexityScenarios")
    {
        addTest(new TimeComplexityScenariosHeap());
        addTest(new TimeComplexityScenariosPriorityQueueTwoList());
    }

    TimeComplexityScenariosHeap::TimeComplexityScenariosHeap() :
        ComplexTest("Heap")
    {
        addTest(new HeapPushComplexity());
        addTest(new HeapPopComplexity());
        addTest(new HeapPeekComplexity());
    }

    HeapPushComplexity::HeapPushComplexity() :
        TimeComplexityTests("HeapPush")
    {
    }

    void HeapPushComplexity::test()
    {
        complexityTest(1, 1, "zadanie3_uloha3/Heap_push.csv");
        SimpleTest::assertTrue(1 == 1, "End of time complexity heap push.");
    }

    HeapPopComplexity::HeapPopComplexity() :
        TimeComplexityTests("HeapPop")
    {
    }

    void HeapPopComplexity::test()
    {
        complexityTest(1, 2, "zadanie3_uloha3/Heap_pop.csv");
        SimpleTest::assertTrue(1 == 1, "End of time complexity heap pop.");
    }

    HeapPeekComplexity::HeapPeekComplexity() :
        TimeComplexityTests("HeapPeek")
    {
    }

    void HeapPeekComplexity::test()
    {
        complexityTest(1, 3, "zadanie3_uloha3/Heap_peek.csv");
        SimpleTest::assertTrue(1 == 1, "End of time complexity heap peek.");
    }
    ////////
    ////////
    ////////

    TimeComplexityScenariosPriorityQueueTwoList::TimeComplexityScenariosPriorityQueueTwoList() :
        ComplexTest("PriorityQueueTwoList")
    {
        addTest(new PriorityQueueTwoListPushComplexity());
        addTest(new PriorityQueueTwoListPopComplexity());
        addTest(new PriorityQueueTwoListPeekComplexity());
    }

    PriorityQueueTwoListPushComplexity::PriorityQueueTwoListPushComplexity() :
        TimeComplexityTests("PriorityQueueTwoListPush")
    {
    }

    void PriorityQueueTwoListPushComplexity::test()
    {
        complexityTest(2, 1, "zadanie3_uloha3/PriorityQueueTwoList_push.csv");
        SimpleTest::assertTrue(1 == 1, "End of time complexity PriorityQueueTwoList push.");
    }

    PriorityQueueTwoListPopComplexity::PriorityQueueTwoListPopComplexity() :
        TimeComplexityTests("PriorityQueueTwoListPop")
    {
    }

    void PriorityQueueTwoListPopComplexity::test()
    {
        complexityTest(2, 2, "zadanie3_uloha3/PriorityQueueTwoList_pop.csv");
        SimpleTest::assertTrue(1 == 1, "End of time complexity PriorityQueueTwoList pop.");
    }

    PriorityQueueTwoListPeekComplexity::PriorityQueueTwoListPeekComplexity() :
        TimeComplexityTests("PriorityQueueTwoListPeek")
    {
    }

    void PriorityQueueTwoListPeekComplexity::test()
    {
        complexityTest(2, 3, "zadanie3_uloha3/PriorityQueueTwoList_peek.csv");
        SimpleTest::assertTrue(1 == 1, "End of time complexity PriorityQueueTwoList peek.");
    }

}
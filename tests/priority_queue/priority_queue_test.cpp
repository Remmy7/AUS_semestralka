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
        queue->push(0, x);
        queue->peek();
        queue->peekPriority();
        queue->pop();
        queue->assign(*queue);
        delete queue;
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
        int insert = 0;
        int removeAt = 0;
        int at = 0;
        int getIndexOf = 0;
        std::string listType = "";

        if (type == 1) {
            listType = "Heap";
        }
        else if (type == 2) {
            listType = "PriorityQueueTwoLists";
        }
        else {
            SimpleTest::logInfo("Wrong type.");
            return;
        }
        structures::PriorityQueue<int>* list = this->makeQueueType(type);

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
        SimpleTest::assertTrue(1 == 1, "End of scenario Heap A.");
    }
    HeapScenarioB::HeapScenarioB()
        : ScenarioTest("HeapScenarioB")
    {
    }
    void HeapScenarioB::test()
    {
        SimpleTest::assertTrue(1 == 1, "End of scenario Heap B.");
    }
    HeapScenarioC::HeapScenarioC()
        : ScenarioTest("HeapScenarioC")
    {
    }
    void HeapScenarioC::test()
    {
        SimpleTest::assertTrue(1 == 1, "End of scenario Heap C.");
    }


    PriorityQueueTwoListScenarios::PriorityQueueTwoListScenarios()
        : ComplexTest("PriorityQueueScenarios")
    {
        addTest(new PriorityQueueTwoListsScenarioA());
        addTest(new PriorityQueueTwoListsScenarioB());
        addTest(new PriorityQueueTwoListsScenarioC());
    }
    PriorityQueueTwoListsScenarioA::PriorityQueueTwoListsScenarioA()
        : ScenarioTest("PriorityQueueScenarioA")
    {
    }
    void PriorityQueueTwoListsScenarioA::test()
    {
        SimpleTest::assertTrue(1 == 1, "End of scenario PriorityQueueTwoListsScenario A.");
    }
    PriorityQueueTwoListsScenarioB::PriorityQueueTwoListsScenarioB()
        : ScenarioTest("PriorityQueueScenarioA")
    {
    }
    void PriorityQueueTwoListsScenarioB::test()
    {
        SimpleTest::assertTrue(1 == 1, "End of scenario PriorityQueueTwoListsScenario B.");
    }
    PriorityQueueTwoListsScenarioC::PriorityQueueTwoListsScenarioC()
        : ScenarioTest("PriorityQueueScenarioA")
    {
    }
    void PriorityQueueTwoListsScenarioC::test()
    {
        SimpleTest::assertTrue(1 == 1, "End of scenario PriorityQueueTwoListsScenario C.");
    }
}
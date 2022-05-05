#pragma once

#include "../test.h"
#include "../../structures/priority_queue/priority_queue.h"
#include "../../structures/priority_queue/priority_queue_list.h"
#include "../../structures/_logger/file_log_consumer.h"


namespace tests
{
    /// <summary>
    /// Zavola vsetky metody z rozhrania prioritneho frontu avsak nekontroluje ich spravnost.
    /// Zabezpeci, ze vsetky metody budu prelozene kompilatorom.
    /// </summary>
    class PriorityQueueTestInterface
        : public SimpleTest
    {
    public:
        PriorityQueueTestInterface();
        void test() override;

    protected:
        virtual structures::PriorityQueue<int>* makePriorityQueue() = 0;
    };

    /// <summary>
    /// Zavola vsetky metody prioritneho frontu.
    /// </summary>
    class PriorityQueueUnsortedArrayListTestInterface
        : public PriorityQueueTestInterface
    {
    protected:
        structures::PriorityQueue<int>* makePriorityQueue() override;
    };

    /// <summary>
    /// Zavola vsetky metody prioritneho frontu.
    /// </summary>
    class PriorityQueueSortedArrayListTestInterface
        : public PriorityQueueTestInterface
    {
    protected:
        structures::PriorityQueue<int>* makePriorityQueue() override;
    };

    /// <summary>
    /// Zavola vsetky metody prioritneho frontu.
    /// </summary>
    class PriorityQueueLimitedSortedArrayListTestInterface
        : public PriorityQueueTestInterface
    {
    protected:
        structures::PriorityQueue<int>* makePriorityQueue() override;
    };

    /// <summary>
    /// Zavola vsetky metody prioritneho frontu.
    /// </summary>
    class PriorityQueueLinkedListTestInterface
        : public PriorityQueueTestInterface
    {
    protected:
        structures::PriorityQueue<int>* makePriorityQueue() override;
    };

    /// <summary>
    /// Zavola vsetky metody prioritneho frontu.
    /// </summary>
    class PriorityQueueTwoListsTestInterface
        : public PriorityQueueTestInterface
    {
    protected:
        structures::PriorityQueue<int>* makePriorityQueue() override;
    };

    /// <summary>
    /// Zavola vsetky metody prioritneho frontu.
    /// </summary>
    class HeapTestInterface
        : public PriorityQueueTestInterface
    {
    protected:
        structures::PriorityQueue<int>* makePriorityQueue() override;
    };

    /// <summary>
    /// Zahrna v sebe vsetky testy, ktore testuju dany prioritny front.
    /// </summary>
    class PriorityQueueUnsortedArrayListTestOverall
        : public ComplexTest
    {
    public:
        PriorityQueueUnsortedArrayListTestOverall();
    };

    /// <summary>
    /// Zahrna v sebe vsetky testy, ktore testuju dany prioritny front.
    /// </summary>
    class PriorityQueueSortedArrayListTestOverall
        : public ComplexTest
    {
    public:
        PriorityQueueSortedArrayListTestOverall();
    };

    /// <summary>
    /// Zahrna v sebe vsetky testy, ktore testuju dany prioritny front.
    /// </summary>
    class PriorityQueueLimitedSortedArrayListTestOverall
        : public ComplexTest
    {
    public:
        PriorityQueueLimitedSortedArrayListTestOverall();
    };

    /// <summary>
    /// Zahrna v sebe vsetky testy, ktore testuju dany prioritny front.
    /// </summary>
    class PriorityQueueLinkedListTestOverall
        : public ComplexTest
    {
    public:
        PriorityQueueLinkedListTestOverall();
    };

    /// <summary>
    /// Zahrna v sebe vsetky testy, ktore testuju dany prioritny front.
    /// </summary>
    class PriorityQueueTwoListsTestOverall
        : public ComplexTest
    {
    public:
        PriorityQueueTwoListsTestOverall();
    };

    /// <summary>
    /// Zahrna v sebe vsetky testy, ktore testuju dany prioritny front.
    /// </summary>
    class HeapTestOverall
        : public ComplexTest
    {
    public:
        HeapTestOverall();
    };

    /// <summary>
    /// Zahrna v sebe vsetky testy, ktore testuju prioritny front.
    /// </summary>
    class PriorityQueueTestOverall
        : public ComplexTest
    {
    public:
        PriorityQueueTestOverall();
    };

    ///////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    
    /// <summary>
    /// Spoloèná testovacia metóda pre scenáre.
    /// </summary>
    class ScenarioTest
        : public SimpleTest
    {
    public:
        void scenarioTest(int type, int scenario, std::string filePath);
        ScenarioTest(std::string name);
    protected:
        virtual structures::PriorityQueue<int>* makeQueueType(int type);
    };

    class PriorityQueueScenarios
        : public ComplexTest
    {
    public:
        PriorityQueueScenarios();
    };

    /// <summary>
    /// Heap scenáre.
    /// </summary>

    class HeapScenarios
        : public ComplexTest
    {
    public:
        HeapScenarios();
    };

    class HeapScenarioA
        : public ScenarioTest
    {
    public:
        HeapScenarioA();
        void test() override;
    };
    class HeapScenarioB
        : public ScenarioTest
    {
    public:
        HeapScenarioB();
        void test() override;
    };
    class HeapScenarioC
        : public ScenarioTest
    {
    public:
        HeapScenarioC();
        void test() override;
    };

    /// <summary>
    /// PriorityQueueTwoList scenáre.
    /// </summary>
    class PriorityQueueTwoListScenarios
        : public ComplexTest
    {
    public:
        PriorityQueueTwoListScenarios();
    };

    class PriorityQueueTwoListsScenarioA
        : public ScenarioTest
    {
    public:
        PriorityQueueTwoListsScenarioA();
        void test() override;
    };
    class PriorityQueueTwoListsScenarioB
        : public ScenarioTest
    {
    public:
        PriorityQueueTwoListsScenarioB();
        void test() override;
    };
    class PriorityQueueTwoListsScenarioC
        : public ScenarioTest
    {
    public:
        PriorityQueueTwoListsScenarioC();
        void test() override;
    };

    /// Úloha 3
    class TimeComplexityTests
        : public SimpleTest
    {
    public:
        void complexityTest(int type, int operation);
        TimeComplexityTests(std::string name);
    protected:
        virtual structures::PriorityQueue<int>* makeQueueType(int type);
    };

    class TimeComplexityScenarios
        : public ComplexTest
    {
    public:
        TimeComplexityScenarios();
    };

    /// <summary>
    /// Testy pre Heap.
    /// </summary>
    class TimeComplexityScenariosHeap
        : public ComplexTest
    {
    public:
        TimeComplexityScenariosHeap();
    };

    class HeapPushComplexity
        : public TimeComplexityTests
    {
    public:
        HeapPushComplexity();
        void test() override;
    };
    class HeapPopComplexity
        : public TimeComplexityTests
    {
    public:
        HeapPopComplexity();
        void test() override;
    };
    class HeapPeekComplexity
        : public TimeComplexityTests
    {
    public:
        HeapPeekComplexity();
        void test() override;
    };




    /// <summary>
    /// Testy pre PriorityQueueTwoList.
    /// </summary>
    class TimeComplexityScenariosPriorityQueueTwoList
        : public ComplexTest
    {
    public:
        TimeComplexityScenariosPriorityQueueTwoList();
    };

    class PriorityQueueTwoListPushComplexity
        : public TimeComplexityTests
    {
    public:
        PriorityQueueTwoListPushComplexity();
        void test() override;
    };
    class PriorityQueueTwoListPopComplexity
        : public TimeComplexityTests
    {
    public:
        PriorityQueueTwoListPopComplexity();
        void test() override;
    };
    class PriorityQueueTwoListPeekComplexity
        : public TimeComplexityTests
    {
    public:
        PriorityQueueTwoListPeekComplexity();
        void test() override;
    };

}
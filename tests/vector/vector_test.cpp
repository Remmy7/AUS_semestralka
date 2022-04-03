#include "vector_test.h"
#include "../../structures/vector/vector.h"

namespace tests
{
    // VectorTestInterface:

    VectorTestInterface::VectorTestInterface() :
        SimpleTest("Interface")
    {
    }

    void VectorTestInterface::test()
    {
        structures::Vector* vector = new structures::Vector(10);
        vector->size();
        vector->assign(*vector);
        vector->equals(*vector);
        vector->at(0);
        vector->getBytePointer(0);
        //structures::Vector::copy(*vector, 0, *vector, 0, 1);
        delete vector;
        SimpleTest::logPass("Compiled.");
    }

    // VectorTestAt:

    VectorTestAt::VectorTestAt() :
        SimpleTest("Vector test at")
    {
    }

    void VectorTestAt::test()
    {
        SimpleTest::startStopwatch();

        structures::Vector* testVector = new structures::Vector(10);

        SimpleTest::assertTrue(testVector->size() == 10, "Vector::size()");

        for (int i = 0; i < 10; i++) {
            testVector->at(i) = i;
        }

        for (int i = 0; i < 10; i++) {
            SimpleTest::assertTrue(testVector->at(i) == i, "Vector::at(" + std::to_string(i) + ")");
            SimpleTest::assertTrue(*(testVector->getBytePointer(i)) == i, "Vector::getBytePointer(" + std::to_string(i) + ")");
        }

        delete testVector;

        SimpleTest::stopStopwatch();
        structures::Logger::getInstance().logDuration(0, SimpleTest::getElapsedTime(), "Vector test at duration");
    }


    // VectorTestOverall:

    VectorTestOverall::VectorTestOverall() :
        ComplexTest("Vector")
    {
        addTest(new VectorTestInterface());
        addTest(new VectorTestAt());
    }
}
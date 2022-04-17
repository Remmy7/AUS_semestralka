#include "list_test.h"

namespace tests
{
// ListTestInterface:

	ListTestInterface::ListTestInterface(std::string name) :
		SimpleTest(std::move(name))
	{
	}

	void ListTestInterface::test()
	{
		int x = 0;
		structures::List<int>* list = this->makeList();
		list->add(x);
		list->assign(*list);
		list->clear();
		delete list->getBeginIterator();
		delete list->getEndIterator();
		list->getIndexOf(x);
		list->insert(x, x);
		list->isEmpty();
		list->operator[](0);
		list->removeAt(0);
		list->size();
		list->tryRemove(x);
		delete list;
		this->logPass("Compiled.");
	}





// ArrayListTestInterface:

	ArrayListTestInterface::ArrayListTestInterface() :
		ListTestInterface("Interface")
	{
	}

	structures::List<int>* ArrayListTestInterface::makeList() const
	{
		return new structures::ArrayList<int>();
	}

// LinkedListTestInterface:

	LinkedListTestInterface::LinkedListTestInterface() :
		ListTestInterface("Interface")
	{
	}

	structures::List<int>* LinkedListTestInterface::makeList() const
	{
		return new structures::LinkedList<int>();
	}

// ArrayListTestOverall:

	ArrayListTestOverall::ArrayListTestOverall() :
		ComplexTest("ArrayList")
	{
		addTest(new ArrayListTestInterface());
	}

// LinkedListTestOverall:

	LinkedListTestOverall::LinkedListTestOverall() :
		ComplexTest("LinkedList")
	{
		addTest(new LinkedListTestInterface());
	}

// ListTestOverall:

	ListTestOverall::ListTestOverall() :
		ComplexTest("List")
	{
		addTest(new ArrayListTestOverall());
		addTest(new LinkedListTestOverall());
	}

// Unit test list:

	/// <summary>
	/// Hlavný test pre všetky scenáriá.
	/// </summary>
	/// <param name="type"> Typ, 1==arrayList, 2==doubleLinkedList </param>
	/// <param name="scenario"> Scenáriá zo zadania. </param>
	void UnitTest::scenarioTest(int type, int scenario)
	{
		int insert = 0;
		int removeAt = 0;
		int at = 0;
		int getIndexOf = 0;
		if (type > 0 || type < 2) {
			SimpleTest::logInfo("Wrong type.");
			return;
		}
		structures::List<int>* list = this->makeListType(type);
		switch (scenario) {
		case 1:
			insert = 20;
			removeAt = 20;
			at = 50;
			getIndexOf = 10;
			break;
		case 2:
			insert = 35;
			removeAt = 35;
			at = 20;
			getIndexOf = 10;
			break;
		case 3:
			insert = 45;
			removeAt = 45;
			at = 5;
			getIndexOf = 5;
			break;
		default:
			SimpleTest::logInfo("Wrong scenario.");
			return;
		}
			
		
		SimpleTest::assertTrue(type == scenario, "xdasdfawefasd");
		delete list;
	}

	UnitTest::UnitTest(std::string name) :
		SimpleTest(std::move(name))
	{
	}

	structures::List<int>* UnitTest::makeListType(int type)
	{
		if (type == 1) {
			return new structures::ArrayList<int>();
		}
		/*else {
			return new structures::DoubleLinkedList<int>();
		}*/
	}

	void ArrayListUnitTest::test()
	{
		scenarioTest(1, 1);
	}

	ArrayListUnitTest::ArrayListUnitTest() :
		UnitTest("ArrayListUnitTest")
	{

	}

	

	ArrayListScenarios::ArrayListScenarios() :
		ComplexTest("ArrayListScenarios")
	{
		addTest(new ArrayListUnitTest());
	}

	LinkedListScenarios::LinkedListScenarios() :
		ComplexTest("LinkedListScenarios")
	{
	}

	// Unit test linkedlist:
}
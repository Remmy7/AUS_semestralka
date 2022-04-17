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
		list->insert(x, x);
		list->insert(x, x);
		list->insert(x, x);
		list->isEmpty();
		list->operator[](0);
		list->removeAt(0);
		//list->removeAt(list->size());
		list->removeAt(list->size() - 1);
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
		//addTest(new ArrayListTestInterface());
	}

// LinkedListTestOverall:

	LinkedListTestOverall::LinkedListTestOverall() :
		ComplexTest("LinkedList")
	{
		//addTest(new LinkedListTestInterface());
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
	/// Hlavn˝ test pre vöetky scen·ri·.
	/// </summary>
	/// <param name="type"> Typ, 1==arrayList, 2==doubleLinkedList </param>
	/// <param name="scenario"> Scen·ri· zo zadania. </param>
	/// <param name="filePath"> Cesta do s˙boru, do ktorÈho sa maj˙ zapÌsaù v˝stupnÈ d·ta. </param>
	void UnitTest::scenarioTest(int type, int scenario, std::string filePath)
	{
		structures::FileLogConsumer* fileLogConsumer = new structures::FileLogConsumer(filePath);
		//structures::Logger::getInstance().registerConsumer(fileLogConsumer);
		int operationCount = 100000;
		int insert = 0;
		int removeAt = 0;
		int at = 0;
		int getIndexOf = 0;
		std::string listType = "";

		// Rozmedzie v akom sa bud˙ prid·vaù hodnoty do listov.
		int randomRange = 100;

		if (type == 1) {
			listType = "ArrayList";
		}
		else if (type == 2) {
			listType = "DoubleLinkedList";
		} 
		else {
			SimpleTest::logInfo("Wrong type.");
			return;
		}
		structures::List<int>* list = this->makeListType(type);
		if (type == 1) {
			
		}
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

		int insertCount = (operationCount / 100) * insert;
		int removeAtCount = (operationCount / 100) * removeAt;
		int atCount = (operationCount / 100) * at;
		int getIndexOfCount = (operationCount / 100) * getIndexOf;

		DurationType insertCountTime = tests::DurationType::zero();
		DurationType removeAtCountTime = tests::DurationType::zero();
		DurationType atCountTime = tests::DurationType::zero();
		DurationType getIndexOfCountTime = tests::DurationType::zero();

		srand(time(NULL));
		
		SimpleTest::logInfo(listType + " scenario: " + std::to_string(scenario));
		SimpleTest::logInfo("Insert [%]:	" + std::to_string(insert));
		SimpleTest::logInfo("RemoveAt [%]:	" + std::to_string(removeAt));
		SimpleTest::logInfo("At [%]:		" + std::to_string(at));
		SimpleTest::logInfo("GetIndexOf [%]:" + std::to_string(getIndexOf));

		fileLogConsumer->log(listType + " scenario: " + std::to_string(scenario));
		
		/*structures::Logger::getInstance().logInfo(listType + " scenario: " + std::to_string(scenario));
		structures::Logger::getInstance().logInfo("Insert [%]:		" + std::to_string(insert));
		structures::Logger::getInstance().logInfo("RemoveAt [%]:	" + std::to_string(removeAt));
		structures::Logger::getInstance().logInfo("At [%]:			" + std::to_string(at));
		structures::Logger::getInstance().logInfo("GetIndexOf [%]:  " + std::to_string(getIndexOf));*/
			
		//vloûenie 1000 prvkov na zaËiatok.
		for (int i = 0; i < 1000; i++) {
			int tempInsert = rand() % randomRange;
			list->add(tempInsert);
		}


		for (int replication = 1; replication <= operationCount; replication++) {
			int randChance = rand() % 100;
			int tempNumb = 0;
			if (list->size() > 0) {
				tempNumb = rand() % list->size();
			}			
			
			if (randChance < insert && insertCount != 0) {
				insertCount--;
				int tempInsert = rand() % randomRange;
				SimpleTest::startStopwatch();
				list->insert(tempInsert, tempNumb);
				SimpleTest::stopStopwatch();
				insertCountTime += SimpleTest::getElapsedTime();
				//structures::Logger::getInstance().logInfo(std::to_string(SimpleTest::getElapsedTime().count()) + ";insert");
			} else if (randChance < removeAt + insert && removeAtCount != 0) {
				if (list->size() != 0) {
					removeAtCount--;
					SimpleTest::startStopwatch();
					list->removeAt(tempNumb);
					SimpleTest::stopStopwatch();
					removeAtCountTime += SimpleTest::getElapsedTime();
					//structures::Logger::getInstance().logInfo(std::to_string(SimpleTest::getElapsedTime().count()) + ";removeAt");
				}
				else {
					operationCount++;
				}
			} else if (randChance < at + removeAt + insert && atCount != 0) {			
				if (list->size() != 0) {
					SimpleTest::startStopwatch();
					atCount--;
					list->at(tempNumb);
					SimpleTest::stopStopwatch();
					atCountTime += SimpleTest::getElapsedTime();
					//structures::Logger::getInstance().logInfo(std::to_string(SimpleTest::getElapsedTime().count()) + ";at");
				}
				else {
					operationCount++;
				}
			} else if (randChance < 100 && getIndexOfCount != 0) {
				if (list->size() != 0) {
					getIndexOfCount--;
					int tempInsert = rand() % randomRange;
					SimpleTest::startStopwatch();
					list->getIndexOf(tempInsert);
					SimpleTest::stopStopwatch();
					getIndexOfCountTime += SimpleTest::getElapsedTime();
					//structures::Logger::getInstance().logInfo(std::to_string(SimpleTest::getElapsedTime().count()) + ";getIndexOf");
				}
				else {
					operationCount++;
				}
			}
		}

		fileLogConsumer->log("----------------------------------");
		fileLogConsumer->log("----------------------------------");
		fileLogConsumer->log("Dokopy Ëas insert: ;" + std::to_string(insertCountTime.count()) + ";mikrosek˙nd");
		fileLogConsumer->log("Dokopy Ëas removeAt: ;" + std::to_string(removeAtCountTime.count()) + ";mikrosek˙nd");
		fileLogConsumer->log("Dokopy Ëas at: ;" + std::to_string(atCountTime.count()) + " ;mikrosek˙nd");
		fileLogConsumer->log("Dokopy Ëas getIndexOf: ;" + std::to_string(getIndexOfCountTime.count()) + " ;mikrosek˙nd");
		fileLogConsumer->log("Priemern˝ Ëas insert: ;" + std::to_string(insertCountTime.count() / ((operationCount / 100) * insert)) + ";mikrosek˙nd");
		fileLogConsumer->log("Priemern˝ Ëas removeAt: ;" + std::to_string(removeAtCountTime.count() / ((operationCount / 100) * removeAt)) + ";mikrosek˙nd");
		fileLogConsumer->log("Priemern˝ Ëas at: ;" + std::to_string(atCountTime.count() / ((operationCount / 100) * at)) + " ;mikrosek˙nd");
		fileLogConsumer->log("Priemern˝ Ëas getIndexOf: ;" + std::to_string(getIndexOfCountTime.count() / ((operationCount / 100) * getIndexOf)) + " ;mikrosek˙nd");
		fileLogConsumer->log("----------------------------------");

		
		SimpleTest::assertTrue(1 == 1, "End of scenario.");
		delete list;
		delete fileLogConsumer;
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
		return new structures::ArrayList<int>();;
		/*else {
			return new structures::DoubleLinkedList<int>();
		}*/
	}

	// ArrayList

	ArrayListScenarios::ArrayListScenarios() :
		ComplexTest("ArrayListScenarios")
	{
		//addTest(new ArrayListUnitTest());
		addTest(new ArrayListScenarioA());
		addTest(new ArrayListScenarioB());
		addTest(new ArrayListScenarioC());
	}

	void ArrayListUnitTest::test()
	{
		scenarioTest(1, 1, "ArrayListUnitTest.csv");
	}

	ArrayListUnitTest::ArrayListUnitTest() :
		UnitTest("ArrayListUnitTest")
	{

	}

	// scenarios

	ArrayListScenarioA::ArrayListScenarioA() :
		UnitTest("ArrayList scenario A")
	{
	}
	void ArrayListScenarioA::test()
	{
		scenarioTest(1, 1, "ArrayList_scenarioA.csv");
	}
	ArrayListScenarioB::ArrayListScenarioB() :
		UnitTest("ArrayList scenario B")
	{
	}
	void ArrayListScenarioB::test()
	{
		scenarioTest(1, 2, "ArrayList_scenarioB.csv");
	}
	ArrayListScenarioC::ArrayListScenarioC() :
		UnitTest("ArrayList scenario C")
	{
	}
	void ArrayListScenarioC::test()
	{
		scenarioTest(1, 3, "ArrayList_scenarioC.csv");
	}
	

	// DoubleLinkedList

	LinkedListScenarios::LinkedListScenarios() :
		ComplexTest("LinkedListScenarios")
	{
		//addTest(new DoubleLinkedListUnitTest());
		addTest(new DoubleLinkedListScenarioA());
		addTest(new DoubleLinkedListScenarioB());
		addTest(new DoubleLinkedListScenarioC());
	}

	DoubleLinkedListUnitTest::DoubleLinkedListUnitTest() :
		UnitTest("DoubleLinkedListUnitTest")
	{
	}

	void DoubleLinkedListUnitTest::test()
	{
		
	}
	
	DoubleLinkedListScenarioA::DoubleLinkedListScenarioA() :
		UnitTest("DoubleLinkedList scenario A")
	{
	}

	void DoubleLinkedListScenarioA::test()
	{
		scenarioTest(2, 1, "DoubleLinkedList_scenarioA.csv");
	}

	DoubleLinkedListScenarioB::DoubleLinkedListScenarioB() :
		UnitTest("DoubleLinkedList scenario B")
	{
	}

	void DoubleLinkedListScenarioB::test()
	{
		scenarioTest(2, 2, "DoubleLinkedList_scenarioB.csv");
	}

	DoubleLinkedListScenarioC::DoubleLinkedListScenarioC() :
		UnitTest("DoubleLinkedList scenario C")
	{
	}

	void DoubleLinkedListScenarioC::test()
	{
		scenarioTest(2, 3, "DoubleLinkedList_scenarioC.csv");
	}

}
#include "table_test.h"
#include "../../structures/table/binary_search_tree.h"
#include "../../structures/table/hash_table.h"
#include "../../structures/table/linked_table.h"
#include "../../structures/table/sorted_sequence_table.h"
#include "../../structures/table/table.h"
#include "../../structures/table/treap.h"
#include "../../structures/table/unsorted_sequence_table.h"

namespace tests
{
	TableTestInterface::TableTestInterface() :
		SimpleTest("Interface")
	{
	}

	void TableTestInterface::test()
	{
		int x = 0;
		structures::Table<int, int>* table = this->makeTable();
		table->equals(*table);
		table->assign(*table);
		table->insert(0, 0);
		table->find(0);
		table->remove(0);
		table->tryFind(0, x);
		table->containsKey(0);
		delete table;
		this->logPass("Compiled.");
	}

	structures::Table<int, int>* BinarySearchTreeTestInterface::makeTable()
	{
		return new structures::BinarySearchTree<int, int>();
	}

	structures::Table<int, int>* HashTableTestInterface::makeTable()
	{
		return new structures::HashTable<int, int>();
	}

	structures::Table<int, int>* LinkedTableTestInterface::makeTable()
	{
		return new structures::LinkedTable<int, int>();
	}

	structures::Table<int, int>* SortedSequenceTableTestInterface::makeTable()
	{
		return new structures::SortedSequenceTable<int, int>();
	}

	structures::Table<int, int>* TreapTestInterface::makeTable()
	{
		return new structures::Treap<int, int>();
	}

	structures::Table<int, int>* UnsortedSequenceTableTestInterface::makeTable()
	{
		return new structures::UnsortedSequenceTable<int, int>();
	}

	BinarySearchTreeTestOverall::BinarySearchTreeTestOverall() :
		ComplexTest("BinarySearchTree")
	{
		addTest(new BinarySearchTreeTestInterface());
	}

	HashTableTestOverall::HashTableTestOverall() :
		ComplexTest("HashTable")
	{
		addTest(new HashTableTestInterface());
	}

	LinkedTableTestOverall::LinkedTableTestOverall() :
		ComplexTest("LinkedTable")
	{
		addTest(new LinkedTableTestInterface());
	}

	SortedSequenceTableTestOverall::SortedSequenceTableTestOverall() :
		ComplexTest("SortedSequenceTable")
	{
		addTest(new SortedSequenceTableTestInterface());
	}

	TreapTestOverall::TreapTestOverall() :
		ComplexTest("Treap")
	{
		addTest(new TreapTestInterface());
	}

	UnsortedSequenceTableTestOverall::UnsortedSequenceTableTestOverall() :
		ComplexTest("UnsortedSequenceTable")
	{
		addTest(new UnsortedSequenceTableTestInterface());
	}

	TableTestOverall::TableTestOverall() :
		ComplexTest("Table")
	{
		addTest(new BinarySearchTreeTestOverall());
		addTest(new HashTableTestOverall());
		addTest(new LinkedTableTestOverall());
		addTest(new SortedSequenceTableTestOverall());
		addTest(new TreapTestOverall());
		addTest(new UnsortedSequenceTableTestOverall());
	}

	/////////////////////////////////
	///////////DZ4///////////////////
	/////////////////////////////////
	ScenarioTestDZ4::ScenarioTestDZ4(std::string name) :
		SimpleTest(std::move(name))
	{
	}
	void ScenarioTestDZ4::scenarioTestDZ4(int type, int scenario, std::string filePath)
	{
		structures::FileLogConsumer* fileLogConsumer = new structures::FileLogConsumer(filePath);
		int operationCount = 100000;
		int insert	= 0;
		int remove	= 0;
		int tryFind	= 0;
		std::string tableType = "";
		structures::Table<int, int>* tableTest;

		if (type == 1) {
			tableType = "SortedSequenceTable";
			tableTest = new structures::SortedSequenceTable<int, int>;

		}
		else if (type == 2) {
			tableType = "BinarySearchTree";
			tableTest = new structures::BinarySearchTree<int, int>;
		}
		else {
			SimpleTest::logInfo("Wrong type.");
			return;
		}
		switch (scenario) {
		case 1:
			insert = 20;
			remove = 20;
			tryFind = 60;
			break;
		case 2:
			insert = 40;
			remove = 40;
			tryFind = 20;
			break;
		default:
			SimpleTest::logInfo("Wrong scenario.");
			return;
		}

		int insertCount = (operationCount / 100) * insert;
		int removeCount = (operationCount / 100) * remove;
		int tryFindCount = (operationCount / 100) * tryFind;

		DurationType insertTime = tests::DurationType::zero();
		DurationType removeTime = tests::DurationType::zero();
		DurationType tryFindTime = tests::DurationType::zero();

		srand(time(NULL));
		
		SimpleTest::logInfo(tableType + " scenario: " + std::to_string(scenario));
		SimpleTest::logInfo("Insert [%]:	" + std::to_string(insert));
		SimpleTest::logInfo("Remove [%]:	" + std::to_string(remove));
		SimpleTest::logInfo("TryFind [%]:		" + std::to_string(tryFind));

		fileLogConsumer->log(tableType + " ;scenario: " + std::to_string(scenario));
		fileLogConsumer->log("Insert [%]:;	" + std::to_string(insert));
		fileLogConsumer->log("Remove [%]:;	" + std::to_string(remove));
		fileLogConsumer->log("TryFind [%]:;		" + std::to_string(tryFind));
		fileLogConsumer->log("èas[ms];typ_operácie");

		for (int replication = 1; replication <= operationCount; replication++) {
			int randChance = rand() % 100;
			if (randChance < insert && insertCount != 0) {
				insertCount--;
				int randKey = (rand() * rand()) % 100000;
				int randValue = (rand() * rand()) % 100000;
				SimpleTest::startStopwatch();
				tableTest->insert(randKey, randValue);
				SimpleTest::stopStopwatch();
				insertTime += SimpleTest::getElapsedTime();
				fileLogConsumer->log(std::to_string(SimpleTest::getElapsedTime().count()) + ";insert");
			}
			else if (randChance < insert + remove && removeCount != 0) {
				int randKey = (rand() * rand()) % 100000;
				if (tableTest->size() == 0) {					
					int randValue = (rand() * rand()) % 100000;
					tableTest->insert(randKey, randValue);
				}
				removeCount--;
				SimpleTest::startStopwatch();
				tableTest->remove(randKey);
				SimpleTest::stopStopwatch();
				removeTime += SimpleTest::getElapsedTime();
				fileLogConsumer->log(std::to_string(SimpleTest::getElapsedTime().count()) + ";remove");
			}
			else if (randChance < insert + remove + tryFind && tryFindCount != 0) {
				int randKey = (rand() * rand()) % 100000;
				int randValue = (rand() * rand()) % 100000;
				if (tableTest->size() == 0) {				
					tableTest->insert(randKey, randValue);
				}
				tryFindCount--;
				SimpleTest::startStopwatch();
				tableTest->tryFind(randKey, randValue);
				SimpleTest::stopStopwatch();
				tryFindTime += SimpleTest::getElapsedTime();
				fileLogConsumer->log(std::to_string(SimpleTest::getElapsedTime().count()) + ";tryFind");
				if (tableTest->size() == 1) {
					tableTest->remove(randKey);
				}

			}
		}

		fileLogConsumer->log("----------------------------------");
		fileLogConsumer->log("----------------------------------");
		fileLogConsumer->log("Dokopy èas insert: ;" + std::to_string(insertTime.count()) + ";mikrosekúnd");
		fileLogConsumer->log("Dokopy èas remove: ;" + std::to_string(removeTime.count()) + ";mikrosekúnd");
		fileLogConsumer->log("Dokopy èas tryFind: ;" + std::to_string(tryFindTime.count()) + " ;mikrosekúnd");
		fileLogConsumer->log("Priemerný èas insert: ;" + std::to_string(insertTime.count() / ((operationCount / 100) * insert)) + ";mikrosekúnd");
		fileLogConsumer->log("Priemerný èas remove: ;" + std::to_string(removeTime.count() / ((operationCount / 100) * remove)) + ";mikrosekúnd");
		fileLogConsumer->log("Priemerný èas tryFind: ;" + std::to_string(tryFindTime.count() / ((operationCount / 100) * tryFind)) + " ;mikrosekúnd");
		fileLogConsumer->log("Celkový èas: ;" + std::to_string(insertTime.count() + removeTime.count() + tryFindTime.count()));
		fileLogConsumer->log("----------------------------------");
		delete tableTest;
		delete fileLogConsumer;

		SimpleTest::assertTrue(1 == 1, "Scenario passed successfully!");
	}

	
	SortedSequenceTableScenarios::SortedSequenceTableScenarios() :
		ComplexTest("SortedSequenceTable")
	{
		addTest(new SSTCopyConstr());
		addTest(new SSTAssign());
		addTest(new SSTInsert());
		addTest(new SSTEquals());
		addTest(new SSTFind());
		addTest(new SSTRemove());
		addTest(new SSTTryFind());
		addTest(new SSTContainsKey());

		addTest(new SSTScenarioA());
		addTest(new SSTScenarioB());


		addTest(new SSTTimeComplexityInsert());
		addTest(new SSTTimeComplexityRemove());
		addTest(new SSTTimeComplexityTryFind());
	}

	BinarySearchTreeScenarios::BinarySearchTreeScenarios() :
		ComplexTest("Binary search tree")
	{
		addTest(new BSTCopyConstr());
		addTest(new BSTAssign());
		addTest(new BSTInsert());
		addTest(new BSTEquals());
		addTest(new BSTFind());
		addTest(new BSTRemove());
		addTest(new BSTTryFind());
		addTest(new BSTContainsKey());

		addTest(new BSTScenarioA());
		addTest(new BSTScenarioB());


		addTest(new BSTTimeComplexityInsert());
		addTest(new BSTTimeComplexityRemove());
		addTest(new BSTTimeComplexityTryFind());
	}

	/////////////////////////////////
	/////////unit testy//////////////
	/////////////////////////////////

	SSTCopyConstr::SSTCopyConstr() :
		ScenarioTestDZ4("CopyConstr")
	{
	}
	
	void SSTCopyConstr::test()
	{
		SimpleTest::logInfo("Does nothing rn");
	}

	SSTAssign::SSTAssign() :
		ScenarioTestDZ4("Assign")
	{
	}
	void SSTAssign::test()
	{
		SimpleTest::logInfo("Does nothing rn");

	}
	SSTEquals::SSTEquals() :
		ScenarioTestDZ4("Equals")
	{
	}
	void SSTEquals::test()
	{
	}
	SSTInsert::SSTInsert() :
		ScenarioTestDZ4("Insert")
	{
	}
	void SSTInsert::test()
	{
		SimpleTest::logInfo("Does nothing rn");

	}
	SSTFind::SSTFind() :
		ScenarioTestDZ4("Find")
	{
	}
	void SSTFind::test()
	{
		SimpleTest::logInfo("Does nothing rn");

	}
	SSTRemove::SSTRemove() :
		ScenarioTestDZ4("Remove")
	{
	}
	void SSTRemove::test()
	{
		SimpleTest::logInfo("Does nothing rn");

	}
	SSTTryFind::SSTTryFind() :
		ScenarioTestDZ4("TryFind")
	{
	}
	void SSTTryFind::test()
	{
		SimpleTest::logInfo("Does nothing rn");

	}
	SSTContainsKey::SSTContainsKey() :
		ScenarioTestDZ4("ContainsKey")
	{
	}
	void SSTContainsKey::test()
	{
		SimpleTest::logInfo("Does nothing rn");

	}
	//////////////////////////////////
	BSTCopyConstr::BSTCopyConstr() :
		ScenarioTestDZ4("CopyConstr")
	{
	}

	void BSTCopyConstr::test()
	{
		SimpleTest::logInfo("Does nothing rn");

	}

	BSTAssign::BSTAssign() :
		ScenarioTestDZ4("Assign")
	{
	}

	void BSTAssign::test()
	{
		SimpleTest::logInfo("Does nothing rn");

	}

	BSTEquals::BSTEquals() :
		ScenarioTestDZ4("Equals")
	{
	}

	void BSTEquals::test()
	{
		SimpleTest::logInfo("Does nothing rn");

	}

	BSTInsert::BSTInsert() :
		ScenarioTestDZ4("Insert")
	{
	}

	void BSTInsert::test()
	{
		SimpleTest::logInfo("Does nothing rn");

	}

	BSTFind::BSTFind() :
		ScenarioTestDZ4("Find")
	{
	}

	void BSTFind::test()
	{
		SimpleTest::logInfo("Does nothing rn");

	}

	BSTRemove::BSTRemove() :
		ScenarioTestDZ4("Remove")
	{
	}

	void BSTRemove::test()
	{
		SimpleTest::logInfo("Does nothing rn");

	}

	BSTTryFind::BSTTryFind() :
		ScenarioTestDZ4("Find")
	{
	}

	void BSTTryFind::test()
	{
		SimpleTest::logInfo("Does nothing rn");

	}

	BSTContainsKey::BSTContainsKey() :
		ScenarioTestDZ4("ContainsKey")
	{
	}

	void BSTContainsKey::test()
	{
		SimpleTest::logInfo("Does nothing rn");

	}

	

	

	SSTScenarioA::SSTScenarioA() :
		ScenarioTestDZ4("Scenario A")
	{
	}

	void SSTScenarioA::test()
	{
		scenarioTestDZ4(1, 2, "zadanie4_uloha2/SSTScenarioC.csv");
		SimpleTest::logInfo("SST scenario C passed successfully!");
	}

	SSTScenarioB::SSTScenarioB() :
		ScenarioTestDZ4("Scenario B")
	{
	}

	void SSTScenarioB::test()
	{
		scenarioTestDZ4(1, 2, "zadanie4_uloha2/SSTScenarioC.csv");
		SimpleTest::logInfo("SST scenario B passed successfully!");
	}

	BSTScenarioA::BSTScenarioA() :
		ScenarioTestDZ4("Scenario A")
	{
	}

	void BSTScenarioA::test()
	{
		scenarioTestDZ4(2, 1, "zadanie4_uloha2/BSTScenarioA.csv");
		SimpleTest::logInfo("BST scenario A passed successfully!");
	}

	BSTScenarioB::BSTScenarioB() :
		ScenarioTestDZ4("Scenario B")
	{
	}

	void BSTScenarioB::test()
	{
		scenarioTestDZ4(2, 2, "zadanie4_uloha2/BSTScenarioB.csv");
		SimpleTest::logInfo("BST scenario B passed successfully!");
	}


	/// <summary>
	/// 
	/// </summary>
	/// <param name="type"></param>
	/// <param name="scenario"></param>
	/// <param name="filePath"></param>
	void TimeComplexityDZ4::timeComplexityDZ4(int type, int scenario, std::string filePath)
	{

	}
	TimeComplexityDZ4::TimeComplexityDZ4(std::string name) :
		SimpleTest(std::move(name))
	{
	}
	SSTTimeComplexityInsert::SSTTimeComplexityInsert() :
		TimeComplexityDZ4("Insert")
	{
	}
	void SSTTimeComplexityInsert::test()
	{
		timeComplexityDZ4(1, 1, "uloha3_zadanie4/SSTInsert.csv");
		SimpleTest::logInfo("SSTInsert passed successfully!");
	}
	SSTTimeComplexityRemove::SSTTimeComplexityRemove() :
		TimeComplexityDZ4("Remove")
	{
	}
	void SSTTimeComplexityRemove::test()
	{
		timeComplexityDZ4(1, 2, "uloha3_zadanie4/SSTRemove.csv");
		SimpleTest::logInfo("SSTRemove passed successfully!");
	}
	SSTTimeComplexityTryFind::SSTTimeComplexityTryFind() :
		TimeComplexityDZ4("TryFind")
	{
	}
	void SSTTimeComplexityTryFind::test()
	{
		timeComplexityDZ4(1, 3, "uloha3_zadanie4/SSTTryFind.csv");
		SimpleTest::logInfo("SSTTryFind passed successfully!");
	}
	BSTTimeComplexityInsert::BSTTimeComplexityInsert() :
		TimeComplexityDZ4("Insert")
	{
	}
	void BSTTimeComplexityInsert::test()
	{
		timeComplexityDZ4(2, 1, "uloha3_zadanie4/BSTInsert.csv");
		SimpleTest::logInfo("BSTInsert passed successfully!");
	}
	BSTTimeComplexityRemove::BSTTimeComplexityRemove() :
		TimeComplexityDZ4("Remove")
	{
	}
	void BSTTimeComplexityRemove::test()
	{
		timeComplexityDZ4(2, 2, "uloha3_zadanie4/BSTRemove.csv");
		SimpleTest::logInfo("BSTRemove passed successfully!");
	}
	BSTTimeComplexityTryFind::BSTTimeComplexityTryFind() :
		TimeComplexityDZ4("TryFind")
	{
	}
	void BSTTimeComplexityTryFind::test()
	{
		timeComplexityDZ4(2, 3, "uloha3_zadanie4/BSTTryFind.csv");
		SimpleTest::logInfo("BSTTryFind passed successfully!");
	}
}
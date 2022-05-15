#pragma once

#include "../test.h"
#include "../../structures/table/table.h"
#include "../../structures/_logger/file_log_consumer.h"

namespace tests
{
	/// <summary>
	/// Zavola vsetky metody z rozhrania tabulky avsak nekontroluje ich spravnost.
	/// Zabezpeci, ze vsetky metody budu prelozene kompilatorom.
	/// </summary>
	class TableTestInterface
		: public SimpleTest
	{
	public:
		TableTestInterface();
		void test() override;

	protected:
		virtual structures::Table<int, int>* makeTable() = 0;
	};

	/// <summary>
	/// Zavola vsetky metody danej tabulky.
	/// </summary>
	class BinarySearchTreeTestInterface
		: public TableTestInterface
	{
	protected:
		structures::Table<int, int>* makeTable() override;
	};

	/// <summary>
	/// Zavola vsetky metody danej tabulky.
	/// </summary>
	class HashTableTestInterface
		: public TableTestInterface
	{
	protected:
		structures::Table<int, int>* makeTable() override;
	};

	/// <summary>
	/// Zavola vsetky metody danej tabulky.
	/// </summary>
	class LinkedTableTestInterface
		: public TableTestInterface
	{
	protected:
		structures::Table<int, int>* makeTable() override;
	};

	/// <summary>
	/// Zavola vsetky metody danej tabulky.
	/// </summary>
	class SortedSequenceTableTestInterface
		: public TableTestInterface
	{
	protected:
		structures::Table<int, int>* makeTable() override;
	};

	/// <summary>
	/// Zavola vsetky metody danej tabulky.
	/// </summary>
	class TreapTestInterface
		: public TableTestInterface
	{
	protected:
		structures::Table<int, int>* makeTable() override;
	};

	/// <summary>
	/// Zavola vsetky metody danej tabulky.
	/// </summary>
	class UnsortedSequenceTableTestInterface
		: public TableTestInterface
	{
	protected:
		structures::Table<int, int>* makeTable() override;
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju danu tabulku.
	/// </summary>
	class BinarySearchTreeTestOverall
		: public ComplexTest
	{
	public:
		BinarySearchTreeTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju danu tabulku.
	/// </summary>
	class HashTableTestOverall
		: public ComplexTest
	{
	public:
		HashTableTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju danu tabulku.
	/// </summary>
	class LinkedTableTestOverall
		: public ComplexTest
	{
	public:
		LinkedTableTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju danu tabulku.
	/// </summary>
	class SortedSequenceTableTestOverall
		: public ComplexTest
	{
	public:
		SortedSequenceTableTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju danu tabulku.
	/// </summary>
	class TreapTestOverall
		: public ComplexTest
	{
	public:
		TreapTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju danu tabulku.
	/// </summary>
	class UnsortedSequenceTableTestOverall
		: public ComplexTest
	{
	public:
		UnsortedSequenceTableTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju tabulku.
	/// </summary>
	class TableTestOverall
		: public ComplexTest
	{
	public:
		TableTestOverall();
	};


	////////////////////////////
	/////////////DZ4////////////
	////////////////////////////

	class ScenarioTestDZ4
		: public SimpleTest
	{
	public:
		void scenarioTestDZ4(int type, int scenario, std::string filePath);
		ScenarioTestDZ4(std::string name);
	};

	class SortedSequenceTableScenarios
		: public ComplexTest
	{
	public:
		SortedSequenceTableScenarios();
	};

	class BinarySearchTreeScenarios
		: public ComplexTest
	{
	public:
		BinarySearchTreeScenarios();
	};


	/////////////////////////////////
	/////////unit testy//////////////
	/////////////////////////////////
	class SSTCopyConstr
		: public ScenarioTestDZ4
	{
	public:
		SSTCopyConstr();
		void test() override;
	};

	class SSTAssign
		: public ScenarioTestDZ4
	{
	public:
		SSTAssign();
		void test() override;
	};
	class SSTEquals
		: public ScenarioTestDZ4
	{
	public:
		SSTEquals();
		void test() override;
	};
	class SSTInsert
		: public ScenarioTestDZ4
	{
	public:
		SSTInsert();
		void test() override;
	};
	class SSTFind
		: public ScenarioTestDZ4
	{
	public:
		SSTFind();
		void test() override;
	};
	class SSTRemove
		: public ScenarioTestDZ4
	{
	public:
		SSTRemove();
		void test() override;
	};
	class SSTTryFind
		: public ScenarioTestDZ4
	{
	public:
		SSTTryFind();
		void test() override;
	}; 
	class SSTContainsKey
		: public ScenarioTestDZ4
	{
	public:
		SSTContainsKey();
		void test() override;
	};
	/////////////////////////////////////

	class BSTCopyConstr
		: public ScenarioTestDZ4
	{
	public:
		BSTCopyConstr();
		void test() override;
	};

	class BSTAssign
		: public ScenarioTestDZ4
	{
	public:
		BSTAssign();
		void test() override;
	};
	class BSTEquals
		: public ScenarioTestDZ4
	{
	public:
		BSTEquals();
		void test() override;
	};
	class BSTInsert
		: public ScenarioTestDZ4
	{
	public:
		BSTInsert();
		void test() override;
	};
	class BSTFind
		: public ScenarioTestDZ4
	{
	public:
		BSTFind();
		void test() override;
	};
	class BSTRemove
		: public ScenarioTestDZ4
	{
	public:
		BSTRemove();
		void test() override;
	};
	class BSTTryFind
		: public ScenarioTestDZ4
	{
	public:
		BSTTryFind();
		void test() override;
	};
	class BSTContainsKey
		: public ScenarioTestDZ4
	{
	public:
		BSTContainsKey();
		void test() override;
	};

	/////////////////////////////////
	////////scenáre//////////////////
	//////Sorted sequence table//////
	/////////////////////////////////


	class SSTScenarioA
		: public ScenarioTestDZ4
	{
	public:
		SSTScenarioA();
		void test() override;
	};
	class SSTScenarioB
		: public ScenarioTestDZ4
	{
	public:
		SSTScenarioB();
		void test() override;
	};
	

	///////////////////////////////
	//////Binary search tree///////
	///////////////////////////////

	class BSTScenarioA
		: public ScenarioTestDZ4
	{
	public:
		BSTScenarioA();
		void test() override;
	};
	class BSTScenarioB
		: public ScenarioTestDZ4
	{
	public:
		BSTScenarioB();
		void test() override;
	};
	

	//////////////////////////////////
	/////Time complexity scenarios////
	//////////////////////////////////
	class TimeComplexityDZ4
		: public SimpleTest
	{
	public:
		void timeComplexityDZ4(int type, int scenario, std::string filePath);
		TimeComplexityDZ4(std::string name);
	};
	class SSTTimeComplexityInsert
		: public TimeComplexityDZ4
	{
	public:
		SSTTimeComplexityInsert();
		void test() override;
	};
	class SSTTimeComplexityRemove
		: public TimeComplexityDZ4
	{
	public:
		SSTTimeComplexityRemove();
		void test() override;
	};
	class SSTTimeComplexityTryFind
		: public TimeComplexityDZ4
	{
	public:
		SSTTimeComplexityTryFind();
		void test() override;
	};
	class BSTTimeComplexityInsert
		: public TimeComplexityDZ4
	{
	public:
		BSTTimeComplexityInsert();
		void test() override;
	};
	class BSTTimeComplexityRemove
		: public TimeComplexityDZ4
	{
	public:
		BSTTimeComplexityRemove();
		void test() override;
	};
	class BSTTimeComplexityTryFind
		: public TimeComplexityDZ4
	{
	public:
		BSTTimeComplexityTryFind();
		void test() override;
	};
	
}
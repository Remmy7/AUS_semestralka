#pragma once

#include "../test.h"
#include "../../structures/table/table.h"

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

	class ScenarioTest
		: public SimpleTest
	{
	public:
		void scenarioTest(int type, int scenario, std::string filePath);
		ScenarioTest(std::string name);
	};

	class PriorityQueueScenarios
		: public ComplexTest
	{
	public:
		PriorityQueueScenarios();
	};

	////////////////////////////////
	//////Sorted sequence table/////
	////////////////////////////////

	class SortedSequenceTableScenarios
		: public ComplexTest
	{
		SortedSequenceTableScenarios();
	};
	/////////////////////////////////
	/////////unit testy//////////////
	/////////////////////////////////
	class SSTCopyConstr
		: public SimpleTest
	{
		SSTCopyConstr();
		void test() override;
	};

	class SSTAssign
		: public SimpleTest
	{
		SSTAssign();
		void test() override;
	};
	class SSTEquals
		: public SimpleTest
	{
		SSTEquals();
		void test() override;
	};
	class SSTInsert
		: public SimpleTest
	{
		SSTInsert();
		void test() override;
	};
	class SSTFindTableItem
		: public SimpleTest
	{
		SSTFindTableItem();
		void test() override;
	};
	class SSTFindTableItem
		: public SimpleTest
	{
		SSTFindTableItem();
		void test() override;
	};



	/////////////////////////////////
	////////scenáre//////////////////
	/////////////////////////////////


	class SSTScenarioA
		: public ScenarioTest
	{
	public:
		SSTScenarioA();
		void test() override;
	};
	class SSTScenarioB
		: public ScenarioTest
	{
	public:
		SSTScenarioB();
		void test() override;
	};
	class SSTScenarioC
		: public ScenarioTest
	{
	public:
		SSTScenarioC();
		void test() override;
	};

	///////////////////////////////
	//////Binary search tree///////
	///////////////////////////////

	class BinarySearchTreeScenarios
		: public ComplexTest
	{
		BinarySearchTreeScenarios();
	};

	class BSTScenarioA
		: public ScenarioTest
	{
	public:
		BSTScenarioA();
		void test() override;
	};
	class BSTScenarioB
		: public ScenarioTest
	{
	public:
		BSTScenarioB();
		void test() override;
	};
	class BSTScenarioC
		: public ScenarioTest
	{
	public:
		BSTScenarioC();
		void test() override;
	};

	//////////////////////////////////
	/////Time complexity scenarios////
	//////////////////////////////////

}
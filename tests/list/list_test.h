#pragma once

#include "../test.h"
#include "../../structures/list/array_list.h"
#include "../../structures/list/linked_list.h"
#include "../../structures/list/double_linked_list.h"

namespace tests
{
	/// <summary>
	/// Zavola vsetky metody z rozhrania listu avsak nekontroluje ich spravnost.
	/// Zabezpeci, ze vsetky metody budu prelozene kompilatorom.
	/// </summary>
	class ListTestInterface
		: public SimpleTest
	{
	public:
		ListTestInterface(std::string name);
		void test() override;

	protected:
		virtual structures::List<int>* makeList() const = 0;
	};

	
	/// <summary>
	/// Zavola vsetky metody ArrayListu.
	/// </summary>
	class ArrayListTestInterface
		: public ListTestInterface
	{
	public:
		ArrayListTestInterface();

	protected:
		structures::List<int>* makeList() const override;
	};

	/// <summary>
	/// Zavola vsetky metody LinkedListu.
	/// </summary>
	class LinkedListTestInterface
		: public ListTestInterface
	{
	public:
		LinkedListTestInterface();

	protected:
		structures::List<int>* makeList() const override;
	};

	

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju ArrayList.
	/// </summary>
	class ArrayListTestOverall
		: public ComplexTest
	{
	public:
		ArrayListTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju LinkedList.
	/// </summary>
	class LinkedListTestOverall
		: public ComplexTest
	{
	public:
		LinkedListTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju ArrayList a LinkedList.
	/// </summary>
	class ListTestOverall :
		public ComplexTest
	{
	public:
		ListTestOverall();
	};

	// Zadanie 2

	class UnitTest
		: public SimpleTest
	{
	public:
		void scenarioTest(int type, int scenario, std::string filePath);
		UnitTest(std::string name);
	protected:
		virtual structures::List<int>* makeListType(int type);
	};

	
	// ArrayList
	//////////////////////////////////////////////////////////

	class ArrayListScenarios
		: public ComplexTest
	{
	public:
		ArrayListScenarios();
	};
	

	class ArrayListUnitTest
		: public UnitTest
	{
	public:
		ArrayListUnitTest();
		void test() override;
	};

	class ArrayListScenarioA
		: public UnitTest
	{
	public:
		ArrayListScenarioA();
		void test() override;
	};
	class ArrayListScenarioB
		: public UnitTest
	{
	public:
		ArrayListScenarioB();
		void test() override;
	};
	class ArrayListScenarioC
		: public UnitTest
	{
	public:
		ArrayListScenarioC();
		void test() override;
	};

	// DoubleLinkedList
	//////////////////////////////////////////////////////////

	class LinkedListScenarios
		: public ComplexTest
	{
	public:
		LinkedListScenarios();
	};
	class DoubleLinkedListUnitTest
		: public UnitTest
	{
	public:
		DoubleLinkedListUnitTest();
		void test() override;
	};

	class DoubleLinkedListScenarioA
		: public UnitTest
	{
	public:
		DoubleLinkedListScenarioA();
		void test() override;
	};
	class DoubleLinkedListScenarioB
		: public UnitTest
	{
	public:
		DoubleLinkedListScenarioB();
		void test() override;
	};
	class DoubleLinkedListScenarioC
		: public UnitTest
	{
	public:
		DoubleLinkedListScenarioC();
		void test() override;
	};

}
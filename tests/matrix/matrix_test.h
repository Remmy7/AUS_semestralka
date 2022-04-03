#pragma once

#include "../test.h"
#include "../../structures/matrix/matrix.h"
#include "../../structures/_logger/logger.h"

namespace tests
{
	/// <summary>
	/// Zavola vsetky metody z rozhrania matice avsak nekontroluje ich spravnost.
	/// Zabezpeci, ze vsetky metody budu prelozene kompilatorom.
	/// </summary>
	class MatrixTestInterface
		: public SimpleTest
	{
	public:
		MatrixTestInterface();
		void test() override;

	protected:
		virtual structures::Matrix<int>* makeMatrix(size_t rows, size_t cols) const = 0;
	};


	/// <summary>
	/// Zavola vsetky metody koherentnej matice.
	/// </summary>
	class CoherentMatrixTestInterface
		: public MatrixTestInterface
	{
	protected:
		structures::Matrix<int>* makeMatrix(size_t rows, size_t cols) const override;
	};

	/// <summary>
	/// Zavola vsetky metody nekoherentnej matice.
	/// </summary>
	class IncoherentMatrixTestInterface
		: public MatrixTestInterface
	{
	protected:
		structures::Matrix<int>* makeMatrix(size_t rows, size_t cols) const override;
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju CoherentMatrix.
	/// </summary>
	class CoherentMatrixTestOverall
		: public ComplexTest
	{
	public:
		CoherentMatrixTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju IncoherentMatrix.
	/// </summary>
	class IncoherentMatrixTestOverall
		: public ComplexTest
	{
	public:
		IncoherentMatrixTestOverall();
	};

	/// <summary>
	/// Zahrna v sebe vsetky testy, ktore testuju CoherrentMatrix a IncoherrentMatrix.
	/// </summary>
	class MatrixTestOverall
		: public ComplexTest
	{
	public:
		MatrixTestOverall();
	
	};
	/// <summary>
	/// Testovanie pre súvislú maticu.
	/// </summary>
	class CoherentMatrixTest1
		: public SimpleTest
	{
	public:
		CoherentMatrixTest1();
		void test() override;

	
	};
	/// <summary>
	/// Testovanie pre nesúvislú maticu.
	/// </summary>
	class IncoherentMatrixTest1
		: public SimpleTest
	{
	public:
		IncoherentMatrixTest1();
		void test() override;
	};
	/// <summary>
	/// Zahàòa v sebe testy na scenáre coherent matíc.
	/// </summary>
	class CoherentMatrixTestScenarios
		: public ComplexTest
	{
	public:
		CoherentMatrixTestScenarios();
	

	};
	/// <summary>
	/// Zahàòa v sebe testy na scenáre incoherent matíc.
	/// </summary>
	class IncoherentMatrixTestScenarios
		: public ComplexTest
	{
	public:
		IncoherentMatrixTestScenarios();
	};
	

	/// <summary>
	/// Testovanie druhej úlohy v prvom zadaní pre súvislú maticu, scenár A
	/// </summary>
	class CoherentMatrixScenarA
		: public SimpleTest
	{
	public:
		CoherentMatrixScenarA();
		void test() override;
	};
	/// <summary>
	/// Testovanie druhej úlohy v prvom zadaní pre súvislú maticu, scenár B
	/// </summary>
	class CoherentMatrixScenarB
		: public SimpleTest
	{
	public:
		CoherentMatrixScenarB();
		void test() override;
	};
	/// <summary>
	/// Testovanie druhej úlohy v prvom zadaní pre súvislú maticu, scenár C
	/// </summary>
	class CoherentMatrixScenarC
		: public SimpleTest
	{
	public:
		CoherentMatrixScenarC();
		void test() override;
	};
	/// <summary>
	/// Testovanie druhej úlohy v prvom zadaní pre súvislú maticu, scenár D
	/// </summary>
	class CoherentMatrixScenarD
		: public SimpleTest
	{
	public:
		CoherentMatrixScenarD();
		void test() override;
	};


	/// <summary>
	/// Testovanie druhej úlohy v prvom zadaní pre nesúvislú maticu, scenár A
	/// </summary>
	class IncoherentMatrixScenarA
		: public SimpleTest
	{
	public:
		IncoherentMatrixScenarA();
		void test() override;
	};
	/// <summary>
	/// Testovanie druhej úlohy v prvom zadaní pre nesúvislú maticu, scenár B
	/// </summary>
	class IncoherentMatrixScenarB
		: public SimpleTest
	{
	public:
		IncoherentMatrixScenarB();
		void test() override;
	};
	/// <summary>
	/// Testovanie druhej úlohy v prvom zadaní pre nesúvislú maticu, scenár C
	/// </summary>
	class IncoherentMatrixScenarC
		: public SimpleTest
	{
	public:
		IncoherentMatrixScenarC();
		void test() override;
	};
	/// <summary>
	/// Testovanie druhej úlohy v prvom zadaní pre nesúvislú maticu, scenár D
	/// </summary>
	class IncoherentMatrixScenarD
		: public SimpleTest
	{
	public:
		IncoherentMatrixScenarD();
		void test() override;
	};
}
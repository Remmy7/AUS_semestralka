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
	/// Testovanie pre s�visl� maticu.
	/// </summary>
	class CoherentMatrixTest1
		: public SimpleTest
	{
	public:
		CoherentMatrixTest1();
		void test() override;
	};
	/// <summary>
	/// Testovanie pre nes�visl� maticu.
	/// </summary>
	class IncoherentMatrixTest1
		: public SimpleTest
	{
	public:
		IncoherentMatrixTest1();
		void test() override;
	};


	

	/// <summary>
	/// Testovanie druhej �lohy v prvom zadan� pre s�visl� maticu, scen�r A
	/// </summary>
	class CoherentMatrixScenarA
		: public SimpleTest
	{
	public:
		CoherentMatrixScenarA();
		void test() override;
	};
	/// <summary>
	/// Pomocn� funkcia, ktor� si zavol� ka�d� scen�r a vykon� �ou dan� scen�r.
	/// </summary>
	/// <param name="matrix">V�ber medzi coherent(1) a incoherent(2) maticou</param>
	/// <param name="size_row">D�ka matice</param>
	/// <param name="size_column">��rka matice</param>
	/// <param name="rowCount">Pomer oper�ci� getRowCount</param>
	/// <param name="columnCount">Pomer oper�ci� getColumnCount</param>
	/*class pomocnaFunkcia
		: public SimpleTest 
	{
		void pomocnaFunkcia(int matrix, int size_row, int size_column, int rowCount, int columnCount);
	};*/
	

}
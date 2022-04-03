#include "matrix_test.h"
#include "../../structures/matrix/coherent_matrix.h"
#include "../../structures/matrix/incoherent_matrix.h"

namespace tests
{
	tests::MatrixTestInterface::MatrixTestInterface() :
		SimpleTest("Interface")
	{
	}

	void tests::MatrixTestInterface::test()
	{
		structures::Matrix<int>* matrix = this->makeMatrix(20, 20);
		matrix->assign(*matrix);
		matrix->equals(*matrix);
		matrix->size();
		matrix->isEmpty();
		matrix->getRowCount();
		matrix->getColumnCount();
		matrix->at(10, 10);
		delete matrix;
	}

	structures::Matrix<int>* CoherentMatrixTestInterface::makeMatrix(size_t rows, size_t cols) const
	{
		return new structures::CoherentMatrix<int>(rows, cols);
	}

	structures::Matrix<int>* IncoherentMatrixTestInterface::makeMatrix(size_t rows, size_t cols) const
	{
		return new structures::IncoherentMatrix<int>(rows, cols);
	}

	CoherentMatrixTestOverall::CoherentMatrixTestOverall() :
		ComplexTest("CoherentMatrix")
	{
		addTest(new CoherentMatrixTestInterface());
		addTest(new CoherentMatrixTest1());
	}

	IncoherentMatrixTestOverall::IncoherentMatrixTestOverall() :
		ComplexTest("IncoherentMatrix")
	{
		addTest(new IncoherentMatrixTestInterface());
		addTest(new IncoherentMatrixTest1());
	}

	MatrixTestOverall::MatrixTestOverall() :
		ComplexTest("Matrix")
	{
		addTest(new CoherentMatrixTestOverall());
		addTest(new IncoherentMatrixTestOverall());
	}
	CoherentMatrixTest1::CoherentMatrixTest1() :
		SimpleTest("CoherentMatrix-test1")
	{
	}
	void CoherentMatrixTest1::test()
	{
		DurationType time = tests::DurationType::zero();
		SimpleTest::startStopwatch();
		structures::CoherentMatrix<int>* coherentMatrix = new structures::CoherentMatrix<int>(20, 20);
		coherentMatrix->at(5, 5) = 516;
		coherentMatrix->at(coherentMatrix->getRowCount() - 1, coherentMatrix->getRowCount() - 1) = 100;
		coherentMatrix->at(0, 0) = 200;

		structures::CoherentMatrix<int>* copyCoherentMatrix = new structures::CoherentMatrix<int>(*coherentMatrix);
		structures::CoherentMatrix<int>* assignCoherentMatrix = new structures::CoherentMatrix<int>(20, 20);
		assignCoherentMatrix->assign(*coherentMatrix);

		SimpleTest::assertTrue(coherentMatrix->size() == 400, "matrix1.size == 400");
		SimpleTest::assertTrue(copyCoherentMatrix->size() == 400, "matrix2[10,10] == 0");

		SimpleTest::assertTrue(coherentMatrix->at(10, 10) == 0, "matrix1[10,10] == 0");
		SimpleTest::assertTrue(coherentMatrix->at(5, 5) == 516, "matrix1[5,5] == 516");
		
		SimpleTest::assertTrue(copyCoherentMatrix->at(5, 5), "matrix2[5,5] == 516");
		SimpleTest::assertTrue(assignCoherentMatrix->at(5,5), "matrix3[5, 5] == 516");
		
		SimpleTest::assertTrue(copyCoherentMatrix->at(copyCoherentMatrix->getRowCount() - 1, copyCoherentMatrix->getRowCount() - 1), "matrix2[20, 20] == 100");
		SimpleTest::assertTrue(assignCoherentMatrix->at(assignCoherentMatrix->getRowCount() - 1, assignCoherentMatrix->getRowCount() - 1), "matrix3[20, 20] == 100");
		SimpleTest::assertTrue(copyCoherentMatrix->at(0, 0), "matrix2[0, 0] == 200");
		SimpleTest::assertTrue(assignCoherentMatrix->at(0, 0), "matrix3[0, 0] == 200");

		SimpleTest::assertTrue(coherentMatrix->equals(*copyCoherentMatrix), "matrix1 is equal to matrix2");
		SimpleTest::assertTrue(coherentMatrix->equals(*assignCoherentMatrix), "matrix1 is equal to matrix3");
		SimpleTest::assertTrue(copyCoherentMatrix->equals(*assignCoherentMatrix), "matrix2 is equal to matrix3");
		
		SimpleTest::stopStopwatch();
		time = getElapsedTime();
		SimpleTest::logInfo("Total time: " + std::to_string(time.count()));
		//getElapsedTime();
		SimpleTest::logInfo("finished");

		

		delete coherentMatrix;
		delete copyCoherentMatrix;
		delete assignCoherentMatrix;	
	}
	IncoherentMatrixTest1::IncoherentMatrixTest1() :
		SimpleTest("IncoherentMatrix-test1")
	{
	}
	void IncoherentMatrixTest1::test()
	{
		DurationType time = tests::DurationType::zero();
		SimpleTest::startStopwatch();
		structures::IncoherentMatrix<int>* incoherentMatrix = new structures::IncoherentMatrix<int>(20, 20);
		incoherentMatrix->at(5, 5) = 516;
		incoherentMatrix->at(incoherentMatrix->getRowCount() - 1, incoherentMatrix->getRowCount() - 1) = 100;
		incoherentMatrix->at(0, 0) = 200;

		structures::IncoherentMatrix<int>* copyIncoherentMatrix = new structures::IncoherentMatrix<int>(*incoherentMatrix);
		structures::IncoherentMatrix<int>* assignIncoherentMatrix = new structures::IncoherentMatrix<int>(20, 20);
		assignIncoherentMatrix->assign(*incoherentMatrix);

		SimpleTest::assertTrue(incoherentMatrix->size() == 400, "matrix1.size == 400");
		SimpleTest::assertTrue(copyIncoherentMatrix->size() == 400, "matrix2[10,10] == 0");

		SimpleTest::assertTrue(incoherentMatrix->at(10, 10) == 0, "matrix1[10,10] == 0");
		SimpleTest::assertTrue(incoherentMatrix->at(5, 5) == 516, "matrix1[5,5] == 516");

		SimpleTest::assertTrue(copyIncoherentMatrix->at(5, 5), "matrix2[5,5] == 516");
		SimpleTest::assertTrue(assignIncoherentMatrix->at(5, 5), "matrix3[5, 5] == 516");

		SimpleTest::assertTrue(copyIncoherentMatrix->at(copyIncoherentMatrix->getRowCount() - 1, copyIncoherentMatrix->getRowCount() - 1), "matrix2[20, 20] == 100");
		SimpleTest::assertTrue(assignIncoherentMatrix->at(assignIncoherentMatrix->getRowCount() - 1, assignIncoherentMatrix->getRowCount() - 1), "matrix3[20, 20] == 100");
		SimpleTest::assertTrue(copyIncoherentMatrix->at(0, 0), "matrix2[0, 0] == 200");
		SimpleTest::assertTrue(assignIncoherentMatrix->at(0, 0), "matrix3[0, 0] == 200");

		SimpleTest::assertTrue(incoherentMatrix->equals(*copyIncoherentMatrix), "matrix1 is equal to matrix2");
		SimpleTest::assertTrue(incoherentMatrix->equals(*assignIncoherentMatrix), "matrix1 is equal to matrix3");
		SimpleTest::assertTrue(copyIncoherentMatrix->equals(*assignIncoherentMatrix), "matrix2 is equal to matrix3");

		SimpleTest::stopStopwatch();
		time = getElapsedTime();
		SimpleTest::logInfo("Total time: " + std::to_string(time.count()));
		//getElapsedTime();
		SimpleTest::logInfo("finished");



		delete incoherentMatrix;
		delete copyIncoherentMatrix;
		delete assignIncoherentMatrix;

		SimpleTest::logInfo("finished");
	}
}

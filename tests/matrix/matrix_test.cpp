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
		addTest(new CoherentMatrixScenarA());
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
		//addTest(new CoherentMatrixTestOverall());
		//addTest(new IncoherentMatrixTestOverall());
		addTest(new CoherentMatrixTestScenarios());
		addTest(new IncoherentMatrixTestScenarios());

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
		for (int i = 0; i < coherentMatrix->getRowCount() - 1; i++) {
			for (int j = 0; j < coherentMatrix->getColumnCount() - 1; j++) {
				coherentMatrix->at(i, j) = i + j;
			}
		}
		for (int i = 0; i < coherentMatrix->getRowCount() - 1; i++) {
			for (int j = 0; j < coherentMatrix->getColumnCount() - 1; j++) {
				SimpleTest::assertTrue(coherentMatrix->at(i, j) == i + j,"");
			}
		}
		coherentMatrix->at(5, 5) = 516;
		coherentMatrix->at(coherentMatrix->getRowCount() - 1, coherentMatrix->getRowCount() - 1) = 100;
		coherentMatrix->at(0, 0) = 200;

		structures::CoherentMatrix<int>* copyCoherentMatrix = new structures::CoherentMatrix<int>(*coherentMatrix);
		structures::CoherentMatrix<int>* assignCoherentMatrix = new structures::CoherentMatrix<int>(20, 20);
		assignCoherentMatrix->assign(*coherentMatrix);

		SimpleTest::assertTrue(coherentMatrix->size() == 400, "matrix1.size == 400");
		SimpleTest::assertTrue(copyCoherentMatrix->size() == 400, "matrix2[10,10] == 0");

		SimpleTest::assertFalse(coherentMatrix->at(10, 10) == 0, "matrix1[10,10] == 0");
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
		/*for (int i = 0; i < assignCoherentMatrix->getRowCount() - 1; i++) {
			for (int j = 0; j < assignCoherentMatrix->getColumnCount() - 1; j++) {
				SimpleTest::assertTrue(assignCoherentMatrix->at(i, j) == i + j, "");
			}
		}
		
		for (int i = 0; i < copyCoherentMatrix->getRowCount() - 1; i++) {
			for (int j = 0; j < copyCoherentMatrix->getColumnCount() - 1; j++) {
				SimpleTest::assertTrue(copyCoherentMatrix->at(i, j) == i + j, "");
			}
		}*/
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
		SimpleTest::logInfo("finished");



		delete incoherentMatrix;
		delete copyIncoherentMatrix;
		delete assignIncoherentMatrix;

		SimpleTest::logInfo("finished");
	}
	////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////
	CoherentMatrixTestScenarios::CoherentMatrixTestScenarios() :
		ComplexTest("Coherent scenarios")
	{
		addTest(new CoherentMatrixScenarA);
		addTest(new CoherentMatrixScenarB);
		addTest(new CoherentMatrixScenarC);
		addTest(new CoherentMatrixScenarD);
	}

	IncoherentMatrixTestScenarios::IncoherentMatrixTestScenarios() :
		ComplexTest("Incoherent scenarios")
	{
		addTest(new IncoherentMatrixScenarA);
		addTest(new IncoherentMatrixScenarB);
		addTest(new IncoherentMatrixScenarC);
		addTest(new IncoherentMatrixScenarD);

	}

	CoherentMatrixScenarA::CoherentMatrixScenarA() :
		SimpleTest("CoherentMatrixScenarA")
	{
		
	}

	void CoherentMatrixScenarA::test()
	{
		srand(time(NULL));
		SimpleTest::logInfo("Coherent matrix scenar A");
		SimpleTest::logInfo("row size: 10");
		SimpleTest::logInfo("column size: 50");
		SimpleTest::logInfo("Rowcount: 5%, columncount: 5%, at: 90%");

		int operationCount = 1000000;
		structures::CoherentMatrix<int>* matrix = new structures::CoherentMatrix<int>(10, 50);

		int getRowCount = (operationCount / 100) * 5;
		int getColumnCount = (operationCount / 100) * 5;
		int getAtCount = (operationCount / 100) * (100 - 5 - 5);
		DurationType rowCountTime = tests::DurationType::zero();
		DurationType columnCountTime = tests::DurationType::zero();
		DurationType atCountTime = tests::DurationType::zero();
		for (int replication = 1; replication <= operationCount; replication++) {
			int randChance = rand() % 100;
			if (randChance < 90 && getAtCount != 0) {
				getAtCount--;
				int x = rand() % 10;
				int y = rand() % 50;
				SimpleTest::startStopwatch();
				matrix->at(x, y);
				SimpleTest::stopStopwatch();
				atCountTime += SimpleTest::getElapsedTime();

			}
			else if (randChance < 95 && getColumnCount != 0) {
				getColumnCount--;
				SimpleTest::startStopwatch();
				matrix->getColumnCount();
				SimpleTest::stopStopwatch();
				columnCountTime += SimpleTest::getElapsedTime();
			}
			else if (getRowCount != 0) {
				getRowCount--;
				SimpleTest::startStopwatch();
				matrix->getRowCount();
				SimpleTest::stopStopwatch();
				rowCountTime += SimpleTest::getElapsedTime();
			}
		}
		SimpleTest::logInfo("Dokopy èas getColumnSize: " + std::to_string(rowCountTime.count()) + " mikrosekúnd");
		SimpleTest::logInfo("Dokopy èas getRowSize: " + std::to_string(columnCountTime.count()) + " mikrosekúnd");
		SimpleTest::logInfo("Dokopy èas getAt: " + std::to_string(atCountTime.count()) + " mikrosekúnd");		
	}

	CoherentMatrixScenarB::CoherentMatrixScenarB() :
		SimpleTest("CoherentMatrixScenarB")
	{
	}

	void CoherentMatrixScenarB::test()
	{
		SimpleTest::logInfo("Coherent matrix scenar B");
		SimpleTest::logInfo("row size: 2000");
		SimpleTest::logInfo("column size: 500");
		SimpleTest::logInfo("Rowcount: 5%, columncount: 5%, at: 90%");
		
		int operationCount = 1000000;
		structures::CoherentMatrix<int>* matrix = new structures::CoherentMatrix<int>(2000, 500);

		int getRowCount = (operationCount / 100) * 5;
		int getColumnCount = (operationCount / 100) * 5;
		int getAtCount = (operationCount / 100) * (100 - 5 - 5);
		DurationType rowCountTime = tests::DurationType::zero();
		DurationType columnCountTime = tests::DurationType::zero();
		DurationType atCountTime = tests::DurationType::zero();
		for (int replication = 1; replication <= operationCount; replication++) {
			int randChance = rand() % 100;
			if (randChance < 90 && getAtCount != 0) {
				getAtCount--;
				int x = rand() % 2000;
				int y = rand() % 500;
				SimpleTest::startStopwatch();
				matrix->at(x, y);
				SimpleTest::stopStopwatch();
				atCountTime += SimpleTest::getElapsedTime();

			}
			else if (randChance < 95 && getColumnCount != 0) {
				getColumnCount--;
				SimpleTest::startStopwatch();
				matrix->getColumnCount();
				SimpleTest::stopStopwatch();
				columnCountTime += SimpleTest::getElapsedTime();
			}
			else if (getRowCount != 0) {
				getRowCount--;
				SimpleTest::startStopwatch();
				matrix->getRowCount();
				SimpleTest::stopStopwatch();
				rowCountTime += SimpleTest::getElapsedTime();
			}
		}
		SimpleTest::logInfo("Dokopy èas getColumnSize: " + std::to_string(rowCountTime.count()) + " mikrosekúnd");
		SimpleTest::logInfo("Dokopy èas getRowSize: " + std::to_string(columnCountTime.count()) + " mikrosekúnd");
		SimpleTest::logInfo("Dokopy èas getAt: " + std::to_string(atCountTime.count()) + " mikrosekúnd");

	}

	CoherentMatrixScenarC::CoherentMatrixScenarC() :
		SimpleTest("CoherentMatrixScenarC")
	{
	}

	void CoherentMatrixScenarC::test()
	{
		SimpleTest::logInfo("Coherent matrix scenar C");
		SimpleTest::logInfo("row size: 50");
		SimpleTest::logInfo("column size: 10");
		SimpleTest::logInfo("Rowcount: 10%, columncount: 30%, at: 60%");

		int operationCount = 1000000;
		structures::CoherentMatrix<int>* matrix = new structures::CoherentMatrix<int>(50, 10);

		int getRowCount = (operationCount / 100) * 10;
		int getColumnCount = (operationCount / 100) * 30;
		int getAtCount = (operationCount / 100) * (100 - 10 - 30);
		DurationType rowCountTime = tests::DurationType::zero();
		DurationType columnCountTime = tests::DurationType::zero();
		DurationType atCountTime = tests::DurationType::zero();
		for (int replication = 1; replication <= operationCount; replication++) {
			int randChance = rand() % 100;
			if (randChance < 60 && getAtCount != 0) {
				getAtCount--;
				int x = rand() % 50;
				int y = rand() % 10;
				SimpleTest::startStopwatch();
				matrix->at(x, y);
				SimpleTest::stopStopwatch();
				atCountTime += SimpleTest::getElapsedTime();

			}
			else if (randChance < 90 && getColumnCount != 0) {
				getColumnCount--;
				SimpleTest::startStopwatch();
				matrix->getColumnCount();
				SimpleTest::stopStopwatch();
				columnCountTime += SimpleTest::getElapsedTime();
			}
			else if (getRowCount != 0) {
				getRowCount--;
				SimpleTest::startStopwatch();
				matrix->getRowCount();
				SimpleTest::stopStopwatch();
				rowCountTime += SimpleTest::getElapsedTime();
			}
		}
		SimpleTest::logInfo("Dokopy èas getColumnSize: " + std::to_string(rowCountTime.count()) + " mikrosekúnd");
		SimpleTest::logInfo("Dokopy èas getRowSize: " + std::to_string(columnCountTime.count()) + " mikrosekúnd");
		SimpleTest::logInfo("Dokopy èas getAt: " + std::to_string(atCountTime.count()) + " mikrosekúnd");
	}

	CoherentMatrixScenarD::CoherentMatrixScenarD() :
		SimpleTest("CoherentMatrixScenarD")
	{
	}

	void CoherentMatrixScenarD::test()
	{
		SimpleTest::logInfo("Coherent matrix scenar D");
		SimpleTest::logInfo("row size: 500");
		SimpleTest::logInfo("column size: 2000");
		SimpleTest::logInfo("Rowcount: 10%, columncount: 30%, at: 60%");

		SimpleTest::logInfo("Coherent matrix scenar C");
		SimpleTest::logInfo("row size: 50");
		SimpleTest::logInfo("column size: 10");
		SimpleTest::logInfo("Rowcount: 10%, columncount: 30%, at: 60%");

		int operationCount = 1000000;
		structures::CoherentMatrix<int>* matrix = new structures::CoherentMatrix<int>(500, 2000);

		int getRowCount = (operationCount / 100) * 10;
		int getColumnCount = (operationCount / 100) * 30;
		int getAtCount = (operationCount / 100) * (100 - 10 - 30);
		DurationType rowCountTime = tests::DurationType::zero();
		DurationType columnCountTime = tests::DurationType::zero();
		DurationType atCountTime = tests::DurationType::zero();
		for (int replication = 1; replication <= operationCount; replication++) {
			int randChance = rand() % 100;
			if (randChance < 60 && getAtCount != 0) {
				getAtCount--;
				int x = rand() % 500;
				int y = rand() % 2000;
				SimpleTest::startStopwatch();
				matrix->at(x, y);
				SimpleTest::stopStopwatch();
				atCountTime += SimpleTest::getElapsedTime();

			}
			else if (randChance < 90 && getColumnCount != 0) {
				getColumnCount--;
				SimpleTest::startStopwatch();
				matrix->getColumnCount();
				SimpleTest::stopStopwatch();
				columnCountTime += SimpleTest::getElapsedTime();
			}
			else if (getRowCount != 0) {
				getRowCount--;
				SimpleTest::startStopwatch();
				matrix->getRowCount();
				SimpleTest::stopStopwatch();
				rowCountTime += SimpleTest::getElapsedTime();
			}
		}
		SimpleTest::logInfo("Dokopy èas getColumnSize: " + std::to_string(rowCountTime.count()) + " mikrosekúnd");
		SimpleTest::logInfo("Dokopy èas getRowSize: " + std::to_string(columnCountTime.count()) + " mikrosekúnd");
		SimpleTest::logInfo("Dokopy èas getAt: " + std::to_string(atCountTime.count()) + " mikrosekúnd");
	}

	IncoherentMatrixScenarA::IncoherentMatrixScenarA() :
		SimpleTest("InoherentMatrixScenarA")
	{
	}

	void IncoherentMatrixScenarA::test()
	{
		SimpleTest::logInfo("Incoherent matrix scenar A");
		SimpleTest::logInfo("row size: 10");
		SimpleTest::logInfo("column size: 50");
		SimpleTest::logInfo("Rowcount: 5%, columncount: 5%, at: 90%");

		int operationCount = 1000000;
		structures::IncoherentMatrix<int>* matrix = new structures::IncoherentMatrix<int>(10, 50);

		int getRowCount = (operationCount / 100) * 5;
		int getColumnCount = (operationCount / 100) * 5;
		int getAtCount = (operationCount / 100) * (100 - 5 - 5);
		DurationType rowCountTime = tests::DurationType::zero();
		DurationType columnCountTime = tests::DurationType::zero();
		DurationType atCountTime = tests::DurationType::zero();
		for (int replication = 1; replication <= operationCount; replication++) {
			int randChance = rand() % 100;
			if (randChance < 90 && getAtCount != 0) {
				getAtCount--;
				int x = rand() % 10;
				int y = rand() % 50;
				SimpleTest::startStopwatch();
				matrix->at(x, y);
				SimpleTest::stopStopwatch();
				atCountTime += SimpleTest::getElapsedTime();

			}
			else if (randChance < 95 && getColumnCount != 0) {
				getColumnCount--;
				SimpleTest::startStopwatch();
				matrix->getColumnCount();
				SimpleTest::stopStopwatch();
				columnCountTime += SimpleTest::getElapsedTime();
			}
			else if (getRowCount != 0) {
				getRowCount--;
				SimpleTest::startStopwatch();
				matrix->getRowCount();
				SimpleTest::stopStopwatch();
				rowCountTime += SimpleTest::getElapsedTime();
			}
		}
		SimpleTest::logInfo("Dokopy èas getColumnSize: " + std::to_string(rowCountTime.count()) + " mikrosekúnd");
		SimpleTest::logInfo("Dokopy èas getRowSize: " + std::to_string(columnCountTime.count()) + " mikrosekúnd");
		SimpleTest::logInfo("Dokopy èas getAt: " + std::to_string(atCountTime.count()) + " mikrosekúnd");
	}

	IncoherentMatrixScenarB::IncoherentMatrixScenarB() :
		SimpleTest("InoherentMatrixScenarD")
	{
	}

	void IncoherentMatrixScenarB::test()
	{
		SimpleTest::logInfo("Incoherent matrix scenar B");
		SimpleTest::logInfo("row size: 2000");
		SimpleTest::logInfo("column size: 500");
		SimpleTest::logInfo("Rowcount: 5%, columncount: 5%, at: 90%");

		int operationCount = 1000000;
		structures::IncoherentMatrix<int>* matrix = new structures::IncoherentMatrix<int>(2000, 500);

		int getRowCount = (operationCount / 100) * 5;
		int getColumnCount = (operationCount / 100) * 5;
		int getAtCount = (operationCount / 100) * (100 - 5 - 5);
		DurationType rowCountTime = tests::DurationType::zero();
		DurationType columnCountTime = tests::DurationType::zero();
		DurationType atCountTime = tests::DurationType::zero();
		for (int replication = 1; replication <= operationCount; replication++) {
			int randChance = rand() % 100;
			if (randChance < 90 && getAtCount != 0) {
				getAtCount--;
				int x = rand() % 2000;
				int y = rand() % 500;
				SimpleTest::startStopwatch();
				matrix->at(x, y);
				SimpleTest::stopStopwatch();
				atCountTime += SimpleTest::getElapsedTime();

			}
			else if (randChance < 95 && getColumnCount != 0) {
				getColumnCount--;
				SimpleTest::startStopwatch();
				matrix->getColumnCount();
				SimpleTest::stopStopwatch();
				columnCountTime += SimpleTest::getElapsedTime();
			}
			else if (getRowCount != 0) {
				getRowCount--;
				SimpleTest::startStopwatch();
				matrix->getRowCount();
				SimpleTest::stopStopwatch();
				rowCountTime += SimpleTest::getElapsedTime();
			}
		}
		SimpleTest::logInfo("Dokopy èas getColumnSize: " + std::to_string(rowCountTime.count()) + " mikrosekúnd");
		SimpleTest::logInfo("Dokopy èas getRowSize: " + std::to_string(columnCountTime.count()) + " mikrosekúnd");
		SimpleTest::logInfo("Dokopy èas getAt: " + std::to_string(atCountTime.count()) + " mikrosekúnd");

	}

	IncoherentMatrixScenarC::IncoherentMatrixScenarC() :
		SimpleTest("InoherentMatrixScenarC")
	{
	}

	void IncoherentMatrixScenarC::test()
	{
		SimpleTest::logInfo("Incoherent matrix scenar C");
		SimpleTest::logInfo("row size: 50");
		SimpleTest::logInfo("column size: 10");
		SimpleTest::logInfo("Rowcount: 10%, columncount: 30%, at: 60%");

		int operationCount = 1000000;
		structures::IncoherentMatrix<int>* matrix = new structures::IncoherentMatrix<int>(50, 10);

		int getRowCount = (operationCount / 100) * 10;
		int getColumnCount = (operationCount / 100) * 30;
		int getAtCount = (operationCount / 100) * (100 - 10 - 30);
		DurationType rowCountTime = tests::DurationType::zero();
		DurationType columnCountTime = tests::DurationType::zero();
		DurationType atCountTime = tests::DurationType::zero();
		for (int replication = 1; replication <= operationCount; replication++) {
			int randChance = rand() % 100;
			if (randChance < 60 && getAtCount != 0) {
				getAtCount--;
				int x = rand() % 50;
				int y = rand() % 10;
				SimpleTest::startStopwatch();
				matrix->at(x, y);
				SimpleTest::stopStopwatch();
				atCountTime += SimpleTest::getElapsedTime();

			}
			else if (randChance < 90 && getColumnCount != 0) {
				getColumnCount--;
				SimpleTest::startStopwatch();
				matrix->getColumnCount();
				SimpleTest::stopStopwatch();
				columnCountTime += SimpleTest::getElapsedTime();
			}
			else if (getRowCount != 0) {
				getRowCount--;
				SimpleTest::startStopwatch();
				matrix->getRowCount();
				SimpleTest::stopStopwatch();
				rowCountTime += SimpleTest::getElapsedTime();
			}
		}
		SimpleTest::logInfo("Dokopy èas getColumnSize: " + std::to_string(rowCountTime.count()) + " mikrosekúnd");
		SimpleTest::logInfo("Dokopy èas getRowSize: " + std::to_string(columnCountTime.count()) + " mikrosekúnd");
		SimpleTest::logInfo("Dokopy èas getAt: " + std::to_string(atCountTime.count()) + " mikrosekúnd");
	}

	IncoherentMatrixScenarD::IncoherentMatrixScenarD() :
		SimpleTest("InoherentMatrixScenarD")
	{
	}

	void IncoherentMatrixScenarD::test()
	{
		SimpleTest::logInfo("Incoherent matrix scenar D");
		SimpleTest::logInfo("row size: 500");
		SimpleTest::logInfo("column size: 2000");
		SimpleTest::logInfo("Rowcount: 10%, columncount: 30%, at: 60%");

		int operationCount = 1000000;
		structures::IncoherentMatrix<int>* matrix = new structures::IncoherentMatrix<int>(500, 2000);

		int getRowCount = (operationCount / 100) * 10;
		int getColumnCount = (operationCount / 100) * 30;
		int getAtCount = (operationCount / 100) * (100 - 10 - 30);
		DurationType rowCountTime = tests::DurationType::zero();
		DurationType columnCountTime = tests::DurationType::zero();
		DurationType atCountTime = tests::DurationType::zero();
		for (int replication = 1; replication <= operationCount; replication++) {
			int randChance = rand() % 100;
			if (randChance < 60 && getAtCount != 0) {
				getAtCount--;
				int x = rand() % 500;
				int y = rand() % 2000;
				SimpleTest::startStopwatch();
				matrix->at(x, y);
				SimpleTest::stopStopwatch();
				atCountTime += SimpleTest::getElapsedTime();

			}
			else if (randChance < 90 && getColumnCount != 0) {
				getColumnCount--;
				SimpleTest::startStopwatch();
				matrix->getColumnCount();
				SimpleTest::stopStopwatch();
				columnCountTime += SimpleTest::getElapsedTime();
			}
			else if (getRowCount != 0) {
				getRowCount--;
				SimpleTest::startStopwatch();
				matrix->getRowCount();
				SimpleTest::stopStopwatch();
				rowCountTime += SimpleTest::getElapsedTime();
			}
		}
		SimpleTest::logInfo("Dokopy èas getColumnSize: " + std::to_string(rowCountTime.count()) + " mikrosekúnd");
		SimpleTest::logInfo("Dokopy èas getRowSize: " + std::to_string(columnCountTime.count()) + " mikrosekúnd");
		SimpleTest::logInfo("Dokopy èas getAt: " + std::to_string(atCountTime.count()) + " mikrosekúnd");
	}
}

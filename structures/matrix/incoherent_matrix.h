#pragma once

#include "matrix.h"
#include <stdexcept>

namespace structures
{
	/// <summary> Implementacia matice v nesuvislej pamati. </summary>
	/// <typeparam name = "T"> Typ dat ukladanych v matici. </typepram>
	template<typename T>
	class IncoherentMatrix
		: public Matrix<T>
	{
	public:
		/// <summary>
		///	Konstruktor. Vytvori maticu o danom pocte riadkov a stlpcov.
		/// Polozky su inicializovane na "nulovu" hodnotu typu T.
		/// </summary>
		/// <param name="rowCount"> Pocet riadkov. </param>
		/// <param name="columnCount"> Pocet stlpcov. </param>
		IncoherentMatrix(size_t rowCount, size_t columnCount);

		/// <summary> Inicializuje tuto maticu ako kopiu matice odovzdanej ako parameter. </summary>
		/// <param name = "other"> Odkaz na maticu, z ktorej sa prevezmu vlastnosti. </param>
		IncoherentMatrix(IncoherentMatrix& other);

		/// <summary> Destruktor. </summary>
		~IncoherentMatrix();

		/// <summary>
		/// Ak je to mozne (parametrom je matica, ktora ma rovnake rozmery ako ako aktualna matica),
		/// tak skopiruje vlastnosti z matice odovzdanej ako parameter.
		/// Ak to nie je mozne, vyhodi sa vynimka.
		/// </summary>
		/// <param name = "other"> Odkaz na strukturu, z ktorej maju prebrat vlastnosti. </param>
		/// <returns> Adresa, na ktorej sa struktura nachadza. </returns>
		Structure& assign(Structure& other) override;

		/// <summary>
		/// Ak je parametrom matica a obsah porovnavanych matic je rovnaky,
		/// tak vrati hodnotu true. V opacnom pripade vrati hodnotu false.
		/// </summary>
		/// <param name="other"> Odkaz na strukturu, s ktorou sa ma tato matica porovnat. </param>
		/// <returns>True ak su struktury zhodne typom aj obsahom. </returns>
		bool equals(Structure& other) override;

		/// <summary> Pocet vsetkych prvkov v matici. </summary>
		/// <returns> Pocet prvkov v matici. </returns>
		size_t size() override;

		/// <summary> Vrati pocet riadkov v matici. </summary>
		/// <returns> Pocet riadkov matice. </returns>
		size_t getRowCount() override;

		/// <summary> Vrati pocet stlpcov matice. </summary>
		/// <returns> Pocet stlpcov matice. </returns>
		size_t getColumnCount() override;

		/// <summary> Vrati odkaz na prvok v danom riadku a stlpci. </summary>
		/// <param name="rowIndex"> Index riadku. </param>
		/// <param name="columnIndex"> Index stlpca. </param>
		/// <returns> Odkaz na prvok na danych indexoch. </returns>
		/// <exception cref="std::out_of_range"> Vyhodena, ak index riadku alebo stlpca nepatri do matice. </exception>
		T& at(int rowIndex, int columnIndex) override;
	private:
		Array<Array<T>*>* incoherentMatrix;
		size_t rowCount;
		size_t columnCount;
	};

	template<typename T>
	inline IncoherentMatrix<T>::IncoherentMatrix(size_t rowCount, size_t columnCount)
	{
		this->rowCount = rowCount;
		this->columnCount = columnCount;
		incoherentMatrix = new Array<Array<T>*>(rowCount);
		for (int i = 0; i < rowCount; i++) {
			(*incoherentMatrix)[i] = new Array<T>(columnCount);	
		}
	}

	template<typename T>
	inline IncoherentMatrix<T>::IncoherentMatrix(IncoherentMatrix& other)
	{
		this->rowCount = other.getRowCount();
		this->columnCount = other.getColumnCount();
		incoherentMatrix = new Array<Array<T>*>(rowCount);
		for (int i = 0; i < rowCount; i++) {
			(*incoherentMatrix)[i] = new Array<T>(*(*other.incoherentMatrix)[i]);
		}
	}

	template<typename T>
	inline IncoherentMatrix<T>::~IncoherentMatrix()
	{
		for (int i = 0; i < rowCount; i++) {
			delete (*incoherentMatrix)[i];
		}
		delete incoherentMatrix;
		incoherentMatrix = nullptr;
		rowCount = 0;
		columnCount = 0;
	}

	template<typename T>
	inline Structure& IncoherentMatrix<T>::assign(Structure & other)
	{
		if (this != &other) {
			IncoherentMatrix<T>& otherIncoherentMatrix = dynamic_cast<IncoherentMatrix<T>&>(other);
			if (rowCount != otherIncoherentMatrix.rowCount) {
				throw std::invalid_argument("Coherent matrixes don't have matching row size!");
			}
			if (columnCount != otherIncoherentMatrix.columnCount) {
				throw std::invalid_argument("Coherent matrixes don't have matching column size!");
			}
			delete incoherentMatrix;
			incoherentMatrix = new Array<Array<T>*>(rowCount);
			for (int i = 0; i < rowCount; i++) {
				(*incoherentMatrix)[i] = new Array<T>(*(*otherIncoherentMatrix.incoherentMatrix)[i]);
			}
		}

		return *this;
	}

	template<typename T>
	inline bool IncoherentMatrix<T>::equals(Structure & other)
	{
		if (this == &other) {
			return true;
		}
		IncoherentMatrix<T>* otherIncoherentMatrix = dynamic_cast<IncoherentMatrix<T>*>(&other);
		if (otherIncoherentMatrix == nullptr ||
			otherIncoherentMatrix->getRowCount() != rowCount ||
			otherIncoherentMatrix->getColumnCount() != columnCount) {
			return false;
		}
		for (int i = 0; i < rowCount; i++) {
			for (int j = 0; j < columnCount; j++) {
				if (at(i, j) != otherIncoherentMatrix->at(i, j)) {
					return false;
				}
			}
		}

		return true;
	}

	template<typename T>
	inline size_t IncoherentMatrix<T>::size()
	{
		return (rowCount * columnCount);
	}

	template<typename T>
	inline size_t IncoherentMatrix<T>::getRowCount()
	{
		return rowCount;
	}

	template<typename T>
	inline size_t IncoherentMatrix<T>::getColumnCount()
	{
		return columnCount;
	}

	template<typename T>
	inline T& IncoherentMatrix<T>::at(int rowIndex, int columnIndex)
	{
		return (*(*incoherentMatrix)[rowIndex])[columnIndex];
	}
}
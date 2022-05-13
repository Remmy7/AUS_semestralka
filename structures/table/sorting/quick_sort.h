#pragma once

#include "sort.h"
#include "../unsorted_sequence_table.h"

namespace structures
{
	/// <summary> Triedenie Quick sort. </summary>
	/// <typeparam name = "K"> Kluc prvkov v tabulke. </typepram>
	/// <typeparam name = "T"> Typ dat ukladanych v tabulke. </typepram>
	template <typename K, typename T>
	class QuickSort : public Sort<K, T>
	{
	public:
		/// <summary> Utriedi tabulku triedenim Quick sort. </summary>
		/// <param name = "table"> NonortedSequenceTable, ktoru ma utriedit. </param>
		void sort(UnsortedSequenceTable<K, T>& table) override;
	};

	template<typename K, typename T>
	inline void QuickSort<K, T>::sort(UnsortedSequenceTable<K, T>& table)
	{
		quick(0, table.size() - 1);
	}

	void quick(size_t min, size_t max) { //table getItemAtIndex TODO
		size_t pivot = (min + max) / 2;
		size_t leftIndex = min;
		size_t rightIndex = max;

		do {
			if (leftIndex < pivot) {
				leftIndex++;
			}
			if (rightIndex > pivot) {
				rightIndex--;
			}
			if (leftIndex <= rightIndex) {
				Utils::swap(leftIndex, rightIndex);
				leftIndex++;
				rightIndex--;
			}
		} while (leftIndex <= rightIndex);
		if (min < rightIndex) {
			quick(min, rightIndex);
		}
		if (leftIndex < max) {
			quick(leftIndex, max);
		}
	}
}

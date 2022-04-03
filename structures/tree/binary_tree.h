#pragma once

#include "k_way_tree.h"
#include "tree.h"
#include <queue>

namespace structures
{
	/// <summary> Vrchol binarneho stromu. </summary>
	/// <typeparam name = "T"> Typ dat ukladanych vo vrchole stromu. </typepram>
	template <typename T>
	class BinaryTreeNode : public KWayTreeNode<T,2>
	{
	public:
		/// <summary> Konstruktor. </summary>
		/// <param name = "data"> Data, ktore uchovava. </param>
		BinaryTreeNode(T data);

		/// <summary> Kopirovaci konstruktor. </summary>
		/// <param name = "other"> Vrchol binarneho stromu, z ktoreho sa prevezmu vlastnosti. </param>
		/// <remarks> Vytvori sa ako plytka kopia vrcholu other. </remarks>
		BinaryTreeNode(BinaryTreeNode<T>& other);

		/// <summary> Vytvori plytku kopiu vrchola (teda skopiruje iba data a smerniky na synov). </summary>
		/// <returns> Vystvorena plytka kopia vrcholu. </returns>
		TreeNode<T>* shallowCopy() override;

		/// <summary> Getter otca. </summary>
		/// <returns> Otec. </returns>
		BinaryTreeNode<T>* getParent();

		/// <summary> Getter laveho syna. </summary>
		/// <returns> Lavy syn. </returns>
		BinaryTreeNode<T>* getLeftSon();

		/// <summary> Getter praveho syna. </summary>
		/// <returns> Pravy syn. </returns>
		BinaryTreeNode<T>* getRightSon();

		/// <summary> Setter laveho syna. </summary>
		/// <param name = "leftSon"> Novy lavy syn. </returns>
		/// <returns> Nahradeny lavy syn vrcholu. </returns>
		/// <remarks> Vsetky smerniky zucastnenych vrcholov budu spravne nastavene. </remarks>
		void setLeftSon(BinaryTreeNode<T>* leftSon);

		/// <summary> Setter praveho syna. </summary>
		/// <param name = "rightSon"> Novy pravy syn. </returns>
		/// <returns> Nahradeny pravy vrcholu. </returns>
		/// <remarks> Vsetky smerniky zucastnenych vrcholov budu spravne nastavene. </remarks>
		void setRightSon(BinaryTreeNode<T>* rightSon);

		/// <summary> Zameni laveho syna. </summary>
		/// <param name = "leftSon"> Novy lavy syn. </returns>
		/// <returns> Nahradeny lavy syn vrcholu. </returns>
		/// <remarks> Vsetky smerniky zucastnenych vrcholov budu spravne nastavene. </remarks>
		BinaryTreeNode<T>* changeLeftSon(BinaryTreeNode<T>* leftSon);

		/// <summary> Zameni praveho syna. </summary>
		/// <param name = "rightSon"> Novy pravy syn. </returns>
		/// <returns> Nahradeny pravy vrcholu. </returns>
		/// <remarks> Vsetky smerniky zucastnenych vrcholov budu spravne nastavene. </remarks>
		BinaryTreeNode<T>* changeRightSon(BinaryTreeNode<T>* rightSon);

		/// <summary> Zisti, ci je lavym synom svojho otca. </summary>
		/// <returns> true, ak je lavym synom svojho otca, false ak nema otca alebo nie je jeho lavym synom. </returns>
		bool isLeftSon();

		/// <summary> Zisti, ci je pravym synom svojho otca. </summary>
		/// <returns> true, ak je pravym synom svojho otca, false ak nema otca alebo nie je jeho pravym synom. </returns>
		bool isRightSon();

		/// <summary> Zisti, ci ma laveho syna. </summary>
		/// <returns> true, ma laveho syna, false inak. </returns>
		bool hasLeftSon();

		/// <summary> Zisti, ci ma praveho syna. </summary>
		/// <returns> true, ma praveho syna, false inak. </returns>
		bool hasRightSon();

	private:
		static const int LEFT_SON = 0;
		static const int RIGHT_SON = 1;
	};

	/// <summary> Binary strom. </summary>
	/// <typeparam name = "T"> Typ dat ukladanych v strome. </typepram>
	template <typename T>
	class BinaryTree : public KWayTree<T,2>
	{
	public:
		/// <summary> Konstruktor. </summary>
		BinaryTree();

		/// <summary> Kopirovaci konstruktor. </summary>
		/// <param name = "other"> Binarny strom, z ktoreho sa prevezmu vlastnosti. </param>
		BinaryTree(BinaryTree<T>& other);

		/// <summary> Vytvori a vrati instanciu vrcholu binarneho stromu. </summary>
		/// <returns> Vytvorena instancia vrcholu binarneho stromu. </returns>
		TreeNode<T>* createTreeNodeInstance() override;

		/// <summary> Vrati skutocny iterator na zaciatok struktury </summary>
		/// <returns> Iterator na zaciatok struktury. </returns>
		/// <remarks> Zabezpecuje polymorfizmus. </remarks>
		Iterator<T>* getBeginIterator() override;

		/// <summary> Vrati skutocny iterator na koniec struktury </summary>
		/// <returns> Iterator na koniec struktury. </returns>
		/// <remarks> Zabezpecuje polymorfizmus. </remarks>
		Iterator<T>* getEndIterator() override;

	public:
		class InOrderTreeIterator : public TreeIterator
		{
		public:
			/// <summary> Konstruktor. </summary>
			/// <param name = "startNode"> Vrchol podstromu, cez ktory ma iterovat. </param>
			InOrderTreeIterator(TreeNode<T>* startNode);

		private:
			/// <summary> Zostavi do path_ prehliadku binarneho stromu v poradi inorder. </summary>
			/// <param name = "path"> Cesta stromom, ktoru zostavuje. </param>
			/// <param name = "current"> Aktualny spracovavany vrchol stromu. </param>
			void populatePath(TreeNode<T>* current);
		};
	};

	template<typename T>
	inline BinaryTreeNode<T>::BinaryTreeNode(T data):
		KWayTreeNode<T, 2>(data)
	{
	}

	template<typename T>
	inline BinaryTreeNode<T>::BinaryTreeNode(BinaryTreeNode<T>& other):
		KWayTreeNode<T, 2>(other)
	{
	}

	template<typename T>
	inline TreeNode<T>* BinaryTreeNode<T>::shallowCopy()
	{
		//TODO 07: BinaryTreeNode<T>
		throw std::runtime_error("BinaryTreeNode<T>::shallowCopy: Not implemented yet.");
	}

	template<typename T>
	inline BinaryTreeNode<T>* BinaryTreeNode<T>::getParent()
	{
		//TODO 07: BinaryTreeNode<T>
		throw std::runtime_error("BinaryTreeNode<T>::getParent: Not implemented yet.");
	}

	template<typename T>
	inline BinaryTreeNode<T>* BinaryTreeNode<T>::getLeftSon()
	{
		//TODO 07: BinaryTreeNode<T>
		throw std::runtime_error("BinaryTreeNode<T>::getLeftSon: Not implemented yet.");
	}

	template<typename T>
	inline BinaryTreeNode<T>* BinaryTreeNode<T>::getRightSon()
	{
		//TODO 07: BinaryTreeNode<T>
		throw std::runtime_error("BinaryTreeNode<T>::getRightSon: Not implemented yet.");
	}

	template<typename T>
	inline void BinaryTreeNode<T>::setLeftSon(BinaryTreeNode<T>* leftSon)
	{
		//TODO 07: BinaryTreeNode<T>
		throw std::runtime_error("BinaryTreeNode<T>::setLeftSon: Not implemented yet.");
	}

	template<typename T>
	inline void BinaryTreeNode<T>::setRightSon(BinaryTreeNode<T>* rightSon)
	{
		//TODO 07: BinaryTreeNode<T>
		throw std::runtime_error("BinaryTreeNode<T>::setRightSon: Not implemented yet.");
	}

	template<typename T>
	inline BinaryTreeNode<T>* BinaryTreeNode<T>::changeLeftSon(BinaryTreeNode<T>* leftSon)
	{
		//TODO 07: BinaryTreeNode<T>
		throw std::runtime_error("BinaryTreeNode<T>::changeLeftSon: Not implemented yet.");
	}

	template<typename T>
	inline BinaryTreeNode<T>* BinaryTreeNode<T>::changeRightSon(BinaryTreeNode<T>* rightSon)
	{
		//TODO 07: BinaryTreeNode<T>
		throw std::runtime_error("BinaryTreeNode<T>::changeRightSon: Not implemented yet.");
	}

	template<typename T>
	inline bool BinaryTreeNode<T>::isLeftSon()
	{
		//TODO 07: BinaryTreeNode<T>
		throw std::runtime_error("BinaryTreeNode<T>::isLeftSon: Not implemented yet.");
	}

	template<typename T>
	inline bool BinaryTreeNode<T>::isRightSon()
	{
		//TODO 07: BinaryTreeNode<T>
		throw std::runtime_error("BinaryTreeNode<T>::isRightSon: Not implemented yet.");
	}

	template<typename T>
	inline bool BinaryTreeNode<T>::hasLeftSon()
	{
		//TODO 07: BinaryTreeNode<T>
		throw std::runtime_error("BinaryTreeNode<T>::hasLeftSon: Not implemented yet.");
	}

	template<typename T>
	inline bool BinaryTreeNode<T>::hasRightSon()
	{
		//TODO 07: BinaryTreeNode<T>
		throw std::runtime_error("BinaryTreeNode<T>::hasRightSon: Not implemented yet.");
	}

	template<typename T>
	inline BinaryTree<T>::BinaryTree():
		KWayTree<T, 2>()
	{
	}

	template<typename T>
	inline BinaryTree<T>::BinaryTree(BinaryTree<T>& other):
		KWayTree<T, 2>(other)
	{
	}

	template<typename T>
	inline TreeNode<T>* BinaryTree<T>::createTreeNodeInstance()
	{
		T data = T();
		return new BinaryTreeNode<T>(data);
	}

	template<typename T>
	inline Iterator<T>* BinaryTree<T>::getBeginIterator()
	{
		return new InOrderTreeIterator(getRoot());
	}

	template<typename T>
	inline Iterator<T>* BinaryTree<T>::getEndIterator()
	{
		return new InOrderTreeIterator(nullptr);
	}

	template<typename T>
	inline BinaryTree<T>::InOrderTreeIterator::InOrderTreeIterator(TreeNode<T>* startNode):
		TreeIterator()
	{
		populatePath(startNode);
	}

	template<typename T>
	inline void BinaryTree<T>::InOrderTreeIterator::populatePath(TreeNode<T>* current)
	{
		//TODO 07: BinaryTree<T>::InOrderTreeIterator
		throw std::runtime_error("BinaryTree<T>::InOrderTreeIterator::populatePath: Not implemented yet.");
	}

}


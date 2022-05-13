#pragma once

#include "priority_queue_sorted_array_list.h"
#include <stdexcept>

namespace structures
{
    /// <summary> Prioritny front implementovany utriednym ArrayList-om s obmedzenou kapacitou. </summary>
    /// <typeparam name = "T"> Typ dat ukladanych v prioritnom fronte. </typepram>
    template<typename T>
    class PriorityQueueLimitedSortedArrayList : public PriorityQueueSortedArrayList<T>
    {
    public:
        /// <summary> Konstruktor. </summary>
        PriorityQueueLimitedSortedArrayList();

        /// <summary> Kopirovaci konstruktor. </summary>
        /// <param name = "other"> Prioritny front implementovany utriednym ArrayList-om s obmedzenou kapacitou, z ktoreho sa prevezmu vlastnosti. </param>
        PriorityQueueLimitedSortedArrayList(PriorityQueueLimitedSortedArrayList<T>& other);

        /// <summary> Priradenie struktury. </summary>
        /// <param name = "other"> Struktura, z ktorej ma prebrat vlastnosti. </param>
        /// <returns> Adresa, na ktorej sa struktura nachadza. </returns>
        Structure& assign(Structure& other) override;

        /// <summary> Vlozi prvok s danou prioritou do prioritneho frontu implementovaneho utriednym ArrayList-om s obmedzenou kapacitou. </summary>
        /// <param name = "priority"> Priorita vkladaneho prvku. </param>
        /// <param name = "data"> Vkladany prvok. </param>
        /// <exception cref="std::logic_error"> Vyhodena, ak je prioritny front plny. </exception>
        void push(int priority, const T& data) override;

        /// <summary>
        ///  Vlozi prvok s danou prioritou do prioritneho frontu implementovaneho utriednym ArrayList-om s obmedzenou kapacitou.
        ///  V pripade, ze je prioritny front plny, odstrani polozku s najmensou prioritou z prioritneho frontu a vrati smernik na nu.
        ///  V opacnom pripade vrati nullptr.
        /// </summary>
        /// <param name = "priority"> Priorita vkladaneho prvku. </param>
        /// <param name = "data"> Vkladany prvok. </param>
        /// <returns> Smernik na odstranenu polozku alebo nullptr. </returns>
        PriorityQueueItem<T>* pushAndRemove(int priority, T data);

        /// <summary> Vrati najmensiu prioritu nachadzajucu sa v prioritnom fronte. </summary>
        /// <returns> Najmensiu priorita nachadzajuca sa v prioritnom fronte. </returns>
        int minPriority();

        /// <summary>
        ///  Pokusi sa zmenit kapacitu prioritneho frontu.
        ///  Kapacitu je mozne zmensit len ak nova kapacita nie je mensia ako aktualny pocet poloziek v prioritnom fronte.
        ///  V opacnom pripade nedojde k zmene kapacity.
        /// </summary>
        /// <param name = "capacity"> Nova kapacita. </param>
        /// <returns> true, ak sa kapacitu podarilo zmenit, false inak. </returns>
        bool trySetCapacity(size_t capacity);

    private:
        /// <summary> Kapacita prioritneho frontu. </summary>
        size_t capacity_;
    };

    template<typename T>
    PriorityQueueLimitedSortedArrayList<T>::PriorityQueueLimitedSortedArrayList() :
        PriorityQueueSortedArrayList<T>(),
        capacity_(2)
    {
    }

    template<typename T>
    PriorityQueueLimitedSortedArrayList<T>::PriorityQueueLimitedSortedArrayList(PriorityQueueLimitedSortedArrayList<T>& other) :
        PriorityQueueSortedArrayList<T>(other),
        capacity_(other.capacity_)
    {
    }

    template<typename T>
    inline Structure& PriorityQueueLimitedSortedArrayList<T>::assign(Structure& other)
    {
        return PriorityQueueSortedArrayList::assign(other);
    }

    template<typename T>
    void PriorityQueueLimitedSortedArrayList<T>::push(int priority, const T& data)
    {
        if (list_->size() == capacity_) {
            throw std::logic_error("LimitedList is full! push");
        } 
        if (list_->size() < capacity_) {
            PriorityQueueItem<T>* item = new PriorityQueueItem<T>(priority, data);
            int leftIndex = 0;
            int rightIndex = list_->size();

            while (leftIndex < rightIndex) {
                int middleIndex = leftIndex + ((rightIndex - leftIndex) / 2);
                if (item->getPriority() < list_->at(middleIndex)->getPriority()) {
                    leftIndex = middleIndex + 1;
                }
                if (item->getPriority() >= list_->at(middleIndex)->getPriority()) {
                    rightIndex = middleIndex;
                }
            }
            list_->insert(item, leftIndex);
            
        }
        else {
            throw std::logic_error("PriorityQueueLimitedSortedArrayList is full!");
        }
    }

    template<typename T>
    inline PriorityQueueItem<T>* PriorityQueueLimitedSortedArrayList<T>::pushAndRemove(int priority, T data)
    {
        int size = list_->size();
        if (size >= capacity_) {
            auto item = list_->removeAt(0);
            push(priority, data);
            return item;
        }
        if (size < capacity_) {
            push(priority, data);
            return nullptr;
        }
    }

    template<typename T>
    inline int PriorityQueueLimitedSortedArrayList<T>::minPriority()
    {
        return (*PriorityQueueList<T>::list_)[0]->getPriority();
    }

    template<typename T>
    inline bool PriorityQueueLimitedSortedArrayList<T>::trySetCapacity(size_t capacity)
    {
        if (capacity >= PriorityQueueList<T>::list_->size()) {
            capacity_ = capacity;
            return true;
        }
        return false;
    }
}
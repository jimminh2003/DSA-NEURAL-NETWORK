/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   DLinkedListSE.h
 * Author: LTSACH
 *
 * Created on 31 August 2020, 14:13
 */

#ifndef DLINKEDLISTSE_H
#define DLINKEDLISTSE_H
#include "list/DLinkedList.h"
#include "sorting/ISort.h"

template <class T>
class DLinkedListSE : public DLinkedList<T>
{
public:
    DLinkedListSE(
        void (*removeData)(DLinkedList<T> *) = 0,
        bool (*itemEQ)(T &, T &) = 0) : DLinkedList<T>(removeData, itemEQ) {

                                        };

    DLinkedListSE(const DLinkedList<T> &list)
    {
        this->copyFrom(list);
    }

    void sort(int (*comparator)(T &, T &) = 0)
    {
        // Nếu danh sách trống hoặc chỉ có 1 phần tử thì không cần sắp xếp
        if (this->head == nullptr || this->head->next == nullptr)
            return;

        // Thực hiện merge sort
        this->head = mergeSortRecursive(this->head, comparator);

        // Cập nhật tail sau khi sắp xếp
        this->tail = this->head;
        while (this->tail && this->tail->next)
        {
            this->tail = this->tail->next;
        }
    }

protected:
    static int compare(T &lhs, T &rhs, int (*comparator)(T &, T &) = 0)
    {
        if (comparator != 0)
            return comparator(lhs, rhs);
        else
        {
            if (lhs < rhs)
                return -1;
            else if (lhs > rhs)
                return +1;
            else
                return 0;
        }
    }

private:
    // Tìm node ở giữa danh sách
    typename DLinkedList<T>::Node *findMiddle(typename DLinkedList<T>::Node *head)
    {
        if (head == nullptr)
            return nullptr;

        typename DLinkedList<T>::Node *slow = head;
        typename DLinkedList<T>::Node *fast = head;

        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    // Hàm merge hai danh sách con đã sắp xếp
    typename DLinkedList<T>::Node *merge(
        typename DLinkedList<T>::Node *left,
        typename DLinkedList<T>::Node *right,
        int (*comparator)(T &, T &))
    {
        // Nếu một danh sách rỗng, trả về danh sách kia
        if (left == nullptr)
            return right;
        if (right == nullptr)
            return left;

        // Node đầu tiên và node hiện tại của kết quả
        typename DLinkedList<T>::Node *result = nullptr;
        typename DLinkedList<T>::Node *current = nullptr;

        // So sánh và merge
        while (left && right)
        {
            int comparisonResult = compare(left->data, right->data, comparator);

            if (comparisonResult <= 0)
            {
                // Nếu phần tử bên trái nhỏ hơn hoặc bằng
                if (result == nullptr)
                {
                    result = current = left;
                }
                else
                {
                    current->next = left;
                    left->prev = current;
                    current = left;
                }
                left = left->next;
            }
            else
            {
                // Nếu phần tử bên phải nhỏ hơn
                if (result == nullptr)
                {
                    result = current = right;
                }
                else
                {
                    current->next = right;
                    right->prev = current;
                    current = right;
                }
                right = right->next;
            }
        }

        // Nối các phần tử còn lại
        if (left)
        {
            current->next = left;
            left->prev = current;
        }
        if (right)
        {
            current->next = right;
            right->prev = current;
        }

        return result;
    }

    // Hàm merge sort đệ quy
    typename DLinkedList<T>::Node *mergeSortRecursive(
        typename DLinkedList<T>::Node *head,
        int (*comparator)(T &, T &))
    {
        // Trường hợp cơ sở: danh sách rỗng hoặc chỉ có 1 phần tử
        if (head == nullptr || head->next == nullptr)
            return head;

        // Chia danh sách thành 2 nửa
        typename DLinkedList<T>::Node *middle = findMiddle(head);
        typename DLinkedList<T>::Node *nextOfMiddle = middle->next;

        // Ngắt liên kết giữa 2 nửa
        middle->next = nullptr;
        if (nextOfMiddle)
            nextOfMiddle->prev = nullptr;

        // Đệ quy sắp xếp 2 nửa
        typename DLinkedList<T>::Node *left = mergeSortRecursive(head, comparator);
        typename DLinkedList<T>::Node *right = mergeSortRecursive(nextOfMiddle, comparator);

        // Merge 2 nửa đã sắp xếp
        return merge(left, right, comparator);
    }
};

#endif /* DLINKEDLISTSE_H */

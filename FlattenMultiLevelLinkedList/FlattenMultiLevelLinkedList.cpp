// FlattenMultiLevelLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
class ListNode
{
public:
    int data;
    ListNode* next;
    ListNode* down;
    ListNode(int data)
        : data(data)
        , next(nullptr)
        , down(nullptr)
    {}
};

ListNode* GetListFromInput(ListNode** ppHead, int count)
{
    if (count == 0)
        return nullptr;

    std::cout << "Enter " << count << " numbers of the list: ";
    ListNode* pTail = *ppHead;
    for (int i = 0; i < count; ++i)
    {
        int data = 0;
        std::cin >> data;
        if (*ppHead == nullptr)
        {
            *ppHead = new ListNode(data);
            pTail = *ppHead;
        }
        else
        {
            pTail->down = new ListNode(data);
            pTail = pTail->down;
        }
    }

    return pTail;
}

void PrintList(ListNode* pHead)
{
    if (pHead == nullptr)
        return;

    std::cout << pHead->data;
    pHead = pHead->next;

    while (pHead != nullptr)
    {
        std::cout << ", " << pHead->data;
        pHead = pHead->next;
    }
}

void FreeList(ListNode* pNode)
{
    if (pNode == nullptr)
        return;

    FreeList(pNode->next);
    delete pNode;
}

ListNode* GetNodeByIndex(ListNode* pHead, int index)
{
    if (index == -1)
        return nullptr;

    for (int i = 0; i < index; ++i)
    {
        pHead = pHead->next;
    }

    return pHead;
}

ListNode* MergeLists(ListNode* pHead1, ListNode* pHead2)
{
    ListNode* pNewHead = nullptr;

    if (pHead1 == nullptr)
    {
        pNewHead = pHead2;
        pHead2 = pHead2->next;
    }
    else if (pHead2 == nullptr)
    {
        pNewHead = pHead1;
        pHead1 = pHead1->next;
    }
    else
    {
        if (pHead1->data < pHead2->data)
        {
            pNewHead = pHead1;
            pHead1 = pHead1->next;
        }
        else
        {
            pNewHead = pHead2;
            pHead2 = pHead2->next;
        }
    }

    ListNode* pNewTail = pNewHead;

    while (pHead1 != nullptr && pHead2 != nullptr)
    {
        ListNode* pNewCurrent = nullptr;
        if (pHead1->data < pHead2->data)
        {
            pNewTail->next = pHead1;
            pHead1 = pHead1->next;
            pNewTail->down = nullptr;
            pNewTail = pNewTail->next;
        }
        else
        {
            pNewTail->next = pHead2;
            pHead2 = pHead2->next;
            pNewTail->down = nullptr;
            pNewTail = pNewTail->next;
        }
    }

    while (pHead1 != nullptr)
    {
        pNewTail->next = pHead1;
        pHead1 = pHead1->next;
        pNewTail->down = nullptr;
        pNewTail = pNewTail->next;
    }

    while (pHead2 != nullptr)
    {
        pNewTail->next = pHead2;
        pHead2 = pHead2->next;
        pNewTail->down = nullptr;
        pNewTail = pNewTail->next;
    }

    return pNewHead;
}

void ConvertVerticalToHorizontal(ListNode* pNode)
{
    while (pNode != nullptr)
    {
        pNode->next = pNode->down;
        pNode = pNode->next;
    }
}

ListNode* FlattenTheLinkedList(ListNode* pHead)
{
    ListNode* pCurrentNode = pHead;
    pHead = pHead->next;
    ConvertVerticalToHorizontal(pCurrentNode);

    while (pHead != nullptr)
    {
        ListNode* pNextHorizontalNode = pHead->next;
        ConvertVerticalToHorizontal(pHead);
        pCurrentNode = MergeLists(pCurrentNode, pHead);
        pHead = pNextHorizontalNode;
    }

    return pCurrentNode;
}

int main()
{
    while (true)
    {
        int count = 0;
        std::cout << "Number of vertical lists: ";
        std::cin >> count;
        if (count <= 0)
            break;

        ListNode* pHead = nullptr;
        ListNode* pCurrentHorizontal = nullptr;
        for (int i = 0; i < count; ++i)
        {
            std::cout << "Number of elements in the " << (i + 1) << "th list: ";
            int numOfElements = 0;
            std::cin >> numOfElements;
            ListNode* pNode = nullptr;
            GetListFromInput(&pNode, numOfElements);
            if (pHead == nullptr && pNode != nullptr)
                pHead = pNode;   
            if (pCurrentHorizontal == nullptr)
                pCurrentHorizontal = pHead;
            else
            {
                pCurrentHorizontal->next = pNode;
                pCurrentHorizontal = pCurrentHorizontal->next;
            }
        }

        pHead = FlattenTheLinkedList(pHead);

        std::cout << "The flattered linked list is: ";
        PrintList(pHead);
        std::cout << std::endl;

        FreeList(pHead);
    }
}

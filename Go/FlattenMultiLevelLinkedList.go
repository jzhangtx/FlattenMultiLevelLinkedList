package main

import (
	"fmt"
	"strconv"
)

type ListNode struct {
	data int
	next *ListNode
	down *ListNode
}

func GetArrayFromInput(count int, prompt string) []int {
	if count == 0 {
		return []int{}
	}

	fmt.Print(prompt)

	v := make([]int, count)
	for i := 0; i < count; i++ {
		fmt.Scan(&v[i])
	}

	return v
}

func GetDownListFromArray(v []int) (*ListNode, *ListNode) {
	if len(v) == 0 {
		return nil, nil
	}

	if len(v) == 1 {
		pNode := &ListNode{v[0], nil, nil}
		return pNode, pNode
	}

	pHead := &ListNode{v[0], nil, nil}
	pCur := pHead
	for i := 1; i < len(v); i++ {
		pCur.down = &ListNode{v[i], nil, nil}
		pCur = pCur.down
	}

	return pHead, pCur
}

func (pNode *ListNode) Print() {
	fmt.Print(pNode.data)
	if pNode.next != nil {
		fmt.Print(", ")
	}
	if pNode.next != nil {
		pNode.next.Print()
	} else {
		fmt.Println("")
	}
}

func GetNodeByIndex(head *ListNode, index int) *ListNode {
	for i := 0; i < index; i++ {
		head = head.next
	}

	return head
}

func CountListMoveToTail(head *ListNode) (int, *ListNode) {
	count := 1
	for ; head.next != nil; head = head.next {
		count++
	}

	return count, head
}

func MergeDownList(pList, pDownList *ListNode) *ListNode {
	pHead := pList
	if pList == nil || pList.data > pDownList.data {
		pHead = pDownList
		pDownList = pDownList.down
		pHead.down = nil
	} else {
		pList = pList.next
	}

	pCur := pHead
	for pList != nil && pDownList != nil {
		if pList.data < pDownList.data {
			pCur.next = pList
			pList = pList.next
		} else {
			pCur.next = pDownList
			pDownList = pDownList.down
			pCur.down = nil
		}
		pCur = pCur.next
	}

	for pList != nil {
		pCur.next = pList
		pList = pList.next
		pCur = pCur.next
	}

	for pDownList != nil {
		pCur.next = pDownList
		pDownList = pDownList.down
		pCur.down = nil
		pCur = pCur.next
	}

	return pHead
}

func FlattenTheLinkedList(root *ListNode) *ListNode {
	var pHead *ListNode = nil
	for pNode := root; pNode != nil; {
		pNext := pNode.next
		pHead = MergeDownList(pHead, pNode)
		pNode = pNext
	}

	return pHead
}

func main() {
	for {
		fmt.Print("Number of vertical lists: ")
		var count int
		fmt.Scan(&count)
		if count == 0 {
			break
		}

		sizes := GetArrayFromInput(count, "Please enter the sizes of the vertical lists: ")
		var pRoot *ListNode = nil
		var pCur *ListNode = nil
		for i := 0; i < count; i++ {
			prompt := "Please enter the "
			prompt += strconv.Itoa(i)
			prompt += "th list: "
			vec := GetArrayFromInput(sizes[i], prompt)
			pVer, _ := GetDownListFromArray(vec)
			if pRoot == nil {
				pRoot = pVer
				pCur = pRoot
			}
			pCur.next = pVer
			pCur = pCur.next
		}

		pRoot = FlattenTheLinkedList(pRoot)
		fmt.Print("The flattened list: ")
		pRoot.Print()
	}
}

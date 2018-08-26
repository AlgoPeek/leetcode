// Source: https://leetcode.com/problems/copy-list-with-random-pointer/description/
// Author: Diego Lee
// Date: 2018-08-26
//
// Description:
// A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
//
// Return a deep copy of the list.

#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>

// Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution
{
    public:
        RandomListNode *copyRandomList(RandomListNode *head)
        {
            std::unordered_map<RandomListNode*, RandomListNode*> hash;

            RandomListNode fakeHead(0);
            RandomListNode* copyCurr = &fakeHead;
            RandomListNode* curr = head;
            while (curr != NULL)
            {
                if (hash.find(curr) != hash.end())
                {
                    copyCurr->next = hash[curr];
                }
                else
                {
                    copyCurr->next = new RandomListNode(curr->label);
                }
                copyCurr = copyCurr->next;

                if (curr->random != NULL)
                {
                    copyCurr->random = new RandomListNode(curr->random->label);
                    hash[curr->random] = copyCurr->random;
                }
                curr = curr->next;
            }
            return fakeHead.next;
        }
};

RandomListNode* buildRandomList(const std::vector<int>& labels)
{
    RandomListNode fakeHead(0);
    RandomListNode* curr = &fakeHead;
    for (auto label : labels)
    {
        curr->next = new RandomListNode(label);
        curr = curr->next;
    }
    return fakeHead.next;
}

bool checkEqual(RandomListNode* head1, RandomListNode* head2)
{
    RandomListNode* curr1 = head1;
    RandomListNode* curr2 = head2;
    while (curr1 != NULL
            && curr2 != NULL
            && curr1->label == curr2->label)
    {
        int rand1 = 0;
        int rand2 = 0;
        if (curr1->random)
        {
            rand1 = curr1->random->label;
        }
        if (curr2->random)
        {
            rand2 = curr2->random->label;
        }
        if (rand1 != rand2)
        {
            return false;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return (curr1 == NULL && curr2 == NULL);
}

void testCopyRandomList()
{
    std::vector<int> labels = {1, 2, 3};
    RandomListNode* head = buildRandomList(labels);
    head->random = head->next->next;

    Solution s;
    RandomListNode* copyHead = s.copyRandomList(head);
    assert(copyHead != NULL);
    assert(checkEqual(head, copyHead));
}

int main()
{
    testCopyRandomList();
    return 0;
}

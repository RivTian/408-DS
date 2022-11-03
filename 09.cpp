#include<ds.h>
using namespace std;

/**
 * 创建一个带有头结点的链表并返回
 **/
List9 create_list9(const std::vector<ElemType> &data) {
    if (data.empty()) return NULL;

    auto *head = (Node9 *) malloc(sizeof(Node9));
    head->link = NULL;

    Node9 *p = head;
    for (auto i : data) {
        auto *cur = (Node9 *) malloc(sizeof(Node9));
        cur->data = i;
        cur->link = NULL;
        p->link = cur;
        p = cur;
    }

    return head;
}

/**
 * bf(Bruce Force)
 * 首先扫描出链表长度 len，然后重新向后扫描 len - k 个节点
 * */
int search_k_bf(List9 list, int k) {
    int len = 0;
    Node9 *p = list->link;
    while (p != NULL) {
        p = p->link;
        len += 1;
    }

    if (len < k) return 0;

    int cnt = len - k;
    p = list->link;
    while (cnt --) {
        p = p->link;
    }
    cout << p->data << "\n";
    return 1;
}

/**
 * 最优解不一定是真正的最优，只是符合评判标准的满分
 * 双指针, 一个指针先走 k 步，然后同步走，直到前者走到终点
 * */
int search_k(List9 list, int k) {
    Node9 *p1 = list->link, *p2  = list->link;
    int cnt = 0 ;
    while (p1 != NULL) {
        if (cnt < k) cnt += 1 ;
        else
            p2 = p2->link;
        p1 = p1->link;
    }

    if (cnt < k) return 0;
    cout << p2->data << "\n";
    return 1;
}
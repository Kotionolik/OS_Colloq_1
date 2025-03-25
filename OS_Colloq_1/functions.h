#pragma once
#include <iostream>
#include <vector>
#include <unordered_set>
#include <stdexcept>
#include <memory>
#include <type_traits>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

std::vector<unsigned long long> generateFactorials(int n) {
    if (n < 0) throw std::invalid_argument("n must be non-negative");
    if (n > 20) throw std::overflow_error("n > 20 causes overflow");
    std::vector<unsigned long long> result;
    unsigned long long fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact *= i;
        result.push_back(fact);
    }
    return result;
}

template <typename T>
std::vector<T> removeDuplicates(const std::vector<T>& input) {
    static_assert(std::is_arithmetic<T>::value, "Only numeric types are allowed for the function");
    std::unordered_set<T> seen;
    std::vector<T> result;
    for (const auto& item : input) {
        if (seen.insert(item).second) {
            result.push_back(item);
        }
    }
    return result;
}

Node* reverseLinkedList(Node* head) {
    if (!head || !head->next) return head;
    Node* new_head = reverseLinkedList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return new_head;
}

void freeList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

Node* createList(const std::vector<int>& values) {
    if (values.empty()) return nullptr;
    Node* head = new Node(values[0]);
    Node* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new Node(values[i]);
        current = current->next;
    }
    return head;
}

std::vector<int> listToVector(Node* head) {
    std::vector<int> result;
    while (head) {
        result.push_back(head->data);
        head = head->next;
    }
    return result;
}

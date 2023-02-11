#pragma once

#include <exception>

template<typename T>
class List {
    struct Node {
        T data;
        Node* next;
        Node* prev;

        Node(const T& data, Node* next, Node* prev) : data(data), next(next), prev(prev) {}
        Node(T&& data, Node* next, Node* prev) : data(std::move(data)), next(next), prev(prev) {}
    };

public:
    List() = default;
    ~List() {
        while (head_) {
            pop_front();
        }
    }

    void push_back(const T& value) {
        Node* new_node = new Node(value, nullptr, tail_);
        if (tail_) {
            tail_->next = new_node;
        } else {
            head_ = new_node;
        }
        tail_ = new_node;
        ++list_size_;
    }

    void push_back(T&& value) {
        Node* new_node = new Node(std::move(value), nullptr, tail_);
        if (tail_) {
            tail_->next = new_node;
        } else {
            head_ = new_node;
        }
        tail_ = new_node;
        ++list_size_;
    }

    void pop_back() {
        if (empty()) {
            throw std::runtime_error("List is empty");
        }

        Node* oldTail = tail_;
        tail_ = tail_->prev;
        if (tail_) {
            tail_->next = nullptr;
        } else {
            head_ = nullptr;
        }
        delete oldTail;
        --list_size_;
    }

    void push_front(const T& value) {
        Node* new_node = new Node(value, head_, nullptr);
        if (head_) {
            head_->prev = new_node;
        } else {
            tail_ = new_node;
        }
        head_ = new_node;
        ++list_size_;
    }

    void push_front(T&& value) {
        Node* new_node = new Node(std::move(value), head_, nullptr);
        if (head_) {
            head_->prev = new_node;
        } else {
            tail_ = new_node;
        }
        head_ = new_node;
        ++list_size_;
    }

    void pop_front() {
        if (empty()) {
            throw std::runtime_error("List is empty");
        }
        Node* old_head = head_;
        head_ = head_->next;
        if (head_) {
            head_->prev = nullptr;
        } else {
            tail_ = nullptr;
        }
        delete old_head;
        --list_size_;
    }

    [[nodiscard]] size_t size() const noexcept {
        return list_size_;
    }

    [[nodiscard]] bool empty() const noexcept {
        return list_size_ == 0;
    }

    T& front() {
        return head_->data;
    }

    const T& front() const {
        return head_->data;
    }

    T& back() {
        return tail_->data;
    }

    const T& back() const {
        return tail_->data;
    }

    void insert(Node* node, const T& value) {
        if (node == head_) {
            push_front(value);
        } else if (node == nullptr) {
            push_back(value);
        } else {
            Node* new_node = new Node(value, node, node->prev);
            node->prev->next = new_node;
            node->prev = new_node;
            ++list_size_;
        }
    }

    void insert(size_t idx, const T& value) {
        if (idx >= list_size_) {
            throw std::runtime_error("Index out of range");
        }
        Node* node = head_;
        for (size_t i = 0; i < idx; ++i) {
            node = node->next;
        }
        insert(node, value);
    }

    const T& operator[](size_t index) const {
        if (index >= list_size_) {
            throw std::runtime_error("Index out of range");
        }
        Node* node = head_;
        for (size_t i = 0; i < index; ++i) {
            node = node->next;
        }
        return node->data;
    }

    T& operator[](size_t index) {
        if (index >= list_size_) {
            throw std::runtime_error("Index out of range");
        }
        Node* node = head_;
        for (size_t i = 0; i < index; ++i) {
            node = node->next;
        }
        return node->data;
    }

    void erase(Node* node) {
        if (node == head_) {
            pop_front();
        } else if (node == tail_) {
            pop_back();
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            delete node;
            --list_size_;
        }
    }

    void erase(size_t idx) {
        if (idx >= list_size_) {
            throw std::runtime_error("Index out of range");
        }
        Node* node = head_;
        for (size_t i = 0; i < idx; ++i) {
            node = node->next;
        }
        erase(node);
    }

private:
    Node* head_ = nullptr;
    Node* tail_ = nullptr;
    size_t list_size_ = 0;
};

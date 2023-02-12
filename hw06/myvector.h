#pragma once

template<typename T>
class Vector {
public:
    Vector() : m_data(new T[m_capacity]) {}

    ~Vector() {
        delete[] m_data;
    }

    Vector(const Vector<T>& other) : m_size(other.m_size), m_capacity(other.m_capacity), m_data(new T[m_capacity]) {
        for (int i = 0; i < m_size; ++i) {
            m_data[i] = other.m_data[i];
        }
    }

    Vector<T>& operator=(const Vector<T>& other) {
        if (this != &other) {
            m_size = other.m_size;
            m_capacity = other.m_capacity;
            delete[] m_data;
            m_data = new T[m_capacity];
            for (int i = 0; i < m_size; ++i) {
                m_data[i] = other.m_data[i];
            }
        }
        return *this;
    }

    void push_back(const T& value) {
        if (m_size == m_capacity) {
            resize();
        }
        m_data[m_size++] = value;
    }

    void pop_back() {
        --m_size;
    }

    [[nodiscard]] size_t size() const {
        return m_size;
    }

    [[nodiscard]] bool empty() const {
        return m_size == 0;
    }

    T& operator[](int index) {
        return m_data[index];
    }

    const T& operator[](int index) const {
        return m_data[index];
    }

    void erase(size_t idx) {
        if (idx >= m_size) {
            throw std::runtime_error("Index out of range");
        }
        for (size_t i = idx; i < m_size - 1; ++i) {
            m_data[i] = m_data[i + 1];
        }
        --m_size;
    }

    void insert(size_t idx, const T& value) {
        if (idx >= m_size) {
            if (idx == 0) {
                push_back(value);
                return;
            }
            throw std::runtime_error("Index out of range");
        }
        if (m_size == m_capacity) {
            resize();
        }
        for (size_t i = m_size; i > idx; --i) {
            m_data[i] = m_data[i - 1];
        }
        m_data[idx] = value;
        ++m_size;
    }

    void push_front(const T& value) {
        insert(0, value);
    }

private:
    size_t m_size = 0;
    size_t m_capacity = 1;
    T* m_data;

    void resize() {
        m_capacity *= 2;
        T* newData = new T[m_capacity];
        for (size_t i = 0; i < m_size; ++i) {
            newData[i] = m_data[i];
        }
        delete[] m_data;
        m_data = newData;
    }
};

#pragma once

template <typename Node, typename Traits>
class GenericIterator {
public:
    using NodeType = Node;

    GenericIterator(NodeType* start = nullptr)
        : current(start) {
    }

    bool Empty() const {
        return current == nullptr ;
    }

    auto& operator*() const {
        return Traits::data(current);
    }

    auto* operator->() const {
        return &(Traits::data(current));
    }

    GenericIterator& operator++() {
        if (current)
            current = Traits::next(current);
        return *this;
    }

    GenericIterator operator++(int) {
        GenericIterator temp = *this;
        ++(*this);
        return temp;
    }

    bool operator==(const GenericIterator& other) const {
        return current == other.current;
    }

    bool operator!=(const GenericIterator& other) const {
        return current != other.current;
    }

    NodeType* GetNode() const { return current; }

private:
    NodeType* current;
};

#include <iostream>
#include <assert.h>
#include "List.h"
#include "Arr.cpp"

using namespace std;

template <typename E>
class LL : public List<E> {
    Arr<E> Value;
    Arr<int> Link;
    int head; // position of the first element in Value and Link array
    int curr; // position of the current element in Value and Link array

    void updateLink(int oldVal, int newVal) {
        int pos = Link.Search(oldVal);
        assert(pos != -1); // this value must be present
        Link.moveToPos(pos); // Link is now here
        assert(Link.remove() == oldVal);
        Link.insert(newVal);
        assert(Link.getValue() == newVal);
    }

public:
    LL() {

    }

    LL(List<E> *L) {
        for (int i = 0; i < L->length(); i++) {
            append(L->getValue());
            L->next();
        }
    }

    ~LL() {
        clear();
    }

    void clear() {
        Value.clear();
        Link.clear();
    }

    void insert(const E &item) {
		if (length() == 0) {
            append(item);
            return;
		}
		Value.append(item);
		Link.append(curr);
		updateLink(curr, Link.length()-1);
		curr = Link.length()-1;
    }

    void append(const E &item) {
        Value.append(item);
        Link.append(-1);
        if (length() == 1) {
            // this is the first element
            head = curr = 0;
        }
        else {
            updateLink(-1, Link.length()-1);
        }
    }

    // Remove and return the current element
    E remove() {
        Value.moveToPos(curr);
        Link.moveToPos(curr);
        E ret = Value.remove();
        int newVal = Link.remove();
        if (newVal > curr) newVal--;
        updateLink(curr, newVal);

        for (int i = 0; i < Link.length(); i++) {
            Link.moveToPos(i);
            int val = Link.getValue();
            if (val > curr) {
                updateLink(val, val-1);
            }
        }
        if (curr == head) head = newVal;
        curr = newVal;
        return ret;
    }

    void moveToStart() {
        curr = head;
    }

    // point to last element
    void moveToEnd() {
        curr = Link.Search(-1);
    }

    void prev() {
        if (curr == head) return;
        curr = Link.Search(curr);
    }

    // allows traversal up to size position (n)
    void next() {
        Link.moveToPos(curr);
        if (Link.getValue() == -1) return;
        curr = Link.getValue();
    }

    int length() {
        assert(Value.length() == Link.length());
        return Value.length();
	}

    int currPos() {
        if (curr == head) return 0;
        Link.moveToPos(head);
        int i = 1;
        for (; Link.getValue() != curr; i++) {
            Link.moveToPos(Link.getValue());
        }
        return i;
    }

    void moveToPos(int pos) {
        assert(pos >= 0 && pos < length());
        curr = head;
        Link.moveToPos(curr);
        for (int i = 0; i < pos; i++) {
            curr = Link.getValue();
            Link.moveToPos(curr);
        }
    }

    E getValue() {
        Value.moveToPos(curr);
        return Value.getValue();
    }

    // returns the position of the element item or -1 if not found
    int Search(const E &item) {
        Link.moveToPos(head);
        Value.moveToPos(head);
        for (int i = 0; i < length(); i++) {
            if (Value.getValue() == item) {
                return i;
            }
            if (Link.getValue() == -1) break;
            Value.moveToPos(Link.getValue());
            Link.moveToPos(Link.getValue());
        }
        return -1;
    }
};


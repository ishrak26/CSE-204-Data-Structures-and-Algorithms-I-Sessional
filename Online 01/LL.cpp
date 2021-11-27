#include <iostream>
#include <assert.h>
#include "List.h"
#include "Arr.cpp"

using namespace std;

template <typename E>
class LL : public List<E> {
    Arr<E> Value;
    Arr<int> Link;
    int head_pos;
    int curr;

    void changeCurrentLinkValue(int val) {
		// change to val
		Link.remove();
		Link.insert(val);
//		cerr << "val changed\n";
    }

    void init() {
		head_pos = curr = 0;
    }

public:
    LL() {
		init();
    }

    LL(List<E> *L) {
        init();
//        cerr << Link.length() << "\n"; // ok
//        cerr << Value.length() << "\n"; // ok
//        exit(1);
        int tmp = L->currPos();
//        cerr << "tmp is " << tmp << "\n";
//        exit(1);
        for (int i = 0; i < L->length(); i++) {
			append(L->getValue());
			L->next();
        }
//        cerr << "loop traversal done\n";
//        exit(1);
//        for (L->moveToStart(); L->currPos() < L->length(); L->next())) {
//            append(L->getValue());
//            cerr << "appended\n";
//        }
        L->moveToPos(tmp);
    }

    ~LL() {
        clear();
    }

    void clear() {
        Value.clear();
        Link.clear();
    }

    void insert(const E &item) {
		if (Value.length() == 0) {
			append(item);
			return;
		}
		Value.append(item);
		int pos = Link.Search(curr);
		assert(pos != -1);
		// change this value
		Link.moveToPos(pos);
		Link.remove();
		Link.insert(Link.length());
		Link.append(curr);
		curr = Link.length()-1;
    }

    void append(const E &item) {
        Value.append(item);
        Link.append(-1);
//        cerr << "Value link\n";
        if (Value.length() > 1) {
			// change previous pointer
			assert(Link.Search(-1) != -1);
			Link.moveToPos(Link.Search(-1));
			changeCurrentLinkValue(Link.length()-1);
        }
        else {
			// this is the first element
			head_pos = 0;
			curr = 0;
        }
    }

    // Remove and return the current element
    E remove() {
        assert(Value.length()); // length not zero
        Value.moveToPos(curr);
        Link.moveToPos(curr);
        E item = Value.remove();
        int prev = Link.Search(curr); // position of the prev element
        changeCurrentLinkValue(Link.remove());
        // every position which is greater than curr will be decremented by 1
        for (Link.moveToStart(); Link.currPos() < Link.length(); Link.next()) {
			if (Link.getValue() > curr) {
				changeCurrentLinkValue(Link.getValue() - 1);
			}
        }
    }

    void moveToStart() {
        curr = head_pos;
    }

    // point to last element
    void moveToEnd() {
        assert(length() > 0);
        curr = Link.Search(-1);
    }

    void prev() {
        if (curr == head_pos) return;

    }

    // allows traversal up to size position (n)
    void next() {
        Link.moveToPos(curr);
        int val = Link.getValue();
        if (val != -1) curr = val;
    }

    int length() {
		assert(Value.length() == Link.length());
		return Value.length();
	}

    int currPos() { return curr; }

    void moveToPos(int pos) {
        assert(pos >= 0 && pos <= length());
		curr = head_pos;
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
        return Value.Search(item);
    }
};


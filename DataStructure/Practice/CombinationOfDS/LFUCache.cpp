#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    pair<int, int> data;
    Node* next;
    Node* prev;

    Node(int key, int value) {
        data = {key, value};
        next = prev = nullptr;
    }
};

class DoublyLinkedList {

    Node* head;
    Node* tail;
    unordered_map<int, Node*> track;

public:
    DoublyLinkedList() {
        head = tail = nullptr;
    }

    void insertAtHead(int key, int value) {
        Node* newNode = new Node(key, value);
        track[key] = newNode;

        if(head == nullptr) {
            head = tail = newNode;
        } 
        else {
            newNode -> next = head;
            head -> prev = newNode;
            head = newNode;
        }
    }

    void deleteNode(int key) {
        Node* node = track[key];
        if(node == head) {
            // If the node is head
            deleteHead();
            return;
        }

        if(node == tail) {
            // Node is tail
            deleteTail();
            return;
        }
        track.erase(track.find(key));

        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;
        node -> prev = node -> next = nullptr;
        delete(node);
    }

    void deleteHead() {
        Node* temp = head;
        track.erase(track.find(head -> data.first));
        if(head -> next != nullptr) {
            head -> next -> prev = nullptr;
        }
        head = temp -> next;
        temp -> next = nullptr;

        delete(temp);
    }

    void deleteTail() {
        Node* temp = tail;
        if(temp == head) {
            deleteHead();
            return;
        }
        track.erase(track.find(tail -> data.first));
        tail = temp -> prev;
        temp -> prev -> next = nullptr;
        temp -> prev = nullptr;
        delete(temp);
    }

    bool isEmpty() {
        return head == nullptr;
    }

    int getTailKey() {
        if(tail == nullptr) {
            return -1;
        }
        return tail -> data.first;
    }

    void display() {
        Node* trav = head;
        while(trav != nullptr) {
            cout << "{" <<  trav -> data.first << ", " << trav -> data.second << "} "; 
            trav = trav -> next;
        }
        cout << '\n';
    }
};


class LFUCache {
public:
    int mxSize;
    unordered_map<int, pair<int, int>> mp;
    map<int, DoublyLinkedList> leastFrequent;

    LFUCache(int capacity) {
        mxSize = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()) {
            leastFrequent[mp[key].second].deleteNode(key);

            if(leastFrequent[mp[key].second].isEmpty()) {
                leastFrequent.erase(leastFrequent.find(mp[key].second));
            }

            mp[key].second++;
            leastFrequent[mp[key].second].insertAtHead(key, mp[key].first);
            return mp[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {

        // If we still have capacity
        if(mp.size() < mxSize) {
            if(mp.find(key) != mp.end()) {
                // key is already present
                leastFrequent[mp[key].second].deleteNode(key);

                if(leastFrequent[mp[key].second].isEmpty()) {
                    leastFrequent.erase(leastFrequent.find(mp[key].second));
                }
                mp[key].first = value;
                mp[key].second++;
                leastFrequent[mp[key].second].insertAtHead(key, value);
            }
            else {
                // Key is not present
                mp[key] = {value, 1};
                leastFrequent[1].insertAtHead(key, value);
            }
        }
        // Capacity is full
        else {
            if(mp.find(key) != mp.end()) {
                // key is already present
                leastFrequent[mp[key].second].deleteNode(key);

                if(leastFrequent[mp[key].second].isEmpty()) {
                    leastFrequent.erase(leastFrequent.find(mp[key].second));
                }
                mp[key].first = value;
                mp[key].second++;
                leastFrequent[mp[key].second].insertAtHead(key, value);
                
            }
            else {
                // Key is not present
                mp.erase(mp.find(leastFrequent.begin() -> second.getTailKey())); // Delete from map
                leastFrequent.begin() -> second.deleteTail(); // Delete the least frequent and least recent data
                mp[key] = {value, 1}; // Insert new one
                leastFrequent[1].insertAtHead(key, value); // update in recent
            }

        }
    }

    void display() {
        cout << "Map to store the key and value: " << '\n';

        cout << "Key\tValue\n";
        for(auto it: mp) {
            cout << it.first << "\t" << it.second.first << "\n";
        }

        cout << "\nMap to store the LFU: \n";

        for(auto it: leastFrequent) {
            cout << "Frequency: " << it.first << " ->\n";
            it.second.display();
        } 
    }
};

int main() {
    LFUCache *lfu = new LFUCache(2);
    lfu -> put(3, 1);
    lfu -> put(2, 1);
    lfu -> put(2, 2);
    lfu -> put(4, 4);
    cout << lfu -> get(2);
    lfu -> display();
}
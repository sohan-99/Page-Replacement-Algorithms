#include <bits/stdc++.h> 
using namespace std; 
int pageFaults(vector<int> &pages, int capacity) { 
    unordered_set<int> s; 
    unordered_map<int, int> indexes; 
    int page_faults = 0; 
    for (int i = 0; i < pages.size(); i++) { 
        if (s.size() < capacity) { 
            if (s.find(pages[i]) == s.end()) { 
                s.insert(pages[i]); 
                page_faults++; 
            } 
            indexes[pages[i]] = i; 
        } else { 
            if (s.find(pages[i]) == s.end()) { 
                int lru = INT_MAX, val; 
                for (auto it = s.begin(); it != s.end(); it++) { 
                    if (indexes[*it] < lru) { 
                        lru = indexes[*it]; 
                        val = *it; 
                    } 
                } 
                s.erase(val); 
                s.insert(pages[i]); 
                page_faults++; 
            } 
            indexes[pages[i]] = i; 
        } 
    } 
    return page_faults; 
}
int main() { 
    int n, capacity;
    cout << "Enter the number of pages: ";
    cin >> n;
    vector<int> pages(n);
    cout << "Enter the page sequence: ";
    for (int i = 0; i < n; ++i) {
        cin >> pages[i];
    }
    cout << "Enter the capacity of cache: ";
    cin >> capacity;
    cout << "Number of page faults: " << pageFaults(pages, capacity) << endl;
    return 0; 
}

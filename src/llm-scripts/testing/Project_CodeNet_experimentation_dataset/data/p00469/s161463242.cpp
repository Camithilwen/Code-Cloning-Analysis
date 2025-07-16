/* 駄実装の典型 皆さんはstackではなくてn進法を使いましょう */
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <set>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    while (1) {
        int n;
        int k;
        vector<string> element_strings;
        set<string> generated_strings;
        deque<int> stack;
    
        scanf("%d", &n);
        scanf("%d", &k);
    
        if (n == 0 && k == 0) return 0;
 
        for (int i=0; i<n; i++) {
            char number[3];
            scanf("%s", number);
            element_strings.push_back(string(number));
        }
    
        sort(element_strings.begin(), element_strings.end());
    
        while (1) {
            char has_appeared[11];
            char not_count = 0;
            string new_string = "";
            int next_ind;
    
            while (stack.size() != k) {
                stack.push_back(0);
            }

            memset(has_appeared, 0, sizeof(has_appeared));

            for (deque<int>::iterator itr=stack.begin(); itr != stack.end(); itr++) {
                if (has_appeared[*itr]) {
                    not_count = 1;
                    break;
                }
                has_appeared[*itr] = 1;
                new_string += element_strings[*itr];
            }

            if (!not_count && generated_strings.count(new_string) == 0) { 
                generated_strings.insert(new_string);
            }
    
            while (!stack.empty() && stack.back() == element_strings.size()-1) {
                stack.pop_back();
            }
    
            if (stack.empty()) {
                break;
            }
    
            next_ind = stack.back() + 1;
            stack.pop_back();
            stack.push_back(next_ind);
        }
    
        printf("%lu\n", generated_strings.size());
    }
}
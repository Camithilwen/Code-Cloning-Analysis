#include <iostream>
#include <cmath>
#include <map>
#include <set>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    map<pair<int, int>, set<int>> pair_index;
    for(int i=0; i<n; i++){
        double x;
        int pow2=0, pow5=0;
        unsigned long long val;
        scanf("%lf", &x);
        val=llround(x*1e9);
        while(val%2==0){
            pow2++;
            val/=2;
        }
        while(val%5==0){
            pow5++;
            val/=5;
        }
        pair_index[*new pair(pow2, pow5)].insert(i);
    }
    unsigned long long counter=0;
    for(auto i=pair_index.begin(); i!=pair_index.end(); i++){
        for(auto j=i; j!=pair_index.end(); j++){
            if(min(i->first.first+j->first.first, i->first.second+j->first.second)>=18){
                if(i==j){
                    counter+=i->second.size()*(j->second.size()-1)/2;
                }else if(*i<*j){
                    counter+=(i->second.size()*j->second.size());
                }
            }
        }
    }
    printf("%llu\n", counter);
    return 0;
}

/*Logic:
 * Since floating points are stored as approximate value.
 * Direct multiplication will result in some anomaly.
 * To avoid that we multiplied the given floating point or regular number
 * with 10^9, because the highest number of digits after decimal is 9.
 * This will make the numbers to be in the form
 * number/10^9.
 * Now, if we multiply say (x/10^9 * y/10^9) then we get
 * xy/10^18.
 * To get an integer, all we have to do is cancel out the denominator.
 * So xy has be z*(10^(>=9)).
 * Now we also know that 10^p is basically (2^p)*(5^p).
 * Here, p has to be equal to or greater that 9.
 *
 * Now, comes to the problem of handling TLE.
 * Since the dataset is 2*10^6 and 2 sec, regular brute force gave me TLE.
 * So in order to handle that a map with key (2^p)*(5^q) where p varies and q varies
 * and as value stores the indices of where key was found.
 * Now, for any pair of keys min(p1+p2, q1+q2) >=18, then all we multiply the number
 * of values from the keys.
 * If for the same key min(p1+p1, q1+q1) >=18, then all possible combinations are required.
 * Thus number of values*(number of values-1)/2.
 * Summation of all of these results in the answer.
 */
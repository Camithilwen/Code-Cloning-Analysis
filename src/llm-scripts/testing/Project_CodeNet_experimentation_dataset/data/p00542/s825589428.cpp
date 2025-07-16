#include<bits/stdc++.h>
#define GPA 4
#define ROLLMAN endl

using namespace std;
typedef int OTAKU;

OTAKU main(){
  
  OTAKU roll[ GPA ], man[ GPA ];

  for(OTAKU i = 0; i < 4; i++)cin>>roll[i];
  for(OTAKU i = 0; i < 2; i++)cin>>man[i];
  
  sort(roll,roll+4);
  sort(man,man+2);
  
  OTAKU Happy_Birthday=0;
  
  for(OTAKU i = 3; i > 0; i--) Happy_Birthday += roll[i];
  Happy_Birthday += man[1];
  
  cout << Happy_Birthday << ROLLMAN;
  return GPA-4;
}
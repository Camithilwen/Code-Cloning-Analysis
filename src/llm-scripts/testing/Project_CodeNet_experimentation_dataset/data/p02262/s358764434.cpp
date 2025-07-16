#include <iostream>
#include <vector>
#include <cmath>

template<typename T>
auto print(std::vector<T> array,bool reverse = false) 
 -> void{
 	if(reverse){
		auto iterator = array.rbegin();
		std::cout<<*iterator;
		iterator++;
		for(;iterator != array.rend();++iterator){
			std::cout<<" "<< *iterator;
		}

	}else{
		auto iterator = array.begin();
		std::cout<<*iterator;
		iterator++;
		for(;iterator != array.end();++iterator){
			std::cout<<" "<< *iterator;
		}
	}
	std::cout<<"\n";
}

template<typename T>
auto println(std::vector<T> array) 
 -> void{
	for(auto v : array){
		std::cout<< v <<"\n";
	}
}

int cnt = 0;

template<typename T>
auto insertionSort(std::vector<T> *A,int n,int g)
 -> void{
 	for(int i = g;i < n;i++){
 		auto v = (*A)[i];
 		auto j = i - g;
 		while(j >= 0 && (*A)[j] > v){
 			(*A)[j+g] = (*A)[j];
 			j = j - g;
 			cnt++;
 		}
 		(*A)[j+g] = v;
 	}
 }

template<typename T>
auto shellSort(std::vector<T> *A,int n)
 -> void{
 	cnt = 0;

 	int h = 0;
 	std::vector<int> G;
    for(int k = 1;;k++){
    	h = static_cast<int>((pow(3,k)-1)/2);
    	if(h > n)
    		break;
    	G.push_back(h);
    }

 	std::cout<< G.size() <<std::endl;
 	print(G, true);

 	for(auto it = G.rbegin();it != G.rend();++it){
 		insertionSort<T>( A, n, (*it));
 	}

 }

auto main()
 -> int{

	std::cin.tie(0);
	std::ios_base::sync_with_stdio(false);

	int n;
	std::cin>>n;

	std::vector<int> array(n);
	for(int i=0;i < n;i++)
		std::cin>>array[i];

	shellSort( &array, n);

 	std::cout<< cnt <<"\n";
	println(array);

	return 0;
}
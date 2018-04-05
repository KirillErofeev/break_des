#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <tuple>

template<class T>
void print(T a){
	for(auto v : a)
		std::cout << v << std::endl;
}

template<class T>
struct iter_out_functor
{
		T operator()(T v){
			std::cout << v << std::endl;
			return v;
		}
};

template<class T>
void print(T l, T r){
	iter_out_functor<typename std::iterator_traits<T>::value_type > iter_out;
	std::transform(l, r, l, iter_out);
}

template<class T, class F>
void print(T itr, F f){ 
	for (auto begin = itr.begin(), end = itr.end(); 
		begin != end; ++begin) { 
		std::cout << f(*begin) << std::endl;
	}
}

typedef uint64_t T;
typedef int _13bit_t;
const T ONE = 1;

const T NUM_KEY_EFFICIENT_BITS = 8; //(T)1 << 12;
const T N   = (T)1 << 43;

T magnitude(T a){
	if(a >= N/2)
		return a - N/2;
	return N/2 - a;
}

struct{
	bool operator()(T a, T b){
		return magnitude(a) > magnitude(b);
	}
} effective;

void rearrange(T* KA, T* KB){
	std::sort(KA, KA + NUM_KEY_EFFICIENT_BITS, effective);	
	std::sort(KB, KB + NUM_KEY_EFFICIENT_BITS, effective);
}

void crush(T* KA, T* KB){
	std::vector<std::tuple<_13bit_t, _13bit_t, T>> likely_k26(NUM_KEY_EFFICIENT_BITS*NUM_KEY_EFFICIENT_BITS);
	for(int i = 0; i < NUM_KEY_EFFICIENT_BITS; ++i)
		for(int j = 0; j < NUM_KEY_EFFICIENT_BITS; ++j)
			likely_k26[i*NUM_KEY_EFFICIENT_BITS + j] = make_tuple(i, j, (magnitude(KA[i])+1)*(magnitude(KB[j])+1));
	
	struct{
		bool operator()(std::tuple<_13bit_t, _13bit_t, T> a, std::tuple<_13bit_t, _13bit_t, T> b){
			return std::get<2>(a) > std::get<2>(b);			
		}
	} joint_reliability;

	std::sort(likely_k26.begin(), likely_k26.end(), joint_reliability);

	std::cout << std::endl;
	struct{} get_functor;
	print(likely_k26, std::get<2, _13bit_t, _13bit_t, T>);
}


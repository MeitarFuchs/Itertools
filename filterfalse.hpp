#include <iostream>
#include <vector>
#include <string>
using namespace std;
namespace itertools{

    template<typename FUNC, typename CONT>
    auto filterfalse(FUNC func, CONT container){

        vector<decltype(typename CONT::value_type())> ansV; // to know what is the type of the ans vector

        for( decltype(typename CONT::value_type()) curr : container ) {
            if( !(func(curr) ))  // !- because we want the i that does not answer the func
                ansV.push_back(curr);
        }
        return ansV;
    }

}
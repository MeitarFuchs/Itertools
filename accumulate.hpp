#pragma once
#include <iostream>
#include <vector>


typedef struct {

    template <typename T>
    auto operator()(const T& a , const T& b) const
    {
        return a+b;
    }

} plus;

namespace itertools {

    template<class T,class FUNC=plus>

    class accumulate {
        const  T& container;
        const FUNC& func;
    public:

        accumulate(const T& cont,const FUNC& fun= plus()) :container(cont),func(fun)
        {}

        class iterator{
            decltype(container.begin()) it;
            typename std::decay<decltype(*(container.begin()))>::type sum;
            const accumulate& accum;

        public:
            iterator(decltype(container.begin()) curr,const accumulate& acc0): it(curr),accum(acc0) {
                if (curr!= acc0.container.end())
                    sum= *curr;
            }

            // ++i
            iterator& operator++(){
                ++it;
                if(it==accum.container.end())
                    return *this;
                sum=accum.func(sum,*it);
                return *this;
            }

            // i++
            const iterator operator++(int){
                iterator tempIt = *this;
                sum= accum.func(sum,*(it++));
                return tempIt;
            }

            bool operator==(const iterator &it0) const {
                return it==it0.it;
            }
            bool operator!=(const iterator &it0) const {
                return !(it==it0.it);
            }

            auto operator*(){
                return sum;
            }

            iterator& operator=(const iterator &tempIt)
            {
                return *this;
            }

        };



        iterator begin() const {
            return iterator( container.begin(), *this );

        }
        iterator end() const {
            return iterator( container.end(), *this );
        }
    };

}
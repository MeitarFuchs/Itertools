#pragma once
#include <iostream>
#include <vector>
namespace itertools {

    template<class T> class accumulate {
        const T& container;

    public:
        accumulate(const T& contain): container(contain){}

        class iterator{
            T sum=0;
            T* current;

        public:
            iterator(const T* it) :current(it){
                if (it!=NULL)
                    sum=*it;
            }

            iterator& operator++(){
                ++current;
                sum+=*current;
                return *this;
            }

            const iterator operator++(int){
                iterator temp = *this;
                ++current;
                sum+=*current;
                return temp;
            }

            bool operator==(const iterator &it) const {
                return it.current==current;
            }

            bool operator!=(const iterator &it) const {
                return it.current!=current;
            }

            auto operator*(){
                return sum;
            }

        };



        iterator<T> begin() {
            return iterator<T>(&container[0]);
        }
        iterator<T> end() {
            return iterator<T>(nullptr);
        }
    };




}
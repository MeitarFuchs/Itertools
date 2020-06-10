#include <iostream>
#include <vector>

namespace itertools{
    template<typename CONT,typename CONTB>
    class compress {
        CONT container;
        CONTB ContainerBoolean;

        decltype typename CONT::value_type() value_type; // to know the type of the first container

    public:
        compress(CONT cont, CONT cont)B: container(cont),containerBoolean(contB){} //constractor

        class iterator{
            typename CONT1::iterator it;
            typename CONT::iterator itAnsCont;

            typename CONT2::iterator itBool;

        public:

            explicit iterator(typename CONT::iterator it, typename CONT::iterator ansIt, typename CONTB::iterator itBool)
            }

            iterator(const iterator& other) = default;

            iterator& operator=(const iterator& other){
                return *this;
            };
            iterator& operator ++(){
                return *this;
            }
            iterator operator ++(int){
                iterator tmp = *this;
                ++(*this);
                return tmp;
            }
            bool operator ==(const iterator& other) {
                return true;
            }
            bool operator !=(const iterator& other) {
                return true;
            }
            value_type operator *(){
                return *it;
            }

        };
        iterator begin(){
            return this;
        }
        iterator end(){
            return this;
        }
    };
}
#include <iostream>
#include <vector>
using namespace std;

namespace itertools{
    template <typename T1 , typename T2>
    class compress{
        const T1& container1;
        const T2& container2;

    public:
        compress(const T1& cont1,const T2& cont2) :container1(cont1),container2(cont2){}

        class iterator{
            decltype(container1.begin()) it1;
            decltype(container2.begin()) it2;
            const compress& compr;

        public:
            iterator(decltype(container1.begin()) itA , decltype(container2.begin()) itB , const compress& com) :it1(itA) , it2(itB) , compr(com){
                while(it2!=compr.container2.end() && *it2==false) {
                    it1++;
                    it2++;
                }
            }

            iterator& operator++(){
                ++it1;
                ++it2;
                return *this;
            }

            const iterator operator++(int) {
                iterator tempIt= *this;
                ++it1;
                ++it2;
                return tempIt;
            }

            bool operator==(const iterator& itA) const{
                return it1==itA.it1;
            }

            bool operator!=(const iterator& itA) const{
                return it1!=itA.it1;
            }

            auto operator*(){
                return *it1;
            }

        };

        iterator begin() const{
            return iterator(container1.begin(), container2.begin(), *this);
        }

        iterator end() const {
            return iterator(container1.end(), container2.end(), *this);
        };


    };
}
#pragma once
namespace itertools {
    class range {
        int first;
        int last;
    public:
        range(int f, int l) : first(f), last(l) {}

        class iterator {
            int current;
        public:
            iterator(int currToBe = 0) : current(currToBe) {}

            iterator &operator++() { //++i
                current+= 1;
                return *this; // return with the update value
            }

            const iterator operator++(int) { //i++
                iterator temp= *this; //????????????????????????????????????
                current+= 1;
                return temp; // return the value before we update
            }

            bool operator==(const iterator &it) const {
                return (it.current)==current;
            }

            bool operator!=(const iterator &it) const {
                return (it.current)!=current;
            }

            int operator*(){
                return current;
            }

        };

        iterator begin() const {
            return iterator(first);
        }

        iterator end() const{
            return iterator(last);// maybe last-1
        }

        typedef int value_type;

    };
}
#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_
#include <vector>
#include "avl_tree.h"

template <typename K, typename V>
struct Pair {
    //Variables
    K key;
    V value;

    //Functions
    bool operator<(Pair<K,V> p) const {
        return key < p.key;
    }
    bool operator>(Pair<K,V> p) const {
        return key > p.key;
    }
    bool operator==(Pair<K,V> p) const {
        return key == p.key;
    }
    friend std::ostream& operator<<(std::ostream& hangout, const Pair<K,V>& p){
        hangout << p.key << ", " << p.value;
        return hangout;
    }
};

template <typename K, typename V>
class Dictionary : private AVLTree<Pair<K,V>> {
    public:
        //Constructors
        Dictionary(): AVLTree<Pair<K,V>>() {}
        Dictionary(const AVLTree<Pair<K,V>> &bt): AVLTree<Pair<K,V>>(bt) {}
        
        //Functions
        bool empty() const {
            return AVLTree<Pair<K,V>>::empty();
        }
        int size() const {
            return AVLTree<Pair<K,V>>::size();
        }
        V* get(K key) const {
            auto current = AVLTree<Pair<K,V>>::root;
            while(current){
                if(current->info.key == key){
                    V* pointer;
                    pointer = &current->info.value;
                    return pointer;
                }
                else if(key < current->info.key) current = current->left;
                else current = current->right;
            }

            return nullptr;
        }
        void put(K key, V value){
            Pair<K, V> pair;
            pair.key = key;
            pair.value = value;

            V* alreadyexist = get(key);
            if(alreadyexist){
                *alreadyexist = value;  //Since get() returns a pointer, we can manipulate the value here
            }
            else{
                AVLTree<Pair<K,V>>::insert(pair);
            }
        }
        void del(K key){
            if(!(get(key))){    //Checking to see if the value doesn't exist
                return;
            }
            //Constructing the pair
            Pair<K,V> pair {key};

            AVLTree<Pair<K,V>>::remove(pair);   //Borrowing remove function with pair
        }
        void clear(){
            while(!(empty())){
                del(AVLTree<Pair<K,V>>::root->info.key);    //We only need to delete the root, because the AVLTree will constantly refill the root
            }
        }
        std::vector<K> keys() const {
            Dictionary<K, V> copy(*this);
            std::vector<K> v;

            //Creating a copy to obtain keys and delete as you go
            while(!(copy.empty())){
                v.push_back(copy.getroot()->info.key);
                copy.del(copy.getroot()->info.key);
            }
            return v;
        }
        std::vector<V> values() const {
            Dictionary<K, V> copy(*this);
            std::vector<V> v;

            while(!(copy.empty())){
                v.push_back(copy.getroot()->info.value);
                copy.del(copy.getroot()->info.key);
            }
            return v;
        }
        Node<Pair<K,V>>* getroot() {    //Getter function to enable values() and keys()
            return AVLTree<Pair<K,V>>::root;
        }
        friend std::ostream& operator<<(std::ostream& scout, Dictionary<K,V>& d){
            d.inorderTraversal(scout);
            return scout;
        }

};

#endif
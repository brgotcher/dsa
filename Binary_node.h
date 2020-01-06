template <class Entry>
struct Binary_node{
//    data members:
   Entry data;
   Binary_node<Entry> *left;
   Binary_node<Entry> *right;
//    constructors:
   Binary_node();
   Binary_node(const Entry &x);

};

template <class Entry>
Binary_node<Entry>::Binary_node(){
   left = nullptr;
   right = nullptr;
}

template <class Entry>
Binary_node<Entry>::Binary_node(const Entry &x){
   data = x;
   left = nullptr;
   right = nullptr;
}


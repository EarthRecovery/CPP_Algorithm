#include <algorithm>

template<typename Object>
class Vector{
    public:
        typedef Object * iterator;
        typedef const Object * const_iterator;

        explicit Vector( int  initSize = 0 ) : theSize{ initSize },
        theCapacity : { initSize + SPARE_CAPACITY },
        {objects = new Object[ theCapacity ]; }

        Vector(const Vector & rhs) : theSize{ rhs.theSize },
        theCapacity : { rhs.theCapacity },
        {
            objects = new Object[ theCapacity ];
            for(int k=0;k<theSize; k++){
                objects[k] = rhs.objects[k];
            }
        }

        Vector & operator= (const Vector & rhs){
            Vector copy = rhs;
            std::swap( *this, copy );
            return *this; 
        }

        ~Vector() {
            delete [] objects; //注意不要忘[] 如果new[], 就delete[]
        }

        Vector(Vector && rhs) : theSize{ rhs.theSize },
        theCapacity : { rhs.theCapacity },
        objects : { rhs.objects }
        {
            rhs.theSize = 0;
            rhs.theCapacity = 0;
            rhs.objects = nullptr;
        }

        Vector & operator= (Vector && rhs){
            std::swap( theSize, rhs.theSize);
            std::swap( theCapacity, rhs.theCapacity);
            std::swap( objects, rhs.objects);

            return *this; 
        }

        void resize( int newSize ){
            if(newSize > theCapacity){
                reserve(newSize * 2);
            }
            theSize = newSize;
        }

        void reserve( int newCapacity ){
            if(newCapacity < theSize) return;
            Object *newArray = new Object[ newCapacity ];
            for(int k=0;k<theSize;k++){
                newArray[k] = std::move( objects[k] );
            }

            theCapacity = newCapacity;
            std::swap( objects,newArray );
            delete [] newArray;
        }

        Object & operator[] ( int index ){
            return objects[index];
        }
        const Object & operator[] ( int index ) const {
            return objects[index];
        }

        bool empty() const {
            return theSize == 0;
        }
        int size() const {
            return theSize;
        }
        int capacity() const {
            return theCapacity;
        }

        void push_back( const Object & k){
            if(theSize == theCapacity){
                reserve(2*theCapacity + 1);
            }
            objects[theSize++] = k;
        }

        void pop_back(){
            --theSize();
        }

        const Object & back() const {
            return objects[theSize-1];
        }

        iterator begin(){
            return &Object[0];
        }
        const_iterator begin() const {
            return &Object[0];
        }
        const_iterator end() const {
            return &Object[theSize];
        }

    private:
        static const int SPARE_CAPACITY = 16;
        int theSize;
        int theCapacity;
        Object * objects;
};

int main(){
    Vector<int> a;
}
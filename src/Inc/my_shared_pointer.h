typedef unsigned int uint;

template<class T>
class my_shared_ptr
{
private:
    T* ptr = nullptr;
    uint* refCounter = nullptr;
    void cleanup()
    {
        (*refCounter)--;
        if (*refCounter == 0)
        {
            if (ptr != nullptr)
            {
                delete ptr;
            }
            delete refCounter;
        }
    }


public:
    // def constructor
    my_shared_ptr() : ptr(nullptr), refCounter(new uint(0))
    {

    }
    //constructor
    my_shared_ptr(T* ptr) : ptr(ptr), refCounter(new uint(1))
    {

    }
    // Copy
    my_shared_ptr(const my_shared_ptr &obj)
    {
        this->ptr = obj.ptr;
        this->refCounter = obj.refCounter;
        if (nullptr != obj.ptr)
        {
            (*this->refCounter)++;
        }
    }
    // Copy assigment
    my_shared_ptr& operator=(const my_shared_ptr &obj)
    {
        cleanup();

        this->ptr = obj.ptr;
        this->refCounter = obj.refCounter;
        if (nullptr != obj.ptr)
        {
            (*this->refCounter)++;
        }

    }
    // Move
    my_shared_ptr(my_shared_ptr && dyingObj)
    {
        this->ptr = dyingObj.ptr;
        this->refCounter = dyingObj.refCounter;
        dyingObj.ptr = nullptr;
        dyingObj.refCounter = nullptr;
    }

    // Move assigment
    my_shared_ptr& operator=(my_shared_ptr && dyingObj)
    {
        cleanup();

        this->ptr = dyingObj.ptr;
        this->refCounter = dyingObj.refCounter;
        dyingObj.ptr = nullptr;
        dyingObj.refCounter = nullptr;
    }

    // dereference operators overload
    T* operator->() const
    {
        return this->ptr;
    }

    T* operator*() const
    {
        return this->ptr;
    }

    // utility functions
    uint get_count() const
    {
        return *refCounter;
    }
    T* get() const
    {
        return this->ptr;
    }

    void reset(T* newPtr)
    {
        (*refCounter)--;
        this->ptr = newPtr;
        this->refCounter = new uint(1);
    }

    ~my_shared_ptr()
    {
        cleanup();
    }
};

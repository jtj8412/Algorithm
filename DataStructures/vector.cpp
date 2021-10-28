//----------------------------------------------------------------------------------
// [ Vector ]
//----------------------------------------------------------------------------------

#include <iostream>

template <typename T>
class Vector 
{
public:
    Vector(): mData(nullptr), mSize(0), mCapacity(0) { }

    Vector(int size) : mData(new T[size]), mSize(size), mCapacity(size) { }

    Vector(int size, const T& data) : mData(new T[size]), mSize(size), mCapacity(size)
    {
        for (int i = 0; i < size; ++i)
        {
            mData[i] = data;
        }
    }

    Vector(const Vector& x) : mData(new T[x.mCapacity]), mSize(x.mSize), mCapacity(x.mCapacity)
    {
        for (int i = 0; i < mSize; ++i)
        {
            mData[i] = x.mData[i];
        }
    }

    ~Vector() 
    {
        if (mData)
        {
            delete[] mData;
        }
    }

public:
    Vector& operator=(const Vector& x)
    {
        if (mCapacity != x.mCapacity)
        {
            if (mData)
            {
                delete[] mData;
            }
            mData = new T[x.mCapacity];
        }

        for (int i = 0; i < x.mSize; ++i)
        {
            mData[i] = x.mData[i];
        }

        mCapacity = x.mCapacity;
        mSize = x.mSize;
    }

    T& operator[](int n) const
    {
        return mData[n];
    }

public:
    bool IsEmpty() const 
    {
        return mSize == 0;
    }

    int GetSize() const
    {
        return mSize;
    }

    int GetCapacity() const
    {
        return mCapacity;
    }

    T& GetFront() const
    {
        return mData[0];
    }

    T& GetBack() const
    {
        return mData[mSize - 1];
    }

    void SetCapacity(int capacity)
    {
        if (capacity == mCapacity)
        {
            return;
        }

        T* newData = new T[capacity];
        int size = (capacity < mSize) ? capacity : mSize;

        for (int i = 0; i < size; ++i)
        {
            newData[i] = mData[i];
        }

        delete mData;

        mData = newData;
        mCapacity = capacity;
        mSize = size;
    }

    void SetSize(int size)
    {
        if (size == mSize)
        {
            return;
        }

        if (size > mCapacity)
        {
            SetCapacity(size);
        }

        mSize = size;
    }

    void SetSize(int size, const T& data)
    {
        int prevSize = mSize;

        SetSize(size);

        for (int i = prevSize; i < size; ++i)
        {
            mData[i] = data;
        }
    }

    void Clear()
    {
        mSize = 0;
    }

    void Push(const T& data)
    {
        SafeMemoryByAdd();

        mData[mSize++] = data;
    }

    void Pop()
    {
        if (mSize != 0)
        {
            mSize--;
        }
    }

    void Insert(int index, const T& data)
    {
        SafeMemoryByAdd();

        for (int i = mSize - 1; i >= index; --i)
        {
            mData[i + 1] = mData[i];
        }
        
        mData[index] = data;
        mSize++;
    }

    void Erase(int index)
    {
        for (int i = index; i < mSize - 1; ++i)
        {
            mData[i] = mData[i + 1];
        }

        mSize--;
    }

    void Erase(int firstIndex, int lastIndex)
    {
        if (firstIndex >= mSize || firstIndex > lastIndex)
        {
            return;
        }

        int count = (lastIndex < mSize) ? lastIndex - firstIndex + 1 : mSize - firstIndex;

        for (int i = lastIndex + 1; i < mSize; ++i)
        {
            mData[i - count] = mData[i];
        }

        mSize -= count;
    }

    void EraseByData(const T& data)
    {
        for (int i = 0; i < mSize; ++i)
        {
            if (mData[i] == data)
            {
                Erase(i);
                break;
            }
        }
    }

    void EraseAllByData(const T& data)
    {
        int count = 0;

        for (int i = 0; i < mSize; ++i)
        {
            if (mData[i] == data)
            {
                count++;
            }
            else
            {
                mData[i - count] = mData[i];
            }
        }

        mSize -= count;
    }

    T* Find(const T& data)
    {
        T* find = nullptr;

        for (int i = 0; i < mSize; ++i)
        {
            if (mData[i] == data)
            {
                find = &mData[i];
                break;
            }
        }

        return find;
    }

    int FindIndex(const T& data)
    {
        int index = -1;

        for (int i = 0; i < mSize; ++i)
        {
            if (mData[i] == data)
            {
                index = i;
                break;
            }
        }

        return index;
    }

private:
    void SafeMemoryByAdd()
    {
        if (mSize == mCapacity)
        {
            if (mCapacity == 0)
            {
                SetCapacity(1);
            }
            else
            {
                SetCapacity(mCapacity * 2);
            }
        }
    }

private:
    T* mData;
    int mSize;
    int mCapacity;
};






template <typename T>
void PrintVectorSize(const Vector<T>& vec) 
{
    // GetSize, GetCapacity
    printf("size: %d, capacity: %d\n", vec.GetSize(), vec.GetCapacity());
}

template <typename T>
void PrintVectorData(const Vector<T>& vec)
{
    for (int i = 0; i < vec.GetSize(); ++i)
    {
        // operator[]
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void PrintVectorAll(const Vector<T>& vec)
{
    PrintVectorSize(vec);
    PrintVectorData(vec);
    printf("\n");
}






int main() {
    Vector<int> vec;

    // IsEmpty
    printf("IsEmpty(): %d\n\n", vec.IsEmpty());

    // Push
    printf("Push(0 ~ 9)\n");
    for (int i = 0; i < 10; ++i)
    {
        vec.Push(i);
        PrintVectorSize(vec); 
    }
    PrintVectorData(vec);
    printf("\n");

    // Vector(const Vector& x)
    Vector<int> vec2(vec);
    printf("Vector(vec)\n");
    PrintVectorAll(vec2);

    // operator=
    printf("operator=\n");
    Vector<int> vec3 = vec2;
    PrintVectorAll(vec3);
    
    // GetFront
    printf("GetFront(): %d\n\n", vec.GetFront());

    // GetBack
    printf("GetBack(): %d\n\n", vec.GetBack());

    // Find
    printf("Find(7): %d\n\n", *vec.Find(7));

    // SetCapacity
    vec.SetCapacity(20);
    printf("SetCapacity(20)\n");
    PrintVectorAll(vec);

    // SetSize
    vec.SetSize(8);
    printf("SetSize(8)\n");
    PrintVectorAll(vec);

    // SetSize 2
    vec.SetSize(10, 3);
    printf("SetSize(10, 3)\n");
    PrintVectorAll(vec);

    // Pop
    vec.Pop();
    printf("Pop()\n");
    PrintVectorAll(vec);
    
    // Insert
    vec.Insert(3, 100);
    printf("Insert(3, 100)\n");
    PrintVectorAll(vec);

    // Erase
    vec.Erase(5);
    printf("Erase(5)\n");
    PrintVectorAll(vec);

    // Erase 2
    vec.Erase(1, 3);
    printf("Erase(1, 3)\n");
    PrintVectorAll(vec);

    // EraseByData
    vec.EraseByData(5);
    printf("EraseByData(5)\n");
    PrintVectorAll(vec);

    // FindIndex
    printf("FindIndex(6): %d\n\n", vec.FindIndex(6));

    // EraseAllByData
    vec.EraseAllByData(3);
    printf("EraseAllByData(3)\n");
    PrintVectorAll(vec);

    // Clear
    vec.Clear();
    printf("Clear()\n");
    PrintVectorAll(vec);

    // Constructor
    Vector<int> vec4(10, 9);
    printf("Vector(10, 4)\n");
    PrintVectorAll(vec4);
}
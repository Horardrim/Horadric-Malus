#include "_vector.hxx"

void stl_vector_usageI()
{
    std::vector<int> vecI;
    vecI[0] = 10;  // 无法通过[] operator读取一个没有任何元素的vector.
    for (std::vector<int>::iterator it = vecI.begin(); it != vecI.end(); ++it) {
        printf("vectI[1] = %d\n", *it);
    }
}